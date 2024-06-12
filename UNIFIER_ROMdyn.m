function DX=UNIFIER_ROMdyn(X,U)

%% Test
% clc
% clear
% close all
% 
% X = [0, -1219, 72.731047032614440, 1.142307104518741, 0.015706052282666, 0;...
%      0, -1219, 72.731047032614440, 1.142307104518741, 0.015706052282666, 0];
% 
% U = [-0.015298320692100, 0.306978739246813, 0.271067256037969;...
%      0.015298320692100, 0.306978739246813, 0.271067256037969];
% U = [-0.015298320692100, 0, 0.306978739246813, 0.271067256037969;...
%      -0.015298320692100, 0, 0.306978739246813, 0.271067256037969];
% U=[-0.030909732474324,0.306466616418674,0.275128721852146];

%% Constants

global runconfig

if runconfig.ROMfile==1
    load data/UNIFIER_LOAD_ROM_72.mat % v1 at 72.74 m/s
elseif runconfig.ROMfile==2
    load data/UNIFIER_LOAD_ROM_50.mat % v1 at 50 m/s
elseif runconfig.ROMfile==3
    load data/UNIFIER_LOAD_ROM_v2.mat % v2
else
    error("Invalid ROM file setting")
end

prop_d  = 1.6;
DEP_inc = deg2rad(-5);
n_prop  = 12;

%% Extract State and Control Variables

% States
x     = X(:,1); % m
z     = X(:,2); % m
u     = X(:,3); % m/s
w     = X(:,4); % m/s
theta = X(:,5); % rad
q     = X(:,6); % rad/s

% Controls
dElev = U(:,1); % rad
DEP   = U(:,2); % 0-1
HTU   = U(:,3); % 0-1
% dFlap = U(:,4); % rad

% dFlap = deg2rad(0);
dFlap = runconfig.dFlap;
dFlap = linspace(dFlap,dFlap,numel(x))';

%% Intermediate Variables

alpha         = atan2(w,u);        % angle of attack
[~,~,~,rho,~] = atmosisa(-z);      % density
Va            = sqrt(w.^2 + u.^2); % airspeed
Q             = 0.5*rho.*Va.^2;    % dynamic pressure

%% Propulsion

% HTU ---------------------------------------------------------------------
T_HTU_req = interp1([-0.5,1.5],[-5000,15000],HTU,"linear");
T_HTU_max = interp1(dp_HTU.limits.V_up_lim,...
                    dp_HTU.limits.T_up_lim,...
                    Va,...
                    "linear");
T_HTU_min = interp1(dp_HTU.limits.V_low_lim,...
                    dp_HTU.limits.T_low_lim,...
                    Va,...
                    "linear");
T_HTU     = max(min(T_HTU_req,T_HTU_max),T_HTU_min);

FHTU_b_x = T_HTU;
FHTU_b_z = 0;
MHTU     = 0;

% DEP ---------------------------------------------------------------------

% convert activity factor to rps command
T_DEP_req = DEP.*800;
rpm_cmd   = interpn(dp_DEP.rpm_lookup.V_vec,...
                    dp_DEP.rpm_lookup.T_vec,...
                    dp_DEP.rpm_lookup.rpm_gird,...
                    Va,...
                    T_DEP_req,...
                    'linear');
if DEP < 0.001
    rpm_cmd = rpm_cmd.*0;
end
rps_cmd = rpm_cmd./60;

% calculate advance ratio, thrust coefficient, thrust force
J = Va./(rps_cmd.*1.6+eps);
J = max(min(J,2.5),0.3);
CT = interp1(dp_DEP.J,...
             dp_DEP.C_T,...
             J,...
             "linear");
T = prop_d^4*rps_cmd.^2.*rho.*CT;

% calculate body forces

FDEP_single_b_x = T.*cos(DEP_inc);
FDEP_single_b_z = T.*sin(DEP_inc)*-1;
FDEP_b_x = n_prop.*FDEP_single_b_x;
FDEP_b_z = n_prop.*FDEP_single_b_z;

% calculate moments
M_arms   = xyz_DEP-xyz_cg_12;
M_arms_x = sum(M_arms(1,:));
M_arms_z = sum(M_arms(3,:));
MDEP_x   = FDEP_single_b_x.*M_arms_z;
MDEP_z   = FDEP_single_b_z.*M_arms_x.*-1;
MDEP     = MDEP_x+MDEP_z;

%% Aerodynamics

% apply lookup input saturation limits
alpha_sat = max(min(alpha,max(ROM.alpha)),min(ROM.alpha));
Va_sat    = max(min(Va,max(ROM.Va)),min(ROM.Va));
DEP_sat   = max(min(DEP,max(ROM.DEP_col)),min(ROM.DEP_col));
dElev_sat = max(min(dElev,max(ROM.dElev)),min(ROM.dElev));
dFlap_sat = max(min(dFlap,max(ROM.dFlap)),min(ROM.dFlap));

