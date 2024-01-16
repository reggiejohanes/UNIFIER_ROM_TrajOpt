function simul = simTime(aircraft, simul, T)
% Launch time domain simulation
%		Executes the Simulink/Simscape file and performs a flight simulation
%   with the currently loaded Flight Mechanics Model. The gathers and
%   processes output.
%
% INPUTS ------------------------------------------------------------------
%		aircraft: aircraft model, struct
%		simul: simulation data model, struct
%   T: total time of the simulation, s
%
% OUTPUTS -----------------------------------------------------------------
%		simul: simulation data model, struct
%
% EXAMPLES-----------------------------------------------------------------
%   simul = simTime(aircraft, simul, 20);
%
% NOTES -------------------------------------------------------------------
%
%
% See also: SIMPILOTED, SETPILOTINPUT_DEFAULT
%
% CREATED BY -------------------------------------------------------------
%		Carmine Varriale (C.Varriale@tudelft.nl)
%		PhD Candidate
%		Flight Performance and Propulsion Group
%		Faculty of Aerospace Engineering
%		Delft University of Technology
%
% TRACKING
%   Date of creation:   16-Apr-2019
%   Date of last edit:  05-Aug-2019
%
% ========================================================================

%% Attempt simulation
try
  openFmmModel(aircraft)
  
  set_param(aircraft.info.name,...
    'StartTime', '0',...
    'StopTime', num2str(T));
  
  if simul.solver.opts.fastRestart
    % Extract trim values to current workspace
    for v = ["Xe", "Ye", "Ze", "Ue", "Ve", "We",...
        "psi", "psiDot", "theta", "thetaDot", "phi", "phiDot", ...
        "delta"]
      try
        eval(strcat(v, " = simul.trim.", v, ";"));
      catch
      end
    end
    clear v
  end
  
  simOut = sim(aircraft.info.name, 'SrcWorkspace', 'current');
  simul.timeHist = simOut;
  
  
%% Deal with crash or divergence
catch err
  
  switch err.identifier
    case 'Simulink:Engine:DerivNotFinite'
      tErr = extractBetween(err.message, 'at time ', ' is not finite');
      fprintf(['Some derivative is not finite at time ', tErr{1}]);
      fprintf(newline);
      fprintf(err.message);
      fprintf(newline);
      fprintf('Relaunching simulation. Stopping before the critical event\n')
      simul = simTime(aircraft, simul,...
        max([0, str2double(tErr{1})-simul.solver.dt]));
      
    otherwise
      rethrow(err)
      
  end
end



end

% ========================================================================
%
% Copyright (c) 2019 Carmine Varriale
%
% This code is subject to a Non-Disclosure Agreement.
% You have received a temporary copy of the code for non-commercial,
% educational purposes only.
%
% This code and information are provided "as is" without warranty of any
% kind, either expressed or implied, including but not limited to the
% implied warranties of merchantability and/or fitness for a particular
% purpose.
% ========================================================================
%
% EOF