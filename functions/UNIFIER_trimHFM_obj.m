function f0=UNIFIER_trimHFM_obj(z)

global runconfig

Va_target = runconfig.Va_target;
ze        = runconfig.ze;
dFlap     = runconfig.dFlap;

x=[0;...        % xe
   0;...        % ye
   -ze;         % ze
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
   0;...        % DEP_col
   0;...        % DEP_slope
   z(5)];       % HTU

if runconfig.DEPset==1
    u(5)=z(5);
    u(7)=z(6);
end

out  = UNIFIER_dyn(0,[],[x;u],'outputs');
xdot = out(2:12);

Va    = sqrt(x(4)^2+x(5)^2+x(6)^2);

Q = [xdot;
    Va-Va_target];

H = diag(ones(1,numel(Q))); % penalty weight matrix
H(2,2)   = runconfig.penalty_zedot; % penalty weight for zedot (rate of descent)
H(3,3)   = runconfig.penalty_udot;  % udot (horizontal acceleration)
H(5,5)   = runconfig.penalty_wdot;  % wdot (vertical acceleration)
H(10,10) = runconfig.penalty_qdot;  % qdot (pitch acceleration)
H(12,12) = runconfig.penalty_Va;    % Va (airspeed)

f0 = Q'*H*Q;