
clc
clear all
% close all

%% Load data

% reference trajectory
% load rundata_trajopt/UNIFIERLanding_20240219_003236.mat solution
% load rundata_trajopt/UNIFIERLanding_20240322_035130.mat solution
load rundata_trajopt/UNIFIERLanding_20240620_050711.mat solution

% aircraft data
load data/UNIFIER_LOAD.mat
global LOADROM
LOADROM.gr        = gr;
LOADROM.dp_DEP    = dp_DEP;
LOADROM.dp_HTU    = dp_HTU;
LOADROM.m         = m;
LOADROM.xyz_cg_12 = xyz_cg_12;
LOADROM.Iyy       = Iyy;
LOADROM.S         = S;
LOADROM.c         = c;
LOADROM.xyz_DEP   = xyz_DEP;
LOADROM.prop_d    = prop_d;
LOADROM.DEP_inc   = DEP_inc;
LOADROM.n_prop    = n_prop;

% Load ROM data
load data/ROMv3/UNIFIER_ROMv3_20240613_002318.mat % v3, subset v1-50
LOADROM.ROM = ROM;

dt       = solution.T(2);    % timestep size
X_target = solution.X;       % extract reference state trajectories
nX       = size(X_target,2); % number of state variables
nsteps   = size(X_target,1); % number oftime steps
Umax     = [umax(3) umax(5) umax(7)];    % controls max value
Umin     = [umin(3) umin(5) umin(7)];    % controls min value
DUmax    = [dumax(3) dumax(5) dumax(7)]; % control rate limits

%% Set Flap Deflection

dFlap = deg2rad(12);

global runconfig
runconfig.dFlap = dFlap;
runconfig.ROMfile=4;
runconfig.ROMdep=1;

%% Optimization

fprintf('OPTIMIZATION PROGRESS:\n')
fprintf(' ____________________ \n')
fprintf('|START       COMPLETE|\n')
fprintf(' ')

startLoop = tic;
% nsteps=40;
for i=1:nsteps

    % current state
    if i==1
        X_res(i,:) = X_target(1,:);
    else
        X_res(i,:) = X_res(i-1,:) + DX_res(i-1,:).*dt;
    end

    if i~=nsteps
        % target accelerations
        DX_target(i,:) = (X_target(i+1,:)-X_res(i,:))/dt;
    
        % guess control inputs, bounds
        if i==1
            U_guess(i,:) = [deg2rad(-1) 0.31 0.25];
            ub(i,:) = Umax;
            lb(i,:) = Umin;
        else
            U_guess(i,:) = U_res(i-1,:);
            ub(i,:) = min(U_res(i-1,:)+DUmax,Umax);
            lb(i,:) = max(U_res(i-1,:)-DUmax,Umin);
        end
        
        % set fmincon options
        options.Display       = 'off';
        % options.Algorithm     = 'sqp';
        options.Algorithm     = 'interior-point';
        options.FunValCheck   = 'off';
        options.ScaleProblem  = 'false';
        options.FinDiffType   = 'forward';
        options.TolX          = 1e-8;  % Termination tolerance on x (aka step tolerance) Default=1e-6
        options.DiffMinChange = 1e-7;  % Minimum change in variables for finite-difference gradients. Default=0.
        % options.DiffMaxChange = 1e-0;  % Maximum change in variables for finite-difference gradients. Default=Inf.
        % options.TolFun        = 1e-8;  % Termination tolerance on the first-order optimality (aka optimalityTolerance). Default=1e-6. 
        % options.TolCon        = 1e-3;  % Constraint violation tolerance
        % options.MaxIter       = 100;   % Max iterations
        % options.MaxFunEvals   = 1000;  % Max function evaluations
        % options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
        % options.OutputFcn     = @outputFcn_global;
        
        % run otpimization
        global target
        target.DX = DX_target(i,:);
        target.X  = X_res(i,:);
        
        startOpt  = tic;
        [U_res(i,:),fval,exitflag,output] = fmincon(@(x) OptimalTracking_UNIFIER_obj(x),U_guess(i,:),[],[],[],[],lb(i,:),ub(i,:),[],options);
        t_opt(i) = toc(startOpt);
        fval_hist(i)                 = fval;
        output_hist.iterations(i)    = output.iterations;
        output_hist.funcCount(i)     = output.funcCount;
        output_hist.stepsize(i)      = output.stepsize;
        output_hist.firstorderopt(i) = output.firstorderopt;
        
        % evaluate accelerations
        DX_res(i,:) = UNIFIER_ROMdyn(X_res(i,:),U_res(i,:));
    end

    if rem(i,nsteps/20)==0
        fprintf('=')
    end

end
t_total = toc(startLoop);

%% Print Summary 

fprintf('\n')
fprintf('\n')
fprintf('<<OPTIMIZATION COMPLETE>>')
fprintf('\n')
fprintf('\n')
disp('PROCESSING TIME:');
fprintf('Total                = %6.2f seconds\n',t_total);
fprintf('Avg per Optimization = %6.4f seconds\n',mean(t_opt));
fprintf('Max per Optimization = %6.4f seconds\n',max(t_opt));
fprintf('Min per Optimization = %6.4f seconds\n',min(t_opt));
fprintf('\n');
disp('OPTIMIZATION RESULTS:');
fprintf('Avg No. of Iterations      = %3.1f iterations\n',mean(output_hist.iterations));
fprintf('Avg Obj. Func. Value       = %6.4f\n',mean(fval_hist));
fprintf('Avg First-Order Optimality = %5.4f\n',mean(output_hist.firstorderopt));
% fprintf('Avg Step Size              = %6.4f\n',mean(output_hist.stepsize))
fprintf('\n');

%% Plot Results

nplot=nsteps;

