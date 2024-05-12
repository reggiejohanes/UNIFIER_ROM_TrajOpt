function J=DEPVa2J(Va,DEP)

load data/UNIFIER_LOAD_ROM.mat

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

J = Va./(rps_cmd.*1.6+eps);
J = max(min(J,2.5),0.3);

end