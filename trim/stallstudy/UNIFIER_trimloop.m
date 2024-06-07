
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

Va_max      = 90;
Va_min      = 30;
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
        res = UNIFIER_trimA_loop(ze_cruise,Va_range(j),dFlap_range(i));
        zedot(i,j) = res.xdot(3);
        wdot(i,j)  = res.xdot(6);
        fval(i,j)  = res.fval;
        
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

zedotconv=convvel(zedot,'m/s','ft/min')*-1;

%% Plot results

close all

fig(1)=figure('Name','Rate of Climb vs Airspeed','Position', [50 200 500 500]);
roc1=plot(Va_range,zedotconv(1,:),'.-r');
hold on
roc2=plot(Va_range,zedotconv(2,:),'.-b');
roc3=plot(Va_range,zedotconv(3,:),'.-m');
grid on
title('Rate of Climb vs Airspeed at Best Trim Results (Alt=1219m, HFM)')
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


