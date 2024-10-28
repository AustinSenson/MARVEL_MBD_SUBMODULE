/*
 * CellBalancing.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CellBalancing".
 *
 * Model version              : 4.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Oct 11 19:04:07 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "CellBalancing.h"
#include "rtwtypes.h"
#include "CellBalancing_private.h"
#include <math.h>
#include <string.h>
#include "CellBalancing_types.h"

/* Named constants for Chart: '<S1>/BalancingStateMachine' */
#define CellBalancin_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define CellBalancing_IN_Even_Balance  ((uint8_T)1U)
#define CellBalancing_IN_Lobby         ((uint8_T)2U)
#define CellBalancing_IN_Odd_Balance   ((uint8_T)3U)
#define CellBalancing_IN_Terminate     ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart' */
#define Cell_IN_BalancingTimeOn_Default ((uint8_T)2U)
#define IN_BalancingTimeOn_BasedOnTemp_ ((uint8_T)1U)

/* Named constants for Chart: '<S3>/Chart1' */
#define CellBalancing_IN_PCBTemp_Danger ((uint8_T)1U)
#define CellBalancing_IN_PCBTemp_Safe  ((uint8_T)2U)

/* Block signals (default storage) */
B_CellBalancing_T CellBalancing_B;

/* Block states (default storage) */
DW_CellBalancing_T CellBalancing_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CellBalancing_T CellBalancing_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_CellBalancing_T CellBalancing_Y;

/* Real-time model */
static RT_MODEL_CellBalancing_T CellBalancing_M_;
RT_MODEL_CellBalancing_T *const CellBalancing_M = &CellBalancing_M_;

/* Forward declaration for local functions */
static void CellBalanc_BalanceFetCmd_AllOff(void);
static void CellBalancing_CellBalance(void);
const CellBalancingOutputBus CellBalancing_rtZCellBalancingO = { 0,/* MaxImbalance_mV */
  false,                               /* BalanceEn */
  Terminate                            /* CurrentBalancingState */
};

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S1>/BalancingStateMachine' */
static void CellBalanc_BalanceFetCmd_AllOff(void)
{
  int32_T b;

  /* Inport: '<Root>/DataPipeline' */
  if (CellBalancing_U.DataPipeline.nCells_series < 1) {
    b = 0;
  } else {
    b = CellBalancing_U.DataPipeline.nCells_series;
  }

  /* End of Inport: '<Root>/DataPipeline' */
  if (b - 1 >= 0) {
    /* Outport: '<Root>/BalanceCmd' */
    memset(&CellBalancing_Y.BalanceCmd[0], 0, (uint32_T)b * sizeof(int8_T));
  }
}

/* Function for Chart: '<S1>/BalancingStateMachine' */
static void CellBalancing_CellBalance(void)
{
  boolean_T sf_internal_predicateOutput;
  if (CellBalancing_B.BalanceEn) {
    int32_T tmp;

    /* Inport: '<Root>/DataPipeline' incorporates:
     *  Inport: '<Root>/Thresholds'
     */
    if ((CellBalancing_U.DataPipeline.VoltageSenseBus.mV_min < 0) &&
        (CellBalancing_U.Thresholds.Balancing_MaxAllowedImb_mV < MIN_int32_T
         - CellBalancing_U.DataPipeline.VoltageSenseBus.mV_min)) {
      tmp = MIN_int32_T;
    } else if ((CellBalancing_U.DataPipeline.VoltageSenseBus.mV_min > 0) &&
               (CellBalancing_U.Thresholds.Balancing_MaxAllowedImb_mV >
                MAX_int32_T
                - CellBalancing_U.DataPipeline.VoltageSenseBus.mV_min)) {
      tmp = MAX_int32_T;
    } else {
      tmp = CellBalancing_U.DataPipeline.VoltageSenseBus.mV_min +
        CellBalancing_U.Thresholds.Balancing_MaxAllowedImb_mV;
    }

    /* End of Inport: '<Root>/DataPipeline' */
    if (CellBalancing_U.DataPipeline.VoltageSenseBus.Voltages_mV[(int32_T)
        CellBalancing_DW.i - 1] > tmp) {
      sf_internal_predicateOutput = true;
    } else {
      sf_internal_predicateOutput = false;
    }
  } else {
    sf_internal_predicateOutput = false;
  }

  /* Outport: '<Root>/BalanceCmd' */
  CellBalancing_Y.BalanceCmd[(int32_T)CellBalancing_DW.i - 1] = (int8_T)
    sf_internal_predicateOutput;
}

