
% clc
clear all
% close all

%% Aircraft Data

load data\UNIFIER_LOAD.mat

%% Aerodynamic data & trim conditions



%% Reference trajectory

load rundata_trajopt/UNIFIERLanding_20240524_162938.mat solution Va alpha % prelim results
% load rundata_trajopt/UNIFIERLanding_20240613_232402.mat solution Va alpha rodft % v1
% load rundata_trajopt/UNIFIERLanding_20240613_192010.mat solution Va alpha rodft % v2
% load rundata_trajopt/UNIFIERLanding_20240613_190735.mat solution Va alpha rodft % v3