/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AccumulatorManagementRing.c
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

#include "AccumulatorManagementRing.h"
#include "AccumulatorManagementRing_private.h"

/* Named constants for Chart: '<Root>/ ModeSelection' */
#define AccumulatorManagementRing_IN_HVComplete ((uint8_T)1U)
#define AccumulatorManagementRing_IN_HVPrechg ((uint8_T)2U)
#define AccumulatorManagementRing_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define AccumulatorManagementRing_IN_OPERATIONAL ((uint8_T)1U)
#define AccumulatorManagementRing_IN_Off ((uint8_T)2U)
#define AccumulatorManagementRing_IN_RqstPrechg ((uint8_T)3U)
#define AccumulatorManagementRing_IN_Running ((uint8_T)1U)
#define AccumulatorManagementRing_IN_Shutdown ((uint8_T)3U)
#define AccumulatorManagementRing_IN_ShutdownComplete ((uint8_T)1U)
#define AccumulatorManagementRing_IN_ShutdownInProgress ((uint8_T)2U)
#define AccumulatorManagementRing_IN_Startup ((uint8_T)2U)

/* Block states (default storage) */
DW_AccumulatorManagementRing_T AccumulatorManagementRing_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AccumulatorManagementRing_T AccumulatorManagementRing_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AccumulatorManagementRing_T AccumulatorManagementRing_Y;

/* Real-time model */
RT_MODEL_AccumulatorManagementRing_T AccumulatorManagementRing_M_;
RT_MODEL_AccumulatorManagementRing_T *const AccumulatorManagementRing_M =
  &AccumulatorManagementRing_M_;