% calculate airspeed & angle of attack ------------------------------------
Va_sol    = sqrt(solution.X(:,3).^2+solution.X(:,4).^2);
alpha_sol = atan2(solution.X(:,4),solution.X(:,3));

Va_res    = sqrt(X_res(:,3).^2+X_res(:,4).^2);
alpha_res = atan2(X_res(:,4),X_res(:,3));

% state histories ---------------------------------------------------------
fig(1)=figure('Name','State Histories','Position', [50 75 1000 650]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

nexttile
plotx1=plot(solution.T(1:nplot),solution.X(1:nplot,1),'.-r');
hold on
plotx2=plot(solution.T(1:nplot),X_res(1:nplot,1),'.-b');
grid on
legend([plotx1 plotx2],{'Reference','Tracking Result'},'Location','northwest');
title('Horizontal Position')
ylabel('x (m)')
xlabel('t (s)')

nexttile
plotz1=plot(solution.T(1:nplot),-1*solution.X(1:nplot,2),'.-r');
hold on
plotz2=plot(solution.T(1:nplot),-1*X_res(1:nplot,2),'.-b');
grid on
title('Altitude')
ylabel('-z (m)')
xlabel('t (s)')

nexttile
plott1=plot(solution.T(1:nplot),rad2deg(solution.X(1:nplot,5)),'.-r');
hold on
plott2=plot(solution.T(1:nplot),rad2deg(X_res(1:nplot,5)),'.-b');
grid on
title('Pitch Angle')
ylabel('\theta (deg)')
xlabel('t (s)')

% nexttile
% plotu1=plot(solution.T(1:nplot),solution.X(1:nplot,3),'.-r');
% hold on
% plotu2=plot(solution.T(1:nplot),X_res(1:nplot,3),'.-b');
% grid on
% % legend([plotu1 plotu2],{'Reference','Tracking Result'},'Location','best');
% title('Horizontal Speed (Body Axes)')
% ylabel('u (m/s)')
% xlabel('t (s)')
% 
% nexttile
% plotw1=plot(solution.T(1:nplot),-1*solution.X(1:nplot,4),'.-r');
% hold on
% plotw2=plot(solution.T(1:nplot),-1*X_res(1:nplot,4),'.-b');
% grid on
% % legend([plotw1 plotz2],{'Reference','Tracking Result'},'Location','best');title('Equality Constraints')
% title('Vertical Speed (Body Axes)')
% ylabel('-w (m/s)')
% xlabel('t (s)')

nexttile
plotu1=plot(solution.T(1:nplot),Va_sol(1:nplot),'.-r');
hold on
plotu2=plot(solution.T(1:nplot),Va_res(1:nplot),'.-b');
grid on
title('Airspeed')
ylabel('V_a (m/s)')
xlabel('t (s)')

nexttile
plotw1=plot(solution.T(1:nplot),rad2deg(alpha_sol(1:nplot)),'.-r');
hold on
plotw2=plot(solution.T(1:nplot),rad2deg(alpha_res(1:nplot)),'.-b');
grid on
title('Angle of Attack')
ylabel('\alpha (deg)')
xlabel('t (s)')

nexttile
plotq1=plot(solution.T(1:nplot),rad2deg(solution.X(1:nplot,6)),'.-r');
hold on
plotq2=plot(solution.T(1:nplot),rad2deg(X_res(1:nplot,6)),'.-b');
grid on
title('Pitch Rate')
ylabel('q (deg/s)')
xlabel('t (s)')

% control histories ---------------------------------------------------------
fig(2)=figure('Name','Control Histories','Position', [900 75 600 650]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")

nexttile
plot(solution.T(1:nplot),solution.U(1:nplot,2),'.-r')
hold on
plot(solution.T(1:nplot-1),U_res(1:nplot-1,2),'.-b')
title('DEP Thrust Level')
xlabel('Time, s')
ylabel('DEP_c_o_l, 0-1')
grid on

nexttile
plotu1=plot(solution.T(1:nplot),solution.U(1:nplot,3),'.-r');
hold on
plotu2=plot(solution.T(1:nplot-1),U_res(1:nplot-1,3),'.-b');
title('HTU Thrust Level')
xlabel('Time, s')
ylabel('HTU, 0-1')
grid on
legend([plotu1 plotu2],{'Reference','Tracking Result'},'Location','northeast');

nexttile
plot(solution.T(1:nplot),rad2deg(solution.U(1:nplot,1)),'.-r')
hold on
plot(solution.T(1:nplot-1),rad2deg(U_res(1:nplot-1,1)),'.-b')
title('Elevator Deflection')
xlabel('Time, s')
ylabel('\delta_E_l_e_v, deg')
yline(0,':b','LineWidth',1)
grid on

nexttile
plot(solution.T(1:nplot),linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solution.T)),'.-k')
% plot(solution.T,rad2deg(solution.U(:,4)),'.-k')
title('Flap Deflection')
xlabel('Time, s')
ylabel('\delta_F_l_a_p, deg')
ylim([-5 15])
yline(0,':b','LineWidth',1)
grid on

% convergence history -----------------------------------------------------
fig(2)=figure('Name','Convergence History','Position', [75 75 1400 380]);
tiledlayout(1,3,"TileSpacing","tight","Padding","compact")

nexttile
plot(1:nplot-1,fval_hist,'.-k')
grid on
title('Objective Function Value')
xlabel('Timestep')
ylabel('Fval')

nexttile
plot(1:nplot-1,output_hist.firstorderopt,'.-k')
grid on
title('First Order Optimality')
xlabel('Timestep')
ylabel('Optimality')

nexttile
plot(1:nplot-1,output_hist.iterations,'.-k')
grid on
title('No. of Iterations')
xlabel('Timestep')
ylabel('Iterations')

