clear all

%% Load ROMs

load data/UNIFIER_LOAD_ROM_72.mat ROM % v1, 72.74 m/s
ROM1=ROM;
clear ROM

load data/UNIFIER_LOAD_ROM_50.mat ROM % v1, 50 m/s
ROM2=ROM;
clear ROM

load data/UNIFIER_LOAD_ROM_v2.mat ROM % v2
ROM3=ROM;
clear ROM

load data/ROMv3/UNIFIER_LOAD_ROMv3_20240613_002318.mat ROM % v3, subset v1-50
ROM4=ROM;
clear ROM

load data/ROMv4/UNIFIER_LOAD_ROMv4_20240613_053529.mat ROM S c % v4, subset v1-10
ROM5=ROM;
clear ROM

%% Evaluate forces from same control inputs

% load states & controls

% load trim/rundata/UNIFIER_trim_out_20240612_031926 xstar ustar % HFM cruise 0 deg flap
load trim/rundata/UNIFIER_trim_out_20240612_032607 xstar ustar xdotstar% HFM cruise 5 deg flap
xstarhfm=xstar;
ustarhfm=ustar;
xdotstarhfm=xdotstar;
clear xdotstar
clear xstar
clear ustar

u     = xstarhfm(4);
w     = xstarhfm(6);
Va    = sqrt(u^2+w^2);
DEP   = ustarhfm(5);

alpha = atan2(w,u);
dElev = ustarhfm(3);
dFlap = ustarhfm(4);
J     = DEPVa2J(Va,DEP);

h             = -xstarhfm(3);
[~,~,~,rho,~] = atmosisa(h);
qS            = 0.5*rho*Va^2*S;

% HFM ---------------------------------------------------------------------

% call dynamics function
set_param('UNIFIER_dyn','SimulationMode','rapid-accelerator')
UNIFIER_dyn([],[],[],'compile')
out = UNIFIER_dyn(0,[],[xstarhfm;ustarhfm],'outputs');
UNIFIER_dyn([],[],[],'term')

% extract aerodynamic forces in body axes
F_ae_b = out(17:19);

% convert to wind axes
rot    = [cos(alpha)   0  sin(alpha);  
          0               1  0;
          -sin(alpha)  0  cos(alpha)];
F_ae_w = rot*F_ae_b;

L_HFM = -F_ae_w(3);
D_HFM = -F_ae_w(1);
M_HFM = out(21);


% ROM v1 (ROM2) -----------------------------------------------------------

CLv1 = interpn(ROM2.dFlap,ROM2.alpha,ROM2.J,ROM2.dElev,... % CL(alpha)
               ROM2.CL,...                              
               dFlap,alpha,J,dElev);
CDv1 = interpn(ROM2.dFlap,ROM2.alpha,ROM2.J,ROM2.dElev,... % CD(alpha)
               ROM2.CD,...
               dFlap,alpha,J,dElev); 
CMv1 = interpn(ROM2.dFlap,ROM2.alpha,ROM2.J,ROM2.dElev,... % CM(alpha,dElev)
               ROM2.CM,... 
               dFlap,alpha,J,dElev);

L_v1 = CLv1*qS;
D_v1 = CDv1*qS;
M_v1 = CMv1*qS*c;

% ROM v2 (ROM5) -----------------------------------------------------------

CLv2 = interpn(ROM5.alpha,ROM5.dElev,ROM5.dFlap,... % breakpoints
               ROM5.CL,...                        % table data
               alpha,dElev,dFlap);   % inputs
CDv2 = interpn(ROM5.alpha,ROM5.dElev,ROM5.dFlap,... % breakpoints
               ROM5.CD,...                        % table data
               alpha,dElev,dFlap);   % inputs
CMv2 = interpn(ROM5.alpha,ROM5.dElev,ROM5.dFlap,... % breakpoints
               ROM5.CM,...                        % table data
               alpha,dElev,dFlap);   % inputs

L_v2 = CLv2*qS;
D_v2 = CDv2*qS;
M_v2 = CMv2*qS*c;

% ROM v2 (ROM5) -----------------------------------------------------------

CLv3 = interp1(ROM4.alpha,...           % breakpoints
               ROM4.CL,...              % table data
               alpha);             % inputs
CDv3 = interp1(ROM4.alpha,...           % breakpoints
               ROM4.CD,...              % table data
               alpha);             % inputs
CMv3 = interpn(ROM4.alpha,ROM4.dElev,... % breakpoints
               ROM4.CM,...              % table data
               alpha,dElev);   % inputs

L_v3 = CLv3*qS;
D_v3 = CDv3*qS;
M_v3 = CMv3*qS*c;

% compile
Lcomp = [L_HFM; L_v1; L_v2; L_v3];
Dcomp = [D_HFM; D_v1; D_v2; D_v3];
Mcomp = [M_HFM; M_v1; M_v2; M_v3];
forcecomp = [Lcomp Dcomp Mcomp];

%% Compare trim controls

% load trim results
load trim/rundata/UNIFIER_trim_out_20240612_060030 xstar ustar xdotstar% ROM2-1 cruise 5 deg flap
xstarv1=xstar;
ustarv1=ustar;
xdotstarv1=xdotstar;
clear xdotstar
clear xstar
clear ustar

load trim/rundata/UNIFIER_trim_out_20240613_054350 xstar ustar xdotstar% ROM5 cruise 5 deg flap
xstarv2=xstar;
ustarv2=ustar;
xdotstarv2=xdotstar;
clear xdotstar
clear xstar
clear ustar

load trim/rundata/UNIFIER_trim_out_20240613_002923 xstar ustar xdotstar% ROM4 cruise 5 deg flap
xstarv3=xstar;
ustarv3=ustar;
xdotstarv3=xdotstar;
clear xdotstar
clear xstar
clear ustar

%compile
ucomp=[xstarhfm(4); xstarv1(3); xstarv2(3); xstarv3(3)];
wcomp=[xstarhfm(6); xstarv1(4); xstarv2(4); xstarv3(4)];

Vacomp       = sqrt(ucomp.^2+wcomp.^2);
alphacomp    = rad2deg(atan2(wcomp,ucomp));
thetacomp    = rad2deg([xstarhfm(8); xstarv1(5); xstarv2(5); xstarv3(5)]);

dElevcomp    = rad2deg([ustarhfm(3); ustarv1(1); ustarv2(1); ustarv3(1)]);
HTUcomp      = [ustarhfm(7); ustarv1(3); ustarv2(3); ustarv3(3)];

xedotcomp    = [xdotstarhfm(1); xdotstarv1(1); xdotstarv2(1); xdotstarv3(1)];
zedotcomp    = [xdotstarhfm(3); xdotstarv1(2); xdotstarv2(2); xdotstarv3(2)];
udotcomp     = [xdotstarhfm(4); xdotstarv1(3); xdotstarv2(3); xdotstarv3(3)];
wdotcomp     = [xdotstarhfm(6); xdotstarv1(4); xdotstarv2(4); xdotstarv3(4)];
thetadotcomp = rad2deg([xdotstarhfm(8); xdotstarv1(5); xdotstarv2(5); xdotstarv3(5)]);
qdotcomp    = rad2deg([xdotstarhfm(11); xdotstarv1(6); xdotstarv2(6); xdotstarv3(6)]);

trimcomp = [Vacomp alphacomp dElevcomp HTUcomp xedotcomp zedotcomp udotcomp wdotcomp thetadotcomp qdotcomp];












