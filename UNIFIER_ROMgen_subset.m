
% clc
clear all
% close all

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'data\ROMv3\UNIFIER_ROMv3_' + timestamp; % name of diary & data log file

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
dFlap_fixed = deg2rad(5);
dElev_fixed = deg2rad(0);

%% SET SWEEP RANGES

% Angle of attack
alpha_min = -40; % minimum alpha (deg)
alpha_max = 40;  % maximum alpha (deg)
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

romgenset = [timestamp J_fixed dFlap_fixed dElev_fixed alpha_min alpha_max dElev_min dElev_max];

%% EVALUATE FORCES & MOMENTS

for i=1:alpha_n
    for j=1:dElev_n
        CLtemp(i,j) = interpn(ROMv1.dFlap,ROMv1.alpha,ROMv1.J,ROMv1.dElev,... % CL(alpha)
                              ROMv1.CL,...                              
                              dFlap_fixed,alpha(i),J_fixed,dElev_fixed);
        CDtemp(i,j) = interpn(ROMv1.dFlap,ROMv1.alpha,ROMv1.J,ROMv1.dElev,... % CD(alpha)
                              ROMv1.CD,...
                              dFlap_fixed,alpha(i),J_fixed,dElev_fixed); 
        CM(i,j)     = interpn(ROMv1.dFlap,ROMv1.alpha,ROMv1.J,ROMv1.dElev,... % CM(alpha,dElev)
                              ROMv1.CM,... 
                              dFlap_fixed,alpha(i),J_fixed,dElev_range(j)); 
    end
end

CL=CLtemp(:,7);
CD=CDtemp(:,7);

%% COMPILE DATA

ROM.Va      = Va;
ROM.h       = 0;
ROM.CL      = CL;
ROM.CD      = CD;
ROM.CM      = CM;
ROM.dFlap   = dFlap_fixed;
ROM.alpha   = alpha;
ROM.DEP_col = DEP;
ROM.dElev   = dElev_range; 

save(logname,"ROM")

%% TEST INTERPOLATION

alpha_test = deg2rad(0);
dElev_test = deg2rad(0);

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



