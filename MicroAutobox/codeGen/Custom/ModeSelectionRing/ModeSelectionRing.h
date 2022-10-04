/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ModeSelectionRing.h
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

#ifndef RTW_HEADER_ModeSelectionRing_h_
#define RTW_HEADER_ModeSelectionRing_h_
#ifndef ModeSelectionRing_COMMON_INCLUDES_
# define ModeSelectionRing_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ModeSelectionRing_COMMON_INCLUDES_ */

#include "ModeSelectionRing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<Root>/ModeSelectionRing' */
  uint16_T temporalCounter_i2;         /* '<Root>/ModeSelectionRing' */
  uint8_T tp_STARTUP;                  /* '<Root>/ModeSelectionRing' */
  uint8_T is_active_c2_ModeSelectionRing;/* '<Root>/ModeSelectionRing' */
  uint8_T is_c2_ModeSelectionRing;     /* '<Root>/ModeSelectionRing' */
  uint8_T is_OPERATION;                /* '<Root>/ModeSelectionRing' */
  uint8_T is_STARTUP;                  /* '<Root>/ModeSelectionRing' */
  uint8_T is_HIGH_VOLTAGE;             /* '<Root>/ModeSelectionRing' */
  uint8_T is_ACCUMULATOR_HV_STARTUP;   /* '<Root>/ModeSelectionRing' */
  uint8_T is_MOTORS_HV_STARTUP;        /* '<Root>/ModeSelectionRing' */
  uint8_T is_VEHICLE_DYNAMICS_STARTUP; /* '<Root>/ModeSelectionRing' */
  uint8_T is_COOLING_STARTUP;          /* '<Root>/ModeSelectionRing' */
  uint8_T is_MOTORS_LV_STARTUP;        /* '<Root>/ModeSelectionRing' */
  uint8_T is_SYSTEM_MODE_SELECTION;    /* '<Root>/ModeSelectionRing' */
  uint8_T is_SHUTDOWN;                 /* '<Root>/ModeSelectionRing' */
  uint8_T is_VEHICLE_DYNAMICS_SHUTDOWN;/* '<Root>/ModeSelectionRing' */
  uint8_T is_MOTORS_HV_SHUTDOWN;       /* '<Root>/ModeSelectionRing' */
  uint8_T is_active_MOTORS_HV_SHUTDOWN;/* '<Root>/ModeSelectionRing' */
  uint8_T is_ACCUMULATOR_HV_STARTUP_b; /* '<Root>/ModeSelectionRing' */
  uint8_T is_active_ACCUMULATOR_HV_STARTU;/* '<Root>/ModeSelectionRing' */
  uint8_T is_COOLING_SHUTDOWN;         /* '<Root>/ModeSelectionRing' */
  boolean_T internalShutdown;          /* '<Root>/ModeSelectionRing' */
  boolean_T motorLvStartupFail;        /* '<Root>/ModeSelectionRing' */
  boolean_T motorLvStartupPass;        /* '<Root>/ModeSelectionRing' */
  boolean_T vehicleDynamicsStartupPass;/* '<Root>/ModeSelectionRing' */
  boolean_T vehicleDynamicsStartupFail;/* '<Root>/ModeSelectionRing' */
  boolean_T coolingStartupFail;        /* '<Root>/ModeSelectionRing' */
  boolean_T coolingStartupPass;        /* '<Root>/ModeSelectionRing' */
  boolean_T accumulatorHvStartupFail;  /* '<Root>/ModeSelectionRing' */
  boolean_T motorHvStartupFail;        /* '<Root>/ModeSelectionRing' */
  boolean_T motorHvStartupPass;        /* '<Root>/ModeSelectionRing' */
  boolean_T vehicleReady;              /* '<Root>/ModeSelectionRing' */
  boolean_T accumulatorHvStartupPass;  /* '<Root>/ModeSelectionRing' */
  boolean_T motorHvShutdownPass;       /* '<Root>/ModeSelectionRing' */
  boolean_T motorHvShutdownFail;       /* '<Root>/ModeSelectionRing' */
  boolean_T coolingShutdownPass;       /* '<Root>/ModeSelectionRing' */
  boolean_T coolingShutdownFail;       /* '<Root>/ModeSelectionRing' */
  boolean_T accumulatorHvShutdownFail; /* '<Root>/ModeSelectionRing' */
  boolean_T vehicleDynamicsShutdownFail;/* '<Root>/ModeSelectionRing' */
  boolean_T vehicleDynamicsShutdownPass;/* '<Root>/ModeSelectionRing' */
  boolean_T accumulatorHvShutdownPass; /* '<Root>/ModeSelectionRing' */
} DW_ModeSelectionRing_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  RING_STATUS AmrStatus;               /* '<Root>/AmrStatus' */
  RING_STATUS TmrStatus;               /* '<Root>/TmrStatus' */
  RING_STATUS VdrStatus;               /* '<Root>/VdrStatus' */
  RING_STATUS CcrStatus;               /* '<Root>/CcrStatus' */
  DRIVER_BUTTON DriverButton;          /* '<Root>/DriverButton' */
  real_T Brakes;                       /* '<Root>/Brakes [%]' */
  boolean_T AmrError;                  /* '<Root>/AmrError' */
  boolean_T TmrError;                  /* '<Root>/TmrError' */
} ExtU_ModeSelectionRing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  MSR_REQUEST AMR_ModeRequest;         /* '<Root>/AMR_ModeRequest' */
  MSR_REQUEST TMR_ModeRequest;         /* '<Root>/TMR_ModeRequest' */
  MSR_REQUEST VDR_ModeRequest;         /* '<Root>/VDR_ModeRequest' */
  MSR_REQUEST CcrModeReuqest;          /* '<Root>/CcrModeReuqest' */
  MSR_States MSR_leaf_state1;          /* '<Root>/MSR_leaf_state1' */
  boolean_T RTDS;                      /* '<Root>/RTDS' */
  VEHICLE_STATUS VehicleStatus;        /* '<Root>/VehicleStatus' */
} ExtY_ModeSelectionRing_T;

/* Real-time Model Data Structure */
struct tag_RTM_ModeSelectionRing_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_ModeSelectionRing_T ModeSelectionRing_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ModeSelectionRing_T ModeSelectionRing_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ModeSelectionRing_T ModeSelectionRing_Y;

/* Model entry point functions */
extern void ModeSelectionRing_initialize(void);
extern void ModeSelectionRing_step(void);
extern void ModeSelectionRing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ModeSelectionRing_T *const ModeSelectionRing_M;

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
 * '<Root>' : 'ModeSelectionRing'
 * '<S1>'   : 'ModeSelectionRing/BrakesFullyEngagedCheck'
 * '<S2>'   : 'ModeSelectionRing/ModeSelectionRing'
 */
#endif                                 /* RTW_HEADER_ModeSelectionRing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
