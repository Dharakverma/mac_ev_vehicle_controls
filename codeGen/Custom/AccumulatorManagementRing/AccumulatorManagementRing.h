/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AccumulatorManagementRing.h
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

#ifndef RTW_HEADER_AccumulatorManagementRing_h_
#define RTW_HEADER_AccumulatorManagementRing_h_
#ifndef AccumulatorManagementRing_COMMON_INCLUDES_
# define AccumulatorManagementRing_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                          /* AccumulatorManagementRing_COMMON_INCLUDES_ */

#include "AccumulatorManagementRing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T MovingAverage_states[499];    /* '<S15>/MovingAverage' */
  real_T UnitDelay_DSTATE;             /* '<S16>/Unit Delay' */
  real_T MovingAverage_states_b[499];  /* '<S10>/MovingAverage' */
  real_T UnitDelay_DSTATE_a;           /* '<S11>/Unit Delay' */
  int32_T MovingAverage_circBuf;       /* '<S15>/MovingAverage' */
  int32_T MovingAverage_circBuf_j;     /* '<S10>/MovingAverage' */
  boolean_T UnitDelay_DSTATE_e;        /* '<Root>/Unit Delay' */
  uint8_T is_active_c3_AccumulatorManagementRing;/* '<Root>/ ModeSelection' */
  uint8_T is_c3_AccumulatorManagementRing;/* '<Root>/ ModeSelection' */
  uint8_T is_Shutdown;                 /* '<Root>/ ModeSelection' */
  uint8_T is_OPERATIONAL;              /* '<Root>/ ModeSelection' */
  uint8_T is_Startup;                  /* '<Root>/ ModeSelection' */
} DW_AccumulatorManagementRing_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  MSR_REQUEST MSR_ModeRequest;         /* '<Root>/MSR_ModeRequest' */
  boolean_T BmsFault;                  /* '<Root>/BmsFault' */
  boolean_T K1Precharge;               /* '<Root>/K1Precharge' */
  boolean_T K2HvPositive;              /* '<Root>/K2HvPositive' */
  boolean_T K3Negative;                /* '<Root>/K3Negative' */
  boolean_T RelayFault;                /* '<Root>/RelayFault' */
  uint8_T AMS_Level_Faults;            /* '<Root>/AMS_Level_Faults' */
  boolean_T AMS_HLIM;                  /* '<Root>/AMS_HLIM' */
  boolean_T AMS_LLIM;                  /* '<Root>/AMS_LLIM' */
  real_T AMS_SOC;                      /* '<Root>/AMS_SOC' */
  real_T AMS_Crnt;                     /* '<Root>/AMS_Crnt' */
  real_T AMS_ChgLmt;                   /* '<Root>/AMS_ChgLmt' */
  real_T AMS_DChgLmt;                  /* '<Root>/AMS_DChgLmt' */
  real_T AMS_Vltg;                     /* '<Root>/AMS_Vltg' */
  real_T AMS_Tmp;                      /* '<Root>/AMS_Tmp' */
  uint8_T AMS_Fault_Code;              /* '<Root>/AMS_Fault_Code' */
} ExtU_AccumulatorManagementRing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  RING_STATUS AMR_Status;              /* '<Root>/AMR_Status' */
  boolean_T AMS_Shutdown_Request;      /* '<Root>/AMS_Shutdown_Request' */
  real_T AMR_ContactorRequest;         /* '<Root>/AMR_ContactorRequest' */
  real_T AMR_ChargeLimit;              /* '<Root>/AMR_ChargeLimit' */
  real_T AMR_DischargeLimit;           /* '<Root>/AMR_DischargeLimit' */
  real_T AMS_Power;                    /* '<Root>/AMS_Power' */
} ExtY_AccumulatorManagementRing_T;

/* Real-time Model Data Structure */
struct tag_RTM_AccumulatorManagementRing_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_AccumulatorManagementRing_T AccumulatorManagementRing_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_AccumulatorManagementRing_T AccumulatorManagementRing_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_AccumulatorManagementRing_T AccumulatorManagementRing_Y;

/* Model entry point functions */
extern void AccumulatorManagementRing_initialize(void);
extern void AccumulatorManagementRing_step(void);
extern void AccumulatorManagementRing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AccumulatorManagementRing_T *const AccumulatorManagementRing_M;

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
 * '<Root>' : 'AccumulatorManagementRing'
 * '<S1>'   : 'AccumulatorManagementRing/ ModeSelection'
 * '<S2>'   : 'AccumulatorManagementRing/AMS Faults'
 * '<S3>'   : 'AccumulatorManagementRing/Compare To Constant'
 * '<S4>'   : 'AccumulatorManagementRing/Online Charge Limits'
 * '<S5>'   : 'AccumulatorManagementRing/AMS Faults/FaultCodeCheck'
 * '<S6>'   : 'AccumulatorManagementRing/AMS Faults/PowerViolationCheck '
 * '<S7>'   : 'AccumulatorManagementRing/AMS Faults/VoltageViolationCheck'
 * '<S8>'   : 'AccumulatorManagementRing/AMS Faults/PowerViolationCheck /Average'
 * '<S9>'   : 'AccumulatorManagementRing/AMS Faults/PowerViolationCheck /Continuous'
 * '<S10>'  : 'AccumulatorManagementRing/AMS Faults/PowerViolationCheck /Average/Moving Average1'
 * '<S11>'  : 'AccumulatorManagementRing/AMS Faults/PowerViolationCheck /Continuous/Discrete Timer1'
 * '<S12>'  : 'AccumulatorManagementRing/AMS Faults/PowerViolationCheck /Continuous/Discrete Timer1/Compare To Constant'
 * '<S13>'  : 'AccumulatorManagementRing/AMS Faults/VoltageViolationCheck/Average'
 * '<S14>'  : 'AccumulatorManagementRing/AMS Faults/VoltageViolationCheck/Continuous'
 * '<S15>'  : 'AccumulatorManagementRing/AMS Faults/VoltageViolationCheck/Average/Moving Average'
 * '<S16>'  : 'AccumulatorManagementRing/AMS Faults/VoltageViolationCheck/Continuous/Discrete Timer'
 * '<S17>'  : 'AccumulatorManagementRing/AMS Faults/VoltageViolationCheck/Continuous/Discrete Timer/Compare To Constant'
 */
#endif                             /* RTW_HEADER_AccumulatorManagementRing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
