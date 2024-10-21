/*
 * Code generation for system system '<S1>/SOC_WriteToFlash'
 *
 * Model                      : SOCEstimation
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:53:30 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "rtwtypes.h"
#include "SOC_WriteToFlash.h"
#include "SOCEstimation_private.h"

/* Output and update for atomic system: '<S1>/SOC_WriteToFlash' */
void SOCEstimation_SOC_WriteToFlash(int32_T rtu_SOC_cpct,
  B_SOC_WriteToFlash_SOCEstimat_T *localB)
{
  localB->SOC = rtu_SOC_cpct;
}
