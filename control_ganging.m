function u = control_ganging(u0)

ail0   = u0(1);
rud0   = u0(2);
elev0   = u0(3);
flap0   = u0(4);
DEP_col = u0(5);
DEP_slp = u0(6);
HTU     = u0(7);

% ailerons
ailL = ail0;
ailR = ail0*-1;

% v-tail
rudL = elev0-rud0;
rudR = elev0+rud0;

% flaps
flapL = flap0;
flapR = flap0;

% DEP
zeta = [-1, -0.8, -0.4, -0.2, -0.1, 0, 0, 0.1, 0.2, 0.4, 0.8, 1];
k_slope = 0.785;
DEPi = zeros(1,numel(zeta));
for i=1:numel(zeta)
    DEPi(i) = tan(DEP_slp*k_slope)*zeta(i)+DEP_col;
end

%compile new control vector
u = [ailL;
     ailR;
     rudL;
     rudR;
     flapL;
     flapR;
     DEPi;  % DEP activity factors 1-12
     HTU;   % HTU activity factor
     0];     % landing gear position (0 = stowed)

end