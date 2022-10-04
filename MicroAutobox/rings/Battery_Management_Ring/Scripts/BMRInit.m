%% BMR Variables
load BatteryFaults.mat
BMR.AuxilaryLoads = 0;

%% Battery Characteristics
BMR.Batt.Capacity = 25 * 3600; %C
BMR.Batt.Impedance = 0.1; %Ohm

%% LV Permissible Voltages
BMR.Startup.MinVoltage = 13;
BMR.Startup.MinSOC = 0.5;
BMR.Running.MinVoltage = 12;
BMR.Running.MinSOC = 0.2;
BMR.Running.MaxDchrgCrnt = 2 * BMR.Batt.Capacity / 3600; %A

%% Battery SOC Estimation
BMR.Batt.SOC.ChrgCrnt = 0.2 * BMR.Batt.Capacity/3600; %A - charge conditions where SOC-V was tested 
BMR.Batt.SOC.Voltage = [11.62222222	12.42222222	12.86666667	13.06666667	13.22222222	13.4	13.62222222	13.77777778	13.84444444	14.04444444	14.33333333	14.95555556	15.15555556	15.2 15.3] - BMR.Batt.SOC.ChrgCrnt * BMR.Batt.Impedance;
BMR.Batt.SOC.SOC = 0.01 * [-2.468655617	-1.837495396	-0.543941068	1.76854512	5.556095764	14.37406998	40.01532228	60.51005525	69.23668508	81.75911602	86.95572744	91.23300184	93.67808471	96.71130755 100]; 
BMR.Batt.SOC.HiCrntThrshld = BMR.Batt.Capacity * 0.05; %20% c-rate
BMR.Batt.SOC.InitSOC = 1; % First guess of initial SOC is 100%

%% BMR Mode Acitivites
BMR.State.OFF = 0;
BMR.State.OFF_PASS = 9;
BMR.State.STARTUP_INPROGRESS = 10; 
BMR.State.STARTUP_LOWENERGY = 11; 
BMR.State.STARTUP_PASS = 19; 
BMR.State.RUNNING = 20; 
BMR.State.RUNNING_PWRSAVE = 25; 
BMR.State.RUNNING_FAIL = 29;
BMR.State.SHUTDOWN_INPROGRESS = 30;
BMR.State.SHUTDOWN_COMPLETE = 39;

%% BMR Mode Requests from MSR
BMR.ModeRequest.OFF = 0;  
BMR.ModeRequest.STARTUP = 1;
BMR.ModeRequest.RUN = 2;
BMR.ModeRequest.SHUTDOWN = 3;

%% BMR Error Valid Range Checks
BMR.Undervoltage = 5;
BMR.Overrvoltage = 18;
BMR.Under_SOC = -0.5;
BMR.Over_SOC = 1.5;
