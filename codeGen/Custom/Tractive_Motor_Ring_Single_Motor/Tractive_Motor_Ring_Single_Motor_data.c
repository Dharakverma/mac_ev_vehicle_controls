/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tractive_Motor_Ring_Single_Motor_data.c
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

#include "Tractive_Motor_Ring_Single_Motor.h"
#include "Tractive_Motor_Ring_Single_Motor_private.h"

/* Invariant block signals (default storage) */
const ConstB_Tractive_Motor_Ring_Si_T Tractive_Motor_Ring_Sing_ConstB = {
  0                                    /* '<S9>/Compare' */
};

/* Constant parameters (default storage) */
const ConstP_Tractive_Motor_Ring_Si_T Tractive_Motor_Ring_Sing_ConstP = {
  /* Pooled Parameter (Expression: [1,0])
   * Referenced by:
   *   '<S4>/Inverter Cold Plate Temperature Limiting Factor'
   *   '<S4>/Inverter Power Supply Temperature Limiting Factor'
   *   '<S4>/Inverter i2t Limiting Factor'
   *   '<S4>/Motor Temperature Limiting Factor'
   *   '<S4>/Motor i2t Limiting Factor'
   *   '<S4>/Overvoltage in HV Limiting Factor'
   */
  { 1.0, 0.0 },

  /* Expression: [TMR.MtrTempFullTrq, TMR.MtrTempNoTrq]
   * Referenced by: '<S4>/Motor Temperature Limiting Factor'
   */
  { 398.15, 413.15 },

  /* Expression: [TMR.PwrSpplyTempFullTrq, TMR.PwrSpplyTempNoTrq]
   * Referenced by: '<S4>/Inverter Power Supply Temperature Limiting Factor'
   */
  { 388.15, 398.15 },

  /* Expression: [TMR.ColdPlateTempFullTrq, TMR.ColdPlateTempNoTrq]
   * Referenced by: '<S4>/Inverter Cold Plate Temperature Limiting Factor'
   */
  { 323.15, 333.15 },

  /* Expression: [TMR.HighBatteryVolt, TMR.MaxBatteryVolt]
   * Referenced by: '<S4>/Overvoltage in HV Limiting Factor'
   */
  { 400.0, 720.0 },

  /* Expression: [0,1]
   * Referenced by: '<S4>/Undervoltage in HV Limiting Factor'
   */
  { 0.0, 1.0 },

  /* Expression: [TMR.MinBatteryVolt, TMR.LowBatteryVolt]
   * Referenced by: '<S4>/Undervoltage in HV Limiting Factor'
   */
  { 100.0, 250.0 },

  /* Expression: [TMR.MtrCurrOverloadThreshold*TMR.MtrI2t,  TMR.MtrI2t]
   * Referenced by: '<S4>/Motor i2t Limiting Factor'
   */
  { 0.0, 6.1365615704937539 },

  /* Expression: [TMR.InvCurrOverloadThreshold*TMR.InvI2t, TMR.InvI2t]
   * Referenced by: '<S4>/Inverter i2t Limiting Factor'
   */
  { 0.0, 52.151649540292055 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
