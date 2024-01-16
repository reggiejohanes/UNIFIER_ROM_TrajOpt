
clc
clear
% close all

%% Get aircraft data

load UNIFIER_LOAD.mat c S

%% Set flight Conditions

Va     = 30;   % airspeed [m/s]
h      = 1000; % altitude [m]

[~,~,~,rho,nu] = atmosisa(h);
Re             = Va*c/nu;
qS             = 0.5*rho*Va^2*S;

%% Set alpha range

alphamin = -20; % minimum alpha
alphamax = 20;  % maximum alpha
alphainc = 2;   % alpha increment
alpha_n  = (alphamax-alphamin)/alphainc+1;
alpha    = linspace(alphamin,alphamax,alpha_n)';

L  = zeros(alpha_n,1);
D  = zeros(alpha_n,1);
CL = zeros(alpha_n,1);
CD = zeros(alpha_n,1);

%% Alpha loop

fprintf('<strong><< LOOP START >></strong>');
fprintf('\n');
fprintf('\n');
fprintf('<strong>CALCULATING..</strong>');

tic
for i=1:alpha_n

    alphai = deg2rad(alpha(i)); % angle of attack [deg]
    
    % Setup state & control vectors
    x = [0;              % 1) xe [m]
         0;              % 2) ye [m]
         -h;             % 3) (-)ze [m]
         Va*cos(alphai); % 4) u [m/s]
         0;              % 5) v [m/s]
         Va*sin(alphai); % 6) w [m/s]
         deg2rad(0);     % 7) phi [rad]
         alphai;         % 8) theta [rad]
         deg2rad(0);     % 9) psi [rad/s]
         deg2rad(0);     % 10) p [rad/s]
         deg2rad(0);     % 11) q [rad/s]
         deg2rad(0)];    % 12) r [rad/s]
    u = [deg2rad(0);     % 13) dAil [rad]
         deg2rad(0);     % 14) dRud [rad]
         deg2rad(0);     % 15) dElev [rad]
         deg2rad(0);    % 16) dFlap [rad] 
         0.0;            % 17) DEP_col [0-1]
         0.0;            % 18) DEP_slope [0-1]
         0.0];           % 19) HTU [0-1]
    
    % Call dynamics function
    res    = UNIFIER_forces(x,u);
    F_ae_b = res.F_ae';
    
    % Convert forces to wind axis
    % rot    = roty(-rad2deg(alpha));
    rot    = [cos(alphai)   0  sin(alphai);  % rotate clockwise by alpha
              0             1  0;
              -sin(alphai)  0  cos(alphai)];
    F_ae_w = rot*F_ae_b;
    L(i)   = -F_ae_w(3);
    D(i)   = -F_ae_w(1);
    
    % Calculate coefficients
    CL(i) = L(i)/qS;
    CD(i) = D(i)/qS;

    fprintf('.');
end

fprintf('\n');
fprintf('\n');
fprintf('<strong><< LOOP END >></strong>');
fprintf('\n');
fprintf('\n');

toc

%% Plot results

figure('Name','Total Lift Coefficient','Position',[150 250 600 500])
plot(alpha,CL,'.-b')
title('Total Lift Coefficient')
hold on
yline(0)
xline(0)
grid on
ylabel('C_L  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)

figure('Name','Total Drag Coefficient','Position',[800 250 600 500])
plot(alpha,CD,'.-r')
title('Total Drag Coefficient')
hold on
yline(0)
xline(0)
grid on
ylabel('C_D  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)





