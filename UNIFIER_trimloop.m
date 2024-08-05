
% clc
clear all
% close all

% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata_trimloop\UNIFIER_trimloopv2_' + timestamp; % name of diary & data log file

%% Set altitude, airspeed, & flap deflection range

ze_cruise   = 5;
DEPset      = 1;

Va_max      = 65;
Va_min      = 25;
Va_inc      = 1;
Va_n        = (Va_max-Va_min)/Va_inc+1;
Va_range    = linspace(Va_min,Va_max,Va_n);

dFlap_range = [0 5 10 12 20 25];
dFlap_range = deg2rad(dFlap_range);

%% Set numerical parameters

% HFM
dmcHFM           = 1e-6; % fmincon diffminchange setting
penaltyHFM.zedot = 1;
penaltyHFM.udot  = 1;
penaltyHFM.wdot  = 1;
penaltyHFM.qdot  = 100;
penaltyHFM.Va    = 1;

% ROM
dmcROM           = 1e-8;
penaltyROM.zedot = 1;
penaltyROM.udot  = 1;
penaltyROM.wdot  = 1;
penaltyROM.qdot  = 100;
penaltyROM.Va    = 1;

%% Calculate trim accelerations

fprintf('\n');
fprintf('<strong><< STARTING LOOP >></strong>');
fprintf('\n');
fprintf('\n');

startloop=tic;
set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
UNIFIER_dyn([],[],[],'compile')
count=0;

for i=1:numel(dFlap_range)
    for j=1:Va_n
        
        count=count+1;
        startstep=tic;

        % HFM
        reshfm = UNIFIER_trimHFM_loop(DEPset,Va_range(j),ze_cruise,dFlap_range(i),penaltyHFM,dmcHFM);
        xdothfm(:,i,j)     = reshfm.xdot;
        Vahfm(i,j)         = reshfm.Va;
        residualhfm(1,i,j) = xdothfm(3,i,j);           % zedot
        residualhfm(2,i,j) = xdothfm(4,i,j);           % udot
        residualhfm(3,i,j) = xdothfm(6,i,j);           % wdot
        residualhfm(4,i,j) = xdothfm(8,i,j);           % thetadot
        residualhfm(5,i,j) = xdothfm(11,i,j);          % qdot
        residualhfm(6,i,j) = Vahfm(i,j)-Va_range(j);   % va error
        normhfm(i,j)       = norm(residualhfm(:,i,j)); % norm of residuals

        % v1 (ROM2-1)
        resv1 = UNIFIER_trimROM_loop(DEPset,2,1,Va_range(j),ze_cruise,dFlap_range(i),penaltyROM,dmcROM);
        xdotv1(:,i,j)       = resv1.xdot;
        Vav1(i,j)           = resv1.Va;
        residualv1(1:5,i,j) = xdotv1(2:6,i,j);         % xdot except xedot
        residualv1(6,i,j)   = Vav1(i,j)-Va_range(j);   % va error
        normv1(i,j)         = norm(residualv1(:,i,j)); % norm of residuals

        % v2 (ROM5)
        resv2 = UNIFIER_trimROM_loop(DEPset,5,1,Va_range(j),ze_cruise,dFlap_range(i),penaltyROM,dmcROM);
        xdotv2(:,i,j)       = resv2.xdot;
        Vav2(i,j)           = resv2.Va;
        residualv2(1:5,i,j) = xdotv2(2:6,i,j);         % xdot except xedot
        residualv2(6,i,j)   = Vav2(i,j)-Va_range(j);   % va error
        normv2(i,j)         = norm(residualv2(:,i,j)); % norm of residuals

        % v3 (ROM4)
        resv3 = UNIFIER_trimROM_loop(DEPset,4,1,Va_range(j),ze_cruise,dFlap_range(i),penaltyROM,dmcROM);
        xdotv3(:,i,j)       = resv3.xdot;
        Vav3(i,j)           = resv3.Va;
        residualv3(1:5,i,j) = xdotv3(2:6,i,j);         % xdot except xedot
        residualv3(6,i,j)   = Vav3(i,j)-Va_range(j);   % va error
        normv3(i,j)         = norm(residualv3(:,i,j)); % norm of residuals

        t_step=toc(startstep);
        fprintf(num2str(count))
        fprintf('/')
        fprintf(num2str(Va_n*numel(dFlap_range)))
        fprintf(' %6.4f s\n',t_step);
    end
end

UNIFIER_dyn([],[],[],'term')

