

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIERsim_' + timestamp; % name of diary & data log file

%% Assign variables

res.t             = out.tout;
res.alpha         = out.states(:,1);
res.x             = out.states(:,2);
res.z             = out.states(:,3);
res.theta         = out.states(:,4);
res.q             = out.states(:,5);
res.Va            = out.states(:,6);
res.Va_ref        = out.Va_ctrl(:,1);
res.thr_cmd       = out.Va_ctrl(:,2);
res.Ze_ref        = out.alt_ctrl(:,1);
res.theta_cmd     = out.alt_ctrl(:,2);
res.q_cmd         = out.alt_ctrl(:,3);
res.elev_cmd      = out.alt_ctrl(:,4);
res.elev_cmd_trim = out.u_cmd_trim(:,1);
res.DEP_cmd_trim  = out.u_cmd_trim(:,2);
res.HTU_cmd_trim  = out.u_cmd_trim(:,3);
res.flap_cmd_trim = out.u_cmd_trim(:,4);
res.elev          = out.u_cmd_trim_lim(:,1);
res.DEP_col       = out.u_cmd_trim_lim(:,2);
res.HTU           = out.u_cmd_trim_lim(:,3);
res.flap          = out.u_cmd_trim_lim(:,4);

%% Plots

close all

% state trajectories ------------------------------------------------------
fig(1)=figure('Name','State Trajectories','Position', [5 75 400 1250]);
tiledlayout(6,1,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
plottraj1=plot(solution.X(:,1)/1000,-1*solution.X(:,2),'r');
hold on
plottraj2=plot(res.x/1000,-1*res.z,'b');
% title('Altitude')
% xlabel('x, km')
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])

% rate of climb
nexttile
plot(solution.X(:,1)/1000,Va,'r')
hold on
plot(res.x/1000,res.Va,'b')
% title('Airspeed')
% xlabel('x, km')
ylabel('Rate of Climb, ft/min')
grid on
% vminlabel=['V_m_i_n= ' num2str(round(min(Va),2)) ' m/s'];
% yline(35.85*1.3,'-.r',{'V_s_t_a_l_l*1.3 = 46.6 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
% ylim([55 80])
% xlim([0 12.5])

% airspeed
nexttile
plot(solution.X(:,1)/1000,Va,'r')
hold on
plot(res.x/1000,res.Va,'b')
% title('Airspeed')
% xlabel('x, km')
ylabel('Airspeed, m/s')
grid on
% vminlabel=['V_m_i_n= ' num2str(round(min(Va),2)) ' m/s'];
% yline(35.85*1.3,'-.r',{'V_s_t_a_l_l*1.3 = 46.6 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
% ylim([55 80])
% xlim([0 12.5])

% angle of attack
nexttile
plot(solution.X(:,1)/1000,rad2deg(alpha),'r')
hold on
plot(res.x/1000,rad2deg(res.alpha),'b')
% title('AoA')
% xlabel('x, km')
ylabel('Angle of Attack, deg')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

% pitch angle
nexttile
plot(solution.X(:,1)/1000,rad2deg(solution.X(:,5)),'r')
hold on
plot(res.x/1000,rad2deg(res.theta),'b')
% title('Pitch Angle')
% xlabel('x, km')
ylabel('Pitch Angle, deg')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

%pitch rate
nexttile
plot(solution.X(:,1)/1000,rad2deg(solution.X(:,6)),'r')
hold on
plot(res.x/1000,rad2deg(res.q),'b')
% title('Pitch Rate')
xlabel('Distance, km')
ylabel('Pitch Rate, deg/s')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

% control trajectories ----------------------------------------------------

fig(2)=figure('Name','Control Inputs','Position', [600 70 500 800]);
tiledlayout(5,1,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
plottraj1=plot(solution.X(:,1)/1000,-1*solution.X(:,2),'r');
hold on
plottraj2=plot(res.x/1000,-1*res.z,'b');
% title('Altitude')
% xlabel('x, km')
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])

% DEP
nexttile
plot(solution.X(:,1)/1000,solution.U(:,2),'r')
hold on
plot(res.x/1000,res.DEP_col,'b');
% plot
% title('DEP Thrust Level')
% xlabel('x, km')
ylabel('DEP_c_o_l, 0-1')
grid on
yline(0,':k','LineWidth',1)
% ylim([-0.05 0.35])
% xlim([0 12.5])

% HTU
nexttile
plot(solution.X(:,1)/1000,solution.U(:,3),'r')
hold on
plot(res.x/1000,res.HTU,'b');
% title('HTU Thrust Level')
% xlabel('x, km')
ylabel('HTU, 0-1')
grid on
yline(0,':k','LineWidth',1)
% ylim([-0.75 1])
% xlim([0 12.5])

% elevator deflection
nexttile
plot(solution.X(:,1)/1000,rad2deg(solution.U(:,1)),'r')
hold on
plot(res.x/1000,rad2deg(res.elev),'b');
% title('Elevator Deflection')
% xlabel('x, km')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
yline(0,':k','LineWidth',1)
grid on
% xlim([0 12.5])

% flap deflection
nexttile
plot(solution.X(:,1)/1000,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solution.T)),'r')
hold on
plot(res.x/1000,rad2deg(res.flap),'b');
% title('Flap Deflection')
xlabel('Distance, km')
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
