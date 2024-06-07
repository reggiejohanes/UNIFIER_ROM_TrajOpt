function res=UNIFIER_trimC_loop(ze_target,Va_target,dFlap)

global target
target.Va    = Va_target;
target.ze    = ze_target;
target.dFlap = dFlap;

global penalty
penalty.zedot = 1;
penalty.udot  = 1;
penalty.wdot  = 1;
penalty.qdot  = 100;
penalty.Va    = 1;

%% Initialize z_guess

% Initial states
x0 = [Va_target/100; % u [m/s]
      0/100;         % w [m/s]
      deg2rad(0)];   % theta [deg]

% Initial control inputs
u0 = [deg2rad(0);  % Elevator deflection [deg]
      0.5;         % DEP activity factor [0-1]
      0.5];        % HTU activity factor [0-1]

z0 = [x0;u0];

%% Optimization

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

% Set options -------------------------------------------------------------

options.Display       = 'off';
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
% options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Run optimization --------------------------------------------------------

[zstar,fval,exitflag,output] = fmincon(@(x) UNIFIER_trimC_obj(x),z0,[],[],[],[],lb,ub,[],options);

%% Process Results

% Extract states & controls -----------------------------------------------

xstar = [0;            % xe
         -ze_target;   % ze
         zstar(1)*100; % u
         zstar(2)*100; % w
         zstar(3);     % theta
         0];           % q
ustar = [zstar(4);     % dElev
         zstar(5);     % DEP_col
         zstar(6);     % HTU
         dFlap];       % dFlap

vastar=sqrt(xstar(3)^2+xstar(4)^2);

% Evaluate accelerations --------------------------------------------------

xdotstar = UNIFIER_ROMdyn_trim(xstar,ustar);

res.xdot = xdotstar;
res.Va   = vastar;
res.fval = fval;