/* Model step function */
void CellBalancing_step(void)
{
  int32_T q0;
  int32_T rtb_MaxImbalance_mV_tmp;
  boolean_T rtb_PCBTemp;

  /* Chart: '<S3>/Chart1' incorporates:
   *  Inport: '<Root>/DataPipeline'
   *  Inport: '<Root>/Thresholds'
   */
  if (CellBalancing_DW.is_active_c26_CellBalancing == 0U) {
    CellBalancing_DW.is_active_c26_CellBalancing = 1U;
    CellBalancing_DW.is_c26_CellBalancing = CellBalancing_IN_PCBTemp_Safe;
    rtb_PCBTemp = true;
  } else if (CellBalancing_DW.is_c26_CellBalancing ==
             CellBalancing_IN_PCBTemp_Danger) {
    rtb_PCBTemp = false;
    if ((CellBalancing_U.DataPipeline.TemperatureSenseBus[1].T_max <
         CellBalancing_U.Thresholds.Temperature[1].Protections_OTC_Error_C) ||
        (CellBalancing_U.DataPipeline.TemperatureSenseBus[1].T_max <
         CellBalancing_U.Thresholds.Temperature[1].Protections_OTD_Error_C)) {
      CellBalancing_DW.is_c26_CellBalancing = CellBalancing_IN_PCBTemp_Safe;
      rtb_PCBTemp = true;
    }
  } else {
    /* case IN_PCBTemp_Safe: */
    rtb_PCBTemp = true;
    if ((CellBalancing_U.DataPipeline.TemperatureSenseBus[1].T_max >=
         CellBalancing_U.Thresholds.Temperature[1].Protections_OTC_Error_C) ||
        (CellBalancing_U.DataPipeline.TemperatureSenseBus[1].T_max >=
         CellBalancing_U.Thresholds.Temperature[1].Protections_OTD_Error_C)) {
      CellBalancing_DW.is_c26_CellBalancing = CellBalancing_IN_PCBTemp_Danger;
      rtb_PCBTemp = false;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Sum: '<S3>/Subtract' incorporates:
   *  Inport: '<Root>/DataPipeline'
   *  Sum: '<S1>/Subtract'
   */
  rtb_MaxImbalance_mV_tmp = CellBalancing_U.DataPipeline.VoltageSenseBus.mV_max
    - CellBalancing_U.DataPipeline.VoltageSenseBus.mV_min;

  /* Switch: '<S3>/Switch' incorporates:
   *  Inport: '<Root>/DataPipeline'
   *  Inport: '<Root>/Thresholds'
   *  Inport: '<Root>/maxAllowedImbalance'
   *  Logic: '<S3>/AND'
   *  Logic: '<S3>/OR1'
   *  RelationalOperator: '<S3>/GreaterThan'
   *  RelationalOperator: '<S3>/GreaterThan2'
   *  RelationalOperator: '<S3>/GreaterThan3'
   *  RelationalOperator: '<S6>/Compare'
   *  Sum: '<S3>/Subtract'
   */
  CellBalancing_B.BalanceEn = (rtb_PCBTemp && ((rtb_MaxImbalance_mV_tmp >
    CellBalancing_U.maxAllowedImbalance) ||
    CellBalancing_U.DataPipeline.VCU.isChargerConnected) &&
    (CellBalancing_U.DataPipeline.VoltageSenseBus.mV_min >
     CellBalancing_U.Thresholds.Balancing_Min_Thr_mV) &&
    (rtb_MaxImbalance_mV_tmp >
     CellBalancing_U.Thresholds.Balancing_MaxAllowedImb_mV));

  /* Chart: '<S3>/Chart' incorporates:
   *  Inport: '<Root>/BalancingTempGroup'
   *  Inport: '<Root>/DataPipeline'
   *  Inport: '<Root>/StLineEq_varA'
   *  Inport: '<Root>/StLineEq_varB'
   *  Inport: '<Root>/Thresholds'
   */
  if (CellBalancing_DW.is_active_c6_CellBalancing == 0U) {
    CellBalancing_DW.is_active_c6_CellBalancing = 1U;
    CellBalancing_DW.durationCounter_1 = 0U;
    CellBalancing_DW.is_c6_CellBalancing = Cell_IN_BalancingTimeOn_Default;
    CellBalancing_B.BalancingTimeOn_msec =
      CellBalancing_U.Thresholds.Balancing_DefaultBalancingTimeOn_msec;
  } else if (CellBalancing_DW.is_c6_CellBalancing ==
             IN_BalancingTimeOn_BasedOnTemp_) {
    real_T tmp;
    tmp = rt_roundd_snf((real_T)CellBalancing_U.StLineEq_varA *
                        CellBalancing_DW.x);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        q0 = (int32_T)tmp;
      } else {
        q0 = MIN_int32_T;
      }
    } else {
      q0 = MAX_int32_T;
    }

    if ((q0 < 0) && (CellBalancing_U.StLineEq_varB < MIN_int32_T - q0)) {
      CellBalancing_B.BalancingTimeOn_msec = -2.147483648E+9;
    } else if ((q0 > 0) && (CellBalancing_U.StLineEq_varB > MAX_int32_T - q0)) {
      CellBalancing_B.BalancingTimeOn_msec = 2.147483647E+9;
    } else {
      CellBalancing_B.BalancingTimeOn_msec = q0 + CellBalancing_U.StLineEq_varB;
    }
  } else {
    /* case IN_BalancingTimeOn_Default: */
    if (CellBalancing_U.DataPipeline.TemperatureSenseBus[CellBalancing_U.BalancingTempGroup
        - 1].T_max <=
        CellBalancing_U.Thresholds.BalancingCurrentDerateActivationTemp_C) {
      CellBalancing_DW.durationCounter_1 = 0U;
    }

    if ((real_T)(uint32_T)((int32_T)CellBalancing_DW.durationCounter_1 * 100) >
        CellBalancing_U.Thresholds.BalancingCurrentDerateCheckTime_msec) {
      CellBalancing_DW.is_c6_CellBalancing = IN_BalancingTimeOn_BasedOnTemp_;
      CellBalancing_DW.x =
        CellBalancing_U.DataPipeline.TemperatureSenseBus[CellBalancing_U.BalancingTempGroup
        - 1].T_max;
    }
  }

  if (CellBalancing_U.DataPipeline.TemperatureSenseBus[CellBalancing_U.BalancingTempGroup
      - 1].T_max >
      CellBalancing_U.Thresholds.BalancingCurrentDerateActivationTemp_C) {
    CellBalancing_DW.durationCounter_1++;
  } else {
    CellBalancing_DW.durationCounter_1 = 0U;
  }

  /* End of Chart: '<S3>/Chart' */

  /* Chart: '<S1>/BalancingStateMachine' incorporates:
   *  Inport: '<Root>/DataPipeline'
   *  Inport: '<Root>/Thresholds'
   *  Outport: '<Root>/BalanceCmd'
   */
  if (CellBalancing_DW.temporalCounter_i1 < MAX_uint32_T) {
    CellBalancing_DW.temporalCounter_i1++;
  }

  if (CellBalancing_DW.is_active_c3_CellBalancing == 0U) {
    CellBalancing_DW.is_active_c3_CellBalancing = 1U;
    CellBalancing_DW.durationCounter_1_c = 0U;
    CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Lobby;
    CellBalancing_DW.temporalCounter_i1 = 0U;

    /* BusCreator: '<S1>/Bus Creator' incorporates:
     *  Outport: '<Root>/CellBalancingOutput'
     */
    CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Lobby;
  } else {
    switch (CellBalancing_DW.is_c3_CellBalancing) {
     case CellBalancing_IN_Even_Balance:
      /* BusCreator: '<S1>/Bus Creator' incorporates:
       *  Outport: '<Root>/CellBalancingOutput'
       */
      CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Even_Balancing;
      if ((uint32_T)((int32_T)CellBalancing_DW.temporalCounter_i1 * 100) >=
          (uint32_T)ceil(CellBalancing_B.BalancingTimeOn_msec)) {
        if (CellBalancing_U.DataPipeline.nCells_series < 1) {
          q0 = 0;
        } else {
          q0 = CellBalancing_U.DataPipeline.nCells_series;
        }

        if (q0 - 1 >= 0) {
          memset(&CellBalancing_Y.BalanceCmd[0], 0, (uint32_T)q0 * sizeof(int8_T));
        }

        CellBalanc_BalanceFetCmd_AllOff();
        CellBalancing_DW.durationCounter_1_n = 0U;
        CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Odd_Balance;
        CellBalancing_DW.temporalCounter_i1 = 0U;
        CellBalanc_BalanceFetCmd_AllOff();

        /* BusCreator: '<S1>/Bus Creator' incorporates:
         *  Inport: '<Root>/DataPipeline'
         *  Outport: '<Root>/BalanceCmd'
         *  Outport: '<Root>/CellBalancingOutput'
         */
        CellBalancing_Y.CellBalancingOutput.CurrentBalancingState =
          Odd_Balancing;
        CellBalancing_DW.i = 1.0;
        while ((int32_T)CellBalancing_DW.i <=
               CellBalancing_U.DataPipeline.nCells_series) {
          CellBalancing_CellBalance();
          CellBalancing_DW.i += 2.0;
        }
      } else {
        if (CellBalancing_B.BalanceEn) {
          CellBalancing_DW.durationCounter_1_h = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)CellBalancing_DW.durationCounter_1_h *
                               100) >
            CellBalancing_U.Thresholds.Balancing_StateRestPeriod_msec) {
          CellBalanc_BalanceFetCmd_AllOff();
          CellBalancing_DW.durationCounter_1_k = 0U;
          CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Terminate;
          CellBalanc_BalanceFetCmd_AllOff();

          /* BusCreator: '<S1>/Bus Creator' incorporates:
           *  Outport: '<Root>/CellBalancingOutput'
           */
          CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Terminate;
        }
      }
      break;

     case CellBalancing_IN_Lobby:
      /* BusCreator: '<S1>/Bus Creator' incorporates:
       *  Outport: '<Root>/CellBalancingOutput'
       */
      CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Lobby;
      if (CellBalancing_B.BalanceEn) {
        CellBalancing_DW.durationCounter_1_c = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)CellBalancing_DW.durationCounter_1_c * 100)
          > CellBalancing_U.Thresholds.Balancing_StateRestPeriod_msec) {
        CellBalancing_DW.durationCounter_1_k = 0U;
        CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Terminate;
        CellBalanc_BalanceFetCmd_AllOff();

        /* BusCreator: '<S1>/Bus Creator' incorporates:
         *  Outport: '<Root>/CellBalancingOutput'
         */
        CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Terminate;
      } else if (CellBalancing_B.BalanceEn && ((uint32_T)((int32_T)
                   CellBalancing_DW.temporalCounter_i1 * 100) >= (uint32_T)
                  CellBalancing_U.Thresholds.Balancing_StateRestPeriod_msec)) {
        CellBalancing_DW.durationCounter_1_h = 0U;
        CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Even_Balance;
        CellBalancing_DW.temporalCounter_i1 = 0U;
        CellBalanc_BalanceFetCmd_AllOff();

        /* BusCreator: '<S1>/Bus Creator' incorporates:
         *  Outport: '<Root>/CellBalancingOutput'
         */
        CellBalancing_Y.CellBalancingOutput.CurrentBalancingState =
          Even_Balancing;
        CellBalancing_DW.i = 2.0;
        while ((int32_T)CellBalancing_DW.i <=
               CellBalancing_U.DataPipeline.nCells_series) {
          CellBalancing_CellBalance();
          CellBalancing_DW.i += 2.0;
        }
      }
      break;

     case CellBalancing_IN_Odd_Balance:
      /* BusCreator: '<S1>/Bus Creator' incorporates:
       *  Outport: '<Root>/CellBalancingOutput'
       */
      CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Odd_Balancing;
      if ((uint32_T)((int32_T)CellBalancing_DW.temporalCounter_i1 * 100) >=
          (uint32_T)ceil(CellBalancing_B.BalancingTimeOn_msec)) {
        if (CellBalancing_U.DataPipeline.nCells_series < 1) {
          q0 = 0;
        } else {
          q0 = CellBalancing_U.DataPipeline.nCells_series;
        }

        if (q0 - 1 >= 0) {
          memset(&CellBalancing_Y.BalanceCmd[0], 0, (uint32_T)q0 * sizeof(int8_T));
        }

        CellBalanc_BalanceFetCmd_AllOff();
        CellBalancing_DW.durationCounter_1_c = 0U;
        CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Lobby;
        CellBalancing_DW.temporalCounter_i1 = 0U;

        /* BusCreator: '<S1>/Bus Creator' incorporates:
         *  Inport: '<Root>/DataPipeline'
         *  Outport: '<Root>/BalanceCmd'
         *  Outport: '<Root>/CellBalancingOutput'
         */
        CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Lobby;
      } else {
        if (CellBalancing_B.BalanceEn) {
          CellBalancing_DW.durationCounter_1_n = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)CellBalancing_DW.durationCounter_1_n *
                               100) >
            CellBalancing_U.Thresholds.Balancing_StateRestPeriod_msec) {
          CellBalanc_BalanceFetCmd_AllOff();
          CellBalancing_DW.durationCounter_1_k = 0U;
          CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Terminate;
          CellBalanc_BalanceFetCmd_AllOff();

          /* BusCreator: '<S1>/Bus Creator' incorporates:
           *  Outport: '<Root>/CellBalancingOutput'
           */
          CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Terminate;
        }
      }
      break;

     default:
      /* BusCreator: '<S1>/Bus Creator' incorporates:
       *  Outport: '<Root>/CellBalancingOutput'
       */
      /* case IN_Terminate: */
      CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Terminate;
      if (!CellBalancing_B.BalanceEn) {
        CellBalancing_DW.durationCounter_1_k = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)CellBalancing_DW.durationCounter_1_k * 100)
          > CellBalancing_U.Thresholds.Balancing_StateRestPeriod_msec) {
        CellBalancing_DW.durationCounter_1_c = 0U;
        CellBalancing_DW.is_c3_CellBalancing = CellBalancing_IN_Lobby;
        CellBalancing_DW.temporalCounter_i1 = 0U;

        /* BusCreator: '<S1>/Bus Creator' incorporates:
         *  Outport: '<Root>/CellBalancingOutput'
         */
        CellBalancing_Y.CellBalancingOutput.CurrentBalancingState = Lobby;
      }
      break;
    }
  }

  if (!CellBalancing_B.BalanceEn) {
    CellBalancing_DW.durationCounter_1_c++;
    CellBalancing_DW.durationCounter_1_k = 0U;
    CellBalancing_DW.durationCounter_1_h++;
    CellBalancing_DW.durationCounter_1_n++;
  } else {
    CellBalancing_DW.durationCounter_1_c = 0U;
    CellBalancing_DW.durationCounter_1_k++;
    CellBalancing_DW.durationCounter_1_h = 0U;
    CellBalancing_DW.durationCounter_1_n = 0U;
  }

  /* End of Chart: '<S1>/BalancingStateMachine' */

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Outport: '<Root>/CellBalancingOutput'
   */
  CellBalancing_Y.CellBalancingOutput.MaxImbalance_mV = rtb_MaxImbalance_mV_tmp;
  CellBalancing_Y.CellBalancingOutput.BalanceEn = CellBalancing_B.BalanceEn;
}

