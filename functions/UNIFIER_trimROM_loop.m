function res=UNIFIER_trimROM_loop(DEPset,ROMfile,ROMdep,Va_target,ze,dFlap,penalty,dmc)

%% Configure trim run

global runconfig

runconfig.DEPset  = DEPset;  % 1=DEP on, 0=DEP off
runconfig.ROMfile = ROMfile; % 1=72.74, 2=50, 3=v2a
runconfig.ROMdep  = ROMdep;  % 1=all dependencies, 2=reduced dependencies

runconfig.Va_target = Va_target; % airspeed target (m/s) cruise=72.74m/s
runconfig.ze        = ze;        % altitude (m) cruise=1219m
runconfig.dFlap     = dFlap;     % flap deflection (deg)

runconfig.penalty_zedot = penalty.zedot;
runconfig.penalty_udot  = penalty.udot;
runconfig.penalty_wdot  = penalty.wdot;
runconfig.penalty_qdot  = penalty.qdot;
runconfig.penalty_Va    = penalty.Va;

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

z0 = [x0;u0];

%% Setup optimization

% Set options -------------------------------------------------------------

options.TolX          = 1e-10;  % Termination tolerance on x (aka step tolerance) Default=1e-6
options.DiffMinChange = dmc;  % Minimum change in variables for finite-difference gradients. Default=0.

options.Display       = 'off';
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
% options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Set bounds --------------------------------------------------------------

load UNIFIER_LOAD umin umax

% upper bounds
ub=[76/100,...          % u
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

% tic
[zstar,fval,exitflag,output] = fmincon(@(x) UNIFIER_trimROM_obj(x),z0,[],[],[],[],lb,ub,[],options);
% t_fmincon=toc;

%% Process Results

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

res.xdot = xdotstar;
res.Va   = vastar;
res.fval = fval;

