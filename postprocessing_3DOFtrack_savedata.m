
% clc
% clear all
% close all

% Generate timestamp
starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata_tracking\UNIFIER_3DOFsim_track_' + timestamp; % name of diary & data log file

% Calculate LSED
tsol    = solution.T(1:end-0);
xsol    = solution.X(1:end-0,1);
zsol    = solution.X(1:end-0,2);

xres    = interp1(out.tout,out.x,tsol);
zres    = interp1(out.tout,out.z,tsol);

dist_x  = xres-xsol;
dist_z  = zres-zsol;
dist    = sqrt(dist_x.^2+dist_z.^2);

LSED    = norm(dist);
LSEDavg = mean(dist)

% Summarize run
runset = [timestamp timestamprun num2str(runconfig.ROMfile) num2str(LSEDavg)];

% Save workspace
% save(logname ,"solution","out","runset","LSED","LSEDavg");