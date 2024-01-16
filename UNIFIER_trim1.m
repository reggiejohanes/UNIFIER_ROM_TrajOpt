
clc
clear
close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIER_trim1_out_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Set target trim conditions

Va_target = 72.74;  % airspeed target [m/s] cruise=72.74
ze_target = 1219; % altitude [m] cruise=1219

global target
target.Va    = Va_target;
target.ze    = ze_target;

%% Initialize z_guess

% Initial states
x0 = [Va_target;   % u [m/s]
      0;           % w [m/s]
      deg2rad(1)]; % theta [deg]

% Initial control inputs
u0 = [deg2rad(-2);  % Elevator deflection [deg]
      deg2rad(12);  % Flap deflection [deg]
      0.5];        % DEP activity factor (collective) [0-1]

init = 1;  % 0 = start from initial guess
           % 1 = use saved values from last run

if init==0
    z0 = [x0;u0];
else
    load UNIFIER_trim1_res zstar
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
    deg2rad(10),...  % theta pitch
    umax(3),...      % dElevator
    umax(4),...      % dFlap
    umax(5)];        % DEP_col

% lower bounds
lb=[-inf,...         % u
    -inf,...         % w
    -deg2rad(5),...  % theta pitch
    umin(3),...      % dElevator
    umin(4),...      % dFlap
    umin(5)];        % DEP_col

% Set options -------------------------------------------------------------

options.Display       = 'iter-detailed';
options.Algorithm     = 'sqp';
options.FunValCheck   = 'off';
options.ScaleProblem  = 'false';
options.FinDiffType   = 'forward';
options.TolX          = 1e-8;  % Termination tolerance on x (aka step tolerance) Default=1e-6
options.DiffMinChange = 1e-5;  % Minimum change in variables for finite-difference gradients. Default=0.
% options.DiffMaxChange = 1e-0;  % Maximum change in variables for finite-difference gradients. Default=Inf.
% options.TolFun        = 1e-8;  % Termination tolerance on the first-order optimality (aka optimalityTolerance). Default=1e-6. 
% options.TolCon        = 1e-3;  % Constraint violation tolerance
% options.MaxIter       = 100;   % Max iterations
options.MaxFunEvals   = 1000;  % Max function evaluations
options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Run optimization --------------------------------------------------------

tic
[zstar,fval,exitflag,output] = fmincon(@(x) UNIFIER_trim1_obj(x),z0,[],[],[],[],lb,ub,[],options);
t_fmincon=toc;

fprintf('<strong><< OPTIMIZATION COMPLETE >></strong>');
fprintf('\n');
fprintf('\n');
disp('Optimization Processing Time:');
fprintf('Total                = %6s\n',char(duration(0,0,t_fmincon)));
fprintf('Avg. per Iteration   = %6s\n',char(duration(0,0,t_fmincon/(output.iterations+1))));
fprintf('Avg. per Func. Eval. = %6.4f seconds\n',t_fmincon/output.funcCount);

%% Process Results

% Extract states & controls -----------------------------------------------
xstar=[0;...          % xe
       0;...          % ye
       -ze_target;... % ze
       zstar(1);...   % u
       0;...          % v
       zstar(2);...   % w
       0;...          % phi
       zstar(3);...   % theta
       0;...          % psi
       0;...          % p
       0;...          % q
       0];            % r
ustar=[0;...          % dAil
       0;...          % dRud
       zstar(4);...   % dElev
       zstar(5);...   % dFlap
       zstar(6);...   % DEP_col
       0;...          % DEP_slope
       0];            % HTU

% Evaluate accelerations --------------------------------------------------
xdotstar=UNIFIER_dynamics(xstar,ustar);

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

%% Save results

% save for next run
save UNIFIER_trim1_res zstar xstar ustar

% save workspace
save (logname);

% end diary
diary off
