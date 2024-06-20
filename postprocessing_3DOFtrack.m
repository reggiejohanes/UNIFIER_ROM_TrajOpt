
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


%% Plot figures

close all

% state trajectories ------------------------------------------------------
fig(1)=figure('Name','State Trajectories (vs distance)','Position', [50 75 400 1250]);
tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
% fig(1)=figure('Name','State Trajectories','Position', [5 75 1200 400]);
% tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
plottraj1=plot(solution.X(:,1),-1*solution.X(:,2),'r');
hold on
plottraj2=plot(res.x,-1*res.z,'b');
% title('Altitude')
% xlabel('x, m')
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])

% rate of climb
nexttile
plot(solution.X(:,1),Va,'r')
hold on
plot(res.x,res.Va,'b')
% title('Airspeed')
% xlabel('x, m')
ylabel('Rate of Climb, ft/min')
grid on
% vminlabel=['V_m_i_n= ' num2str(round(min(Va),2)) ' m/s'];
% yline(35.85*1.3,'-.r',{'V_s_t_a_l_l*1.3 = 46.6 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
% ylim([55 80])
% xlim([0 12.5])

% airspeed
nexttile
plot(solution.X(:,1),Va,'r')
hold on
plot(res.x,res.Va,'b')
% title('Airspeed')
% xlabel('x, m')
ylabel('Airspeed, m/s')
grid on
% vminlabel=['V_m_i_n= ' num2str(round(min(Va),2)) ' m/s'];
% yline(35.85*1.3,'-.r',{'V_s_t_a_l_l*1.3 = 46.6 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
% ylim([55 80])
% xlim([0 12.5])

% angle of attack
nexttile
plot(solution.X(:,1),rad2deg(alpha),'r')
hold on
plot(res.x,rad2deg(res.alpha),'b')
% title('AoA')
% xlabel('Distance, m')
ylabel('Angle of Attack, deg')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

% pitch angle
nexttile
plot(solution.X(:,1),rad2deg(solution.X(:,5)),'r')
hold on
plot(res.x,rad2deg(res.theta),'b')
% title('Pitch Angle')
% xlabel('x, m')
ylabel('Pitch Angle, deg')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

%pitch rate
nexttile
plot(solution.X(:,1),rad2deg(solution.X(:,6)),'r')
hold on
plot(res.x,rad2deg(res.q),'b')
% title('Pitch Rate')
xlabel('Distance, m')
ylabel('Pitch Rate, deg/s')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

% state trajectories (time) -----------------------------------------------
fig(2)=figure('Name','State Trajectories (vs distance)','Position', [500 75 800 400]);
tiledlayout(1,2,"TileSpacing","tight","Padding","compact")
% fig(1)=figure('Name','State Trajectories','Position', [5 75 1200 400]);
% tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
plottraj1=plot(solution.T,-1*solution.X(:,2),'r');
hold on
plottraj2=plot(res.t,-1*res.z,'b');
% title('Altitude')
xlabel('Time, s')
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])

% distance
nexttile
plottraj1=plot(solution.T,solution.X(:,1),'r');
hold on
plottraj2=plot(res.t,res.x,'b');
% title('Altitude')
xlabel('Time, s')
ylabel('Distance, m')
grid on
% legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])

% control trajectories ----------------------------------------------------

fig(3)=figure('Name','Control Inputs','Position', [600 70 500 800]);
tiledlayout(5,1,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
plottraj1=plot(solution.X(:,1),-1*solution.X(:,2),'r');
hold on
plottraj2=plot(res.x,-1*res.z,'b');
% title('Altitude')
% xlabel('x, m')
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])

% DEP
nexttile
plot(solution.X(:,1),solution.U(:,2),'r')
hold on
plot(res.x,res.DEP_col,'b');
% plot
% title('DEP Thrust Level')
% xlabel('x, m')
ylabel('DEP_c_o_l, 0-1')
grid on
yline(0,':k','LineWidth',1)
% ylim([-0.05 0.35])
% xlim([0 12.5])

% HTU
nexttile
plot(solution.X(:,1),solution.U(:,3),'r')
hold on
plot(res.x,res.HTU,'b');
% title('HTU Thrust Level')
% xlabel('x, m')
ylabel('HTU, 0-1')
grid on
yline(0,':k','LineWidth',1)
% ylim([-0.75 1])
% xlim([0 12.5])

% elevator deflection
nexttile
plot(solution.X(:,1),rad2deg(solution.U(:,1)),'r')
hold on
plot(res.x,rad2deg(res.elev),'b');
% title('Elevator Deflection')
% xlabel('x, m')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

% flap deflection
nexttile
plot(solution.X(:,1),linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solution.T)),'r')
hold on
plot(res.x,rad2deg(res.flap),'b');
% title('Flap Deflection')
xlabel('Distance, m')
ylabel('Flap Deflection, deg')
% ylim([-5 15])
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])


%% Save results

% save figures
savefig(fig,logname + '_figs');
clear fig

% save workspace
save(logname);