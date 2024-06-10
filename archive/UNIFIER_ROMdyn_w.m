% function DX=UNIFIER_ROMdyn_v2(X,U)

%% Test
clc
clear
close all

X0 = [0, -1219, 72.731047032614440, 1.142307104518741, 0.015706052282666, 0];

x0     = X0(1);
z0     = X0(2);
u0     = X0(3);
w0     = X0(4);
theta0 = X0(5);
q0     = X0(6);

Va0    = sqrt(u0^2+w0^2);
alpha0 = atan2(w0,u0);
gamma0 = theta0-alpha0;

X(1:2,1) = x0;
X(1:2,2) = z0;
X(1:2,3) = Va0;
X(1:2,4) = gamma0;
X(1:2,5) = alpha0;
X(1:2,6) = q0;

U = [-0.015298320692100, 0.306978739246813, 0.271067256037969;...
     0.015298320692100, 0.306978739246813, 0.271067256037969];

% U = [-0.015298320692100, 0, 0.306978739246813, 0.271067256037969;...
%      -0.015298320692100, 0, 0.306978739246813, 0.271067256037969];
% U=[-0.030909732474324,0.306466616418674,0.275128721852146];

%% Constants

load data/UNIFIER_LOAD_ROM.mat

prop_d  = 1.6;
DEP_inc = deg2rad(-5);
n_prop  = 12;

%% Extract State and Control Variables

% States
x     = X(:,1); % m
z     = X(:,2); % m
Va    = X(:,3); % m/s
gamma = X(:,4); % rad
alpha = X(:,5); % rad
q     = X(:,6); % rad/s

% x     = X(:,1); % m
% z     = X(:,2); % m
% u     = X(:,3); % m/s
% w     = X(:,4); % m/s
% theta = X(:,5); % rad
% q     = X(:,6); % rad/s

% Controls
dElev = U(:,1); % rad
DEP   = U(:,2); % 0-1
HTU   = U(:,3); % 0-1
% dFlap = U(:,4); % rad

dFlap = deg2rad(12);
% global controls
% dFlap = controls.dFlap;
dFlap = linspace(dFlap,dFlap,numel(x))';

%% Intermediate Variables

[~,~,~,rho,~] = atmosisa(-z);      % density
Q             = 0.5*rho.*Va.^2;    % dynamic pressure
alpha_T       = alpha + DEP_inc;

% alpha         = atan2(w,u);        % angle of attack
% Va            = sqrt(w.^2 + u.^2); % airspeed
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

% FHTU_b_x = T_HTU;
% FHTU_b_z = 0;
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
T_DEP_single = prop_d^4*rps_cmd.^2.*rho.*CT;

% calculate total thrust force
T_DEP = T_DEP_single.*n_prop;

% calculate body forces

FDEP_single_b_x = T_DEP_single.*cos(DEP_inc);
FDEP_single_b_z = T_DEP_single.*sin(DEP_inc)*-1;
% FDEP_b_x = n_prop.*FDEP_single_b_x;
% FDEP_b_z = n_prop.*FDEP_single_b_z;

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
% Fae_b_x = -1*(D.*cos(alpha) - L.*sin(alpha));
% Fae_b_z = -1*(D.*sin(alpha) + L.*cos(alpha));

%% Equations of Motion

% Add forces and moments --------------------------------------------------
% Fx_b = Fae_b_x + FDEP_b_x + FHTU_b_x;
% Fz_b = Fae_b_z + FDEP_b_z + FHTU_b_z;
M_total  = Mae + MDEP + MHTU;

% Force/moment balance equations ------------------------------------------
dVa    = (T_DEP.*cos(alpha_T)+T_HTU.*cos(alpha)-D)./m - gr.*sin(gamma);
dgamma = (T_DEP.*sin(alpha_T)+T_HTU.*sin(alpha)+L)./(m.*Va) - gr.*cos(gamma)./Va;
dq     = M_total/Iyy;

% du = Fx_b./m - w.*q - gr*sin(theta);
% dw = Fz_b./m + u.*q + gr*cos(theta);
% dq = M_b/Iyy;

% Kinematics --------------------------------------------------------------
dx     = Va.*cos(gamma);
dz     = Va.*sin(gamma);
dalpha = q.*cos(alpha)-dgamma;

% dx     = u.*cos(theta) + w.*sin(theta);
% dz     = w.*cos(theta) - u.*sin(theta);
% dtheta = q;

%% Compile Accelerations

DX = [dx dz dVa dgamma dalpha dq];

Xnew=X+DX;

Xnew0=[72.7400169643264	-1219.00010444813	72.5242164823886	-4.70998386219179	0.0157060522826660	-0.00992552219006166;
72.7400169643264	-1219.00010444813	72.5268530173866	-4.88718984150586	0.0157060522826660	-0.126179840390454];

Vanew0    = sqrt(Xnew0(1,4)^2+Xnew0(1,3)^2);
alphanew0 = atan2(Xnew0(1,4),Xnew0(1,3));
gammanew0 = Xnew0(1,5)-alphanew0;

Xnew0conv=[...
    Xnew0(1,1)...
    Xnew0(1,2)...
    Vanew0...
    gammanew0...
    alphanew0...
    Xnew0(1,6)];


% DX = [dx dz du dw dtheta dq];

% end

