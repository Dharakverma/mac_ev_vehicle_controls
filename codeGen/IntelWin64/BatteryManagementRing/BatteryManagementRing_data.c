/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BatteryManagementRing_data.c
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

/* Constant parameters (default storage) */
const ConstP_BatteryManagementRing_T BatteryManagementRing_ConstP = {
  /* Expression: BMR.Batt.SOC.SOC
   * Referenced by: '<S3>/Vltg2SOC'
   */
  { -0.024686556170000002, -0.01837495396, -0.0054394106799999994, 0.0176854512,
    0.055560957640000005, 0.1437406998, 0.4001532228, 0.6051005525, 0.6923668508,
    0.8175911602, 0.86955727440000008, 0.9123300184, 0.9367808471, 0.9671130755,
    1.0 },

  /* Expression: BMR.Batt.SOC.Voltage
   * Referenced by: '<S3>/Vltg2SOC'
   */
  { 11.12222222, 11.92222222, 12.36666667, 12.56666667, 12.72222222, 12.9,
    13.12222222, 13.27777778, 13.34444444, 13.54444444, 13.83333333, 14.45555556,
    14.65555556, 14.7, 14.8 },

  /* Expression: [20:-1:0]/sum([20:-1:0])
   * Referenced by: '<S3>/LowPassFilter'
   */
  { 0.095238095238095233, 0.090476190476190474, 0.085714285714285715,
    0.080952380952380956, 0.0761904761904762, 0.071428571428571425,
    0.066666666666666666, 0.061904761904761907, 0.057142857142857141,
    0.052380952380952382, 0.047619047619047616, 0.042857142857142858,
    0.0380952380952381, 0.033333333333333333, 0.028571428571428571,
    0.023809523809523808, 0.019047619047619049, 0.014285714285714285,
    0.0095238095238095247, 0.0047619047619047623, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
