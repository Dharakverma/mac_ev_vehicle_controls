/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AccumulatorManagementRing_types.h
 *
 * Code generated for Simulink model 'AccumulatorManagementRing'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Mar 20 13:39:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AccumulatorManagementRing_types_h_
#define RTW_HEADER_AccumulatorManagementRing_types_h_
#include "rtwtypes.h"
#include "RING_STATUS.h"
#include "MSR_REQUEST.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_AMR_leaf_states_
#define DEFINED_TYPEDEF_FOR_AMR_leaf_states_

typedef enum {
  AMR_leaf_states_None = 0,            /* Default value */
  AMR_leaf_states_Off,
  AMR_leaf_states_RqstPrechg,
  AMR_leaf_states_HVPrechg,
  AMR_leaf_states_HVComplete,
  AMR_leaf_states_Running,
  AMR_leaf_states_ShutdownInProgress,
  AMR_leaf_states_ShutdownComplete
} AMR_leaf_states;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_AccumulatorManagementRing_T
  RT_MODEL_AccumulatorManagementRing_T;

#endif                       /* RTW_HEADER_AccumulatorManagementRing_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
