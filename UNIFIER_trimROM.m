
% clc
clear
% close all

% global check1
% check1 = [0;0;0;0;0];
% global check3
% check3 = 0;

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata_trim\UNIFIER_trim_out_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Configure trim run

global runconfig

runconfig.DEPset  = 0; % 1=DEP on, 0=DEP off
runconfig.ROMfile = 5; % 1=v1-72.74, 2=v1-50, 3=v0, 4=v3, 5=v2
runconfig.ROMdep  = 1; % 1=all dependencies, 2=reduced dependencies

runconfig.Va_target = 72.74;       % airspeed target (m/s) cruise=72.74m/s
runconfig.ze        = 1219;        % altitude (m) cruise=1219m
runconfig.dFlap     = deg2rad(0); % flap deflection (deg)

runconfig.penalty_zedot = 1;
runconfig.penalty_udot  = 1;
runconfig.penalty_wdot  = 1;
runconfig.penalty_qdot  = 100;
runconfig.penalty_Va    = 1;

dmc = 1e-8; %diffminchange

%% Load data

% aircraft data
load data/UNIFIER_LOAD.mat
global LOADROM
LOADROM.gr        = gr;
LOADROM.dp_DEP    = dp_DEP;
LOADROM.dp_HTU    = dp_HTU;
LOADROM.m         = m;
LOADROM.xyz_cg_12 = xyz_cg_12;
LOADROM.Iyy       = Iyy;
LOADROM.S         = S;
LOADROM.c         = c;
LOADROM.xyz_DEP   = xyz_DEP;
LOADROM.prop_d    = prop_d;
LOADROM.DEP_inc   = DEP_inc;
LOADROM.n_prop    = n_prop;

% Load ROM data
if runconfig.ROMfile==1
    load data/UNIFIER_ROM_72.mat % v1, 72.74 m/s
elseif runconfig.ROMfile==2
    load data/UNIFIER_ROM_50.mat % v1, 50 m/s
elseif runconfig.ROMfile==3
    load data/UNIFIER_ROM_v0.mat % v0
elseif runconfig.ROMfile==4
    load data/ROMv3/UNIFIER_ROMv3_20240613_002318.mat % v3, subset v1-50
elseif runconfig.ROMfile==5
    load data/ROMv2/UNIFIER_ROMv2_20240613_053529.mat % v2, subset v1-10
else
    error("Invalid ROM file setting")
end
LOADROM.ROM = ROM;

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
    load data/UNIFIER_trimROM_res zstar
    z0 = zstar;
end

%% Setup optimization

% Set options -------------------------------------------------------------

options.TolX          = 1e-10;  % Termination tolerance on x (aka step tolerance) Default=1e-6
options.DiffMinChange = dmc;  % Minimum change in variables for finite-difference gradients. Default=0.

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
         -runconfig.ze;    % ze
         zstar(1)*100;      % u
         zstar(2)*100;      % w
         zstar(3);          % theta
         0];                % q

if runconfig.DEPset==1
    ustar = [zstar(4);          % dElev
             zstar(5);          % DEP_col
             zstar(6);          % HTU
             runconfig.dFlap]; % dFlap
elseif runconfig.DEPset==0
    ustar = [zstar(4);          % dElev
             0;                 % DEP_col
             zstar(5);          % HTU
             runconfig.dFlap]; % dFlap 
else
    error("Invalid DEP setting")
end

vastar=sqrt(xstar(3)^2+xstar(4)^2);

% Evaluate accelerations --------------------------------------------------

xdotstar = UNIFIER_ROMdyn(xstar,ustar);

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
Va_error  = Va_actual-runconfig.Va_target

% f0 without penalties ----------------------------------------------------
Q = [xdotstar(2:6)';
    vastar-runconfig.Va_target];
H = diag(ones(1,numel(Q))); % penalty weight matrix
f0 = Q'*H*Q

% Numerical Settings & Results --------------------------------------------
% (for documentation purposes only)

funcinfo = dbstack;

numset = [options.TolX,...              % 2 TolX
          options.DiffMinChange,...     % 3 DiffMinChange
          inf,...                       % 4 DiffMaxChange
          1e-6,...                      % 5 TolFun
          runconfig.Va_target,...      % 6 Va target (m/s)
          runconfig.ze,...             % 7 Ze target (m)
          x0(1)*100,...                 % 8 u (m/s) guess
          x0(2)*100,...                 % 9 w (m/s) guess
          rad2deg(x0(3)),...            % 10 theta (deg) guess
          rad2deg(u0(1)),...            % 11 dElev (deg) guess
          rad2deg(runconfig.dFlap),... % 12 dFlap (deg) setting
          0,...                         % 13 DEP (0-1) setting
          u0(2),...                     % 14 HTU (0-1) guess
          runconfig.penalty_zedot,...  % 15 zedot objective penalty
          runconfig.penalty_udot,...   % 16 udot objective penalty
          runconfig.penalty_wdot,...   % 17 wdot objective penalty
          runconfig.penalty_qdot,...   % 18 qdot objective penalty
          runconfig.penalty_Va,...     % 19 Va objective penalty
          lb(5),...                     % 20 HTU lower bound
          runconfig.DEPset,...         % 21 DEP on/off
          runconfig.ROMfile,...        % 22 ROM file (74.74/50/v2)
          runconfig.ROMdep];           % 23 ROM dependency setting            

if runconfig.DEPset==1
    numset(12)=u0(2);
    numset(13)=u0(3);
    numset(19)=lb(6);
end

numres = [fval,...                       % 24 fval
          output.firstorderopt,...       % 25 Optimality
          0,...                          % 26 Step length
          output.stepsize,...            % 27 Norm of step
          output.iterations,...          % 28 Iterartions
          output.funcCount,...           % 29 Function evaluations
          t_fmincon,...                  % 30 Total time
          t_fmincon/output.funcCount,... % 31 Avg. per func. eval (s)
          f0];                           % 32 fval w/o penalties

xdotfill = [xdotstardisp(1),... % 33 x
            0,...               % 34 y
            xdotstardisp(2),... % 35 z
            xdotstardisp(3),... % 36 u
            0,...               % 37 v
            xdotstardisp(4),... % 38 w
            0,...               % 39 phi
            xdotstardisp(5),... % 40 theta
            0,...               % 41 psi
            0,...               % 42 p 
            xdotstardisp(6),... % 43 q
            0];                 % 44 r

numall = [timestamp numset numres xdotfill Va_actual Va_error funcinfo.name];
numall(34) = '-'; 
numall(37) = '-';  
numall(39) = '-'; 
numall(41) = '-';
numall(42) = '-'; 
numall(44) = '-';

if runconfig.DEPset==0
    numall(13)='-';
end

if runconfig.ROMfile==4 || runconfig.ROMfile==5
    numall(23)='-';
end

%% Save results

% save for next run
save data/UNIFIER_trimROM_res zstar xstar ustar vastar

% save workspace
save (logname);

% end diary
diary off
