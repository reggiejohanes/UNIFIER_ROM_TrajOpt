
% clc
clear all
% close all

% Documentation

% starttime = datetime; % start date & time
% timestamp = string(starttime,"yyyyMMdd_HHmmss");
% logname   = 'rundata\UNIFIERsim_' + timestamp; % name of diary & data log file

% Load data

% v1 ----------------------------------------------------------------------
load rundata_tracking/UNIFIER_3DOFsim_track_20240620_192011.mat solution out % v1
solv1 = solution;
outv1 = out;
clear sol out
% calculate Va, alpha, RoC
solv1.Va    = sqrt(solv1.X(:,3).^2+solv1.X(:,4).^2);
solv1.alpha = atan2(solv1.X(:,4),solv1.X(:,3)); 
for i=1:numel(solv1.T)-1
    solv1.rod(i)=(solv1.X(i+1,2)-solv1.X(i,2))/(solv1.T(i+1)-solv1.T(i));
end
solv1.rocft=convvel(solv1.rod,'m/s','ft/min')*-1;
outv1.rod=0;
for i=1:numel(outv1.tout)-1
    outv1.rod(i)=(outv1.z(i+1)-outv1.z(i))/(outv1.tout(i+1)-outv1.tout(i));
end
outv1.rocft=convvel(outv1.rod,'m/s','ft/min')*-1;

% v2 ----------------------------------------------------------------------
load rundata_tracking/UNIFIER_3DOFsim_track_20240620_192721.mat solution out % v2
solv2 = solution;
outv2 = out;
clear sol out
% calculate Va, alpha, RoC
solv2.Va    = sqrt(solv2.X(:,3).^2+solv2.X(:,4).^2);
solv2.alpha = atan2(solv2.X(:,4),solv2.X(:,3)); 
for i=1:numel(solv2.T)-1
    solv2.rod(i)=(solv2.X(i+1,2)-solv2.X(i,2))/(solv2.T(i+1)-solv2.T(i));
end
solv2.rocft=convvel(solv2.rod,'m/s','ft/min')*-1;
outv2.rod=0;
for i=1:numel(outv2.tout)-1
    outv2.rod(i)=(outv2.z(i+1)-outv2.z(i))/(outv2.tout(i+1)-outv2.tout(i));
end
outv2.rocft=convvel(outv2.rod,'m/s','ft/min')*-1;

% v3 ----------------------------------------------------------------------
load rundata_tracking/UNIFIER_3DOFsim_track_20240620_194050.mat solution out % v3
solv3 = solution;
outv3 = out;
clear sol out
% calculate Va, alpha, RoC
solv3.Va    = sqrt(solv3.X(:,3).^2+solv3.X(:,4).^2);
solv3.alpha = atan2(solv3.X(:,4),solv3.X(:,3)); 
for i=1:numel(solv3.T)-1
    solv3.rod(i)=(solv3.X(i+1,2)-solv3.X(i,2))/(solv3.T(i+1)-solv3.T(i));
end
solv3.rocft=convvel(solv3.rod,'m/s','ft/min')*-1;
outv3.rod=0;
for i=1:numel(outv3.tout)-1
    outv3.rod(i)=(outv3.z(i+1)-outv3.z(i))/(outv3.tout(i+1)-outv3.tout(i));
end
outv3.rocft=convvel(outv3.rod,'m/s','ft/min')*-1;

%% Calculate error

% v1 ----------------------------------------------------------------------

tsolv1    = solv1.T(1:end-0);
xsolv1    = solv1.X(1:end-0,1);
zsolv1    = solv1.X(1:end-0,2);

xoutv1v1    = interp1(outv1.tout,outv1.x,tsolv1);
zoutv1v1    = interp1(outv1.tout,outv1.z,tsolv1);

dist_xv1  = xoutv1v1-xsolv1;
dist_zv1  = zoutv1v1-zsolv1;
distv1    = sqrt(dist_xv1.^2+dist_zv1.^2);

LSEDv1    = norm(distv1);
LSEDavgv1 = mean(distv1)

% v2 ----------------------------------------------------------------------

tsolv2    = solv2.T(1:end-0);
xsolv2    = solv2.X(1:end-0,1);
zsolv2    = solv2.X(1:end-0,2);