/* Model initialize function */
void CellBalancing_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(CellBalancing_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &CellBalancing_B), 0,
                sizeof(B_CellBalancing_T));

  /* states (dwork) */
  (void) memset((void *)&CellBalancing_DW, 0,
                sizeof(DW_CellBalancing_T));

  /* external inputs */
  (void)memset(&CellBalancing_U, 0, sizeof(ExtU_CellBalancing_T));

  /* external outputs */
  (void)memset(&CellBalancing_Y, 0, sizeof(ExtY_CellBalancing_T));
  CellBalancing_Y.CellBalancingOutput = CellBalancing_rtZCellBalancingO;

  {
    int32_T i;

    /* SystemInitialize for Chart: '<S3>/Chart1' */
    CellBalancing_DW.is_active_c26_CellBalancing = 0U;
    CellBalancing_DW.is_c26_CellBalancing = CellBalancin_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S3>/Chart' */
    CellBalancing_DW.is_active_c6_CellBalancing = 0U;
    CellBalancing_DW.is_c6_CellBalancing = CellBalancin_IN_NO_ACTIVE_CHILD;
    CellBalancing_DW.x = 1.0;
    CellBalancing_B.BalancingTimeOn_msec = 1.0;

    /* SystemInitialize for Chart: '<S1>/BalancingStateMachine' */
    CellBalancing_DW.temporalCounter_i1 = 0U;
    CellBalancing_DW.is_active_c3_CellBalancing = 0U;
    CellBalancing_DW.is_c3_CellBalancing = CellBalancin_IN_NO_ACTIVE_CHILD;
    CellBalancing_DW.i = 0.0;
    for (i = 0; i < 18; i++) {
      /* SystemInitialize for Outport: '<Root>/BalanceCmd' incorporates:
       *  Chart: '<S1>/BalancingStateMachine'
       */
      CellBalancing_Y.BalanceCmd[i] = 0;
    }
  }
}

/* Model terminate function */
void CellBalancing_terminate(void)
{
  /* (no terminate code required) */
}
