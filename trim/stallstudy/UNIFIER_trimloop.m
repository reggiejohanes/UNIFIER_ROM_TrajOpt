
% clc
clear
close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIER_trimloop_' + timestamp; % name of diary & data log file

%% Set altitude, airspeed, & flap deflection range

ze_cruise   = 1219;
ze_landing  = 5;

Va_max      = 80;
Va_min      = 50;
Va_interval = 2.5;
Va_n        = (Va_max-Va_min)/Va_interval+1;
Va_range    = linspace(Va_min,Va_max,Va_n);

dFlap_range = [0 5 12];
dFlap_range = deg2rad(dFlap_range);

%% Calculate trim accelerations

fprintf('\n');
fprintf('<strong><< LOOP START >></strong>');
fprintf('\n');
fprintf('\n');
fprintf('<strong>CALCULATING..</strong>');

tic
set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
UNIFIER_dyn([],[],[],'compile')

for i=1:numel(dFlap_range)
    for j=1:Va_n

        % Case A - HFM, DEP on
        resA = UNIFIER_trimA_loop(ze_landing,Va_range(j),dFlap_range(i));
        zedotA(i,j) = resA.xdot(3);
        wdotA(i,j)  = resA.xdot(6);
        fvalA(i,j)  = resA.fval;
        
        % Case B - HFM, DEP off
        resB = UNIFIER_trimB_loop(ze_cruise,Va_range(j),dFlap_range(i));
        zedotB(i,j) = resB.xdot(3);
        wdotB(i,j)  = resB.xdot(6);
        fvalB(i,j)  = resB.fval;

        % Case C - ROM, DEP on
        resC = UNIFIER_trimC_loop(ze_landing,Va_range(j),dFlap_range(i));
        zedotC(i,j) = resC.xdot(3);
        wdotC(i,j)  = resC.xdot(6);
        fvalC(i,j)  = resC.fval;

        % Case D - ROM, DEP off
        resD = UNIFIER_trimD_loop(ze_cruise,Va_range(j),dFlap_range(i));
        zedotD(i,j) = resD.xdot(3);
        wdotD(i,j)  = resD.xdot(6);
        fvalD(i,j)  = resD.fval;
        
        fprintf('.')

    end
end

UNIFIER_dyn([],[],[],'term')

fprintf('\n');
fprintf('\n');
fprintf('<strong><< LOOP END >></strong>');
fprintf('\n');
fprintf('\n');

t_eval = toc;
evals  = Va_n*numel(dFlap_range);
fprintf('Total               = %6.4f seconds\n',t_eval);
fprintf('Avg. per Evaluation = %6.4f seconds\n',t_eval/evals);
fprintf('\n');

%% Convert units

zedotconvA = convvel(zedotA,'m/s','ft/min')*-1;
zedotconvB = convvel(zedotB,'m/s','ft/min')*-1;
zedotconvC = convvel(zedotC,'m/s','ft/min')*-1;
zedotconvD = convvel(zedotD,'m/s','ft/min')*-1;

%% Plot results

close all

fig(1)=figure('Name','RoC vs Va, Case A','Position', [50 200 500 500]);
roc1=plot(Va_range,zedotconvA(1,:),'.-r');
hold on
roc2=plot(Va_range,zedotconvA(2,:),'.-b');
roc3=plot(Va_range,zedotconvA(3,:),'.-m');
grid on
title('RoC vs Va (Alt = 5m, DEP on, HFM)')
xlabel('Airspeed, m/s')
ylabel('Rate of Climb, ft/min')
legend([roc1 roc2 roc3],...
       {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 5 deg','\delta_F_l_a_p = 12 deg'},...
       'Location','southeast');

fig(2)=figure('Name','RoC vs Va, Case B','Position', [250 200 500 500]);
roc1=plot(Va_range,zedotconvB(1,:),'.-r');
hold on
roc2=plot(Va_range,zedotconvB(2,:),'.-b');
roc3=plot(Va_range,zedotconvB(3,:),'.-m');
grid on
title('RoC vs Va (Alt = 1219m, DEP off, HFM)')
xlabel('Airspeed, m/s')
ylabel('Rate of Climb, ft/min')
legend([roc1 roc2 roc3],...
       {'\delta_F_l_a_p = 0 deg','\delta_F_l_a_p = 5 deg','\delta_F_l_a_p = 12 deg'},...
       'Location','southeast');

fig(3)=figure('Name','RoC vs Va, Case C','Position', [450 200 500 500]);
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

fig(4)=figure('Name','RoC vs Va, Case D','Position', [650 200 500 500]);
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

%% Save results

% save figures
savefig(fig,logname + '_figs');
clear fig

% save workspace
save (logname);