fprintf('\n');
fprintf('<strong><< LOOP COMPLETED >></strong>');
fprintf('\n');
fprintf('\n');

t_eval = toc(startloop);
evals  = Va_n*numel(dFlap_range)*4;
fprintf('Total               = %6.4f seconds\n',t_eval);
fprintf('Avg. per Evaluation = %6.4f seconds\n',t_eval/evals);
fprintf('\n');


%% Plot results

close all

fig(1)=figure('Name','Trim Results at Varying Airspeeds','Position',[150 200 600 400]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")

nexttile
plot1=plot(Va_range,normhfm(1,:),'.-c');
title('HFM')
hold on
plot2=plot(Va_range,normhfm(3,:),'.-m');
plot3=plot(Va_range,normhfm(6,:),'.-g');
% legend([plot1 plot2 plot3],...
%        {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 10 deg','\delta_F_l_a_p = 25 deg'},...
%        'Location','northeast');
ylim([-0.5 5])
xlim([Va_min Va_max])
% xlabel('Airspeed, m/s')
ylabel('Norm of Residuals')
grid on

nexttile
plot1=plot(Va_range,normv1(1,:),'.-c');
title('ROM v1')
hold on
plot2=plot(Va_range,normv1(3,:),'.-m');
plot3=plot(Va_range,normv1(6,:),'.-g');
% legend([plot1 plot2 plot3],...
%        {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 10 deg','\delta_F_l_a_p = 25 deg'},...
%        'Location','northeast');
ylim([-0.5 5])
xlim([Va_min Va_max])
% xlabel('Airspeed, m/s')
% ylabel('Norm of Residuals')
grid on

nexttile
plot1=plot(Va_range,normv2(1,:),'.-c');
title('ROM v2')
hold on
plot2=plot(Va_range,normv2(3,:),'.-m');
plot3=plot(Va_range,normv2(6,:),'.-g');
% legend([plot1 plot2 plot3],...
%        {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 10 deg','\delta_F_l_a_p = 25 deg'},...
%        'Location','northeast');
ylim([-0.5 5])
xlim([Va_min Va_max])
xlabel('Airspeed, m/s')
ylabel('Norm of Residuals')
grid on

nexttile
plot1=plot(Va_range,normv3(1,:),'.-c');
title('ROM v3')
hold on
plot2=plot(Va_range,normv3(3,:),'.-m');
plot3=plot(Va_range,normv3(6,:),'.-g');
legend([plot1 plot2 plot3],...
       {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 10 deg','\delta_F_l_a_p = 25 deg'},...
       'Location','northeast');
ylim([-0.5 5])
xlim([Va_min Va_max])
xlabel('Airspeed, m/s')
% ylabel('Norm of Residuals')
grid on

%% ----------------------------------------------------

fig(2)=figure('Name','Approximate Stall Speed vs Flap Deflection','Position',[750 200 600 400]);
hold on

st4=plot(rad2deg(dFlap_range),[46 46 46 46 46 46],'.-c'); %ROMv3
st3=plot(rad2deg(dFlap_range),[50 48 46 45 42 40],'.-m'); %ROMv2
st2=plot(rad2deg(dFlap_range),[52 49 46 46 43 41],'.-g','LineWidth',1); %ROMv1
st1=plot(rad2deg(dFlap_range),[52 49 48 47 43 43],'.-k'); %HFM (CRUISE)
yticks(linspace(40,55,(55-40)/1+1))
ylim([39 53])

% st4=plot(rad2deg(dFlap_range),[44 44 44 44 44 44],'.-c'); %ROMv3
% st3=plot(rad2deg(dFlap_range),[48 45 43 42 40 38],'.-m'); %ROMv2
% st2=plot(rad2deg(dFlap_range),[47 45 42 42 39 38],'.-g','LineWidth',1); %ROMv1
% st1=plot(rad2deg(dFlap_range),[47 45 42 40 38 35],'.-k'); %HFM (LANDING)
% yticks(linspace(35,48,(48-35)/1+1))
% ylim([35 48])

legend([st1 st2 st3 st4],...
       {'HFM','ROM v1','ROM v2','ROM v3'},...
       'Location','northeast');
ylabel('Stall Speed, m/s')
xlabel('\delta_F_l_a_p, deg')
xlim([0 25])
grid on

%% Save results

% save figures
saveas(fig(1),'figures\trimloop_residual_'+timestamp,'jpg')
saveas(fig(2),'figures\trimloop_stallspeed_'+timestamp,'jpg')
savefig(fig,logname + '_figs');
clear fig

% save workspace
% save (logname);







