
clear all
% close all
% clc

%% ROM File

timestamp="20240613_053529";
romfile="UNIFIER_ROMv4_" + timestamp;
load(romfile,"ROM")

%% Constants

gr = 9.80665;      % standard gravity

%% Aircraft Data

load("dp_HTU.mat")
load("dp_DEP.mat")
load UNIFIER_LOAD.mat m xyz_cg I c S b xyz_DEP umax umin

xyz_cg_12(1,1:12)=xyz_cg(1);
xyz_cg_12(2,1:12)=xyz_cg(2);
xyz_cg_12(3,1:12)=xyz_cg(3);

Iyy = I(2,2);

%% Control Limits/Saturation

% Rate limits
dumax(1) = 60; % Aileron    [deg/s]
dumax(2) = 60; % Rudder     [deg/s]
dumax(3) = 60; % Elevator   [deg/s]
dumax(4) = 10; % Flap       [deg/s]
dumax(5) = 2;  % DEP_col
dumax(6) = 2;  % DEP_slope
dumax(7) = 2;  % HTU

% Convert to rad
dumax(1:4) = deg2rad(dumax(1:4));

%% Save to .mat

loadname="UNIFIER_LOAD_ROMv4_"+timestamp;
save(loadname)
