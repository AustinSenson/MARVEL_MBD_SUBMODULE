/*
 * Code generation for system system '<S1>/SOC_WriteToFlash'
 * For more details, see corresponding source file SOC_WriteToFlash.c
 *
 */

#ifndef RTW_HEADER_SOC_WriteToFlash_h_
#define RTW_HEADER_SOC_WriteToFlash_h_
#ifndef SOCEstimation_COMMON_INCLUDES_
#define SOCEstimation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* SOCEstimation_COMMON_INCLUDES_ */

/* Block signals for system '<S1>/SOC_WriteToFlash' */
typedef struct {
  real32_T A;                          /* '<S1>/SOC_WriteToFlash' */
  real32_T XYZ;                        /* '<S1>/SOC_WriteToFlash' */
  real32_T SOC;                        /* '<S1>/SOC_WriteToFlash' */
} B_SOC_WriteToFlash_SOCEstimat_T;

extern void SOCEstimation_SOC_WriteToFlash(int32_T rtu_SOH_pct, int32_T
  rtu_TotalCapacityExchange_mAh, int32_T rtu_MaxUsableCapacity_mAh, real32_T
  rtu_SOC_cpct, int32_T rtu_TotalDischarge_mAh, int32_T
  rtu_TotalCapacityRemains_mAh, B_SOC_WriteToFlash_SOCEstimat_T *localB);

#endif                                 /* RTW_HEADER_SOC_WriteToFlash_h_ */
