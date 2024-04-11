
% clc
clear all;
% close all;
format compact;

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata_trajopt\UNIFIERLanding_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Set Flap Deflection

dFlap = deg2rad(12);
global controls
controls.dFlap = dFlap;

%% Run Problem

tic
[problem,guess]      = UNIFIERLanding;        % Fetch the problem definition
options              = problem.settings(2200); % Get options and solver settings 
[solution,MRHistory] = solveMyProblem(problem,guess,options);
t_run=toc;

%% Plot Figures

close all

% calculate airspeed & angle of attack
Va    = sqrt(solution.X(:,3).^2+solution.X(:,4).^2);
alpha = atan2(solution.X(:,4),solution.X(:,3));

% physical trajectory -----------------------------------------------------

fig(1)=figure('Name','Physical Trajectory and Airspeed','Position', [50 450 1200 400]);
plot(solution.X(:,1)/1000,-1*solution.X(:,2),'.-k')
title('Altitude vs Horizontal Distance')
xlabel('Horizontal Distance, km')
ylabel('Altitude, m')
grid on

% control histories ---------------------------------------------------------

fig(2)=figure('Name','Control Histories','Position', [900 75 600 500]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile
plot(solution.T,solution.U(:,2),'.-k')
title('DEP Thrust Level')
xlabel('Time, s')
ylabel('DEP_c_o_l, 0-1')
grid on
nexttile
plot(solution.T,solution.U(:,3),'.-k')
title('HTU Thrust Level')
xlabel('Time, s')
ylabel('HTU, 0-1')
grid on
nexttile
plot(solution.T,rad2deg(solution.U(:,1)),'.-k')
title('Elevator Deflection')
xlabel('Time, s')
ylabel('\delta_E_l_e_v, deg')
yline(0,':b','LineWidth',1)
grid on
nexttile
plot(solution.T,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solution.T)),'.-k')
% plot(solution.T,rad2deg(solution.U(:,4)),'.-k')
title('Flap Deflection')
xlabel('Time, s')
ylabel('\delta_F_l_a_p, deg')
ylim([-5 15])
yline(0,':b','LineWidth',1)
grid on

% state histories ---------------------------------------------------------

fig(3)=figure('Name','State Histories','Position', [50 75 1000 500]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile
plot(solution.T,solution.X(:,1)/1000,'.-k')
title('Horizontal Distance')
xlabel('Time, s')
ylabel('Horizontal Distance, km')
grid on
nexttile
plot(solution.T,-1*solution.X(:,2),'.-k')
title('Altitude')
xlabel('Time, s')
ylabel('Altitude, m')
grid on
nexttile
plot(solution.T,rad2deg(solution.X(:,5)),'.-k')
title('Pitch Angle')
xlabel('Time, s')
ylabel('\theta, deg')
yline(0,':b','LineWidth',1)
grid on
nexttile
plot(solution.T,Va,'.-k')
title('Airspeed')
xlabel('Time, s')
ylabel('Va, m/s')
grid on
vminlabel=['V_m_i_n= ' num2str(round(min(Va),2)) ' m/s'];
yline(35.85*1.3,'-.r',{'V_s_t_a_l_l*1.3 = 46.6 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
ylim([40 80])
nexttile
plot(solution.T,rad2deg(alpha),'.-k')
title('AoA')
xlabel('Time, s')
ylabel('\alpha, deg')
yline(0,':b','LineWidth',1)
grid on
nexttile
plot(solution.T,rad2deg(solution.X(:,6)),'.-k')
title('Pitch Rate')
xlabel('Time, s')
ylabel('q, deg/s')
yline(0,':b','LineWidth',1)
grid on

%% Save results

% save figures
savefig(fig,logname + '_figs');
clear fig

% save workspace
save(logname);

% end diary
diary off
