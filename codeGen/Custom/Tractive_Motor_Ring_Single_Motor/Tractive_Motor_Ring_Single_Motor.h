/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tractive_Motor_Ring_Single_Motor.h
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

#ifndef RTW_HEADER_Tractive_Motor_Ring_Single_Motor_h_
#define RTW_HEADER_Tractive_Motor_Ring_Single_Motor_h_
#include <math.h>
#ifndef Tractive_Motor_Ring_Single_Motor_COMMON_INCLUDES_
# define Tractive_Motor_Ring_Single_Motor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                   /* Tractive_Motor_Ring_Single_Motor_COMMON_INCLUDES_ */

#include "Tractive_Motor_Ring_Single_Motor_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Positive_Torque_Request;      /* '<Root>/TMR Logic' */
  real_T Velocity_Output;              /* '<Root>/TMR Logic' */
} B_Tractive_Motor_Ring_Single__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S6>/Discrete-Time Integrator' */
  uint8_T is_active_c1_Tractive_Motor_Rin;/* '<Root>/TMR Logic' */
  uint8_T is_NORMAL_OPERATION;         /* '<Root>/TMR Logic' */
  uint8_T was_NORMAL_OPERATION;        /* '<Root>/TMR Logic' */
  uint8_T is_SHUTDOWN;                 /* '<Root>/TMR Logic' */
  uint8_T is_OPERATIONAL;              /* '<Root>/TMR Logic' */
  uint8_T is_STARTUP_LV;               /* '<Root>/TMR Logic' */
  uint8_T is_RUNNING;                  /* '<Root>/TMR Logic' */
  uint8_T is_SetpointSettingsTorqueContro;/* '<Root>/TMR Logic' */
  uint8_T is_STARTUP_HV;               /* '<Root>/TMR Logic' */
} DW_Tractive_Motor_Ring_Single_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T Compare;             /* '<S9>/Compare' */
} ConstB_Tractive_Motor_Ring_Si_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [1,0])
   * Referenced by:
   *   '<S4>/Inverter Cold Plate Temperature Limiting Factor'
   *   '<S4>/Inverter Power Supply Temperature Limiting Factor'
   *   '<S4>/Inverter i2t Limiting Factor'
   *   '<S4>/Motor Temperature Limiting Factor'
   *   '<S4>/Motor i2t Limiting Factor'
   *   '<S4>/Overvoltage in HV Limiting Factor'
   */
  real_T pooled4[2];

  /* Expression: [TMR.MtrTempFullTrq, TMR.MtrTempNoTrq]
   * Referenced by: '<S4>/Motor Temperature Limiting Factor'
   */
  real_T MotorTemperatureLimitingFactor_[2];

  /* Expression: [TMR.PwrSpplyTempFullTrq, TMR.PwrSpplyTempNoTrq]
   * Referenced by: '<S4>/Inverter Power Supply Temperature Limiting Factor'
   */
  real_T InverterPowerSupplyTemperatureL[2];

  /* Expression: [TMR.ColdPlateTempFullTrq, TMR.ColdPlateTempNoTrq]
   * Referenced by: '<S4>/Inverter Cold Plate Temperature Limiting Factor'
   */
  real_T InverterColdPlateTemperatureLim[2];

  /* Expression: [TMR.HighBatteryVolt, TMR.MaxBatteryVolt]
   * Referenced by: '<S4>/Overvoltage in HV Limiting Factor'
   */
  real_T OvervoltageinHVLimitingFactor_b[2];

  /* Expression: [0,1]
   * Referenced by: '<S4>/Undervoltage in HV Limiting Factor'
   */
  real_T UndervoltageinHVLimitingFactor_[2];

  /* Expression: [TMR.MinBatteryVolt, TMR.LowBatteryVolt]
   * Referenced by: '<S4>/Undervoltage in HV Limiting Factor'
   */
  real_T UndervoltageinHVLimitingFacto_d[2];

  /* Expression: [TMR.MtrCurrOverloadThreshold*TMR.MtrI2t,  TMR.MtrI2t]
   * Referenced by: '<S4>/Motor i2t Limiting Factor'
   */
  real_T Motori2tLimitingFactor_bp01Data[2];

  /* Expression: [TMR.InvCurrOverloadThreshold*TMR.InvI2t, TMR.InvI2t]
   * Referenced by: '<S4>/Inverter i2t Limiting Factor'
   */
  real_T Inverteri2tLimitingFactor_bp01D[2];
} ConstP_Tractive_Motor_Ring_Si_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  MSR_REQUEST TMRModeRequest;          /* '<Root>/TMR Mode Request' */
  real_T TMRControlMode;               /* '<Root>/TMR Control Mode' */
  real_T MtrTrqRequestNm;              /* '<Root>/MtrTrqRequest [Nm]' */
  real_T VelocityRequest;              /* '<Root>/Velocity Request' */
  real_T HVSupplyVoltageV;             /* '<Root>/HV Supply Voltage [V]' */
  boolean_T AMK_bSystemReady;          /* '<Root>/AMK_bSystemReady' */
  boolean_T AMK_bError;                /* '<Root>/AMK_bError' */
  boolean_T AMK_bWarn;                 /* '<Root>/AMK_bWarn' */
  boolean_T AMK_bQuitDcOn;             /* '<Root>/AMK_bQuitDcOn' */
  boolean_T AMK_bDcOn;                 /* '<Root>/AMK_bDcOn' */
  boolean_T AMK_bQuitInverterOn;       /* '<Root>/AMK_bQuitInverterOn' */
  boolean_T AMKbInverterOn;            /* '<Root>/AMK-bInverterOn' */
  boolean_T AMK_bDerating;             /* '<Root>/AMK_bDerating' */
  real_T MotorSpeedrads;               /* '<Root>/Motor Speed [rad//s]' */
  real_T AMK_TorqueCurrent;            /* '<Root>/AMK_TorqueCurrent' */
  real_T AMK_MagnetizingCurrent;       /* '<Root>/AMK_MagnetizingCurrent' */
  real_T MotorTemperatureK;            /* '<Root>/Motor Temperature [°K]' */
  real_T InverterColdPlateTemperatureK;
                            /* '<Root>/Inverter Cold Plate Temperature [°K]' */
  real_T AMK_ErrorInfo;                /* '<Root>/AMK_ErrorInfo' */
  real_T InverterPowerSupplyTemperatureK;
                          /* '<Root>/Inverter Power Supply Temperature [°K]' */
} ExtU_Tractive_Motor_Ring_Sing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  AmkSetpoints AMK_Setpoints;          /* '<Root>/AMK_Setpoints' */
  RING_STATUS TMRState;                /* '<Root>/TMR State' */
  TMR_LogicModeType TMRLeafstate;      /* '<Root>/TMR Leaf-state' */
  real_T TorqueLimit;                  /* '<Root>/Torque Limit' */
} ExtY_Tractive_Motor_Ring_Sing_T;

