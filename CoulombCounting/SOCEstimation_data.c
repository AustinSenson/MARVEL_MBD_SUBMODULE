/*
 * SOCEstimation_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SOCEstimation".
 *
 * Model version              : 4.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 23 20:32:49 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Debugging
 * Validation result: Passed (0), Warning (1), Error (0)
 */

#include "SOCEstimation.h"

/* Block parameters (default storage) */
P_SOCEstimation_T SOCEstimation_P = {
  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: 10000
   * Referenced by: '<S3>/Gain1'
   */
  10000.0,

  /* Computed Parameter: Tested_InstalledCapacity_mAh_Y0
   * Referenced by: '<S18>/Tested_InstalledCapacity_mAh'
   */
  0,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<S1>/Saturation1'
   */
  10000,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S1>/Saturation1'
   */
  0,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S1>/Saturation'
   */
  10000,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S1>/Saturation'
   */
  0,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<S1>/Data Store Memory'
   */
  0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  858993459,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S18>/Gain3'
   */
  1759218604,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S3>/Gain2'
   */
  0.001F,

  /* Computed Parameter: Gain1_Gain_e
   * Referenced by: '<S7>/Gain1'
   */
  0.001F,

  /* Computed Parameter: Gain1_Gain_g
   * Referenced by: '<S18>/Gain1'
   */
  0.001F,

  /* Computed Parameter: Gain2_Gain_o
   * Referenced by: '<S18>/Gain2'
   */
  0.000277777785F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S18>/Gain'
   */
  10000.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: Gain2_Gain_k
   * Referenced by: '<S7>/Gain2'
   */
  0.000277777785F,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<S3>/Discrete-Time Integrator2'
   */
  0.1F,

  /* Computed Parameter: DiscreteTimeIntegrator2_IC
   * Referenced by: '<S3>/Discrete-Time Integrator2'
   */
  0.0F,

  /* Computed Parameter: Multiply2_Gain
   * Referenced by: '<S3>/Multiply2'
   */
  0.000277777785F,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S7>/Gain'
   */
  10000.0F,

  /* Computed Parameter: Switch1_Threshold
   * Referenced by: '<S1>/Switch1'
   */
  1.0F,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<S1>/Data Store Memory1'
   */
  0.0F,

  /* Expression: false
   * Referenced by: '<S1>/Data Store Memory2'
   */
  false,

  /* Computed Parameter: CC_InputsSensorAccuracy_pct100_
   * Referenced by: '<S3>/CC_Inputs.SensorAccuracy_pct//100'
   */
  1
};
