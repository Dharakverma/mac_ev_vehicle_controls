%Torque Vectoring inputs, outputs and parameters
% Inputs
% DriverThrottleInput
% steering angle
% velocity
% velocity - x direction, forward is positive
% accelerometer - x direction, forward is positive
% accelerometer - y direction, left side of the car is positive
% steering factor (sf), controls how much the car oversteers and understeers, range: [-10,10]
% Absolute values of the max/min torques for each motor

% Outputs
% Torque distribution based on weight transfer and vehicle stability (yaw rate error)

% Notes
% A counter-clockwise yaw rate is positive.
% Launch control would be used for when the vehicle is at rest.
% The outputs of the torque vectoring module are used for the traction
% control module.
% The traction control module checks if the wheel slip ratios are between
% [0.08,0.2].
% The traction control module adjusts the torque for each wheel to ensure
% stability.
load('MotorRPMs.mat');
%% VDR Modes (input from MSR)
VDR.Mode.OFF = 0;
VDR.Mode.STARTUP = 1;
VDR.Mode.DRIVING = 2;
VDR.Mode.SHUTDOWN = 3;

%% VDR Error Structs
VDR.ERROR.APPS.FAILURE = 1;
VDR.ERROR.APPS.OKAY = 0;

%% VDR Startup Status
VDR.UNTESTED = 0;
VDR.FAIL = 1;
VDR.PASS = 5;

%% Vehicle Parameteters
VDR.g = 9.81; % gravity, m/s^2
VDR.l = 1.525; % wheelbase length, units: m
VDR.d = (1270+1219.2)/2; % track width, units: m
VDR.M = 200; % vehicle's mass, units: kg
VDR.h_g = 0.254; % the height of the centre of mass from the ground, units: m
VDR.l_f = VDR.l/2; % distance between the centre of mass to the front axel, units: m
VDR.l_r = VDR.l/2; % distance between the centre of mass to the rear axel, units: m
VDR.p_f = 177/(205+177); % Front roll stiffness ratio: front/(front+rear)
VDR.p_r = 205/(205+177); % Rear roll stiffness ratio: rear/(front+rear)
VDR.Kt = 1; % Experimentally determined factor for the stable controller
VDR.Kp = 1;
%% Wheel Specific Stable Controller Gains
VDR.Kp_fl = 1; % Experimentally determined factor for the front-left unstable controller
VDR.Kp_fr = 1; % Experimentally determined factor for the front-right unstable controller
VDR.Kp_rl = 1; % Experimentally determined factor for the rear-left unstable controller
VDR.Kp_rr = 1; % Experimentally determined factor for the rear-right unstable controller
%% VDR States (output)
VDR.OFF = 0;
VDR.STARTUP = 1;
VDR.DRIVING = 2;
VDR.SHUTDOWN = 3;
%% TMR Control Modes
VDR.DRIVING_MODE.OFF = 0;
VDR.DRIVING_MODE.TV = 1;
VDR.DRIVING_MODE.CONVENTIONAL = 2;
VDR.TV_MODE.STABLE = 0;
VDR.TV_MODE.UNSTABLE = 1;
VDR.DRIVETRAIN.RWD = 0;
VDR.DRIVETRAIN.FWD = 1;
VDR.DRIVETRAIN.AWD = 2;
%% Sensor Diagnostics Parameters
VDR.MaxSteerAngle = 270;
VDR.MinAccelX = 0.1;
VDR.MinAccelY = 0.1;
VDR.MinVelocityX = 0.1;
VDR.MinVelocity = 0.1;
VDR.MaxAccelX = 50;
VDR.MaxAccelY = 50;
VDR.EncoderTol = 1;

%VDR_SampleTime = str2double(get_param('VDR','FixedStep'));
VDR_SampleTime = 0.01;
VDR.EncoderTorqueCounter = 5/VDR_SampleTime;
VDR.AccelTorqueCounter = 5/VDR_SampleTime;