% lookup coefficients
if runconfig.ROMfile==1 || runconfig.ROMfile==2 % v1 ROMs
    if runconfig.ROMdep==1
        % Coefficients (all dependencies) ---------------------------------
        if runconfig.ROMfile==1 %rom72
            J_lim = max(min(J,DEPVa2J(72.74,min(ROM.DEP_col))),DEPVa2J(72.74,max(ROM.DEP_col)));
        elseif runconfig.ROMfile==2 %rom50
            J_lim = max(min(J,DEPVa2J(50,min(ROM.DEP_col))),DEPVa2J(50,max(ROM.DEP_col)));
        end
        
        CL = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,... % breakpoints
                     ROM.CL,...                              % table data
                     dFlap_sat,alpha_sat,J_lim,dElev_sat);   % inputs
        CD = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,...
                     ROM.CD,...
                     dFlap_sat,alpha_sat,J_lim,dElev_sat); 
        CM = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,...
                     ROM.CM,... 
                     dFlap_sat,alpha_sat,J_lim,dElev_sat);
    elseif runconfig.ROMdep==2
        % Coefficients (reduced dependencies) -----------------------------
        dElev_fixed = deg2rad(0);
        if runconfig.ROMfile==1
            J_fixed = DEPVa2J(72.74,0.5); % J at Vcruise & DEP=0.5
        elseif runconfig.ROMfile==2
            J_fixed = DEPVa2J(50,0.5); % J at Vcruise & DEP=0.5
        end
        
        dElev_fixed = linspace(dElev_fixed,dElev_fixed,numel(x))';
        J_fixed     = linspace(J_fixed,J_fixed,numel(x))';
        
        CL = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,... % CL(alpha)
                     ROM.CL,...                              
                     dFlap_sat,alpha_sat,J_fixed,dElev_fixed);
        CD = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,... % CD(alpha)
                     ROM.CD,...
                     dFlap_sat,alpha_sat,J_fixed,dElev_fixed); 
        CM = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,... % CM(alpha,dElev)
                     ROM.CM,... 
                     dFlap_sat,alpha_sat,J_fixed,dElev);
    else
        error("Invalid ROM dependency setting")
    end
elseif runconfig.ROMfile==3 % v2 ROM
    if runconfig.ROMdep==1
        % Coefficients (all dependencies) ---------------------------------
        CL = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,... % breakpoints
                     ROM.CL,...                                           % table data
                     dFlap_sat,dElev_sat,DEP_sat,Va_sat,alpha_sat);       % inputs
        CD = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,...
                     ROM.CD,...
                     dFlap_sat,dElev_sat,DEP_sat,Va_sat,alpha_sat);
        CM = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,...
                     ROM.CM,...
                     dFlap_sat,dElev_sat,DEP_sat,Va_sat,alpha_sat);
    elseif runconfig.ROMdep==2
        % Coefficients (reduced dependencies) -----------------------------
        dElev_fixed = deg2rad(0);
        DEP_fixed   = 0.5;
        Va_fixed    = 72.74;
        
        dElev_fixed = linspace(dElev_fixed,dElev_fixed,numel(x))';
        DEP_fixed = linspace(DEP_fixed,DEP_fixed,numel(x))';
        Va_fixed = linspace(Va_fixed,Va_fixed,numel(x))';
        
        CL = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,... % CL(alpha)
                     ROM.CL,...                                      
                     dFlap_sat,dElev_fixed,DEP_fixed,Va_fixed,alpha_sat);     
        CD = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,... % CD(alpha)
                     ROM.CD,...
                     dFlap_sat,dElev_fixed,DEP_fixed,Va_fixed,alpha_sat);
        CM = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,... % CM(dElev, alpha)
                     ROM.CM,...
                     dFlap_sat,dElev_fixed,DEP_fixed,Va_fixed,alpha_sat);  
    else
        error("Invalid ROM dependency setting")
    end
else
    error("Invalid ROM file setting")
end

% Dimensionalize forces and moments ---------------------------------------
L   = Q.*S.*CL;
D   = Q.*S.*CD;
Mae = Q.*S.*c.*CM;

% Wind to body axes -------------------------------------------------------
Fae_b_x = -1*(D.*cos(alpha) - L.*sin(alpha));
Fae_b_z = -1*(D.*sin(alpha) + L.*cos(alpha));

%% Equations of Motion

% Add forces and moments --------------------------------------------------
Fx_b = Fae_b_x + FDEP_b_x + FHTU_b_x;
Fz_b = Fae_b_z + FDEP_b_z + FHTU_b_z;
M_b  = Mae + MDEP + MHTU;

% Force/moment balance equations ------------------------------------------
du = Fx_b./m - w.*q - gr*sin(theta);
dw = Fz_b./m + u.*q + gr*cos(theta);
dq = M_b/Iyy;

% Kinematics --------------------------------------------------------------
dx     = u.*cos(theta) + w.*sin(theta);
dz     = w.*cos(theta) - u.*sin(theta);
dtheta = q;

%% Compile Accelerations

DX = [dx dz du dw dtheta dq];

% Xnew=X+DX;

end