xoutv1v2    = interp1(outv2.tout,outv2.x,tsolv2);
zoutv1v2    = interp1(outv2.tout,outv2.z,tsolv2);

dist_xv2  = xoutv1v2-xsolv2;
dist_zv2  = zoutv1v2-zsolv2;
distv2    = sqrt(dist_xv2.^2+dist_zv2.^2);

LSEDv2    = norm(distv2);
LSEDavgv2 = mean(distv2)

% v3 ----------------------------------------------------------------------

tsolv3    = solv3.T(1:end-0);
xsolv3    = solv3.X(1:end-0,1);
zsolv3    = solv3.X(1:end-0,2);

xoutv1v3    = interp1(outv3.tout,outv3.x,tsolv3);
zoutv1v3    = interp1(outv3.tout,outv3.z,tsolv3);

dist_xv3  = xoutv1v3-xsolv3;
dist_zv3  = zoutv1v3-zsolv3;
distv3    = sqrt(dist_xv3.^2+dist_zv3.^2);

LSEDv3    = norm(distv3);
LSEDavgv3 = mean(distv3)

%% Plot error

fig(1)=figure('Name','State Trajectories (vs distance)','Position', [120 200 600 400]);
hold on
p1=plot(tsolv1,distv1,'-g','LineWidth',1);
p2=plot(tsolv2,distv2,'-m','LineWidth',1);
p3=plot(tsolv3,distv3,'-c','LineWidth',1);
grid on
ylabel('Tracking Error (Euclidean Distance, m)')
xlabel('Time, s')
% yline(LSEDavgv1,'-.b',{'v1 avg. = 0.47'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
% yline(LSEDavgv2,'-.m',{'v2 avg. = 0.52'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
% yline(LSEDavgv3,'-.r',{'v3 avg. = 0.57'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
legend([p1 p2 p3],...
       {'ROM v1','ROM v2','ROM v3'},...
       'Location','northwest','NumColumns',3);

%% Plot figures (v1)

% state trajectories ======================================================
% fig(2)=figure('Name','State Trajectories (vs distance) v1','Position', [50 75 400 1250]);
% tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
fig(2)=figure('Name','State Trajectories (vs distance) v1','Position', [5 75 1200 600]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE ------------------------------------------------------- 
hold on
plottraj2=plot(outv1.x/1000,-1*outv1.z,'r');
plottraj1=plot(solv1.X(:,1)/1000,-1*solv1.X(:,2),'--k');
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])
nexttile % RATE OF CLIMB --------------------------------------------------
hold on
plot(outv1.x(1:end-1)/1000,outv1.rocft,'r')
plot(solv1.X(1:end-1,1)/1000,solv1.rocft,'--k')
ylabel('Rate of Climb, ft/min')
grid on
% ylim([55 80])
% xlim([0 12.5])
nexttile % AIRSPEED -------------------------------------------------------
hold on
plot(outv1.x/1000,outv1.Va_tas,'r')
plot(solv1.X(:,1)/1000,solv1.Va,'--k')
% title('Airspeed')
% xlabel('x, m')
ylabel('Airspeed, m/s')
grid on
% ylim([55 80])
% xlim([0 12.5])
nexttile % ANGLE OF ATTACK ------------------------------------------------
hold on
plot(outv1.x/1000,rad2deg(outv1.alpha),'r')
plot(solv1.X(:,1)/1000,rad2deg(solv1.alpha),'--k')
% title('AoA')
% xlabel('Distance, m')
ylabel('Angle of Attack, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % PITCH ANGLE ----------------------------------------------------
hold on
plot(outv1.x/1000,rad2deg(outv1.theta),'r')
plot(solv1.X(:,1)/1000,rad2deg(solv1.X(:,5)),'--k')
% title('Pitch Angle')
% xlabel('x, m')
ylabel('Pitch Angle, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % PITCH RATE -----------------------------------------------------
hold on
plot(outv1.x/1000,rad2deg(outv1.q),'r')
plot(solv1.X(:,1)/1000,rad2deg(solv1.X(:,6)),'--k')
% title('Pitch Rate')
xlabel('Distance, km')
ylabel('Pitch Rate, deg/s')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])

% control trajectories ====================================================
% fig(3)=figure('Name','Control Inputs v1','Position', [600 70 500 800]);
% tiledlayout(4,1,"TileSpacing","tight","Padding","compact")
fig(3)=figure('Name','Control Inputs v1','Position', [600 70 800 600]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
% nexttile % ALTITUDE -----------------------------------------------------
% plottraj1=plot(solv1.X(:,1),-1*solv1.X(:,2),'--k');
% hold on
% plottraj2=plot(outv1.x,-1*outv1.z,'r');
% % title('Altitude')
% % xlabel('x, m')
% ylabel('Altitude, m')
% grid on
% legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% % xlim([0 12.5])
nexttile % DEP ------------------------------------------------------------
hold on
plot(outv1.x/1000,outv1.DEP,'r');
plot(solv1.X(:,1)/1000,solv1.U(:,2),'--k')
% plot
% title('DEP Thrust Level')
% xlabel('x, m')
ylabel('DEP_c_o_l, 0-1')
grid on
% yline(0,'--k','LineWidth',1)
ylim([-0.05 0.5])
% xlim([0 12.5])
nexttile % HTU ------------------------------------------------------------
hold on
p2=plot(outv1.x/1000,outv1.HTU,'r');
p1=plot(solv1.X(:,1)/1000,solv1.U(:,3),'--k');
% title('HTU Thrust Level')
% xlabel('x, m')
ylabel('HTU, 0-1')
grid on
% yline(0,'--k','LineWidth',1)
% ylim([-0.75 1])
% xlim([0 12.5])
% legend([p1 p2],...
%        {'Optimal Trajectory','Tracking Result'},...
%        'Location','northwest','NumColumns',2);
nexttile % ELEVATOR -------------------------------------------------------
hold on
plot(outv1.x/1000,rad2deg(outv1.elev),'r');
plot(solv1.X(:,1)/1000,rad2deg(solv1.U(:,1)),'--k')
% title('Elevator Deflection')
% xlabel('x, m')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % FLAP -----------------------------------------------------------
dFlap=deg2rad(5);
hold on
p2=plot(outv1.x/1000,rad2deg(outv1.flap),'r');
p1=plot(solv1.X(:,1)/1000,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solv1.T)),'--k');
% title('Flap Deflection')
xlabel('Distance, km')
ylabel('Flap Deflection, deg')
% ylim([-5 15])
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
legend([p1 p2],...
       {'Optimal Trajectory','Tracking Result'},...
       'Location','south','NumColumns',2);

% state trajectories (time) ===============================================
% fig(3)=figure('Name','State Trajectories (vs time) v1','Position', [500 75 800 400]);
% tiledlayout(1,2,"TileSpacing","tight","Padding","compact")
% % fig(1)=figure('Name','State Trajectories','Position', [5 75 1200 400]);
% % tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
% nexttile % ALTITUDE -------------------------------------------------------
% hold on
% plottraj2=plot(outv1.tout,-1*outv1.z,'r');
% plottraj1=plot(solv1.T,-1*solv1.X(:,2),'--k');
% % title('Altitude')
% xlabel('Time, s')
% ylabel('Altitude, m')
% grid on
% legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% % xlim([0 12.5])
% nexttile % DISTANCE -------------------------------------------------------
% hold on
% plottraj2=plot(outv1.tout,outv1.tout/1000,'r');
% plottraj1=plot(solv1.T,solv1.X(:,1)/1000,'--k');
% % title('Altitude')
% xlabel('Time, s')
% ylabel('Distance, km')
% grid on
% % legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% % xlim([0 12.5])

%% Plot figures (v2)

% state trajectories ======================================================
% fig(4)=figure('Name','State Trajectories (vs distance) v2','Position', [50 75 400 1250]);
% tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
fig(4)=figure('Name','State Trajectories (vs distance) v2','Position', [50 75 1200 600]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE ------------------------------------------------------- 
hold on
plottraj2=plot(outv2.x/1000,-1*outv2.z,'r');
plottraj1=plot(solv2.X(:,1)/1000,-1*solv2.X(:,2),'--k');
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])
nexttile % RATE OF CLIMB --------------------------------------------------
hold on
plot(outv2.x(1:end-1)/1000,outv2.rocft,'r')
plot(solv2.X(1:end-1,1)/1000,solv2.rocft,'--k')
ylabel('Rate of Climb, ft/min')
grid on
% ylim([55 80])
% xlim([0 12.5])
nexttile % AIRSPEED -------------------------------------------------------
hold on
plot(outv2.x/1000,outv2.Va_tas,'r')
plot(solv2.X(:,1)/1000,solv2.Va,'--k')
% title('Airspeed')
% xlabel('x, m')
ylabel('Airspeed, m/s')
grid on
% ylim([55 80])
% xlim([0 12.5])
nexttile % ANGLE OF ATTACK ------------------------------------------------
hold on
plot(outv2.x/1000,rad2deg(outv2.alpha),'r')
plot(solv2.X(:,1)/1000,rad2deg(solv2.alpha),'--k')
% title('AoA')
% xlabel('Distance, m')
ylabel('Angle of Attack, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % PITCH ANGLE ----------------------------------------------------
hold on
plot(outv2.x/1000,rad2deg(outv2.theta),'r')
plot(solv2.X(:,1)/1000,rad2deg(solv2.X(:,5)),'--k')
% title('Pitch Angle')
% xlabel('x, m')
ylabel('Pitch Angle, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % PITCH RATE -----------------------------------------------------
hold on
plot(outv2.x/1000,rad2deg(outv2.q),'r')
plot(solv2.X(:,1)/1000,rad2deg(solv2.X(:,6)),'--k')
% title('Pitch Rate')
xlabel('Distance, km')
ylabel('Pitch Rate, deg/s')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])

% control trajectories ====================================================
% fig(5)=figure('Name','Control Inputs v2','Position', [600 70 500 800]);
% tiledlayout(4,1,"TileSpacing","tight","Padding","compact")
fig(5)=figure('Name','Control Inputs v2','Position', [600 70 800 600]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
% nexttile % ALTITUDE -----------------------------------------------------
% plottraj1=plot(solv2.X(:,1),-1*solv2.X(:,2),'--k');
% hold on
% plottraj2=plot(outv2.x,-1*outv2.z,'r');
% % title('Altitude')
% % xlabel('x, m')
% ylabel('Altitude, m')
% grid on
% legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% % xlim([0 12.5])
nexttile % DEP ------------------------------------------------------------
hold on
plot(outv2.x/1000,outv2.DEP,'r');
plot(solv2.X(:,1)/1000,solv2.U(:,2),'--k')
% plot
% title('DEP Thrust Level')
% xlabel('x, m')
ylabel('DEP_c_o_l, 0-1')
grid on
% yline(0,'--k','LineWidth',1)
ylim([-0.05 0.65])
% xlim([0 12.5])
nexttile % HTU ------------------------------------------------------------
hold on
p2=plot(outv2.x/1000,outv2.HTU,'r');
p1=plot(solv2.X(:,1)/1000,solv2.U(:,3),'--k');
% title('HTU Thrust Level')
% xlabel('x, m')
ylabel('HTU, 0-1')
grid on
% yline(0,'--k','LineWidth',1)
% ylim([-0.75 1])
% xlim([0 12.5])
% legend([p1 p2],...
%        {'Optimal Trajectory','Tracking Result'},...
%        'Location','northwest','NumColumns',2);
nexttile % ELEVATOR -------------------------------------------------------
hold on
plot(outv2.x/1000,rad2deg(outv2.elev),'r');
plot(solv2.X(:,1)/1000,rad2deg(solv2.U(:,1)),'--k')
% title('Elevator Deflection')
% xlabel('x, m')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % FLAP -----------------------------------------------------------
dFlap=deg2rad(5);
hold on
p2=plot(outv2.x/1000,rad2deg(outv2.flap),'r');
p1=plot(solv2.X(:,1)/1000,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solv2.T)),'--k');
% title('Flap Deflection')
xlabel('Distance, km')
ylabel('Flap Deflection, deg')
% ylim([-5 15])
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
legend([p1 p2],...
       {'Optimal Trajectory','Tracking Result'},...
       'Location','south','NumColumns',2);

%% Plot figures (v3)

% state trajectories ======================================================
% fig(6)=figure('Name','State Trajectories (vs distance) v3','Position', [50 75 400 1250]);
% tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
fig(6)=figure('Name','State Trajectories (vs distance) v3','Position', [50 75 1200 600]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE ------------------------------------------------------- 
hold on
plottraj2=plot(outv3.x/1000,-1*outv3.z,'r');
plottraj1=plot(solv3.X(:,1)/1000,-1*solv3.X(:,2),'--k');
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% xlim([0 12.5])
nexttile % RATE OF CLIMB --------------------------------------------------
hold on
plot(outv3.x(1:end-1)/1000,outv3.rocft,'r')
plot(solv3.X(1:end-1,1)/1000,solv3.rocft,'--k')
ylabel('Rate of Climb, ft/min')
grid on
% ylim([55 80])
% xlim([0 12.5])
nexttile % AIRSPEED -------------------------------------------------------
hold on
plot(outv3.x/1000,outv3.Va_tas,'r')
plot(solv3.X(:,1)/1000,solv3.Va,'--k')
% title('Airspeed')
% xlabel('x, m')
ylabel('Airspeed, m/s')
grid on
% ylim([55 80])
% xlim([0 12.5])
nexttile % ANGLE OF ATTACK ------------------------------------------------
hold on
plot(outv3.x/1000,rad2deg(outv3.alpha),'r')
plot(solv3.X(:,1)/1000,rad2deg(solv3.alpha),'--k')
% title('AoA')
% xlabel('Distance, m')
ylabel('Angle of Attack, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % PITCH ANGLE ----------------------------------------------------
hold on
plot(outv3.x/1000,rad2deg(outv3.theta),'r')
plot(solv3.X(:,1)/1000,rad2deg(solv3.X(:,5)),'--k')
% title('Pitch Angle')
% xlabel('x, m')
ylabel('Pitch Angle, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % PITCH RATE -----------------------------------------------------
hold on
plot(outv3.x/1000,rad2deg(outv3.q),'r')
plot(solv3.X(:,1)/1000,rad2deg(solv3.X(:,6)),'--k')
% title('Pitch Rate')
xlabel('Distance, km')
ylabel('Pitch Rate, deg/s')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])

% control trajectories ====================================================
% fig(7)=figure('Name','Control Inputs v3','Position', [600 70 500 800]);
% tiledlayout(4,1,"TileSpacing","tight","Padding","compact")
fig(7)=figure('Name','Control Inputs v3','Position', [600 70 800 600]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
% nexttile % ALTITUDE -----------------------------------------------------
% plottraj1=plot(solv3.X(:,1),-1*solv3.X(:,2),'--k');
% hold on
% plottraj2=plot(outv3.x,-1*outv3.z,'r');
% % title('Altitude')
% % xlabel('x, m')
% ylabel('Altitude, m')
% grid on
% legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
% % xlim([0 12.5])
nexttile % DEP ------------------------------------------------------------
hold on
plot(outv3.x/1000,outv3.DEP,'r');
plot(solv3.X(:,1)/1000,solv3.U(:,2),'--k')
% plot
% title('DEP Thrust Level')
% xlabel('x, m')
ylabel('DEP_c_o_l, 0-1')
grid on
% yline(0,'--k','LineWidth',1)
ylim([-0.05 0.5])
% xlim([0 12.5])
nexttile % HTU ------------------------------------------------------------
hold on
p2=plot(outv3.x/1000,outv3.HTU,'r');
p1=plot(solv3.X(:,1)/1000,solv3.U(:,3),'--k');
% title('HTU Thrust Level')
% xlabel('x, m')
ylabel('HTU, 0-1')
grid on
% yline(0,'--k','LineWidth',1)
% ylim([-0.75 1])
% xlim([0 12.5])
% legend([p1 p2],...
%        {'Optimal Trajectory','Tracking Result'},...
%        'Location','northwest','NumColumns',2);
nexttile % ELEVATOR -------------------------------------------------------
hold on
plot(outv3.x/1000,rad2deg(outv3.elev),'r');
plot(solv3.X(:,1)/1000,rad2deg(solv3.U(:,1)),'--k')
% title('Elevator Deflection')
% xlabel('x, m')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
nexttile % FLAP -----------------------------------------------------------
dFlap=deg2rad(5);
hold on
p2=plot(outv3.x/1000,rad2deg(outv3.flap),'r');
p1=plot(solv3.X(:,1)/1000,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solv3.T)),'--k');
% title('Flap Deflection')
xlabel('Distance, km')
ylabel('Flap Deflection, deg')
% ylim([-5 15])
% yline(0,'--k','LineWidth',1)
grid on
% xlim([0 12.5])
legend([p1 p2],...
       {'Optimal Trajectory','Tracking Result'},...
       'Location','south','NumColumns',2);

%% Plot figures (v1,time)

% state trajectories ======================================================
fig(8)=figure('Name','State Trajectories (vs time) v1','Position', [50 75 400 1250]);
tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
% fig(8)=figure('Name','State Trajectories (vs time) v1','Position', [5 75 1200 600]);
% tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE ------------------------------------------------------- 
hold on
plottraj2=plot(outv1.tout,-1*outv1.z,'r');
plottraj1=plot(solv1.T,-1*solv1.X(:,2),'--k');
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
nexttile % RATE OF CLIMB --------------------------------------------------
hold on
plot(outv1.tout(1:end-1),outv1.rocft,'r')
plot(solv1.T(1:end-1),solv1.rocft,'--k')
ylabel('Rate of Climb, ft/min')
grid on
nexttile % AIRSPEED -------------------------------------------------------
hold on
plot(outv1.tout,outv1.Va_tas,'r')
plot(solv1.T,solv1.Va,'--k')
ylabel('Airspeed, m/s')
grid on
nexttile % ANGLE OF ATTACK ------------------------------------------------
hold on
plot(outv1.tout,rad2deg(outv1.alpha),'r')
plot(solv1.T,rad2deg(solv1.alpha),'--k')
ylabel('Angle of Attack, deg')
grid on
nexttile % PITCH ANGLE ----------------------------------------------------
hold on
plot(outv1.tout,rad2deg(outv1.theta),'r')
plot(solv1.T,rad2deg(solv1.X(:,5)),'--k')
ylabel('Pitch Angle, deg')
grid on
nexttile % PITCH RATE -----------------------------------------------------
hold on
plot(outv1.tout,rad2deg(outv1.q),'r')
plot(solv1.T,rad2deg(solv1.X(:,6)),'--k')
xlabel('Time, s')
ylabel('Pitch Rate, deg/s')
grid on

% control trajectories ====================================================
fig(9)=figure('Name','Control Inputs v1','Position', [600 70 500 800]);
tiledlayout(3,1,"TileSpacing","tight","Padding","compact")
% fig(9)=figure('Name','Control Inputs v1','Position', [600 70 800 600]);
% tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile % DEP ------------------------------------------------------------
hold on
plot(outv1.tout,outv1.DEP,'r');
plot(solv1.T,solv1.U(:,2),'--k')
ylabel('DEP_c_o_l, 0-1')
grid on
ylim([-0.05 0.5])
nexttile % HTU ------------------------------------------------------------
hold on
p2=plot(outv1.tout,outv1.HTU,'r');
p1=plot(solv1.T,solv1.U(:,3),'--k');
ylabel('HTU, 0-1')
grid on
nexttile % ELEVATOR -------------------------------------------------------
hold on
p2=plot(outv1.tout,rad2deg(outv1.elev),'r');
p1=plot(solv1.T,rad2deg(solv1.U(:,1)),'--k');
ylabel('Elevator Deflection, deg')
grid on
xlabel('Time, s')
legend([p1 p2],...
       {'Optimal Trajectory','Tracking Result'},...
       'Location','south','NumColumns',2);
% nexttile % FLAP -----------------------------------------------------------
% dFlap=deg2rad(5);
% hold on
% p2=plot(outv1.tout,rad2deg(outv1.flap),'r');
% p1=plot(solv1.T,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solv1.T)),'--k');
% xlabel('Time, s')
% ylabel('Flap Deflection, deg')
% grid on
% legend([p1 p2],...
%        {'Optimal Trajectory','Tracking Result'},...
%        'Location','south','NumColumns',2);


