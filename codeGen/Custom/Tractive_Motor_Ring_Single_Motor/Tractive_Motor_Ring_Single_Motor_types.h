/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tractive_Motor_Ring_Single_Motor_types.h
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

#ifndef RTW_HEADER_Tractive_Motor_Ring_Single_Motor_types_h_
#define RTW_HEADER_Tractive_Motor_Ring_Single_Motor_types_h_
#include "rtwtypes.h"
#include "MSR_REQUEST.h"
#include "RING_STATUS.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_AmkSetpoints_
#define DEFINED_TYPEDEF_FOR_AmkSetpoints_

typedef struct {
  int16_T AMK_TorqueLimitPositiv;
  int16_T AMK_TorqueLimitNegativ;
  int16_T AMK_TargetVelocity;
  boolean_T AMK_bInverterOn;
  boolean_T AMK_bDcOn;
  boolean_T AMK_bEnable;
  boolean_T AMK_bErrorReset;
} AmkSetpoints;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TMR_LogicModeType_
#define DEFINED_TYPEDEF_FOR_TMR_LogicModeType_

typedef enum {
  TMR_LogicModeType_None = 0,          /* Default value */
  TMR_LogicModeType_OFF,
  TMR_LogicModeType_AMK_CHECK,
  TMR_LogicModeType_AMK_ONLINE,
  TMR_LogicModeType_StartingStartUpSequence,
  TMR_LogicModeType_HV_Activation,
  TMR_LogicModeType_CheckQuitDcON,
  TMR_LogicModeType_Requirements,
  TMR_LogicModeType_SetX15EF1EF2,
  TMR_LogicModeType_SetX140BE1,
  TMR_LogicModeType_SetEnable,
  TMR_LogicModeType_SetInverterOn,
  TMR_LogicModeType_CheckQuitInverterOn,
  TMR_LogicModeType_SetX140BE2,
  TMR_LogicModeType_StartUpPass,
  TMR_LogicModeType_ControlModeOff,
  TMR_LogicModeType_ForwardAccelSetpointSettingsTorqueControl,
  TMR_LogicModeType_BrakingSetpointSettingsTorqueControl,
  TMR_LogicModeType_SetpointSettingsSpeedControl,
  TMR_LogicModeType_RequirementsShutDown,
  TMR_LogicModeType_ResetX140BE2,
  TMR_LogicModeType_ResetInverterOn,
  TMR_LogicModeType_ResetEnable,
  TMR_LogicModeType_ResetX140BE1,
  TMR_LogicModeType_ResetX15EF1EF2,
  TMR_LogicModeType_HV_Deactivation,
  TMR_LogicModeType_CheckQuitDcON1,
  TMR_LogicModeType_ShutDown
} TMR_LogicModeType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_gIxFYvTsYVVgn2SAAQ3SGC_
#define DEFINED_TYPEDEF_FOR_struct_gIxFYvTsYVVgn2SAAQ3SGC_

typedef struct {
  real_T OFF;
  real_T COMMUNICATION_CHECK;
  real_T STARTUP;
  real_T RUNNING;
  real_T SHUTDOWN;
} struct_gIxFYvTsYVVgn2SAAQ3SGC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_B84TWF76W5er6OWyrfO87F_
#define DEFINED_TYPEDEF_FOR_struct_B84TWF76W5er6OWyrfO87F_

typedef struct {
  real_T OFF;
  real_T TORQUE_CONTROL;
  real_T SPEED_CONTROL;
} struct_B84TWF76W5er6OWyrfO87F;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_VZ5bUa3CbJUA8gT3MQkovD_
#define DEFINED_TYPEDEF_FOR_struct_VZ5bUa3CbJUA8gT3MQkovD_

typedef struct {
  struct_gIxFYvTsYVVgn2SAAQ3SGC Mode;
  real_T TURNED_OFF;
  real_T COMMUNICATION_PASS;
  real_T CHECKING_COMMUNICATION;
  real_T BEGIN_STARTUP;
  real_T STARTUP_PASS;
  real_T SPEED_CONTROL;
  real_T FORWARD_TORQUE_CONTROL;
  real_T BACKAWRD_TORQUE_CONTROL;
  real_T BEGIN_SHUTDOWN;
  real_T SHUTDOWN_PASS;
  struct_B84TWF76W5er6OWyrfO87F CONTROL_MODE;
  real_T LimitFactorOffset;
  real_T MtrTempFullTrq;
  real_T MtrTempNoTrq;
  real_T PwrSpplyTempFullTrq;
  real_T PwrSpplyTempNoTrq;
  real_T ColdPlateTempFullTrq;
  real_T ColdPlateTempNoTrq;
  real_T HighBatteryVolt;
  real_T MaxBatteryVolt;
  real_T LowBatteryVolt;
  real_T MinBatteryVolt;
  real_T MtrPeakCurr;
  real_T MtrNominalCurr;
  real_T MtrStandstillCurr;
  real_T MtrPeakCurrTime;
  real_T InvPeakCurr;
  real_T InvNominalCurr;
  real_T InvPeakCurrTime;
  real_T MtrI2t;
  real_T InvI2t;
  real_T MtrCurrOverloadThreshold;
  real_T InvCurrOverloadThreshold;
  real_T ENDURANCE_MODE;
  real_T VoltageK;
  real_T MtrPeakTrq;
  real_T MtrNominalTrq;
  real_T MinMtrSpd;
  real_T MinStartupCount;
} struct_VZ5bUa3CbJUA8gT3MQkovD;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Tractive_Motor_Ring_S_T RT_MODEL_Tractive_Motor_Ring__T;

#endif                /* RTW_HEADER_Tractive_Motor_Ring_Single_Motor_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
