/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tractive_Motor_Ring_Single_Motor.c
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

/* Named constants for Chart: '<Root>/TMR Logic' */
#define IN_BrakingSetpointSettingsTorqu ((uint8_T)1U)
#define IN_ForwardAccelSetpointSettings ((uint8_T)2U)
#define IN_SetpointSettingsSpeedControl ((uint8_T)2U)
#define IN_SetpointSettingsTorqueContro ((uint8_T)3U)
#define Trac_IN_StartingStartUpSequence ((uint8_T)11U)
#define Tractiv_IN_RequirementsShutDown ((uint8_T)3U)
#define Tractive_IN_CheckQuitInverterOn ((uint8_T)2U)
#define Tractive_Mot_IN_HV_Deactivation ((uint8_T)2U)
#define Tractive_Mot_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Tractive_Mot_IN_ResetInverterOn ((uint8_T)5U)
#define Tractive_Moto_IN_CheckQuitDcON1 ((uint8_T)1U)
#define Tractive_Moto_IN_ControlModeOff ((uint8_T)1U)
#define Tractive_Moto_IN_ResetX15EF1EF2 ((uint8_T)8U)
#define Tractive_Motor_IN_CheckQuitDcON ((uint8_T)1U)
#define Tractive_Motor_IN_HV_Activation ((uint8_T)3U)
#define Tractive_Motor_IN_SetInverterOn ((uint8_T)6U)
#define Tractive_Motor_R_IN_OPERATIONAL ((uint8_T)2U)
#define Tractive_Motor_R_IN_ResetEnable ((uint8_T)4U)
#define Tractive_Motor_R_IN_StartUpPass ((uint8_T)10U)
#define Tractive_Motor_Ri_IN_AMK_ONLINE ((uint8_T)2U)
#define Tractive_Motor_Ri_IN_STARTUP_HV ((uint8_T)2U)
#define Tractive_Motor_Ri_IN_STARTUP_LV ((uint8_T)3U)
#define Tractive_Motor_Ri_IN_SetX140BE1 ((uint8_T)7U)
#define Tractive_Motor_Ri_IN_SetX140BE2 ((uint8_T)8U)
#define Tractive_Motor_Rin_IN_AMK_CHECK ((uint8_T)1U)
#define Tractive_Motor_Rin_IN_SetEnable ((uint8_T)5U)
#define Tractive_Motor_Ring_IN_SHUTDOWN ((uint8_T)3U)
#define Tractive_Motor_Ring_IN_ShutDown ((uint8_T)9U)
#define Tractive_Motor_Ring_Sing_IN_OFF ((uint8_T)1U)
#define Tractive_Motor_Ring__IN_RUNNING ((uint8_T)1U)
#define Tractive_Motor__IN_Requirements ((uint8_T)4U)
#define Tractive_Motor__IN_ResetX140BE1 ((uint8_T)6U)
#define Tractive_Motor__IN_ResetX140BE2 ((uint8_T)7U)
#define Tractive_Motor__IN_SetX15EF1EF2 ((uint8_T)9U)

/* Block signals (default storage) */
B_Tractive_Motor_Ring_Single__T Tractive_Motor_Ring_Single_Mo_B;

/* Block states (default storage) */
DW_Tractive_Motor_Ring_Single_T Tractive_Motor_Ring_Single_M_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Tractive_Motor_Ring_Sing_T Tractive_Motor_Ring_Single_Mo_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Tractive_Motor_Ring_Sing_T Tractive_Motor_Ring_Single_Mo_Y;

/* Real-time model */
RT_MODEL_Tractive_Motor_Ring__T Tractive_Motor_Ring_Single_M_M_;
RT_MODEL_Tractive_Motor_Ring__T *const Tractive_Motor_Ring_Single_M_M =
  &Tractive_Motor_Ring_Single_M_M_;

