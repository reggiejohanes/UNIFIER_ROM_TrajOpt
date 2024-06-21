% clc
clear all
% close all

%% load results

load rundata_trajopt\UNIFIERLanding_20240620_044819 solution rodft Va alpha avgglideslope tf xf
solutionv1      = solution;
rodftv1         = rodft;
Vav1            = Va;
alphav1         = alpha;
avgglideslopev1 = avgglideslope;
tfv1            = tf;
xfv1            = xf;
clear solution rodft Va alpha avgglideslope tf xf

load rundata_trajopt\UNIFIERLanding_20240620_045023 solution rodft Va alpha avgglideslope tf xf
solutionv2      = solution;
rodftv2         = rodft;
Vav2            = Va;
alphav2         = alpha;
avgglideslopev2 = avgglideslope;
tfv2            = tf;
xfv2            = xf;
clear solution rodft Va alpha avgglideslope tf xf

load rundata_trajopt\UNIFIERLanding_20240620_050711 solution rodft Va alpha avgglideslope tf xf
solutionv3      = solution;
rodftv3         = rodft;
Vav3            = Va;
alphav3         = alpha;
avgglideslopev3 = avgglideslope;
tfv3            = tf;
xfv3            = xf;
clear solution rodft Va alpha avgglideslope tf xf

%% plot

close all

mpoints=250;

% states ------------------------------------------------------------------

fig(1)=figure('Name','State Histories','Position', [5 75 400 1250]);
tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
% fig(1)=figure('Name','State Histories','Position', [5 75 1200 600]);
% tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE
p1=plot(solutionv1.X(:,1)/1000,-1*solutionv1.X(:,2),'-b','LineWidth',0.5);
hold on
p2=plot(solutionv2.X(:,1)/1000,-1*solutionv2.X(:,2),'-m','LineWidth',0.5);
p3=plot(solutionv3.X(:,1)/1000,-1*solutionv3.X(:,2),'-r','LineWidth',0.5);
legend([p1 p2 p3],...
       {'ROM v1','ROM v2','ROM v3'},...
       'Location','northeast');
