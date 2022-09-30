/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BatteryManagementRing.c
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

#include "BatteryManagementRing.h"
#include "BatteryManagementRing_private.h"

/* Named constants for Chart: '<Root>/Diagnostics' */
#define BatteryMa_IN_STARTUP_INPROGRESS ((uint8_T)1U)
#define BatteryMan_IN_RUNNING_POWERSAVE ((uint8_T)2U)
#define BatteryMan_IN_STARTUP_LOWENERGY ((uint8_T)2U)
#define BatteryManag_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define BatteryManageme_IN_NORMAL_POWER ((uint8_T)1U)
#define BatteryManageme_IN_STARTUP_PASS ((uint8_T)3U)
#define BatteryManagemen_IN_OPERATIONAL ((uint8_T)2U)
#define BatteryManagementRi_IN_SHUTDOWN ((uint8_T)3U)
#define BatteryManagementRin_IN_RUNNING ((uint8_T)1U)
#define BatteryManagementRin_IN_STARTUP ((uint8_T)2U)
#define BatteryManagementRing_IN_OFF   ((uint8_T)1U)

/* Block states (default storage) */
DW_BatteryManagementRing_T BatteryManagementRing_DW;

/* External inputs (root inport signals with default storage) */
ExtU_BatteryManagementRing_T BatteryManagementRing_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BatteryManagementRing_T BatteryManagementRing_Y;

