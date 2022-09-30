/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ModeSelectionRing.c
 *
 * Code generated for Simulink model 'ModeSelectionRing'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Mar 20 18:04:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ModeSelectionRing.h"
#include "ModeSelectionRing_private.h"

/* Named constants for Chart: '<Root>/ModeSelectionRing' */
#define IN_ACCUMULATOR_HV_REQUEST_START ((uint8_T)1U)
#define IN_ACCUMULATOR_HV_STARTUP_FAIL ((uint8_T)2U)
#define IN_ACCUMULATOR_HV_STARTUP_PASS ((uint8_T)3U)
#define IN_VEHICLE_DYANMICS_REQUEST_SHU ((uint8_T)1U)
#define IN_VEHICLE_DYANMICS_REQUEST_STA ((uint8_T)1U)
#define IN_VEHICLE_DYANMICS_SHUTDOWN_FA ((uint8_T)2U)
#define IN_VEHICLE_DYANMICS_SHUTDOWN_PA ((uint8_T)3U)
#define IN_VEHICLE_DYANMICS_STARTUP_FAI ((uint8_T)2U)
#define IN_VEHICLE_DYANMICS_STARTUP_PAS ((uint8_T)3U)
#define IN_WAITING_FOR_RTD_AND_BRAKES1 ((uint8_T)8U)
#define M_IN_MOTORS_HV_REQUEST_SHUTDOWN ((uint8_T)1U)
#define M_IN_WAITING_FOR_RTD_AND_BRAKES ((uint8_T)7U)
#define Mo_IN_HIGH_VOLTAGE_STARTUP_FAIL ((uint8_T)2U)
#define Mo_IN_MOTORS_HV_REQUEST_STARTUP ((uint8_T)1U)
#define Mo_IN_MOTORS_LV_REQUEST_STARTUP ((uint8_T)1U)
#define Mo_IN_VEHICLE_DYNAMICS_SHUTDOWN ((uint8_T)5U)
#define Mod_IN_COOLING_REQUEST_SHUTDOWN ((uint8_T)1U)
#define Mod_IN_LOW_VOLTAGE_STARTUP_FAIL ((uint8_T)3U)
#define Mod_IN_TRACTIVE_SYSTEM_SHUTDOWN ((uint8_T)4U)
#define Mod_IN_VEHICLE_DYNAMICS_STARTUP ((uint8_T)4U)
#define ModeS_IN_ACCUMULATOR_HV_STARTUP ((uint8_T)1U)
#define ModeS_IN_MOTORS_HV_STARTUP_FAIL ((uint8_T)2U)
#define ModeS_IN_MOTORS_HV_STARTUP_PASS ((uint8_T)3U)
#define ModeS_IN_MOTORS_LV_STARTUP_FAIL ((uint8_T)2U)
#define ModeS_IN_MOTORS_LV_STARTUP_PASS ((uint8_T)3U)
#define ModeS_IN_ReadyToDriveSoundStart ((uint8_T)6U)
#define ModeSe_IN_COOLING_SHUTDOWN_FAIL ((uint8_T)2U)
#define ModeSe_IN_COOLING_SHUTDOWN_PASS ((uint8_T)3U)
#define ModeSe_IN_SYSTEM_MODE_SELECTION ((uint8_T)2U)
#define ModeSel_IN_COOLING_STARTUP_FAIL ((uint8_T)2U)
#define ModeSel_IN_COOLING_STARTUP_PASS ((uint8_T)3U)
#define ModeSel_IN_ReadyToDriveSoundEnd ((uint8_T)5U)
#define ModeSelect_IN_MOTORS_HV_STARTUP ((uint8_T)3U)
#define ModeSelect_IN_MOTORS_LV_STARTUP ((uint8_T)4U)
#define ModeSelecti_IN_COOLING_SHUTDOWN ((uint8_T)1U)
#define ModeSelecti_IN_ShutdownComplete ((uint8_T)3U)
#define ModeSelectio_IN_COOLING_STARTUP ((uint8_T)1U)
#define ModeSelectio_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ModeSelectionR_IN_SHUTDOWN_FAIL ((uint8_T)2U)
#define ModeSelectionRi_IN_HIGH_VOLTAGE ((uint8_T)2U)
#define ModeSelectionRing_IN_NORMAL    ((uint8_T)2U)
#define ModeSelectionRing_IN_OPERATION ((uint8_T)1U)
#define ModeSelectionRing_IN_SHUTDOWN  ((uint8_T)2U)
#define ModeSelectionRing_IN_STARTUP   ((uint8_T)1U)
#define Mode_IN_COOLING_REQUEST_STARTUP ((uint8_T)1U)
#define Mode_IN_MOTORS_HV_SHUTDOWN_FAIL ((uint8_T)2U)
#define Mode_IN_MOTORS_HV_SHUTDOWN_PASS ((uint8_T)3U)

