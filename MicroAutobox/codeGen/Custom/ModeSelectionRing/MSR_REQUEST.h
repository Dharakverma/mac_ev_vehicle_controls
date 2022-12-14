/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MSR_REQUEST.h
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

#ifndef RTW_HEADER_MSR_REQUEST_h_
#define RTW_HEADER_MSR_REQUEST_h_
#include "rtwtypes.h"

/* Mode request made by the MSR for the other control rings. */
typedef enum {
  MSR_REQUEST_OFF = 0,                 /* Default value */
  MSR_REQUEST_STARTUP_LV,
  MSR_REQUEST_STARTUP_HV,
  MSR_REQUEST_RUNNING,
  MSR_REQUEST_SHUTDOWN_LV,
  MSR_REQUEST_SHUTDOWN_HV
} MSR_REQUEST;

#endif                                 /* RTW_HEADER_MSR_REQUEST_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
