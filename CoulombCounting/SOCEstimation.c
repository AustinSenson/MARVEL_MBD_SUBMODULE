/*
 * SOCEstimation.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SOCEstimation".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:53:30 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "SOCEstimation.h"
#include "rtwtypes.h"
#include "UsableCapacity_mAh.h"
#include <math.h>
#include "VoltagemV_Vs_CapacitymAh.h"
#include "SOC_ReadFromFlash.h"
#include "SOC_WriteToFlash.h"
#include "SOCEstimation_types.h"
#include <string.h>
#include "SOCEstimation_private.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S1>/Chart' */
#define SOCEstim_IN_FirstCycleCompleted ((uint8_T)1U)
#define SOCEstimatio_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define SOCEstimation_IN_Lobby         ((uint8_T)2U)

/* Named constants for Chart: '<S3>/Chart' */
#define SOCEstima_IN_PseudoLatchHandler ((uint8_T)3U)
#define SOCEstimation_IN_Fully_Charged ((uint8_T)1U)
#define SOCEstimation_IN_Zero_Charged  ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart1' */
#define SOCEstimat_IN_IntegratedCurrent ((uint8_T)1U)
#define SOCEstimatio_IN_IntegratorReset ((uint8_T)2U)

/* Named constants for Chart: '<S4>/SOC_Calibration' */
#define SOCEsti_IN_PseudoLatchHandler_j ((uint8_T)2U)
#define SOCEsti_IN_Recalibrate_Charging ((uint8_T)3U)
#define SOCEstimatio_IN_CoulombCounting ((uint8_T)1U)
#define SOCEstimatio_IN_Vehicle_at_Rest ((uint8_T)4U)

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

