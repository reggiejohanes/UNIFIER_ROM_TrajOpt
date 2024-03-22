
% clear all
% close all
% clc

%% Constants

gr = 9.80665;      % standard gravity

%% Aircraft Data

load("dp_HTU.mat")
load("dp_DEP.mat")
load("UNIFIER_ROM.mat")

% Mass case NO PASSENGERS, FULL FUEL: (aft C.G.)
% m = 5423;
% xyz_cg = [-8.45,0,-0.2];

% Mass case FULL PASSANGERS, FULL FUEL:
% m = 7438;
% xyz_cg = [-8.32,0,-0.2];

% Mass case FULL PASSANGERS, FULL FUEL, WITH ONLY PARTIAL CARGO: (front C.G.)
m = 7057;
xyz_cg = [-8.09,0,-0.2];

xyz_cg_12(1,1:12)=xyz_cg(1);
xyz_cg_12(2,1:12)=xyz_cg(2);
xyz_cg_12(3,1:12)=xyz_cg(3);

% Intertia:
I = [23600,     -0,   -1740;
    -0,      89800,      -0;
    -1740,      -0,  102000];

Iyy = I(2,2);

% Geometry
b = 20.11467;
c = 1.43676;
S = 29.98388;

xyz_DEP = [ -6.9629998	-6.9210000	-6.8660002	-6.8099999	-6.7540002	-6.6999998	-6.6999998	-6.7540002	-6.8099999	-6.8660002	-6.9210000	-6.9629998
    -10.050000	-8.4499998	-6.8499999	-5.2500000	-3.6500001	-2.0500000	2.0500000	3.6500001	5.2500000	6.8499999	8.4499998	10.050000
    -0.90899998	-0.79200000	-0.82300001	-0.85000002	-0.87599999	-0.89899999	-0.89899999	-0.87599999	-0.85000002	-0.82300001	-0.79200000	-0.90899998];

%% Control Limits/Saturation

% Max/min deflections
umin(1) = -25; % Min aileron deflection  [deg]
umax(1) = 25;  % Max aileron deflection  [deg]

umin(2) = -30; % Min rudder deflection   [deg]
umax(2) = 30;  % Max rudder deflection   [deg]

umin(3) = -5;  % Min elevator deflection [deg]
umax(3) = 20;  % Max elevator deflection [deg]

umin(4) = 0;   % Min flap deflection     [deg]
umax(4) = 25;  % Max flap deflection     [deg]

umin(5) = 0;   % Min DEP_col             [-]
umax(5) = 1;   % Max DEP_col             [-]

umin(6) = -1;  % Min DEP_slope           [-]
umax(6) = 1;   % Max DEP_slope           [-]

umin(7) = 0;   % Min HTU                 [-]
umax(7) = 1;   % Max HTU                 [-]

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
dumax      = deg2rad(dumax);

%% Save to .mat

save UNIFIER_LOAD_ROM
