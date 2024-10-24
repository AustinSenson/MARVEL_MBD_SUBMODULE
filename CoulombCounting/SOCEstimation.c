/*
 * SOCEstimation.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SOCEstimation".
 *
 * Model version              : 4.5
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Oct 24 15:16:27 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Debugging
 * Validation result: Passed (0), Warning (1), Error (0)
 */

#include "SOCEstimation.h"
#include "rtwtypes.h"
#include "SOCEstimation_types.h"
#include "UsableCapacity_mAh.h"
#include "VoltagemV_Vs_CapacitymAh.h"
#include "SOC_ReadFromFlash.h"
#include <math.h>
#include "SOC_WriteToFlash.h"
#include <string.h>
#include "SOCEstimation_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define SOCEstim_IN_FirstCycleCompleted ((uint8_T)1U)
#define SOCEstimatio_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define SOCEstimation_IN_Lobby         ((uint8_T)2U)

/* Named constants for Chart: '<S3>/Chart' */
#define SOCEst_IN_LobbyIntegrationState ((uint8_T)2U)
#define SOCEstima_IN_PseudoLatchHandler ((uint8_T)3U)
#define SOCEstimation_IN_Fully_Charged ((uint8_T)1U)
#define SOCEstimation_IN_Zero_Charged  ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart1' */
#define SOCEstimat_IN_IntegratedCurrent ((uint8_T)1U)
#define SOCEstimatio_IN_IntegratorReset ((uint8_T)2U)

/* Named constants for Chart: '<S4>/SOC_Calibration' */
#define SOCEsti_IN_Recalibrate_Charging ((uint8_T)2U)
#define SOCEstimatio_IN_CoulombCounting ((uint8_T)1U)
#define SOCEstimatio_IN_Vehicle_at_Rest ((uint8_T)3U)

/* Named constants for Chart: '<S8>/SOH_Calibration' */
#define SOCEstimatio_IN_TestBench_Entry ((uint8_T)7U)
#define SOCEstimation_IN_Full_Charge   ((uint8_T)1U)
#define SOCEstimation_IN_Full_Discharge ((uint8_T)2U)
#define SOCEstimation_IN_Int1          ((uint8_T)3U)
#define SOCEstimation_IN_Int2          ((uint8_T)4U)
#define SOCEstimation_IN_Int3          ((uint8_T)5U)
#define SOCEstimation_IN_Int4          ((uint8_T)6U)

/* Named constants for Chart: '<S18>/Chart' */
#define SOCE_IN_Reset_IntegratedCurrent ((uint8_T)2U)

/* Exported block states */
boolean_T PSEUDO_LATCH_SUCCESS;        /* '<S1>/Data Store Memory2' */

/* Block signals (default storage) */
B_SOCEstimation_T SOCEstimation_B;

/* Block states (default storage) */
DW_SOCEstimation_T SOCEstimation_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_SOCEstimation_T SOCEstimation_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_SOCEstimation_T SOCEstimation_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SOCEstimation_T SOCEstimation_Y;

/* Real-time model */
static RT_MODEL_SOCEstimation_T SOCEstimation_M_;
RT_MODEL_SOCEstimation_T *const SOCEstimation_M = &SOCEstimation_M_;
const CC_OutputsBus SOCEstimation_rtZCC_OutputsBus = { 0,/* Initial_Capacity_mAh */
  0,                                   /* Total_CapacityRemains_mAh */
  0,                                   /* Total_Discharge_mAh */
  0,                                   /* SOC_cpct */
  CoulombCounting,                     /* CC_State */
  0,                                   /* MaxUsableCapacity_mAh */
  0,                                   /* TotalCapacityExchange_mAh */
  0,                                   /* SOH_cpct */
  0.0F                                 /* CycleCount */
};

const CellBalancingOutputBus SOCEstimation_rtZCellBalancingO = { 0,/* MaxImbalance_mV */
  false,                               /* BalanceEn */
  Terminate                            /* CurrentBalancingState */
};

const ProtectionState_Out SOCEstimation_rtZProtectionStat = { NoError,/* ThermalRunaway */
  NoError,                             /* TemperatureGradient */
  NoError,                             /* HighImbalanceFlag */
  NoError,                             /* ShortCircuitDetect */
  NoError,                             /* SuddenVoltageDrop */
  NoError,                             /* OV */
  NoError,                             /* UV */
  NoError,                             /* OCC */
  NoError,                             /* OCD */
  0.0F,                                /* i2t_Calculated_A2sec */
  NoError,                             /* eFuseChargeFlag */
  NoError,                             /* eFuseDischargeFlag */
  NoErr,                               /* TempState1 */
  NoErr,                               /* TempState2 */
  NoError,                             /* FlagGroup1 */
  NoError,                             /* FlagGroup2 */
  NoError,                             /* TempOverallState */
  NoError,                             /* ErrorDetect */
  NoError,                             /* DCLI_CurrentFlag */
  NoError                              /* DCLO_CurrentFlag */
};

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << 16U) + absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += productHiLo << 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

