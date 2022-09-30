/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CoolingControlRing.c
 *
 * Code generated for Simulink model 'CoolingControlRing'.
 *
 * Model version                  : 1.114
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Mar 20 20:09:03 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CoolingControlRing.h"
#include "CoolingControlRing_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define CoolingCont_IN_PUMP_FAN_TESTING ((uint8_T)1U)
#define CoolingContr_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define CoolingContr_IN_TestingComplete ((uint8_T)4U)
#define CoolingContro_IN_SENSOR_TESTING ((uint8_T)3U)
#define CoolingControlRi_IN_OPERATIONAL ((uint8_T)2U)
#define CoolingControlRing_IN_OFF      ((uint8_T)1U)
#define CoolingControlRing_IN_RUNNING  ((uint8_T)2U)
#define CoolingControlRing_IN_SHUTDOWN ((uint8_T)3U)

/* Block signals (default storage) */
B_CoolingControlRing_T CoolingControlRing_B;

/* Block states (default storage) */
DW_CoolingControlRing_T CoolingControlRing_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CoolingControlRing_T CoolingControlRing_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_CoolingControlRing_T CoolingControlRing_Y;

/* Real-time model */
RT_MODEL_CoolingControlRing_T CoolingControlRing_M_;
RT_MODEL_CoolingControlRing_T *const CoolingControlRing_M =
  &CoolingControlRing_M_;

/* Forward declaration for local functions */
static void CoolingControlRing_SensorSanity(void);

/* Function for Chart: '<Root>/Chart' */
static void CoolingControlRing_SensorSanity(void)
{
  /* Inport: '<Root>/MotorTempFL' */
  CoolingControlRing_B.MotorTemperatureFrontLeftFault =
    ((CoolingControlRing_U.MotorTempFL > 100.0) ||
     (CoolingControlRing_U.MotorTempFL < 0.0));

  /* Inport: '<Root>/MotorTempFR' */
  CoolingControlRing_B.MotorTemperatureFrontRightFault =
    ((CoolingControlRing_U.MotorTempFR > 100.0) ||
     (CoolingControlRing_U.MotorTempFR < 0.0));

  /* Inport: '<Root>/MotorTempBL' */
  CoolingControlRing_B.MotorTemperatureRearLeftFault =
    ((CoolingControlRing_U.MotorTempBL > 100.0) ||
     (CoolingControlRing_U.MotorTempBL < 0.0));

  /* Inport: '<Root>/MotorTempBR' */
  CoolingControlRing_B.MotorTemperatureRearRightFault =
    ((CoolingControlRing_U.MotorTempBR > 100.0) ||
     (CoolingControlRing_U.MotorTempBR < 0.0));

  /* Inport: '<Root>/Velocity' */
  CoolingControlRing_B.velocity_error = ((CoolingControlRing_U.Velocity > 200.0)
    || (CoolingControlRing_U.Velocity < -50.0));

  /* Inport: '<Root>/InverterCoolingPlateTemp' */
  CoolingControlRing_B.InverterCoolingPlateTemperature =
    ((CoolingControlRing_U.InverterCoolingPlateTemp > 100.0) ||
     (CoolingControlRing_U.InverterCoolingPlateTemp < 0.0));

  /* Inport: '<Root>/MotorLoopFluidTemp' */
  CoolingControlRing_B.MotorLoopFluidTemperatureFault =
    ((CoolingControlRing_U.MotorLoopFluidTemp > 100.0) ||
     (CoolingControlRing_U.MotorLoopFluidTemp < 0.0));

  /* Inport: '<Root>/InverterLoopFluidTemp' */
  CoolingControlRing_B.InverterLoopFluidTemperatureFau =
    ((CoolingControlRing_U.InverterLoopFluidTemp > 100.0) ||
     (CoolingControlRing_U.InverterLoopFluidTemp < 0.0));

  /* Inport: '<Root>/MotorLoopPressure' */
  CoolingControlRing_B.MotorLoopPressureFault =
    ((CoolingControlRing_U.MotorLoopPressure > 25.5) ||
     (CoolingControlRing_U.MotorLoopPressure < 10.5));

  /* Inport: '<Root>/InverterLoopPressure' */
  CoolingControlRing_B.InverterLoopPressureFault =
    ((CoolingControlRing_U.InverterLoopPressure > 25.5) ||
     (CoolingControlRing_U.InverterLoopPressure < 10.5));
}

