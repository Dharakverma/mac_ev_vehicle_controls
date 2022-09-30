%% Bus Initialization
load AMRBus
load AccumulatorFaults

%% Accumulator Variables
Accumulator.Cell.Qfull = 13*3600;  %C
Accumulator.Cell.CrntLmt.Chrg = 15 * Accumulator.Cell.Qfull/3600; %A
Accumulator.Cell.CrntLmt.Dschrg = 3 * Accumulator.Cell.Qfull/3600; %A

%% AMR Variables
AMR.SimTime = 0.001;         %s = MFE.SimTime;
Ts = AMR.SimTime; 

% Moving Average
AMR.Lmt.MaxVoltage = 600;               %V
AMR.Lmt.MaxPwr = 80000;                 %W
AMR.Lmt.Tcont = 0.1;                    %s
AMR.Lmt.Tavg = 0.5;                     %s

AMR.Cells.NoSeries = 138;

% AMS Tuning
AMR.Accumulator.Capacity = Accumulator.Cell.Qfull;
AMR.VChgPt = 3.6 * AMR.Cells.NoSeries;
AMR.VDChgPt = 3.4 * AMR.Cells.NoSeries; 
% Accumulator Limits
AMR.Lmt.TChgMin = 0;
AMR.Lmt.TChgLow = 20; 
AMR.Lmt.TChgHi = 80;
AMR.Lmt.TChgMax = 100; 
AMR.Lmt.VPackHigh = 570;
AMR.Lmt.VPackMax = 600; 
AMR.Lmt.VCellHigh = AMR.Lmt.VPackHigh / AMR.Cells.NoSeries;
AMR.Lmt.VCellMax = AMR.Lmt.VPackMax / AMR.Cells.NoSeries; 
AMR.Lmt.VPackLow = 350;
AMR.Lmt.VPackMin = 300; 
AMR.Lmt.VCellLow = AMR.Lmt.VPackLow /AMR.Cells.NoSeries;
AMR.Lmt.VCellMin = AMR.Lmt.VPackMin / AMR.Cells.NoSeries; 

% CAN
AMR.CAN.Timeout.t = 1;
AMR.CAN.MinHealth = 5;
AMR.CAN.MaxHealth = 10;

% Plausibility
AMR.Plausibility.PowerDiffRel = 30;     % [~``%]
AMR.Plausibility.PowerDiffAbs = 5000;   % W

% Precharge and ContaChgctor
AMR.Precharge.Time = 3; 


%AMR.Lmt.MovAvg.NoCoeff = AMR.Lmt.MovAvg.t / AMR.SimTime;
%AMR.Lmt.MovAvg.Coeff = ones(1, AMR.Lmt.MovAvg.NoCoeff) / AMR.Lmt.MovAvg.NoCoeff;

%% AMR State Acitivites
AMR.State.Off = 0;
AMR.State.Off_Pass = 9;
AMR.State.Startup_RqstPrechg = 10;
AMR.State.Startup_Prechg = 11; 
AMR.State.Startup_Pass = 19; 
AMR.State.Running = 20; 
AMR.State.Running_Fail = 29;
AMR.State.Shutdown_InProgress = 30;
AMR.State.Shutdown_Complete = 39;

%% AMR Mode Requests from MSR
AMR.ModeRequest.Off = AMR.State.Off;  
AMR.ModeRequest.Startup = AMR.State.Startup_RqstPrechg;
AMR.ModeRequest.Run = AMR.State.Running;
AMR.ModeRequest.Shutdown = AMR.State.Shutdown_InProgress;
AMR.Off_Pass = 0;
AMR.Startup_Pass = 1;
AMR.Shutdown_Complete = 2;

%% Notes

%ContactorRqt => 1 = Closed, 0 = Open
