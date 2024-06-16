
% clc
clear all
close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIER_trimloop_' + timestamp; % name of diary & data log file

%% Set altitude, airspeed, & flap deflection range

ze_cruise   = 1219;
ze_landing  = 5;

Va_max      = 75;
Va_min      = 35;
Va_inc      = 2.5;
Va_n        = (Va_max-Va_min)/Va_inc+1;
Va_range    = linspace(Va_min,Va_max,Va_n);

dFlap_range = [0 5 12];
dFlap_range = deg2rad(dFlap_range);

%% Set numerical parameters

% ROM settings
ROMfile = 2; % 1=v1-72.74, 2=v1-50, 3=v0, 4=v3, 5=v2
ROMdep  = 2; % 1=all dependencies, 2=reduced dependencies

% Case A - HFM, DEP on
dmcA           = 1e-7;
penaltyA.zedot = 1;
penaltyA.udot  = 1;
penaltyA.wdot  = 1;
penaltyA.qdot  = 100;
penaltyA.Va    = 1;

% Case B - HFM, DEP off
dmcB           = 1e-6;
penaltyB.zedot = 1;
penaltyB.udot  = 1;
penaltyB.wdot  = 1;
penaltyB.qdot  = 100;
penaltyB.Va    = 1;

% Case C - ROM, DEP on
dmcC           = 1e-7;
penaltyC.zedot = 1;
penaltyC.udot  = 1;
penaltyC.wdot  = 1;
penaltyC.qdot  = 100;
penaltyC.Va    = 1;

% Case D - ROM, DEP off
dmcD           = 1e-7;
penaltyD.zedot = 1;
penaltyD.udot  = 1;
penaltyD.wdot  = 1;
penaltyD.qdot  = 100;
penaltyD.Va    = 1;

% Documentation
numset=[ROMfile,...
        ROMdep,...
        dmcA,...
        penaltyA.zedot,...
        penaltyA.udot,...
        penaltyA.wdot,...
        penaltyA.qdot,...
        penaltyA.Va,...
        dmcB,...
        penaltyB.zedot,...
        penaltyB.udot,...
        penaltyB.wdot,...
        penaltyB.qdot,...
        penaltyB.Va,...
        dmcC,...
        penaltyC.zedot,...
        penaltyC.udot,...
        penaltyC.wdot,...
        penaltyC.qdot,...
        penaltyC.Va,...
        dmcD,...
        penaltyD.zedot,...
        penaltyD.udot,...
        penaltyD.wdot,...
        penaltyD.qdot,...
        penaltyD.Va];
numall=[timestamp numset];

%% Calculate trim accelerations

fprintf('\n');
fprintf('<strong><< STARTING LOOP >></strong>');
fprintf('\n');
fprintf('\n');
% fprintf('<strong>START         END</strong>');
% fprintf('\n');
% fprintf('<strong>|---------------|</strong>');
% fprintf('\n');

startloop=tic;
% set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
% UNIFIER_dyn([],[],[],'compile')
count=0;

for i=1:numel(dFlap_range)
    for j=1:Va_n
        
        count=count+1;
        startstep=tic;

        % % Case A - HFM, DEP on
        % resA = UNIFIER_trimHFM_loop(1,Va_range(j),ze_landing,dFlap_range(i),penaltyA,dmcA);
        % zedotA(i,j) = resA.xdot(3);
        % wdotA(i,j)  = resA.xdot(6);
        % fvalA(i,j)  = resA.fval;
        % 
        % % Case B - HFM, DEP off
        % resB = UNIFIER_trimHFM_loop(0,Va_range(j),ze_cruise,dFlap_range(i),penaltyB,dmcB);
        % zedotB(i,j) = resB.xdot(3);
        % wdotB(i,j)  = resB.xdot(6);
        % fvalB(i,j)  = resB.fval;

        % Case C - ROM, DEP on
        resC = UNIFIER_trimROM_loop(1,ROMfile,ROMdep,Va_range(j),ze_landing,dFlap_range(i),penaltyC,dmcC);
        zedotC(i,j) = resC.xdot(2);
        wdotC(i,j)  = resC.xdot(4);
        fvalC(i,j)  = resC.fval;

        % Case D - ROM, DEP off
        resD = UNIFIER_trimROM_loop(0,ROMfile,ROMdep,Va_range(j),ze_cruise,dFlap_range(i),penaltyD,dmcD);
        zedotD(i,j) = resD.xdot(2);
        wdotD(i,j)  = resD.xdot(4);
        fvalD(i,j)  = resD.fval;

        t_step=toc(startstep);
        fprintf(num2str(count))
        fprintf('/')
        fprintf(num2str(Va_n*numel(dFlap_range)))
        fprintf(' %6.4f s\n',t_step);
    end
