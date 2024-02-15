function DX=UNIFIER_ROMdyn_script(X,U)

%% Test
% clc
% clear
% close all
% 
% X = [0, -1219, 72.731047032614440, 1.142307104518741, 0.015706052282666, 0;...
%      0, -1219, 72.731047032614440, 1.142307104518741, 0.015706052282666, 0];
% U = [-0.015298320692100, 0, 0.306978739246813, 0.271067256037969;...
%      -0.015298320692100, 0, 0.306978739246813, 0.271067256037969];

%% Constants

UNIFIER_LOAD_ROM

prop_d  = 1.6;
DEP_inc = deg2rad(-5);
n_prop  = 12;

%% Extract State and Control Variables

% States
x     = X(:,1); % mc
z     = X(:,2); % m
u     = X(:,3); % m/s
w     = X(:,4); % m/s
theta = X(:,5); % rad
q     = X(:,6); % rad/s

% Controls
dElev = U(:,1); % rad
dFlap = U(:,2); % rad
DEP   = U(:,3); % 0-1
HTU   = U(:,4); % 0-1

n = numel(x);

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

% Coefficients ------------------------------------------------------------
CL   = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,... % breakpoints
                     ROM.CL,...                        % table data
                     dFlap,alpha,J,dElev);             % inputs
CD   = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,...
                     ROM.CD,...
                     dFlap,alpha,J,dElev); 
CM   = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,...
                     ROM.CM,... 
                     dFlap,alpha,J,dElev);

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
du = Fx_b./m - w.*q - g.*sin(theta);
dw = Fz_b./m + u.*q + g.*cos(theta);
dq = M_b/Iyy;

% Kinematics --------------------------------------------------------------
dx     = u.*cos(theta) + w.*sin(theta);
dz     = w.*cos(theta) - u.*sin(theta);
dtheta = q;

%% Compile Accelerations

DX = [dx dz du dw dtheta dq];

end