%% Plot figures (v2,time)

% state trajectories ======================================================
fig(10)=figure('Name','State Trajectories (vs time) v2','Position', [50 75 400 1250]); % PORTRAIT
tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
% fig(10)=figure('Name','State Trajectories (vs time) v2','Position', [50 75 1200 600]);
% tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE ------------------------------------------------------- 
hold on
plottraj2=plot(outv2.tout,-1*outv2.z,'r');
plottraj1=plot(solv2.T,-1*solv2.X(:,2),'--k');
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
nexttile % RATE OF CLIMB --------------------------------------------------
hold on
plot(outv2.tout(1:end-1),outv2.rocft,'r')
plot(solv2.T(1:end-1),solv2.rocft,'--k')
ylabel('Rate of Climb, ft/min')
grid on
nexttile % AIRSPEED -------------------------------------------------------
hold on
plot(outv2.tout,outv2.Va_tas,'r')
plot(solv2.T,solv2.Va,'--k')
ylabel('Airspeed, m/s')
grid on
nexttile % ANGLE OF ATTACK ------------------------------------------------
hold on
plot(outv2.tout,rad2deg(outv2.alpha),'r')
plot(solv2.T,rad2deg(solv2.alpha),'--k')
ylabel('Angle of Attack, deg')
grid on
nexttile % PITCH ANGLE ----------------------------------------------------
hold on
plot(outv2.tout,rad2deg(outv2.theta),'r')
plot(solv2.T,rad2deg(solv2.X(:,5)),'--k')
ylabel('Pitch Angle, deg')
grid on
nexttile % PITCH RATE -----------------------------------------------------
hold on
plot(outv2.tout,rad2deg(outv2.q),'r')
plot(solv2.T,rad2deg(solv2.X(:,6)),'--k')
xlabel('Time, s')
ylabel('Pitch Rate, deg/s')
grid on

