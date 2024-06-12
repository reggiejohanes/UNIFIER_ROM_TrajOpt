
% clc
clear all;
% close all;
format compact;

%% Documentation

starttime = datetime; % start date & time
timestamp = string(starttime,"yyyyMMdd_HHmmss");
logname   = 'rundata_trajopt\UNIFIERLanding_' + timestamp; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Configure Run

mpoints = 100;

global runconfig

% ROM settings
runconfig.ROMfile = 2; % 1=72.74, 2=50, 3=v2
runconfig.ROMdep  = 2; % 1=all dependencies, 2=reduced dependencies

% flap deflection
dFlap = deg2rad(12);
runconfig.dFlap = dFlap;

% cost function
runconfig.stagecost    = 1; % 1 = stage cost on
runconfig.boundarycost = 1; % 1 = tf
                            % 2 = xf(1)
                            % 3 = -

% inequality constraints
runconfig.ineq_rodmin = convvel(-inf,'ft/min','m/s');
runconfig.ineq_rodmax = convvel(inf,'ft/min','m/s');
runconfig.ineq_aoamin = deg2rad(-inf);
runconfig.ineq_aoamax = deg2rad(inf);
runconfig.ineq_Vamin  = 35.85*1.3*-inf;
runconfig.ineq_Vamax  = inf;

% boundary constraints
runconfig.bndc_rodmin = convvel(-inf,'ft/min','m/s');
runconfig.bndc_rodmax = convvel(inf,'ft/min','m/s');
runconfig.bndc_Vamin  = -inf;
runconfig.bndc_Vamax  = inf;

% control & rate limits
loadfile='data/UNIFIER_LOAD_ROM_72.mat';
load(loadfile,"umax","umin","dumax")

runconfig.dumax = dumax;

runconfig.xmin     = 0;
runconfig.zmin     = -inf;
runconfig.umin     = 35*cosd(20);
runconfig.wmin     = -75*sind(20);
runconfig.thetamin = deg2rad(-5);
runconfig.qmin     = deg2rad(-2);
runconfig.dElevmin = umin(3);
runconfig.DEPmin   = umin(5);
runconfig.HTUmin   = umin(7);
runconfig.dFlapmin = Umin(4); 

runconfig.xmax     = inf;
runconfig.zmax     = 0;
runconfig.umax     = 75;
runconfig.wmax     = 75*sind(20);
runconfig.thetamax = deg2rad(5);
runconfig.qmax     = deg2rad(2);
runconfig.dElevmax = umax(3);
runconfig.DEPmax   = umax(5);
runconfig.HTUmax   = umax(7);
runconfig.dFlapmax = Umax(4); 

% initial conditions
if runconfig.ROMfile==1 
    trimname="20240607_023005"; %ROM 72.74, cruise, 5deg flap, DEP off
elseif runconfig.ROMfile==2
    % trimname="20240608_174341"; %ROM 50, cruise, 5deg flap, DEP off
    trimname="20240609_210811"; %ROM 50, reduced depencencies, cruise, 12deg flap, DEP off
elseif runconfig.ROMfile==3
    trimname="20240607_200221"; %ROM v2a, cruise, 5deg flap, DEP off
else
    error("Invalid ROM file setting")
end
trimfile='trim/rundata/UNIFIER_trim_out_'+trimname+'.mat';
load(trimfile,"xstar","ustar")

runconfig.x0     = xstar(1);
runconfig.z0     = xstar(2);
runconfig.u0     = xstar(3);
runconfig.w0     = xstar(4);
runconfig.theta0 = xstar(5);
runconfig.q0     = xstar(6);
runconfig.dElev0 = ustar(1);
runconfig.DEP0   = ustar(2);
runconfig.HTU0   = ustar(3);

% terminal conditions
runconfig.zf      = -5;
runconfig.xf      = -1*(xstar(2)-runconfig.zf)/tand(3); % 3deg glide slope
runconfig.uf      = 35.85*1.3;
runconfig.wf      = 2;
runconfig.thetaf  = deg2rad(0);
runconfig.qf      = deg2rad(0);

runconfig.xfu     = inf; %xf*1.2;
runconfig.zfu     = runconfig.zf;
runconfig.ufu     = inf; %uf*1.2;
runconfig.wfu     = inf; %wf+3;
runconfig.thetafu = inf; %thetaf+deg2rad(3);
runconfig.qfu     = inf; %qf+deg2rad(1);

runconfig.xfl     = -inf; %xf*0.8; -inf
runconfig.zfl     = runconfig.zf;
runconfig.ufl     = -inf; %uf*0.8;
runconfig.wfl     = -inf; %wf-3;
runconfig.thetafl = -inf; %thetaf-deg2rad(3);
runconfig.qfl     = -inf; %qf-deg2rad(1);

% error bound multiplier
runconfig.ebmult = 1;

