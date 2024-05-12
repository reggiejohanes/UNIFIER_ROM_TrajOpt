function [problem,guess] = UNIFIERLanding

%------------- BEGIN CODE --------------
% Plant model name, used for Adigator
InternalDynamics = @UNIFIERLanding_Dynamics_Internal;
SimDynamics      = @UNIFIERLanding_Dynamics_Sim;

% Analytic derivative files (optional)
problem.analyticDeriv.gradCost          = [];
problem.analyticDeriv.hessianLagrangian = [];
problem.analyticDeriv.jacConst          = [];

% Settings file
problem.settings = @UNIFIERLanding_Settings;

%%

% Load data
load trim/UNIFIER_trim_res.mat xstar ustar
load data/UNIFIER_LOAD_ROM.mat umax umin dumax
Umax  = umax;
Umin  = umin;
DUmax = dumax;

% initial conditions
x0     = xstar(1);
z0     = xstar(3);
u0     = xstar(4);
w0     = xstar(6);
theta0 = xstar(8);
q0     = xstar(11);
dElev0 = ustar(3);
DEP0   = ustar(5);
HTU0   = ustar(7);
% dFlap0 = deg2rad(5);
% dFlap0 = ustar(4);

% variable bounds
xmin     = -inf;
zmin     = -inf;
umin     = 0;
wmin     = -inf;
thetamin = deg2rad(-5);
qmin     = deg2rad(-2);
dElevmin = Umin(3);
DEPmin   = Umin(5);
HTUmin   = Umin(7);
% dFlapmin = deg2rad(4.999); 
% dFlapmin = Umin(4); 

xmax     = inf;
zmax     = 0;
umax     = inf;
wmax     = inf;
thetamax = deg2rad(5);
qmax     = deg2rad(2);
dElevmax = Umax(3);
DEPmax   = Umax(5);
HTUmax   = Umax(7);
% dFlapmax = deg2rad(5.001); 
% dFlapmax = Umax(4); 

% terminal conditions
zf      = -5;
xf      = -1*(z0-zf)/tand(3); % 3deg glide slope
uf      = 40;
wf      = 0;
thetaf  = deg2rad(1);
qf      = deg2rad(0);

xfu     = inf; %xf*1.2;
zfu     = zf;
ufu     = inf; %uf*1.2;
wfu     = inf; %wf+3;
thetafu = inf; %thetaf+deg2rad(3);
qfu     = inf; %qf+deg2rad(1);

xfl     = -inf; %xf*0.8; -inf
zfl     = zf;
ufl     = -inf; %uf*0.8;
wfl     = -inf; %wf-3;
thetafl = -inf; %thetaf-deg2rad(3);
qfl     = -inf; %qf-deg2rad(1);

%%

%Initial Time. t0<tf
problem.time.t0_min = 0;
problem.time.t0_max = 0;
guess.t0            = 0;


% Final time. Let tf_min=tf_max if tf is fixed.
guess.tf            = xf/(uf+(u0-uf)/2);
problem.time.tf_min = guess.tf/2;     
problem.time.tf_max = guess.tf*2; 

% Parameters bounds. pl=< p <=pu
problem.parameters.pl = [];
problem.parameters.pu = [];
guess.parameters      = [];

% Initial conditions for system.
problem.states.x0 = [x0 z0 u0 w0 theta0 q0];

% Initial conditions for system. Bounds if x0 is free s.t. x0l=< x0 <=x0u
problem.states.x0l = [x0 z0 u0 w0 theta0 q0];
problem.states.x0u = [x0 z0 u0 w0 theta0 q0];

% State bounds. xl=< x <=xu
problem.states.xl = [xmin zmin umin wmin thetamin qmin]; 
problem.states.xu = [xmax zmax umax wmax thetamax qmax]; 

% State rate bounds. xrl=< x <=xru
problem.states.xrl = [-inf -inf -inf -inf -inf -inf]; 
problem.states.xru = [ inf  inf  inf  inf  inf  inf]; 

ebmult = 1e3; % error bound multiplier

% State error bounds
problem.states.xErrorTol_local    = [1 1 0.5 0.5 deg2rad(1) deg2rad(0.5)]*ebmult;
problem.states.xErrorTol_integral = [1 1 0.5 0.5 deg2rad(1) deg2rad(0.5)]*ebmult;

% State constraint error bounds
problem.states.xConstraintTol  = [1 1 0.5 0.5 deg2rad(1) deg2rad(0.5)]*ebmult;
problem.states.xrConstraintTol = [1 1 0.5 0.5 deg2rad(1) deg2rad(0.5)]*ebmult;

% Terminal state bounds. xfl=< xf <=xfu
problem.states.xfl = [xfl zfl ufl wfl thetafl qfl]; 
problem.states.xfu = [xfu zfu ufu wfu thetafu qfu]; 

