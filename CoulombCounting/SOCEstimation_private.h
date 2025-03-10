/*
 * SOCEstimation_private.h
 *
 * Code generation for model "SOCEstimation".
 *
 * Model version              : 7.160
 * Simulink Coder version     : 24.1 (R2024a)
 * C source code generated on : Mon Feb 17 13:54:37 2025
 *
 * Target selection: grt.tlc
 * Embedded hardware: ARM Cortex-M
 */

#ifndef SOCEstimation_PRIVATE_H_
#define SOCEstimation_PRIVATE_H_

#include "rtwtypes.h"
#include "multiword_types.h"
#include "SOCEstimation_types.h"
#include "SOCEstimation.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include <limits.h>

extern real_T rt_roundd(real_T u);
extern real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern void sMultiWordMul_cc(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T n2, uint32_T y[], int32_T n);
extern void mul_wide_s32_cc(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_sat_cc(int32_T a, int32_T b);

#endif /* SOCEstimation_PRIVATE_H_ */
