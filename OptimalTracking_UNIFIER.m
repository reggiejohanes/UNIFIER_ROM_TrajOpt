clc
clear all
close all

%% Load data

load rundata_trajopt/UNIFIERLanding_20240219_003236.mat solution
load data/UNIFIER_LOAD_ROM.mat

dt       = solution.T(2);    % timestep size
X_target = solution.X;       % extract reference state trajectories
nX       = size(X_target,2); % number of state variables
nsteps   = size(X_target,1); % number of state variables
Umax     = [umax(3) umax(4) umax(5) umax(7)];     % controls max value
Umin     = [umin(3) umin(4) umin(5) umin(7)];     % controls min value
DUmax    = [dumax(3) dumax(4) dumax(5) dumax(7)]; % control rate limits

%%

fprintf('OPTIMIZATION PROGRESS:\n')
fprintf(' ____________________ \n')
fprintf('|START       COMPLETE|\n')
fprintf(' ')

startLoop = tic;
nsteps=40;
for i=1:nsteps

    % initial states
    if i==1
        X_res(i,:) = X_target(1,:);
    else
        X_res(i,:) = X_res(i-1,:) + DX_res(i-1,:).*dt;
    end
    
    % target accelerations
    DX_target(i,:) = (X_target(i+1,:)-X_res(i,:))/dt;
    
    % guess
    if i==1
        U_guess(i,:) = [deg2rad(-1) deg2rad(0.1) 0.31 0.25];
    else
        U_guess(i,:) = U_res(i-1,:);
    end
    
    % bounds
    if i==1
        ub(i,:) = Umax;
        lb(i,:) = Umin;
    else
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
    options.DiffMinChange = 1e-8;  % Minimum change in variables for finite-difference gradients. Default=0.
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
    DX_res(i,:) = UNIFIER_ROMdyn_script(X_res(i,:),U_res(i,:));

    if rem(i,nsteps/20)==0
        fprintf('=')
    end

end
t_total = toc(startLoop);

%%
fprintf('\n')
fprintf('\n')
fprintf('<<OPTIMIZATION COMPLETE>>')
fprintf('\n')
fprintf('\n')
disp('PROCESSING TIME:');
fprintf('Total                = %6.4f seconds\n',t_total);
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

% state histories ---------------------------------------------------------
fig(1)=figure('Name','State Histories','Position', [75 75 1400 750]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")

nexttile
plotx1=plot(solution.T(1:nsteps),solution.X(1:nsteps,1),'.-r');
hold on
plotx2=plot(solution.T(1:nsteps),X_res(1:nsteps,1),'.-b');
grid on
legend([plotx1 plotx2],{'Reference','Tracking Result'},'Location','northwest');
title('Horizontal Position')
xlabel('x (m)')
ylabel('t (s)')

nexttile
plotz1=plot(solution.T(1:nsteps),-1*solution.X(1:nsteps,2),'.-r');
hold on
plotz2=plot(solution.T(1:nsteps),-1*X_res(1:nsteps,2),'.-b');
grid on
% legend([plotz1 plotz2],{'Reference','Tracking Result'},'Location','best');title('Equality Constraints')
title('Altitude')
xlabel('-z (m)')
ylabel('t (s)')

nexttile
plott1=plot(solution.T(1:nsteps),rad2deg(solution.X(1:nsteps,5)),'.-r');
hold on
plott2=plot(solution.T(1:nsteps),rad2deg(X_res(1:nsteps,5)),'.-b');
grid on
% legend([plott1 plott2],{'Reference','Tracking Result'},'Location','best');
title('Pitch Angle')
xlabel('\theta (deg)')
ylabel('t (s)')

nexttile
plotu1=plot(solution.T(1:nsteps),solution.X(1:nsteps,3),'.-r');
hold on
plotu2=plot(solution.T(1:nsteps),X_res(1:nsteps,3),'.-b');
grid on
% legend([plotu1 plotu2],{'Reference','Tracking Result'},'Location','best');
title('Horizontal Speed (Body Axes)')
xlabel('u (m/s)')
ylabel('t (s)')

nexttile
plotw1=plot(solution.T(1:nsteps),-1*solution.X(1:nsteps,4),'.-r');
hold on
plotw2=plot(solution.T(1:nsteps),-1*X_res(1:nsteps,4),'.-b');
grid on
% legend([plotw1 plotz2],{'Reference','Tracking Result'},'Location','best');title('Equality Constraints')
title('Vertical Speed (Body Axes)')
xlabel('-w (m/s)')
ylabel('t (s)')

nexttile
plotq1=plot(solution.T(1:nsteps),rad2deg(solution.X(1:nsteps,6)),'.-r');
hold on
plotq2=plot(solution.T(1:nsteps),rad2deg(X_res(1:nsteps,6)),'.-b');
grid on
% legend([plotq1 plotq2],{'Reference','Tracking Result'},'Location','best');title('Equality Constraints')
title('Pitch Rate')
xlabel('q (deg/s)')
ylabel('t (s)')

% convergence history -----------------------------------------------------
fig(2)=figure('Name','Convergence History','Position', [75 75 1400 380]);
tiledlayout(1,3,"TileSpacing","tight","Padding","compact")

nexttile
plot(1:nsteps,fval_hist,'.-k')
grid on
title('Objective Function Value')
xlabel('Timestep')
ylabel('Fval')

nexttile
plot(1:nsteps,output_hist.firstorderopt,'.-k')
grid on
title('First Order Optimality')
xlabel('Timestep')
ylabel('Optimality')

nexttile
plot(1:nsteps,output_hist.iterations,'.-k')
grid on
title('No. of Iterations')
xlabel('Timestep')
ylabel('Iterations')