/* Forward declaration for local functions */
static void Tracti_exit_internal_STARTUP_HV(void);
static void Tractive_Motor_Ring_OPERATIONAL(const real_T *Switch2);
real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Function for Chart: '<Root>/TMR Logic' */
static void Tracti_exit_internal_STARTUP_HV(void)
{
  /* Outport: '<Root>/TMR Leaf-state' */
  Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate = TMR_LogicModeType_None;
  Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
    Tractive_Mot_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<Root>/TMR Logic' */
static void Tractive_Motor_Ring_OPERATIONAL(const real_T *Switch2)
{
  /* Inport: '<Root>/TMR Mode Request' */
  if (Tractive_Motor_Ring_Single_Mo_U.TMRModeRequest == MSR_REQUEST_SHUTDOWN_HV)
  {
    Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
      Tractive_Mot_IN_NO_ACTIVE_CHILD;
    Tractive_Motor_Ring_Single_M_DW.is_RUNNING = Tractive_Mot_IN_NO_ACTIVE_CHILD;
    Tracti_exit_internal_STARTUP_HV();
    Tractive_Motor_Ring_Single_M_DW.is_STARTUP_LV =
      Tractive_Mot_IN_NO_ACTIVE_CHILD;
    Tractive_Motor_Ring_Single_M_DW.is_OPERATIONAL =
      Tractive_Mot_IN_NO_ACTIVE_CHILD;
    Tractive_Motor_Ring_Single_M_DW.is_NORMAL_OPERATION =
      Tractive_Motor_Ring_IN_SHUTDOWN;
    Tractive_Motor_Ring_Single_M_DW.was_NORMAL_OPERATION =
      Tractive_Motor_Ring_IN_SHUTDOWN;

    /* Outport: '<Root>/TMR State' */
    Tractive_Motor_Ring_Single_Mo_Y.TMRState =
      RING_STATUS_SHUTDOWN_IN_PROGRESS_HV;
    Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
      Tractiv_IN_RequirementsShutDown;

    /* Outport: '<Root>/TMR Leaf-state' */
    Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
      TMR_LogicModeType_RequirementsShutDown;
    Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = 0.0;
    Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 0.0;
  } else {
    switch (Tractive_Motor_Ring_Single_M_DW.is_OPERATIONAL) {
     case Tractive_Motor_Ring__IN_RUNNING:
      switch (Tractive_Motor_Ring_Single_M_DW.is_RUNNING) {
       case Tractive_Moto_IN_ControlModeOff:
        /* Inport: '<Root>/TMR Control Mode' */
        if (Tractive_Motor_Ring_Single_Mo_U.TMRControlMode == 1.0) {
          Tractive_Motor_Ring_Single_M_DW.is_RUNNING =
            IN_SetpointSettingsTorqueContro;
          if (*Switch2 >= 0.0) {
            Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
              IN_ForwardAccelSetpointSettings;

            /* Outport: '<Root>/TMR Leaf-state' */
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_ForwardAccelSetpointSettingsTorqueControl;
          } else {
            Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
              IN_BrakingSetpointSettingsTorqu;

            /* Outport: '<Root>/TMR Leaf-state' */
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_BrakingSetpointSettingsTorqueControl;
          }
        } else if (Tractive_Motor_Ring_Single_Mo_U.TMRControlMode == 2.0) {
          Tractive_Motor_Ring_Single_M_DW.is_RUNNING =
            IN_SetpointSettingsSpeedControl;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_SetpointSettingsSpeedControl;
        } else {
          Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = 0.0;
          Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 0.0;
        }
        break;

       case IN_SetpointSettingsSpeedControl:
        /* Inport: '<Root>/TMR Control Mode' */
        if (Tractive_Motor_Ring_Single_Mo_U.TMRControlMode == 1.0) {
          Tractive_Motor_Ring_Single_M_DW.is_RUNNING =
            IN_SetpointSettingsTorqueContro;
          if (*Switch2 >= 0.0) {
            Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
              IN_ForwardAccelSetpointSettings;

            /* Outport: '<Root>/TMR Leaf-state' */
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_ForwardAccelSetpointSettingsTorqueControl;
          } else {
            Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
              IN_BrakingSetpointSettingsTorqu;

            /* Outport: '<Root>/TMR Leaf-state' */
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_BrakingSetpointSettingsTorqueControl;
          }
        } else if (Tractive_Motor_Ring_Single_Mo_U.TMRControlMode == 0.0) {
          Tractive_Motor_Ring_Single_M_DW.is_RUNNING =
            Tractive_Moto_IN_ControlModeOff;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_ControlModeOff;
        } else {
          /* Inport: '<Root>/Velocity Request' */
          Tractive_Motor_Ring_Single_Mo_B.Velocity_Output =
            Tractive_Motor_Ring_Single_Mo_U.VelocityRequest;
          Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = *Switch2;
        }
        break;

       default:
        /* Inport: '<Root>/TMR Control Mode' */
        /* case IN_SetpointSettingsTorqueControl: */
        if (Tractive_Motor_Ring_Single_Mo_U.TMRControlMode == 2.0) {
          Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
            Tractive_Mot_IN_NO_ACTIVE_CHILD;
          Tractive_Motor_Ring_Single_M_DW.is_RUNNING =
            IN_SetpointSettingsSpeedControl;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_SetpointSettingsSpeedControl;
        } else if (Tractive_Motor_Ring_Single_Mo_U.TMRControlMode == 0.0) {
          Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
            Tractive_Mot_IN_NO_ACTIVE_CHILD;
          Tractive_Motor_Ring_Single_M_DW.is_RUNNING =
            Tractive_Moto_IN_ControlModeOff;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_ControlModeOff;
        } else if
            (Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro ==
             IN_BrakingSetpointSettingsTorqu) {
          if (*Switch2 >= 0.0) {
            Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
              IN_ForwardAccelSetpointSettings;

            /* Outport: '<Root>/TMR Leaf-state' */
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_ForwardAccelSetpointSettingsTorqueControl;
          } else {
            Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 0.0;
            Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = 0.0;
          }
        } else {
          /* case IN_ForwardAccelSetpointSettingsTorqueControl: */
          if (*Switch2 < 0.0) {
            Tractive_Motor_Ring_Single_M_DW.is_SetpointSettingsTorqueContro =
              IN_BrakingSetpointSettingsTorqu;

            /* Outport: '<Root>/TMR Leaf-state' */
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_BrakingSetpointSettingsTorqueControl;
          } else {
            Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 30000.0;
            Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = *Switch2;
          }
        }
        break;
      }
      break;

     case Tractive_Motor_Ri_IN_STARTUP_HV:
      /* Outport: '<Root>/TMR State' incorporates:
       *  Inport: '<Root>/AMK-bInverterOn'
       *  Inport: '<Root>/AMK_bDcOn'
       *  Inport: '<Root>/AMK_bQuitDcOn'
       *  Inport: '<Root>/AMK_bQuitInverterOn'
       *  Outport: '<Root>/TMR Leaf-state'
       */
      if ((Tractive_Motor_Ring_Single_Mo_U.TMRModeRequest == MSR_REQUEST_RUNNING)
          && (Tractive_Motor_Ring_Single_Mo_Y.TMRState ==
              RING_STATUS_STARTUP_COMPLETE_HV)) {
        Tracti_exit_internal_STARTUP_HV();
        Tractive_Motor_Ring_Single_M_DW.is_OPERATIONAL =
          Tractive_Motor_Ring__IN_RUNNING;
        Tractive_Motor_Ring_Single_Mo_Y.TMRState = RING_STATUS_RUNNING;
        Tractive_Motor_Ring_Single_M_DW.is_RUNNING =
          Tractive_Moto_IN_ControlModeOff;
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_ControlModeOff;
      } else {
        switch (Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV) {
         case Tractive_Motor_IN_CheckQuitDcON:
          if (Tractive_Motor_Ring_Single_Mo_U.AMK_bQuitDcOn) {
            Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
              Tractive_Motor__IN_Requirements;
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_Requirements;
            Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = 0.0;
            Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 0.0;
          }
          break;

         case Tractive_IN_CheckQuitInverterOn:
          if (Tractive_Motor_Ring_Single_Mo_U.AMK_bQuitInverterOn) {
            Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
              Tractive_Motor_Ri_IN_SetX140BE2;
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_SetX140BE2;
          }
          break;

         case Tractive_Motor_IN_HV_Activation:
          Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bDcOn = true;
          if (Tractive_Motor_Ring_Single_Mo_U.AMK_bDcOn) {
            Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
              Tractive_Motor_IN_CheckQuitDcON;
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_CheckQuitDcON;
          }
          break;

         case Tractive_Motor__IN_Requirements:
          Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
            Tractive_Motor__IN_SetX15EF1EF2;
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_SetX15EF1EF2;
          break;

         case Tractive_Motor_Rin_IN_SetEnable:
          Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bEnable = true;
          Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
            Tractive_Motor_IN_SetInverterOn;
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_SetInverterOn;
          Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bInverterOn = true;
          break;

         case Tractive_Motor_IN_SetInverterOn:
          Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bInverterOn = true;
          if (Tractive_Motor_Ring_Single_Mo_U.AMKbInverterOn) {
            Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
              Tractive_IN_CheckQuitInverterOn;
            Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
              TMR_LogicModeType_CheckQuitInverterOn;
          }
          break;

         case Tractive_Motor_Ri_IN_SetX140BE1:
          Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
            Tractive_Motor_Rin_IN_SetEnable;
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_SetEnable;
          Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bEnable = true;
          break;

         case Tractive_Motor_Ri_IN_SetX140BE2:
          Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
            Tractive_Motor_R_IN_StartUpPass;
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_StartUpPass;
          Tractive_Motor_Ring_Single_Mo_Y.TMRState =
            RING_STATUS_STARTUP_COMPLETE_HV;
          break;

         case Tractive_Motor__IN_SetX15EF1EF2:
          Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
            Tractive_Motor_Ri_IN_SetX140BE1;
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_SetX140BE1;
          break;

         case Tractive_Motor_R_IN_StartUpPass:
          break;

         default:
          /* case IN_StartingStartUpSequence: */
          Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
            Tractive_Motor_IN_HV_Activation;
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_HV_Activation;
          Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bDcOn = true;
          break;
        }
      }
      break;

     default:
      /* Outport: '<Root>/TMR State' incorporates:
       *  Inport: '<Root>/AMK_bSystemReady'
       *  Outport: '<Root>/TMR Leaf-state'
       */
      /* case IN_STARTUP_LV: */
      if ((Tractive_Motor_Ring_Single_Mo_U.TMRModeRequest ==
           MSR_REQUEST_STARTUP_HV) && (Tractive_Motor_Ring_Single_Mo_Y.TMRState ==
           RING_STATUS_STARTUP_COMPLETE_LV)) {
        Tractive_Motor_Ring_Single_M_DW.is_STARTUP_LV =
          Tractive_Mot_IN_NO_ACTIVE_CHILD;
        Tractive_Motor_Ring_Single_M_DW.is_OPERATIONAL =
          Tractive_Motor_Ri_IN_STARTUP_HV;
        Tractive_Motor_Ring_Single_Mo_Y.TMRState =
          RING_STATUS_STARTUP_IN_PROGRESS_HV;
        Tractive_Motor_Ring_Single_M_DW.is_STARTUP_HV =
          Trac_IN_StartingStartUpSequence;
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_StartingStartUpSequence;
      } else if ((Tractive_Motor_Ring_Single_M_DW.is_STARTUP_LV ==
                  Tractive_Motor_Rin_IN_AMK_CHECK) &&
                 Tractive_Motor_Ring_Single_Mo_U.AMK_bSystemReady) {
        Tractive_Motor_Ring_Single_M_DW.is_STARTUP_LV =
          Tractive_Motor_Ri_IN_AMK_ONLINE;
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_AMK_ONLINE;
        Tractive_Motor_Ring_Single_Mo_Y.TMRState =
          RING_STATUS_STARTUP_COMPLETE_LV;
      } else {
        /* case IN_AMK_ONLINE: */
      }
      break;
    }
  }

  /* End of Inport: '<Root>/TMR Mode Request' */
}

/* Model step function */
void Tractive_Motor_Ring_Single_Motor_step(void)
{
  real_T rtb_MathFunction1;
  real_T Switch2;
  real_T u0;

  /* Abs: '<S10>/Abs' incorporates:
   *  Inport: '<Root>/Motor Speed [rad//s]'
   */
  Switch2 = fabs(Tractive_Motor_Ring_Single_Mo_U.MotorSpeedrads);

  /* Lookup_n-D: '<S4>/Motor Temperature Limiting Factor' incorporates:
   *  Inport: '<Root>/Motor Temperature [°K]'
   */
  u0 = look1_binlcpw(Tractive_Motor_Ring_Single_Mo_U.MotorTemperatureK,
                     Tractive_Motor_Ring_Sing_ConstP.MotorTemperatureLimitingFactor_,
                     Tractive_Motor_Ring_Sing_ConstP.pooled4, 1U);

  /* Lookup_n-D: '<S4>/Inverter Power Supply Temperature Limiting Factor' incorporates:
   *  Inport: '<Root>/Inverter Power Supply Temperature [°K]'
   */
  rtb_MathFunction1 = look1_binlcpw
    (Tractive_Motor_Ring_Single_Mo_U.InverterPowerSupplyTemperatureK,
     Tractive_Motor_Ring_Sing_ConstP.InverterPowerSupplyTemperatureL,
     Tractive_Motor_Ring_Sing_ConstP.pooled4, 1U);

  /* MinMax: '<S4>/MinMax' */
  if ((u0 < rtb_MathFunction1) || rtIsNaN(rtb_MathFunction1)) {
    rtb_MathFunction1 = u0;
  }

  /* Lookup_n-D: '<S4>/Inverter Cold Plate Temperature Limiting Factor' incorporates:
   *  Inport: '<Root>/Inverter Cold Plate Temperature [°K]'
   */
  u0 = look1_binlcpw
    (Tractive_Motor_Ring_Single_Mo_U.InverterColdPlateTemperatureK,
     Tractive_Motor_Ring_Sing_ConstP.InverterColdPlateTemperatureLim,
     Tractive_Motor_Ring_Sing_ConstP.pooled4, 1U);

  /* MinMax: '<S4>/MinMax' */
  if ((rtb_MathFunction1 < u0) || rtIsNaN(u0)) {
    u0 = rtb_MathFunction1;
  }

  /* Lookup_n-D: '<S4>/Overvoltage in HV Limiting Factor' incorporates:
   *  Inport: '<Root>/HV Supply Voltage [V]'
   */
  rtb_MathFunction1 = look1_binlcpw
    (Tractive_Motor_Ring_Single_Mo_U.HVSupplyVoltageV,
     Tractive_Motor_Ring_Sing_ConstP.OvervoltageinHVLimitingFactor_b,
     Tractive_Motor_Ring_Sing_ConstP.pooled4, 1U);

  /* MinMax: '<S4>/MinMax' */
  if ((u0 < rtb_MathFunction1) || rtIsNaN(rtb_MathFunction1)) {
    rtb_MathFunction1 = u0;
  }

  /* Lookup_n-D: '<S4>/Undervoltage in HV Limiting Factor' incorporates:
   *  Inport: '<Root>/HV Supply Voltage [V]'
   */
  u0 = look1_binlcpw(Tractive_Motor_Ring_Single_Mo_U.HVSupplyVoltageV,
                     Tractive_Motor_Ring_Sing_ConstP.UndervoltageinHVLimitingFacto_d,
                     Tractive_Motor_Ring_Sing_ConstP.UndervoltageinHVLimitingFactor_,
                     1U);

  /* MinMax: '<S4>/MinMax' */
  if ((rtb_MathFunction1 < u0) || rtIsNaN(u0)) {
    u0 = rtb_MathFunction1;
  }

  /* Lookup_n-D: '<S4>/Motor i2t Limiting Factor' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   */
  rtb_MathFunction1 = look1_binlcpw
    (Tractive_Motor_Ring_Single_M_DW.DiscreteTimeIntegrator_DSTATE,
     Tractive_Motor_Ring_Sing_ConstP.Motori2tLimitingFactor_bp01Data,
     Tractive_Motor_Ring_Sing_ConstP.pooled4, 1U);

  /* MinMax: '<S4>/MinMax' */
  if ((u0 < rtb_MathFunction1) || rtIsNaN(rtb_MathFunction1)) {
    rtb_MathFunction1 = u0;
  }

  /* Lookup_n-D: '<S4>/Inverter i2t Limiting Factor' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   */
  u0 = look1_binlcpw
    (Tractive_Motor_Ring_Single_M_DW.DiscreteTimeIntegrator_DSTATE_p,
     Tractive_Motor_Ring_Sing_ConstP.Inverteri2tLimitingFactor_bp01D,
     Tractive_Motor_Ring_Sing_ConstP.pooled4, 1U);

  /* Saturate: '<S10>/Saturation' */
  if (Switch2 > 10000.0) {
    Switch2 = 10000.0;
  } else {
    if (Switch2 < 1.0E-7) {
      Switch2 = 1.0E-7;
    }
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Gain: '<S10>/1//VoltageK'
   *  Inport: '<Root>/HV Supply Voltage [V]'
   *  Product: '<S10>/Product'
   */
  Switch2 = 2.6524760638297868 *
    Tractive_Motor_Ring_Single_Mo_U.HVSupplyVoltageV * 21.0 / Switch2;

  /* MinMax: '<S4>/MinMax' */
  if ((rtb_MathFunction1 < u0) || rtIsNaN(u0)) {
    u0 = rtb_MathFunction1;
  }

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit = u0 * 21.0;

  /* MinMax: '<S2>/MaxTrq' */
  if ((Switch2 < Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit) || rtIsNaN
      (Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit)) {
    /* Product: '<S5>/Product' */
    Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit = Switch2;
  }

  /* End of MinMax: '<S2>/MaxTrq' */

  /* Switch: '<S11>/Switch2' incorporates:
   *  Gain: '<S2>/Regen'
   *  Inport: '<Root>/MtrTrqRequest [Nm]'
   *  RelationalOperator: '<S11>/LowerRelop1'
   *  RelationalOperator: '<S11>/UpperRelop'
   *  Switch: '<S11>/Switch'
   */
  if (Tractive_Motor_Ring_Single_Mo_U.MtrTrqRequestNm >
      Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit) {
    Switch2 = Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit;
  } else if (Tractive_Motor_Ring_Single_Mo_U.MtrTrqRequestNm <
             -Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit) {
    /* Switch: '<S11>/Switch' incorporates:
     *  Gain: '<S2>/Regen'
     */
    Switch2 = -Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit;
  } else {
    Switch2 = Tractive_Motor_Ring_Single_Mo_U.MtrTrqRequestNm;
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Chart: '<Root>/TMR Logic' incorporates:
   *  Inport: '<Root>/AMK-bInverterOn'
   *  Inport: '<Root>/AMK_bDcOn'
   *  Inport: '<Root>/AMK_bQuitDcOn'
   *  Inport: '<Root>/TMR Mode Request'
   */
  if (Tractive_Motor_Ring_Single_M_DW.is_active_c1_Tractive_Motor_Rin == 0U) {
    Tractive_Motor_Ring_Single_M_DW.is_active_c1_Tractive_Motor_Rin = 1U;
    switch (Tractive_Motor_Ring_Single_M_DW.was_NORMAL_OPERATION) {
     case Tractive_Motor_Ring_Sing_IN_OFF:
      Tractive_Motor_Ring_Single_M_DW.is_NORMAL_OPERATION =
        Tractive_Motor_Ring_Sing_IN_OFF;
      Tractive_Motor_Ring_Single_M_DW.was_NORMAL_OPERATION =
        Tractive_Motor_Ring_Sing_IN_OFF;

      /* Outport: '<Root>/TMR Leaf-state' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate = TMR_LogicModeType_OFF;

      /* Outport: '<Root>/TMR State' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRState = RING_STATUS_OFF;
      Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = 0.0;
      Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 0.0;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bInverterOn = false;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bDcOn = false;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bEnable = false;
      break;

     case Tractive_Motor_R_IN_OPERATIONAL:
      Tractive_Motor_Ring_Single_M_DW.is_NORMAL_OPERATION =
        Tractive_Motor_R_IN_OPERATIONAL;
      Tractive_Motor_Ring_Single_M_DW.was_NORMAL_OPERATION =
        Tractive_Motor_R_IN_OPERATIONAL;
      Tractive_Motor_Ring_Single_M_DW.is_OPERATIONAL =
        Tractive_Motor_Ri_IN_STARTUP_LV;

      /* Outport: '<Root>/TMR State' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRState =
        RING_STATUS_STARTUP_IN_PROGRESS_LV;
      Tractive_Motor_Ring_Single_M_DW.is_STARTUP_LV =
        Tractive_Motor_Rin_IN_AMK_CHECK;

      /* Outport: '<Root>/TMR Leaf-state' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate = TMR_LogicModeType_AMK_CHECK;
      break;

     case Tractive_Motor_Ring_IN_SHUTDOWN:
      Tractive_Motor_Ring_Single_M_DW.is_NORMAL_OPERATION =
        Tractive_Motor_Ring_IN_SHUTDOWN;
      Tractive_Motor_Ring_Single_M_DW.was_NORMAL_OPERATION =
        Tractive_Motor_Ring_IN_SHUTDOWN;

      /* Outport: '<Root>/TMR State' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRState =
        RING_STATUS_SHUTDOWN_IN_PROGRESS_HV;
      Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
        Tractiv_IN_RequirementsShutDown;

      /* Outport: '<Root>/TMR Leaf-state' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
        TMR_LogicModeType_RequirementsShutDown;
      Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = 0.0;
      Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 0.0;
      break;

     default:
      Tractive_Motor_Ring_Single_M_DW.is_NORMAL_OPERATION =
        Tractive_Motor_Ring_Sing_IN_OFF;
      Tractive_Motor_Ring_Single_M_DW.was_NORMAL_OPERATION =
        Tractive_Motor_Ring_Sing_IN_OFF;

      /* Outport: '<Root>/TMR Leaf-state' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate = TMR_LogicModeType_OFF;

      /* Outport: '<Root>/TMR State' */
      Tractive_Motor_Ring_Single_Mo_Y.TMRState = RING_STATUS_OFF;
      Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request = 0.0;
      Tractive_Motor_Ring_Single_Mo_B.Velocity_Output = 0.0;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bInverterOn = false;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bDcOn = false;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bEnable = false;
      break;
    }
  } else {
    switch (Tractive_Motor_Ring_Single_M_DW.is_NORMAL_OPERATION) {
     case Tractive_Motor_Ring_Sing_IN_OFF:
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bInverterOn = false;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bDcOn = false;
      Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bEnable = false;
      if (Tractive_Motor_Ring_Single_Mo_U.TMRModeRequest ==
          MSR_REQUEST_STARTUP_LV) {
        Tractive_Motor_Ring_Single_M_DW.is_NORMAL_OPERATION =
          Tractive_Motor_R_IN_OPERATIONAL;
        Tractive_Motor_Ring_Single_M_DW.was_NORMAL_OPERATION =
          Tractive_Motor_R_IN_OPERATIONAL;
        Tractive_Motor_Ring_Single_M_DW.is_OPERATIONAL =
          Tractive_Motor_Ri_IN_STARTUP_LV;

        /* Outport: '<Root>/TMR State' */
        Tractive_Motor_Ring_Single_Mo_Y.TMRState =
          RING_STATUS_STARTUP_IN_PROGRESS_LV;
        Tractive_Motor_Ring_Single_M_DW.is_STARTUP_LV =
          Tractive_Motor_Rin_IN_AMK_CHECK;

        /* Outport: '<Root>/TMR Leaf-state' */
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_AMK_CHECK;
      }
      break;

     case Tractive_Motor_R_IN_OPERATIONAL:
      Tractive_Motor_Ring_OPERATIONAL(&Switch2);
      break;

     default:
      /* case IN_SHUTDOWN: */
      switch (Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN) {
       case Tractive_Moto_IN_CheckQuitDcON1:
        if (!Tractive_Motor_Ring_Single_Mo_U.AMK_bQuitDcOn) {
          Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
            Tractive_Motor_Ring_IN_ShutDown;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_ShutDown;

          /* Outport: '<Root>/TMR State' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRState =
            RING_STATUS_SHUTDOWN_COMPLETE_HV;
        }
        break;

       case Tractive_Mot_IN_HV_Deactivation:
        Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bDcOn = false;
        if (!Tractive_Motor_Ring_Single_Mo_U.AMK_bDcOn) {
          Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
            Tractive_Moto_IN_CheckQuitDcON1;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_CheckQuitDcON1;
        }
        break;

       case Tractiv_IN_RequirementsShutDown:
        Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
          Tractive_Motor__IN_ResetX140BE2;

        /* Outport: '<Root>/TMR Leaf-state' */
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_ResetX140BE2;
        break;

       case Tractive_Motor_R_IN_ResetEnable:
        Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bEnable = false;
        if (!Tractive_Motor_Ring_Single_Mo_U.AMK_bQuitDcOn) {
          Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
            Tractive_Motor__IN_ResetX140BE1;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_ResetX140BE1;
        }
        break;

       case Tractive_Mot_IN_ResetInverterOn:
        Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bInverterOn = false;
        if (!Tractive_Motor_Ring_Single_Mo_U.AMKbInverterOn) {
          Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
            Tractive_Motor_R_IN_ResetEnable;

          /* Outport: '<Root>/TMR Leaf-state' */
          Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
            TMR_LogicModeType_ResetEnable;
          Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bEnable = false;
        }
        break;

       case Tractive_Motor__IN_ResetX140BE1:
        Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
          Tractive_Moto_IN_ResetX15EF1EF2;

        /* Outport: '<Root>/TMR Leaf-state' */
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_ResetX15EF1EF2;
        break;

       case Tractive_Motor__IN_ResetX140BE2:
        Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
          Tractive_Mot_IN_ResetInverterOn;

        /* Outport: '<Root>/TMR Leaf-state' */
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_ResetInverterOn;
        Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bInverterOn = false;
        break;

       case Tractive_Moto_IN_ResetX15EF1EF2:
        Tractive_Motor_Ring_Single_M_DW.is_SHUTDOWN =
          Tractive_Mot_IN_HV_Deactivation;

        /* Outport: '<Root>/TMR Leaf-state' */
        Tractive_Motor_Ring_Single_Mo_Y.TMRLeafstate =
          TMR_LogicModeType_HV_Deactivation;
        Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bDcOn = false;
        break;

       default:
        /* case IN_ShutDown: */
        break;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/TMR Logic' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  Switch2 = floor(102.0408163265306 *
                  Tractive_Motor_Ring_Single_Mo_B.Positive_Torque_Request);
  if (rtIsNaN(Switch2) || rtIsInf(Switch2)) {
    Switch2 = 0.0;
  } else {
    Switch2 = fmod(Switch2, 65536.0);
  }

  Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_TorqueLimitPositiv =
    (int16_T)(Switch2 < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-Switch2 :
              (int32_T)(int16_T)(uint16_T)Switch2);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Switch2 = floor(Tractive_Motor_Ring_Single_Mo_B.Velocity_Output);
  if (rtIsNaN(Switch2) || rtIsInf(Switch2)) {
    Switch2 = 0.0;
  } else {
    Switch2 = fmod(Switch2, 65536.0);
  }

  Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_TargetVelocity = (int16_T)
    (Switch2 < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-Switch2 : (int32_T)
     (int16_T)(uint16_T)Switch2);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* BusCreator: '<Root>/Bus Creator' incorporates:
   *  Outport: '<Root>/AMK_Setpoints'
   */
  Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_TorqueLimitNegativ = 0;
  Tractive_Motor_Ring_Single_Mo_Y.AMK_Setpoints.AMK_bErrorReset = false;

  /* Switch: '<S2>/Switch' */
  if (Tractive_Motor_Ring_Sing_ConstB.Compare) {
    /* Saturate: '<S2>/Saturation' */
    if (Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit > 9.8) {
      /* Product: '<S5>/Product' incorporates:
       *  Outport: '<Root>/Torque Limit'
       */
      Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit = 9.8;
    } else {
      if (Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit < 0.0) {
        /* Product: '<S5>/Product' incorporates:
         *  Outport: '<Root>/Torque Limit'
         */
        Tractive_Motor_Ring_Single_Mo_Y.TorqueLimit = 0.0;
      }
    }

    /* End of Saturate: '<S2>/Saturation' */
  }

  /* End of Switch: '<S2>/Switch' */

  /* Product: '<S6>/Divide1' incorporates:
   *  Constant: '<S6>/Inverter Nominal Current'
   *  Inport: '<Root>/AMK_MagnetizingCurrent'
   */
  Switch2 = Tractive_Motor_Ring_Single_Mo_U.AMK_MagnetizingCurrent / 43.0;

  /* Math: '<S6>/Math Function1'
   *
   * About '<S6>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_MathFunction1 = Switch2 * Switch2;

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/Motor Nominal Current'
   *  Inport: '<Root>/AMK_TorqueCurrent'
   */
  Switch2 = Tractive_Motor_Ring_Single_Mo_U.AMK_TorqueCurrent / 41.0;

  /* Sum: '<S7>/Subtract' incorporates:
   *  Constant: '<S7>/Constant'
   *  Math: '<S7>/Math Function'
   *
   * About '<S7>/Math Function':
   *  Operator: magnitude^2
   */
  Switch2 = Switch2 * Switch2 - 1.0;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/AMK_TorqueCurrent'
   *  Product: '<S7>/Product'
   *  RelationalOperator: '<S8>/Compare'
   */
  Tractive_Motor_Ring_Single_M_DW.DiscreteTimeIntegrator_DSTATE += (real_T)
    (Tractive_Motor_Ring_Single_Mo_U.AMK_TorqueCurrent >= 20.0) * Switch2 *
    0.001;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Sum: '<S6>/Subtract1'
   */
  Tractive_Motor_Ring_Single_M_DW.DiscreteTimeIntegrator_DSTATE_p +=
    (rtb_MathFunction1 - 1.0) * 0.001;
}

/* Model initialize function */
void Tractive_Motor_Ring_Single_Motor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void Tractive_Motor_Ring_Single_Motor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
