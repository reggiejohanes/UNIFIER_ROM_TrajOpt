function f0=UNIFIER_trimA_loop_obj(z)

global target
Va_target    = target.Va;
ze_target    = target.ze;
dFlap        = target.dFlap;
% gamma_target = target.gamma;

x=[0;...        % xe
   0;...        % ye
   -ze_target;  % ze
   z(1)*100;... % u
   0;...        % v
   z(2)*100;... % w
   0;...        % phi
   z(3);...     % theta
   0;...        % psi
   0;...        % p
   0;...        % q
   0];...       % r
u=[0;...        % dAil
   0;...        % dRud
   z(4);...     % dElev
   dFlap;...    % dFlap
   z(5);...     % DEP_col
   0;...        % DEP_slope
   z(6)];       % HTU

% xdot = UNIFIER_dynamics(x,u);
% xdot(1) = [];

out  = UNIFIER_dyn(0,[],[x;u],'outputs');
xdot = out(2:12);


Va    = sqrt(x(4)^2+x(5)^2+x(6)^2);
% theta = x(8);
% alpha = atan2(x(6),x(4));
% gam   = theta-alpha;

Q = [xdot;
    Va-Va_target];

global penalty
zedot_penalty = penalty.zedot;
udot_penalty  = penalty.udot;
wdot_penalty  = penalty.wdot;
qdot_penalty  = penalty.qdot;
Va_penalty    = penalty.Va;

H = diag(ones(1,numel(Q))); % penalty weight matrix
H(2,2)   = zedot_penalty; % penalty weight for zedot (rate of descent)
H(3,3)   = udot_penalty;  % udot (horizontal acceleration)
H(5,5)   = wdot_penalty;  % wdot (vertical acceleration)
H(10,10) = qdot_penalty;  % qdot (pitch acceleration)
H(12,12) = Va_penalty;    % Va (airspeed)

f0 = Q'*H*Q;