void mul_wide_s32_cc(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
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

int32_T mul_s32_sat_cc(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32_cc(a, b, &u32_chi, &u32_clo);
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
  int32_T rtb_MaxCurrentLimit_mA;
  int32_T rtb_MinCurrentLimit_mA;
  int32_T rtb_SOC_cpct_a;
  int32_T rtb_SOH_cpct;
  int32_T rtb_absCurrent_mA_l;
  int32_T u;
  real32_T rtb_CycleCount;
  real32_T rtb_Gain2;
  real32_T rtb_absCurrent_mA;
  real32_T tmp;
  CCState rtb_CC_State;
  ZCEventType zcEvent;

  /* Switch: '<S4>/Switch3' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_U.DataPipeline.VCU.FastCharge) {
    rtb_MinCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.FastCharge.MinCurrentLimit_mA;
  } else {
    rtb_MinCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.SlowCharge.MinCurrentLimit_mA;
  }

  /* End of Switch: '<S4>/Switch3' */

  /* Abs: '<S7>/Abs' incorporates:
   *  Inport: '<Root>/Current_mA'
   */
  if (SOCEstimation_U.Current_mA < 0) {
    rtb_absCurrent_mA_l = -SOCEstimation_U.Current_mA;
  } else {
    rtb_absCurrent_mA_l = SOCEstimation_U.Current_mA;
  }

  /* End of Abs: '<S7>/Abs' */

  /* Chart: '<S7>/Chart' incorporates:
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_DW.is_active_c19_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c19_SOCEstimation = 1U;
  } else {
    SOCEstimation_B.IntegratedCurrent +=
      SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec * (real32_T)
      rtb_absCurrent_mA_l;
  }

  /* End of Chart: '<S7>/Chart' */

  /* Switch: '<S7>/Switch' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S7>/Gain1'
   *  Inport: '<Root>/CC_Inputs'
   */
  if (SOCEstimation_U.CC_Inputs.LoopTimeSelector) {
    tmp = SOCEstimation_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    tmp = 0.001F * SOCEstimation_B.IntegratedCurrent;
  }

  /* Gain: '<S7>/Gain2' incorporates:
   *  Switch: '<S7>/Switch'
   */
  rtb_Gain2 = 0.000277777785F * tmp;

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  rtb_CycleCount = rtb_Gain2 / (real32_T)
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

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_k * SOCEstimation_U.looptimeSoC)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_jc = 0U;
        SOCEstimation_DW.durationCounter_1_g = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Int2;
      } else {
        if ((SOCEstimation_U.DataPipeline.isChargeEn != 0) ||
            (SOCEstimation_U.ProtectionOutput.OV == Error)) {
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

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_j * SOCEstimation_U.looptimeSoC)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 1.0;
        SOCEstimation_DW.durationCounter_2_m0 = 0U;
        SOCEstimation_DW.durationCounter_1_dq = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimation_IN_Int1;
      } else {
        if ((SOCEstimation_U.DataPipeline.isChargeEn != 1) ||
            (SOCEstimation_U.ProtectionOutput.UV == Error)) {
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
      if ((SOCEstimation_U.DataPipeline.isChargeEn != 0) ||
          (SOCEstimation_U.ProtectionOutput.OV != Error)) {
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

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_g * SOCEstimation_U.looptimeSoC)
          >= SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_B.CalcEnable = 0.0;
        SOCEstimation_DW.durationCounter_2_m = 0U;
        SOCEstimation_DW.durationCounter_1_p = 0U;
        SOCEstimation_DW.is_c21_SOCEstimation = SOCEstimatio_IN_TestBench_Entry;

        /* Outport: '<Root>/SOHCalibrationCycleCompletion' */
        SOCEstimation_Y.SOHCalibrationCycleCompletion = 0.0;
      } else {
        if ((SOCEstimation_U.DataPipeline.isChargeEn != 0) ||
            (SOCEstimation_U.ProtectionOutput.UV != Error)) {
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

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2 * SOCEstimation_U.looptimeSoC) >=
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

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_b * SOCEstimation_U.looptimeSoC)
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

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_m * SOCEstimation_U.looptimeSoC)
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

  if ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
      (SOCEstimation_U.ProtectionOutput.OV != Error)) {
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

  if ((SOCEstimation_U.DataPipeline.isChargeEn == 1) &&
      (SOCEstimation_U.ProtectionOutput.UV != Error)) {
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

  if ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
      (SOCEstimation_U.ProtectionOutput.OV == Error)) {
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

  if ((SOCEstimation_U.DataPipeline.isChargeEn == 0) &&
      (SOCEstimation_U.ProtectionOutput.UV == Error)) {
    SOCEstimation_DW.durationCounter_2_jc++;
  } else {
    SOCEstimation_DW.durationCounter_2_jc = 0U;
  }

  /* End of Chart: '<S8>/SOH_Calibration' */

  /* Outputs for Enabled SubSystem: '<S8>/Subsystem' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (SOCEstimation_B.CalcEnable > 0.0) {
    /* Chart: '<S18>/Chart' incorporates:
     *  Abs: '<S18>/Abs'
     *  Inport: '<Root>/CC_Inputs'
     *  Inport: '<Root>/Current_mA'
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

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1 * SOCEstimation_U.looptimeSoC) >=
          SOCEstimation_U.CC_Inputs.SOHCalibrationTimeout_msec) {
        SOCEstimation_DW.durationCounter_1_i = 0U;
        SOCEstimation_DW.is_c22_SOCEstimation = SOCE_IN_Reset_IntegratedCurrent;
        SOCEstimation_B.Final_IntegratedCurrent =
          SOCEstimation_DW.IntegratedCurrent;
      } else {
        if (SOCEstimation_U.Current_mA < 0) {
          /* Abs: '<S18>/Abs' incorporates:
           *  Inport: '<Root>/Current_mA'
           */
          rtb_SOH_cpct = -SOCEstimation_U.Current_mA;
        } else {
          /* Abs: '<S18>/Abs' incorporates:
           *  Inport: '<Root>/Current_mA'
           */
          rtb_SOH_cpct = SOCEstimation_U.Current_mA;
        }

        SOCEstimation_DW.IntegratedCurrent +=
          SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec * (real32_T)
          rtb_SOH_cpct;
      }
    } else {
      /* case IN_Reset_IntegratedCurrent: */
      if (!(SOCEstimation_Y.SOHCalibrationCycleCompletion == 0.0)) {
        SOCEstimation_DW.durationCounter_1_i = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_i * SOCEstimation_U.looptimeSoC)
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

    /* MATLAB Function: '<S18>/UsableCapacity_mAh' incorporates:
     *  Gain: '<S18>/Gain1'
     *  Gain: '<S18>/Gain2'
     *  Inport: '<Root>/CC_Inputs'
     *  Product: '<S18>/Divide'
     */
    SOCEstimat_UsableCapacity_mAh_m(0.000277777785F * (0.001F *
      SOCEstimation_B.Final_IntegratedCurrent) / (real32_T)
      SOCEstimation_U.CC_Inputs.EquivalentCycleCapacity_mAh,
      SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh,
      SOCEstimation_U.CC_Inputs.SOH_Vs_Capacity_Gain,
      SOCEstimation_U.CC_Inputs.SOH_Vs_Capacity_Offset,
      &SOCEstimation_B.sf_UsableCapacity_mAh_m);

    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Gain: '<S18>/Gain'
     *  Gain: '<S18>/Gain3'
     *  Inport: '<Root>/CC_Inputs'
     *  Product: '<S18>/Divide1'
     *  Product: '<S18>/Product'
     */
    SOCEstimation_B.DataTypeConversion = (int32_T)floorf((real32_T)((int32_T)
      floorf((real32_T)
             SOCEstimation_B.sf_UsableCapacity_mAh_m.MaxUsableCapacity_mAh /
             (real32_T)SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh *
             10000.0F) * SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh) *
      0.0001F);
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
    if ((!SOCEstimation_U.CC_Inputs.SOHCalibrationOn) ||
        (!(SOCEstimation_Y.SOHCalibrationCycleCompletion == 1.0))) {
      SOCEstimation_DW.durationCounter_1_k = 0U;
    }

    if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_k * SOCEstimation_U.looptimeSoC) >
        SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
      SOCEstimation_DW.is_c25_SOCEstimation = SOCEstim_IN_FirstCycleCompleted;
      SOCEstimation_B.Final_InstalledCapacity_mAh =
        SOCEstimation_B.DataTypeConversion;
    }
  }

  if (SOCEstimation_U.CC_Inputs.SOHCalibrationOn &&
      (SOCEstimation_Y.SOHCalibrationCycleCompletion == 1.0)) {
    SOCEstimation_DW.durationCounter_1_k++;
  } else {
    SOCEstimation_DW.durationCounter_1_k = 0U;
  }

  /* End of Chart: '<S1>/Chart' */

  /* MATLAB Function: '<S7>/UsableCapacity_mAh' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  SOCEstimatio_UsableCapacity_mAh(rtb_CycleCount,
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

  /* Switch: '<S4>/Switch2' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_U.DataPipeline.VCU.FastCharge) {
    rtb_MaxCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.FastCharge.MaxCurrentLimit_mA;
  } else {
    rtb_MaxCurrentLimit_mA =
      SOCEstimation_U.CC_Inputs.SlowCharge.MaxCurrentLimit_mA;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Chart: '<S4>/SOC_Calibration' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/CellBalancingOutput'
   *  Inport: '<Root>/Current_mA'
   *  Inport: '<Root>/DataPipeline'
   *  Switch: '<S4>/Switch1'
   */
  if (SOCEstimation_DW.temporalCounter_i1 < MAX_uint32_T) {
    SOCEstimation_DW.temporalCounter_i1++;
  }

  if (SOCEstimation_DW.is_active_c15_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c15_SOCEstimation = 1U;
    SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_Vehicle_at_Rest;
    SOCEstimation_DW.temporalCounter_i1 = 0U;
    rtb_CC_State = Vehicle_at_Rest;

    /* Switch: '<S1>/Switch' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    if (SOCEstimation_U.CC_Inputs.InitialCapacity_Guess) {
      SOCEstimation_B.Initial_Capacity_mAh = (int32_T)
        SOCEstimation_B.sf_Voltage_Vs_Capacity.Capacity_mAh;
    } else {
      SOCEstimation_B.Initial_Capacity_mAh =
        SOCEstimation_B.sf_SOC_ReadFromFlash.CapacityRemains_mAh;
    }

    /* End of Switch: '<S1>/Switch' */
    SOCEstimation_DW.TransitionCapacity_mAh =
      SOCEstimation_B.Initial_Capacity_mAh;
  } else {
    switch (SOCEstimation_DW.is_c15_SOCEstimation) {
     case SOCEstimatio_IN_CoulombCounting:
      rtb_CC_State = CoulombCounting;
      if (SOCEstimation_U.DataPipeline.VoltageSenseBus.mV_min >=
          SOCEstimation_U.CC_Inputs.minVoltageForLatch_mV) {
        if (SOCEstimation_U.Current_mA < 0) {
          if (SOCEstimation_U.Current_mA <= MIN_int32_T) {
            rtb_SOH_cpct = MAX_int32_T;
          } else {
            rtb_SOH_cpct = -SOCEstimation_U.Current_mA;
          }
        } else {
          rtb_SOH_cpct = SOCEstimation_U.Current_mA;
        }

        if (rtb_SOH_cpct < rtb_MaxCurrentLimit_mA) {
          if (SOCEstimation_U.Current_mA < 0) {
            if (SOCEstimation_U.Current_mA <= MIN_int32_T) {
              rtb_SOH_cpct = MAX_int32_T;
            } else {
              rtb_SOH_cpct = -SOCEstimation_U.Current_mA;
            }
          } else {
            rtb_SOH_cpct = SOCEstimation_U.Current_mA;
          }

          if (rtb_SOH_cpct > rtb_MinCurrentLimit_mA) {
          } else {
            SOCEstimation_DW.durationCounter_1_l = 0U;
          }
        } else {
          SOCEstimation_DW.durationCounter_1_l = 0U;
        }
      } else {
        SOCEstimation_DW.durationCounter_1_l = 0U;
      }

      /* Switch: '<S4>/Switch1' incorporates:
       *  Inport: '<Root>/Current_mA'
       */
      if (SOCEstimation_U.DataPipeline.VCU.FastCharge) {
        rtb_SOH_cpct = SOCEstimation_U.CC_Inputs.FastCharge.MaxAllowedImb_mV;
      } else {
        rtb_SOH_cpct = SOCEstimation_U.CC_Inputs.SlowCharge.MaxAllowedImb_mV;
      }

      if (((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_l *
                              100) >
           SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) &&
          SOCEstimation_U.DataPipeline.VCU.isChargerConnected &&
          (SOCEstimation_U.CellBalancingOutput.MaxImbalance_mV < rtb_SOH_cpct))
      {
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEsti_IN_Recalibrate_Charging;
        SOCEstimation_DW.temporalCounter_i1 = 0U;
        rtb_CC_State = Recalibrate;
        SOCEstimation_B.Initial_Capacity_mAh =
          SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;
        SOCEstimation_DW.TransitionCapacity_mAh =
          SOCEstimation_B.Initial_Capacity_mAh;
      } else if (SOCEstimation_DW.PSEUDO_LATCH_SUCCESS) {
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEsti_IN_PseudoLatchHandler_j;
        SOCEstimation_DW.PSEUDO_LATCH_SUCCESS = false;
      }
      break;

     case SOCEsti_IN_PseudoLatchHandler_j:
      SOCEstimation_DW.is_c15_SOCEstimation = SOCEsti_IN_Recalibrate_Charging;
      SOCEstimation_DW.temporalCounter_i1 = 0U;
      rtb_CC_State = Recalibrate;
      SOCEstimation_B.Initial_Capacity_mAh =
        SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;
      SOCEstimation_DW.TransitionCapacity_mAh =
        SOCEstimation_B.Initial_Capacity_mAh;
      break;

     case SOCEsti_IN_Recalibrate_Charging:
      rtb_CC_State = Recalibrate;
      if ((uint32_T)((int32_T)SOCEstimation_DW.temporalCounter_i1 * 100) >=
          (uint32_T)SOCEstimation_U.CC_Inputs.CCTimeout_msec) {
        SOCEstimation_DW.durationCounter_1_l = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_CoulombCounting;
        rtb_CC_State = CoulombCounting;
        SOCEstimation_B.Initial_Capacity_mAh =
          SOCEstimation_DW.CapacityRemains_mAh;
      }
      break;

     default:
      /* case IN_Vehicle_at_Rest: */
      rtb_CC_State = Vehicle_at_Rest;
      if ((uint32_T)((int32_T)SOCEstimation_DW.temporalCounter_i1 * 100) >=
          (uint32_T)SOCEstimation_U.CC_Inputs.CCTimeout_msec) {
        SOCEstimation_DW.durationCounter_1_l = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_CoulombCounting;
        rtb_CC_State = CoulombCounting;
        SOCEstimation_B.Initial_Capacity_mAh =
          SOCEstimation_DW.CapacityRemains_mAh;
      }
      break;
    }
  }

  if (SOCEstimation_U.DataPipeline.VoltageSenseBus.mV_min >=
      SOCEstimation_U.CC_Inputs.minVoltageForLatch_mV) {
    if (SOCEstimation_U.Current_mA < 0) {
      if (SOCEstimation_U.Current_mA <= MIN_int32_T) {
        rtb_SOH_cpct = MAX_int32_T;
      } else {
        rtb_SOH_cpct = -SOCEstimation_U.Current_mA;
      }
    } else {
      rtb_SOH_cpct = SOCEstimation_U.Current_mA;
    }

    if (rtb_SOH_cpct < rtb_MaxCurrentLimit_mA) {
      if (SOCEstimation_U.Current_mA < 0) {
        if (SOCEstimation_U.Current_mA <= MIN_int32_T) {
          rtb_SOH_cpct = MAX_int32_T;
        } else {
          rtb_SOH_cpct = -SOCEstimation_U.Current_mA;
        }
      } else {
        rtb_SOH_cpct = SOCEstimation_U.Current_mA;
      }

      if (rtb_SOH_cpct > rtb_MinCurrentLimit_mA) {
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

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  if (((int32_T)rtb_CC_State > 0) &&
      (SOCEstimation_DW.DiscreteTimeIntegrator2_PrevRes <= 0)) {
    SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE = 0.0F;
  }

  /* Sum: '<S3>/Add1' incorporates:
   *  Gain: '<S3>/CC_Inputs.SensorAccuracy_pct//100'
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/Current_mA'
   */
  rtb_absCurrent_mA = ((real32_T)SOCEstimation_U.CC_Inputs.SensorOffset_mA +
                       (real32_T)SOCEstimation_U.CC_Inputs.BleedingCurrent_mA) +
    (real32_T)SOCEstimation_U.Current_mA;

  /* Chart: '<S3>/Chart1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_DW.is_active_c14_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c14_SOCEstimation = 1U;
    SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;
  } else if (SOCEstimation_DW.is_c14_SOCEstimation ==
             SOCEstimat_IN_IntegratedCurrent) {
    if ((int32_T)rtb_CC_State == 1) {
      SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimatio_IN_IntegratorReset;
    } else {
      SOCEstimation_B.IntegratedCurrent_k +=
        SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec * rtb_absCurrent_mA;
    }

    /* case IN_IntegratorReset: */
  } else if (((int32_T)rtb_CC_State == 0) || ((int32_T)rtb_CC_State == 2)) {
    SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;
  } else {
    SOCEstimation_B.IntegratedCurrent_k = 0.0F;
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator2'
   *  Gain: '<S3>/Gain2'
   *  Inport: '<Root>/CC_Inputs'
   */
  if (SOCEstimation_U.CC_Inputs.LoopTimeSelector) {
    tmp = SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE;
  } else {
    tmp = 0.001F * SOCEstimation_B.IntegratedCurrent_k;
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  Gain: '<S3>/Multiply2'
   *  Switch: '<S3>/Switch1'
   */
  rtb_MinCurrentLimit_mA = (int32_T)floorf(0.000277777785F * tmp);

  /* Chart: '<S3>/Chart' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/DataPipeline'
   */
  if (SOCEstimation_DW.is_active_c27_SOCEstimation == 0U) {
    SOCEstimation_DW.is_active_c27_SOCEstimation = 1U;
    SOCEstimation_DW.durationCounter_1_mg = 0U;
    SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimation_IN_Lobby;
  } else {
    switch (SOCEstimation_DW.is_c27_SOCEstimation) {
     case SOCEstimation_IN_Fully_Charged:
      if ((int32_T)rtb_CC_State == 0) {
        SOCEstimation_DW.durationCounter_1_mg = 0U;
        SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimation_IN_Lobby;
      } else {
        if ((SOCEstimation_B.Initial_Capacity_mAh < 0) &&
            (rtb_MinCurrentLimit_mA < MIN_int32_T
             - SOCEstimation_B.Initial_Capacity_mAh)) {
          SOCEstimation_B.TotalCapacityRemains_mAh = MIN_int32_T;
        } else if ((SOCEstimation_B.Initial_Capacity_mAh > 0) &&
                   (rtb_MinCurrentLimit_mA > MAX_int32_T
                    - SOCEstimation_B.Initial_Capacity_mAh)) {
          SOCEstimation_B.TotalCapacityRemains_mAh = MAX_int32_T;
        } else {
          SOCEstimation_B.TotalCapacityRemains_mAh =
            SOCEstimation_B.Initial_Capacity_mAh + rtb_MinCurrentLimit_mA;
        }

        if (SOCEstimation_B.TotalCapacityRemains_mAh <
            SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }
      }
      break;

     case SOCEstimation_IN_Lobby:
      {
        boolean_T tmp_0;
        tmp_0 = !SOCEstimation_U.CC_Inputs.pseudoLatchFlag;
        if ((SOCEstimation_B.Initial_Capacity_mAh ==
             SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) &&
            ((int32_T)rtb_CC_State == 1) && tmp_0) {
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
          if (tmp_0 || (!SOCEstimation_U.DataPipeline.VCU.isChargerConnected)) {
            SOCEstimation_DW.durationCounter_1_mg = 0U;
          }

          if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_mg *
               100) > SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
            SOCEstimation_DW.durationCounter_2_d = 0U;
            SOCEstimation_DW.durationCounter_1_n = 0U;
            SOCEstimation_DW.is_c27_SOCEstimation =
              SOCEstima_IN_PseudoLatchHandler;
          } else {
            if ((SOCEstimation_B.Initial_Capacity_mAh < 0) &&
                (rtb_MinCurrentLimit_mA < MIN_int32_T
                 - SOCEstimation_B.Initial_Capacity_mAh)) {
              SOCEstimation_B.TotalCapacityRemains_mAh = MIN_int32_T;
            } else if ((SOCEstimation_B.Initial_Capacity_mAh > 0) &&
                       (rtb_MinCurrentLimit_mA > MAX_int32_T
                        - SOCEstimation_B.Initial_Capacity_mAh)) {
              SOCEstimation_B.TotalCapacityRemains_mAh = MAX_int32_T;
            } else {
              SOCEstimation_B.TotalCapacityRemains_mAh =
                SOCEstimation_B.Initial_Capacity_mAh + rtb_MinCurrentLimit_mA;
            }

            if (SOCEstimation_B.TotalCapacityRemains_mAh <
                SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
              SOCEstimation_DW.durationCounter_2_d = 0U;
            }
          }
        }
      }
      break;

     case SOCEstima_IN_PseudoLatchHandler:
      if (SOCEstimation_B.TotalCapacityRemains_mAh <
          SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh) {
        SOCEstimation_DW.durationCounter_2_d = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2_d * SOCEstimation_U.looptimeSoC)
          > SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
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
          SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimation_IN_Lobby;
        } else {
          if ((SOCEstimation_B.Initial_Capacity_mAh < 0) &&
              (rtb_MinCurrentLimit_mA < MIN_int32_T
               - SOCEstimation_B.Initial_Capacity_mAh)) {
            SOCEstimation_B.TotalCapacityRemains_mAh = MIN_int32_T;
          } else if ((SOCEstimation_B.Initial_Capacity_mAh > 0) &&
                     (rtb_MinCurrentLimit_mA > MAX_int32_T
                      - SOCEstimation_B.Initial_Capacity_mAh)) {
            SOCEstimation_B.TotalCapacityRemains_mAh = MAX_int32_T;
          } else {
            SOCEstimation_B.TotalCapacityRemains_mAh =
              SOCEstimation_B.Initial_Capacity_mAh + rtb_MinCurrentLimit_mA;
          }

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
        SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimation_IN_Lobby;
      } else {
        SOCEstimation_B.TotalCapacityRemains_mAh = 0;
        if (SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh > 0) {
          SOCEstimation_DW.durationCounter_2_d = 0U;
        }
      }
      break;
    }
  }

  if (SOCEstimation_U.CC_Inputs.pseudoLatchFlag &&
      SOCEstimation_U.DataPipeline.VCU.isChargerConnected) {
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

  /* DataStoreWrite: '<S1>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  SOCEstimation_DW.CapacityRemains_mAh =
    SOCEstimation_B.TotalCapacityRemains_mAh;

  /* Gain: '<S7>/Gain' incorporates:
   *  Product: '<S7>/Divide1'
   */
  rtb_SOH_cpct = (int32_T)floorf((real32_T)
    SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh / (real32_T)
    SOCEstimation_B.Final_InstalledCapacity_mAh * 10000.0F);

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_SOH_cpct > 10000) {
    rtb_SOH_cpct = 10000;
  } else if (rtb_SOH_cpct < 0) {
    rtb_SOH_cpct = 0;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  rtb_MaxCurrentLimit_mA = (int32_T)floorf(rtb_Gain2);

  /* MATLAB Function: '<S1>/SOC_WriteToFlash' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  SOCEstimation_SOC_WriteToFlash(SOCEstimation_DW.SOC_pct,
    &SOCEstimation_B.sf_SOC_WriteToFlash);

  /* Gain: '<S3>/Gain1' incorporates:
   *  Product: '<S3>/Divide2'
   */
  rtb_SOC_cpct_a = (int32_T)floor((real_T)
    SOCEstimation_B.TotalCapacityRemains_mAh / (real_T)
    SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh * 10000.0);

  /* Saturate: '<S1>/Saturation' */
  if (rtb_SOC_cpct_a > 10000) {
    rtb_SOC_cpct_a = 10000;
  } else if (rtb_SOC_cpct_a < 0) {
    rtb_SOC_cpct_a = 0;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Sum: '<S1>/Subtract' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  u = rtb_SOC_cpct_a - SOCEstimation_DW.SOC_pct;

  /* Abs: '<S1>/Abs' */
  if (u < 0) {
    u = -u;
  }

  /* Outputs for Triggered SubSystem: '<S1>/Subsystem' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  /* Switch: '<S1>/Switch1' incorporates:
   *  Abs: '<S1>/Abs'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &SOCEstimation_PrevZCX.Subsystem_Trig_ZCE,
                     ((real_T)(u > 1)));
  if (zcEvent != NO_ZCEVENT) {
    /* DataStoreWrite: '<S9>/Data Store Write1' */
    SOCEstimation_DW.SOC_pct = rtb_SOC_cpct_a;
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* BusCreator: '<S1>/Bus Creator1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Outport: '<Root>/CC_Outputs'
   */
  SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh =
    SOCEstimation_B.Initial_Capacity_mAh;
  SOCEstimation_Y.CC_Outputs.Total_CapacityRemains_mAh =
    SOCEstimation_B.TotalCapacityRemains_mAh;
  SOCEstimation_Y.CC_Outputs.Total_Discharge_mAh = rtb_MinCurrentLimit_mA;
  SOCEstimation_Y.CC_Outputs.SOC_cpct = rtb_SOC_cpct_a;
  SOCEstimation_Y.CC_Outputs.CC_State = rtb_CC_State;
  SOCEstimation_Y.CC_Outputs.MaxUsableCapacity_mAh =
    SOCEstimation_B.sf_UsableCapacity_mAh.MaxUsableCapacity_mAh;
  SOCEstimation_Y.CC_Outputs.TotalCapacityExchange_mAh = rtb_MaxCurrentLimit_mA;
  SOCEstimation_Y.CC_Outputs.SOH_cpct = rtb_SOH_cpct;
  SOCEstimation_Y.CC_Outputs.CycleCount = rtb_CycleCount;

  /* Outport: '<Root>/SOC_FromFlash' */
  SOCEstimation_Y.SOC_FromFlash = SOCEstimation_B.sf_SOC_WriteToFlash.SOC;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  SOCEstimation_DW.DiscreteTimeIntegrator_DSTATE += 0.1F * (real32_T)
    rtb_absCurrent_mA_l;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE += 0.1F * rtb_absCurrent_mA;
  if ((int32_T)rtb_CC_State > 0) {
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

  /* states (dwork) */
  (void) memset((void *)&SOCEstimation_DW, 0,
                sizeof(DW_SOCEstimation_T));

  /* external inputs */
  (void)memset(&SOCEstimation_U, 0, sizeof(ExtU_SOCEstimation_T));
  SOCEstimation_U.ProtectionOutput = SOCEstimation_rtZProtectionStat;
  SOCEstimation_U.CellBalancingOutput = SOCEstimation_rtZCellBalancingO;

  /* external outputs */
  (void)memset(&SOCEstimation_Y, 0, sizeof(ExtY_SOCEstimation_T));
  SOCEstimation_Y.CC_Outputs = SOCEstimation_rtZCC_OutputsBus;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
  SOCEstimation_DW.SOC_pct = 0;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
  SOCEstimation_DW.PSEUDO_LATCH_SUCCESS = false;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  SOCEstimation_DW.CapacityRemains_mAh = 0;
  SOCEstimation_PrevZCX.Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  SOCEstimation_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
  SOCEstimation_DW.DiscreteTimeIntegrator2_DSTATE = 0.0F;
  SOCEstimation_DW.DiscreteTimeIntegrator2_PrevRes = 2;

  /* SystemInitialize for Chart: '<S7>/Chart' */
  SOCEstimation_DW.is_active_c19_SOCEstimation = 0U;
  SOCEstimation_B.IntegratedCurrent = 0.0F;

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
  SOCEstimation_B.DataTypeConversion = 0;

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
  SOCEstimation_B.Initial_Capacity_mAh = 0;

  /* SystemInitialize for Chart: '<S3>/Chart1' */
  SOCEstimation_DW.is_active_c14_SOCEstimation = 0U;
  SOCEstimation_DW.is_c14_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_B.IntegratedCurrent_k = 0.0F;

  /* SystemInitialize for Chart: '<S3>/Chart' */
  SOCEstimation_DW.is_active_c27_SOCEstimation = 0U;
  SOCEstimation_DW.is_c27_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;
  SOCEstimation_B.TotalCapacityRemains_mAh = 2;
}

/* Model terminate function */
void SOCEstimation_terminate(void)
{
  /* (no terminate code required) */
}
