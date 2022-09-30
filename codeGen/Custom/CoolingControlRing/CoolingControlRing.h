/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CoolingControlRing.h
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

#ifndef RTW_HEADER_CoolingControlRing_h_
#define RTW_HEADER_CoolingControlRing_h_
#ifndef CoolingControlRing_COMMON_INCLUDES_
# define CoolingControlRing_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CoolingControlRing_COMMON_INCLUDES_ */

#include "CoolingControlRing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T MotorTemperatureFrontLeftFault;/* '<Root>/Chart' */
  real_T MotorTemperatureFrontRightFault;/* '<Root>/Chart' */
  real_T MotorTemperatureRearLeftFault;/* '<Root>/Chart' */
  real_T MotorTemperatureRearRightFault;/* '<Root>/Chart' */
  real_T velocity_error;               /* '<Root>/Chart' */
  real_T InverterCoolingPlateTemperature;/* '<Root>/Chart' */
  real_T InverterLoopFluidTemperatureFau;/* '<Root>/Chart' */
  real_T MotorLoopPressureFault;       /* '<Root>/Chart' */
  real_T InverterLoopPressureFault;    /* '<Root>/Chart' */
  real_T MotorLoopFluidTemperatureFault;/* '<Root>/Chart' */
  real_T SFunction_o34;                /* '<Root>/Chart' */
  real_T SFunction_o35;                /* '<Root>/Chart' */
  real_T SFunction_o36;                /* '<Root>/Chart' */
  real_T SFunction_o37;                /* '<Root>/Chart' */
  real_T SFunction_o38;                /* '<Root>/Chart' */
} B_CoolingControlRing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T sensorsWorking;               /* '<Root>/Chart' */
  real_T pumpAndFansWorking;           /* '<Root>/Chart' */
  uint8_T is_active_c2_CoolingControlRing;/* '<Root>/Chart' */
  uint8_T is_c2_CoolingControlRing;    /* '<Root>/Chart' */
  uint8_T is_OPERATIONAL;              /* '<Root>/Chart' */
} DW_CoolingControlRing_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  MSR_REQUEST ModeRequest;             /* '<Root>/ModeRequest' */
  real_T MotorTempFL;                  /* '<Root>/MotorTempFL' */
  real_T MotorTempFR;                  /* '<Root>/MotorTempFR' */
  real_T MotorTempBL;                  /* '<Root>/MotorTempBL' */
  real_T MotorTempBR;                  /* '<Root>/MotorTempBR' */
  real_T InverterCoolingPlateTemp;     /* '<Root>/InverterCoolingPlateTemp' */
  real_T MotorLoopFluidTemp;           /* '<Root>/MotorLoopFluidTemp' */
  real_T InverterLoopFluidTemp;        /* '<Root>/InverterLoopFluidTemp' */
  real_T MotorLoopPressure;            /* '<Root>/MotorLoopPressure' */
  real_T InverterLoopPressure;         /* '<Root>/InverterLoopPressure' */
  real_T Velocity;                     /* '<Root>/Velocity' */
} ExtU_CoolingControlRing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T CR_Motor_Loop_Pump_PWM;       /* '<Root>/CR_Motor_Loop_Pump_PWM' */
  real_T CR_Motor_Loop_Fan_PWM;        /* '<Root>/CR_Motor_Loop_Fan_PWM' */
  real_T CR_Inverter_Loop_Pump_PWM;    /* '<Root>/CR_Inverter_Loop_Pump_PWM' */
  real_T CR_Inverter_Loop_Fan_PWM;     /* '<Root>/CR_Inverter_Loop_Fan_PWM' */
  RING_STATUS CcrStatus;               /* '<Root>/CcrStatus' */
  boolean_T CrFaults;                  /* '<Root>/CrFaults' */
} ExtY_CoolingControlRing_T;

/* Real-time Model Data Structure */
struct tag_RTM_CoolingControlRing_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_CoolingControlRing_T CoolingControlRing_B;

/* Block states (default storage) */
extern DW_CoolingControlRing_T CoolingControlRing_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CoolingControlRing_T CoolingControlRing_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_CoolingControlRing_T CoolingControlRing_Y;

/* Model entry point functions */
extern void CoolingControlRing_initialize(void);
extern void CoolingControlRing_step(void);
extern void CoolingControlRing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CoolingControlRing_T *const CoolingControlRing_M;

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
 * '<Root>' : 'CoolingControlRing'
 * '<S1>'   : 'CoolingControlRing/Chart'
 * '<S2>'   : 'CoolingControlRing/Chart/OPERATIONAL.PUMP_FAN_TESTING.Pump_and_fan_test'
 * '<S3>'   : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter'
 * '<S4>'   : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_motor'
 * '<S5>'   : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working'
 * '<S6>'   : 'CoolingControlRing/Chart/OPERATIONAL.PUMP_FAN_TESTING.Pump_and_fan_test/Subsystem'
 * '<S7>'   : 'CoolingControlRing/Chart/OPERATIONAL.PUMP_FAN_TESTING.Pump_and_fan_test/Subsystem/Compare To Constant'
 * '<S8>'   : 'CoolingControlRing/Chart/OPERATIONAL.PUMP_FAN_TESTING.Pump_and_fan_test/Subsystem/Compare To Constant1'
 * '<S9>'   : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter/Subsystem'
 * '<S10>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter/Subsystem/Compare To Constant'
 * '<S11>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter/Subsystem/Compare To Constant1'
 * '<S12>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter/Subsystem/Compare To Constant2'
 * '<S13>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter/Subsystem/Compare To Constant3'
 * '<S14>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter/Subsystem/Compare To Constant4'
 * '<S15>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_inverter/Subsystem/Compare To Constant5'
 * '<S16>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_motor/Subsystem'
 * '<S17>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_motor/Subsystem/Compare To Constant'
 * '<S18>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_motor/Subsystem/Compare To Constant1'
 * '<S19>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_motor/Subsystem/Compare To Constant2'
 * '<S20>'  : 'CoolingControlRing/Chart/OPERATIONAL.RUNNING.running_motor/Subsystem/Compare To Constant3'
 * '<S21>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking'
 * '<S22>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant'
 * '<S23>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant1'
 * '<S24>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant10'
 * '<S25>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant11'
 * '<S26>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant12'
 * '<S27>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant2'
 * '<S28>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant3'
 * '<S29>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant7'
 * '<S30>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant8'
 * '<S31>'  : 'CoolingControlRing/Chart/OPERATIONAL.SENSOR_TESTING.Sensors_working/AllSensorsWorking/Compare To Constant9'
 */
#endif                                 /* RTW_HEADER_CoolingControlRing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
