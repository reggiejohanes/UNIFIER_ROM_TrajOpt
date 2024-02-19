
clc
clear all;
close all;
format compact;

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata_trajopt\UNIFIERLanding_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Run Problem

tic
[problem,guess]      = UNIFIERLanding;        % Fetch the problem definition
options              = problem.settings(500); % Get options and solver settings 
[solution,MRHistory] = solveMyProblem(problem,guess,options);
t_run=toc;

%% Plot Figures

% close all

% control histories ---------------------------------------------------------

fig(1)=figure('Name','Control Histories','Position', [900 75 600 500]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile
plot(solution.T,rad2deg(solution.U(:,1)),'.-k')
title('Time vs Elevator Deflection')
xlabel('Time, s')
ylabel('\delta_E_l_e_v, deg')
yline(0,'-.r','LineWidth',2)
grid on
nexttile
plot(solution.T,rad2deg(solution.U(:,2)),'.-k')
title('Time vs Flap Deflection')
xlabel('Time, s')
ylabel('\delta_F_l_a_p, deg')
grid on
nexttile
plot(solution.T,solution.U(:,3),'.-k')
title('Time vs DEP Thrust Level')
xlabel('Time, s')
ylabel('DEP_c_o_l, 0-1')
grid on
nexttile
plot(solution.T,solution.U(:,4),'.-k')
title('Time vs HTU Thrust Level')
xlabel('Time, s')
ylabel('HTU, 0-1')
grid on

% state histories ---------------------------------------------------------

fig(2)=figure('Name','State Histories','Position', [50 75 1000 500]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile
plot(solution.T,solution.X(:,1)/1000,'.-k')
title('Time vs Horizontal Distance')
xlabel('Time, s')
ylabel('Horizontal Distance, km')
grid on
nexttile
plot(solution.T,-1*solution.X(:,2),'.-k')
title('Time vs Altitude')
xlabel('Time, s')
ylabel('Altitude, m')
grid on
nexttile
plot(solution.T,rad2deg(solution.X(:,5)),'.-k')
title('Time vs Pitch Angle')
xlabel('Time, s')
ylabel('\theta, deg')
yline(0,'-.r','LineWidth',2)
grid on
nexttile
plot(solution.T,solution.X(:,3),'.-k')
title('Time vs X-velocity (Body Axis)')
xlabel('Time, s')
ylabel('u, m/s')
grid on
nexttile
plot(solution.T,-1*solution.X(:,4),'.-k')
title('Time vs Z-velocity (Body Axis)')
xlabel('Time, s')
ylabel('-w, m/s')
yline(0,'-.r','LineWidth',2)
grid on
nexttile
plot(solution.T,rad2deg(solution.X(:,6)),'.-k')
title('Time vs Pitch Rate')
xlabel('Time, s')
ylabel('q, deg/s')
yline(0,'-.r','LineWidth',2.)
grid on

% physical trajectory -----------------------------------------------------

fig(3)=figure('Name','Physical Trajectory and Airspeed','Position', [50 450 1450 400]);
tiledlayout(1,3,"TileSpacing","tight","Padding","compact")
nexttile([1,2])
plot(solution.X(:,1)/1000,-1*solution.X(:,2),'.-k')
title('Altitude vs Horizontal Distance')
xlabel('Horizontal Distance, km')
ylabel('Altitude, m')
grid on
nexttile
plot(solution.T,Va,'.-k')
title('Time vs Airspeed')
xlabel('Time, s')
ylabel('Airspeed, m/s')
grid on

%% Save results

% save figures
savefig(fig,logname + '_figs');
clear fig

% save workspace
save(logname);

% end diary
diary off
