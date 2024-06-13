
% clc
clear all
% close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'data\ROMv3\UNIFIER_ROMv3_' + timestamp; % name of diary & data log file

%% GET AIRCRAFT DATA

load data/UNIFIER_LOAD.mat c S umax umin

%% SET FLIGHT CONDITIONS

Va    = 72.74; % airspeed [m/s] cruise=72.74
h     = 1219;  % altitude [m]
DEP   = 0;
dFlap = deg2rad(5);
dElev_fixed = deg2rad(0);

[~,~,~,rho,nu] = atmosisa(h);
Re             = Va*c/nu;
qS             = 0.5*rho*Va^2*S;

%% SET SWEEP RANGES

% Angle of attack
alpha_min = -20; % minimum alpha (deg)
alpha_max = 20;  % maximum alpha (deg)
alpha_inc = 1;   % alpha increment
alpha_n   = (alpha_max-alpha_min)/alpha_inc+1;
alpha_deg = linspace(alpha_min,alpha_max,alpha_n)';
alpha     = deg2rad(alpha_deg);

% Elevator deflection
dElev_min   = round(rad2deg(umin(3)));
dElev_max   = round(rad2deg(umax(3)));
dElev_inc   = 5;
dElev_n     = (dElev_max-dElev_min)/dElev_inc+1;
dElev_deg   = linspace(dElev_min,dElev_max,dElev_n)';
dElev_range = deg2rad(dElev_deg);

romgenset = [timestamp Va h DEP rad2deg(dFlap) dElev_fixed alpha_min alpha_max dElev_min dElev_max];

%% EVALUATE FORCES & MOMENTS

fprintf('\n');
fprintf('<strong><< LOOP START >></strong>');
fprintf('\n');
fprintf('\n');
fprintf('<strong>CALCULATING..</strong>');

tic
set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
UNIFIER_dyn([],[],[],'compile')

for i=1:alpha_n
    for j=1:dElev_n
        
        % Setup state & control vectors
        x = [0;                % 1) xe [m]
             0;                % 2) ye [m]
             -h;               % 3) (-)ze [m]
             Va*cos(alpha(i)); % 4) u [m/s]
             0;                % 5) v [m/s]
             Va*sin(alpha(i)); % 6) w [m/s]
             deg2rad(0);       % 7) phi [rad]
             alpha(i);         % 8) theta [rad]
             deg2rad(0);       % 9) psi [rad/s]
             deg2rad(0);       % 10) p [rad/s]
             deg2rad(0);       % 11) q [rad/s]
             deg2rad(0)];      % 12) r [rad/s]
        u = [deg2rad(0);       % 13) dAil [rad]
             deg2rad(0);       % 14) dRud [rad]
             dElev_range(j);   % 15) dElev [rad]
             dFlap;            % 16) dFlap [rad] 
             DEP;              % 17) DEP_col [0-1]
             0.0;              % 18) DEP_slope [0-1]
             0.0];             % 19) HTU [0-1]
        
        % Call dynamics function
        out = UNIFIER_dyn(0,[],[x;u],'outputs');
        F_ae_b = out(17:19);
        
        % Convert forces to wind axis
        rot    = [cos(alpha(j))  0  sin(alpha(j));  
                  0              1  0;
                 -sin(alpha(j))  0  cos(alpha(j))];
        F_ae_w = rot*F_ae_b;

        L   = -F_ae_w(3);
        D   = -F_ae_w(1);
        My  = out(21);
        
        % Calculate coefficients
        CLtemp(i,j) = L/qS;
        CDtemp(i,j) = D/qS;
        CM(i,j)     = My/(qS*c);
    
    end
    fprintf('.')
end

CL=CLtemp(:,7);
CD=CDtemp(:,7);

UNIFIER_dyn([],[],[],'term')

fprintf('\n');
fprintf('\n');
fprintf('<strong><< LOOP END >></strong>');
fprintf('\n');
fprintf('\n');

t_eval = toc;
evals  = alpha_n*dElev_n;
fprintf('Total               = %6.4f seconds\n',t_eval);
fprintf('Avg. per Evaluation = %6.4f seconds\n',t_eval/evals);

%% COMPILE DATA

ROM.Va      = Va;
ROM.h       = h;
ROM.CL      = CL;
ROM.CD      = CD;
ROM.CM      = CM;
ROM.dFlap   = dFlap;
ROM.alpha   = alpha;
ROM.DEP_col = DEP;
ROM.dElev   = dElev_range; 

save(logname,"ROM")

%% TEST INTERPOLATION

alpha_test = deg2rad(0);
dElev_test = deg2rad(20);

CL_test = interp1(ROM.alpha,... % breakpoints
                  ROM.CL,...    % table data
                  alpha_test)  % inputs

CD_test = interp1(ROM.alpha,... % breakpoints
                  ROM.CD,...    % table data
                  alpha_test)  % inputs

CM_test = interpn(ROM.alpha,ROM.dElev,... % breakpoints
                  ROM.CM,...              % table data
                  alpha_test,dElev_test) % inputs

%% PLOT RESULTS

close all

% CL ----------------------------------------------------------------------
figure('Name','Total Lift Coefficient','Position',[150 250 600 500])
plot(alpha_deg,CL,'.-b')
title('Total Lift Coefficient')
yline(0)
xline(0)
grid on
ylabel('C_L  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)

% CD ----------------------------------------------------------------------
figure('Name','Total Drag Coefficient','Position',[800 250 600 500])
plot(alpha_deg,CD,'.-r')
hold on
title('Total Drag Coefficient')
hold on
yline(0)
xline(0)
grid on
ylabel('C_D  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)

% CM ----------------------------------------------------------------------
figure('Name','Pitching Moment Coefficient','Position',[150 250 600 500])
plot(alpha_deg,CM(:,7),'.-k')
hold on
title('Pitching Moment Coefficient')
yline(0)
xline(0)
grid on
ylabel('C_M  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)



