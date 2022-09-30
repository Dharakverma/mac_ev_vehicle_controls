%% MSR Variables
load MSR_SU_bus;
load MSR_SD_bus;
%% MSR -> TMR
MSR.AMK_RETRY_STARTUP = 10; %seconds
MSR.AMK_COMMUNICATION_WAIT = 10; %seconds
ModelSimTime = 0.001;