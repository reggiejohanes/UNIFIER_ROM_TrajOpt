% clc
clear all
% close all

%% load results

load rundata_trajopt\UNIFIERLanding_20240613_232402 solution rodft Va alpha avgglideslope tf xf
solutionv1      = solution;
rodftv1         = rodft;
Vav1            = Va;
alphav1         = alpha;
avgglideslopev1 = avgglideslope;
tfv1            = tf;
xfv1            = xf;
clear solution rodft Va alpha avgglideslope tf xf

load rundata_trajopt\UNIFIERLanding_20240613_192010 solution rodft Va alpha avgglideslope tf xf
solutionv2      = solution;
rodftv2         = rodft;
Vav2            = Va;
alphav2         = alpha;
avgglideslopev2 = avgglideslope;
tfv2            = tf;
xfv2            = xf;
clear solution rodft Va alpha avgglideslope tf xf

load rundata_trajopt\UNIFIERLanding_20240613_190735 solution rodft Va alpha avgglideslope tf xf
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

% fig(1)=figure('Name','State Histories','Position', [5 75 400 1250]);
% tiledlayout(6,1,"TileSpacing","tight","Padding","compact")
fig(1)=figure('Name','State Histories','Position', [5 75 1200 600]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

nexttile
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

nexttile
plot(solutionv1.X(1:mpoints-1,1)/1000,-1*rodftv1,'-b','LineWidth',0.5)
yline(-350,'-.k',{'Max RoD = 350 ft/min'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8,'LineWidth',0.2)
hold on
plot(solutionv2.X(1:mpoints-1,1)/1000,-1*rodftv2,'-m','LineWidth',0.5)
plot(solutionv3.X(1:mpoints-1,1)/1000,-1*rodftv3,'-r','LineWidth',0.5)
% title('Rate of Climb')
% xlabel('Distance, km')
ylabel('Rate of Climb, ft/min')
grid on
ylim([-400 -100])

nexttile
plot(solutionv1.X(:,1)/1000,Vav1,'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,Vav2,'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,Vav3,'-r','LineWidth',0.5)
% title('Airspeed')
% xlabel('Distance, km')
ylabel('Airspeed, m/s')
grid on
% vminlabel=['V_m_i_n= ' num2str(round(min(Vav1),2)) ' m/s'];
yline(35.85*1.1,'-.k',{'Min Va = 39.4 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
ylim([35 80])

nexttile
plot(solutionv1.X(:,1)/1000,rad2deg(alphav1),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(alphav2),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(alphav3),'-r','LineWidth',0.5)
% title('AoA')
xlabel('Distance, km')
ylabel('Angle of Attack, deg')
% yline(0,':b','LineWidth',1)
grid on

nexttile
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.X(:,5)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.X(:,5)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.X(:,5)),'-r','LineWidth',0.5)
% title('Pitch Angle')
% xlabel('Distance, km')
ylabel('Pitch Angle, deg')
% yline(0,':b','LineWidth',1)
grid on

nexttile
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

% fig(2)=figure('Name','Control Histories','Position', [5 75 400 900]);
% tiledlayout(4,1,"TileSpacing","tight","Padding","compact")
fig(2)=figure('Name','Control Histories','Position', [5 75 800 600]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")

nexttile
p1=plot(solutionv1.X(:,1)/1000,solutionv1.U(:,2),'-b','LineWidth',0.5);
hold on
p2=plot(solutionv2.X(:,1)/1000,solutionv2.U(:,2),'-m','LineWidth',0.5);
p3=plot(solutionv3.X(:,1)/1000,solutionv3.U(:,2),'-r','LineWidth',0.5);
legend([p1 p2 p3],...
       {'ROM v1','ROM v2','ROM v3'},...
       'Location','southeast');
% title('DEP Thrust Level')
% xlabel('Distance, km')
ylabel('DEP_c_o_l, 0-1')
grid on

nexttile
plot(solutionv1.X(:,1)/1000,solutionv1.U(:,3),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,solutionv2.U(:,3),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,solutionv3.U(:,3),'-r','LineWidth',0.5)
% title('HTU Thrust Level')
% xlabel('Distance, km')
ylabel('HTU, 0-1')
grid on

nexttile
plot(solutionv1.X(:,1)/1000,rad2deg(solutionv1.U(:,1)),'-b','LineWidth',0.5)
hold on
plot(solutionv2.X(:,1)/1000,rad2deg(solutionv2.U(:,1)),'-m','LineWidth',0.5)
plot(solutionv3.X(:,1)/1000,rad2deg(solutionv3.U(:,1)),'-r','LineWidth',0.5)
% title('Elevator Deflection')
% xlabel('Distance, km')
% ylabel('\delta_E_l_e_v, deg')
ylabel('Elevator Deflection, deg')
% yline(0,':b','LineWidth',1)
grid on

nexttile
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

% save results -----------------------------------------------------------

% % save figures
% saveas(fig(1),'figures\trajoptres_states','jpg')
% saveas(fig(2),'figures\trajoptres_controls','jpg')
% savefig(fig,'figures\trajoptrescomp_figs');
% clear fig
% 
% % save workspace
% save('figures\trajoptrescomp')



