/* Model step function */
void AccumulatorManagementRing_step(void)
{
  int32_T j;
  int32_T u;
  real_T acc1;
  real_T acc1_0;
  real_T rtb_Switch_o;
  boolean_T rtb_DataTypeConversion[8];
  uint8_T rtb_IntegertoBitConverter[8];
  real_T Product2;
  int32_T i;

  /* Chart: '<Root>/ ModeSelection' incorporates:
   *  Inport: '<Root>/K1Precharge'
   *  Inport: '<Root>/K2HvPositive'
   *  Inport: '<Root>/K3Negative'
   *  Inport: '<Root>/MSR_ModeRequest'
   *  Outport: '<Root>/AMR_Status'
   */
  if (AccumulatorManagementRing_DW.is_active_c3_AccumulatorManagementRing == 0U)
  {
    AccumulatorManagementRing_DW.is_active_c3_AccumulatorManagementRing = 1U;
    AccumulatorManagementRing_DW.is_c3_AccumulatorManagementRing =
      AccumulatorManagementRing_IN_Off;

    /* Outport: '<Root>/AMR_ContactorRequest' */
    AccumulatorManagementRing_Y.AMR_ContactorRequest = 0.0;

    /* Outport: '<Root>/AMR_Status' */
    AccumulatorManagementRing_Y.AMR_Status = RING_STATUS_OFF;
  } else {
    switch (AccumulatorManagementRing_DW.is_c3_AccumulatorManagementRing) {
     case AccumulatorManagementRing_IN_OPERATIONAL:
      if (AccumulatorManagementRing_U.MSR_ModeRequest == MSR_REQUEST_SHUTDOWN_HV)
      {
        AccumulatorManagementRing_DW.is_Startup =
          AccumulatorManagementRing_IN_NO_ACTIVE_CHILD;
        AccumulatorManagementRing_DW.is_OPERATIONAL =
          AccumulatorManagementRing_IN_NO_ACTIVE_CHILD;
        AccumulatorManagementRing_DW.is_c3_AccumulatorManagementRing =
          AccumulatorManagementRing_IN_Shutdown;
        AccumulatorManagementRing_DW.is_Shutdown =
          AccumulatorManagementRing_IN_ShutdownInProgress;

        /* Outport: '<Root>/AMR_Status' */
        AccumulatorManagementRing_Y.AMR_Status =
          RING_STATUS_SHUTDOWN_IN_PROGRESS_HV;

        /* Outport: '<Root>/AMR_ContactorRequest' */
        AccumulatorManagementRing_Y.AMR_ContactorRequest = 0.0;
      } else if (AccumulatorManagementRing_DW.is_OPERATIONAL ==
                 AccumulatorManagementRing_IN_Running) {
        /* Outport: '<Root>/AMR_Status' */
        AccumulatorManagementRing_Y.AMR_Status = RING_STATUS_RUNNING;
      } else {
        /* case IN_Startup: */
        if ((AccumulatorManagementRing_U.MSR_ModeRequest == MSR_REQUEST_RUNNING)
            && (AccumulatorManagementRing_Y.AMR_Status ==
                RING_STATUS_STARTUP_COMPLETE_HV)) {
          AccumulatorManagementRing_DW.is_Startup =
            AccumulatorManagementRing_IN_NO_ACTIVE_CHILD;
          AccumulatorManagementRing_DW.is_OPERATIONAL =
            AccumulatorManagementRing_IN_Running;
          AccumulatorManagementRing_Y.AMR_Status = RING_STATUS_RUNNING;
        } else {
          switch (AccumulatorManagementRing_DW.is_Startup) {
           case AccumulatorManagementRing_IN_HVComplete:
            AccumulatorManagementRing_Y.AMR_Status =
              RING_STATUS_STARTUP_COMPLETE_HV;
            break;

           case AccumulatorManagementRing_IN_HVPrechg:
            if ((!AccumulatorManagementRing_U.K1Precharge) &&
                AccumulatorManagementRing_U.K2HvPositive &&
                AccumulatorManagementRing_U.K3Negative) {
              AccumulatorManagementRing_DW.is_Startup =
                AccumulatorManagementRing_IN_HVComplete;
              AccumulatorManagementRing_Y.AMR_Status =
                RING_STATUS_STARTUP_COMPLETE_HV;
            }
            break;

           default:
            /* case IN_RqstPrechg: */
            AccumulatorManagementRing_Y.AMR_Status =
              RING_STATUS_STARTUP_IN_PROGRESS_HV;

            /* Outport: '<Root>/AMR_ContactorRequest' */
            AccumulatorManagementRing_Y.AMR_ContactorRequest = 1.0;
            if (AccumulatorManagementRing_U.K1Precharge &&
                (!AccumulatorManagementRing_U.K2HvPositive) &&
                AccumulatorManagementRing_U.K3Negative) {
              AccumulatorManagementRing_DW.is_Startup =
                AccumulatorManagementRing_IN_HVPrechg;
            }
            break;
          }
        }
      }
      break;

     case AccumulatorManagementRing_IN_Off:
      /* Outport: '<Root>/AMR_ContactorRequest' */
      AccumulatorManagementRing_Y.AMR_ContactorRequest = 0.0;

      /* Outport: '<Root>/AMR_Status' */
      AccumulatorManagementRing_Y.AMR_Status = RING_STATUS_OFF;
      if (AccumulatorManagementRing_U.MSR_ModeRequest == MSR_REQUEST_STARTUP_HV)
      {
        AccumulatorManagementRing_DW.is_c3_AccumulatorManagementRing =
          AccumulatorManagementRing_IN_OPERATIONAL;
        AccumulatorManagementRing_DW.is_OPERATIONAL =
          AccumulatorManagementRing_IN_Startup;
        AccumulatorManagementRing_DW.is_Startup =
          AccumulatorManagementRing_IN_RqstPrechg;

        /* Outport: '<Root>/AMR_Status' */
        AccumulatorManagementRing_Y.AMR_Status =
          RING_STATUS_STARTUP_IN_PROGRESS_HV;

        /* Outport: '<Root>/AMR_ContactorRequest' */
        AccumulatorManagementRing_Y.AMR_ContactorRequest = 1.0;
      }
      break;

     default:
      /* case IN_Shutdown: */
      if (AccumulatorManagementRing_DW.is_Shutdown ==
          AccumulatorManagementRing_IN_ShutdownComplete) {
        /* Outport: '<Root>/AMR_Status' */
        AccumulatorManagementRing_Y.AMR_Status =
          RING_STATUS_SHUTDOWN_COMPLETE_HV;
      } else {
        /* Outport: '<Root>/AMR_Status' */
        /* case IN_ShutdownInProgress: */
        AccumulatorManagementRing_Y.AMR_Status =
          RING_STATUS_SHUTDOWN_IN_PROGRESS_HV;

        /* Outport: '<Root>/AMR_ContactorRequest' */
        AccumulatorManagementRing_Y.AMR_ContactorRequest = 0.0;
        if ((!AccumulatorManagementRing_U.K1Precharge) &&
            (!AccumulatorManagementRing_U.K2HvPositive) &&
            (!AccumulatorManagementRing_U.K3Negative)) {
          AccumulatorManagementRing_DW.is_Shutdown =
            AccumulatorManagementRing_IN_ShutdownComplete;

          /* Outport: '<Root>/AMR_Status' */
          AccumulatorManagementRing_Y.AMR_Status =
            RING_STATUS_SHUTDOWN_COMPLETE_HV;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/ ModeSelection' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S3>/Constant'
   *  Outport: '<Root>/AMR_Status'
   *  RelationalOperator: '<S3>/Compare'
   */
  rtb_Switch_o = (AccumulatorManagementRing_Y.AMR_Status == RING_STATUS_RUNNING);

  /* Outport: '<Root>/AMR_ChargeLimit' incorporates:
   *  Inport: '<Root>/AMS_ChgLmt'
   *  Product: '<S4>/Product'
   */
  AccumulatorManagementRing_Y.AMR_ChargeLimit =
    AccumulatorManagementRing_U.AMS_ChgLmt * rtb_Switch_o;

  /* Outport: '<Root>/AMR_DischargeLimit' incorporates:
   *  Inport: '<Root>/AMS_DChgLmt'
   *  Product: '<S4>/Product1'
   */
  AccumulatorManagementRing_Y.AMR_DischargeLimit =
    AccumulatorManagementRing_U.AMS_DChgLmt * rtb_Switch_o;

  /* Outputs for Enabled SubSystem: '<Root>/AMS Faults' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* UnitDelay: '<Root>/Unit Delay' */
  if (AccumulatorManagementRing_DW.UnitDelay_DSTATE_e) {
    /* S-Function (scominttobit): '<S2>/Integer to Bit Converter' incorporates:
     *  Inport: '<Root>/AMS_Level_Faults'
     */
    /* Integer to Bit Conversion */
    i = 0;
    u = AccumulatorManagementRing_U.AMS_Level_Faults;
    for (j = 0; j < 8; j++) {
      rtb_IntegertoBitConverter[i] = (uint8_T)(u & 1U);
      u = (int32_T)((uint32_T)u >> 1);
      i++;
    }

    /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter' */

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    for (i = 0; i < 8; i++) {
      rtb_DataTypeConversion[i] = (rtb_IntegertoBitConverter[i] != 0);
    }

    /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

    /* DiscreteFir: '<S15>/MovingAverage' incorporates:
     *  Inport: '<Root>/AMS_Vltg'
     */
    acc1 = AccumulatorManagementRing_U.AMS_Vltg * 0.002;
    for (j = AccumulatorManagementRing_DW.MovingAverage_circBuf; j < 499; j++) {
      acc1 += AccumulatorManagementRing_DW.MovingAverage_states[j] * 0.002;
    }

    for (j = 0; j < AccumulatorManagementRing_DW.MovingAverage_circBuf; j++) {
      acc1 += AccumulatorManagementRing_DW.MovingAverage_states[j] * 0.002;
    }

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S14>/Constant4'
     *  Constant: '<S16>/Constant'
     *  Inport: '<Root>/AMS_Vltg'
     *  RelationalOperator: '<S14>/Relational Operator4'
     *  UnitDelay: '<S16>/Unit Delay'
     */
    if (AccumulatorManagementRing_U.AMS_Vltg > 600.0) {
      rtb_Switch_o = AccumulatorManagementRing_DW.UnitDelay_DSTATE;
    } else {
      rtb_Switch_o = 0.0;
    }

    /* End of Switch: '<S16>/Switch' */

    /* Product: '<S2>/Product2' incorporates:
     *  Inport: '<Root>/AMS_Crnt'
     *  Inport: '<Root>/AMS_Vltg'
     */
    Product2 = AccumulatorManagementRing_U.AMS_Vltg *
      AccumulatorManagementRing_U.AMS_Crnt;

    /* DiscreteFir: '<S10>/MovingAverage' */
    acc1_0 = Product2 * 0.002;
    for (j = AccumulatorManagementRing_DW.MovingAverage_circBuf_j; j < 499; j++)
    {
      acc1_0 += AccumulatorManagementRing_DW.MovingAverage_states_b[j] * 0.002;
    }

    for (j = 0; j < AccumulatorManagementRing_DW.MovingAverage_circBuf_j; j++) {
      acc1_0 += AccumulatorManagementRing_DW.MovingAverage_states_b[j] * 0.002;
    }

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S9>/Constant6'
     *  RelationalOperator: '<S9>/Relational Operator6'
     */
    if (!(Product2 > 80000.0)) {
      AccumulatorManagementRing_DW.UnitDelay_DSTATE_a = 0.0;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Outport: '<Root>/AMS_Shutdown_Request' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S14>/Constant5'
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S9>/Constant7'
     *  DiscreteFir: '<S10>/MovingAverage'
     *  DiscreteFir: '<S15>/MovingAverage'
     *  Inport: '<Root>/AMS_Fault_Code'
     *  Inport: '<Root>/AMS_HLIM'
     *  Inport: '<Root>/AMS_LLIM'
     *  Inport: '<Root>/BmsFault'
     *  Inport: '<Root>/RelayFault'
     *  Logic: '<S2>/Logical Operator'
     *  Logic: '<S5>/Logical Operator'
     *  Logic: '<S6>/Logical Operator1'
     *  Logic: '<S7>/Logical Operator'
     *  RelationalOperator: '<S13>/Relational Operator'
     *  RelationalOperator: '<S14>/Relational Operator5'
     *  RelationalOperator: '<S5>/Relational Operator'
     *  RelationalOperator: '<S5>/Relational Operator1'
     *  RelationalOperator: '<S8>/Relational Operator2'
     *  RelationalOperator: '<S9>/Relational Operator7'
     */
    AccumulatorManagementRing_Y.AMS_Shutdown_Request = (rtb_DataTypeConversion[0]
      || rtb_DataTypeConversion[1] || rtb_DataTypeConversion[2] ||
      rtb_DataTypeConversion[3] || rtb_DataTypeConversion[4] ||
      rtb_DataTypeConversion[5] || rtb_DataTypeConversion[6] ||
      rtb_DataTypeConversion[7] || ((AccumulatorManagementRing_U.AMS_Fault_Code >
      0) && (AccumulatorManagementRing_U.AMS_Fault_Code <= 19)) || ((acc1 >
      600.0) || (rtb_Switch_o > 0.1)) || ((acc1_0 > 80000.0) ||
      (AccumulatorManagementRing_DW.UnitDelay_DSTATE_a > 0.1)) ||
      AccumulatorManagementRing_U.AMS_HLIM ||
      AccumulatorManagementRing_U.AMS_LLIM ||
      AccumulatorManagementRing_U.BmsFault ||
      AccumulatorManagementRing_U.RelayFault);

    /* SampleTimeMath: '<S11>/Weighted Sample Time' incorporates:
     *  UnitDelay: '<S11>/Unit Delay'
     *
     * About '<S11>/Weighted Sample Time':
     *  y = u + K where K = ( w * Ts )
     */
    AccumulatorManagementRing_DW.UnitDelay_DSTATE_a += 0.001;

    /* SampleTimeMath: '<S16>/Weighted Sample Time' incorporates:
     *  UnitDelay: '<S16>/Unit Delay'
     *
     * About '<S16>/Weighted Sample Time':
     *  y = u + K where K = ( w * Ts )
     */
    AccumulatorManagementRing_DW.UnitDelay_DSTATE = rtb_Switch_o + 0.001;

    /* Update for DiscreteFir: '<S15>/MovingAverage' incorporates:
     *  Inport: '<Root>/AMS_Vltg'
     */
    /* Update circular buffer index */
    AccumulatorManagementRing_DW.MovingAverage_circBuf--;
    if (AccumulatorManagementRing_DW.MovingAverage_circBuf < 0) {
      AccumulatorManagementRing_DW.MovingAverage_circBuf = 498;
    }

    /* Update circular buffer */
    AccumulatorManagementRing_DW.MovingAverage_states[AccumulatorManagementRing_DW.MovingAverage_circBuf]
      = AccumulatorManagementRing_U.AMS_Vltg;

    /* End of Update for DiscreteFir: '<S15>/MovingAverage' */

    /* Update for DiscreteFir: '<S10>/MovingAverage' */
    /* Update circular buffer index */
    AccumulatorManagementRing_DW.MovingAverage_circBuf_j--;
    if (AccumulatorManagementRing_DW.MovingAverage_circBuf_j < 0) {
      AccumulatorManagementRing_DW.MovingAverage_circBuf_j = 498;
    }

    /* Update circular buffer */
    AccumulatorManagementRing_DW.MovingAverage_states_b[AccumulatorManagementRing_DW.MovingAverage_circBuf_j]
      = Product2;

    /* End of Update for DiscreteFir: '<S10>/MovingAverage' */
  }

  /* End of Outputs for SubSystem: '<Root>/AMS Faults' */

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Outport: '<Root>/AMS_Shutdown_Request'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  AccumulatorManagementRing_DW.UnitDelay_DSTATE_e =
    !AccumulatorManagementRing_Y.AMS_Shutdown_Request;

  /* Outport: '<Root>/AMS_Power' incorporates:
   *  Inport: '<Root>/AMS_Crnt'
   *  Inport: '<Root>/AMS_Vltg'
   *  Product: '<Root>/AccumulatorPower'
   */
  AccumulatorManagementRing_Y.AMS_Power = AccumulatorManagementRing_U.AMS_Vltg *
    AccumulatorManagementRing_U.AMS_Crnt;
}

/* Model initialize function */
void AccumulatorManagementRing_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void AccumulatorManagementRing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
