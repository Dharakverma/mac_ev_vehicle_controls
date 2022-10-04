%% Bus Objects
load AmkSetpoints.mat
load AmkActualValues1.mat
load AmkActualValues2.mat
load TorqueLimits.mat
load TorqueRequests.mat

%% TMR Inputs
% 
%% TMR Outputs
% 

%% TMR Modes (input from MSR)
TMR.Mode.OFF = 0;
TMR.Mode.COMMUNICATION_CHECK = 1;
TMR.Mode.STARTUP = 2;
TMR.Mode.RUNNING = 3;
TMR.Mode.SHUTDOWN = 4;
%% TMR States (output)
TMR.TURNED_OFF = 0;
TMR.COMMUNICATION_PASS = 1;
TMR.CHECKING_COMMUNICATION = 2;
TMR.BEGIN_STARTUP = 3;
TMR.STARTUP_PASS = 4;
TMR.SPEED_CONTROL = 5;
TMR.FORWARD_TORQUE_CONTROL = 6;
TMR.BACKAWRD_TORQUE_CONTROL = 7;
TMR.BEGIN_SHUTDOWN = 8;
TMR.SHUTDOWN_PASS = 9;
%% TMR Control Modes
TMR.CONTROL_MODE.OFF = 0;
TMR.CONTROL_MODE.TORQUE_CONTROL = 1;
TMR.CONTROL_MODE.SPEED_CONTROL = 2;
%% Limiting Factor Parameters
TMR.LimitFactorOffset = 0.05;
TMR.MtrTempFullTrq = 125.0 + 273.15; % °K, ID 32798 - 11, Device-specific value. Motor temperature up to which full torque is available.
TMR.MtrTempNoTrq = 140.0 + 273.15; % °K, ID 32798 - 12, Device-specific value. Motor temperature at which no torque is available.
TMR.PwrSpplyTempFullTrq = 115.0 + 273.15; % °K, ID 32798 - 11, Device-specific value. Power supply temperature up to which full torque is available.
TMR.PwrSpplyTempNoTrq = 125.0 + 273.15; % °K, ID 32798 - 11, Device-specific value. Power supply temperature up to which no torque is available
TMR.ColdPlateTempFullTrq = 50.0 + 273.15; % °K, ID 32798 - 5, Device-specific value. Inverter temperature (cold plate) up to which full torque is available.
TMR.ColdPlateTempNoTrq = 60.0 + 273.15; % °K, ID 32798 - 6, Device-specific value. Inverter temperature (cold plate) up to which no torque is available.
TMR.HighBatteryVolt = 400; % VDC, BMS value, User-specific value, at least 5% below the maximum battery voltage. If oscillation occurs, a value > 5% must be selected.
TMR.MaxBatteryVolt = 720; % VDC, ID 32798 - 7, User-specific value, max value = 720
TMR.LowBatteryVolt = 250; % VDC, ID 32798 - 10, User-specific value, min value = 250
TMR.MinBatteryVolt = 100; % VDC, BMS value, User-specific value, at least 20% higher than the minimum battery voltage.
%% Motor and Inverter Current Overload Parameters
TMR.MtrPeakCurr = 100; % A, ID 109, Motor Peak Current
TMR.MtrNominalCurr = 41; %A, ID 111, Motor Nomial Current
TMR.MtrStandstillCurr = 20; %A ID 34096, limiting value at which the i2t monitoring starts to work.
TMR.MtrPeakCurrTime =  1.24; %s, ID 34168, Time at which the motor can run at Motor Peak Current
TMR.InvPeakCurr = 107.2; %A, ID 110, Inverter Peak Current 
TMR.InvNominalCurr = 43; %A, ID 112, Inverter Nominal Current
TMR.InvPeakCurrTime = 10; %s, ID 34195, Time at which the inverter can run at Inverter Peak Current (default value)
TMR.MtrI2t = ((TMR.MtrPeakCurr/TMR.MtrNominalCurr)^2 - 1)*TMR.MtrPeakCurrTime; % i2t motor current overload protection
TMR.InvI2t = ((TMR.InvPeakCurr/TMR.InvNominalCurr)^2 - 1)*TMR.InvPeakCurrTime; % i2t inverter current overload protection
TMR.MtrCurrOverloadThreshold = 0; % ID 114 (0-1, specifics when the derating occurs).
TMR.InvCurrOverloadThreshold = 0; % ID 32999 (0-1, specifics when the derating occurs)
TMR.ENDURANCE_MODE = 0;
%% Torque vs Speed Characteristic Curve Parameters
TMR.VoltageK = 18.8*2.1/(1000*0.104719755); % V/(rads/s) 
TMR.MtrPeakTrq =  21; % Nm
TMR.MtrNominalTrq = 9.8; %Nm
TMR.MinMtrSpd = 1e-7; % rad/s
%% TMR Error Parameters
TMR.MinStartupCount = 10; % Minimum number of attempts for the startup sequence.
%% TMR Error Bits

%% TMR Bus Objects