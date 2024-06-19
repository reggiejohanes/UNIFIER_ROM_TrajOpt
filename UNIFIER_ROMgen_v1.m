
% clc
clear all
% close all

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");

%% GET AIRCRAFT DATA

load data/UNIFIER_LOAD.mat c S umax umin

%% SET FLIGHT CONDITIONS

Va = 50; % airspeed [m/s] cruise=72.74
h  = 1219;  % altitude [m]

[~,~,~,rho,nu] = atmosisa(h);
Re             = Va*c/nu;
qS             = 0.5*rho*Va^2*S;

%% SET SWEEP RANGES

% Angle of attack
alpha_min = -40; % minimum alpha (deg)
alpha_max = 40;  % maximum alpha (deg)
alpha_inc = 1;   % alpha increment
alpha_n   = (alpha_max-alpha_min)/alpha_inc+1;
alpha_deg = linspace(alpha_min,alpha_max,alpha_n)';
alpha     = deg2rad(alpha_deg);

% Elevator deflection
dElev_min = rad2deg(umin(3));
dElev_max = rad2deg(umax(3));
dElev_inc = 5;
dElev_n   = (dElev_max-dElev_min)/dElev_inc+1;
dElev_deg = linspace(dElev_min,dElev_max,dElev_n)';
dElev     = deg2rad(dElev_deg);

% Flap deflection
dFlap_min = rad2deg(umin(4));
dFlap_max = rad2deg(umax(4));
dFlap_inc = 5;
dFlap_n   = (dFlap_max-dFlap_min)/dFlap_inc+1;
dFlap_deg = linspace(dFlap_min,dFlap_max,dFlap_n)';
dFlap     = deg2rad(dFlap_deg);

% DEP thrust setting
DEP_min = umin(5);
DEP_max = umax(5);
DEP_inc = 0.1;
DEP_n   = (DEP_max-DEP_min)/DEP_inc+1;
DEP_col = linspace(DEP_max,DEP_min,DEP_n)';

evals   = dFlap_n*alpha_n*DEP_n*dElev_n;

%% EVALUATE FORCES & MOMENTS

fprintf('\n');
fprintf('<strong><< LOOP START >></strong>');
fprintf('\n');
fprintf('\n');

startloop=tic;
set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
UNIFIER_dyn([],[],[],'compile')
count=0;

for i=1:dFlap_n
    % Va(i) = Re(i)*nu/c;
    % qS(i) = 0.5*rho*Va(i)^2*S;
    for j=1:alpha_n

        startstep=tic;
        count=count+1;

        for k=1:DEP_n
            for m=1:dElev_n
                
                % Setup state & control vectors
                x = [0;                   % 1) xe [m]
                     0;                   % 2) ye [m]
                     -h;                  % 3) (-)ze [m]
                     Va*cos(alpha(j));    % 4) u [m/s]
                     0;                   % 5) v [m/s]
                     Va*sin(alpha(j));    % 6) w [m/s]
                     deg2rad(0);          % 7) phi [rad]
                     alpha(j);            % 8) theta [rad]
                     deg2rad(0);          % 9) psi [rad/s]
                     deg2rad(0);          % 10) p [rad/s]
                     deg2rad(0);          % 11) q [rad/s]
                     deg2rad(0)];         % 12) r [rad/s]
                u = [deg2rad(0);          % 13) dAil [rad] 1
                     deg2rad(0);          % 14) dRud [rad] 2
                     dElev(m);            % 15) dElev [rad] 3
                     dFlap(i);            % 16) dFlap [rad] 4
                     DEP_col(k);          % 17) DEP_col [0-1] 5
                     0.0;                 % 18) DEP_slope [0-1] 6
                     0.0];                % 19) HTU [0-1] 7
                
                % Call dynamics function
                out = UNIFIER_dyn(0,[],[x;u],'outputs');
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
                          0               1  0;
                          -sin(alpha(j))  0  cos(alpha(j))];
                F_ae_w = rot*F_ae_b;

                L   = -F_ae_w(3);
                D   = -F_ae_w(1);
                My  = out(21);
                
                % Calculate coefficients
                CL(i,j,k,m) = L/qS;
                CD(i,j,k,m) = D/qS;
                CM(i,j,k,m) = My/(qS*c);


            
            end
            % Store J, CT
            J(k)      = out(59);
            CT(k)     = out(47);
        end
        t_step=toc(startstep);
        fprintf(num2str(count))
        fprintf('/')
        fprintf(num2str(alpha_n*dFlap_n))
        fprintf(' %6.4f s\n',t_step);
    end
end

UNIFIER_dyn([],[],[],'term')

fprintf('\n');
fprintf('\n');
fprintf('<strong><< LOOP END >></strong>');
fprintf('\n');
fprintf('\n');

t_eval = toc(startloop);
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
ROM.CT      = CT';
ROM.J       = J';
ROM.dElev   = dElev; 

% SAVE ROM
% save data/UNIFIER_ROM_72.mat ROM
% save data/UNIFIER_ROM_50.mat ROM

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
% CL_test    = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,...   % breakpoints
%                      ROM.CL,...                                % table data
%                      dFlap_test,alpha_test,J_test,dElev_test); % inputs
% 
% CD_test    = interpn(ROM.dFlap,ROM.alpha,ROM.J,ROM.dElev,...
%                      ROM.CD,...
%                      dFlap_test,alpha_test,J_test,dElev_test);

%% PLOT RESULTS

close all

plotstyle = [".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k";
             ".-m";".-r";".-g";".-c";".-b";".-k"];

% CL ----------------------------------------------------------------------
fig(1)=figure('Name','Total Lift Coefficient','Position',[150 250 600 500]);
for i=1:dFlap_n
    dflaplegend(i) = strjoin(["\delta_{flap} =",num2str(dFlap_deg(i)),"\circ"]);
    plot(alpha_deg,CL(i,:,1,2),plotstyle(i))
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

% CD ----------------------------------------------------------------------
fig(2)=figure('Name','Total Drag Coefficient','Position',[800 250 600 500]);
for i=1:dFlap_n
    plot(alpha_deg,CD(i,:,1,2),plotstyle(i))
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
fig(3)=figure('Name','Pitching Moment Coefficient','Position',[150 250 600 500]);
for i=1:dFlap_n
    plot(alpha_deg,CM(i,:,1,2),plotstyle(i))
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

% save plots
saveas(fig(1),'figures\ROMgenv1_CL_'+timestamp,'jpg')
saveas(fig(2),'figures\ROMgenv1_CD_'+timestamp,'jpg')
saveas(fig(3),'figures\ROMgenv1_CM_'+timestamp,'jpg')
savefig(fig,'figures\ROMgenv1_'+timestamp + '_figs');





