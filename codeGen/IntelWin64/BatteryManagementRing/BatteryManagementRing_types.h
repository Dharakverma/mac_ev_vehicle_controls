/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BatteryManagementRing_types.h
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

#ifndef RTW_HEADER_BatteryManagementRing_types_h_
#define RTW_HEADER_BatteryManagementRing_types_h_
#include "rtwtypes.h"
#include "MSR_REQUEST.h"
#include "RING_STATUS.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_BatteryFaults_
#define DEFINED_TYPEDEF_FOR_BatteryFaults_

typedef struct {
  boolean_T UnderVoltageFault;
  boolean_T OverVoltageFault;
  boolean_T UnderBatterySocFault;
  boolean_T OverBatterSocFault;
} BatteryFaults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_jP1ftFFQdb6OfTi2Dl5gn_
#define DEFINED_TYPEDEF_FOR_struct_jP1ftFFQdb6OfTi2Dl5gn_

typedef struct {
  real_T ChrgCrnt;
  real_T Voltage[15];
  real_T SOC[15];
  real_T HiCrntThrshld;
  real_T InitSOC;
} struct_jP1ftFFQdb6OfTi2Dl5gn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_scghECln5aeUTgCYVvCqaG_
#define DEFINED_TYPEDEF_FOR_struct_scghECln5aeUTgCYVvCqaG_

typedef struct {
  real_T Capacity;
  real_T Impedance;
  struct_jP1ftFFQdb6OfTi2Dl5gn SOC;
} struct_scghECln5aeUTgCYVvCqaG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SqAZ3awpaWsYIuFEU2kvSB_
#define DEFINED_TYPEDEF_FOR_struct_SqAZ3awpaWsYIuFEU2kvSB_

typedef struct {
  real_T MinVoltage;
  real_T MinSOC;
} struct_SqAZ3awpaWsYIuFEU2kvSB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_YgLbZIcE0WOh98yzg2BfQE_
#define DEFINED_TYPEDEF_FOR_struct_YgLbZIcE0WOh98yzg2BfQE_

typedef struct {
  real_T MinVoltage;
  real_T MinSOC;
  real_T MaxDchrgCrnt;
} struct_YgLbZIcE0WOh98yzg2BfQE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_iUeq4KXgtZygGv5emZA9KH_
#define DEFINED_TYPEDEF_FOR_struct_iUeq4KXgtZygGv5emZA9KH_

typedef struct {
  real_T OFF;
  real_T OFF_PASS;
  real_T STARTUP_INPROGRESS;
  real_T STARTUP_LOWENERGY;
  real_T STARTUP_PASS;
  real_T RUNNING;
  real_T RUNNING_PWRSAVE;
  real_T RUNNING_FAIL;
  real_T SHUTDOWN_INPROGRESS;
  real_T SHUTDOWN_COMPLETE;
} struct_iUeq4KXgtZygGv5emZA9KH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_HfqclPCIkJ1QtD1AgoPneH_
#define DEFINED_TYPEDEF_FOR_struct_HfqclPCIkJ1QtD1AgoPneH_

typedef struct {
  real_T OFF;
  real_T STARTUP;
  real_T RUN;
  real_T SHUTDOWN;
} struct_HfqclPCIkJ1QtD1AgoPneH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_rTtKJOVs2gbmolP3Odzan_
#define DEFINED_TYPEDEF_FOR_struct_rTtKJOVs2gbmolP3Odzan_

typedef struct {
  real_T AuxilaryLoads;
  struct_scghECln5aeUTgCYVvCqaG Batt;
  struct_SqAZ3awpaWsYIuFEU2kvSB Startup;
  struct_YgLbZIcE0WOh98yzg2BfQE Running;
  struct_iUeq4KXgtZygGv5emZA9KH State;
  struct_HfqclPCIkJ1QtD1AgoPneH ModeRequest;
  real_T Undervoltage;
  real_T Overrvoltage;
  real_T Under_SOC;
  real_T Over_SOC;
} struct_rTtKJOVs2gbmolP3Odzan;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_BatteryManagementRing_T RT_MODEL_BatteryManagementRin_T;

#endif                           /* RTW_HEADER_BatteryManagementRing_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
