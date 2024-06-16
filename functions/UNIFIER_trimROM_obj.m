function f0=UNIFIER_trimROM_obj(z)

%test
% clear
% 
% global runconfig
% 
% runconfig.DEPset  = 0; % 1=DEP on, 0=DEP off
% runconfig.ROMfile = 2; % 1=72.74, 2=50, 3=v2a
% runconfig.ROMdep  = 1; % 1=all dependencies, 2=reduced dependencies
% 
% runconfig.Va_target = 50;       % airspeed target (m/s) cruise=72.74m/s
% runconfig.ze        = 1219;        % altitude (m) cruise=1219m
% runconfig.dFlap     = deg2rad(0); % flap deflection (deg)
% 
% runconfig.penalty_zedot = 1;
% runconfig.penalty_udot  = 1;
% runconfig.penalty_wdot  = 1;
% runconfig.penalty_qdot  = 100;
% runconfig.penalty_Va    = 1;
% 
% % z=[0.501416170030790;
% %     0.0590180161883715;
% %     0.104376088097908;
% %     -0.0872664625204628;
% %     0.543451181763014];
% z=[0.498326034443374;
% 0.0780070528673805;
% 0.140715081996290;
% -0.200966577518637;
% -0.494729321095230];
% global check1
% check1(:,end+1)=z;

global runconfig

Va_target = runconfig.Va_target;
ze        = runconfig.ze;
dFlap     = runconfig.dFlap;

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

if runconfig.DEPset==1
    u(2)=z(5);
    u(3)=z(6);
end

xdot=UNIFIER_ROMdyn(x,u);
xdot(1)=[];

Va    = sqrt(x(3)^2+x(4)^2);

Q = [xdot';
    Va-Va_target];

H = diag(ones(1,numel(Q))); % penalty weight matrix
H(1,1) = runconfig.penalty_zedot; % penalty weight for zedot (rate of descent)
H(2,2) = runconfig.penalty_udot;  % udot (horizontal acceleration)
H(3,3) = runconfig.penalty_wdot;  % wdot (vertical acceleration)
H(5,5) = runconfig.penalty_qdot;  % qdot (pitch acceleration)
H(6,6) = runconfig.penalty_Va;    % Va (airspeed)

f0 = Q'*H*Q;

% global check3
% check3(end+1)=f0;