% title('Altitude')
% xlabel('Distance, km')
ylabel('Altitude, m')
grid on
nexttile % ROC
hold on
yline(0,'-.k',{'Max RoC = 0 ft/min'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8,'LineWidth',0.1)
yline(-350,'-.k',{'Min RoC = -350 ft/min'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8,'LineWidth',0.1)
plot(solutionv1.X(1:mpoints-1,1)/1000,-1*rodftv1,'-b','LineWidth',0.5)
plot(solutionv2.X(1:mpoints-1,1)/1000,-1*rodftv2,'-m','LineWidth',0.5)
plot(solutionv3.X(1:mpoints-1,1)/1000,-1*rodftv3,'-r','LineWidth',0.5)
% title('Rate of Climb')
% xlabel('Distance, km')
ylabel('Rate of Climb, ft/min')
grid on
ylim([-400 25])
nexttile % TAS
plot(solutionv1.X(:,1)/1000,Vav1,'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,Vav2,'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,Vav3,'-r','LineWidth',0.5)
% title('Airspeed')
% xlabel('Distance, km')
ylabel('Airspeed, m/s')
grid on
% vminlabel=['V_m_i_n= ' num2str(round(min(Vav1),2)) ' m/s'];
yline(80,'-.k',{'Max Va = 80 m/s'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8)
yline(35.85*1.3,'-.k',{'Max Va_f = 46.6 m/s'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8)
yline(35.85*1.1,'-.k',{'Min Va = 39.4 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
ylim([38 82])
nexttile % ANGLE OF ATTACK
plot(solutionv1.X(:,1)/1000,rad2deg(alphav1),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(alphav2),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(alphav3),'-r','LineWidth',0.5)
% title('AoA')
% xlabel('Distance, km')
ylabel('Angle of Attack, deg')
% yline(0,':b','LineWidth',1)
grid on
ylim([-4 8])
% str = {'Max \alpha =  10 deg','Min \alpha = -15 deg'};
% apos=subplot(2,2,4);
% a=annotation('textbox','String',str,'Position',apos.Position,'Vert','bottom','FitBoxToText','on');
% a.FontSize = 8;
nexttile % PITCH ANGLE
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.X(:,5)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.X(:,5)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.X(:,5)),'-r','LineWidth',0.5)
% title('Pitch Angle')
% xlabel('Distance, km')
ylabel('Pitch Angle, deg')
yline(5,'-.k',{'Max \theta = 5 deg'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
yline(-5,'-.k',{'Min \theta = -5 deg'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','top','FontSize',8)
ylim([-6 6])
yticks(linspace(-6,6,12/2+1))
grid on
nexttile % PITCH RATE
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.X(:,6)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.X(:,6)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.X(:,6)),'-r','LineWidth',0.5)
% title('Pitch Rate')
xlabel('Distance, km')
ylabel('Pitch Rate, deg/s')
% yline(0,':b','LineWidth',1)
grid on

% controls ----------------------------------------------------------------

fig(2)=figure('Name','Control Histories','Position', [5 75 400 900]);
tiledlayout(4,1,"TileSpacing","tight","Padding","compact")
% fig(2)=figure('Name','Control Histories','Position', [5 75 800 600]);
% tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile % DEP
p1=plot(solutionv1.X(:,1)/1000,solutionv1.U(:,2),'-b','LineWidth',0.5);
hold on
p2=plot(solutionv2.X(:,1)/1000,solutionv2.U(:,2),'-m','LineWidth',0.5);
p3=plot(solutionv3.X(:,1)/1000,solutionv3.U(:,2),'-r','LineWidth',0.5);
legend([p1 p2 p3],...
       {'ROM v1','ROM v2','ROM v3'},...
       'Location','northeast');
% title('DEP Thrust Level')
% xlabel('Distance, km')
ylabel('DEP_c_o_l, 0-1')
ylim([0 0.7])
grid on
nexttile % HTU
plot(solutionv1.X(:,1)/1000,solutionv1.U(:,3),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,solutionv2.U(:,3),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,solutionv3.U(:,3),'-r','LineWidth',0.5)
% title('HTU Thrust Level')
% xlabel('Distance, km')
ylabel('HTU, 0-1')
ylim([-0.5 1])
yticks(linspace(-0.5,1,1.5/0.25+1))
grid on
nexttile % ELEVATOR
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.U(:,1)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.U(:,1)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.U(:,1)),'-r','LineWidth',0.5)
% title('Elevator Deflection')
% xlabel('Distance, km')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
% yline(0,':b','LineWidth',1)
ylim([-25 5])
grid on
nexttile % FLAP
plot(solutionv1.X(:,1)/1000,linspace(5,5,numel(solutionv1.X(:,1))),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,linspace(5,5,numel(solutionv2.X(:,1))),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,linspace(5,5,numel(solutionv3.X(:,1))),'-r','LineWidth',0.5)
% plot(solutionv1.T,rad2deg(solutionv1.U(:,4)),'.-k')
% title('Flap Deflection')
xlabel('Distance, km')
% ylabel('\delta_F_l_a_p, deg')
ylabel('Flap Deflection, deg')
ylim([0 15])
% yline(0,':b','LineWidth',1)
grid on

% states ------------------------------------------------------------------

% fig(3)=figure('Name','State Histories','Position', [5 75 400 1250]);
% tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
fig(3)=figure('Name','State Histories','Position', [5 75 1200 600]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile % ALTITUDE
p1=plot(solutionv1.X(:,1)/1000,-1*solutionv1.X(:,2),'-b','LineWidth',0.5);
hold on
p2=plot(solutionv2.X(:,1)/1000,-1*solutionv2.X(:,2),'-m','LineWidth',0.5);
p3=plot(solutionv3.X(:,1)/1000,-1*solutionv3.X(:,2),'-r','LineWidth',0.5);
legend([p1 p2 p3],...
       {'ROM v1','ROM v2','ROM v3'},...
       'Location','northeast');
% title('Altitude')
% xlabel('Distance, km')
ylabel('Altitude, m')
grid on
nexttile % ROC
hold on
yline(0,'-.k',{'Max RoC = 0 ft/min'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8,'LineWidth',0.1)
yline(-350,'-.k',{'Min RoC = -350 ft/min'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8,'LineWidth',0.1)
plot(solutionv1.X(1:mpoints-1,1)/1000,-1*rodftv1,'-b','LineWidth',0.5)
plot(solutionv2.X(1:mpoints-1,1)/1000,-1*rodftv2,'-m','LineWidth',0.5)
plot(solutionv3.X(1:mpoints-1,1)/1000,-1*rodftv3,'-r','LineWidth',0.5)
% title('Rate of Climb')
% xlabel('Distance, km')
ylabel('Rate of Climb, ft/min')
grid on
ylim([-400 25])
nexttile % TAS
plot(solutionv1.X(:,1)/1000,Vav1,'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,Vav2,'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,Vav3,'-r','LineWidth',0.5)
% title('Airspeed')
% xlabel('Distance, km')
ylabel('Airspeed, m/s')
grid on
% vminlabel=['V_m_i_n= ' num2str(round(min(Vav1),2)) ' m/s'];
yline(80,'-.k',{'Max Va = 80 m/s'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8)
yline(35.85*1.3,'-.k',{'Max Va_f = 46.6 m/s'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8)
yline(35.85*1.1,'-.k',{'Min Va = 39.4 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
ylim([38 82])
nexttile % ANGLE OF ATTACK
plot(solutionv1.X(:,1)/1000,rad2deg(alphav1),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(alphav2),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(alphav3),'-r','LineWidth',0.5)
% title('AoA')
xlabel('Distance, km')
ylabel('Angle of Attack, deg')
% yline(0,':b','LineWidth',1)
grid on
ylim([-4 8])
% str = {'Max \alpha =  10 deg','Min \alpha = -15 deg'};
% apos=subplot(2,2,4);
% a=annotation('textbox','String',str,'Position',apos.Position,'Vert','bottom','FitBoxToText','on');
% a.FontSize = 8;
nexttile % PITCH ANGLE
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.X(:,5)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.X(:,5)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.X(:,5)),'-r','LineWidth',0.5)
% title('Pitch Angle')
% xlabel('Distance, km')
ylabel('Pitch Angle, deg')
% yline(0,':b','LineWidth',1)
ylim([-6 6])
yticks(linspace(-6,6,12/2+1))
grid on
nexttile % PITCH RATE
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.X(:,6)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.X(:,6)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.X(:,6)),'-r','LineWidth',0.5)
% title('Pitch Rate')
% xlabel('Distance, km')
ylabel('Pitch Rate, deg/s')
% yline(0,':b','LineWidth',1)
grid on

% controls ----------------------------------------------------------------

% fig(4)=figure('Name','Control Histories','Position', [5 75 400 900]);
% tiledlayout(4,1,"TileSpacing","tight","Padding","compact")
fig(4)=figure('Name','Control Histories','Position', [5 75 800 600]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile % DEP
p1=plot(solutionv1.X(:,1)/1000,solutionv1.U(:,2),'-b','LineWidth',0.5);
hold on
p2=plot(solutionv2.X(:,1)/1000,solutionv2.U(:,2),'-m','LineWidth',0.5);
p3=plot(solutionv3.X(:,1)/1000,solutionv3.U(:,2),'-r','LineWidth',0.5);
legend([p1 p2 p3],...
       {'ROM v1','ROM v2','ROM v3'},...
       'Location','northeast');
% title('DEP Thrust Level')
% xlabel('Distance, km')
ylabel('DEP_c_o_l, 0-1')
ylim([0 0.7])
grid on
nexttile % HTU
plot(solutionv1.X(:,1)/1000,solutionv1.U(:,3),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,solutionv2.U(:,3),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,solutionv3.U(:,3),'-r','LineWidth',0.5)
% title('HTU Thrust Level')
% xlabel('Distance, km')
ylabel('HTU, 0-1')
ylim([-0.5 1])
yticks(linspace(-0.5,1,1.5/0.25+1))
grid on
nexttile % ELEVATOR
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.U(:,1)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.U(:,1)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.U(:,1)),'-r','LineWidth',0.5)
% title('Elevator Deflection')
% xlabel('Distance, km')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
% yline(0,':b','LineWidth',1)
ylim([-25 5])
grid on
nexttile % FLAP
plot(solutionv1.X(:,1)/1000,linspace(5,5,numel(solutionv1.X(:,1))),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,linspace(5,5,numel(solutionv2.X(:,1))),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,linspace(5,5,numel(solutionv3.X(:,1))),'-r','LineWidth',0.5)
% plot(solutionv1.T,rad2deg(solutionv1.U(:,4)),'.-k')
% title('Flap Deflection')
xlabel('Distance, km')
% ylabel('\delta_F_l_a_p, deg')
ylabel('Flap Deflection, deg')
ylim([0 15])
% yline(0,':b','LineWidth',1)
grid on

%% geometric trajectory ----------------------------------------------------

% fig(5)=figure('Name','Geometric Trajectory','Position', [5 75 1200 400]);
% hold on
% p1=plot(solutionv1.X(:,1),-1*solutionv1.X(:,2),'-b','LineWidth',0.5);
% p2=plot(solutionv2.X(:,1),-1*solutionv2.X(:,2),'-m','LineWidth',0.5);
% p3=plot(solutionv3.X(:,1),-1*solutionv3.X(:,2),'-r','LineWidth',0.5);
% legend([p1 p2 p3],...
%        {'ROM v1','ROM v2','ROM v3'},...
%        'Location','northeast');
% % title('Altitude')
% xlabel('Distance, m')
% ylabel('Altitude, m')
% ylim([0 1219])
% grid on
% % axis equal


%% save results -----------------------------------------------------------

starttime    = datetime; % start date & time
timestampsave = string(starttime,"yyyyMMdd_HHmmss");

% % save figures
saveas(fig(1),'figures\trajoptres_states_port_'+timestampsave,'jpg')
saveas(fig(2),'figures\trajoptres_controls_port_'+timestampsave,'jpg')
saveas(fig(3),'figures\trajoptres_states_hor_'+timestampsave,'jpg')
saveas(fig(4),'figures\trajoptres_controls_hor_'+timestampsave,'jpg')
savefig(fig,'figures\trajoptrescomp_figs_'+timestampsave);
clear fig
% 
% % save workspace
save('figures\trajoptrescomp_'+timestampsave)



















