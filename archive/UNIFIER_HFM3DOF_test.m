function DX=UNIFIER_HFM3DOF_test(X,U)

% clc
% clear
% close all
% X = [0, -1219, 72.731047032614440, 1.142307104518741, 0.015706052282666, 0];
% U = [-0.015298320692100, 0, 0.306978739246813];

X = X*1;

U(4) = U(3);
U(3) = U(2);
U(2) = deg2rad(5);

t_sim  = 0;
res    = sim("UNIFIER_dyn.slx",'SrcWorkspace','current');
DX   = res.dx;

end