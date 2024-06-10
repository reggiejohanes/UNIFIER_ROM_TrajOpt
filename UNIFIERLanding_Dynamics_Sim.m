function [DX] = UNIFIERLanding_Dynamics_Sim(X,U,p,t,data)
% Aircraft Dynamics - Simulation
%
% Syntax:  
%          [dx] = Dynamics(x,u,p,t,vdat)
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

%%

DX = UNIFIER_ROMdyn(X,U);
% DX = UNIFIER_ROMdyn_v2(X,U);