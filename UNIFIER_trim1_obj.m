function f0=UNIFIER_trim1_obj(z)

global target
Va_target    = target.Va;
ze_target    = target.ze;
% gamma_target = target.gamma;

x=[0;...       % xe
   0;...       % ye
   -ze_target; % ze
   z(1);...    % u
   0;...       % v
   z(2);...    % w
   0;...       % phi
   z(3);...    % theta
   0;...       % psi
   0;...       % p
   0;...       % q
   0];...      % r
u=[0;...       % dAil
   0;...       % dRud
   z(4);...    % dElev
   z(5);...    % dFlap
   z(6);...    % DEP_col
   0;...       % DEP_slope
   0];         % HTU

xdot = UNIFIER_dynamics(x,u);
xdot(1) = [];

theta = x(8);
Va    = sqrt(x(4)^2+x(5)^2+x(6)^2);
alpha = atan2(x(6),x(4));
gam   = theta-alpha;

Q = [xdot;
    Va-Va_target;
    gam];

H = diag(ones(1,numel(Q))); % penalty weight matrix
H(10,10) = 1000; % penalty weight for qdot pitch acceleration

f0 = Q'*H*Q;