
% UNIFIER19 C7A-HARW FLIGHT DYNAMICS SIMULATOR
% Revision: 19.07.2022 - J.Soikkeli
%
% www.unifier19.eu
%
% The project has received funding from the CleanSky2 Joint Undertaking (JU) under grant agreement NO 864901. 
% The JU receives support from the European Union%s Horizon 2020 research and innovation programme and the 
% Clean Sky 2 JU members other than the Union.

clear all
% close all
% clc

%% Constants

gr = 9.80665; % standard gravity

%% Aircraft Data

addpath(genpath(pwd))

load("dp_VTAIL.mat");
load("dp_VTAIL_INDUCED.mat");
load("dp_WING.mat");
load("dp_FUSE_FIN.mat");
load("dp_HTU.mat")
load("dp_DEP.mat")

% Mass case NO PASSENGERS, FULL FUEL: (aft C.G.)
% m      = 5423;
% xyz_cg = [-8.45,0,-0.2];

% Mass case FULL PASSANGERS, FULL FUEL:
% m      = 7438;
% xyz_cg = [-8.32,0,-0.2];

% Mass case FULL PASSANGERS, FULL FUEL, WITH ONLY PARTIAL CARGO: (front C.G.)
m      = 7057;
xyz_cg = [-8.09,0,-0.2];

xyz_cg_12(1,1:12) = xyz_cg(1);
xyz_cg_12(2,1:12) = xyz_cg(2);
xyz_cg_12(3,1:12) = xyz_cg(3);

% Constants:
I = [23600,  -0,      -1740;
    -0,       89800,  -0;
    -1740,   -0,       102000];

Iyy = I(2,2);

b = 20.11467;
c = 1.43676;
S = 29.98388;

wing_nodes = [fliplr(dp_WING_tip.LE_Xs),fliplr(dp_WING_root.LE_Xs),dp_WING_root.LE_Xs,dp_WING_tip.LE_Xs;...
             fliplr(-dp_WING_tip.LE_Ys),fliplr(-dp_WING_root.LE_Ys),dp_WING_root.LE_Ys,dp_WING_tip.LE_Ys;...
             fliplr(dp_WING_tip.LE_Zs),fliplr(dp_WING_root.LE_Zs),dp_WING_root.LE_Zs,dp_WING_tip.LE_Zs];

vtail_nodes = [dp_VTAIL.Xs_LE;...
               dp_VTAIL.Ys_LE;...
               dp_VTAIL.Zs_LE];

vtail_dist_to_wing = 7.8070;

xyz_DEP = [ -6.9629998	-6.9210000	-6.8660002	-6.8099999	-6.7540002	-6.6999998	-6.6999998	-6.7540002	-6.8099999	-6.8660002	-6.9210000	-6.9629998
            -10.050000	-8.4499998	-6.8499999	-5.2500000	-3.6500001	-2.0500000	2.0500000	3.6500001	5.2500000	6.8499999	8.4499998	10.050000
            -0.90899998	-0.79200000	-0.82300001	-0.85000002	-0.87599999	-0.89899999	-0.89899999	-0.87599999	-0.85000002	-0.82300001	-0.79200000	-0.90899998];

prop_d  = 1.6;
DEP_inc = deg2rad(-5);
n_prop  = 12;

%% Simulation Settings

DEP_PID_IC         = 163.487227;
DEP_INTEG_IC       = 117.49388;
sensor_delay_steps = 5;

%% Initial Conditions:

fcc.dt     = 1/100;
ground_alt = 0;
latlong0   = [45.466148, 6.692235];

% Xe0     = [0,0,-1100];
% Vb0     = [52.6789583501891, 0, 2.71559652634250];
% Euler0  = [3.43106170068520e-06, 0.0515008506277664, -2.79252663434261];
% omegab0 = [0,0,0];

% u1_0 = [2.1112539e-05, -2.1112539e-05, -0.085004635, -0.084972650, 0.19720161, 0.19720161];
% u2_0 = ones(1,12) .* 0.4252;
% u3_0 = 0.089689;
% u4_0 = 0;

%% Control Limits/Saturation

% Max/min deflections
umin(1) = -25;  % Min aileron deflection  [deg]
umax(1) = 25;   % Max aileron deflection  [deg]

umin(2) = -30;  % Min rudder deflection   [deg]
umax(2) = 30;   % Max rudder deflection   [deg]

umin(3) = -30;  % Min elevator deflection [deg]
umax(3) = 30;   % Max elevator deflection [deg]

umin(4) = 0;    % Min flap deflection     [deg]
umax(4) = 25;   % Max flap deflection     [deg]

umin(5) = 0;    % Min DEP_col             [-]
umax(5) = 1;    % Max DEP_col             [-]

umin(6) = -1;   % Min DEP_slope           [-]
umax(6) = 1;    % Max DEP_slope           [-]

umin(7) = -0.5; % Min HTU                 [-]
umax(7) = 1;    % Max HTU                 [-]

% Rate limits
dumax(1) = 60; % Aileron    [deg/s]
dumax(2) = 60; % Rudder     [deg/s]
dumax(3) = 60; % Elevator   [deg/s]
dumax(4) = 10; % Flap       [deg/s]
dumax(5) = 2;  % DEP_col
dumax(6) = 2;  % DEP_slope
dumax(7) = 2;  % HTU

% Convert to rad
umin(1:4)  = deg2rad(umin(1:4));
umax(1:4)  = deg2rad(umax(1:4));
dumax(1:4) = deg2rad(dumax(1:4));

%% Test inputs

xtest=[0;
       0;
      -1219;
       72.7316573063218;
       0;
      -1.09206753970844;
       0;
      -0.0150133899098928;
       0;
       0;
       0;
       0];

utest=[0;
       0;
       0.0251262152288557;
       0.0872664625997165;
       0;
       0;
       0.545584361024023];

%% Save to .mat

save UNIFIER_LOAD