end

% UNIFIER_dyn([],[],[],'term')

fprintf('\n');
fprintf('<strong><< LOOP COMPLETED >></strong>');
fprintf('\n');
fprintf('\n');

t_eval = toc(startloop);
evals  = Va_n*numel(dFlap_range)*4;
fprintf('Total               = %6.4f seconds\n',t_eval);
fprintf('Avg. per Evaluation = %6.4f seconds\n',t_eval/evals);
fprintf('\n');

%% Convert units

% zedotconvA = convvel(zedotA,'m/s','ft/min')*-1;
% zedotconvB = convvel(zedotB,'m/s','ft/min')*-1;
zedotconvC = convvel(zedotC,'m/s','ft/min')*-1;
zedotconvD = convvel(zedotD,'m/s','ft/min')*-1;

%% Plot results

close all
fig(1)=figure('Name','RoC vs Va, Case C','Position', [450 200 500 500]);
roc1=plot(Va_range,zedotconvC(1,:),'.-r');
hold on
roc2=plot(Va_range,zedotconvC(2,:),'.-b');
roc3=plot(Va_range,zedotconvC(3,:),'.-m');
grid on
title('RoC vs Va (Alt = 5m, DEP on, ROM)')
xlabel('Airspeed, m/s')
ylabel('Rate of Climb, ft/min')
legend([roc1 roc2 roc3],...
       {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 5 deg','\delta_F_l_a_p = 12 deg'},...
       'Location','southeast');
ylim([-250 50])

fig(2)=figure('Name','RoC vs Va, Case D','Position', [650 200 500 500]);
roc1=plot(Va_range,zedotconvD(1,:),'.-r');
hold on
roc2=plot(Va_range,zedotconvD(2,:),'.-b');
roc3=plot(Va_range,zedotconvD(3,:),'.-m');
grid on
title('RoC vs Va (Alt = 1219m, DEP off, ROM)')
xlabel('Airspeed, m/s')
ylabel('Rate of Climb, ft/min')
legend([roc1 roc2 roc3],...
       {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 5 deg','\delta_F_l_a_p = 12 deg'},...
       'Location','southeast');

% fig(3)=figure('Name','RoC vs Va, Case A','Position', [50 200 500 500]);
% roc1=plot(Va_range,zedotconvA(1,:),'.-r');
% hold on
% roc2=plot(Va_range,zedotconvA(2,:),'.-b');
% roc3=plot(Va_range,zedotconvA(3,:),'.-m');
% grid on
% title('RoC vs Va (Alt = 5m, DEP on, HFM)')
% xlabel('Airspeed, m/s')
% ylabel('Rate of Climb, ft/min')
% legend([roc1 roc2 roc3],...
%        {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 5 deg','\delta_F_l_a_p = 12 deg'},...
%        'Location','southeast');
% ylim([-250 50])
% 
% fig(4)=figure('Name','RoC vs Va, Case B','Position', [250 200 500 500]);
% roc1=plot(Va_range,zedotconvB(1,:),'.-r');
% hold on
% roc2=plot(Va_range,zedotconvB(2,:),'.-b');
% roc3=plot(Va_range,zedotconvB(3,:),'.-m');
% grid on
% title('RoC vs Va (Alt = 1219m, DEP off, HFM)')
% xlabel('Airspeed, m/s')
% ylabel('Rate of Climb, ft/min')
% legend([roc1 roc2 roc3],...
%        {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 5 deg','\delta_F_l_a_p = 12 deg'},...
%        'Location','southeast');
% ylim([-250 50])


ylim([-250 50])

%% Save results

% save figures
savefig(fig,logname + '_figs');
clear fig

% save workspace
save (logname);


