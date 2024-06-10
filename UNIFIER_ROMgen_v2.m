
% clc
clear
% close all

%% GET AIRCRAFT DATA

load data/UNIFIER_LOAD.mat c S

%% SET FLIGHT CONDITIONS

h      = 1219;  % altitude [m]
[~,~,~,rho,nu] = atmosisa(h);

% Va     = 50; % airspeed [m/s] cruise=72.74
% Re             = Va*c/nu;
% qS             = 0.5*rho*Va^2*S;

%% SET SWEEP RANGES

% Angle of attack
alpha_min = -20; % minimum alpha
alpha_max = 20;  % maximum alpha
alpha_inc = 1;   % alpha increment
alpha_n   = (alpha_max-alpha_min)/alpha_inc+1;
alpha_deg = linspace(alpha_min,alpha_max,alpha_n)';
alpha     = deg2rad(alpha_deg);

% Flap deflection
dFlap_min = 0;
dFlap_max = 25;
dFlap_inc = 5;
dFlap_n   = (dFlap_max-dFlap_min)/dFlap_inc+1;
dFlap_deg = linspace(dFlap_min,dFlap_max,dFlap_n)';
dFlap     = deg2rad(dFlap_deg);

% DEP thrust setting
DEP_min = 0;
DEP_max = 1;
DEP_inc = 0.1;
DEP_n   = (DEP_max-DEP_min)/DEP_inc+1;
DEP_col = linspace(DEP_min,DEP_max,DEP_n)';

% Elevator deflection
dElev_min = -5;
dElev_max = 20;
dElev_inc = 5;
dElev_n   = (dElev_max-dElev_min)/dElev_inc+1;
dElev_deg = linspace(dElev_min,dElev_max,dElev_n)';
dElev     = deg2rad(dElev_deg);

% Airspeed
Va_min = 20;
Va_max = 90;
Va_inc = 5;
Va_n   = (Va_max-Va_min)/Va_inc+1;
Va     = linspace(Va_min,Va_max,Va_n)';

% Initialize vectors 
% L  = zeros(Re_n,alpha_n);
% D  = zeros(Re_n,alpha_n);
% CL = zeros(Re_n,alpha_n);
% CD = zeros(Re_n,alpha_n);

%% EVALUATE FORCES & MOMENTS

fprintf('\n');
fprintf('<strong><< LOOP START >></strong>');
fprintf('\n');
fprintf('\n');
fprintf('<strong>CALCULATING..</strong>');

tic
set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
UNIFIER_dyn([],[],[],'compile')

for i=1:dFlap_n
    for j=1:dElev_n
        for k=1:DEP_n
            for l=1:Va_n
                qS = 0.5*rho*Va(l)^2*S;
                for m=1:alpha_n

                    % Setup state & control vectors
                    x = [0;                   % 1) xe [m]
                         0;                   % 2) ye [m]
                         -h;                  % 3) (-)ze [m]
                         Va(l)*cos(alpha(m)); % 4) u [m/s]
                         0;                   % 5) v [m/s]
                         Va(l)*sin(alpha(m)); % 6) w [m/s]
                         deg2rad(0);          % 7) phi [rad]
                         alpha(m);            % 8) theta [rad]
                         deg2rad(0);          % 9) psi [rad/s]
                         deg2rad(0);          % 10) p [rad/s]
                         deg2rad(0);          % 11) q [rad/s]
                         deg2rad(0)];         % 12) r [rad/s]
                    u = [deg2rad(0);          % 13) dAil [rad]
                         deg2rad(0);          % 14) dRud [rad]
                         dElev(j);            % 15) dElev [rad]
                         dFlap(i);            % 16) dFlap [rad] 
                         DEP_col(k);          % 17) DEP_col [0-1]
                         0.0;                 % 18) DEP_slope [0-1]
                         0.0];                % 19) HTU [0-1]
                    
                    % Call dynamics function
                    out = UNIFIER_dyn(0,[],[x;u],'outputs');
                    F_ae_b = out(17:19);
                    
                    % Convert forces to wind axis
                    rot    = [cos(alpha(m))   0  sin(alpha(m));  
                              0               1  0;
                              -sin(alpha(m))  0  cos(alpha(m))];
                    F_ae_w = rot*F_ae_b;
                    L(i,j,k,l,m)   = -F_ae_w(3);
                    D(i,j,k,l,m)   = -F_ae_w(1);
                   
                    My(i,j,k,l,m)  = out(21);
                    
                    % Calculate coefficients
                    CL(i,j,k,l,m) = L(i,j,k,l,m)/qS;
                    CD(i,j,k,l,m) = D(i,j,k,l,m)/qS;
                    CM(i,j,k,l,m) = My(i,j,k,l,m)/(qS*c);
                end
            end
        end
    end
    fprintf('.')
