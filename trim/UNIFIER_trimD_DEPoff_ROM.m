
% clc
clear
close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIER_trim_out_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Configure trim run

global trimconfig

trimconfig.ROMfile = 2; % 1=72.74, 2=50, 3=v2a
trimconfig.ROMset  = 2; % 1=all dependencies, 2=reduced dependencies

trimconfig.Va_target    = 72.74; % airspeed target (m/s) cruise=72.74m/s
trimconfig.ze    = 1219;         % altitude (m) cruise=1219m
trimconfig.dFlap = deg2rad(12);  % flap deflection (deg)

trimconfig.penalty_zedot = 1;
trimconfig.penalty_udot  = 1;
trimconfig.penalty_wdot  = 1;
trimconfig.penalty_qdot  = 10;
trimconfig.penalty_Va    = 1;

%% Initialize z_guess

% Initial states
x0 = [trimconfig.Va_target/100; % u [m/s]
      0/100;                    % w [m/s]
      deg2rad(0)];              % theta [deg]

% Initial control inputs
u0 = [deg2rad(0);  % Elevator deflection [deg]
      0.5];        % HTU activity factor [0-1]

init = 0;  % 0 = start from initial guess
           % 1 = use saved values from last run

if init==0
    z0 = [x0;u0];
else
    load UNIFIER_trimD_res zstar
    z0 = zstar;
end

%% Optimization

fprintf('<strong><< OPTIMIZATION START >></strong>');
fprintf('\n');
fprintf('\n');

% Set bounds --------------------------------------------------------------

load UNIFIER_LOAD umin umax

% upper bounds
ub=[inf,...          % u
    inf,...          % w
    deg2rad(10),...  % theta (pitch)
    umax(3),...      % dElevator
    umax(7)];        % HTU

% lower bounds
lb=[0,...            % u
    -inf,...         % w
    -deg2rad(5),...  % theta (pitch)
    umin(3),...      % dElevator
    umin(7)];        % HTU

% Set options -------------------------------------------------------------

options.Display       = 'iter-detailed';
% options.Algorithm     = 'sqp';
options.Algorithm     = 'interior-point';
options.FunValCheck   = 'off';
options.ScaleProblem  = 'false';
options.FinDiffType   = 'forward';
options.TolX          = 1e-10;  % Termination tolerance on x (aka step tolerance) Default=1e-6
options.DiffMinChange = 1e-8;  % Minimum change in variables for finite-difference gradients. Default=0.
% options.DiffMaxChange = 1e-0;  % Maximum change in variables for finite-difference gradients. Default=Inf.
% options.TolFun        = 1e-8;  % Termination tolerance on the first-order optimality (aka optimalityTolerance). Default=1e-6. 
% options.TolCon        = 1e-3;  % Constraint violation tolerance
% options.MaxIter       = 100;   % Max iterations
% options.MaxFunEvals   = 1000;  % Max function evaluations
options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Run optimization --------------------------------------------------------

tic
[zstar,fval,exitflag,output] = fmincon(@(x) UNIFIER_trimD_obj(x),z0,[],[],[],[],lb,ub,[],options);
t_fmincon=toc;

fprintf('<strong><< OPTIMIZATION COMPLETE >></strong>');
fprintf('\n');
fprintf('\n');
disp('Optimization Processing Time:');
% fprintf('Total                = %6s\n',char(duration(0,0,t_fmincon)));
% fprintf('Avg. per Iteration   = %6s\n',char(duration(0,0,t_fmincon/(output.iterations+1))));
fprintf('Total                = %6.4f seconds\n',t_fmincon);
fprintf('Avg. per Iteration   = %6.4f seconds\n',t_fmincon/(output.iterations+1));
fprintf('Avg. per Func. Eval. = %6.4f seconds\n',t_fmincon/output.funcCount);

%% Process Results

% Extract states & controls -----------------------------------------------

xstar = [0;                 % xe
         -trimconfig.ze;    % ze
         zstar(1)*100;      % u
         zstar(2)*100;      % w
         zstar(3);          % theta
         0];                % q
ustar = [zstar(4);          % dElev
         0;                 % DEP_col
         zstar(5);          % HTU
         trimconfig.dFlap]; % dFlap

vastar=sqrt(xstar(3)^2+xstar(4)^2);

% Evaluate accelerations --------------------------------------------------

xdotstar = UNIFIER_ROMdyn_trim(xstar,ustar);

