/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RING_STATUS.h
 *
 * Code generated for Simulink model 'Tractive_Motor_Ring_Single_Motor'.
 *
 * Model version                  : 1.96
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Mar 20 10:54:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RING_STATUS_h_
#define RTW_HEADER_RING_STATUS_h_
#include "rtwtypes.h"

/* Specifies the operating mode for a control ring. */
typedef enum {
  RING_STATUS_OFF = 0,                 /* Default value */
  RING_STATUS_STARTUP_IN_PROGRESS_LV,
  RING_STATUS_STARTUP_COMPLETE_LV,
  RING_STATUS_STARTUP_IN_PROGRESS_HV,
  RING_STATUS_STARTUP_COMPLETE_HV,
  RING_STATUS_RUNNING,
  RING_STATUS_SHUTDOWN_IN_PROGRESS_LV,
  RING_STATUS_SHUTDOWN_COMPLETE_LV,
  RING_STATUS_SHUTDOWN_IN_PROGRESS_HV,
  RING_STATUS_SHUTDOWN_COMPLETE_HV
} RING_STATUS;

#endif                                 /* RTW_HEADER_RING_STATUS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