end

UNIFIER_dyn([],[],[],'term')

fprintf('\n');
fprintf('\n');
fprintf('<strong><< LOOP END >></strong>');
fprintf('\n');
fprintf('\n');

t_eval = toc;
evals  = dFlap_n*alpha_n*DEP_n*dElev_n*Va_n;
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
ROM.DEP_col = DEP_col;
ROM.dElev   = dElev; 

save data/UNIFIER_ROM_v2a.mat ROM

%% TEST INTERPOLATION

% dFlap_test = deg2rad(0);
% alpha_test = deg2rad(0);
% J_test     = 1.7;
% dElev_test = deg2rad(20);
% dFlap_test = 0;
% alpha_test = 0.0157;
% J_test     = 1.98;
% dElev_test = -0.0153;
% 
% dFlap_test = deg2rad(0);
% dElev_test = deg2rad(20);
% DEP_test   = 0.5;
% Va_test    = 20;
% alpha_test = deg2rad(0);
% 
% CL_test    = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,... % breakpoints
%                      ROM.CL,...                                           % table data
%                      dFlap_test,dElev_test,DEP_test,Va_test,alpha_test);  % inputs
% 
% CD_test    = interpn(ROM.dFlap,ROM.dElev,ROM.DEP_col,ROM.Va,ROM.alpha,...
%                      ROM.CD,...
%                      dFlap_test,dElev_test,DEP_test,Va_test,alpha_test);

%% PLOT RESULTS

close all

plotstyle = [".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k"];

% CL ----------------------------------------------------------------------
figure('Name','Total Lift Coefficient','Position',[150 250 600 500])
for i=1:dFlap_n
    dflaplegend(i) = strjoin(["\delta_{flap} =",num2str(dFlap_deg(i)),"\circ"]);
    for j=1:alpha_n
        CL_vect(j)=CL(i,2,6,11,j);
    end
    plot(alpha_deg,CL_vect,plotstyle(i))
    hold on
end
title('Total Lift Coefficient')
yline(0)
xline(0)
grid on
ylabel('C_L  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)
legend(dflaplegend,'Location','southeast')

% CD ----------------------------------------------------------------------
figure('Name','Total Drag Coefficient','Position',[800 250 600 500])
for i=1:dFlap_n
    for j=1:alpha_n
        CD_vect(j)=CD(i,2,6,11,j);
    end
    plot(alpha_deg,CD_vect,plotstyle(i))
    hold on
end
title('Total Drag Coefficient')
hold on
yline(0)
xline(0)
grid on
ylabel('C_D  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)
legend(dflaplegend,'Location','northwest')

% CM ----------------------------------------------------------------------
figure('Name','Pitching Moment Coefficient','Position',[150 250 600 500])
for i=1:dFlap_n
    for j=1:alpha_n
        CM_vect(j)=CM(i,2,6,11,j);
    end
    plot(alpha_deg,CM_vect,plotstyle(i))
    hold on
end
title('Pitching Moment Coefficient')
yline(0)
xline(0)
grid on
ylabel('C_M  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)
legend(dflaplegend,'Location','southwest')





