
clc
clear
close all

%% GET AIRCRAFT DATA

load UNIFIER_LOAD.mat c S

%% SET FLIGHT CONDITIONS

Va     = 20;   % airspeed [m/s]
h      = 1000; % altitude [m]

[~,~,~,rho,nu] = atmosisa(h);
Re             = Va*c/nu;
qS             = 0.5*rho*Va^2*S;

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

% Thrust setting
DEP_min = 0;
DEP_max = 1;
DEP_inc = 0.1;
DEP_n   = (DEP_max-DEP_min)/DEP_inc+1;
DEP_col = linspace(DEP_min,DEP_max,DEP_n)';

% Reynolds number
% Re_min    = 2.5e6;
% Re_max    = 8.5e6;
% Re_inc    = 1e6;
% Re_n      = (Re_max-Re_min)/Re_inc+1;
% Re        = linspace(Re_min,Re_max,Re_n);

% Initialize vectors 
% L  = zeros(Re_n,alpha_n);
% D  = zeros(Re_n,alpha_n);
% CL = zeros(Re_n,alpha_n);
% CD = zeros(Re_n,alpha_n);

%% EVALUATE FORCES & MOMENTS

fprintf('<strong><< LOOP START >></strong>');
fprintf('\n');
fprintf('\n');
fprintf('<strong>CALCULATING..</strong>');

tic
set_param('UNIFIER_dyn2','SimulationMode','rapid-accelerator')
UNIFIER_dyn2([],[],[],'compile')

for i=1:dFlap_n
    % Va(i) = Re(i)*nu/c;
    % qS(i) = 0.5*rho*Va(i)^2*S;

    for j=1:alpha_n

        for k=1:DEP_n

            % Setup state & control vectors
            x = [0;                   % 1) xe [m]
                 0;                   % 2) ye [m]
                 -h;                  % 3) (-)ze [m]
                 Va*cos(alpha(j)); % 4) u [m/s]
                 0;                   % 5) v [m/s]
                 Va*sin(alpha(j)); % 6) w [m/s]
                 deg2rad(0);          % 7) phi [rad]
                 alpha(j);            % 8) theta [rad]
                 deg2rad(0);          % 9) psi [rad/s]
                 deg2rad(0);          % 10) p [rad/s]
                 deg2rad(0);          % 11) q [rad/s]
                 deg2rad(0)];         % 12) r [rad/s]
            u = [deg2rad(0);          % 13) dAil [rad]
                 deg2rad(0);          % 14) dRud [rad]
                 deg2rad(0);          % 15) dElev [rad]
                 dFlap(i);            % 16) dFlap [rad] 
                 DEP_col(k);          % 17) DEP_col [0-1]
                 0.0;                 % 18) DEP_slope [0-1]
                 0.0];                % 19) HTU [0-1]
            
            % Call dynamics function
            out = UNIFIER_dyn2(0,[],[x;u],'outputs');
            % res.dx     = out(1:12);
            % res.Fb     = out(13:15);
            % res.P      = out(16);
            % res.Fb_ae  = out(17:19);
            % res.Mb_ae  = out(20:22);
            % res.Fb_DEP = out(23:25);
            % res.Mb_DEP = out(26:28);
            % res.Fb_HTU = out(29:31);
            % res.Mb_HTU = out(32:34);
            % res.T_DEP  = out(35:46);
            % res.CT_DEP = out(47:58);
            F_ae_b = out(17:19);
            
            % Convert forces to wind axis
            rot    = [cos(alpha(j))   0  sin(alpha(j));  
                      0             1  0;
                      -sin(alpha(j))  0  cos(alpha(j))];
            F_ae_w = rot*F_ae_b;
            L(i,j,k)   = -F_ae_w(3);
            D(i,j,k)   = -F_ae_w(1);
            
            % Calculate coefficients
            CL(i,j,k) = L(i,j)/qS;
            CD(i,j,k) = D(i,j)/qS;

            % Store J, CT
            J(k)      = out(59);
            CT(k)     = out(47);

            % fprintf('.');
        end
    end
end

UNIFIER_dyn2([],[],[],'term')

fprintf('\n');
fprintf('\n');
fprintf('<strong><< LOOP END >></strong>');
fprintf('\n');
fprintf('\n');

toc

%% COMPILE DATA

ROM.Va      = Va;
ROM.h       = h;
ROM.CL      = CL;
ROM.CD      = CD;
ROM.dFlap   = dFlap;
ROM.alpha   = alpha;
ROM.DEP_col = DEP_col;
ROM.CT      = CT';
ROM.J       = J';

%% TEST INTERPOLATION

dFlap_test = deg2rad(0);
alpha_test = deg2rad(0);
J_test     = 0.8;
CL_test    = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.CL,dFlap_test,alpha_test,J_test)
CD_test    = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.CD,dFlap_test,alpha_test,J_test)

%% PLOT RESULTS


plotstyle = [".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k"];

figure('Name','Total Lift Coefficient','Position',[150 250 600 500])
for i=1:dFlap_n
    dflaplegend(i) = strjoin(["\delta_{flap} =",num2str(dFlap_deg(i)),"\circ"]);
    plot(alpha_deg,CL(i,:,1),plotstyle(i))
    hold on
end
title('Total Lift Coefficient')
yline(0)
xline(0)
grid on
ylabel('C_L  ')
xlabel('\alpha [deg]')
set(get(gca,'ylabel'),'rotation',0)
legend(dflaplegend,'Location','northwest')

figure('Name','Total Drag Coefficient','Position',[800 250 600 500])
for i=1:dFlap_n
    plot(alpha_deg,CD(i,:,1),plotstyle(i))
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