/* Real-time model */
RT_MODEL_BatteryManagementRin_T BatteryManagementRing_M_;
RT_MODEL_BatteryManagementRin_T *const BatteryManagementRing_M =
  &BatteryManagementRing_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
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
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
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
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Model step function */
void BatteryManagementRing_step(void)
{
  int32_T j;
  int32_T cff;
  real_T Saturation;

  /* Lookup_n-D: '<S3>/Vltg2SOC' incorporates:
   *  Inport: '<Root>/BMS_BattVoltage'
   */
  Saturation = look1_binlxpw(BatteryManagementRing_U.BMS_BattVoltage,
    BatteryManagementRing_ConstP.Vltg2SOC_bp01Data,
    BatteryManagementRing_ConstP.Vltg2SOC_tableData, 14U);

  /* Saturate: '<S3>/Saturation' */
  if (Saturation > 1.0) {
    Saturation = 1.0;
  } else {
    if (Saturation < 0.0) {
      Saturation = 0.0;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* DiscreteFir: '<S3>/LowPassFilter' */
  BatteryManagementRing_Y.BMR_BattSOC = Saturation * 0.095238095238095233;
  cff = 1;
  for (j = BatteryManagementRing_DW.LowPassFilter_circBuf; j < 20; j++) {
    BatteryManagementRing_Y.BMR_BattSOC +=
      BatteryManagementRing_DW.LowPassFilter_states[j] *
      BatteryManagementRing_ConstP.LowPassFilter_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < BatteryManagementRing_DW.LowPassFilter_circBuf; j++) {
    BatteryManagementRing_Y.BMR_BattSOC +=
      BatteryManagementRing_DW.LowPassFilter_states[j] *
      BatteryManagementRing_ConstP.LowPassFilter_Coefficients[cff];
    cff++;
  }

  /* End of DiscreteFir: '<S3>/LowPassFilter' */

  /* Chart: '<Root>/Diagnostics' incorporates:
   *  Inport: '<Root>/BMS_BattVoltage'
   *  Inport: '<Root>/MSR_ModeRequest'
   *  Outport: '<Root>/BMR_BattSOC'
   *  Outport: '<Root>/BMR_Status'
   */
  if (BatteryManagementRing_DW.temporalCounter_i1 < 15U) {
    BatteryManagementRing_DW.temporalCounter_i1++;
  }

  if (BatteryManagementRing_DW.is_active_c4_BatteryManagementR == 0U) {
    BatteryManagementRing_DW.is_active_c4_BatteryManagementR = 1U;
    BatteryManagementRing_DW.is_c4_BatteryManagementRing =
      BatteryManagementRing_IN_OFF;

    /* Outport: '<Root>/BMR_Status' */
    BatteryManagementRing_Y.BMR_Status = RING_STATUS_OFF;
  } else {
    switch (BatteryManagementRing_DW.is_c4_BatteryManagementRing) {
     case BatteryManagementRing_IN_OFF:
      if (BatteryManagementRing_U.MSR_ModeRequest == MSR_REQUEST_STARTUP_LV) {
        BatteryManagementRing_DW.is_c4_BatteryManagementRing =
          BatteryManagemen_IN_OPERATIONAL;
        BatteryManagementRing_DW.is_OPERATIONAL =
          BatteryManagementRin_IN_STARTUP;

        /* Outport: '<Root>/BMR_Status' */
        BatteryManagementRing_Y.BMR_Status = RING_STATUS_STARTUP_IN_PROGRESS_LV;
        BatteryManagementRing_DW.is_STARTUP = BatteryMa_IN_STARTUP_INPROGRESS;
        BatteryManagementRing_DW.temporalCounter_i1 = 0U;
      }
      break;

     case BatteryManagemen_IN_OPERATIONAL:
      if (BatteryManagementRing_U.MSR_ModeRequest == MSR_REQUEST_SHUTDOWN_LV) {
        BatteryManagementRing_DW.is_RUNNING = BatteryManag_IN_NO_ACTIVE_CHILD;
        BatteryManagementRing_DW.is_STARTUP = BatteryManag_IN_NO_ACTIVE_CHILD;
        BatteryManagementRing_DW.is_OPERATIONAL =
          BatteryManag_IN_NO_ACTIVE_CHILD;
        BatteryManagementRing_DW.is_c4_BatteryManagementRing =
          BatteryManagementRi_IN_SHUTDOWN;

        /* Outport: '<Root>/BMR_Status' */
        BatteryManagementRing_Y.BMR_Status = RING_STATUS_SHUTDOWN_COMPLETE_LV;
      } else if (BatteryManagementRing_DW.is_OPERATIONAL == 1) {
        if ((BatteryManagementRing_DW.is_RUNNING == 1) &&
            ((BatteryManagementRing_U.BMS_BattVoltage < 12.0) &&
             (BatteryManagementRing_Y.BMR_BattSOC < 0.2))) {
          BatteryManagementRing_DW.is_RUNNING = BatteryMan_IN_RUNNING_POWERSAVE;
        } else {
          /* case IN_RUNNING_POWERSAVE: */
        }
      } else {
        /* case IN_STARTUP: */
        if ((BatteryManagementRing_U.MSR_ModeRequest == MSR_REQUEST_RUNNING) &&
            (BatteryManagementRing_Y.BMR_Status ==
             RING_STATUS_STARTUP_COMPLETE_LV)) {
          BatteryManagementRing_DW.is_STARTUP = BatteryManag_IN_NO_ACTIVE_CHILD;
          BatteryManagementRing_DW.is_OPERATIONAL =
            BatteryManagementRin_IN_RUNNING;
          BatteryManagementRing_Y.BMR_Status = RING_STATUS_RUNNING;
          BatteryManagementRing_DW.is_RUNNING = BatteryManageme_IN_NORMAL_POWER;
        } else {
          switch (BatteryManagementRing_DW.is_STARTUP) {
           case BatteryMa_IN_STARTUP_INPROGRESS:
            if ((BatteryManagementRing_U.BMS_BattVoltage < 13.0) ||
                ((BatteryManagementRing_Y.BMR_BattSOC < 0.5) &&
                 (BatteryManagementRing_DW.temporalCounter_i1 >= 10U))) {
              BatteryManagementRing_DW.is_STARTUP =
                BatteryMan_IN_STARTUP_LOWENERGY;
            } else {
              BatteryManagementRing_DW.is_STARTUP =
                BatteryManageme_IN_STARTUP_PASS;
              BatteryManagementRing_Y.BMR_Status =
                RING_STATUS_STARTUP_COMPLETE_LV;
            }
            break;

           case BatteryMan_IN_STARTUP_LOWENERGY:
            break;

           default:
            /* case IN_STARTUP_PASS: */
            break;
          }
        }
      }
      break;

     default:
      /* case IN_SHUTDOWN: */
      break;
    }
  }

  /* End of Chart: '<Root>/Diagnostics' */

  /* Outport: '<Root>/BmrFaults' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/BMS_BattVoltage'
   *  Outport: '<Root>/BMR_BattSOC'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  BatteryManagementRing_Y.BmrFaults.UnderVoltageFault =
    (BatteryManagementRing_U.BMS_BattVoltage < 5.0);
  BatteryManagementRing_Y.BmrFaults.OverVoltageFault =
    (BatteryManagementRing_U.BMS_BattVoltage > 18.0);
  BatteryManagementRing_Y.BmrFaults.UnderBatterySocFault =
    (BatteryManagementRing_Y.BMR_BattSOC < -0.5);
  BatteryManagementRing_Y.BmrFaults.OverBatterSocFault =
    (BatteryManagementRing_Y.BMR_BattSOC > 1.5);

  /* Outport: '<Root>/BMR_BattVoltage' incorporates:
   *  Inport: '<Root>/BMS_BattVoltage'
   */
  BatteryManagementRing_Y.BMR_BattVoltage =
    BatteryManagementRing_U.BMS_BattVoltage;

  /* Update for DiscreteFir: '<S3>/LowPassFilter' */
  /* Update circular buffer index */
  BatteryManagementRing_DW.LowPassFilter_circBuf--;
  if (BatteryManagementRing_DW.LowPassFilter_circBuf < 0) {
    BatteryManagementRing_DW.LowPassFilter_circBuf = 19;
  }

  /* Update circular buffer */
  BatteryManagementRing_DW.LowPassFilter_states[BatteryManagementRing_DW.LowPassFilter_circBuf]
    = Saturation;

  /* End of Update for DiscreteFir: '<S3>/LowPassFilter' */
}

/* Model initialize function */
void BatteryManagementRing_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void BatteryManagementRing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
