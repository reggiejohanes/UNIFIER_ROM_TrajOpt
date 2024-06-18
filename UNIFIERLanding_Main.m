
% clc
clear all;
% close all;
format compact;

%% Documentation

starttime    = datetime; % start date & time
timestamprun = string(starttime,"yyyyMMdd_HHmmss");
logname      = 'rundata_trajopt\UNIFIERLanding_' + timestamprun; % name of diary & data log file

diary (logname + '.txt')
diary on % start diary

%% Configure Run

mpoints = 250;

global runconfig

% cost function
runconfig.boundarycost = 1; % 1 = tf
                            % 2 = xf(1)
                            % 3 = -
runconfig.stagecost    = 1; % 1 = stage cost on

% ROM settings
runconfig.ROMfile = 4; % 1=v1-72.74, 2=v1-50, 3=v0, 4=v3, 5=v2
runconfig.ROMdep  = 1; % 1=all dependencies, 2=reduced dependencies
                            
% flap deflection
dFlap = deg2rad(5);
runconfig.dFlap = dFlap;

% ICLOCS settings
runconfig.ipopttol = 5e-3; %default = 1e-8
runconfig.scaling  = 1; %1=on, 0=off

% Load aircraft data
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
if runconfig.ROMfile==1
    load data/UNIFIER_ROM_72.mat % v1, 72.74 m/s
elseif runconfig.ROMfile==2
    load data/UNIFIER_ROM_50.mat % v1, 50 m/s
elseif runconfig.ROMfile==3
    load data/UNIFIER_ROM_v0.mat % v0
elseif runconfig.ROMfile==4
    load data/ROMv3/UNIFIER_ROMv3_20240613_002318.mat % v3, subset v1-50
elseif runconfig.ROMfile==5
    load data/ROMv2/UNIFIER_ROMv2_20240613_053529.mat % v2, subset v1-10
else
    error("Invalid ROM file setting")
end
LOADROM.ROM = ROM;

% Error bound multiplier
runconfig.ebmult = 1;

% inequality constraints
runconfig.ineq_rodmin = convvel(0,'ft/min','m/s');
runconfig.ineq_rodmax = convvel(350,'ft/min','m/s');
runconfig.ineq_aoamin = deg2rad(-15);
runconfig.ineq_aoamax = deg2rad(10);
runconfig.ineq_Vamin = 35.85*1.1;
runconfig.ineq_Vamax = 80;

% boundary constraints
% runconfig.bndc_Vamin  = -inf;
% runconfig.bndc_Vamax  = inf;
runconfig.bndc_Vamin  = 35.85*1.1;
runconfig.bndc_Vamax  = 35.85*1.3;
runconfig.bndc_rodmin = convvel(-inf,'ft/min','m/s');
runconfig.bndc_rodmax = convvel(inf,'ft/min','m/s');

% control & rate limits

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
runconfig.dFlapmin = umin(4); 

runconfig.xmax     = inf;
runconfig.zmax     = 0;
runconfig.umax     = 75;
runconfig.wmax     = 75*sind(20);
runconfig.thetamax = deg2rad(5);
runconfig.qmax     = deg2rad(2);
runconfig.dElevmax = umax(3);
runconfig.DEPmax   = umax(5);
runconfig.HTUmax   = umax(7);
runconfig.dFlapmax = umax(4); 

% initial conditions
if runconfig.ROMfile==1 
    % trimname0="20240613_051929"; %ROM1-1, cruise, 0deg flap
    trimname0="20240607_023005"; %ROM1-1, cruise, 5deg flap
    % trimname0="20240613_051912"; %ROM1-1, cruise, 12deg flap
elseif runconfig.ROMfile==2
    % trimname0="20240612_055958"; %ROM2-1, cruise, 0deg flap
    trimname0="20240612_060030"; %ROM2-1, cruise, 5deg flap
    % trimname0="20240612_060050"; %ROM2-1, cruise, 12deg flap
    % trimname0="20240612_060119"; %ROM2-2, cruise, 0deg flap
    % trimname0="20240612_060138"; %ROM2-2, cruise, 5deg flap
    % trimname0="20240612_060153"; %ROM2-2, cruise, 12deg flap
elseif runconfig.ROMfile==3
    % trimname0="20240612_035139"; %ROM3-1, cruise, 0deg flap
    trimname0="20240612_035214"; %ROM3-1, cruise, 5deg flap
    % trimname0="20240612_035256"; %ROM3-1, cruise, 12deg flap
elseif runconfig.ROMfile==4
    % trimname0="20240613_050426"; %ROM4 (subset ROM2), cruise, 0deg flap
    trimname0="20240613_002923"; %ROM4 (subset ROM2), cruise, 5deg flap
    % trimname0="20240613_050411"; %ROM4 (subset ROM2), cruise, 12deg flap
