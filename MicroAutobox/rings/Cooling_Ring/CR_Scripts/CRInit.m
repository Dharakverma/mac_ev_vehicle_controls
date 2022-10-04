%--------Mode Requests--------
CR.ModeRequest.Shutdown = 0;
CR.ModeRequest.Startup = 1;
CR.ModeRequest.NormalOperation = 2;
CR.ModeRequest.LVPowerSave = 3;

%--------Status--------
CR.State.Startup_Pass = 0;
CR.State.Running = 1;
CR.State.Running_LV = 2;
CR.State.ShutdownComplete = 3;
CR.State.Off = 10;

%--------Errors--------
CR.ERROR.PASS = 0;
CR.ERROR.FAILURE = 1;

%--------Normal STATE--------
%motor logic constants
CR.motor_maxMotorInputTempNormal = 30;
CR.motor_maxRadiatorOutputTempNormal = 30;
CR.motor_maxPumpInputTempNormal = 30;
CR.motor_maxVehicleSpeedForFansNormal = 10;
%inverter logic constants
CR.inverter_maxVehicleSpeedForFansNormal = 10;

%--------Low Voltage STATE--------
%motor logic constants (Low Voltage)
CR.motor_maxMotorInputTempLV = 35;
CR.motor_maxRadiatorOutputTempLV = 35;
CR.motor_maxPumpInputTempLV = 35;
CR.motor_maxVehicleSpeedForFansLV = 10;
CR.motor_pump_saturation_LV = 0.8;
CR.motor_fan_saturation_LV = 0.8;
%inverter logic constants (Low Voltage)
CR.inverter_maxVehicleSpeedForFansLV = 8;
CR.inverter_pump_saturation_LV = 0.8;
CR.inverter_fan_saturation_LV = 0.8;

%--------Testing STATE--------
%testing PWM values
CR.Motor_Testing_PWM_Pump=0.7;
CR.Motor_Testing_PWM_Fans=0.7;
CR.Inverter_Testing_PWM_Pump=0.7;
CR.Inverter_Testing_PWM_Fans=0.7;
%sensor sanity ranges (min and max values before sensor value is malfunctioning)
CR.motor_temp_min = 0;
CR.motor_temp_max = 100;
CR.velocity_min = -50;
CR.velocity_max = 200;
CR.inverter_cooling_plate_min = 0;
CR.inverter_cooling_plate_max = 100;
CR.inverter_fluid_temp_min = 0;
CR.inverter_fluid_temp_max = 100;
CR.motor_loop_pressure_startup_min = 13.5;
CR.motor_loop_pressure_min = 10.5;
CR.motor_loop_pressure_max = 25.5;
CR.motor_fluid_temp_min = 0;
CR.motor_fluid_temp_max = 100;
CR.inverter_loop_pressure_startup_min = 13.5;
CR.inverter_loop_pressure_min = 10.5;
CR.inverter_loop_pressure_max = 25.5;