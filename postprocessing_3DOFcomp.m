
% clc
clear
% close all

load 3dofout_trim1000_hfm.mat
load 3dofout_trim1000_romv1.mat
load 3dofout_trim1000_romv2.mat
load 3dofout_trim1000_romv3.mat
load UNIFIER_LOAD.mat

%% plot states

close all

fig(1)=figure('Name','State Trajectories','Position', [50 10 600 1875]);
tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
% fig(1)=figure('Name','State Trajectories','Position', [150 100 1200 600]);
% tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
hold on
p4=plot(outromv3.tout,-1*outromv3.z,'c');
p1=plot(outhfm.tout,-1*outhfm.z,'k');
p2=plot(outromv1.tout,-1*outromv1.z,'g');
p3=plot(outromv2.tout,-1*outromv2.z,'m');
ylabel('Altitude (-ze), m')
grid on
legend([p1 p2 p3 p4],{'HFM','ROM v1','ROM v2','ROM v3'},'Location','northoutside','NumColumns',4);
% legend([p1 p2 p3],{'HFM','ROM v1','ROM v2'},'Location','northoutside','NumColumns',3);

% distance
nexttile
hold on
plot(outromv3.tout,outromv3.x,'c');
plot(outhfm.tout,outhfm.x,'k');
plot(outromv1.tout,outromv1.x,'g');
plot(outromv2.tout,outromv2.x,'m');
ylabel('Distance (xe), m')
grid on

% TAS
nexttile
hold on
plot(outromv3.tout,outromv3.Va_tas,'c');
plot(outhfm.tout,outhfm.Va_tas,'k');
plot(outromv1.tout,outromv1.Va_tas,'g');
plot(outromv2.tout,outromv2.Va_tas,'m');
ylabel('TAS (Va), m/s')
grid on

% aoa
nexttile
hold on
plot(outromv3.tout,rad2deg(outromv3.alpha),'c');
plot(outhfm.tout,rad2deg(outhfm.alpha),'k');
plot(outromv1.tout,rad2deg(outromv1.alpha),'g');
plot(outromv2.tout,rad2deg(outromv2.alpha),'m');
ylabel('Angle of Attack (\alpha), deg')
grid on

% pitch angle
nexttile
hold on
plot(outromv3.tout,rad2deg(outromv3.theta),'c');
plot(outhfm.tout,rad2deg(outhfm.theta),'k');
plot(outromv1.tout,rad2deg(outromv1.theta),'g');
plot(outromv2.tout,rad2deg(outromv2.theta),'m');
ylabel('Pitch Angle (\theta), deg')
yticks(linspace(-50,50,100/10+1))
grid on

% pitch rate
nexttile
hold on
plot(outromv3.tout,rad2deg(outromv3.q),'c');
plot(outhfm.tout,rad2deg(outhfm.q),'k');
plot(outromv1.tout,rad2deg(outromv1.q),'g');
plot(outromv2.tout,rad2deg(outromv2.q),'m');
ylabel('Pitch Rate (q), deg/s')
grid on
xlabel('Time (t), s')

% -------------------------------------------------------------------------

