/*
 * Code generation for system system '<S1>/Voltage_Vs_Capacity'
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
#include "VoltagemV_Vs_CapacitymAh.h"
#include "SOCEstimation_private.h"

/* Output and update for atomic system: '<S1>/Voltage_Vs_Capacity' */
void VoltagemV_Vs_CapacitymAh(int32_T rtu_Voltage_mV,
  B_VoltagemV_Vs_CapacitymAh_T *localB)
{
  int32_T tmp;
  tmp = mul_s32_sat_cc(rtu_Voltage_mV, 50);
  if (tmp < 0) {
    tmp = 0;
  }

  localB->Capacity_mAh = (uint32_T)tmp;
}
