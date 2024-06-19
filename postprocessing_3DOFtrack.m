
% clc
% clear all
% close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIERsim_' + timestamp; % name of diary & data log file

%% Calculate error

% LSED

tsol    = solution.T(1:end-1);
xsol    = solution.X(1:end-1,1);
zsol    = solution.X(1:end-1,2);

xres    = interp1(out.tout,out.x,tsol);
zres    = interp1(out.tout,out.z,tsol);

dist_x  = xres-xsol;
dist_z  = zres-zsol;
dist    = sqrt(dist_x.^2+dist_z.^2);

LSED    = norm(dist)
LSEDavg = mean(dist)