% control trajectories ====================================================
fig(11)=figure('Name','Control Inputs v2','Position', [600 70 500 800]); % PORTRAIT
tiledlayout(3,1,"TileSpacing","tight","Padding","compact")
% fig(11)=figure('Name','Control Inputs v2','Position', [600 70 800 600]);
% tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile % DEP ------------------------------------------------------------
hold on
plot(outv2.tout,outv2.DEP,'r');
plot(solv2.T,solv2.U(:,2),'--k')
ylabel('DEP_c_o_l, 0-1')
grid on
ylim([-0.05 0.65])
nexttile % HTU ------------------------------------------------------------
hold on
p2=plot(outv2.tout,outv2.HTU,'r');
p1=plot(solv2.T,solv2.U(:,3),'--k');
ylabel('HTU, 0-1')
grid on
nexttile % ELEVATOR -------------------------------------------------------
hold on
p2=plot(outv2.tout,rad2deg(outv2.elev),'r');
p1=plot(solv2.T,rad2deg(solv2.U(:,1)),'--k');
ylabel('Elevator Deflection, deg')
grid on
xlabel('Time, s')
legend([p1 p2],...
       {'Optimal Trajectory','Tracking Result'},...
       'Location','south','NumColumns',2);
% nexttile % FLAP -----------------------------------------------------------
% dFlap=deg2rad(5);
% hold on
% p2=plot(outv2.tout,rad2deg(outv2.flap),'r');
% p1=plot(solv2.T,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solv2.T)),'--k');
% xlabel('Time, s')
% ylabel('Flap Deflection, deg')
% grid on
% legend([p1 p2],...
%        {'Optimal Trajectory','Tracking Result'},...
%        'Location','south','NumColumns',2);