/* Model step function */
void SOCEstimation_step(void)
{
  int32_T q1;
  int32_T u;
  int32_T u2;
  boolean_T b_hoisted_cond;

  /* Gain: '<S3>/CC_Inputs.SensorAccuracy_pct//100' incorporates:
   *  Inport: '<Root>/Current_mA'
   */
  SOCEstimation_B.CC_InputsSensorAccuracy_pct100 = (real32_T)
    SOCEstimation_P.CC_InputsSensorAccuracy_pct100_ * (real32_T)
    SOCEstimation_U.Current_mA;

  /* Sum: '<S3>/Add1' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  SOCEstimation_B.absCurrent_mA = ((real32_T)
    SOCEstimation_U.CC_Inputs.SensorOffset_mA + (real32_T)
    SOCEstimation_U.CC_Inputs.BleedingCurrent_mA) +
    SOCEstimation_B.CC_InputsSensorAccuracy_pct100;

  /* Switch: '<S4>/Switch3' incorporates:
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_U.DataPipeline.VCU.FastCharge) {
    /* Switch: '<S4>/Switch3' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.MinCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.FastCharge.MinCurrentLimit_mA;
  } else {
    /* Switch: '<S4>/Switch3' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.MinCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.SlowCharge.MinCurrentLimit_mA;
  }

  /* End of Switch: '<S4>/Switch3' */

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  SOCEstimation_B.DiscreteTimeIntegrator =
    SOCEstimation_DW.DiscreteTimeIntegrator_DSTATE;

  /* Abs: '<S7>/Abs' incorporates:
   *  Inport: '<Root>/Current_mA'
   */
  u = SOCEstimation_U.Current_mA;
  if (u < 0) {
    /* Abs: '<S7>/Abs' */
    SOCEstimation_B.absCurrent_mA_p = -u;
  } else {
    /* Abs: '<S7>/Abs' */
    SOCEstimation_B.absCurrent_mA_p = u;
  }

  /* End of Abs: '<S7>/Abs' */

  /* Chart: '<S7>/Chart' incorporates:
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_DW.is_active_c19_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c19_SOCEstimation = 1U;
  } else {
    SOCEstimation_B.IntegratedCurrent_h +=
      SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec * (real32_T)
      SOCEstimation_B.absCurrent_mA_p;
  }

  /* End of Chart: '<S7>/Chart' */

  /* Switch: '<S7>/Switch' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  if (SOCEstimation_U.CC_Inputs.LoopTimeSelector) {
    /* Switch: '<S7>/Switch' */
    SOCEstimation_B.Switch = SOCEstimation_B.DiscreteTimeIntegrator;
  } else {
    /* Gain: '<S7>/Gain1' */
    SOCEstimation_B.IntegratedCurrent_a = SOCEstimation_P.Gain1_Gain_e *
      SOCEstimation_B.IntegratedCurrent_h;

    /* Switch: '<S7>/Switch' */
    SOCEstimation_B.Switch = SOCEstimation_B.IntegratedCurrent_a;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Gain: '<S7>/Gain2' */
  SOCEstimation_B.Gain2 = SOCEstimation_P.Gain2_Gain_k * SOCEstimation_B.Switch;

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  SOCEstimation_B.CycleCount = SOCEstimation_B.Gain2 / (real32_T)
    SOCEstimation_U.CC_Inputs.EquivalentCycleCapacity_mAh;

  /* Chart: '<S8>/SOH_Calibration' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/DataPipeline'
   *  Inport: '<Root>/ProtectionOutput'
   */
  if (SOCEstimation_DW.is_active_c21_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c21_SOCEstimation = 1U;
    SOCEstimation_DW.durationCounter_2_m = 0U;
    SOCEstimation_DW.durationCounter_1_p = 0U;
    SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimatio_IN_TestBench_Entry;

    /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
    SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
  } else {
    switch (SOCEstimation_DW.is_c21_SOCEstimation) {
     case SOCEstimation_IN_Full_Charge:
      if (SOCEstimation_U.DataPipeline.isChargeEn != 0) {
        SOCEstimation_DW.durationCounter_2_k = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_k * 100)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_jc = 0U;
        SOCEstimation_DW.durationCounter_1_g = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Int2;
      } else {
        b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
                          (SOCEstimation_U.ProtectionOutput.OV != Error));
        if (!b_hoisted_cond) {
          SOCEstimation_DW.durationCounter_1_px = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_px *
                               100) >=
            SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
          SOCEstimation_B.CalcEnable = 0.0;
          SOCEstimation_DW.durationCounter_2_m = 0U;
          SOCEstimation_DW.durationCounter_1_p = 0U;
          SOCEstimation_DW.is_c21_SOCEstimation =
            SOCEstimatio_IN_TestBench_Entry;

          /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
          SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
        }
      }
      break;

     case SOCEstimation_IN_Full_Discharge:
      if (SOCEstimation_U.DataPipeline.isChargeEn != 1) {
        SOCEstimation_DW.durationCounter_2_j = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_j * 100)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_m0 = 0U;
        SOCEstimation_DW.durationCounter_1_dq = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Int1;
      } else {
        b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 1) &&
                          (SOCEstimation_U.ProtectionOutput.UV != Error));
        if (!b_hoisted_cond) {
          SOCEstimation_DW.durationCounter_1_e = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_e *
                               100) >=
            SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
          SOCEstimation_B.CalcEnable = 0.0;
          SOCEstimation_DW.durationCounter_2_m = 0U;
          SOCEstimation_DW.durationCounter_1_p = 0U;
          SOCEstimation_DW.is_c21_SOCEstimation =
            SOCEstimatio_IN_TestBench_Entry;

          /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
          SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
        }
      }
      break;

     case SOCEstimation_IN_Int1:
      b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
                        (SOCEstimation_U.ProtectionOutput.OV == Error));
      if (!b_hoisted_cond) {
        SOCEstimation_DW.durationCounter_2_m0 = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_m0 *
                             100) >=
          SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_k = 0U;
        SOCEstimation_DW.durationCounter_1_px = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Full_Charge;

        /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
        SOCEstimation_Y.SOHCalibrationCycleCompletion += 0.5;
      } else {
        if (SOCEstimation_U.DataPipeline.isChargeEn != 0) {
          SOCEstimation_DW.durationCounter_1_dq = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_dq *
                               100) >=
            SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
          SOCEstimation_B.CalcEnable = 0.0;
          SOCEstimation_DW.durationCounter_2_m = 0U;
          SOCEstimation_DW.durationCounter_1_p = 0U;
          SOCEstimation_DW.is_c21_SOCEstimation =
            SOCEstimatio_IN_TestBench_Entry;

          /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
          SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
        }
      }
      break;

     case SOCEstimation_IN_Int2:
      if (SOCEstimation_U.DataPipeline.isChargeEn != 1) {
        SOCEstimation_DW.durationCounter_1_g = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_g * 100)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 0.0;
        SOCEstimation_DW.durationCounter_2_m = 0U;
        SOCEstimation_DW.durationCounter_1_p = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimatio_IN_TestBench_Entry;

        /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
        SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
      } else {
        b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
                          (SOCEstimation_U.ProtectionOutput.UV == Error));
        if (!b_hoisted_cond) {
          SOCEstimation_DW.durationCounter_2_jc = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_jc *
                               100) >=
            SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
          SOCEstimation_B.CalcEnable = 1.0;
          SOCEstimation_DW.durationCounter_2_j = 0U;
          SOCEstimation_DW.durationCounter_1_e = 0U;
          SOCEstimation_DW.is_c21_SOCEstimation =
            SOCEstimation_IN_Full_Discharge;

          /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
          SOCEstimation_Y.SOHCalibrationCycleCompletion += 0.5;
        }
      }
      break;

     case SOCEstimation_IN_Int3:
      if (SOCEstimation_U.ProtectionOutput.OV != Error) {
        SOCEstimation_DW.durationCounter_2 = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2 * 100) >=
          SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_k = 0U;
        SOCEstimation_DW.durationCounter_1_px = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Full_Charge;

        /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
        SOCEstimation_Y.SOHCalibrationCycleCompletion += 0.5;
      } else {
        if (SOCEstimation_U.DataPipeline.isChargeEn != 0) {
          SOCEstimation_DW.durationCounter_1_d = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_d *
                               100) >=
            SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
          SOCEstimation_B.CalcEnable = 0.0;
          SOCEstimation_DW.durationCounter_2_m = 0U;
          SOCEstimation_DW.durationCounter_1_p = 0U;
          SOCEstimation_DW.is_c21_SOCEstimation =
            SOCEstimatio_IN_TestBench_Entry;

          /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
          SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
        }
      }
      break;

     case SOCEstimation_IN_Int4:
      if (SOCEstimation_U.ProtectionOutput.UV != Error) {
        SOCEstimation_DW.durationCounter_2_b = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_b * 100)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_j = 0U;
        SOCEstimation_DW.durationCounter_1_e = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Full_Discharge;

        /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
        SOCEstimation_Y.SOHCalibrationCycleCompletion += 0.5;
      } else {
        if (SOCEstimation_U.DataPipeline.isChargeEn != 1) {
          SOCEstimation_DW.durationCounter_1_m = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_m *
                               100) >=
            SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
          SOCEstimation_B.CalcEnable = 0.0;
          SOCEstimation_DW.durationCounter_2_m = 0U;
          SOCEstimation_DW.durationCounter_1_p = 0U;
          SOCEstimation_DW.is_c21_SOCEstimation =
            SOCEstimatio_IN_TestBench_Entry;

          /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
          SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
        }
      }
      break;

     default:
      /* case IN_TestBench_Entry: */
      if (SOCEstimation_U.DataPipeline.isChargeEn != 0) {
        SOCEstimation_DW.durationCounter_2_m = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_m * 100)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_b = 0U;
        SOCEstimation_DW.durationCounter_1_m = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Int4;
      } else {
        if (SOCEstimation_U.DataPipeline.isChargeEn != 1) {
          SOCEstimation_DW.durationCounter_1_p = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_p *
                               100) >=
            SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
          SOCEstimation_B.CalcEnable = 1.0;
          SOCEstimation_DW.durationCounter_2 = 0U;
          SOCEstimation_DW.durationCounter_1_d = 0U;
          SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Int3;
        }
      }
      break;
    }
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 0) {
    SOCEstimation_DW.durationCounter_1_d++;
  } else {
    SOCEstimation_DW.durationCounter_1_d = 0U;
  }

  if (SOCEstimation_U.ProtectionOutput.OV == Error) {
    SOCEstimation_DW.durationCounter_2++;
  } else {
    SOCEstimation_DW.durationCounter_2 = 0U;
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 1) {
    SOCEstimation_DW.durationCounter_1_p++;
  } else {
    SOCEstimation_DW.durationCounter_1_p = 0U;
  }

  b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
                    (SOCEstimation_U.ProtectionOutput.OV != Error));
  if (b_hoisted_cond) {
    SOCEstimation_DW.durationCounter_1_px++;
  } else {
    SOCEstimation_DW.durationCounter_1_px = 0U;
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 0) {
    SOCEstimation_DW.durationCounter_2_m++;
  } else {
    SOCEstimation_DW.durationCounter_2_m = 0U;
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 1) {
    SOCEstimation_DW.durationCounter_1_m++;
  } else {
    SOCEstimation_DW.durationCounter_1_m = 0U;
  }

  b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 1) &&
                    (SOCEstimation_U.ProtectionOutput.UV != Error));
  if (b_hoisted_cond) {
    SOCEstimation_DW.durationCounter_1_e++;
  } else {
    SOCEstimation_DW.durationCounter_1_e = 0U;
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 1) {
    SOCEstimation_DW.durationCounter_1_g++;
  } else {
    SOCEstimation_DW.durationCounter_1_g = 0U;
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 0) {
    SOCEstimation_DW.durationCounter_1_dq++;
  } else {
    SOCEstimation_DW.durationCounter_1_dq = 0U;
  }

  b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
                    (SOCEstimation_U.ProtectionOutput.OV == Error));
  if (b_hoisted_cond) {
    SOCEstimation_DW.durationCounter_2_m0++;
  } else {
    SOCEstimation_DW.durationCounter_2_m0 = 0U;
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 0) {
    SOCEstimation_DW.durationCounter_2_k++;
  } else {
    SOCEstimation_DW.durationCounter_2_k = 0U;
  }

  if (SOCEstimation_U.ProtectionOutput.UV == Error) {
    SOCEstimation_DW.durationCounter_2_b++;
  } else {
    SOCEstimation_DW.durationCounter_2_b = 0U;
  }

  if (SOCEstimation_U.DataPipeline.isChargeEn == 1) {
    SOCEstimation_DW.durationCounter_2_j++;
  } else {
    SOCEstimation_DW.durationCounter_2_j = 0U;
  }

  b_hoisted_cond = ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
                    (SOCEstimation_U.ProtectionOutput.UV == Error));
  if (b_hoisted_cond) {
    SOCEstimation_DW.durationCounter_2_jc++;
  } else {
    SOCEstimation_DW.durationCounter_2_jc = 0U;
  }

  /* End of Chart: '<S8>/SOH_Calibration' */

  /* Outputs for Enabled SubSystem: '<S8>/Subsystem' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (SOCEstimation_B.CalcEnable > 0.0) {
    /* Abs: '<S18>/Abs' incorporates:
     *  Inport: '<Root>/Current_mA'
     */
    u = SOCEstimation_U.Current_mA;
    if (u < 0) {
      /* Abs: '<S18>/Abs' */
      SOCEstimation_B.absCurrent_mA_i = -u;
    } else {
      /* Abs: '<S18>/Abs' */
      SOCEstimation_B.absCurrent_mA_i = u;
    }

    /* End of Abs: '<S18>/Abs' */

    /* Chart: '<S18>/Chart' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     *  Inport: '<Root>/DataPipeline'
     *  Outport: '<Root>/SOHCalibrationCycleCompletion'
     */
    if (SOCEstimation_DW.is_active_c22_SOCEstimation == 0U) {
      SOCEstimation_DW.is_active_c22_SOCEstimation = 1U;
      SOCEstimation_DW.durationCounter_1 = 0U;
      SOCEstimation_DW.is_c22_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;
    } else if (SOCEstimation_DW.is_c22_SOCEstimation ==
               SOCEstimat_IN_IntegratedCurrent) {
      if (!(SOCEstimation_Y.SOHCalibrationCycleCompletion == 1.0)) {
        SOCEstimation_DW.durationCounter_1 = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1 * 100) >=
          SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_DW.durationCounter_1_i = 0U;
        SOCEstimation_DW.is_c22_SOCEstimation = SOCE_IN_Reset_IntegratedCurrent;
        SOCEstimation_B.Final_IntegratedCurrent =
          SOCEstimation_DW.IntegratedCurrent;
      } else {
        SOCEstimation_DW.IntegratedCurrent +=
          SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec * (real32_T)
          SOCEstimation_B.absCurrent_mA_i;
      }
    } else {
      /* case IN_Reset_IntegratedCurrent: */
      if (!(SOCEstimation_Y.SOHCalibrationCycleCompletion == 0.0)) {
        SOCEstimation_DW.durationCounter_1_i = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_i * 100)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_DW.IntegratedCurrent = 0.0F;
        SOCEstimation_DW.durationCounter_1 = 0U;
        SOCEstimation_DW.is_c22_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;
      }
    }

    if (SOCEstimation_Y.SOHCalibrationCycleCompletion == 1.0) {
      SOCEstimation_DW.durationCounter_1++;
    } else {
      SOCEstimation_DW.durationCounter_1 = 0U;
    }

    if (SOCEstimation_Y.SOHCalibrationCycleCompletion == 0.0) {
      SOCEstimation_DW.durationCounter_1_i++;
    } else {
      SOCEstimation_DW.durationCounter_1_i = 0U;
    }

    /* End of Chart: '<S18>/Chart' */

    /* Gain: '<S18>/Gain1' */
    SOCEstimation_B.Gain1 = SOCEstimation_P.Gain1_Gain_g *
      SOCEstimation_B.Final_IntegratedCurrent;

    /* Gain: '<S18>/Gain2' */
    SOCEstimation_B.CapacityExchange_mAh = SOCEstimation_P.Gain2_Gain_o *
      SOCEstimation_B.Gain1;

    /* Product: '<S18>/Divide' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.InitialCycleCount = SOCEstimation_B.CapacityExchange_mAh /
      (real32_T)SOCEstimation_U.CC_Inputs.EquivalentCycleCapacity_mAh;

    /* MATLAB Function: '<S18>/UsableCapacity_mAh' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimat_UsableCapacity_mAh_m(SOCEstimation_B.InitialCycleCount,
      SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh,
      SOCEstimation_U.CC_Inputs.SOH_Vs_Capacity_Gain,
      SOCEstimation_U.CC_Inputs.SOH_Vs_Capacity_Offset,
      &SOCEstimation_B.sf_UsableCapacity_mAh_m);

    /* Product: '<S18>/Divide1' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.InitialSOH = (real32_T)
      SOCEstimation_B.sf_UsableCapacity_mAh_m.MaxUsableCapacity_mAh / (real32_T)
      SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh;

    /* Gain: '<S18>/Gain' */
    SOCEstimation_B.InitialSOH_cpct = (int32_T)floorf(SOCEstimation_P.Gain_Gain *
      SOCEstimation_B.InitialSOH);

    /* Product: '<S18>/Product' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.Product = SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh *
      SOCEstimation_B.InitialSOH_cpct;

    /* Gain: '<S18>/Gain3' */
    SOCEstimation_B.Gain3 = (real32_T)SOCEstimation_P.Gain3_Gain *
      5.68434189E-14F * (real32_T)SOCEstimation_B.Product;

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    SOCEstimation_B.DataTypeConversion_f = (int32_T)floorf(SOCEstimation_B.Gain3);
  }

  /* End of Outputs for SubSystem: '<S8>/Subsystem' */

  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   *  Outport: '<Root>/SOHCalibrationCycleCompletion'
   */
  if (SOCEstimation_DW.is_active_c25_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c25_SOCEstimation = 1U;
    SOCEstimation_DW.durationCounter_1_k = 0U;
    SOCEstimation_DW.is_c25_SOCEstimation = SOCEstimation_IN_Lobby;
    SOCEstimation_B.Final_InstalledCapacity_mAh =
      SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh;
  } else if (SOCEstimation_DW.is_c25_SOCEstimation ==
             SOCEstim_IN_FirstCycleCompleted) {
    if (!SOCEstimation_U.CC_Inputs.SOHCalibrationOn) {
      SOCEstimation_DW.durationCounter_1_k = 0U;
      SOCEstimation_DW.is_c25_SOCEstimation = SOCEstimation_IN_Lobby;
      SOCEstimation_B.Final_InstalledCapacity_mAh =
        SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh;
    }
  } else {
    /* case IN_Lobby: */
    b_hoisted_cond = (SOCEstimation_U.CC_Inputs.SOHCalibrationOn &&
                      (SOCEstimation_Y.SOHCalibrationCycleCompletion == 1.0));
    if (!b_hoisted_cond) {
      SOCEstimation_DW.durationCounter_1_k = 0U;
    }

    if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_k * 100) >
        SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
      SOCEstimation_DW.is_c25_SOCEstimation = SOCEstim_IN_FirstCycleCompleted;
      SOCEstimation_B.Final_InstalledCapacity_mAh =
        SOCEstimation_B.DataTypeConversion_f;
    }
  }

  b_hoisted_cond = (SOCEstimation_U.CC_Inputs.SOHCalibrationOn &&
                    (SOCEstimation_Y.SOHCalibrationCycleCompletion == 1.0));
  if (b_hoisted_cond) {
    SOCEstimation_DW.durationCounter_1_k++;
  } else {
    SOCEstimation_DW.durationCounter_1_k = 0U;
  }

  /* End of Chart: '<S1>/Chart' */

  /* MATLAB Function: '<S7>/UsableCapacity_mAh' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  SOCEstimatio_UsableCapacity_mAh(SOCEstimation_B.CycleCount,
    SOCEstimation_U.CC_Inputs.SOH_Vs_Capacity_Gain,
    SOCEstimation_U.CC_Inputs.SOH_Vs_Capacity_Offset,
    SOCEstimation_B.Final_InstalledCapacity_mAh,
    &SOCEstimation_B.sf_UsableCapacity_mAh);

  /* MATLAB Function: '<S1>/Voltage_Vs_Capacity' incorporates:
   *  Inport: '<Root>/Voltage_mV'
   */
  VoltagemV_Vs_CapacitymAh(SOCEstimation_U.Voltage_mV,
    &SOCEstimation_B.sf_Voltage_Vs_Capacity);

  /* MATLAB Function: '<S1>/SOC_ReadFromFlash' */
  SOCEstimation_SOC_ReadFromFlash(&SOCEstimation_B.sf_SOC_ReadFromFlash);

  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  if (SOCEstimation_U.CC_Inputs.InitialCapacity_Guess) {
    /* Switch: '<S1>/Switch' */
    SOCEstimation_B.Initial_Guess_mAh =
      SOCEstimation_B.sf_Voltage_Vs_Capacity.Capacity_mAh;
  } else {
    /* Switch: '<S1>/Switch' */
    SOCEstimation_B.Initial_Guess_mAh = (uint32_T)
      SOCEstimation_B.sf_SOC_ReadFromFlash.CapacityRemains_mAh;
  }

  /* End of Switch: '<S1>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  SOCEstimation_B.DataTypeConversion = (int32_T)
    SOCEstimation_B.Initial_Guess_mAh;

  /* DataStoreRead: '<S1>/Data Store Read' */
  SOCEstimation_B.Capacity_mAh = SOCEstimation_DW.CapacityRemains_mAh;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Inport: '<Root>/DataPipeline'
   *  Switch: '<S4>/Switch2'
   */
  if (SOCEstimation_U.DataPipeline.VCU.FastCharge) {
    /* Switch: '<S4>/Switch1' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.MaxAllowedImb_mV =
      SOCEstimation_U.CC_Inputs.FastCharge.MaxAllowedImb_mV;

    /* Switch: '<S4>/Switch2' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.MaxCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.FastCharge.MaxCurrentLimit_mA;
  } else {
    /* Switch: '<S4>/Switch1' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.MaxAllowedImb_mV =
      SOCEstimation_U.CC_Inputs.SlowCharge.MaxAllowedImb_mV;

    /* Switch: '<S4>/Switch2' incorporates:
     *  Inport: '<Root>/CC_Inputs'
     */
    SOCEstimation_B.MaxCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.SlowCharge.MaxCurrentLimit_mA;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Chart: '<S4>/SOC_Calibration' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/CellBalancingOutput'
   *  Inport: '<Root>/Current_mA'
   *  Inport: '<Root>/DataPipeline'
   *  Inport: '<Root>/triggerLatchPseudo'
   */
  if (SOCEstimation_DW.temporalCounter_i1 < MAX_uint32_T) {
    SOCEstimation_DW.temporalCounter_i1++;
  }

  if (SOCEstimation_DW.is_active_c15_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c15_SOCEstimation = 1U;
    SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_Vehicle_at_Rest;
    SOCEstimation_DW.temporalCounter_i1 = 0U;
    SOCEstimation_B.CC_State = Vehicle_at_Rest;
    SOCEstimation_B.Initial_Capacity_mAh = SOCEstimation_B.DataTypeConversion;
    SOCEstimation_DW.TransitionCapacity_mAh =
      SOCEstimation_B.Initial_Capacity_mAh;
  } else {
    switch (SOCEstimation_DW.is_c15_SOCEstimation) {
     case SOCEstimatio_IN_CoulombCounting:
      SOCEstimation_B.CC_State = CoulombCounting;
      if (SOCEstimation_U.DataPipeline.VoltageSenseBus.mV_min >=
          SOCEstimation_U.CC_Inputs.minVoltageForLatch_mV) {
        if (SOCEstimation_U.Current_mA < 0) {
          u = SOCEstimation_U.Current_mA;
          if (u <= MIN_int32_T) {
            u = MAX_int32_T;
          } else {
            u = -u;
          }
        } else {
          u = SOCEstimation_U.Current_mA;
        }

        if (u < SOCEstimation_B.MaxCurrentLimit_mA) {
          if (SOCEstimation_U.Current_mA < 0) {
            u = SOCEstimation_U.Current_mA;
            if (u <= MIN_int32_T) {
              u = MAX_int32_T;
            } else {
              u = -u;
            }
          } else {
            u = SOCEstimation_U.Current_mA;
          }

          if (u > SOCEstimation_B.MinCurrentLimit_mA) {
          } else {
            SOCEstimation_DW.durationCounter_1_l = 0U;
          }
        } else {
          SOCEstimation_DW.durationCounter_1_l = 0U;
        }
      } else {
        SOCEstimation_DW.durationCounter_1_l = 0U;
      }

      b_hoisted_cond = ((((real_T)(uint32_T)((int32_T)
        SOCEstimation_DW.durationCounter_1_l * 100) >
                          SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) &&
                         SOCEstimation_U.DataPipeline.VCU.isChargerConnected &&
                         (SOCEstimation_U.CellBalancingOutput.MaxImbalance_mV <
                          SOCEstimation_B.MaxAllowedImb_mV)) ||
                        (SOCEstimation_U.triggerLatchPseudo == 1.0));
      if (b_hoisted_cond) {
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEsti_IN_Recalibrate_Charging;
        SOCEstimation_DW.temporalCounter_i1 = 0U;
        SOCEstimation_B.CC_State = Recalibrate;
        SOCEstimation_B.Initial_Capacity_mAh =
          SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;
        SOCEstimation_DW.TransitionCapacity_mAh =
          SOCEstimation_B.Initial_Capacity_mAh;
      }
      break;

     case SOCEsti_IN_Recalibrate_Charging:
      SOCEstimation_B.CC_State = Recalibrate;
      if ((uint32_T)((int32_T)SOCEstimation_DW.temporalCounter_i1 * 100) >=
          (uint32_T)SOCEstimation_U.CC_Inputs.CCTimeout_msec) {
        SOCEstimation_DW.durationCounter_1_l = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_CoulombCounting;
        SOCEstimation_B.CC_State = CoulombCounting;
        SOCEstimation_B.Initial_Capacity_mAh = SOCEstimation_B.Capacity_mAh;
      }
      break;

     default:
      /* case IN_Vehicle_at_Rest: */
      SOCEstimation_B.CC_State = Vehicle_at_Rest;
      if ((uint32_T)((int32_T)SOCEstimation_DW.temporalCounter_i1 * 100) >=
          (uint32_T)SOCEstimation_U.CC_Inputs.CCTimeout_msec) {
        SOCEstimation_DW.durationCounter_1_l = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_CoulombCounting;
        SOCEstimation_B.CC_State = CoulombCounting;
        SOCEstimation_B.Initial_Capacity_mAh = SOCEstimation_B.Capacity_mAh;
      }
      break;
    }
  }

  if (SOCEstimation_U.DataPipeline.VoltageSenseBus.mV_min >=
      SOCEstimation_U.CC_Inputs.minVoltageForLatch_mV) {
    if (SOCEstimation_U.Current_mA < 0) {
      u = SOCEstimation_U.Current_mA;
      if (u <= MIN_int32_T) {
        u = MAX_int32_T;
      } else {
        u = -u;
      }
    } else {
      u = SOCEstimation_U.Current_mA;
    }

    if (u < SOCEstimation_B.MaxCurrentLimit_mA) {
      if (SOCEstimation_U.Current_mA < 0) {
        u = SOCEstimation_U.Current_mA;
        if (u <= MIN_int32_T) {
          u = MAX_int32_T;
        } else {
          u = -u;
        }
      } else {
        u = SOCEstimation_U.Current_mA;
      }

      if (u > SOCEstimation_B.MinCurrentLimit_mA) {
        SOCEstimation_DW.durationCounter_1_l++;
      } else {
        SOCEstimation_DW.durationCounter_1_l = 0U;
      }
    } else {
      SOCEstimation_DW.durationCounter_1_l = 0U;
    }
  } else {
    SOCEstimation_DW.durationCounter_1_l = 0U;
  }

  /* End of Chart: '<S4>/SOC_Calibration' */

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  SOCEstimation_B.DataTypeConversion1 = (real32_T)SOCEstimation_B.CC_State;

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
  if ((SOCEstimation_B.DataTypeConversion1 > 0.0F) &&
      (SOCEstimation_DW.DiscreteTimeIntegrator2_PrevRes <= 0)) {
    SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE =
      SOCEstimation_P.DiscreteTimeIntegrator2_IC;
  }

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
  SOCEstimation_B.IntegratedCurrent =
    SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE;

  /* Chart: '<S3>/Chart1' incorporates:
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_DW.is_active_c14_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c14_SOCEstimation = 1U;
    SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;
  } else if (SOCEstimation_DW.is_c14_SOCEstimation ==
             SOCEstimat_IN_IntegratedCurrent) {
    if (SOCEstimation_B.DataTypeConversion1 == 1.0F) {
      SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimatio_IN_IntegratorReset;
    } else {
      SOCEstimation_B.IntegratedCurrent_k +=
        SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec *
        SOCEstimation_B.absCurrent_mA;
    }
  } else {
    /* case IN_IntegratorReset: */
    b_hoisted_cond = ((SOCEstimation_B.DataTypeConversion1 == 0.0F) ||
                      (SOCEstimation_B.DataTypeConversion1 == 2.0F));
    if (b_hoisted_cond) {
      SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;
    } else {
      SOCEstimation_B.IntegratedCurrent_k = 0.0F;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  if (SOCEstimation_U.CC_Inputs.LoopTimeSelector) {
    /* Switch: '<S3>/Switch1' */
    SOCEstimation_B.Switch1_p = SOCEstimation_B.IntegratedCurrent;
  } else {
    /* Gain: '<S3>/Gain2' */
    SOCEstimation_B.IntegratedCurrent_g = SOCEstimation_P.Gain2_Gain *
      SOCEstimation_B.IntegratedCurrent_k;

    /* Switch: '<S3>/Switch1' */
    SOCEstimation_B.Switch1_p = SOCEstimation_B.IntegratedCurrent_g;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Gain: '<S3>/Multiply2' */
  SOCEstimation_B.Multiply2 = SOCEstimation_P.Multiply2_Gain *
    SOCEstimation_B.Switch1_p;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  SOCEstimation_B.DataTypeConversion3 = (int32_T)floorf
    (SOCEstimation_B.Multiply2);

  /* Chart: '<S3>/Chart' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_DW.is_active_c27_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c27_SOCEstimation = 1U;
    SOCEstimation_DW.durationCounter_1_mg = 0U;
    SOCEstimation_DW.is_c27_SOCEstimation = SOCEst_IN_LobbyIntegrationState;
    SOCEstimation_B.TotalCapacityRemains_mAh =
      SOCEstimation_B.Initial_Capacity_mAh;
    if (SOCEstimation_B.TotalCapacityRemains_mAh <
        SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
      SOCEstimation_DW.durationCounter_2_d = 0U;
    }

    /* Outport: '<Root>/pseudoLatchTrigger' */
    SOCEstimation_Y.pseudoLatchTrigger = false;
  } else {
    switch (SOCEstimation_DW.is_c27_SOCEstimation) {
     case SOCEstimation_IN_Fully_Charged:
      if (SOCEstimation_B.DataTypeConversion1 == 0.0F) {
        SOCEstimation_DW.durationCounter_1_mg = 0U;
        SOCEstimation_DW.is_c27_SOCEstimation = SOCEst_IN_LobbyIntegrationState;
        SOCEstimation_B.TotalCapacityRemains_mAh =
          SOCEstimation_B.Initial_Capacity_mAh;
        if (SOCEstimation_B.TotalCapacityRemains_mAh <
            SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }

        /* Outport: '<Root>/pseudoLatchTrigger' */
        SOCEstimation_Y.pseudoLatchTrigger = false;
      } else {
        u = SOCEstimation_B.Initial_Capacity_mAh;
        q1 = SOCEstimation_B.DataTypeConversion3;
        if ((u < 0) && (q1 < MIN_int32_T - u)) {
          u = MIN_int32_T;
        } else if ((u > 0) && (q1 > MAX_int32_T - u)) {
          u = MAX_int32_T;
        } else {
          u += q1;
        }

        SOCEstimation_B.TotalCapacityRemains_mAh = u;
        if (SOCEstimation_B.TotalCapacityRemains_mAh <
            SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }
      }
      break;

     case SOCEst_IN_LobbyIntegrationState:
      b_hoisted_cond = ((SOCEstimation_B.Initial_Capacity_mAh ==
                         SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh)
                        && (SOCEstimation_B.DataTypeConversion1 == 1.0F) &&
                        (!SOCEstimation_U.CC_Inputs.pseudoLatchFlag));
      if (b_hoisted_cond) {
        SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimation_IN_Fully_Charged;
        SOCEstimation_B.TotalCapacityRemains_mAh =
          SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;
        if (SOCEstimation_B.TotalCapacityRemains_mAh <
            SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }
      } else if (SOCEstimation_B.TotalCapacityRemains_mAh <= 0) {
        SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimation_IN_Zero_Charged;
      } else {
        b_hoisted_cond = (SOCEstimation_U.CC_Inputs.pseudoLatchFlag &&
                          SOCEstimation_U.DataPipeline.VCU.isChargerConnected &&
                          (SOCEstimation_B.DataTypeConversion1 != 1.0F));
        if (!b_hoisted_cond) {
          SOCEstimation_DW.durationCounter_1_mg = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_mg *
                               100) >
            SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
          SOCEstimation_DW.durationCounter_1_n = 0U;
          SOCEstimation_DW.is_c27_SOCEstimation =
            SOCEstima_IN_PseudoLatchHandler;
        } else {
          u = SOCEstimation_B.Initial_Capacity_mAh;
          q1 = SOCEstimation_B.DataTypeConversion3;
          if ((u < 0) && (q1 < MIN_int32_T - u)) {
            u = MIN_int32_T;
          } else if ((u > 0) && (q1 > MAX_int32_T - u)) {
            u = MAX_int32_T;
          } else {
            u += q1;
          }

          SOCEstimation_B.TotalCapacityRemains_mAh = u;
          if (SOCEstimation_B.TotalCapacityRemains_mAh <
              SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
            SOCEstimation_DW.durationCounter_2_d = 0U;
          }
        }
      }
      break;

     case SOCEstima_IN_PseudoLatchHandler:
      if (SOCEstimation_B.TotalCapacityRemains_mAh <
          SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
        SOCEstimation_DW.durationCounter_2_d = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_d * 100)
          > SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
        /* Outport: '<Root>/pseudoLatchTrigger' */
        SOCEstimation_Y.pseudoLatchTrigger = true;
        SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimation_IN_Fully_Charged;
        SOCEstimation_B.TotalCapacityRemains_mAh =
          SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;
        if (SOCEstimation_B.TotalCapacityRemains_mAh <
            SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }
      } else {
        if (SOCEstimation_U.CC_Inputs.pseudoLatchFlag) {
          SOCEstimation_DW.durationCounter_1_n = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_n *
                               100) >
            SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
          SOCEstimation_DW.durationCounter_1_mg = 0U;
          SOCEstimation_DW.is_c27_SOCEstimation =
            SOCEst_IN_LobbyIntegrationState;
          SOCEstimation_B.TotalCapacityRemains_mAh =
            SOCEstimation_B.Initial_Capacity_mAh;
          if (SOCEstimation_B.TotalCapacityRemains_mAh <
              SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
            SOCEstimation_DW.durationCounter_2_d = 0U;
          }

          /* Outport: '<Root>/pseudoLatchTrigger' */
          SOCEstimation_Y.pseudoLatchTrigger = false;
        } else {
          u = SOCEstimation_B.Initial_Capacity_mAh;
          q1 = SOCEstimation_B.DataTypeConversion3;
          if ((u < 0) && (q1 < MIN_int32_T - u)) {
            u = MIN_int32_T;
          } else if ((u > 0) && (q1 > MAX_int32_T - u)) {
            u = MAX_int32_T;
          } else {
            u += q1;
          }

          SOCEstimation_B.TotalCapacityRemains_mAh = u;
          if (SOCEstimation_B.TotalCapacityRemains_mAh <
              SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
            SOCEstimation_DW.durationCounter_2_d = 0U;
          }
        }
      }
      break;

     default:
      /* case IN_Zero_Charged: */
      if (SOCEstimation_U.DataPipeline.VCU.isChargerConnected) {
        SOCEstimation_DW.durationCounter_1_mg = 0U;
        SOCEstimation_DW.is_c27_SOCEstimation = SOCEst_IN_LobbyIntegrationState;
        SOCEstimation_B.TotalCapacityRemains_mAh =
          SOCEstimation_B.Initial_Capacity_mAh;
        if (SOCEstimation_B.TotalCapacityRemains_mAh <
            SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }

        /* Outport: '<Root>/pseudoLatchTrigger' */
        SOCEstimation_Y.pseudoLatchTrigger = false;
      } else {
        SOCEstimation_B.TotalCapacityRemains_mAh = 0;
        if (SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh > 0) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }
      }
      break;
    }
  }

  b_hoisted_cond = (SOCEstimation_U.CC_Inputs.pseudoLatchFlag &&
                    SOCEstimation_U.DataPipeline.VCU.isChargerConnected &&
                    (SOCEstimation_B.DataTypeConversion1 != 1.0F));
  if (b_hoisted_cond) {
    SOCEstimation_DW.durationCounter_1_mg++;
  } else {
    SOCEstimation_DW.durationCounter_1_mg = 0U;
  }

  if (!SOCEstimation_U.CC_Inputs.pseudoLatchFlag) {
    SOCEstimation_DW.durationCounter_1_n++;
  } else {
    SOCEstimation_DW.durationCounter_1_n = 0U;
  }

  if (SOCEstimation_B.TotalCapacityRemains_mAh >=
      SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
    SOCEstimation_DW.durationCounter_2_d++;
  } else {
    SOCEstimation_DW.durationCounter_2_d = 0U;
  }

  /* End of Chart: '<S3>/Chart' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  SOCEstimation_B.DataTypeConversion2 = SOCEstimation_B.TotalCapacityRemains_mAh;

  /* Product: '<S3>/Divide2' */
  SOCEstimation_B.SOC_ChargeDischarge = (real_T)
    SOCEstimation_B.TotalCapacityRemains_mAh / (real_T)
    SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;

  /* Gain: '<S3>/Gain1' */
  SOCEstimation_B.TotalSOCRemains_cpct = (int32_T)floor
    (SOCEstimation_P.Gain1_Gain * SOCEstimation_B.SOC_ChargeDischarge);

  /* DataStoreWrite: '<S1>/Data Store Write' */
  SOCEstimation_DW.CapacityRemains_mAh = SOCEstimation_B.DataTypeConversion2;

  /* DataStoreRead: '<S1>/Data Store Read1' */
  SOCEstimation_B.SOC_cpct = SOCEstimation_DW.SOC_pct;

  /* Product: '<S7>/Divide1' */
  SOCEstimation_B.SOH = (real32_T)
    SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh / (real32_T)
    SOCEstimation_B.Final_InstalledCapacity_mAh;

  /* Gain: '<S7>/Gain' */
  SOCEstimation_B.SOH_cpct = (int32_T)floorf(SOCEstimation_P.Gain_Gain_a *
    SOCEstimation_B.SOH);

  /* Saturate: '<S1>/Saturation1' */
  u = SOCEstimation_B.SOH_cpct;
  q1 = SOCEstimation_P.Saturation1_LowerSat;
  u2 = SOCEstimation_P.Saturation1_UpperSat;
  if (u > u2) {
    /* Saturate: '<S1>/Saturation1' */
    SOCEstimation_B.SOH_cpct_f = u2;
  } else if (u < q1) {
    /* Saturate: '<S1>/Saturation1' */
    SOCEstimation_B.SOH_cpct_f = q1;
  } else {
    /* Saturate: '<S1>/Saturation1' */
    SOCEstimation_B.SOH_cpct_f = u;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  SOCEstimation_B.TotalCapacityExchange_mAh = (int32_T)floorf
    (SOCEstimation_B.Gain2);

  /* MATLAB Function: '<S1>/SOC_WriteToFlash' */
  SOCEstimation_SOC_WriteToFlash(SOCEstimation_B.SOH_cpct_f,
    SOCEstimation_B.TotalCapacityExchange_mAh,
    SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh,
    SOCEstimation_B.SOC_cpct, SOCEstimation_B.DataTypeConversion3,
    SOCEstimation_B.DataTypeConversion2, &SOCEstimation_B.sf_SOC_WriteToFlash);

  /* Saturate: '<S1>/Saturation' */
  u = SOCEstimation_B.TotalSOCRemains_cpct;
  q1 = SOCEstimation_P.Saturation_LowerSat;
  u2 = SOCEstimation_P.Saturation_UpperSat;
  if (u > u2) {
    /* Saturate: '<S1>/Saturation' */
    SOCEstimation_B.SOC_cpct_h = u2;
  } else if (u < q1) {
    /* Saturate: '<S1>/Saturation' */
    SOCEstimation_B.SOC_cpct_h = q1;
  } else {
    /* Saturate: '<S1>/Saturation' */
    SOCEstimation_B.SOC_cpct_h = u;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Sum: '<S1>/Subtract' */
  SOCEstimation_B.Subtract = (real32_T)SOCEstimation_B.SOC_cpct_h -
    SOCEstimation_B.SOC_cpct;

  /* Abs: '<S1>/Abs' */
  SOCEstimation_B.Abs = fabsf(SOCEstimation_B.Subtract);

  /* Switch: '<S1>/Switch1' */
  if (SOCEstimation_B.Abs > SOCEstimation_P.Switch1_Threshold) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    SOCEstimation_B.Switch1 = SOCEstimation_P.Constant_Value;
  } else {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    SOCEstimation_B.Switch1 = SOCEstimation_P.Constant1_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* BusCreator: '<S1>/Bus Creator1' incorporates:
   *  Outport: '<Root>/CC_Outputs'
   */
  SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh =
    SOCEstimation_B.Initial_Capacity_mAh;
  SOCEstimation_Y.CC_Outputs.Total_CapacityRemains_mAh =
    SOCEstimation_B.DataTypeConversion2;
  SOCEstimation_Y.CC_Outputs.Total_Discharge_mAh =
    SOCEstimation_B.DataTypeConversion3;
  SOCEstimation_Y.CC_Outputs.SOC_cpct = SOCEstimation_B.SOC_cpct_h;
  SOCEstimation_Y.CC_Outputs.CC_State = SOCEstimation_B.CC_State;
  SOCEstimation_Y.CC_Outputs.MaxUsableCapacity_mAh =
    SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;
  SOCEstimation_Y.CC_Outputs.TotalCapacityExchange_mAh =
    SOCEstimation_B.TotalCapacityExchange_mAh;
  SOCEstimation_Y.CC_Outputs.SOH_cpct = SOCEstimation_B.SOH_cpct_f;
  SOCEstimation_Y.CC_Outputs.CycleCount = SOCEstimation_B.CycleCount;

  /* Outport: '<Root>/SOC_FromFlash' */
  SOCEstimation_Y.SOC_FromFlash = SOCEstimation_B.sf_SOC_WriteToFlash.SOC;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  SOCEstimation_DW.DiscreteTimeIntegrator_DSTATE += (real32_T)
    SOCEstimation_P.DiscreteTimeIntegrator_gainval * 1.16415322E-10F * (real32_T)
    SOCEstimation_B.absCurrent_mA_p;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
  SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE +=
    SOCEstimation_P.DiscreteTimeIntegrator2_gainval *
    SOCEstimation_B.absCurrent_mA;
  if (SOCEstimation_B.DataTypeConversion1 > 0.0F) {
    SOCEstimation_DW.DiscreteTimeIntegrator2_PrevRes = 1;
  } else {
    SOCEstimation_DW.DiscreteTimeIntegrator2_PrevRes = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
}

/* Model initialize function */
void SOCEstimation_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SOCEstimation_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &SOCEstimation_B), 0,
                sizeof(B_SOCEstimation_T));

  {
    SOCEstimation_B.CC_State = CoulombCounting;
  }

  /* states (dwork) */
  (void) memset((void *)&SOCEstimation_DW, 0,
                sizeof(DW_SOCEstimation_T));

  /* exported global states */
  PSEUDO_LATCH_SUCCESS = false;

  /* external inputs */
  (void)memset(&SOCEstimation_U, 0, sizeof(ExtU_SOCEstimation_T));
  SOCEstimation_U.ProtectionOutput = SOCEstimation_rtZProtectionStat;
  SOCEstimation_U.CellBalancingOutput = SOCEstimation_rtZCellBalancingO;

  /* external outputs */
  (void)memset(&SOCEstimation_Y, 0, sizeof(ExtY_SOCEstimation_T));
  SOCEstimation_Y.CC_Outputs = SOCEstimation_rtZCC_OutputsBus;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
  PSEUDO_LATCH_SUCCESS = SOCEstimation_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
  SOCEstimation_DW.SOC_pct = SOCEstimation_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  SOCEstimation_DW.CapacityRemains_mAh =
    SOCEstimation_P.DataStoreMemory_InitialValue;
  SOCEstimation_PrevZCX.Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  SOCEstimation_DW.DiscreteTimeIntegrator_DSTATE =
    SOCEstimation_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
  SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE =
    SOCEstimation_P.DiscreteTimeIntegrator2_IC;
  SOCEstimation_DW.DiscreteTimeIntegrator2_PrevRes = 2;

  /* SystemInitialize for Chart: '<S7>/Chart' */
  SOCEstimation_DW.is_active_c19_SOCEstimation = 0U;
  SOCEstimation_B.IntegratedCurrent_h = 0.0F;

  /* SystemInitialize for Chart: '<S8>/SOH_Calibration' */
  SOCEstimation_DW.is_active_c21_SOCEstimation = 0U;
  SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_B.CalcEnable = 0.0;

  /* SystemInitialize for Outport: '<Root>/SOHCalibrationCycleCompletion' incorporates:
   *  Chart: '<S8>/SOH_Calibration'
   */
  SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S8>/Subsystem' */
  /* SystemInitialize for Chart: '<S18>/Chart' */
  SOCEstimation_DW.is_active_c22_SOCEstimation = 0U;
  SOCEstimation_DW.is_c22_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_DW.IntegratedCurrent = 0.0F;
  SOCEstimation_B.Final_IntegratedCurrent = 0.0F;

  /* SystemInitialize for DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
   *  Outport: '<S18>/Tested_InstalledCapacity_mAh'
   */
  SOCEstimation_B.DataTypeConversion_f =
    SOCEstimation_P.Tested_InstalledCapacity_mAh_Y0;

  /* End of SystemInitialize for SubSystem: '<S8>/Subsystem' */

  /* SystemInitialize for Chart: '<S1>/Chart' */
  SOCEstimation_DW.is_active_c25_SOCEstimation = 0U;
  SOCEstimation_DW.is_c25_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_B.Final_InstalledCapacity_mAh = 0;

  /* SystemInitialize for Chart: '<S4>/SOC_Calibration' */
  SOCEstimation_DW.temporalCounter_i1 = 0U;
  SOCEstimation_DW.is_active_c15_SOCEstimation = 0U;
  SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_DW.TransitionCapacity_mAh = 0;
  SOCEstimation_B.CC_State = CoulombCounting;
  SOCEstimation_B.Initial_Capacity_mAh = 0;

  /* SystemInitialize for Chart: '<S3>/Chart1' */
  SOCEstimation_DW.is_active_c14_SOCEstimation = 0U;
  SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_B.IntegratedCurrent_k = 0.0F;

  /* SystemInitialize for Chart: '<S3>/Chart' */
  SOCEstimation_DW.is_active_c27_SOCEstimation = 0U;
  SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_B.TotalCapacityRemains_mAh = 2;

  /* SystemInitialize for Outport: '<Root>/pseudoLatchTrigger' incorporates:
   *  Chart: '<S3>/Chart'
   */
  SOCEstimation_Y.pseudoLatchTrigger = false;
}

/* Model terminate function */
void SOCEstimation_terminate(void)
{
  /* (no terminate code required) */
}
