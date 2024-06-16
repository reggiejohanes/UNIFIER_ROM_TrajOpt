
% clc
clear
% close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata_trim\UNIFIER_trim_out_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Set target trim conditions

global runconfig

runconfig.DEPset    = 0; % 1=DEP on, 0=DEP off

runconfig.Va_target = 72.74;       % airspeed target (m/s) cruise=72.74m/s
runconfig.ze        = 1219;        % altitude (m) cruise=1219m
runconfig.dFlap     = deg2rad(0); % flap deflection (deg)

runconfig.penalty_zedot = 1;
runconfig.penalty_udot  = 1;
runconfig.penalty_wdot  = 1;
runconfig.penalty_qdot  = 100;
runconfig.penalty_Va    = 1;

%% Initialize z_guess

% Initial states
x0 = [runconfig.Va_target/100; % u [m/s]
      0/100;                    % w [m/s]
      deg2rad(0)];              % theta [deg]

% Initial control inputs
u0 = [deg2rad(0);  % Elevator deflection [deg]
      0.5;         % DEP activity factor [0-1]
      0.5];        % HTU activity factor [0-1]

if runconfig.DEPset==0
    u0(2)=[];
end

init = 0;  % 0 = start from initial guess
           % 1 = use saved values from last run

if init==0
    z0 = [x0;u0];
else
    load data/UNIFIER_trimHFM_res zstar
    z0 = zstar;
end

%% Setup optimization

% Set options -------------------------------------------------------------

options.TolX          = 1e-10;  % Termination tolerance on x (aka step tolerance) Default=1e-6
options.DiffMinChange = 1e-8;  % Minimum change in variables for finite-difference gradients. Default=0.

options.Display       = 'iter-detailed';
% options.Algorithm     = 'sqp';
options.Algorithm     = 'interior-point';
options.FunValCheck   = 'off';
options.ScaleProblem  = 'false';
options.FinDiffType   = 'forward';
% options.DiffMaxChange = 1e-0;  % Maximum change in variables for finite-difference gradients. Default=Inf.
% options.TolFun        = 1e-8;  % Termination tolerance on the first-order optimality (aka optimalityTolerance). Default=1e-6. 
% options.TolCon        = 1e-3;  % Constraint violation tolerance
% options.MaxIter       = 100;   % Max iterations
% options.MaxFunEvals   = 1000;  % Max function evaluations
options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Set bounds --------------------------------------------------------------

load UNIFIER_LOAD umin umax

% upper bounds
ub=[75/100,...          % u
    75*sind(20)/100,... % w
    deg2rad(10),...     % theta (pitch)
    umax(3),...         % dElevator
    umax(5),...         % DEP_col
    umax(7)];           % HTU

% lower bounds
lb=[35*cosd(20)/100,...  % u
    -75*sind(20)/100,... % w
    -deg2rad(5),...      % theta (pitch)
    umin(3),...          % dElevator
    umin(5),...          % DEP_col
    umin(7)];            % HTU

if runconfig.DEPset==0
    ub(5)=[];
    lb(5)=[];
end

%% Execute optimization

fprintf('<strong><< OPTIMIZATION START >></strong>');
fprintf('\n');
fprintf('\n');

tic
set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
UNIFIER_dyn([],[],[],'compile')
[zstar,fval,exitflag,output] = fmincon(@(x) UNIFIER_trimHFM_obj(x),z0,[],[],[],[],lb,ub,[],options);
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

% Get intermediate results ------------------------------------------------

global outputFcn_global_data;

% Extract states & controls -----------------------------------------------

xstar=[0;...              % xe
       0;...              % ye
       -runconfig.ze;... % ze
       zstar(1)*100;...   % u
       0;...              % v
       zstar(2)*100;...   % w
       0;...              % phi
       zstar(3);...       % theta
       0;...              % psi
       0;...              % p
       0;...              % q
       0];                % r

if runconfig.DEPset==1
    ustar=[0;...                % dAil
           0;...                % dRud
           zstar(4);...         % dElev
           runconfig.dFlap;... % dFlap
           zstar(5);...         % DEP_col
           0;...                % DEP_slope
           zstar(6)];           % HTU
elseif runconfig.DEPset==0
    ustar=[0;...                % dAil
           0;...                % dRud
           zstar(4);...         % dElev
           runconfig.dFlap;... % dFlap
           0;...                % DEP_col
           0;...                % DEP_slope
           zstar(5)];           % HTU
else
    error("Invalid DEP setting")
end

vastar=sqrt(xstar(4)^2+xstar(5)^2+xstar(6)^2);

% Evaluate accelerations --------------------------------------------------

% xdotstar=UNIFIER_dynamics(xstar,ustar);

out  = UNIFIER_dyn(0,[],[xstar;ustar],'outputs');
UNIFIER_dyn([],[],[],'term')
xdotstar = out(1:12);

