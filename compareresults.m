
clc
clear
close all

%% run simulations

res_6dof = sim("UNIFIER_dyn.slx");
res_3dof = sim("UNIFIER_ROMdyn.slx");

%% compile results

% high fidelity model
comp(1:2,1)   = res_6dof.F;
comp(3,1)     = res_6dof.M;
comp(4:5,1)   = res_6dof.Fae;
comp(6,1)     = res_6dof.Mae;
comp(7:8,1)   = res_6dof.Fprop;
comp(9,1)     = res_6dof.Mprop;
comp(10:11,1) = res_6dof.Fdep;
comp(12,1)    = res_6dof.Mdep;
comp(13:14,1) = res_6dof.Fhtu;
comp(15,1)    = res_6dof.Mhtu;
comp(16:21,1) = res_6dof.dx;

% ROM
comp(1:2,2)   = res_3dof.F;
comp(3,2)     = res_3dof.M;
comp(4:5,2)   = res_3dof.Fae;
comp(6,2)     = res_3dof.Mae;
comp(7:8,2)   = res_3dof.Fprop;
comp(9,2)     = res_3dof.Mprop;
comp(10:11,2) = res_3dof.Fdep;
comp(12,2)    = res_3dof.Mdep;
comp(13:14,2) = res_3dof.Fhtu;
comp(15,2)    = res_3dof.Mhtu;
comp(16:21,2) = res_3dof.dx;

% calculate delta
comp(:,3)     = comp(:,2)-comp(:,1);
comp(:,4)     = comp(:,3)./comp(:,1);

% initial conditions
xu            = res_3dof.xu';
xu(5:8)       = rad2deg(xu(5:8));

%% force balance check (6dof)

w      = m*g;
faex   = abs(res_6dof.Fae(1));
faez   = abs(res_6dof.Fae(2));
fpropx = abs(res_6dof.Fprop(1));
fpropz = abs(res_6dof.Fprop(2));
theta  = xu(5);

fz     = w...
         + fpropz*cosd(theta)...
         + faex*sind(theta)...
         - faez*cosd(theta)...
         - fpropx*sind(theta);

fx     = fpropz*sind(theta)...
         + fpropx*cosd(theta)...
         - faez*sind(theta)...
         - faex*cosd(theta);