numset = [timestamp,...
          mpoints,...
          runconfig.boundarycost,...
          runconfig.stagecost,...
          convvel(runconfig.ineq_rodmin,'m/s','ft/min'),...
          convvel(runconfig.ineq_rodmax,'m/s','ft/min'),...
          rad2deg(runconfig.ineq_aoamin),...
          rad2deg(runconfig.ineq_aoamax),...
          runconfig.ineq_Vamin,...
          runconfig.ineq_Vamax,...
          runconfig.bndc_Vamin,...
          runconfig.bndc_Vamax,...
          convvel(runconfig.bndc_rodmin,'m/s','ft/min'),...
          convvel(runconfig.bndc_rodmax,'m/s','ft/min'),...
          runconfig.ROMfile,...
          runconfig.ROMdep,...
          rad2deg(runconfig.dFlap),...
          runconfig.ebmult,...
          trimname];

%% Run Problem

tic
[problem,guess]      = UNIFIERLanding;       % Fetch the problem definition
options              = problem.settings(mpoints); % Get options and solver settings %2 inputs for LGR
[solution,MRHistory] = solveMyProblem(problem,guess,options);
t_run=toc;

%% Process results

% calculate airspeed & angle of attack
Va    = sqrt(solution.X(:,3).^2+solution.X(:,4).^2);
alpha = atan2(solution.X(:,4),solution.X(:,3));

% rate of descent
for i=1:mpoints-1
    rod(i)=(solution.X(i+1,2)-solution.X(i,2))/(solution.T(i+1)-solution.T(i));
end
rodft=convvel(rod,'m/s','ft/min');

% average glide slope
avgglideslope = atan2d(solution.X(1,2)*-1,solution.X(end,1))

%documentation
numres = [t_run,...
          solution.MaxConstVioError];
numall = [numset '-' numres];

%% Plot Figures

close all

% physical trajectory -----------------------------------------------------

fig(1)=figure('Name','Physical Trajectory','Position', [50 450 1200 400]);
plot(solution.X(:,1)/1000,-1*solution.X(:,2),'.-k')
title('Altitude vs Horizontal Distance')
xlabel('Horizontal Distance, km')
ylabel('Altitude, m')
grid on

% control histories ---------------------------------------------------------

fig(2)=figure('Name','Control Histories','Position', [900 75 600 500]);
tiledlayout(2,2,"TileSpacing","tight","Padding","compact")
nexttile
plot(solution.T,solution.U(:,2),'.-k')
title('DEP Thrust Level')
xlabel('Time, s')
ylabel('DEP_c_o_l, 0-1')
grid on
nexttile
plot(solution.T,solution.U(:,3),'.-k')
title('HTU Thrust Level')
xlabel('Time, s')
ylabel('HTU, 0-1')
grid on
nexttile
plot(solution.T,rad2deg(solution.U(:,1)),'.-k')
title('Elevator Deflection')
xlabel('Time, s')
ylabel('\delta_E_l_e_v, deg')
yline(0,':b','LineWidth',1)
grid on
nexttile
plot(solution.T,linspace(rad2deg(dFlap),rad2deg(dFlap),numel(solution.T)),'.-k')
% plot(solution.T,rad2deg(solution.U(:,4)),'.-k')
title('Flap Deflection')
xlabel('Time, s')
ylabel('\delta_F_l_a_p, deg')
ylim([-5 15])
yline(0,':b','LineWidth',1)
grid on

% state histories ---------------------------------------------------------

fig(3)=figure('Name','State Histories','Position', [50 75 1000 500]);
tiledlayout(2,3,"TileSpacing","tight","Padding","compact")
nexttile
plot(solution.T,solution.X(:,1)/1000,'.-k')
title('Distance')
xlabel('Time, s')
ylabel('x, km')
grid on
nexttile
plot(solution.T,-1*solution.X(:,2),'.-k')
title('Altitude')
xlabel('Time, s')
ylabel('-z, m')
grid on
nexttile
plot(solution.T,rad2deg(solution.X(:,5)),'.-k')
title('Pitch Angle')
xlabel('Time, s')
ylabel('\theta, deg')
yline(0,':b','LineWidth',1)
grid on
nexttile
plot(solution.T,Va,'.-k')
title('Airspeed')
xlabel('Time, s')
ylabel('Va, m/s')
grid on
vminlabel=['V_m_i_n= ' num2str(round(min(Va),2)) ' m/s'];
yline(35.85*1.3,'-.r',{'V_s_t_a_l_l*1.3 = 46.6 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
ylim([45 80])
nexttile
plot(solution.T,rad2deg(alpha),'.-k')
title('AoA')
xlabel('Time, s')
ylabel('\alpha, deg')
yline(0,':b','LineWidth',1)
grid on
nexttile
plot(solution.T,rad2deg(solution.X(:,6)),'.-k')
title('Pitch Rate')
xlabel('Time, s')
ylabel('q, deg/s')
yline(0,':b','LineWidth',1)
grid on

% rate of climb ---------------------------------------------------------

fig(4)=figure('Name','Rate of Climb','Position',[50 450 600 400]);
plot(solution.X(1:mpoints-1,1)/1000,-1*rodft,'.-k')
title('RoC vs Horizontal Distance')
xlabel('Horizontal Distance, km')
ylabel('Rate of Climb, ft/min')
yline(-350,'-.r',{'Max RoD = 350 ft/min'},'LabelHorizontalAlignment','right','LabelVerticalAlignment','bottom','FontSize',8,'LineWidth',2)
grid on

%% Save results

% save figures
savefig(fig,logname + '_figs');
clear fig

% save workspace
save(logname);

% end diary
diary off