/* Real-time Model Data Structure */
struct tag_RTM_Tractive_Motor_Ring_S_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Tractive_Motor_Ring_Single__T Tractive_Motor_Ring_Single_Mo_B;

/* Block states (default storage) */
extern DW_Tractive_Motor_Ring_Single_T Tractive_Motor_Ring_Single_M_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Tractive_Motor_Ring_Sing_T Tractive_Motor_Ring_Single_Mo_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Tractive_Motor_Ring_Sing_T Tractive_Motor_Ring_Single_Mo_Y;
extern const ConstB_Tractive_Motor_Ring_Si_T Tractive_Motor_Ring_Sing_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Tractive_Motor_Ring_Si_T Tractive_Motor_Ring_Sing_ConstP;

/* Model entry point functions */
extern void Tractive_Motor_Ring_Single_Motor_initialize(void);
extern void Tractive_Motor_Ring_Single_Motor_step(void);
extern void Tractive_Motor_Ring_Single_Motor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Tractive_Motor_Ring__T *const Tractive_Motor_Ring_Single_M_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/AMK_Derating' : Unused code path elimination
 * Block '<Root>/AMK_Warn' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Tractive_Motor_Ring_Single_Motor'
 * '<S1>'   : 'Tractive_Motor_Ring_Single_Motor/AMKInverterLimits'
 * '<S2>'   : 'Tractive_Motor_Ring_Single_Motor/PowerLimit'
 * '<S3>'   : 'Tractive_Motor_Ring_Single_Motor/TMR Logic'
 * '<S4>'   : 'Tractive_Motor_Ring_Single_Motor/AMKInverterLimits/Derating Calculation'
 * '<S5>'   : 'Tractive_Motor_Ring_Single_Motor/AMKInverterLimits/Torque Limit Calculation'
 * '<S6>'   : 'Tractive_Motor_Ring_Single_Motor/AMKInverterLimits/Derating Calculation/Inverter Overload i2t Calculation'
 * '<S7>'   : 'Tractive_Motor_Ring_Single_Motor/AMKInverterLimits/Derating Calculation/Motor Overload i2t Calculation'
 * '<S8>'   : 'Tractive_Motor_Ring_Single_Motor/AMKInverterLimits/Derating Calculation/Motor Overload i2t Calculation/Compare To Motor Standstill Current'
 * '<S9>'   : 'Tractive_Motor_Ring_Single_Motor/PowerLimit/Compare To Zero'
 * '<S10>'  : 'Tractive_Motor_Ring_Single_Motor/PowerLimit/DC Voltage Constraint'
 * '<S11>'  : 'Tractive_Motor_Ring_Single_Motor/PowerLimit/TrqRequest'
 */
#endif                      /* RTW_HEADER_Tractive_Motor_Ring_Single_Motor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
