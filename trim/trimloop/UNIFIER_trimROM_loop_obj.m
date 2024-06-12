function f0=UNIFIER_trimROM_loop_obj(z)

global trimconfig

Va_target = trimconfig.Va_target;
ze        = trimconfig.ze;
dFlap     = trimconfig.dFlap;

x=[0;        % xe
   -ze;      % ze
   z(1)*100; % u
   z(2)*100; % w
   z(3);     % theta
   0];       % q
u=[z(4);     % dElev
   0;        % DEP_col
   z(5);     % HTU
   dFlap];   % dFlap

if trimconfig.DEPset==1
    u(2)=z(5);
    u(3)=z(6);
end

xdot=UNIFIER_ROMdyn_trim_loop(x,u);
xdot(1)=[];

Va    = sqrt(x(3)^2+x(4)^2);

Q = [xdot';
    Va-Va_target];

H = diag(ones(1,numel(Q))); % penalty weight matrix
H(1,1) = trimconfig.penalty_zedot; % penalty weight for zedot (rate of descent)
H(2,2) = trimconfig.penalty_udot;  % udot (horizontal acceleration)
H(3,3) = trimconfig.penalty_wdot;  % wdot (vertical acceleration)
H(5,5) = trimconfig.penalty_qdot;  % qdot (pitch acceleration)
H(6,6) = trimconfig.penalty_Va;    % Va (airspeed)

f0 = Q'*H*Q;

