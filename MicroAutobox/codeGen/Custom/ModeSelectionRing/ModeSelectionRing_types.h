/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ModeSelectionRing_types.h
 *
 * Code generated for Simulink model 'ModeSelectionRing'.
 *
 * Model version                  : 1.233
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Nov  1 13:03:36 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ModeSelectionRing_types_h_
#define RTW_HEADER_ModeSelectionRing_types_h_
#include "rtwtypes.h"
#include "RING_STATUS.h"
#include "MSR_REQUEST.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_DRIVER_BUTTON_
#define DEFINED_TYPEDEF_FOR_DRIVER_BUTTON_

/* enumeration to track the last passed startup state of the MSR */
typedef enum {
  DRIVER_BUTTON_OFF = 0,               /* Default value */
  DRIVER_BUTTON_ON,
  DRIVER_BUTTON_SHUTDOWN
} DRIVER_BUTTON;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MSR_States_
#define DEFINED_TYPEDEF_FOR_MSR_States_

typedef enum {
  MSR_States_None = 0,                 /* Default value */
  MSR_States_COOLING_REQUEST_STARTUP,
  MSR_States_COOLING_STARTUP_PASS,
  MSR_States_COOLING_STARTUP_FAIL,
  MSR_States_MOTORS_LV_REQUEST_STARTUP,
  MSR_States_MOTORS_LV_STARTUP_PASS,
  MSR_States_MOTORS_LV_STARTUP_FAIL,
  MSR_States_LOW_VOLTAGE_STARTUP_FAIL,
  MSR_States_WAITING_FOR_RTD_AND_BRAKES,
  MSR_States_ACCUMULATOR_HV_REQUEST_STARTUP,
  MSR_States_ACCUMULATOR_HV_STARTUP_PASS,
  MSR_States_ACCUMULATOR_HV_STARTUP_FAIL,
  MSR_States_MOTORS_HV_REQUEST_STARTUP,
  MSR_States_MOTORS_HV_STARTUP_PASS,
  MSR_States_MOTORS_HV_STARTUP_FAIL,
  MSR_States_VEHICLE_DYANMICS_REQUEST_STARTUP,
  MSR_States_VEHICLE_DYANMICS_STARTUP_PASS,
  MSR_States_VEHICLE_DYANMICS_STARTUP_FAIL,
  MSR_States_ReadyToDriveSoundStart,
  MSR_States_ReadyToDriveSoundEnd,
  MSR_States_HIGH_VOLTAGE_STARTUP_FAIL,
  MSR_States_WAITING_FOR_RTD_AND_BRAKES1,
  MSR_States_NORMAL,
  MSR_States_SAFE,
  MSR_States_SHUTDOWN_BEGIN,
  MSR_States_LOW_POWER,
  MSR_States_VEHICLE_DYANMICS_REQUEST_SHUTDOWN,
  MSR_States_VEHICLE_DYANMICS_SHUTDOWN_PASS,
  MSR_States_VEHICLE_DYANMICS_SHUTDOWN_FAIL,
  MSR_States_TRACTIVE_SYSTEM_SHUTDOWN,
  MSR_States_COOLING_REQUEST_SHUTDOWN,
  MSR_States_COOLING_SHUTDOWN_PASS,
  MSR_States_COOLING_SHUTDOWN_FAIL,
  MSR_States_ShutdownComplete,
  MSR_States_SHUTDOWN_FAIL
} MSR_States;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VEHICLE_STATUS_
#define DEFINED_TYPEDEF_FOR_VEHICLE_STATUS_

/* enumeration to track the last passed startup state of the MSR */
typedef enum {
  VEHICLE_STATUS_LOCK = 0,             /* Default value */
  VEHICLE_STATUS_ACCESSORY,
  VEHICLE_STATUS_ON,
  VEHICLE_STATUS_SHUTDOWN
} VEHICLE_STATUS;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ModeSelectionRing_T RT_MODEL_ModeSelectionRing_T;

#endif                               /* RTW_HEADER_ModeSelectionRing_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
