clear all

% addpath(genpath(pwd))

%% Aircraft Data

load UNIFIER_LOAD.mat

%% Reference trajectory

load UNIFIERLanding_20240524_162938.mat solution Va alpha % prelim results
% load rundata_trajopt/UNIFIERLanding_20240613_232402.mat solution Va alpha rodft % v1
% load rundata_trajopt/UNIFIERLanding_20240613_192010.mat solution Va alpha rodft % v2
% load rundata_trajopt/UNIFIERLanding_20240613_190735.mat solution Va alpha rodft % v3
t_sim=solution.tf;

%% ROM

load UNIFIER_ROM_50.mat
ROMv1 = ROM;
clear ROM

load UNIFIER_ROMv2_20240613_053529.mat
ROMv2 = ROM;
clear ROM

load UNIFIER_ROMv3_20240613_002318.mat
ROMv3 = ROM;
clear ROM

%% Trim data

% load UNIFIER_trim_out_20240612_031926.mat xstar ustar % HFM cruise 0 flap
load UNIFIER_trim_out_20240612_032607.mat xstar ustar % HFM cruise 5 flap
% load UNIFIER_trim_out_20240612_032933.mat xstar ustar % HFM cruise 12 flap
U_trim = [ustar(3);
          ustar(4);
          ustar(5);
          ustar(7)];

% u1_0 = [ustar(1), -1*ustar(1), ustar(3)-ustar(2), ustar(3)+ustar(2), ustar(4), ustar(4)];
% u2_0 = ones(1,12) .* ustar(5);
% u3_0 = ustar(7);
% u4_0 = 0;

Va0    = sqrt(xstar(4)^2+xstar(6)^2);
theta0 = xstar(8);
q0     = xstar(11);
alpha0 = atan2(xstar(6),xstar(4));
x0     = xstar(1);
z0     = xstar(3);

Xe0     = xstar(1:3)';
Vb0     = xstar(4:6)';
Euler0  = xstar(7:9)';
omegab0 = xstar(10:12)';
