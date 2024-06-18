clear

% addpath(genpath(pwd))

%% Aircraft Data

load UNIFIER_LOAD.mat

%% Reference trajectory

% load UNIFIERLanding_20240524_162938.mat solution Va alpha % prelim results
load rundata_trajopt/UNIFIERLanding_20240613_232402.mat solution Va alpha rodft % v1
% load rundata_trajopt/UNIFIERLanding_20240613_192010.mat solution Va alpha rodft % v2
% load rundata_trajopt/UNIFIERLanding_20240613_190735.mat solution Va alpha rodft % v3
t_sim=solution.tf;


%% Trim data

load UNIFIER_trim_out_20240612_031926.mat xstar ustar % HFM cruise 0 flap
% load UNIFIER_trim_out_20240612_032607.mat xstar ustar % HFM cruise 5 flap
% load UNIFIER_trim_out_20240612_032933.mat xstar ustar % HFM cruise 12 flap

u_trim = ustar;

u1_0 = [ustar(1), -1*ustar(1), ustar(3)-ustar(2), ustar(3)+ustar(2), ustar(4), ustar(4)];
u2_0 = ones(1,12) .* ustar(5);
u3_0 = ustar(7);
u4_0 = 0;

Xe0     = xstar(1:3)';
Vb0     = xstar(4:6)';
Euler0  = xstar(7:9)';
omegab0 = xstar(10:12)';


