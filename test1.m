clc
clear
close all
UNIFIER_LOAD

x = [0;           % 1) xe [m]
     0;           % 2) ye [m]
     -500;        % 3) (-)ze [m]
     45;          % 4) u [m/s]
     0;           % 5) v [m/s]
     0;           % 6) w [m/s]
     deg2rad(0);  % 7) phi [rad]
     deg2rad(5);  % 8) theta [rad]
     deg2rad(0);  % 9) psi [rad/s]
     deg2rad(0);  % 10) p [rad/s]
     deg2rad(0);  % 11) q [rad/s]
     deg2rad(0)]; % 12) r [rad/s]
u = [deg2rad(0);  % 13) dAil [rad]
      deg2rad(0);  % 14) dRud [rad]
      deg2rad(0);  % 15) dElev [rad]
      deg2rad(0);  % 16) dFlap [rad] 
      1.0;         % 17) DEP_col [0-1]
      0.0;         % 18) DEP_slope [0-1]
      0.0];        % 19) HTU [0-1]

set_param('UNIFIER_dyn2','SimulationMode','rapid-accelerator')
UNIFIER_dyn2([],[],[],'compile')
tic
out = UNIFIER_dyn2(0,[],[x;u],'outputs');
res.dx     = out(1:12);
res.Fb     = out(13:15);
res.P      = out(16);
res.Fb_ae  = out(17:19);
res.Mb_ae  = out(20:22);
res.Fb_DEP = out(23:25);
res.Mb_DEP = out(26:28);
res.Fb_HTU = out(29:31);
res.Mb_HTU = out(32:34);
res.T_DEP  = out(35:46);
res.CT_DEP = out(47:58);
toc
UNIFIER_dyn2([],[],[],'term')
