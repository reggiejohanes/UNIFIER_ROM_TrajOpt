function f0=OptimalTracking_UNIFIER_obj(U)

global target
DX_target = target.DX;
X         = target.X;

DX = UNIFIER_ROMdyn_script(X,U);

Q  = (DX'-DX_target')./DX_target';

% penalty weights
H      = diag(ones(1,numel(Q)));
H(1,1) = 1; % xdot
H(2,2) = 1; % zdot
H(3,3) = 1; % udot
H(4,4) = 1; % wdot
H(5,5) = 1; % thetadot
H(6,6) = 1; % qdot

f0 = Q'*H*Q;

end