elseif runconfig.ROMfile==5
    % trimname0="20240613_054253"; %ROM5 (subset ROM2), cruise, 0deg flap
    trimname0="20240613_054350"; %ROM5 (subset ROM2), cruise, 5deg flap
    % trimname0="20240613_054428"; %ROM5 (subset ROM2), cruise, 12deg flap
else
    error("Invalid ROM file setting")
end
trimfile0='rundata_trim/UNIFIER_trim_out_'+trimname0+'.mat';
load(trimfile0,"xstar","ustar")
xstar0=xstar;
ustar0=ustar;

runconfig.x0     = xstar0(1);
runconfig.z0     = xstar0(2);
runconfig.u0     = xstar0(3);
runconfig.w0     = xstar0(4);
runconfig.theta0 = xstar0(5);
runconfig.q0     = xstar0(6);
runconfig.dElev0 = ustar0(1);
runconfig.DEP0   = ustar0(2);
runconfig.HTU0   = ustar0(3);

% terminal conditions
if runconfig.ROMfile==1 
    % trimname_f="20240613_051817"; %ROM1-1, landing, 0deg flap
    trimname_f="20240613_051838"; %ROM1-1, landing, 5deg flap
    % trimname_f="20240613_051852"; %ROM1-1, landing, 12deg flap
elseif runconfig.ROMfile==2
    % trimname_f="20240613_051046"; %ROM2-1, landing, 0deg flap
    trimname_f="20240613_051102"; %ROM2-1, landing, 5deg flap
    % trimname_f="20240613_051121"; %ROM2-1, landing, 12deg flap
    % trimname_f="20240612_060927"; %ROM2-2, landing, 0deg flap
    % trimname_f="20240612_061004"; %ROM2-2, landing, 5deg flap
    % trimname_f="20240612_061021"; %ROM2-2, landing, 12deg flap
elseif runconfig.ROMfile==3
    % trimname_f="20240613_051504"; %ROM3-1, landing, 0deg flap
    trimname_f="20240613_051424"; %ROM3-1, landing, 5deg flap
    % trimname_f="20240613_051333"; %ROM3-1, landing, 12deg flap
elseif runconfig.ROMfile==4
    % trimname_f="20240613_045931"; %ROM4, landing, 0deg flap
    trimname_f="20240613_003604"; %ROM4, landing, 5deg flap
    % trimname_f="20240613_050346"; %ROM4, landing, 12deg flap
elseif runconfig.ROMfile==5
    % trimname_f="20240613_054608"; %ROM5, landing, 0deg flap
    trimname_f="20240613_054553"; %ROM5, landing, 5deg flap
    % trimname_f="20240613_054520"; %ROM5, landing, 12deg flap
else
    error("Invalid ROM file setting")
end
trimfile_f='rundata_trim/UNIFIER_trim_out_'+trimname_f+'.mat';
load(trimfile_f,"xstar","ustar")
xstarf=xstar;
ustarf=ustar;

runconfig.zf      = xstarf(2);
runconfig.xf      = -1*(xstar0(2)-runconfig.zf)/tand(1); % 3deg glide slope
runconfig.uf      = xstarf(3); %35.85*1.3
runconfig.wf      = xstarf(4);
runconfig.thetaf  = xstarf(5);
runconfig.qf      = xstarf(6);

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

runconfig.dElev_f = ustarf(1);
runconfig.DEP_f   = ustarf(2);
runconfig.HTU_f   = ustarf(3);

numset = [timestamprun,...
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
          runconfig.ipopttol,...
          runconfig.scaling,...
          trimname0];

if runconfig.ROMfile==4 || runconfig.ROMfile==5
    numset(16)='-';
end

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

% preview results
avgglideslope = atan2d(solution.X(1,2)*-1,solution.X(end,1))
tf            = solution.tf
xf            = max(solution.X(:,1))

%documentation
numres = [t_run,...
          solution.tf,...
          max(solution.X(:,1)),...
          solution.MaxConstVioError];
numall = [numset '-' numres];

%% Plot Figures

close all

% geometric trajectory -----------------------------------------------------

fig(1)=figure('Name','Geometric Trajectory','Position', [50 450 1200 400]);
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
yline(35.85*1.1,'-.r',{'V_s_t_a_l_l*1.3 = 39.4 m/s'},'LabelHorizontalAlignment','left','LabelVerticalAlignment','top','FontSize',8)
% yline(min(Va),'-.k',{vminlabel},'LabelHorizontalAlignment','left','LabelVerticalAlignment','bottom','FontSize',8)
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