%% Plot figures (v3,time)

% state trajectories ======================================================
fig(12)=figure('Name','State Trajectories (vs time) v2','Position', [50 75 400 1250]); % PORTRAIT
tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
% fig(12)=figure('Name','State Trajectories (vs time) v3','Position', [50 75 1200 600]);
% tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE ------------------------------------------------------- 
hold on
plottraj2=plot(outv3.tout,-1*outv3.z,'r');
plottraj1=plot(solv3.T,-1*solv3.X(:,2),'--k');
ylabel('Altitude, m')
grid on
legend([plottraj1 plottraj2],{'Optimal Trajectory','Tracking Result'},'Location','northeast');
nexttile % RATE OF CLIMB --------------------------------------------------
hold on
plot(outv3.tout(1:end-1),outv3.rocft,'r')
plot(solv3.T(1:end-1),solv3.rocft,'--k')
ylabel('Rate of Climb, ft/min')
grid on
nexttile % AIRSPEED -------------------------------------------------------
hold on
plot(outv3.tout,outv3.Va_tas,'r')
plot(solv3.T,solv3.Va,'--k')
ylabel('Airspeed, m/s')
grid on
nexttile % ANGLE OF ATTACK ------------------------------------------------
hold on
plot(outv3.tout,rad2deg(outv3.alpha),'r')
plot(solv3.T,rad2deg(solv3.alpha),'--k')
ylabel('Angle of Attack, deg')
grid on
nexttile % PITCH ANGLE ----------------------------------------------------
hold on
plot(outv3.tout,rad2deg(outv3.theta),'r')
plot(solv3.T,rad2deg(solv3.X(:,5)),'--k')
ylabel('Pitch Angle, deg')
grid on
nexttile % PITCH RATE -----------------------------------------------------
hold on
plot(outv3.tout,rad2deg(outv3.q),'r')
plot(solv3.T,rad2deg(solv3.X(:,6)),'--k')
xlabel('Time, s')
ylabel('Pitch Rate, deg/s')
grid on

