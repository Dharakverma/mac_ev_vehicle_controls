/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BatteryManagementRing.h
 *
 * Code generated for Simulink model 'BatteryManagementRing'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Mar 27 18:04:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BatteryManagementRing_h_
#define RTW_HEADER_BatteryManagementRing_h_
#ifndef BatteryManagementRing_COMMON_INCLUDES_
# define BatteryManagementRing_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                              /* BatteryManagementRing_COMMON_INCLUDES_ */

#include "BatteryManagementRing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T LowPassFilter_states[20];     /* '<S3>/LowPassFilter' */
  int32_T LowPassFilter_circBuf;       /* '<S3>/LowPassFilter' */
  uint8_T is_active_c4_BatteryManagementR;/* '<Root>/Diagnostics' */
  uint8_T is_c4_BatteryManagementRing; /* '<Root>/Diagnostics' */
  uint8_T is_OPERATIONAL;              /* '<Root>/Diagnostics' */
  uint8_T is_RUNNING;                  /* '<Root>/Diagnostics' */
  uint8_T is_STARTUP;                  /* '<Root>/Diagnostics' */
  uint8_T temporalCounter_i1;          /* '<Root>/Diagnostics' */
} DW_BatteryManagementRing_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: BMR.Batt.SOC.SOC
   * Referenced by: '<S3>/Vltg2SOC'
   */
  real_T Vltg2SOC_tableData[15];

  /* Expression: BMR.Batt.SOC.Voltage
   * Referenced by: '<S3>/Vltg2SOC'
   */
  real_T Vltg2SOC_bp01Data[15];

  /* Expression: [20:-1:0]/sum([20:-1:0])
   * Referenced by: '<S3>/LowPassFilter'
   */
  real_T LowPassFilter_Coefficients[21];
} ConstP_BatteryManagementRing_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  MSR_REQUEST MSR_ModeRequest;         /* '<Root>/MSR_ModeRequest' */
  real_T BMS_BattVoltage;              /* '<Root>/BMS_BattVoltage' */
} ExtU_BatteryManagementRing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  RING_STATUS BMR_Status;              /* '<Root>/BMR_Status' */
  BatteryFaults BmrFaults;             /* '<Root>/BmrFaults' */
  real_T BMR_BattVoltage;              /* '<Root>/BMR_BattVoltage' */
  real_T BMR_BattSOC;                  /* '<Root>/BMR_BattSOC' */
} ExtY_BatteryManagementRing_T;

/* Real-time Model Data Structure */
struct tag_RTM_BatteryManagementRing_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_BatteryManagementRing_T BatteryManagementRing_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_BatteryManagementRing_T BatteryManagementRing_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BatteryManagementRing_T BatteryManagementRing_Y;

/* Constant parameters (default storage) */
extern const ConstP_BatteryManagementRing_T BatteryManagementRing_ConstP;

/* Model entry point functions */
extern void BatteryManagementRing_initialize(void);
extern void BatteryManagementRing_step(void);
extern void BatteryManagementRing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BatteryManagementRin_T *const BatteryManagementRing_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BatteryManagementRing'
 * '<S1>'   : 'BatteryManagementRing/BatteryFaults'
 * '<S2>'   : 'BatteryManagementRing/Diagnostics'
 * '<S3>'   : 'BatteryManagementRing/SOCEstimation'
 * '<S4>'   : 'BatteryManagementRing/BatteryFaults/Compare To Constant'
 * '<S5>'   : 'BatteryManagementRing/BatteryFaults/Compare To Constant1'
 * '<S6>'   : 'BatteryManagementRing/BatteryFaults/Compare To Constant2'
 * '<S7>'   : 'BatteryManagementRing/BatteryFaults/Compare To Constant3'
 */
#endif                                 /* RTW_HEADER_BatteryManagementRing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
