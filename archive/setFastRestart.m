function simul = setFastRestart(aircraft, simul, fastRestart)
% Set Simulink model in order to be compliant with Fast Restart Mode. In
% this way, it does not need to be compiled before every run, which saves a
% lot of time for batch simulations (like trim routines and optimizations...)

%% List of blocks and their parameters that need to be modified

% Simscape Dynamics
blocksDyn = [...
  "/NED Ground to Air/Aircraft Position",...
  "/NED Ground to Air/Aircraft Position X",...
  "/NED Ground to Air/Aircraft Position Z",...
  "/NED Air to Body/Roll Rotation",...
  "/NED Air to Body/Pitch Rotation",...
  "/NED Air to Body/Yaw Rotation"];

paramsDyn = [...
  "PositionTargetValue",...
  "VelocityTargetValue",...
  "PxPositionTargetValue",...
  "PxVelocityTargetValue",...
  "PyPositionTargetValue",...
  "PyVelocityTargetValue",...
  "PzPositionTargetValue",...
  "PzVelocityTargetValue"];

% Flight Control System
blocksFcs = "delta_trim";
paramsFcs = "Value";


%% Update dialog parameters
if fastRestart
  openFmmModel(aircraft)
  set_param(aircraft.info.name, 'FastRestart', 'on');
  fastRestartForLinearAnalysis(aircraft.info.name, 'on')
  warning('off', 'Simulink:Engine:NonTunableVarChangedInFastRestart');
  warning('off', 'Simulink:Engine:NonTunableVarChangedMaxWarnings');
  
  % Simscape dynamics
  for block = blocksDyn
    blockPath = strcat(aircraft.info.name, "/model/",...
      aircraft.inertial.fidelity, block);
    for paramName = paramsDyn
      setRuntimeParams(blockPath, paramName)
    end
  end
  
  % Flight Control System
  for block = blocksFcs
    blockPath = strcat(aircraft.info.name, "/model/FCS/", block);
    for paramName = paramsFcs
      setRuntimeParams(blockPath, paramName)
    end
  end
  
  
else
  set_param(aircraft.info.name, 'FastRestart', 'off');
  fastRestartForLinearAnalysis(aircraft.info.name, 'off')
  warning('on', 'Simulink:Engine:NonTunableVarChangedInFastRestart');
  warning('on', 'Simulink:Engine:NonTunableVarChangedMaxWarnings');
  
  % Simscape dynamics
  for block = blocksDyn
    blockPath = strcat(aircraft.info.name, "/model/",...
      aircraft.inertial.fidelity, block);
    for paramName = paramsDyn
      setCompiletimeParams(blockPath, paramName)
    end
  end
  
  % Flight Control System
  for block = blocksFcs
    blockPath = strcat(aircraft.info.name, "/model/FCS/", block);
    for paramName = paramsFcs
      setCompiletimeParams(blockPath, paramName)
    end
  end
end


%% Set options flag
simul.solver.opts.fastRestart = fastRestart;

end

%% Auxiliary functions
function setRuntimeParams(blockPath, paramName)
try
  paramValue = get_param(blockPath, paramName);
  if contains(paramValue, 'simul.trim.')
    value = split(paramValue, '.');
    set_param(blockPath, paramName, value{end})
    try
      set_param(blockPath, strcat(paramName, "_conf"), 'runtime');
    catch
    end
  end
catch
end
end


function setCompiletimeParams(blockPath, paramName)
try
  paramValue = get_param(blockPath, paramName);
  if ~contains(paramValue, 'simul.trim.')
    set_param(blockPath, paramName, strcat('simul.trim.', paramValue))
    try
      set_param(blockPath, strcat(paramName, "_conf"), 'compiletime');
    catch
    end
  end
catch
end
end