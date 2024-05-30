

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIERsim_' + timestamp; % name of diary & data log file

%% Assign variables

res.t             = out.tout;
res.Va            = out.states(:,1);
res.x             = out.states(:,2);
res.z             = out.states(:,3);
res.theta         = out.states(:,4);
res.q             = out.states(:,5);
res.Va_ref        = out.Va_ctrl(:,1);
res.thr_cmd       = out.Va_ctrl(:,2);
res.Ze_ref        = out.alt_ctrl(:,1);
res.theta_cmd     = out.alt_ctrl(:,2);
res.q_cmd         = out.alt_ctrl(:,3);
res.elev_cmd      = out.alt_ctrl(:,4);
res.elev_cmd_trim = out.u_cmd_trim(:,1);
res.DEP_cmd_trim  = out.u_cmd_trim(:,2);
res.HTU_cmd_trim  = out.u_cmd_trim(:,3);
res.elev          = out.u_cmd_trim_lim(:,1);
res.DEP_col       = out.u_cmd_trim_lim(:,2);
res.HTU           = out.u_cmd_trim_lim(:,3);

%% Plots

% altitude vs distance
% fig(1)=figure('Name','Physical Trajectory','Position', [50 450 1200 400]);
% plot(solution.X(:,1)/1000,-1*solution.X(:,2),'.-k')
% title('Altitude vs Horizontal Distance')
% xlabel('Horizontal Distance, km')
% ylabel('Altitude, m')
% grid on

%% Save results

% save figures
% savefig(fig,logname + '_figs');
% clear fig

% save workspace
save(logname);
