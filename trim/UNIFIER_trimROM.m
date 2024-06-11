
% clc
clear
% close all

% global check1
% check1 =[0;0;0;0;0];

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata\UNIFIER_trim_out_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Set target trim conditions

global trimconfig

trimconfig.DEPset  = 0; % 1=DEP on, 0=DEP off
trimconfig.ROMfile = 3; % 1=72.74, 2=50, 3=v2a
trimconfig.ROMdep  = 1; % 1=all dependencies, 2=reduced dependencies

trimconfig.Va_target = 50;       % airspeed target (m/s) cruise=72.74m/s
trimconfig.ze        = 1219;        % altitude (m) cruise=1219m
trimconfig.dFlap     = deg2rad(0); % flap deflection (deg)

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
      0.5;         % DEP activity factor [0-1]
      0.5];        % HTU activity factor [0-1]

if trimconfig.DEPset==0
    u0(2)=[];
end

init = 0;  % 0 = start from initial guess
           % 1 = use saved values from last run

if init==0
    z0 = [x0;u0];
else
    load UNIFIER_trimROM_res zstar
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
options.DiffMaxChange = inf;  % Maximum change in variables for finite-difference gradients. Default=Inf.
% options.TolFun        = 1e-8;  % Termination tolerance on the first-order optimality (aka optimalityTolerance). Default=1e-6. 
% options.TolCon        = 1e-3;  % Constraint violation tolerance
% options.MaxIter       = 100;   % Max iterations
% options.MaxFunEvals   = 1000;  % Max function evaluations
options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Set bounds --------------------------------------------------------------

load UNIFIER_LOAD umin umax

% upper bounds
ub=[inf,...          % u
    inf,...          % w
    deg2rad(10),...  % theta (pitch)
    umax(3),...      % dElevator
    umax(5),...      % DEP_col
    umax(7)];        % HTU

% lower bounds
lb=[0,...            % u
    -inf,...         % w
    -deg2rad(5),...  % theta (pitch)
    umin(3),...      % dElevator
    umin(5),...      % DEP_col
    umin(7)];        % HTU

if trimconfig.DEPset==0
    ub(5)=[];
    lb(5)=[];
end

%% Execute optimization

fprintf('<strong><< OPTIMIZATION START >></strong>');
fprintf('\n');
fprintf('\n');

tic
[zstar,fval,exitflag,output] = fmincon(@(x) UNIFIER_trimROM_obj(x),z0,[],[],[],[],lb,ub,[],options);
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

% check2(1,:)=check1(1,:)*100;
% check2(2,:)=check1(2,:)*100;
% check2(3,:)=rad2deg(check1(3,:));
% check2(4,:)=rad2deg(check1(4,:));
% check2(5,:)=check1(5,:);
% global outputFcn_global_data;

% Extract states & controls -----------------------------------------------

xstar = [0;                 % xe
         -trimconfig.ze;    % ze
         zstar(1)*100;      % u
         zstar(2)*100;      % w
         zstar(3);          % theta
         0];                % q

if trimconfig.DEPset==1
    ustar = [zstar(4);          % dElev
             zstar(5);          % DEP_col
             zstar(6);          % HTU
             trimconfig.dFlap]; % dFlap
elseif trimconfig.DEPset==0
    ustar = [zstar(4);          % dElev
             0;                 % DEP_col
             zstar(5);          % HTU
             trimconfig.dFlap]; % dFlap 
else
    error("Invalid DEP setting")
end

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

numset = [options.TolX,...              % 2 TolX
          options.DiffMinChange,...     % 3 DiffMinChange
          inf,...                       % 4 DiffMaxChange
          1e-6,...                      % 5 TolFun
          trimconfig.Va_target,...      % 6 Va target (m/s)
          trimconfig.ze,...             % 7 Ze target (m)
          x0(1)*100,...                 % 8 u (m/s) guess
          x0(2)*100,...                 % 9 w (m/s) guess
          rad2deg(x0(3)),...            % 10 theta (deg) guess
          rad2deg(u0(1)),...            % 11 dElev (deg) guess
          rad2deg(trimconfig.dFlap),... % 12 dFlap (deg) setting
          0,...                         % 13 DEP (0-1) setting
          u0(2),...                     % 14 HTU (0-1) guess
          trimconfig.penalty_zedot,...  % 15 zedot objective penalty
          trimconfig.penalty_udot,...   % 16 udot objective penalty
          trimconfig.penalty_wdot,...   % 17 wdot objective penalty
          trimconfig.penalty_qdot,...   % 18 qdot objective penalty
          trimconfig.penalty_Va,...     % 19 Va objective penalty
          lb(5),...                     % 20 HTU lower bound
          trimconfig.DEPset,...         % 21 DEP on/off
          trimconfig.ROMfile,...        % 22 ROM file (74.74/50/v2)
          trimconfig.ROMdep];           % 23 ROM dependency setting            

if trimconfig.DEPset==1
    numset(12)=u0(2);
    numset(13)=u0(3);
    numset(19)=lb(6);
end

numres = [fval,...                     % 24 fval
          output.firstorderopt,...     % 25 Optimality
          0,...                        % 26 Step length
          output.stepsize,...          % 27 Norm of step
          output.iterations,...        % 28 Iterartions
          output.funcCount,...         % 29 Function evaluations
          t_fmincon,...                % 30 Total time
          t_fmincon/output.funcCount]; % 31 Avg. per func. eval (s)

xdotfill = [xdotstardisp(1),... % 32 x
            0,...               % 33 y
            xdotstardisp(2),... % 34 z
            xdotstardisp(3),... % 35 u
            0,...               % 36 v
            xdotstardisp(4),... % 37 w
            0,...               % 38 phi
            xdotstardisp(5),... % 39 theta
            0,...               % 40 psi
            0,...               % 41 p 
            xdotstardisp(6),... % 42 q
            0];                 % 43 r

numall = [timestamp numset numres xdotfill Va_actual Va_error funcinfo.name];
numall(33) = '-'; 
numall(36) = '-';  
numall(38) = '-'; 
numall(40) = '-';
numall(41) = '-'; 
numall(43) = '-';

if trimconfig.DEPset==0
    numall(13)='-';
end

%% Save results

% save for next run
save UNIFIER_trimROM_res zstar xstar ustar vastar

% save workspace
save (logname);

% end diary
diary off
