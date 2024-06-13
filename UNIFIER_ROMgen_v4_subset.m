
% clc
clear all
% close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'data\ROMv4\UNIFIER_ROMv4_' + timestamp; % name of diary & data log file

%% GET AIRCRAFT DATA

load data/UNIFIER_LOAD.mat c S umax umin

%% LOAD MASTER ROM DATA

load data/UNIFIER_ROM_50.mat ROM
ROMv1=ROM;
clear ROM

%% SET FIXED INPUTS

Va          = 50;
DEP         = 0.5;
J_fixed     = DEPVa2J(Va,DEP); % J at Vcruise & DEP=0.5

%% SET SWEEP RANGES

% Angle of attack
alpha_min = -40; % minimum alpha (deg)
alpha_max = 40;  % maximum alpha (deg)
alpha_inc = 1;   % alpha increment
alpha_n   = (alpha_max-alpha_min)/alpha_inc+1;
alpha_deg = linspace(alpha_min,alpha_max,alpha_n)';
alpha     = deg2rad(alpha_deg);

% Elevator deflection
dElev_min = round(rad2deg(umin(3)));
dElev_max = round(rad2deg(umax(3)));
dElev_inc = 5;
dElev_n   = (dElev_max-dElev_min)/dElev_inc+1;
dElev_deg = linspace(dElev_min,dElev_max,dElev_n)';
dElev     = deg2rad(dElev_deg);

% Flap deflection
dFlap_min = round(rad2deg(umin(4)));
dFlap_max = round(rad2deg(umax(4)));
dFlap_inc = 5;
dFlap_n   = (dFlap_max-dFlap_min)/dFlap_inc+1;
dFlap_deg = linspace(dFlap_min,dFlap_max,dFlap_n)';
dFlap     = deg2rad(dFlap_deg);

% romgenset = [timestamp J_fixed dFlap_fixed dElev_fixed alpha_min alpha_max dElev_min dElev_max];

%% EVALUATE FORCES & MOMENTS

for i=1:alpha_n
    for j=1:dElev_n
        for k=1:dFlap_n
            CL(i,j,k) = interpn(ROMv1.dFlap,ROMv1.alpha,ROMv1.J,ROMv1.dElev,... % CL(alpha)
                                ROMv1.CL,...                              
                                dFlap(k),alpha(i),J_fixed,dElev(j));
            CD(i,j,k) = interpn(ROMv1.dFlap,ROMv1.alpha,ROMv1.J,ROMv1.dElev,... % CD(alpha)
                                ROMv1.CD,...
                                dFlap(k),alpha(i),J_fixed,dElev(j)); 
            CM(i,j,k) = interpn(ROMv1.dFlap,ROMv1.alpha,ROMv1.J,ROMv1.dElev,... % CM(alpha,dElev)
                                ROMv1.CM,... 
                                dFlap(k),alpha(i),J_fixed,dElev(j)); 
        end
    end
end

%% COMPILE DATA

ROM.Va      = Va;
ROM.h       = 0;
ROM.CL      = CL;
ROM.CD      = CD;
ROM.CM      = CM;
ROM.dFlap   = dFlap;
ROM.alpha   = alpha;
ROM.DEP_col = DEP;
ROM.dElev   = dElev; 

save(logname,"ROM")

%% TEST INTERPOLATION

alpha_test = deg2rad(0);
dElev_test = deg2rad(0);
dFlap_test = deg2rad(5);

CL_test = interpn(ROM.alpha,ROM.dElev,ROM.dFlap,... % breakpoints
                  ROM.CL,...    % table data
                  alpha_test,dElev_test,dFlap_test)  % inputs

CD_test = interpn(ROM.alpha,ROM.dElev,ROM.dFlap,... % breakpoints
                  ROM.CD,...    % table data
                  alpha_test,dElev_test,dFlap_test)  % inputs

CM_test = interpn(ROM.alpha,ROM.dElev,ROM.dFlap,... % breakpoints
                  ROM.CM,...              % table data
                  alpha_test,dElev_test,dFlap_test) % inputs

%% PLOT RESULTS

% close all
% 
% % CL ----------------------------------------------------------------------
% figure('Name','Total Lift Coefficient','Position',[150 250 600 500])
% plot(alpha_deg,CL,'.-b')
% title('Total Lift Coefficient')
% yline(0)
% xline(0)
% grid on
% ylabel('C_L  ')
% xlabel('\alpha [deg]')
% set(get(gca,'ylabel'),'rotation',0)
% 
% % CD ----------------------------------------------------------------------
% figure('Name','Total Drag Coefficient','Position',[800 250 600 500])
% plot(alpha_deg,CD,'.-r')
% hold on
% title('Total Drag Coefficient')
% hold on
% yline(0)
% xline(0)
% grid on
% ylabel('C_D  ')
% xlabel('\alpha [deg]')
% set(get(gca,'ylabel'),'rotation',0)
% 
% % CM ----------------------------------------------------------------------
% figure('Name','Pitching Moment Coefficient','Position',[150 250 600 500])
% plot(alpha_deg,CM(:,7),'.-k')
% hold on
% title('Pitching Moment Coefficient')
% yline(0)
% xline(0)
% grid on
% ylabel('C_M  ')
% xlabel('\alpha [deg]')
% set(get(gca,'ylabel'),'rotation',0)



