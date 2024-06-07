function f0=UNIFIER_trimD_obj(z)

%test
% Va_target = 55; % airspeed target [m/s] cruise=72.74m/s
% ze_target = 5;  % altitude [m] cruise=1219m
% dFlap     = deg2rad(12); % flap deflection [deg]
% x = [Va_target/100; % u [m/s]
%       0/100;         % w [m/s]
%       deg2rad(0)];   % theta [deg]
% u = [deg2rad(0);  % Elevator deflection [deg]
%       0.5;         % DEP activity factor [0-1]
%       0.5];        % HTU activity factor [0-1]
% z = [x0;u0];

global target
Va_target    = target.Va;
ze_target    = target.ze;
dFlap        = target.dFlap;

x=[0;          % xe
   -ze_target; % ze
   z(1)*100;   % u
   z(2)*100;   % w
   z(3);       % theta
   0];         % q
u=[z(4);       % dElev
   0;          % DEP_col
   z(5);       % HTU
   dFlap];     % dFlap

xdot=UNIFIER_ROMdyn_trim(x,u);
xdot(1)=[];

Va    = sqrt(x(3)^2+x(4)^2);

Q = [xdot';
    Va-Va_target];

global penalty
zedot_penalty = penalty.zedot;
udot_penalty  = penalty.udot;
wdot_penalty  = penalty.wdot;
qdot_penalty  = penalty.qdot;
Va_penalty    = penalty.Va;

H = diag(ones(1,numel(Q))); % penalty weight matrix
H(1,1) = zedot_penalty; % penalty weight for zedot (rate of descent)
H(2,2) = udot_penalty;  % udot (horizontal acceleration)
H(3,3) = wdot_penalty;  % wdot (vertical acceleration)
H(5,5) = qdot_penalty;  % qdot (pitch acceleration)
H(6,6) = Va_penalty;    % Va (airspeed)

f0 = Q'*H*Q;