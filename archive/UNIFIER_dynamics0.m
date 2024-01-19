function xdot=UNIFIER_dynamics0(x,u)

% Test
% clc
% clear
% close all
% UNIFIER_LOAD
% 
% x = [0;           % 1) xe [m]
%      0;           % 2) ye [m]
%      -500;        % 3) (-)ze [m]
%      45;          % 4) u [m/s]
%      0;           % 5) v [m/s]
%      0;           % 6) w [m/s]
%      deg2rad(0);  % 7) phi [rad]
%      deg2rad(5);  % 8) theta [rad]
%      deg2rad(0);  % 9) psi [rad/s]
%      deg2rad(0);  % 10) p [rad/s]
%      deg2rad(0);  % 11) q [rad/s]
%      deg2rad(0)]; % 12) r [rad/s]
% u = [deg2rad(0);  % 13) dAil [rad]
%      deg2rad(0);  % 14) dRud [rad]
%      deg2rad(0);  % 15) dElev [rad]
%      deg2rad(0);  % 16) dFlap [rad] 
%      1.0;         % 17) DEP_col [0-1]
%      0.0;         % 18) DEP_slope [0-1]
%      0.0];        % 19) HTU [0-1]

x0   = x;
u0   = u;
Vrw0 = x(4:6);
[~,~,~,rho0,~]=atmosisa(-1*x(3));

t_sim  = 0;
% res    = sim("RCAM_sim.slx",'SrcWorkspace','current',...
%                 'SimulationMode','rapid', ...
%                 'RapidAcceleratorUpToDateCheck','off');
res    = sim("UNIFIER_dyn0.slx",'SrcWorkspace','current');
xdot   = res.xdot';

% set_param('UNIFIER_dyn2','SimulationMode','rapid-accelerator')
% UNIFIER_dyn2([],[],[],'compile')
% out = UNIFIER_dyn2(0,[],[x;u],'outputs');
% UNIFIER_dyn2([],[],[],'term')

end