/* Model step function */
void CoolingControlRing_step(void)
{
  int32_T tmp;
  uint32_T tmp_0;
  int32_T rtb_Gain;
  uint8_T u1;
  uint8_T u1_0;
  uint8_T u1_1;
  uint8_T u1_2;
  uint8_T u1_3;
  uint8_T u1_4;
  uint8_T u1_5;
  uint8_T u1_6;
  uint8_T u1_7;
  uint32_T u1_8;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/ModeRequest'
   */
  if (CoolingControlRing_DW.is_active_c2_CoolingControlRing == 0U) {
    CoolingControlRing_DW.is_active_c2_CoolingControlRing = 1U;
    CoolingControlRing_DW.is_c2_CoolingControlRing = CoolingControlRing_IN_OFF;

    /* Outport: '<Root>/CR_Motor_Loop_Pump_PWM' */
    CoolingControlRing_Y.CR_Motor_Loop_Pump_PWM = 0.0;

    /* Outport: '<Root>/CR_Motor_Loop_Fan_PWM' */
    CoolingControlRing_Y.CR_Motor_Loop_Fan_PWM = 0.0;

    /* Outport: '<Root>/CR_Inverter_Loop_Pump_PWM' */
    CoolingControlRing_Y.CR_Inverter_Loop_Pump_PWM = 0.0;

    /* Outport: '<Root>/CR_Inverter_Loop_Fan_PWM' */
    CoolingControlRing_Y.CR_Inverter_Loop_Fan_PWM = 0.0;

    /* Outport: '<Root>/CcrStatus' */
    CoolingControlRing_Y.CcrStatus = RING_STATUS_OFF;
    CoolingControlRing_SensorSanity();
  } else {
    switch (CoolingControlRing_DW.is_c2_CoolingControlRing) {
     case CoolingControlRing_IN_OFF:
      if (CoolingControlRing_U.ModeRequest == MSR_REQUEST_STARTUP_LV) {
        CoolingControlRing_DW.is_c2_CoolingControlRing =
          CoolingControlRi_IN_OPERATIONAL;

        /* Outport: '<Root>/CcrStatus' */
        CoolingControlRing_Y.CcrStatus = RING_STATUS_SHUTDOWN_IN_PROGRESS_LV;
        CoolingControlRing_DW.is_OPERATIONAL = CoolingContro_IN_SENSOR_TESTING;
        CoolingControlRing_DW.sensorsWorking = 0.0;
      }
      break;

     case CoolingControlRi_IN_OPERATIONAL:
      if (CoolingControlRing_U.ModeRequest == MSR_REQUEST_SHUTDOWN_LV) {
        CoolingControlRing_DW.is_OPERATIONAL = CoolingContr_IN_NO_ACTIVE_CHILD;
        CoolingControlRing_DW.is_c2_CoolingControlRing =
          CoolingControlRing_IN_SHUTDOWN;

        /* Outport: '<Root>/CcrStatus' */
        CoolingControlRing_Y.CcrStatus = RING_STATUS_SHUTDOWN_COMPLETE_LV;
      } else {
        switch (CoolingControlRing_DW.is_OPERATIONAL) {
         case CoolingCont_IN_PUMP_FAN_TESTING:
          if (CoolingControlRing_DW.pumpAndFansWorking == 1.0) {
            CoolingControlRing_DW.is_OPERATIONAL =
              CoolingContr_IN_TestingComplete;

            /* Outport: '<Root>/CcrStatus' */
            CoolingControlRing_Y.CcrStatus = RING_STATUS_STARTUP_COMPLETE_LV;
          } else {
            /* Outputs for Function Call SubSystem: '<S1>/OPERATIONAL.PUMP_FAN_TESTING.Pump_and_fan_test' */
            /* RelationalOperator: '<S8>/Compare' incorporates:
             *  Constant: '<S8>/Constant'
             *  Inport: '<Root>/InverterLoopPressure'
             */
            u1 = (uint8_T)(CoolingControlRing_U.InverterLoopPressure >= 13.5);

            /* MinMax: '<S6>/MinMax' incorporates:
             *  Constant: '<S7>/Constant'
             *  Inport: '<Root>/MotorLoopPressure'
             *  RelationalOperator: '<S7>/Compare'
             */
            if ((CoolingControlRing_U.MotorLoopPressure >= 13.5) < u1) {
              CoolingControlRing_DW.pumpAndFansWorking = 0.0;
            } else {
              CoolingControlRing_DW.pumpAndFansWorking = u1;
            }

            /* End of MinMax: '<S6>/MinMax' */
            /* End of Outputs for SubSystem: '<S1>/OPERATIONAL.PUMP_FAN_TESTING.Pump_and_fan_test' */
          }
          break;

         case CoolingControlRing_IN_RUNNING:
          /* Outputs for Function Call SubSystem: '<S1>/OPERATIONAL.RUNNING.running_motor' */
          /* MinMax: '<S16>/MinMax2' incorporates:
           *  Constant: '<S19>/Constant'
           *  Constant: '<S20>/Constant'
           *  Gain: '<S16>/Gain1'
           *  Inport: '<Root>/MotorLoopFluidTemp'
           *  RelationalOperator: '<S19>/Compare'
           *  RelationalOperator: '<S20>/Compare'
           */
          rtb_Gain = (int32_T)((uint32_T)
                               (CoolingControlRing_U.MotorLoopFluidTemp > 30.0) <<
                               8);
          tmp = (CoolingControlRing_U.MotorLoopFluidTemp <= 30.0) << 7;
          if ((uint32_T)rtb_Gain > (uint32_T)tmp) {
            /* Outport: '<Root>/CR_Motor_Loop_Pump_PWM' */
            CoolingControlRing_Y.CR_Motor_Loop_Pump_PWM = (real_T)rtb_Gain *
              0.00390625;
          } else {
            /* Outport: '<Root>/CR_Motor_Loop_Pump_PWM' */
            CoolingControlRing_Y.CR_Motor_Loop_Pump_PWM = (real_T)tmp *
              0.00390625;
          }

          /* End of MinMax: '<S16>/MinMax2' */

          /* Outport: '<Root>/CR_Motor_Loop_Fan_PWM' incorporates:
           *  Constant: '<S17>/Constant'
           *  Constant: '<S18>/Constant'
           *  Inport: '<Root>/MotorLoopFluidTemp'
           *  Inport: '<Root>/Velocity'
           *  Product: '<S16>/Product'
           *  RelationalOperator: '<S17>/Compare'
           *  RelationalOperator: '<S18>/Compare'
           */
          CoolingControlRing_Y.CR_Motor_Loop_Fan_PWM =
            CoolingControlRing_U.Velocity < 10.0 ? (real_T)
            (CoolingControlRing_U.MotorLoopFluidTemp > 30.0) : 0.0;

          /* End of Outputs for SubSystem: '<S1>/OPERATIONAL.RUNNING.running_motor' */

          /* Outputs for Function Call SubSystem: '<S1>/OPERATIONAL.RUNNING.running_inverter' */
          /* Gain: '<S9>/Gain' incorporates:
           *  Constant: '<S14>/Constant'
           *  Constant: '<S15>/Constant'
           *  Inport: '<Root>/InverterCoolingPlateTemp'
           *  Inport: '<Root>/InverterLoopFluidTemp'
           *  Product: '<S9>/Product1'
           *  RelationalOperator: '<S14>/Compare'
           *  RelationalOperator: '<S15>/Compare'
           */
          rtb_Gain = (int32_T)(((uint32_T)
                                (CoolingControlRing_U.InverterCoolingPlateTemp >
            25.0) * (CoolingControlRing_U.InverterLoopFluidTemp <= 25.0)) << 15);

          /* MinMax: '<S9>/MinMax1' incorporates:
           *  Constant: '<S13>/Constant'
           *  Inport: '<Root>/InverterLoopFluidTemp'
           *  RelationalOperator: '<S13>/Compare'
           */
          tmp_0 = (uint32_T)(CoolingControlRing_U.InverterLoopFluidTemp > 25.0) <<
            16;

          /* Product: '<S9>/Product' incorporates:
           *  Constant: '<S10>/Constant'
           *  Constant: '<S12>/Constant'
           *  Inport: '<Root>/InverterLoopFluidTemp'
           *  Inport: '<Root>/Velocity'
           *  RelationalOperator: '<S10>/Compare'
           *  RelationalOperator: '<S12>/Compare'
           */
          u1_8 = (uint32_T)(CoolingControlRing_U.InverterLoopFluidTemp > 20.0) *
            (CoolingControlRing_U.Velocity < 10.0);

          /* MinMax: '<S9>/MinMax' incorporates:
           *  Constant: '<S11>/Constant'
           *  Inport: '<Root>/InverterLoopFluidTemp'
           *  RelationalOperator: '<S11>/Compare'
           */
          if ((uint32_T)(CoolingControlRing_U.InverterLoopFluidTemp > 28.0) >
              u1_8) {
            /* Outport: '<Root>/CR_Inverter_Loop_Fan_PWM' */
            CoolingControlRing_Y.CR_Inverter_Loop_Fan_PWM = 1.0;
          } else {
            /* Outport: '<Root>/CR_Inverter_Loop_Fan_PWM' */
            CoolingControlRing_Y.CR_Inverter_Loop_Fan_PWM = u1_8;
          }

          /* End of MinMax: '<S9>/MinMax' */

          /* MinMax: '<S9>/MinMax1' */
          if ((uint32_T)rtb_Gain > tmp_0) {
            /* Outport: '<Root>/CR_Inverter_Loop_Pump_PWM' */
            CoolingControlRing_Y.CR_Inverter_Loop_Pump_PWM = (real_T)rtb_Gain *
              1.52587890625E-5;
          } else {
            /* Outport: '<Root>/CR_Inverter_Loop_Pump_PWM' */
            CoolingControlRing_Y.CR_Inverter_Loop_Pump_PWM = (real_T)tmp_0 *
              1.52587890625E-5;
          }

          /* End of Outputs for SubSystem: '<S1>/OPERATIONAL.RUNNING.running_inverter' */
          break;

         case CoolingContro_IN_SENSOR_TESTING:
          if (CoolingControlRing_DW.sensorsWorking == 1.0) {
            CoolingControlRing_DW.is_OPERATIONAL =
              CoolingCont_IN_PUMP_FAN_TESTING;
            CoolingControlRing_DW.pumpAndFansWorking = 0.0;

            /* Outport: '<Root>/CR_Motor_Loop_Pump_PWM' */
            CoolingControlRing_Y.CR_Motor_Loop_Pump_PWM = 0.7;

            /* Outport: '<Root>/CR_Motor_Loop_Fan_PWM' */
            CoolingControlRing_Y.CR_Motor_Loop_Fan_PWM = 0.7;

            /* Outport: '<Root>/CR_Inverter_Loop_Pump_PWM' */
            CoolingControlRing_Y.CR_Inverter_Loop_Pump_PWM = 0.7;

            /* Outport: '<Root>/CR_Inverter_Loop_Fan_PWM' */
            CoolingControlRing_Y.CR_Inverter_Loop_Fan_PWM = 0.7;
          } else {
            CoolingControlRing_SensorSanity();

            /* Outputs for Function Call SubSystem: '<S1>/OPERATIONAL.SENSOR_TESTING.Sensors_working' */
            /* RelationalOperator: '<S23>/Compare' incorporates:
             *  Constant: '<S23>/Constant'
             */
            u1 = (uint8_T)(CoolingControlRing_B.MotorTemperatureFrontRightFault ==
                           0.0);

            /* RelationalOperator: '<S27>/Compare' incorporates:
             *  Constant: '<S27>/Constant'
             */
            u1_0 = (uint8_T)(CoolingControlRing_B.MotorTemperatureRearLeftFault ==
                             0.0);

            /* RelationalOperator: '<S28>/Compare' incorporates:
             *  Constant: '<S28>/Constant'
             */
            u1_1 = (uint8_T)(CoolingControlRing_B.MotorTemperatureRearRightFault
                             == 0.0);

            /* RelationalOperator: '<S29>/Compare' incorporates:
             *  Constant: '<S29>/Constant'
             */
            u1_2 = (uint8_T)(CoolingControlRing_B.velocity_error == 0.0);

            /* RelationalOperator: '<S30>/Compare' incorporates:
             *  Constant: '<S30>/Constant'
             */
            u1_3 = (uint8_T)
              (CoolingControlRing_B.InverterCoolingPlateTemperature == 0.0);

            /* RelationalOperator: '<S31>/Compare' incorporates:
             *  Constant: '<S31>/Constant'
             */
            u1_4 = (uint8_T)(CoolingControlRing_B.MotorLoopFluidTemperatureFault
                             == 0.0);

            /* RelationalOperator: '<S24>/Compare' incorporates:
             *  Constant: '<S24>/Constant'
             */
            u1_5 = (uint8_T)
              (CoolingControlRing_B.InverterLoopFluidTemperatureFau == 0.0);

            /* RelationalOperator: '<S25>/Compare' incorporates:
             *  Constant: '<S25>/Constant'
             */
            u1_6 = (uint8_T)(CoolingControlRing_B.MotorLoopPressureFault == 0.0);

            /* RelationalOperator: '<S26>/Compare' incorporates:
             *  Constant: '<S26>/Constant'
             */
            u1_7 = (uint8_T)(CoolingControlRing_B.InverterLoopPressureFault ==
                             0.0);

            /* MinMax: '<S21>/MinMax' incorporates:
             *  Constant: '<S22>/Constant'
             *  RelationalOperator: '<S22>/Compare'
             */
            if ((CoolingControlRing_B.MotorTemperatureFrontLeftFault == 0.0) <
                u1) {
              u1 = 0U;
            }

            if (u1 < u1_0) {
              u1_0 = 0U;
            }

            if (u1_0 < u1_1) {
              u1_1 = 0U;
            }

            if (u1_1 < u1_2) {
              u1_2 = 0U;
            }

            if (u1_2 < u1_3) {
              u1_3 = 0U;
            }

            if (u1_3 < u1_4) {
              u1_4 = 0U;
            }

            if (u1_4 < u1_5) {
              u1_5 = 0U;
            }

            if (u1_5 < u1_6) {
              u1_6 = 0U;
            }

            if (u1_6 < u1_7) {
              CoolingControlRing_DW.sensorsWorking = 0.0;
            } else {
              CoolingControlRing_DW.sensorsWorking = u1_7;
            }

            /* End of MinMax: '<S21>/MinMax' */
            /* End of Outputs for SubSystem: '<S1>/OPERATIONAL.SENSOR_TESTING.Sensors_working' */
          }
          break;

         default:
          /* case IN_TestingComplete: */
          if (CoolingControlRing_U.ModeRequest == MSR_REQUEST_RUNNING) {
            CoolingControlRing_DW.is_OPERATIONAL = CoolingControlRing_IN_RUNNING;

            /* Outport: '<Root>/CcrStatus' */
            CoolingControlRing_Y.CcrStatus = RING_STATUS_RUNNING;
          }
          break;
        }
      }
      break;

     default:
      /* case IN_SHUTDOWN: */
      if (CoolingControlRing_U.ModeRequest == MSR_REQUEST_OFF) {
        CoolingControlRing_DW.is_c2_CoolingControlRing =
          CoolingControlRing_IN_OFF;

        /* Outport: '<Root>/CR_Motor_Loop_Pump_PWM' */
        CoolingControlRing_Y.CR_Motor_Loop_Pump_PWM = 0.0;

        /* Outport: '<Root>/CR_Motor_Loop_Fan_PWM' */
        CoolingControlRing_Y.CR_Motor_Loop_Fan_PWM = 0.0;

        /* Outport: '<Root>/CR_Inverter_Loop_Pump_PWM' */
        CoolingControlRing_Y.CR_Inverter_Loop_Pump_PWM = 0.0;

        /* Outport: '<Root>/CR_Inverter_Loop_Fan_PWM' */
        CoolingControlRing_Y.CR_Inverter_Loop_Fan_PWM = 0.0;

        /* Outport: '<Root>/CcrStatus' */
        CoolingControlRing_Y.CcrStatus = RING_STATUS_OFF;
        CoolingControlRing_SensorSanity();
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Outport: '<Root>/CrFaults' incorporates:
   *  Logic: '<Root>/Logical Operator'
   */
  CoolingControlRing_Y.CrFaults =
    ((CoolingControlRing_B.MotorTemperatureFrontLeftFault != 0.0) ||
     (CoolingControlRing_B.MotorTemperatureFrontRightFault != 0.0) ||
     (CoolingControlRing_B.MotorTemperatureRearLeftFault != 0.0) ||
     (CoolingControlRing_B.MotorTemperatureRearRightFault != 0.0) ||
     (CoolingControlRing_B.velocity_error != 0.0) ||
     (CoolingControlRing_B.InverterCoolingPlateTemperature != 0.0) ||
     (CoolingControlRing_B.InverterLoopFluidTemperatureFau != 0.0) ||
     (CoolingControlRing_B.MotorLoopPressureFault != 0.0) ||
     (CoolingControlRing_B.InverterLoopPressureFault != 0.0) ||
     (CoolingControlRing_B.MotorLoopFluidTemperatureFault != 0.0));
}

/* Model initialize function */
void CoolingControlRing_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void CoolingControlRing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
