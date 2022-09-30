function setUpProject()
%setUpProject  Configure the environment for this project
%
%   Set up the environment for the current project. This function is set to
%   Run at Startup.

% Check for Matlab Version
if (~strcmp(version('-release'),'2020a'))
    msgbox('INCORRECT VERSION OF MATLAB, MUST USE MATLAB 2020A!','INVALID MATLAB VERSION','error');
    %TODO close project if incorrect version of MATLAB is used
end

% Modify code generation folder structure
cfg = Simulink.fileGenControl('getConfig');
cfg.CodeGenFolderStructure = 'TargetEnvironmentSubfolder';
Simulink.fileGenControl('setConfig', 'config', cfg);

% Use Simulink Project API to get the current project:
%p = slproject.getCurrentProject;

% CACHE FOLDER AND CODE GEN FOLDER SPECIFIED IN SIMULINK PROJECT DETAILS
% DO NOT NEED THIS CODE
% ----------------------------------------------------------------------
% % Get root path for the work directory
% projectRoot = p.RootFolder;
% % Set the location of cache (slprj) folder to be the "work" folder of the current project:
% myCacheFolder = fullfile(projectRoot, 'work');
% if ~exist(myCacheFolder, 'dir')
%     mkdir(myCacheFolder)
% end
% 
% % Set the file generation settings for 
% myCodeGenFolder = 'codeGen';
% Simulink.fileGenControl('set', 'CacheFolder', myCacheFolder, ...
%    'CodeGenFolder', myCodeGenFolder);