% problem.states.xfl = [xf zf uf wf thetaf qf]; 
% problem.states.xfu = [xf zf uf wf thetaf qf]; 

% Guess the state trajectories with [x0 xf]
guess.states(:,1) = [x0 xf];
guess.states(:,2) = [z0 zf];
guess.states(:,3) = [u0 uf];
guess.states(:,4) = [w0 wf];
guess.states(:,5) = [theta0 thetaf];
guess.states(:,6) = [q0 qf];

% Number of control actions N 
% Set problem.inputs.N=0 if N is equal to the number of integration steps.  
% Note that the number of integration steps defined in settings.m has to be divisible 
% by the  number of control actions N whenever it is not zero.
problem.inputs.N = 0;       
      
% Input bounds
% problem.inputs.ul = [dElevmin DEPmin HTUmin dFlapmin];
% problem.inputs.uu = [dElevmax DEPmax HTUmax dFlapmax];
problem.inputs.ul = [dElevmin DEPmin HTUmin];
problem.inputs.uu = [dElevmax DEPmax HTUmax];

% Initial input bounds
% problem.inputs.u0l = [dElev0 DEP0 HTU0 dFlap0];
% problem.inputs.u0u = [dElev0 DEP0 HTU0 dFlap0];
problem.inputs.u0l = [dElev0 DEP0 HTU0];
problem.inputs.u0u = [dElev0 DEP0 HTU0];

% Input rate bounds
% problem.inputs.url = [-DUmax(3) -DUmax(5) -DUmax(7) -DUmax(4)];
% problem.inputs.uru = [ DUmax(3)  DUmax(5)  DUmax(7)  DUmax(4)];
problem.inputs.url = [-DUmax(3) -DUmax(5) -DUmax(7)];
problem.inputs.uru = [ DUmax(3)  DUmax(5)  DUmax(7)];

% Input constraint error bounds
% problem.inputs.uConstraintTol  = [deg2rad(0.5) 0.1 0.1 deg2rad(0.5)]/1000;
% problem.inputs.urConstraintTol = [deg2rad(0.5) 0.1 0.1 deg2rad(0.5)]/1000;
problem.inputs.uConstraintTol  = [deg2rad(0.5) 0.1 0.1]*ebmult;
problem.inputs.urConstraintTol = [deg2rad(0.5) 0.1 0.1]*ebmult;

% Guess the input sequences with [u0 uf]
guess.inputs(:,1) = [dElev0 dElev0];
guess.inputs(:,2) = [DEP0   DEP0];
guess.inputs(:,3) = [HTU0   HTU0];
% guess.inputs(:,4) = [dFlap0 dFlap0];

% Choose the set-points if required
problem.setpoints.states = [];
problem.setpoints.inputs = [];

% Bounds for path constraint function gl =< g(x,u,p,t) =< gu

problem.constraints.ng_eq   = 0;
problem.constraints.gTol_eq = [];

problem.constraints.gl       = [-inf,...   % min rate of descent convvel(0,'ft/min','m/s')
                                deg2rad(-15),... % min alpha deg2rad(-15)
                                35.85*1.3];      % min airspeed 35.85*1.3

problem.constraints.gu       = [inf,... % max rate of descent convvel(350,'ft/min','m/s')
                                deg2rad(10),...                 % max alpha deg2rad(10)
                                inf];                           % max airspeed

problem.constraints.gTol_neq = [convvel(5,'ft/min','m/s'),...
                                deg2rad(0.1),...
                                0.001];

% problem.constraints.gl       = [deg2rad(-15),... % min alpha
%                                 35.85*1.3];      % min airspeed 35.85*1.3
% 
% problem.constraints.gu       = [deg2rad(10),...                 % max alpha
%                                 inf];                           % max airspeed
% 
% problem.constraints.gTol_neq = [deg2rad(0.1),...
%                                 0.001];

% problem.constraints.gl       = [];
% problem.constraints.gu       = [];
% problem.constraints.gTol_neq = [];

% % problem.constraints.g_neq_ActiveTime{1}=[guess.tf/2 guess.tf];
% problem.constraints.g_neq_ActiveTime{1}=[0 guess.tf];
% problem.constraints.g_neq_ActiveTime{2}=[];
% problem.constraints.g_neq_ActiveTime{3}=[];
% problem.constraints.g_neq_ActiveTime{4}=[0 guess.tf];
% % problem.constraints.g_neq_ActiveTime{4}=[0 guess.tf/2];
% problem.constraints.g_neq_ActiveTime{5}=[];

% Bounds for boundary constraints bl =< b(x0,xf,u0,uf,p,t0,tf) =< bu
problem.constraints.bl   = [];
problem.constraints.bu   = [];
problem.constraints.bTol = [];

