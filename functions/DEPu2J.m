function J=DEPu2J(u,DEP)

load data/UNIFIER_LOAD dp_DEP DEP_inc

% calculate DEP axial velocity
Va_DEPax = u.*cos(DEP_inc); % + w.*sin(DEP_inc) - not included in OBM

% convert activity factor to rps command
T_DEP_req = DEP.*800;
rpm_cmd   = interpn(dp_DEP.rpm_lookup.V_vec,...
                    dp_DEP.rpm_lookup.T_vec,...
                    dp_DEP.rpm_lookup.rpm_gird,...
                    Va,...
                    T_DEP_req,...
                    'linear');
if DEP < 0.001
    rpm_cmd = rpm_cmd.*0;
end
rps_cmd = rpm_cmd./60;

J = Va_DEPax./(rps_cmd.*1.6+eps);
J = max(min(J,2.5),0.3);

end