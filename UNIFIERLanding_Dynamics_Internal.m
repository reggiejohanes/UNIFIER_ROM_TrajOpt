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

DX = UNIFIER_ROMdyn(X,U);

%% Evaluate path constraints

alpha  = atan2(X(:,4),X(:,3));
Va     = sqrt(X(:,3).^2+X(:,4).^2);

g_neq  = [DX(:,2) alpha Va];
% g_neq  = [alpha Va];