% Table 1 - States --------------------------------------------------------
xstardisp=xstar;
xstardisp(5:6)=rad2deg(xstardisp(5:6));
xtable=array2table(xstardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) xe    [m]', ...
    '2) ze    [m]', ...
    '3) u     [m/s]', ...
    '4) w     [m/s]', ...
    '5) theta [deg]', ...
    '6) q     [deg/s]'});
xtable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), xtable);
xtable0.Properties.VariableNames = xtable.Properties.VariableNames;
xtable0.Properties.RowNames = xtable.Properties.RowNames;
fprintf('\n');
disp('<strong>> Table 1 - States</strong>')
disp(xtable0)
fprintf('\n');

% Table 2 - Controls ------------------------------------------------------
ustardisp=ustar;
ustardisp(1)=rad2deg(ustardisp(1));
ustardisp(4)=rad2deg(ustardisp(4));
utable=array2table(ustardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) dElevator [deg]', ...
    '2) DEP_col   [deg]', ...
    '3) HTU       [deg]', ...
    '4) dFlap     [deg]'});
utable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), utable);
utable0.Properties.VariableNames = utable.Properties.VariableNames;
utable0.Properties.RowNames = utable.Properties.RowNames;
disp('<strong>> Table 2 - Control Inputs</strong>')
disp(utable0)
fprintf('\n');

% Table 3 - Accelerations -------------------------------------------------
xdotstardisp=xdotstar';
xdotstardisp(5:6)=rad2deg(xdotstardisp(5:6));
xdottable=array2table(xdotstardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) xedot    [m/s]', ...
    '2) zedot    [m/s]', ...    
    '3) udot     [m/s2]', ...
    '4) wdot     [m/s2]', ...
    '5) thetadot [deg/s]', ...
    '6) qdot     [deg/s2]'});
xdottable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), xdottable);
xdottable0.Properties.VariableNames = xdottable.Properties.VariableNames;
xdottable0.Properties.RowNames = xdottable.Properties.RowNames;
disp('<strong>> Table 3 - Accelerations</strong>')
disp(xdottable0)

% Va results --------------------------------------------------------------
Va_actual = vastar
Va_error  = Va_actual-trimconfig.Va_target

% Numerical Settings & Results --------------------------------------------
% (for documentation purposes only)

funcinfo = dbstack;

numset = [options.TolX,...              % TolX
          options.DiffMinChange,...     % DiffMinChange
          inf,...                       % DiffMaxChange
          1e-6,...                      % TolFun
          trimconfig.Va_target,...      % Va target (m/s)
          trimconfig.ze,...             % Ze target (m)
          x0(1)*100,...                 % u (m/s) guess
          x0(2)*100,...                 % w (m/s) guess
          rad2deg(x0(3)),...            % theta (deg) guess
          rad2deg(u0(1)),...            % dElev (deg) guess
          rad2deg(trimconfig.dFlap),... % dFlap (deg) setting
          0,...                         % DEP (0-1) setting
          u0(2),...                     % HTU (0-1) guess
          trimconfig.penalty_zedot,...  % zedot objective penalty
          trimconfig.penalty_udot,...   % udot objective penalty
          trimconfig.penalty_wdot,...   % wdot objective penalty
          trimconfig.penalty_qdot,...   % qdot objective penalty
          trimconfig.penalty_Va,...     % Va objective penalty
          lb(5)];                       % HTU lower bound

numres = [fval,...                     % fval
          output.firstorderopt,...     % Optimality
          0,...                        % Step length
          output.stepsize,...          % Norm of step
          output.iterations,...        % Iterartions
          output.funcCount,...         % Function evaluations
          t_fmincon,...                % Total time
          t_fmincon/output.funcCount]; % Avg. per func. eval (s)

xdotfill = [xdotstardisp(1),...
            0,...
            xdotstardisp(2),...
            xdotstardisp(3),...
            0,...
            xdotstardisp(4),...
            0,...
            xdotstardisp(5),...
            0,...
            0,...
            xdotstardisp(6),...
            0];

numall = [numset numres timestamp xdotfill Va_actual Va_error funcinfo.name];
numall(12) = '-';
numall(30) = '-'; 
numall(33) = '-';  
numall(35) = '-'; 
numall(37) = '-';
numall(38) = '-'; 
numall(40) = '-';

%% Save results

% save for next run
save UNIFIER_trimD_res zstar xstar ustar vastar

% save workspace
save (logname);

% end diary
diary off
