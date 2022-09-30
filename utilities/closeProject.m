function closeProject()
% closeProject  Reset the environment settings for this project
%
%   Set up the environment for the current project. This function is set to
%   Run at Startup.

% Use Simulink Project API to get the current project:

% Reset file generation settings
Simulink.fileGenControl('reset');