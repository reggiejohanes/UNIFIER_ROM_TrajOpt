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
global runconfig

% initial conditions
x0     = runconfig.x0;
z0     = runconfig.z0;
u0     = runconfig.u0;
w0     = runconfig.w0;
theta0 = runconfig.theta0;
q0     = runconfig.q0;
dElev0 = runconfig.dElev0;
DEP0   = runconfig.DEP0;
HTU0   = runconfig.HTU0;
% dFlap0 = runconfig.dFlap0;

% variable bounds

xmin     = runconfig.xmin;
zmin     = runconfig.zmin;
umin     = runconfig.umin;
wmin     = runconfig.wmin;
thetamin = runconfig.thetamin;
qmin     = runconfig.qmin;
dElevmin = runconfig.dElevmin;
DEPmin   = runconfig.DEPmin;
HTUmin   = runconfig.HTUmin;
% dFlapmin = runconfig.dFlapmin; 

xmax     = runconfig.xmax;
zmax     = runconfig.zmax;
umax     = runconfig.umax;
wmax     = runconfig.wmax;
thetamax = runconfig.thetamax;
qmax     = runconfig.qmax;
dElevmax = runconfig.dElevmax;
DEPmax   = runconfig.DEPmax;
HTUmax   = runconfig.HTUmax;
% dFlapmax = runconfig.dFlapmax; 

% terminal conditions
zf      = runconfig.zf;
xf      = runconfig.xf;
uf      = runconfig.uf;
wf      = runconfig.wf;
thetaf  = runconfig.thetaf;
qf      = runconfig.qf;

xfu     = runconfig.xfu;
zfu     = runconfig.zfu;
ufu     = runconfig.ufu;
wfu     = runconfig.wfu;
thetafu = runconfig.thetafu;
qfu     = runconfig.qfu;

xfl     = runconfig.xfl;
zfl     = runconfig.zfl;
ufl     = runconfig.ufl;
wfl     = runconfig.wfl;
thetafl = runconfig.thetafl;
qfl     = runconfig.qfl;

dElev_f = runconfig.dElev_f;
DEP_f   = runconfig.DEP_f;
HTU_f   = runconfig.HTU_f;

%%

%Initial Time. t0<tf
problem.time.t0_min = 0;
problem.time.t0_max = 0;
guess.t0            = 0;


% Final time. Let tf_min=tf_max if tf is fixed.
guess.tf            = xf/(uf+(u0-uf)/2);
problem.time.tf_min = 1; %guess.tf/2     
problem.time.tf_max = inf; %guess.tf*2

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

ebmult = runconfig.ebmult; % error bound multiplier

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
DUmax = runconfig.dumax;
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
guess.inputs(:,1) = [dElev0 dElev_f];
guess.inputs(:,2) = [DEP0   DEP_f];
guess.inputs(:,3) = [HTU0   HTU_f];
% guess.inputs(:,4) = [dFlap0 dFlap0];

% Choose the set-points if required
problem.setpoints.states = [];
problem.setpoints.inputs = [];

% Bounds for path constraint function gl =< g(x,u,p,t) =< gu

problem.constraints.ng_eq   = 0;
problem.constraints.gTol_eq = [];

problem.constraints.gl = [runconfig.ineq_rodmin,... % min rate of descent convvel(0,'ft/min','m/s')
                          runconfig.ineq_aoamin,... % min alpha deg2rad(-15)
                          runconfig.ineq_Vamin];   % min airspeed 35.85*1.3
problem.constraints.gu = [runconfig.ineq_rodmax,... % max rate of descent convvel(350,'ft/min','m/s')
                          runconfig.ineq_aoamax,... % max alpha deg2rad(10)
                          runconfig.ineq_Vamax];    % max airspeed
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
problem.constraints.bl   = [runconfig.bndc_Vamin,... % min final airspeed (m/s) 35.85*1.1
                            runconfig.bndc_rodmin];  % vertical speed (m/s) convvel(200,'ft/min','m/s')

problem.constraints.bu   = [runconfig.bndc_Vamax,... % max final airspeed 35.85*1.3
                            runconfig.bndc_rodmax];  % max veritcal speed (m/s) convvel(350,'ft/min','m/s')

problem.constraints.bTol = [0.001,...
                            convvel(5,'ft/min','m/s')];

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

global runconfig

if runconfig.stagecost==1
    k   = 0.1;
    z   = x(:,2); 
    z0  = x(1,2);
    p  = exp(((z-z0)/z0).^2);
    Va  = sqrt(x(:,3).^2+x(:,4).^2);
    Va0 = sqrt(x(1,3).^2+x(1,4).^2);
    stageCost = k .* p .* Va/Va0;
else
    stageCost = 0*t;
end

% stageCost = k.*sqrt(Va.^2.*(h-h0).^2);
% stageCost = k.*Va.*(h-h0).^2;


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

global runconfig

if runconfig.boundarycost==1
    boundaryCost = tf;
elseif runconfig.boundarycost==2
    boundaryCost = xf(1);
else
    boundaryCost = tf;
end

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

Va_f    = sqrt(xf(3)^2+xf(4)^2);  % airspeed
alpha_f = atan2(xf(4),xf(3));     % angle of attack
gamma_f = xf(5)-alpha_f;          % glide slope
dz_f    = Va_f*sin(gamma_f);      % vertical speed (flat earth frame)

bc=[Va_f;...
    dz_f];
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

