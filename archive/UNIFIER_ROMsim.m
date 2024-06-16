clc
clear
close all

%% Load Data

load rundata_trajopt/UNIFIERLanding_20240322_035130.mat solution
load data/UNIFIER_LOAD_ROM.mat

nsteps   = size(solution.X,1); % number of timesteps
U        = solution.U;
X(1,:)   = solution.X(1,:);

nsteps=7;

%% Set Flap Deflection

dFlap = deg2rad(5);

global controls
controls.dFlap = dFlap;

%% Run Simulation


fprintf('SIMULATION PROGRESS:\n')
fprintf(' ____________________ \n')
fprintf('|START       COMPLETE|\n')
fprintf(' ')

tic
for i=1:nsteps

    % DX(i,:)  = UNIFIER_ROMdyn(X(i,:),U(i,:));
    DX(i,:)  = UNIFIER_HFM3DOF_test(X(i,:),U(i,:));

    if i~=nsteps
        dt(i)    = solution.T(i+1)-solution.T(i);
        X(i+1,:) = X(i,:)+DX(i,:)*dt(i);
    end

    if rem(i,nsteps/20)==0
        fprintf('=')
    end

end
fprintf('\n')
t_sim=toc;

%% Plot Figures

% close all

nplot=7;

% calculate airspeed & angle of attack
Va_sim    = sqrt(X(:,3).^2+X(:,4).^2);
alpha_sim = atan2(X(:,4),X(:,3));

Va_sol    = sqrt(solution.X(:,3).^2+solution.X(:,4).^2);
alpha_sol = atan2(solution.X(:,4),solution.X(:,3));

% control histories ---------------------------------------------------------

fig(1)=figure('Name','Control Histories','Position', [900 75 600 650]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile
plot(solution.T(1:nplot),U(1:nplot,2),'.-k')
title('DEP Thrust Level')
xlabel('Time, s')
ylabel('DEP_c_o_l, 0-1')
grid on

nexttile
plot(solution.T(1:nplot),U(1:nplot,3),'.-k')
title('HTU Thrust Level')
xlabel('Time, s')
ylabel('HTU, 0-1')
grid on

nexttile
plot(solution.T(1:nplot),rad2deg(U(1:nplot,1)),'.-k')
title('Elevator Deflection')
xlabel('Time, s')
ylabel('\delta_E_l_e_v, deg')
yline(0,':b','LineWidth',1)
grid on

nexttile
plot(solution.T(1:nplot),linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solution.T(1:nplot))),'.-k')
% plot(solution.T,rad2deg(U(:,4)),'.-k')
title('Flap Deflection')
xlabel('Time, s')
ylabel('\delta_F_l_a_p, deg')
ylim([-10 10])
yline(0,':b','LineWidth',1)
grid on

% state histories ---------------------------------------------------------

fig(2)=figure('Name','State Histories','Position', [50 75 1000 650]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

nexttile
plotx1=plot(solution.T(1:nplot),X(1:nplot,1)/1000,'.-b');
hold on
plotx2=plot(solution.T(1:nplot),solution.X(1:nplot,1)/1000,'.-r');
title('Horizontal Distance')
xlabel('Time, s')
ylabel('Horizontal Distance, km')
grid on
legend([plotx2 plotx1],{'ICLOCS Solution','Simulation Results'},'Location','northwest');

nexttile
plot(solution.T(1:nplot),-1*X(1:nplot,2),'.-b')
hold on
plot(solution.T(1:nplot),-1*solution.X(1:nplot,2),'.-r')
title('Altitude')
xlabel('Time, s')
ylabel('Altitude, m')
grid on

nexttile
plot(solution.T(1:nplot),rad2deg(X(1:nplot,5)),'.-b')
hold on
plot(solution.T(1:nplot),rad2deg(solution.X(1:nplot,5)),'.-r')
title('Pitch Angle')
xlabel('Time, s')
ylabel('\theta, deg')
yline(0,':b','LineWidth',1)
grid on

nexttile
plot(solution.T(1:nplot),Va_sim(1:nplot),'.-b')
hold on
plot(solution.T(1:nplot),Va_sol(1:nplot),'.-r')
title('Airspeed')
xlabel('Time, s')
ylabel('Va, m/s')
grid on

nexttile
plot(solution.T(1:nplot),rad2deg(alpha_sim(1:nplot)),'.-b')
hold on
plot(solution.T(1:nplot),rad2deg(alpha_sol(1:nplot,1)),'.-r')
title('AoA')
xlabel('Time, s')
ylabel('\alpha, deg')
yline(0,':b','LineWidth',1)
grid on

nexttile
plot(solution.T(1:nplot),rad2deg(X(1:nplot,6)),'.-b')
hold on
plot(solution.T(1:nplot),rad2deg(solution.X(1:nplot,6)),'.-r')
title('Pitch Rate')
xlabel('Time, s')
ylabel('q, deg/s')
yline(0,':b','LineWidth',1)
grid on