% control trajectories ====================================================
fig(13)=figure('Name','Control Inputs v3','Position', [600 70 500 800]); % PORTRAIT
tiledlayout(3,1,"TileSpacing","tight","Padding","compact")
% fig(13)=figure('Name','Control Inputs v3','Position', [600 70 800 600]);
% tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile % DEP ------------------------------------------------------------
hold on
plot(outv3.tout,outv3.DEP,'r');
plot(solv3.T,solv3.U(:,2),'--k')
ylabel('DEP_c_o_l, 0-1')
grid on
ylim([-0.05 0.5])
nexttile % HTU ------------------------------------------------------------
hold on
p2=plot(outv3.tout,outv3.HTU,'r');
p1=plot(solv3.T,solv3.U(:,3),'--k');
ylabel('HTU, 0-1')
grid on
nexttile % ELEVATOR -------------------------------------------------------
hold on
p2=plot(outv3.tout,rad2deg(outv3.elev),'r');
p1=plot(solv3.T,rad2deg(solv3.U(:,1)),'--k');
xlabel('Time, s')
ylabel('Elevator Deflection, deg')
grid on
legend([p1 p2],...
       {'Optimal Trajectory','Tracking Result'},...
       'Location','south','NumColumns',2);
% nexttile % FLAP -----------------------------------------------------------
% dFlap=deg2rad(5);
% hold on
% p2=plot(outv3.tout,rad2deg(outv3.flap),'r');
% p1=plot(solv3.T,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solv3.T)),'--k');
% xlabel('Time, s')
% ylabel('Flap Deflection, deg')
% grid on
% legend([p1 p2],...
%        {'Optimal Trajectory','Tracking Result'},...
%        'Location','south','NumColumns',2);

%% Save results

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");

% save figures
saveas(fig(1),'figures\3doftrack_error_'+timestamp,'jpg')
saveas(fig(8),'figures\3doftrack_statesv1_'+timestamp,'jpg')
saveas(fig(9),'figures\3doftrack_controlsv1_'+timestamp,'jpg')
saveas(fig(10),'figures\3doftrack_statesv2_'+timestamp,'jpg')
saveas(fig(11),'figures\3doftrack_controlsv2_'+timestamp,'jpg')
saveas(fig(12),'figures\3doftrack_statesv3_'+timestamp,'jpg')
saveas(fig(13),'figures\3doftrack_controlsv3_'+timestamp,'jpg')
% savefig(fig,'figures\3doftrack_'+timestamp);
% clear fig

% save workspace
save('figures\3doftrack_'+timestamp)



