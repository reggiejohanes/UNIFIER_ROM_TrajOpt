function res=UNIFIER_trimROM_loop(DEPset,ROMfile,ROMdep,Va_target,ze,dFlap,penalty,dmc)

%% Configure trim run

global trimconfig

trimconfig.DEPset  = DEPset;  % 1=DEP on, 0=DEP off
trimconfig.ROMfile = ROMfile; % 1=72.74, 2=50, 3=v2a
trimconfig.ROMdep  = ROMdep;  % 1=all dependencies, 2=reduced dependencies

trimconfig.Va_target = Va_target; % airspeed target (m/s) cruise=72.74m/s
trimconfig.ze        = ze;        % altitude (m) cruise=1219m
trimconfig.dFlap     = dFlap;     % flap deflection (deg)

trimconfig.penalty_zedot = penalty.zedot;
trimconfig.penalty_udot  = penalty.udot;
trimconfig.penalty_wdot  = penalty.wdot;
trimconfig.penalty_qdot  = penalty.qdot;
trimconfig.penalty_Va    = penalty.Va;

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

% tic
[zstar,fval,exitflag,output] = fmincon(@(x) UNIFIER_trimROM_obj(x),z0,[],[],[],[],lb,ub,[],options);
% t_fmincon=toc;

%% Process Results

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

res.xdot = xdotstar;
res.Va   = vastar;
res.fval = fval;

