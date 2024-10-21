/*
 * DataPipeline_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DataPipeline".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:52:37 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "DataPipeline.h"

/* Block parameters (default storage) */
P_DataPipeline_T DataPipeline_P = {
  /* Variable: nCells_parallel
   * Referenced by:
   *   '<S1>/Gain2'
   *   '<S1>/Gain3'
   *   '<S1>/Gain5'
   *   '<S1>/Gain9'
   */
  1
};

/* Constant parameters (default storage) */
const ConstP_DataPipeline_T DataPipeline_ConstP = {
  /* Computed Parameter: Gain7_Gain
   * Referenced by: '<S1>/Gain7'
   */
  { { 0x33330000UL, 0x73UL } }
};