/* Block states (default storage) */
DW_ModeSelectionRing_T ModeSelectionRing_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ModeSelectionRing_T ModeSelectionRing_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ModeSelectionRing_T ModeSelectionRing_Y;

/* Real-time model */
RT_MODEL_ModeSelectionRing_T ModeSelectionRing_M_;
RT_MODEL_ModeSelectionRing_T *const ModeSelectionRing_M = &ModeSelectionRing_M_;

/* Forward declaration for local functions */
static void Mode_exit_internal_HIGH_VOLTAGE(void);
static void ModeSelectionRing_HIGH_VOLTAGE(const boolean_T *Compare);
static void ModeSelec_exit_internal_STARTUP(void);
static void ModeSelectionRing_STARTUP(const boolean_T *Compare);
static void ModeSelectionRing_SHUTDOWN(void);

/* Function for Chart: '<Root>/ModeSelectionRing' */
static void Mode_exit_internal_HIGH_VOLTAGE(void)
{
  ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP =
    ModeSelectio_IN_NO_ACTIVE_CHILD;
  ModeSelectionRing_DW.is_MOTORS_HV_STARTUP = ModeSelectio_IN_NO_ACTIVE_CHILD;

  /* Outport: '<Root>/MSR_leaf_state1' */
  ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_None;
  ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_STARTUP =
    ModeSelectio_IN_NO_ACTIVE_CHILD;
  ModeSelectionRing_DW.is_HIGH_VOLTAGE = ModeSelectio_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<Root>/ModeSelectionRing' */
static void ModeSelectionRing_HIGH_VOLTAGE(const boolean_T *Compare)
{
  if (!*Compare) {
    Mode_exit_internal_HIGH_VOLTAGE();
    ModeSelectionRing_DW.is_STARTUP = IN_WAITING_FOR_RTD_AND_BRAKES1;

    /* Outport: '<Root>/MSR_leaf_state1' */
    ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_WAITING_FOR_RTD_AND_BRAKES1;
    ModeSelectionRing_DW.internalShutdown = true;
  } else {
    switch (ModeSelectionRing_DW.is_HIGH_VOLTAGE) {
     case ModeS_IN_ACCUMULATOR_HV_STARTUP:
      if (ModeSelectionRing_DW.accumulatorHvStartupPass) {
        ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_HIGH_VOLTAGE = ModeSelect_IN_MOTORS_HV_STARTUP;
        ModeSelectionRing_DW.is_MOTORS_HV_STARTUP =
          Mo_IN_MOTORS_HV_REQUEST_STARTUP;
        ModeSelectionRing_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_MOTORS_HV_REQUEST_STARTUP;

        /* Outport: '<Root>/TMR_ModeRequest' */
        ModeSelectionRing_Y.TMR_ModeRequest = MSR_REQUEST_STARTUP_HV;
      } else if (ModeSelectionRing_DW.accumulatorHvStartupFail) {
        ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_HIGH_VOLTAGE = Mo_IN_HIGH_VOLTAGE_STARTUP_FAIL;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_HIGH_VOLTAGE_STARTUP_FAIL;
      } else {
        if (ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP ==
            IN_ACCUMULATOR_HV_REQUEST_START) {
          /* Inport: '<Root>/AmrStatus' */
          if (ModeSelectionRing_U.AmrStatus == RING_STATUS_STARTUP_COMPLETE_HV)
          {
            ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP =
              IN_ACCUMULATOR_HV_STARTUP_PASS;

            /* Outport: '<Root>/MSR_leaf_state1' */
            ModeSelectionRing_Y.MSR_leaf_state1 =
              MSR_States_ACCUMULATOR_HV_STARTUP_PASS;
            ModeSelectionRing_DW.accumulatorHvStartupPass = true;
          } else {
            if (ModeSelectionRing_DW.temporalCounter_i1 >= 10000U) {
              ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP =
                IN_ACCUMULATOR_HV_STARTUP_FAIL;

              /* Outport: '<Root>/MSR_leaf_state1' */
              ModeSelectionRing_Y.MSR_leaf_state1 =
                MSR_States_ACCUMULATOR_HV_STARTUP_FAIL;
              ModeSelectionRing_DW.accumulatorHvStartupFail = true;
            }
          }

          /* End of Inport: '<Root>/AmrStatus' */
        }
      }
      break;

     case Mo_IN_HIGH_VOLTAGE_STARTUP_FAIL:
      break;

     case ModeSelect_IN_MOTORS_HV_STARTUP:
      if (ModeSelectionRing_DW.motorHvStartupPass) {
        ModeSelectionRing_DW.is_MOTORS_HV_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_HIGH_VOLTAGE = Mod_IN_VEHICLE_DYNAMICS_STARTUP;
        ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_STARTUP =
          IN_VEHICLE_DYANMICS_REQUEST_STA;
        ModeSelectionRing_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_VEHICLE_DYANMICS_REQUEST_STARTUP;

        /* Outport: '<Root>/VDR_ModeRequest' */
        ModeSelectionRing_Y.VDR_ModeRequest = MSR_REQUEST_STARTUP_HV;
      } else if (ModeSelectionRing_DW.motorHvStartupFail) {
        ModeSelectionRing_DW.is_MOTORS_HV_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_HIGH_VOLTAGE = Mo_IN_HIGH_VOLTAGE_STARTUP_FAIL;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_HIGH_VOLTAGE_STARTUP_FAIL;
      } else {
        if (ModeSelectionRing_DW.is_MOTORS_HV_STARTUP ==
            Mo_IN_MOTORS_HV_REQUEST_STARTUP) {
          /* Inport: '<Root>/TmrStatus' */
          if (ModeSelectionRing_U.TmrStatus == RING_STATUS_STARTUP_COMPLETE_HV)
          {
            ModeSelectionRing_DW.is_MOTORS_HV_STARTUP =
              ModeS_IN_MOTORS_HV_STARTUP_PASS;

            /* Outport: '<Root>/MSR_leaf_state1' */
            ModeSelectionRing_Y.MSR_leaf_state1 =
              MSR_States_MOTORS_HV_STARTUP_PASS;
            ModeSelectionRing_DW.motorHvStartupPass = true;
          } else {
            if (ModeSelectionRing_DW.temporalCounter_i1 >= 10000U) {
              ModeSelectionRing_DW.is_MOTORS_HV_STARTUP =
                ModeS_IN_MOTORS_HV_STARTUP_FAIL;

              /* Outport: '<Root>/MSR_leaf_state1' */
              ModeSelectionRing_Y.MSR_leaf_state1 =
                MSR_States_MOTORS_HV_STARTUP_FAIL;
              ModeSelectionRing_DW.motorHvStartupFail = true;
            }
          }

          /* End of Inport: '<Root>/TmrStatus' */
        }
      }
      break;

     case Mod_IN_VEHICLE_DYNAMICS_STARTUP:
      if (ModeSelectionRing_DW.vehicleDynamicsStartupPass) {
        ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_HIGH_VOLTAGE = ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_STARTUP = ModeS_IN_ReadyToDriveSoundStart;
        ModeSelectionRing_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_ReadyToDriveSoundStart;

        /* Outport: '<Root>/RTDS' */
        ModeSelectionRing_Y.RTDS = true;
      } else if (ModeSelectionRing_DW.vehicleDynamicsStartupFail) {
        ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_HIGH_VOLTAGE = Mo_IN_HIGH_VOLTAGE_STARTUP_FAIL;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_HIGH_VOLTAGE_STARTUP_FAIL;
      } else {
        if (ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_STARTUP ==
            IN_VEHICLE_DYANMICS_REQUEST_STA) {
          /* Inport: '<Root>/VdrStatus' */
          if (ModeSelectionRing_U.VdrStatus == RING_STATUS_STARTUP_COMPLETE_HV)
          {
            ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_STARTUP =
              IN_VEHICLE_DYANMICS_STARTUP_PAS;

            /* Outport: '<Root>/MSR_leaf_state1' */
            ModeSelectionRing_Y.MSR_leaf_state1 =
              MSR_States_VEHICLE_DYANMICS_STARTUP_PASS;
            ModeSelectionRing_DW.vehicleDynamicsStartupPass = true;
          } else {
            if (ModeSelectionRing_DW.temporalCounter_i1 >= 10000U) {
              ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_STARTUP =
                IN_VEHICLE_DYANMICS_STARTUP_FAI;

              /* Outport: '<Root>/MSR_leaf_state1' */
              ModeSelectionRing_Y.MSR_leaf_state1 =
                MSR_States_VEHICLE_DYANMICS_STARTUP_FAIL;
              ModeSelectionRing_DW.vehicleDynamicsStartupFail = true;
            }
          }

          /* End of Inport: '<Root>/VdrStatus' */
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/ModeSelectionRing' */
static void ModeSelec_exit_internal_STARTUP(void)
{
  if (ModeSelectionRing_DW.is_STARTUP == ModeS_IN_ReadyToDriveSoundStart) {
    /* Outport: '<Root>/MSR_leaf_state1' */
    ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_None;

    /* Outport: '<Root>/RTDS' */
    ModeSelectionRing_Y.RTDS = false;
    ModeSelectionRing_DW.is_STARTUP = ModeSelectio_IN_NO_ACTIVE_CHILD;
  } else {
    ModeSelectionRing_DW.is_COOLING_STARTUP = ModeSelectio_IN_NO_ACTIVE_CHILD;
    Mode_exit_internal_HIGH_VOLTAGE();
    ModeSelectionRing_DW.is_MOTORS_LV_STARTUP = ModeSelectio_IN_NO_ACTIVE_CHILD;

    /* Outport: '<Root>/MSR_leaf_state1' */
    ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_None;
    ModeSelectionRing_DW.is_STARTUP = ModeSelectio_IN_NO_ACTIVE_CHILD;
  }
}

/* Function for Chart: '<Root>/ModeSelectionRing' */
static void ModeSelectionRing_STARTUP(const boolean_T *Compare)
{
  if (ModeSelectionRing_DW.vehicleReady) {
    ModeSelec_exit_internal_STARTUP();
    ModeSelectionRing_DW.tp_STARTUP = 0U;
    ModeSelectionRing_DW.is_OPERATION = ModeSe_IN_SYSTEM_MODE_SELECTION;

    /* Outport: '<Root>/VehicleStatus' */
    ModeSelectionRing_Y.VehicleStatus = VEHICLE_STATUS_ON;
    ModeSelectionRing_DW.is_SYSTEM_MODE_SELECTION = ModeSelectionRing_IN_NORMAL;

    /* Outport: '<Root>/MSR_leaf_state1' */
    ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_NORMAL;
  } else {
    switch (ModeSelectionRing_DW.is_STARTUP) {
     case ModeSelectio_IN_COOLING_STARTUP:
      if (ModeSelectionRing_DW.coolingStartupPass) {
        ModeSelectionRing_DW.is_COOLING_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_STARTUP = ModeSelect_IN_MOTORS_LV_STARTUP;
        ModeSelectionRing_DW.is_MOTORS_LV_STARTUP =
          Mo_IN_MOTORS_LV_REQUEST_STARTUP;
        ModeSelectionRing_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_MOTORS_LV_REQUEST_STARTUP;

        /* Outport: '<Root>/TMR_ModeRequest' */
        ModeSelectionRing_Y.TMR_ModeRequest = MSR_REQUEST_STARTUP_LV;
      } else if (ModeSelectionRing_DW.coolingStartupFail) {
        ModeSelectionRing_DW.is_COOLING_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_STARTUP = Mod_IN_LOW_VOLTAGE_STARTUP_FAIL;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_LOW_VOLTAGE_STARTUP_FAIL;
      } else {
        if (ModeSelectionRing_DW.is_COOLING_STARTUP ==
            Mode_IN_COOLING_REQUEST_STARTUP) {
          /* Inport: '<Root>/CcrStatus' */
          if (ModeSelectionRing_U.CcrStatus == RING_STATUS_STARTUP_COMPLETE_LV)
          {
            ModeSelectionRing_DW.is_COOLING_STARTUP =
              ModeSel_IN_COOLING_STARTUP_PASS;

            /* Outport: '<Root>/MSR_leaf_state1' */
            ModeSelectionRing_Y.MSR_leaf_state1 =
              MSR_States_COOLING_STARTUP_PASS;
            ModeSelectionRing_DW.coolingStartupPass = true;
          } else {
            if (ModeSelectionRing_DW.temporalCounter_i1 >= 10000U) {
              ModeSelectionRing_DW.is_COOLING_STARTUP =
                ModeSel_IN_COOLING_STARTUP_FAIL;

              /* Outport: '<Root>/MSR_leaf_state1' */
              ModeSelectionRing_Y.MSR_leaf_state1 =
                MSR_States_COOLING_STARTUP_FAIL;
              ModeSelectionRing_DW.coolingStartupFail = true;
            }
          }

          /* End of Inport: '<Root>/CcrStatus' */
        }
      }
      break;

     case ModeSelectionRi_IN_HIGH_VOLTAGE:
      ModeSelectionRing_HIGH_VOLTAGE(Compare);
      break;

     case Mod_IN_LOW_VOLTAGE_STARTUP_FAIL:
     case ModeSel_IN_ReadyToDriveSoundEnd:
     case IN_WAITING_FOR_RTD_AND_BRAKES1:
      break;

     case ModeSelect_IN_MOTORS_LV_STARTUP:
      if (ModeSelectionRing_DW.motorLvStartupFail) {
        ModeSelectionRing_DW.is_MOTORS_LV_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_STARTUP = Mod_IN_LOW_VOLTAGE_STARTUP_FAIL;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_LOW_VOLTAGE_STARTUP_FAIL;
      } else if (ModeSelectionRing_DW.motorLvStartupPass) {
        ModeSelectionRing_DW.is_MOTORS_LV_STARTUP =
          ModeSelectio_IN_NO_ACTIVE_CHILD;
        ModeSelectionRing_DW.is_STARTUP = M_IN_WAITING_FOR_RTD_AND_BRAKES;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_WAITING_FOR_RTD_AND_BRAKES;

        /* Outport: '<Root>/VehicleStatus' */
        ModeSelectionRing_Y.VehicleStatus = VEHICLE_STATUS_ACCESSORY;
      } else {
        if (ModeSelectionRing_DW.is_MOTORS_LV_STARTUP ==
            Mo_IN_MOTORS_LV_REQUEST_STARTUP) {
          /* Inport: '<Root>/TmrStatus' */
          if (ModeSelectionRing_U.TmrStatus == RING_STATUS_STARTUP_COMPLETE_LV)
          {
            ModeSelectionRing_DW.is_MOTORS_LV_STARTUP =
              ModeS_IN_MOTORS_LV_STARTUP_PASS;

            /* Outport: '<Root>/MSR_leaf_state1' */
            ModeSelectionRing_Y.MSR_leaf_state1 =
              MSR_States_MOTORS_LV_STARTUP_PASS;
            ModeSelectionRing_DW.motorLvStartupPass = true;
          } else {
            if (ModeSelectionRing_DW.temporalCounter_i1 >= 10000U) {
              ModeSelectionRing_DW.is_MOTORS_LV_STARTUP =
                ModeS_IN_MOTORS_LV_STARTUP_FAIL;

              /* Outport: '<Root>/MSR_leaf_state1' */
              ModeSelectionRing_Y.MSR_leaf_state1 =
                MSR_States_MOTORS_LV_STARTUP_FAIL;
              ModeSelectionRing_DW.motorLvStartupFail = true;
            }
          }

          /* End of Inport: '<Root>/TmrStatus' */
        }
      }
      break;

     case ModeS_IN_ReadyToDriveSoundStart:
      if (ModeSelectionRing_DW.temporalCounter_i1 >= 3500U) {
        /* Outport: '<Root>/RTDS' */
        ModeSelectionRing_Y.RTDS = false;
        ModeSelectionRing_DW.is_STARTUP = ModeSel_IN_ReadyToDriveSoundEnd;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_ReadyToDriveSoundEnd;
        ModeSelectionRing_DW.vehicleReady = true;
      }
      break;

     case M_IN_WAITING_FOR_RTD_AND_BRAKES:
      /* Inport: '<Root>/DriverButton' */
      if ((ModeSelectionRing_U.DriverButton == DRIVER_BUTTON_ON) && (*Compare))
      {
        ModeSelectionRing_DW.is_STARTUP = ModeSelectionRi_IN_HIGH_VOLTAGE;
        ModeSelectionRing_DW.is_HIGH_VOLTAGE = ModeS_IN_ACCUMULATOR_HV_STARTUP;
        ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP =
          IN_ACCUMULATOR_HV_REQUEST_START;
        ModeSelectionRing_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_ACCUMULATOR_HV_REQUEST_STARTUP;

        /* Outport: '<Root>/AMR_ModeRequest' */
        ModeSelectionRing_Y.AMR_ModeRequest = MSR_REQUEST_STARTUP_HV;
      }

      /* End of Inport: '<Root>/DriverButton' */
      break;
    }
  }
}

/* Function for Chart: '<Root>/ModeSelectionRing' */
static void ModeSelectionRing_SHUTDOWN(void)
{
  switch (ModeSelectionRing_DW.is_SHUTDOWN) {
   case ModeSelecti_IN_COOLING_SHUTDOWN:
    if (ModeSelectionRing_DW.coolingShutdownPass) {
      ModeSelectionRing_DW.is_COOLING_SHUTDOWN = ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_SHUTDOWN = ModeSelecti_IN_ShutdownComplete;

      /* Outport: '<Root>/MSR_leaf_state1' */
      ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_ShutdownComplete;

      /* Outport: '<Root>/VehicleStatus' */
      ModeSelectionRing_Y.VehicleStatus = VEHICLE_STATUS_SHUTDOWN;
    } else if (ModeSelectionRing_DW.coolingShutdownFail) {
      ModeSelectionRing_DW.is_COOLING_SHUTDOWN = ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_SHUTDOWN = ModeSelectionR_IN_SHUTDOWN_FAIL;

      /* Outport: '<Root>/MSR_leaf_state1' */
      ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_SHUTDOWN_FAIL;
    } else {
      if (ModeSelectionRing_DW.is_COOLING_SHUTDOWN ==
          Mod_IN_COOLING_REQUEST_SHUTDOWN) {
        /* Inport: '<Root>/CcrStatus' */
        if (ModeSelectionRing_U.CcrStatus == RING_STATUS_SHUTDOWN_COMPLETE_LV) {
          ModeSelectionRing_DW.is_COOLING_SHUTDOWN =
            ModeSe_IN_COOLING_SHUTDOWN_PASS;

          /* Outport: '<Root>/MSR_leaf_state1' */
          ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_COOLING_SHUTDOWN_PASS;
          ModeSelectionRing_DW.coolingShutdownPass = true;
        } else {
          if (ModeSelectionRing_DW.temporalCounter_i1 >= 10000U) {
            ModeSelectionRing_DW.is_COOLING_SHUTDOWN =
              ModeSe_IN_COOLING_SHUTDOWN_FAIL;

            /* Outport: '<Root>/MSR_leaf_state1' */
            ModeSelectionRing_Y.MSR_leaf_state1 =
              MSR_States_COOLING_SHUTDOWN_FAIL;
            ModeSelectionRing_DW.coolingShutdownFail = true;
          }
        }

        /* End of Inport: '<Root>/CcrStatus' */
      }
    }
    break;

   case ModeSelectionR_IN_SHUTDOWN_FAIL:
   case ModeSelecti_IN_ShutdownComplete:
    break;

   case Mod_IN_TRACTIVE_SYSTEM_SHUTDOWN:
    if (ModeSelectionRing_DW.motorHvShutdownPass &&
        ModeSelectionRing_DW.accumulatorHvShutdownPass) {
      ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP_b =
        ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_active_ACCUMULATOR_HV_STARTU = 0U;
      ModeSelectionRing_DW.is_MOTORS_HV_SHUTDOWN =
        ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_active_MOTORS_HV_SHUTDOWN = 0U;
      ModeSelectionRing_DW.is_SHUTDOWN = ModeSelecti_IN_COOLING_SHUTDOWN;
      ModeSelectionRing_DW.is_COOLING_SHUTDOWN = Mod_IN_COOLING_REQUEST_SHUTDOWN;
      ModeSelectionRing_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/MSR_leaf_state1' */
      ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_COOLING_REQUEST_SHUTDOWN;

      /* Outport: '<Root>/CcrModeReuqest' */
      ModeSelectionRing_Y.CcrModeReuqest = MSR_REQUEST_SHUTDOWN_LV;
    } else if (ModeSelectionRing_DW.motorHvShutdownFail &&
               ModeSelectionRing_DW.accumulatorHvShutdownFail) {
      ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP_b =
        ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_active_ACCUMULATOR_HV_STARTU = 0U;
      ModeSelectionRing_DW.is_MOTORS_HV_SHUTDOWN =
        ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_active_MOTORS_HV_SHUTDOWN = 0U;
      ModeSelectionRing_DW.is_SHUTDOWN = ModeSelectionR_IN_SHUTDOWN_FAIL;

      /* Outport: '<Root>/MSR_leaf_state1' */
      ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_SHUTDOWN_FAIL;
    } else {
      if ((ModeSelectionRing_DW.is_active_MOTORS_HV_SHUTDOWN != 0U) &&
          (ModeSelectionRing_DW.is_MOTORS_HV_SHUTDOWN ==
           M_IN_MOTORS_HV_REQUEST_SHUTDOWN)) {
        /* Inport: '<Root>/TmrStatus' */
        if (ModeSelectionRing_U.TmrStatus == RING_STATUS_SHUTDOWN_COMPLETE_HV) {
          ModeSelectionRing_DW.is_MOTORS_HV_SHUTDOWN =
            Mode_IN_MOTORS_HV_SHUTDOWN_PASS;
          ModeSelectionRing_DW.motorHvShutdownPass = true;
        } else {
          if (ModeSelectionRing_DW.temporalCounter_i1 >= 3000U) {
            ModeSelectionRing_DW.is_MOTORS_HV_SHUTDOWN =
              Mode_IN_MOTORS_HV_SHUTDOWN_FAIL;
            ModeSelectionRing_DW.motorHvShutdownFail = true;
          }
        }

        /* End of Inport: '<Root>/TmrStatus' */
      }

      if ((ModeSelectionRing_DW.is_active_ACCUMULATOR_HV_STARTU != 0U) &&
          (ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP_b ==
           IN_ACCUMULATOR_HV_REQUEST_START)) {
        /* Inport: '<Root>/AmrStatus' */
        if (ModeSelectionRing_U.AmrStatus == RING_STATUS_SHUTDOWN_COMPLETE_HV) {
          ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP_b =
            IN_ACCUMULATOR_HV_STARTUP_PASS;
          ModeSelectionRing_DW.accumulatorHvShutdownPass = true;
        } else {
          if (ModeSelectionRing_DW.temporalCounter_i2 >= 3000U) {
            ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP_b =
              IN_ACCUMULATOR_HV_STARTUP_FAIL;
            ModeSelectionRing_DW.accumulatorHvShutdownFail = true;
          }
        }

        /* End of Inport: '<Root>/AmrStatus' */
      }
    }
    break;

   case Mo_IN_VEHICLE_DYNAMICS_SHUTDOWN:
    if (ModeSelectionRing_DW.vehicleDynamicsShutdownPass) {
      ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_SHUTDOWN =
        ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_SHUTDOWN = Mod_IN_TRACTIVE_SYSTEM_SHUTDOWN;

      /* Outport: '<Root>/MSR_leaf_state1' */
      ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_TRACTIVE_SYSTEM_SHUTDOWN;
      ModeSelectionRing_DW.is_active_MOTORS_HV_SHUTDOWN = 1U;
      ModeSelectionRing_DW.is_MOTORS_HV_SHUTDOWN =
        M_IN_MOTORS_HV_REQUEST_SHUTDOWN;
      ModeSelectionRing_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/TMR_ModeRequest' */
      ModeSelectionRing_Y.TMR_ModeRequest = MSR_REQUEST_SHUTDOWN_HV;
      ModeSelectionRing_DW.is_active_ACCUMULATOR_HV_STARTU = 1U;
      ModeSelectionRing_DW.is_ACCUMULATOR_HV_STARTUP_b =
        IN_ACCUMULATOR_HV_REQUEST_START;
      ModeSelectionRing_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/AMR_ModeRequest' */
      ModeSelectionRing_Y.AMR_ModeRequest = MSR_REQUEST_SHUTDOWN_HV;
    } else if (ModeSelectionRing_DW.vehicleDynamicsShutdownFail) {
      ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_SHUTDOWN =
        ModeSelectio_IN_NO_ACTIVE_CHILD;
      ModeSelectionRing_DW.is_SHUTDOWN = ModeSelectionR_IN_SHUTDOWN_FAIL;

      /* Outport: '<Root>/MSR_leaf_state1' */
      ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_SHUTDOWN_FAIL;
    } else {
      if (ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_SHUTDOWN ==
          IN_VEHICLE_DYANMICS_REQUEST_SHU) {
        /* Inport: '<Root>/VdrStatus' */
        if (ModeSelectionRing_U.VdrStatus == RING_STATUS_SHUTDOWN_COMPLETE_HV) {
          ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_SHUTDOWN =
            IN_VEHICLE_DYANMICS_SHUTDOWN_PA;

          /* Outport: '<Root>/MSR_leaf_state1' */
          ModeSelectionRing_Y.MSR_leaf_state1 =
            MSR_States_VEHICLE_DYANMICS_SHUTDOWN_PASS;
          ModeSelectionRing_DW.vehicleDynamicsShutdownPass = true;
        } else {
          if (ModeSelectionRing_DW.temporalCounter_i1 >= 3000U) {
            ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_SHUTDOWN =
              IN_VEHICLE_DYANMICS_SHUTDOWN_FA;

            /* Outport: '<Root>/MSR_leaf_state1' */
            ModeSelectionRing_Y.MSR_leaf_state1 =
              MSR_States_VEHICLE_DYANMICS_SHUTDOWN_FAIL;
            ModeSelectionRing_DW.vehicleDynamicsShutdownFail = true;
          }
        }

        /* End of Inport: '<Root>/VdrStatus' */
      }
    }
    break;
  }
}

/* Model step function */
void ModeSelectionRing_step(void)
{
  boolean_T Compare;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Brakes [%]'
   */
  Compare = (ModeSelectionRing_U.Brakes >= 80.0);

  /* Chart: '<Root>/ModeSelectionRing' incorporates:
   *  Inport: '<Root>/AmrError'
   *  Inport: '<Root>/DriverButton'
   *  Inport: '<Root>/TmrError'
   *  Logic: '<Root>/Logical Operator'
   */
  if (ModeSelectionRing_DW.temporalCounter_i1 < 16383U) {
    ModeSelectionRing_DW.temporalCounter_i1++;
  }

  if (ModeSelectionRing_DW.temporalCounter_i2 < 4095U) {
    ModeSelectionRing_DW.temporalCounter_i2++;
  }

  if (ModeSelectionRing_DW.is_active_c2_ModeSelectionRing == 0U) {
    ModeSelectionRing_DW.is_active_c2_ModeSelectionRing = 1U;
    ModeSelectionRing_DW.is_c2_ModeSelectionRing =
      ModeSelectionRing_IN_OPERATION;
    ModeSelectionRing_DW.is_OPERATION = ModeSelectionRing_IN_STARTUP;
    ModeSelectionRing_DW.tp_STARTUP = 1U;

    /* Outport: '<Root>/VehicleStatus' */
    ModeSelectionRing_Y.VehicleStatus = VEHICLE_STATUS_LOCK;
    ModeSelectionRing_DW.is_STARTUP = ModeSelectio_IN_COOLING_STARTUP;
    ModeSelectionRing_DW.is_COOLING_STARTUP = Mode_IN_COOLING_REQUEST_STARTUP;
    ModeSelectionRing_DW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/MSR_leaf_state1' */
    ModeSelectionRing_Y.MSR_leaf_state1 = MSR_States_COOLING_REQUEST_STARTUP;

    /* Outport: '<Root>/CcrModeReuqest' */
    ModeSelectionRing_Y.CcrModeReuqest = MSR_REQUEST_STARTUP_LV;
  } else {
    switch (ModeSelectionRing_DW.is_c2_ModeSelectionRing) {
     case ModeSelectionRing_IN_OPERATION:
      if ((ModeSelectionRing_U.DriverButton == DRIVER_BUTTON_SHUTDOWN) ||
          ModeSelectionRing_DW.internalShutdown || (ModeSelectionRing_U.AmrError
           || ModeSelectionRing_U.TmrError)) {
        if (ModeSelectionRing_DW.is_OPERATION == ModeSelectionRing_IN_STARTUP) {
          ModeSelec_exit_internal_STARTUP();
          ModeSelectionRing_DW.tp_STARTUP = 0U;
          ModeSelectionRing_DW.is_OPERATION = ModeSelectio_IN_NO_ACTIVE_CHILD;
        } else {
          ModeSelectionRing_DW.is_SYSTEM_MODE_SELECTION =
            ModeSelectio_IN_NO_ACTIVE_CHILD;
          ModeSelectionRing_DW.is_OPERATION = ModeSelectio_IN_NO_ACTIVE_CHILD;
        }

        ModeSelectionRing_DW.is_c2_ModeSelectionRing =
          ModeSelectionRing_IN_SHUTDOWN;
        ModeSelectionRing_DW.is_SHUTDOWN = Mo_IN_VEHICLE_DYNAMICS_SHUTDOWN;
        ModeSelectionRing_DW.is_VEHICLE_DYNAMICS_SHUTDOWN =
          IN_VEHICLE_DYANMICS_REQUEST_SHU;
        ModeSelectionRing_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/MSR_leaf_state1' */
        ModeSelectionRing_Y.MSR_leaf_state1 =
          MSR_States_VEHICLE_DYANMICS_REQUEST_SHUTDOWN;

        /* Outport: '<Root>/VDR_ModeRequest' */
        ModeSelectionRing_Y.VDR_ModeRequest = MSR_REQUEST_SHUTDOWN_HV;
      } else {
        switch (ModeSelectionRing_DW.is_OPERATION) {
         case ModeSelectionRing_IN_STARTUP:
          ModeSelectionRing_STARTUP(&Compare);
          break;

         case ModeSe_IN_SYSTEM_MODE_SELECTION:
          if (ModeSelectionRing_DW.is_SYSTEM_MODE_SELECTION ==
              ModeSelectionRing_IN_NORMAL) {
            /* Outport: '<Root>/AMR_ModeRequest' */
            ModeSelectionRing_Y.AMR_ModeRequest = MSR_REQUEST_RUNNING;

            /* Outport: '<Root>/TMR_ModeRequest' */
            ModeSelectionRing_Y.TMR_ModeRequest = MSR_REQUEST_RUNNING;

            /* Outport: '<Root>/VDR_ModeRequest' */
            ModeSelectionRing_Y.VDR_ModeRequest = MSR_REQUEST_RUNNING;

            /* Outport: '<Root>/CcrModeReuqest' */
            ModeSelectionRing_Y.CcrModeReuqest = MSR_REQUEST_RUNNING;
          }
          break;
        }
      }
      break;

     case ModeSelectionRing_IN_SHUTDOWN:
      ModeSelectionRing_SHUTDOWN();
      break;
    }
  }

  /* End of Chart: '<Root>/ModeSelectionRing' */
}

/* Model initialize function */
void ModeSelectionRing_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ModeSelectionRing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