% store the necessary problem parameters used in the functions
% problem.data = [];

% Get function handles and return to Main.m
problem.data.InternalDynamics   = InternalDynamics;
problem.data.functionfg         = @fg;
problem.data.plantmodel         = func2str(InternalDynamics);
problem.functions               = {@L,@E,@f,@g,@avrc,@b};
problem.sim.functions           = SimDynamics;
problem.sim.inputX              = [];
problem.sim.inputU              = 1:length(problem.inputs.ul);
problem.functions_unscaled      = {@L_unscaled,@E_unscaled,@f_unscaled,@g_unscaled,@avrc,@b_unscaled};
problem.data.functions_unscaled = problem.functions_unscaled;
problem.data.ng_eq              = problem.constraints.ng_eq;
problem.constraintErrorTol      = [problem.constraints.gTol_eq,...
                                   problem.constraints.gTol_neq,...
                                   problem.constraints.gTol_eq,...
                                   problem.constraints.gTol_neq,...
                                   problem.states.xConstraintTol,...
                                   problem.states.xConstraintTol,...
                                   problem.inputs.uConstraintTol,...
                                   problem.inputs.uConstraintTol];

%------------- END OF CODE --------------

function stageCost = L_unscaled(x,xr,u,ur,p,t,vdat)

% L_unscaled - Returns the stage cost.
% The function must be vectorized and
% xi, ui are column vectors taken as x(:,i) and u(:,i) (i denotes the i-th
% variable)
% 
% Syntax:  stageCost = L(x,xr,u,ur,p,t,data)
%
% Inputs:
%    x  - state vector
%    xr - state reference
%    u  - input
%    ur - input reference
%    p  - parameter
%    t  - time
%    data- structured variable containing the values of additional data used inside
%          the function
%
% Output:
%    stageCost - Scalar or vectorized stage cost
%
%  Remark: If the stagecost does not depend on variables it is necessary to multiply
%          the assigned value by t in order to have right vector dimesion when called for the optimization. 
%          Example: stageCost = 0*t;

%------------- BEGIN CODE --------------

k   = 0.1;

z   = x(:,2); 
z0  = x(1,2);
p  = exp(((z-z0)/z0).^2);

Va  = sqrt(x(:,3).^2+x(:,4).^2);
Va0 = sqrt(x(1,3).^2+x(1,4).^2);

stageCost = k .* p .* Va/Va0;

% stageCost = k.*sqrt(Va.^2.*(h-h0).^2);
% stageCost = k.*Va.*(h-h0).^2;
% stageCost = 0*t;

%------------- END OF CODE --------------


function boundaryCost=E_unscaled(x0,xf,u0,uf,p,t0,tf,data) 

% E_unscaled - Returns the boundary value cost
%
% Syntax:  boundaryCost=E_unscaled(x0,xf,u0,uf,p,t0,tf,data) 
%
% Inputs:
%    x0  - state at t=0
%    xf  - state at t=tf
%    u0  - input at t=0
%    uf  - input at t=tf
%    p   - parameter
%    tf  - final time
%    data- structured variable containing the values of additional data used inside
%          the function
%
% Output:
%    boundaryCost - Scalar boundary cost
%
%------------- BEGIN CODE --------------

% Va  = sqrt(xf(:,3).^2+xf(:,4).^2);
% Va0 = sqrt(xf(1,3).^2+xf(1,4).^2);

boundaryCost= tf;

%------------- END OF CODE --------------

function bc=b_unscaled(x0,xf,u0,uf,p,t0,tf,vdat,varargin)

% b_unscaled - Returns a column vector containing the evaluation of the boundary constraints: bl =< bf(x0,xf,u0,uf,p,t0,tf) =< bu
%
% Syntax:  bc=b_unscaled(x0,xf,u0,uf,p,t0,tf,vdat,varargin)
%
% Inputs:
%    x0  - state at t=0
%    xf  - state at t=tf
%    u0  - input at t=0
%    uf  - input at t=tf
%    p   - parameter
%    tf  - final time
%    data- structured variable containing the values of additional data used inside
%          the function
%
%          
% Output:
%    bc - column vector containing the evaluation of the boundary function 
%
%------------- BEGIN CODE --------------
varargin=varargin{1};

bc=[];
%------------- END OF CODE --------------
% When adpative time interval add constraint on time
%------------- BEGIN CODE --------------
if length(varargin)==2
    options=varargin{1};
    t_segment=varargin{2};
    if ((strcmp(options.discretization,'hpLGR')) || (strcmp(options.discretization,'globalLGR')))  && options.adaptseg==1 
        if size(t_segment,1)>size(t_segment,2)
            bc=[bc;diff(t_segment)];
        else
            bc=[bc,diff(t_segment)'];
        end
    end
end

%------------- END OF CODE --------------