% fig(2)=figure('Name','State Trajectories','Position', [50 75 400 1250]);
% tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
fig(2)=figure('Name','State Trajectories','Position', [150 100 1200 600]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
hold on
p4=plot(outromv3.tout,-1*outromv3.z,'c');
p1=plot(outhfm.tout,-1*outhfm.z,'k');
p2=plot(outromv1.tout,-1*outromv1.z,'g');
p3=plot(outromv2.tout,-1*outromv2.z,'m');
ylabel('Altitude (-ze), m')
grid on
legend([p1 p2 p3 p4],{'HFM','ROM v1','ROM v2','ROM v3'},'Location','northoutside','NumColumns',4);
% legend([p1 p2 p3],{'HFM','ROM v1','ROM v2'},'Location','northoutside','NumColumns',3);

% distance
nexttile
hold on
p4=plot(outromv3.tout,outromv3.x,'c');
p1=plot(outhfm.tout,outhfm.x,'k');
p2=plot(outromv1.tout,outromv1.x,'g');
p3=plot(outromv2.tout,outromv2.x,'m');
% legend([p1 p2 p3 p4],{'HFM','ROM v1','ROM v2','ROM v3'},'Location','northoutside','NumColumns',4);
ylabel('Distance (xe), m')
grid on

% TAS
nexttile
hold on
p4=plot(outromv3.tout,outromv3.Va_tas,'c');
p1=plot(outhfm.tout,outhfm.Va_tas,'k');
p2=plot(outromv1.tout,outromv1.Va_tas,'g');
p3=plot(outromv2.tout,outromv2.Va_tas,'m');
% legend([p1 p2 p3 p4],{'HFM','ROM v1','ROM v2','ROM v3'},'Location','northoutside','NumColumns',4);
ylabel('TAS (Va), m/s')
grid on

% aoa
nexttile
hold on
plot(outromv3.tout,rad2deg(outromv3.alpha),'c');
plot(outhfm.tout,rad2deg(outhfm.alpha),'k');
plot(outromv1.tout,rad2deg(outromv1.alpha),'g');
plot(outromv2.tout,rad2deg(outromv2.alpha),'m');
ylabel('Angle of Attack (\alpha), deg')
grid on

% pitch angle
nexttile
hold on
plot(outromv3.tout,rad2deg(outromv3.theta),'c');
plot(outhfm.tout,rad2deg(outhfm.theta),'k');
plot(outromv1.tout,rad2deg(outromv1.theta),'g');
plot(outromv2.tout,rad2deg(outromv2.theta),'m');
ylabel('Pitch Angle (\theta), deg')
yticks(linspace(-50,50,100/10+1))
grid on
xlabel('Time (t), s')

% pitch rate
nexttile
hold on
plot(outromv3.tout,rad2deg(outromv3.q),'c');
plot(outhfm.tout,rad2deg(outhfm.q),'k');
plot(outromv1.tout,rad2deg(outromv1.q),'g');
plot(outromv2.tout,rad2deg(outromv2.q),'m');
ylabel('Pitch Rate (q), deg/s')
grid on

% -------------------------------------------------------------------------

% fig(3)=figure('Name','State Trajectories','Position', [50 75 400 1250]);
% tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
fig(3)=figure('Name','State Trajectories','Position', [150 100 1200 600]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

% altitude
nexttile
hold on
% p4=plot(outromv3.tout,-1*outromv3.z,'c');
p1=plot(outhfm.tout,-1*outhfm.z,'k');
p2=plot(outromv1.tout,-1*outromv1.z,'g');
p3=plot(outromv2.tout,-1*outromv2.z,'m');
ylabel('Altitude (-ze), m')
grid on
% legend([p1 p2 p3 p4],{'HFM','ROM v1','ROM v2','ROM v3'},'Location','northoutside','NumColumns',4);
legend([p1 p2 p3],{'HFM','ROM v1','ROM v2'},'Location','northoutside','NumColumns',3);

% distance
nexttile
hold on
% p4=plot(outromv3.tout,outromv3.x,'c');
p1=plot(outhfm.tout,outhfm.x,'k');
p2=plot(outromv1.tout,outromv1.x,'g');
p3=plot(outromv2.tout,outromv2.x,'m');
% legend([p1 p2 p3 p4],{'HFM','ROM v1','ROM v2','ROM v3'},'Location','northoutside','NumColumns',4);
ylabel('Distance (xe), m')
grid on

% TAS
nexttile
hold on
% p4=plot(outromv3.tout,outromv3.Va_tas,'c');
p1=plot(outhfm.tout,outhfm.Va_tas,'k');
p2=plot(outromv1.tout,outromv1.Va_tas,'g');
p3=plot(outromv2.tout,outromv2.Va_tas,'m');
% legend([p1 p2 p3 p4],{'HFM','ROM v1','ROM v2','ROM v3'},'Location','northoutside','NumColumns',4);
ylabel('TAS (Va), m/s')
grid on

% aoa
nexttile
hold on
% plot(outromv3.tout,rad2deg(outromv3.alpha),'c');
plot(outhfm.tout,rad2deg(outhfm.alpha),'k');
plot(outromv1.tout,rad2deg(outromv1.alpha),'g');
plot(outromv2.tout,rad2deg(outromv2.alpha),'m');
ylabel('Angle of Attack (\alpha), deg')
grid on

% pitch angle
nexttile
hold on
% plot(outromv3.tout,rad2deg(outromv3.theta),'c');
plot(outhfm.tout,rad2deg(outhfm.theta),'k');
plot(outromv1.tout,rad2deg(outromv1.theta),'g');
plot(outromv2.tout,rad2deg(outromv2.theta),'m');
ylabel('Pitch Angle (\theta), deg')
% yticks(linspace(-50,50,100/10+1))
grid on
xlabel('Time (t), s')

% pitch rate
nexttile
hold on
% plot(outromv3.tout,rad2deg(outromv3.q),'c');
plot(outhfm.tout,rad2deg(outhfm.q),'k');
plot(outromv1.tout,rad2deg(outromv1.q),'g');
plot(outromv2.tout,rad2deg(outromv2.q),'m');
ylabel('Pitch Rate (q), deg/s')
grid on

%% save results

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");

% save figures
saveas(fig(1),'figures\3dofcomp_port_'+timestamp,'jpg')
saveas(fig(2),'figures\3dofcomp_landsc_all_'+timestamp,'jpg')
saveas(fig(3),'figures\3dofcomp_landsc_exclromv3_'+timestamp,'jpg')
savefig(fig,'figures\3dofcomp_'+timestamp);
clear fig

% save workspace
save('figures\3dofcomp_'+timestamp)


