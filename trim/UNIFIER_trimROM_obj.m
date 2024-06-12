function f0=UNIFIER_trimROM_obj(z)

%test
% clear
% 
% global trimconfig
% 
% trimconfig.DEPset  = 0; % 1=DEP on, 0=DEP off
% trimconfig.ROMfile = 2; % 1=72.74, 2=50, 3=v2a
% trimconfig.ROMdep  = 1; % 1=all dependencies, 2=reduced dependencies
% 
% trimconfig.Va_target = 50;       % airspeed target (m/s) cruise=72.74m/s
% trimconfig.ze        = 1219;        % altitude (m) cruise=1219m
% trimconfig.dFlap     = deg2rad(0); % flap deflection (deg)
% 
% trimconfig.penalty_zedot = 1;
% trimconfig.penalty_udot  = 1;
% trimconfig.penalty_wdot  = 1;
% trimconfig.penalty_qdot  = 100;
% trimconfig.penalty_Va    = 1;
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

xdot=UNIFIER_ROMdyn_trim(x,u);
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

% global check3
% check3(end+1)=f0;
