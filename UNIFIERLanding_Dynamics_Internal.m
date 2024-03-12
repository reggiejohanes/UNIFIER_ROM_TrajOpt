function [DX,g_neq] = UNIFIERLanding_Dynamics_Internal(X,U,p,t,data)
% Aircraft Dynamics - Internal
%
% Syntax:  
%          [dx] = Dynamics(x,u,p,t,vdat)	(Dynamics Only)
%          [dx,g_eq] = Dynamics(x,u,p,t,vdat)   (Dynamics and Eqaulity Path Constraints)
%          [dx,g_neq] = Dynamics(x,u,p,t,vdat)   (Dynamics and Inqaulity Path Constraints)
%          [dx,g_eq,g_neq] = Dynamics(x,u,p,t,vdat)   (Dynamics, Equality and Ineqaulity Path Constraints)
% 
% Inputs:
%    x  - state vector
%    u  - input
%    p  - parameter
%    t  - time
%    vdat - structured variable containing the values of additional data used inside
%          the function%      
% Output:
%    dx - time derivative of x
%    g_eq - constraint function for equality constraints
%    g_neq - constraint function for inequality constraints

%% Evaluate accelerations

DX = UNIFIER_ROMdyn_script(X,U);

%% Evaluate path constraints

% constraint(s) violated when negative (c<0)

% max rate of descent
rodmax = convvel(800,'ft/min','m/s');
c1     = rodmax-DX(:,2);

% min rate of descent
rodmin = 0;
c2     = DX(:,2)-rodmin;

g_neq  = [c1,c2];