% Table 1 - States --------------------------------------------------------
xstardisp=xstar;
xstardisp(7:12)=rad2deg(xstardisp(7:12));
xtable=array2table(xstardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) xe    [m]', ...
    '2) ye    [m]', ...
    '3) ze    [m]', ...
    '4) u     [m/s]', ...
    '5) v     [m/s]', ...
    '6) w     [m/s]', ...
    '7) phi   [deg]', ...
    '8) theta [deg]', ...
    '9) psi   [deg]', ...
    '10) p    [deg/s]', ...
    '11) q    [deg/s]', ...
    '12) r    [deg/s]'});
xtable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), xtable);
xtable0.Properties.VariableNames = xtable.Properties.VariableNames;
xtable0.Properties.RowNames = xtable.Properties.RowNames;
fprintf('\n');
disp('<strong>> Table 1 - States</strong>')
disp(xtable0)
fprintf('\n');

% Table 2 - Controls ------------------------------------------------------
ustardisp=ustar;
ustardisp(1:4)=rad2deg(ustardisp(1:4));
utable=array2table(ustardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) dAileron  [deg]', ...
    '2) dRudder   [deg]', ...
    '3) dElevator [deg]', ...
    '4) dFlap     [deg]', ...
    '5) DEP_col   [deg]', ...
    '6) DEP_slope [deg]', ...
    '7) HTU       [deg]'});
utable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), utable);
utable0.Properties.VariableNames = utable.Properties.VariableNames;
utable0.Properties.RowNames = utable.Properties.RowNames;
disp('<strong>> Table 2 - Control Inputs</strong>')
disp(utable0)
fprintf('\n');

% Table 3 - Accelerations -------------------------------------------------
xdotstardisp=xdotstar;
xdotstardisp(7:12)=rad2deg(xdotstardisp(7:12));
xdottable=array2table(xdotstardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) xedot    [m/s]', ...
    '2) yedot    [m/s]', ...
    '3) zedot    [m/s]', ...    
    '4) udot     [m/s2]', ...
    '5) vdot     [m/s2]', ...
    '6) wdot     [m/s2]', ...
    '7) phidot   [deg/s]', ...
    '8) thetadot [deg/s]', ...
    '9) psidot   [deg/s]', ...
    '10) pdot    [deg/s2]', ...
    '11) qdot    [deg/s2]', ...
    '12) rdot    [deg/s2]'});
xdottable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), xdottable);
xdottable0.Properties.VariableNames = xdottable.Properties.VariableNames;
xdottable0.Properties.RowNames = xdottable.Properties.RowNames;
disp('<strong>> Table 3 - Accelerations</strong>')
disp(xdottable0)

% Va results --------------------------------------------------------------
Va_actual = vastar
Va_error  = Va_actual-runconfig.Va_target

% f0 without penalties ----------------------------------------------------
Q = [xdotstar(2:12);
    vastar-runconfig.Va_target];
H = diag(ones(1,numel(Q))); % penalty weight matrix
f0 = Q'*H*Q

% Numerical Settings & Results --------------------------------------------
% (for documentation purposes only)

funcinfo = dbstack;

numset = [options.TolX,...              % TolX
          options.DiffMinChange,...     % DiffMinChange
          inf,...                       % DiffMaxChange
          1e-6,...                      % TolFun
          runconfig.Va_target,...      % Va target (m/s)
          runconfig.ze,...             % Ze target (m)
          x0(1)*100,...                 % u (m/s) guess
          x0(2)*100,...                 % w (m/s) guess
          rad2deg(x0(3)),...            % theta (deg) guess
          rad2deg(u0(1)),...            % dElev (deg) guess
          rad2deg(runconfig.dFlap),... % dFlap (deg) setting
          0,...                         % DEP (0-1) setting
          u0(2),...                     % HTU (0-1) guess
          runconfig.penalty_zedot,...  % zedot objective penalty
          runconfig.penalty_udot,...   % udot objective penalty
          runconfig.penalty_wdot,...   % wdot objective penalty
          runconfig.penalty_qdot,...   % qdot objective penalty
          runconfig.penalty_Va,...     % Va objective penalty
          lb(5),...                     % HTU lower bound
          runconfig.DEPset,...         % DEPset
          0,...                         % ROMfile
          0];                           % ROMset

if runconfig.DEPset==1
    numset(12)=u0(2);
    numset(13)=u0(3);
    numset(19)=lb(6);
end
    
numres = [fval,...                       % fval
          output.firstorderopt,...       % Optimality
          0,...                          % Step length
          output.stepsize,...            % Norm of step
          output.iterations,...          % Iterartions
          output.funcCount,...           % Function evaluations
          t_fmincon,...                  % Total time
          t_fmincon/output.funcCount,... % Avg. per func. eval (s)
          f0];                           % fval w/o penalties

numall = [timestamp numset numres xdotstardisp' Va_actual Va_error funcinfo.name];

numall(22) = '-';
numall(23) = '-';
if runconfig.DEPset==0
    numall(13) = '-';
end

%% Save results

% save for next run
save data/UNIFIER_trimHFM_res zstar xstar ustar vastar

% save workspace
save (logname);

% end diary
diary off
