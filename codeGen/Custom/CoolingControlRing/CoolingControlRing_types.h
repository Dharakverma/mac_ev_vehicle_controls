/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CoolingControlRing_types.h
 *
 * Code generated for Simulink model 'CoolingControlRing'.
 *
 * Model version                  : 1.114
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Mar 20 20:09:03 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CoolingControlRing_types_h_
#define RTW_HEADER_CoolingControlRing_types_h_
#include "rtwtypes.h"
#include "MSR_REQUEST.h"
#include "RING_STATUS.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_wW26LiCn4yRVu099zb8nMG_
#define DEFINED_TYPEDEF_FOR_struct_wW26LiCn4yRVu099zb8nMG_

typedef struct {
  real_T Shutdown;
  real_T Startup;
  real_T NormalOperation;
  real_T LVPowerSave;
} struct_wW26LiCn4yRVu099zb8nMG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4ncLsmg3tP22dF8aZ5mNs_
#define DEFINED_TYPEDEF_FOR_struct_4ncLsmg3tP22dF8aZ5mNs_

typedef struct {
  real_T Startup_Pass;
  real_T Running;
  real_T Running_LV;
  real_T ShutdownComplete;
  real_T Off;
} struct_4ncLsmg3tP22dF8aZ5mNs;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SzSk5NfKHW6Co9DIMaAw6E_
#define DEFINED_TYPEDEF_FOR_struct_SzSk5NfKHW6Co9DIMaAw6E_

typedef struct {
  real_T PASS;
  real_T FAILURE;
} struct_SzSk5NfKHW6Co9DIMaAw6E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mbrgHN73zkKQ18Ge0x92RE_
#define DEFINED_TYPEDEF_FOR_struct_mbrgHN73zkKQ18Ge0x92RE_

typedef struct {
  struct_wW26LiCn4yRVu099zb8nMG ModeRequest;
  struct_4ncLsmg3tP22dF8aZ5mNs State;
  struct_SzSk5NfKHW6Co9DIMaAw6E ERROR;
  real_T motor_maxMotorInputTempNormal;
  real_T motor_maxRadiatorOutputTempNormal;
  real_T motor_maxPumpInputTempNormal;
  real_T motor_maxVehicleSpeedForFansNormal;
  real_T inverter_maxVehicleSpeedForFansNormal;
  real_T motor_maxMotorInputTempLV;
  real_T motor_maxRadiatorOutputTempLV;
  real_T motor_maxPumpInputTempLV;
  real_T motor_maxVehicleSpeedForFansLV;
  real_T motor_pump_saturation_LV;
  real_T motor_fan_saturation_LV;
  real_T inverter_maxVehicleSpeedForFansLV;
  real_T inverter_pump_saturation_LV;
  real_T inverter_fan_saturation_LV;
  real_T Motor_Testing_PWM_Pump;
  real_T Motor_Testing_PWM_Fans;
  real_T Inverter_Testing_PWM_Pump;
  real_T Inverter_Testing_PWM_Fans;
  real_T motor_temp_min;
  real_T motor_temp_max;
  real_T velocity_min;
  real_T velocity_max;
  real_T inverter_cooling_plate_min;
  real_T inverter_cooling_plate_max;
  real_T inverter_fluid_temp_min;
  real_T inverter_fluid_temp_max;
  real_T motor_loop_pressure_startup_min;
  real_T motor_loop_pressure_min;
  real_T motor_loop_pressure_max;
  real_T motor_fluid_temp_min;
  real_T motor_fluid_temp_max;
  real_T inverter_loop_pressure_startup_min;
  real_T inverter_loop_pressure_min;
  real_T inverter_loop_pressure_max;
} struct_mbrgHN73zkKQ18Ge0x92RE;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_CoolingControlRing_T RT_MODEL_CoolingControlRing_T;

#endif                              /* RTW_HEADER_CoolingControlRing_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
