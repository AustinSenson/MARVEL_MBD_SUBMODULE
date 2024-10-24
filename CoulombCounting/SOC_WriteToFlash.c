/*
 * Code generation for system system '<S1>/SOC_WriteToFlash'
 *
 * Model                      : SOCEstimation
 * Model version              : 4.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 23 20:32:49 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "rtwtypes.h"
#include "SOC_WriteToFlash.h"
#include "SOCEstimation_private.h"

/* Output and update for atomic system: '<S1>/SOC_WriteToFlash' */
void SOCEstimation_SOC_WriteToFlash(int32_T rtu_SOH_pct, int32_T
  rtu_TotalCapacityExchange_mAh, int32_T rtu_MaxUsableCapacity_mAh, real32_T
  rtu_SOC_cpct, int32_T rtu_TotalDischarge_mAh, int32_T
  rtu_TotalCapacityRemains_mAh, B_SOC_WriteToFlash_SOCEstimat_T *localB)
{
  real32_T A;
  A = (real32_T)rtu_SOH_pct * (real32_T)rtu_TotalDischarge_mAh;
  localB->XYZ = ((real32_T)rtu_TotalCapacityExchange_mAh / (real32_T)
                 rtu_MaxUsableCapacity_mAh + A) + (rtu_SOC_cpct - (real32_T)
    rtu_TotalCapacityRemains_mAh);
  localB->SOC = rtu_SOC_cpct;
  localB->A = A;
}
