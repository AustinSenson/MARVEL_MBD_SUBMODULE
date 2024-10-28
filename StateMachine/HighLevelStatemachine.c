/*
 * HighLevelStatemachine.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "HighLevelStatemachine".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:50:55 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "HighLevelStatemachine.h"
#include "rtwtypes.h"
#include "HighLevelStatemachine_types.h"
#include <string.h>

/* Named constants for Chart: '<S1>/HighLevelStatemachine' */
#define HighLevelSt_IN_PermanentFailure ((uint8_T)2U)
#define HighLevelSta_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define HighLevelState_IN_DeepSleepMode ((uint8_T)7U)
#define HighLevelStatem_IN_FastCharging ((uint8_T)3U)
#define HighLevelStatem_IN_LowPowerMode ((uint8_T)8U)
#define HighLevelStatem_IN_Regeneration ((uint8_T)5U)
#define HighLevelStatem_IN_SlowCharging ((uint8_T)6U)
#define HighLevelStatema_IN_Discharging ((uint8_T)2U)
#define HighLevelStatema_IN_ServiceMode ((uint8_T)9U)
#define HighLevelStatemac_IN_Activating ((uint8_T)1U)
#define HighLevelStatemac_IN_Fault_Mode ((uint8_T)1U)
#define HighLevelStatemac_IN_Protection ((uint8_T)3U)
#define HighLevelStatemachi_IN_LimpHome ((uint8_T)1U)
#define HighLevelStatemachine_IN_Active ((uint8_T)2U)
#define HighLevelStatemachine_IN_Error ((uint8_T)3U)
#define HighLevelStatemachine_IN_Idle  ((uint8_T)4U)
#define HighLevelStatemachine_IN_Ready ((uint8_T)5U)

/* Block states (default storage) */
DW_HighLevelStatemachine_T HighLevelStatemachine_DW;

/* External inputs (root inport signals with default storage) */
ExtU_HighLevelStatemachine_T HighLevelStatemachine_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_HighLevelStatemachine_T HighLevelStatemachine_Y;

/* Real-time model */
static RT_MODEL_HighLevelStatemachin_T HighLevelStatemachine_M_;
RT_MODEL_HighLevelStatemachin_T *const HighLevelStatemachine_M =
  &HighLevelStatemachine_M_;

/* Forward declaration for local functions */
static void HighLevelStatemachin_Fault_Mode(void);
static void HighLevelStatemach_FastCharging(void);
static void HighLevelStatemach_SlowCharging(void);
static void HighLevel_HighLevelStatemachine(void);
static void HighLevelStatemachine_BMS_State(void);
const ProtectionState_Out HighLevelStatemachine_rtZProtec = { NoError,/* ThermalRunaway */
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

/* Function for Chart: '<S1>/HighLevelStatemachine' */
static void HighLevelStatemachin_Fault_Mode(void)
{
  switch (HighLevelStatemachine_DW.is_Fault_Mode) {
   case HighLevelStatemachi_IN_LimpHome:
    /* Inport: '<Root>/DataPipeline' */
    if (!HighLevelStatemachine_U.DataPipeline.VCU.VCUPermanentFail) {
      HighLevelStatemachine_DW.durationCounter_2_lq = 0U;
    }

    /* Inport: '<Root>/Thresholds' incorporates:
     *  Inport: '<Root>/DataPipeline'
     */
    if ((real_T)(uint32_T)((int32_T)
                           HighLevelStatemachine_DW.durationCounter_2_lq * HighLevelStatemachine_U.looptimeStateMachine) >
        HighLevelStatemachine_U.Thresholds.FaultsModeTimeout_msec) {
      HighLevelStatemachine_DW.durationCounter_1_jt = 0U;
      HighLevelStatemachine_DW.is_Fault_Mode = HighLevelSt_IN_PermanentFailure;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = PermanentFailFault;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      if (!HighLevelStatemachine_U.DataPipeline.VCU.ServiceMode) {
        HighLevelStatemachine_DW.durationCounter_1_dz = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_1_dz * HighLevelStatemachine_U.looptimeStateMachine)
          > HighLevelStatemachine_U.Thresholds.ServiceModeTimeout_msec) {
        HighLevelStatemachine_DW.is_Fault_Mode = HighLevelSta_IN_NO_ACTIVE_CHILD;
        HighLevelStatemachine_DW.is_HighLevelStatemachine =
          HighLevelStatema_IN_ServiceMode;

        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = ServiceMode;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      } else {
        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = LimpHomeFault;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      }
    }
    break;

   case HighLevelSt_IN_PermanentFailure:
    /* Inport: '<Root>/DataPipeline' */
    if (!HighLevelStatemachine_U.DataPipeline.VCU.ServiceMode) {
      HighLevelStatemachine_DW.durationCounter_1_jt = 0U;
    }

    /* Inport: '<Root>/Thresholds' */
    if ((real_T)(uint32_T)((int32_T)
                           HighLevelStatemachine_DW.durationCounter_1_jt * HighLevelStatemachine_U.looptimeStateMachine) >
        HighLevelStatemachine_U.Thresholds.ServiceModeTimeout_msec) {
      HighLevelStatemachine_DW.is_Fault_Mode = HighLevelSta_IN_NO_ACTIVE_CHILD;
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelStatema_IN_ServiceMode;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = ServiceMode;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = PermanentFailFault;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    }
    break;

   default:
    /* Inport: '<Root>/DataPipeline' */
    /* case IN_Protection: */
    if (!HighLevelStatemachine_U.DataPipeline.VCU.TransmissionFail) {
      HighLevelStatemachine_DW.durationCounter_2_bc = 0U;
    }

    /* Inport: '<Root>/Thresholds' incorporates:
     *  Inport: '<Root>/DataPipeline'
     */
    if ((real_T)(uint32_T)((int32_T)
                           HighLevelStatemachine_DW.durationCounter_2_bc * HighLevelStatemachine_U.looptimeStateMachine) >
        HighLevelStatemachine_U.Thresholds.FaultsModeTimeout_msec) {
      HighLevelStatemachine_DW.durationCounter_2_lq = 0U;
      HighLevelStatemachine_DW.durationCounter_1_dz = 0U;
      HighLevelStatemachine_DW.is_Fault_Mode = HighLevelStatemachi_IN_LimpHome;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = LimpHomeFault;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      if (!HighLevelStatemachine_U.DataPipeline.VCU.ServiceMode) {
        HighLevelStatemachine_DW.durationCounter_1_k = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_1_k * HighLevelStatemachine_U.looptimeStateMachine)
          > HighLevelStatemachine_U.Thresholds.ServiceModeTimeout_msec) {
        HighLevelStatemachine_DW.is_Fault_Mode = HighLevelSta_IN_NO_ACTIVE_CHILD;
        HighLevelStatemachine_DW.is_HighLevelStatemachine =
          HighLevelStatema_IN_ServiceMode;

        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = ServiceMode;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      } else {
        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = ProtectionFault;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      }
    }
    break;
  }
}

/* Function for Chart: '<S1>/HighLevelStatemachine' */
static void HighLevelStatemach_FastCharging(void)
{
  /* Inport: '<Root>/DataPipeline' */
  if (!HighLevelStatemachine_U.DataPipeline.VCU.SlowCharge) {
    HighLevelStatemachine_DW.durationCounter_4_k = 0U;
  }

  /* Inport: '<Root>/Thresholds' incorporates:
   *  Inport: '<Root>/DataPipeline'
   */
  if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_4_k *
       100) > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
    HighLevelStatemachine_DW.durationCounter_4_e = 0U;
    HighLevelStatemachine_DW.durationCounter_3_g = 0U;
    HighLevelStatemachine_DW.durationCounter_2_h = 0U;
    HighLevelStatemachine_DW.durationCounter_1_h = 0U;
    HighLevelStatemachine_DW.is_HighLevelStatemachine =
      HighLevelStatem_IN_SlowCharging;

    /* Outport: '<Root>/HighLevelStateMode' */
    HighLevelStatemachine_Y.HighLevelStateMode = ChargingSlow;
    HighLevelStatemachine_DW.durationCounter_2 = 0U;
    HighLevelStatemachine_DW.durationCounter_1_n = 0U;
  } else {
    if (HighLevelStatemachine_U.DataPipeline.Current_mA >=
        HighLevelStatemachine_U.Thresholds.ChargeDetectionThreshold_mA) {
      HighLevelStatemachine_DW.durationCounter_3_e = 0U;
    }

    /* Inport: '<Root>/DataPipeline' */
    if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_3_e
         * 100) > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
      HighLevelStatemachine_DW.durationCounter_4_o = 0U;
      HighLevelStatemachine_DW.durationCounter_3 = 0U;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1 = 0U;
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelStatemachine_IN_Idle;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = Idle;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      if (HighLevelStatemachine_U.DataPipeline.isChargeEn != 0) {
        HighLevelStatemachine_DW.durationCounter_2_b = 0U;
      }

      /* Inport: '<Root>/ProtectionOutput' */
      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_2_b * HighLevelStatemachine_U.looptimeStateMachine)
          > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
        HighLevelStatemachine_DW.durationCounter_4 = 0U;
        HighLevelStatemachine_DW.durationCounter_3_a = 0U;
        HighLevelStatemachine_DW.durationCounter_2_l = 0U;
        HighLevelStatemachine_DW.durationCounter_1_j = 0U;
        HighLevelStatemachine_DW.is_HighLevelStatemachine =
          HighLevelStatema_IN_Discharging;

        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = Discharging;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      } else {
        if ((int32_T)HighLevelStatemachine_U.ProtectionOutput.ErrorDetect != 1)
        {
          HighLevelStatemachine_DW.durationCounter_1_d = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)
                               HighLevelStatemachine_DW.durationCounter_1_d *
                               100) >
            HighLevelStatemachine_U.Thresholds.FaultsModeTimeout_msec) {
          HighLevelStatemachine_DW.is_HighLevelStatemachine =
            HighLevelStatemac_IN_Fault_Mode;
          HighLevelStatemachine_DW.durationCounter_2_bc = 0U;
          HighLevelStatemachine_DW.durationCounter_1_k = 0U;
          HighLevelStatemachine_DW.is_Fault_Mode =
            HighLevelStatemac_IN_Protection;

          /* Outport: '<Root>/HighLevelStateMode' */
          HighLevelStatemachine_Y.HighLevelStateMode = ProtectionFault;
          HighLevelStatemachine_DW.durationCounter_2 = 0U;
          HighLevelStatemachine_DW.durationCounter_1_n = 0U;
        }
      }

      /* End of Inport: '<Root>/ProtectionOutput' */
    }
  }

  /* End of Inport: '<Root>/Thresholds' */
}

/* Function for Chart: '<S1>/HighLevelStatemachine' */
static void HighLevelStatemach_SlowCharging(void)
{
  /* Inport: '<Root>/DataPipeline' */
  if (!HighLevelStatemachine_U.DataPipeline.VCU.FastCharge) {
    HighLevelStatemachine_DW.durationCounter_4_e = 0U;
  }

  /* Inport: '<Root>/Thresholds' incorporates:
   *  Inport: '<Root>/DataPipeline'
   */
  if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_4_e *
       100) > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
    HighLevelStatemachine_DW.durationCounter_4_k = 0U;
    HighLevelStatemachine_DW.durationCounter_3_e = 0U;
    HighLevelStatemachine_DW.durationCounter_2_b = 0U;
    HighLevelStatemachine_DW.durationCounter_1_d = 0U;
    HighLevelStatemachine_DW.is_HighLevelStatemachine =
      HighLevelStatem_IN_FastCharging;

    /* Outport: '<Root>/HighLevelStateMode' */
    HighLevelStatemachine_Y.HighLevelStateMode = ChargingFast;
    HighLevelStatemachine_DW.durationCounter_2 = 0U;
    HighLevelStatemachine_DW.durationCounter_1_n = 0U;
  } else {
    if (HighLevelStatemachine_U.DataPipeline.Current_mA >=
        HighLevelStatemachine_U.Thresholds.ChargeDetectionThreshold_mA) {
      HighLevelStatemachine_DW.durationCounter_3_g = 0U;
    }

    /* Inport: '<Root>/ProtectionOutput' */
    if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_3_g
         * 100) > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
      HighLevelStatemachine_DW.durationCounter_4_o = 0U;
      HighLevelStatemachine_DW.durationCounter_3 = 0U;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1 = 0U;
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelStatemachine_IN_Idle;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = Idle;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      if ((int32_T)HighLevelStatemachine_U.ProtectionOutput.ErrorDetect != 1) {
        HighLevelStatemachine_DW.durationCounter_1_h = 0U;
      }

      /* Inport: '<Root>/DataPipeline' */
      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_1_h * HighLevelStatemachine_U.looptimeStateMachine)
          > HighLevelStatemachine_U.Thresholds.FaultsModeTimeout_msec) {
        HighLevelStatemachine_DW.is_HighLevelStatemachine =
          HighLevelStatemac_IN_Fault_Mode;
        HighLevelStatemachine_DW.durationCounter_2_bc = 0U;
        HighLevelStatemachine_DW.durationCounter_1_k = 0U;
        HighLevelStatemachine_DW.is_Fault_Mode = HighLevelStatemac_IN_Protection;

        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = ProtectionFault;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      } else {
        if (HighLevelStatemachine_U.DataPipeline.isChargeEn != 0) {
          HighLevelStatemachine_DW.durationCounter_2_h = 0U;
        }

        if ((real_T)(uint32_T)((int32_T)
                               HighLevelStatemachine_DW.durationCounter_2_h *
                               100) >
            HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
          HighLevelStatemachine_DW.durationCounter_4 = 0U;
          HighLevelStatemachine_DW.durationCounter_3_a = 0U;
          HighLevelStatemachine_DW.durationCounter_2_l = 0U;
          HighLevelStatemachine_DW.durationCounter_1_j = 0U;
          HighLevelStatemachine_DW.is_HighLevelStatemachine =
            HighLevelStatema_IN_Discharging;

          /* Outport: '<Root>/HighLevelStateMode' */
          HighLevelStatemachine_Y.HighLevelStateMode = Discharging;
          HighLevelStatemachine_DW.durationCounter_2 = 0U;
          HighLevelStatemachine_DW.durationCounter_1_n = 0U;
        }
      }
    }

    /* End of Inport: '<Root>/ProtectionOutput' */
  }

  /* End of Inport: '<Root>/Thresholds' */
}

/* Function for Chart: '<S1>/HighLevelStatemachine' */
static void HighLevel_HighLevelStatemachine(void)
{
  switch (HighLevelStatemachine_DW.is_HighLevelStatemachine) {
   case HighLevelStatemac_IN_Fault_Mode:
    HighLevelStatemachin_Fault_Mode();
    break;

   case HighLevelStatema_IN_Discharging:
    /* Inport: '<Root>/DataPipeline' */
    if (HighLevelStatemachine_U.DataPipeline.isChargeEn != 1) {
      HighLevelStatemachine_DW.durationCounter_3_a = 0U;
    }

    /* Inport: '<Root>/Thresholds' incorporates:
     *  Inport: '<Root>/DataPipeline'
     */
    if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_3_a
         * 100) > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
      HighLevelStatemachine_DW.durationCounter_4_e = 0U;
      HighLevelStatemachine_DW.durationCounter_3_g = 0U;
      HighLevelStatemachine_DW.durationCounter_2_h = 0U;
      HighLevelStatemachine_DW.durationCounter_1_h = 0U;
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelStatem_IN_SlowCharging;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = ChargingSlow;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      if (HighLevelStatemachine_U.DataPipeline.Current_mA >=
          HighLevelStatemachine_U.Thresholds.ChargeDetectionThreshold_mA) {
        HighLevelStatemachine_DW.durationCounter_2_l = 0U;
      }

      /* Inport: '<Root>/DataPipeline' */
      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_2_l * HighLevelStatemachine_U.looptimeStateMachine)
          > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
        HighLevelStatemachine_DW.durationCounter_4_o = 0U;
        HighLevelStatemachine_DW.durationCounter_3 = 0U;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1 = 0U;
        HighLevelStatemachine_DW.is_HighLevelStatemachine =
          HighLevelStatemachine_IN_Idle;

        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = Idle;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      } else {
        if (HighLevelStatemachine_U.DataPipeline.VCU.isChargerConnected ||
            (HighLevelStatemachine_U.DataPipeline.isChargeEn != 1)) {
          HighLevelStatemachine_DW.durationCounter_4 = 0U;
        }

        /* Inport: '<Root>/ProtectionOutput' */
        if ((real_T)(uint32_T)((int32_T)
                               HighLevelStatemachine_DW.durationCounter_4 * HighLevelStatemachine_U.looptimeStateMachine)
            > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
          HighLevelStatemachine_DW.durationCounter_2_g = 0U;
          HighLevelStatemachine_DW.durationCounter_1_a = 0U;
          HighLevelStatemachine_DW.is_HighLevelStatemachine =
            HighLevelStatem_IN_Regeneration;

          /* Outport: '<Root>/HighLevelStateMode' */
          HighLevelStatemachine_Y.HighLevelStateMode = Regeneration;
          HighLevelStatemachine_DW.durationCounter_2 = 0U;
          HighLevelStatemachine_DW.durationCounter_1_n = 0U;
        } else {
          if ((int32_T)HighLevelStatemachine_U.ProtectionOutput.ErrorDetect != 1)
          {
            HighLevelStatemachine_DW.durationCounter_1_j = 0U;
          }

          if ((real_T)(uint32_T)((int32_T)
                                 HighLevelStatemachine_DW.durationCounter_1_j *
                                 100) >
              HighLevelStatemachine_U.Thresholds.FaultsModeTimeout_msec) {
            HighLevelStatemachine_DW.is_HighLevelStatemachine =
              HighLevelStatemac_IN_Fault_Mode;
            HighLevelStatemachine_DW.durationCounter_2_bc = 0U;
            HighLevelStatemachine_DW.durationCounter_1_k = 0U;
            HighLevelStatemachine_DW.is_Fault_Mode =
              HighLevelStatemac_IN_Protection;

            /* Outport: '<Root>/HighLevelStateMode' */
            HighLevelStatemachine_Y.HighLevelStateMode = ProtectionFault;
            HighLevelStatemachine_DW.durationCounter_2 = 0U;
            HighLevelStatemachine_DW.durationCounter_1_n = 0U;
          }
        }
      }
    }
    break;

   case HighLevelStatem_IN_FastCharging:
    HighLevelStatemach_FastCharging();
    break;

   case HighLevelStatemachine_IN_Idle:
    /* Inport: '<Root>/DataPipeline' */
    if (HighLevelStatemachine_U.DataPipeline.isChargeEn != 0) {
      HighLevelStatemachine_DW.durationCounter_3 = 0U;
    }

    /* Inport: '<Root>/Thresholds' incorporates:
     *  Inport: '<Root>/DataPipeline'
     */
    if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_3 *
         100) > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
      HighLevelStatemachine_DW.durationCounter_4 = 0U;
      HighLevelStatemachine_DW.durationCounter_3_a = 0U;
      HighLevelStatemachine_DW.durationCounter_2_l = 0U;
      HighLevelStatemachine_DW.durationCounter_1_j = 0U;
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelStatema_IN_Discharging;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = Discharging;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      if (HighLevelStatemachine_U.DataPipeline.isChargeEn != 1) {
        HighLevelStatemachine_DW.durationCounter_4_o = 0U;
      }

      /* Outport: '<Root>/HighLevelStateMode' */
      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_4_o * HighLevelStatemachine_U.looptimeStateMachine)
          > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
        HighLevelStatemachine_DW.durationCounter_4_e = 0U;
        HighLevelStatemachine_DW.durationCounter_3_g = 0U;
        HighLevelStatemachine_DW.durationCounter_2_h = 0U;
        HighLevelStatemachine_DW.durationCounter_1_h = 0U;
        HighLevelStatemachine_DW.is_HighLevelStatemachine =
          HighLevelStatem_IN_SlowCharging;

        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = ChargingSlow;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      } else {
        if (HighLevelStatemachine_Y.HighLevelStateMode != Idle) {
          HighLevelStatemachine_DW.durationCounter_2 = 0U;
        }

        /* Inport: '<Root>/DataPipeline' */
        if ((real_T)(uint32_T)((int32_T)
                               HighLevelStatemachine_DW.durationCounter_2 * HighLevelStatemachine_U.looptimeStateMachine)
            > HighLevelStatemachine_U.Thresholds.PowerSaverModeTimeout_msec) {
          HighLevelStatemachine_DW.durationCounter_1_n = 0U;
          HighLevelStatemachine_DW.is_HighLevelStatemachine =
            HighLevelStatem_IN_LowPowerMode;

          /* Outport: '<Root>/HighLevelStateMode' */
          HighLevelStatemachine_Y.HighLevelStateMode = LowPowerMode;
          HighLevelStatemachine_DW.durationCounter_2 = 0U;
        } else {
          if (!HighLevelStatemachine_U.DataPipeline.VCU.ServiceMode) {
            HighLevelStatemachine_DW.durationCounter_1 = 0U;
          }

          if ((real_T)(uint32_T)((int32_T)
                                 HighLevelStatemachine_DW.durationCounter_1 *
                                 100) >
              HighLevelStatemachine_U.Thresholds.ServiceModeTimeout_msec) {
            HighLevelStatemachine_DW.is_HighLevelStatemachine =
              HighLevelStatema_IN_ServiceMode;

            /* Outport: '<Root>/HighLevelStateMode' */
            HighLevelStatemachine_Y.HighLevelStateMode = ServiceMode;
            HighLevelStatemachine_DW.durationCounter_2 = 0U;
            HighLevelStatemachine_DW.durationCounter_1_n = 0U;
          }
        }
      }
    }
    break;

   case HighLevelStatem_IN_Regeneration:
    /* Inport: '<Root>/DataPipeline' */
    if (HighLevelStatemachine_U.DataPipeline.isChargeEn != 0) {
      HighLevelStatemachine_DW.durationCounter_2_g = 0U;
    }

    /* Inport: '<Root>/Thresholds' incorporates:
     *  Inport: '<Root>/ProtectionOutput'
     */
    if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_2_g
         * 100) > HighLevelStatemachine_U.Thresholds.NormalModeTimeout_msec) {
      HighLevelStatemachine_DW.durationCounter_4 = 0U;
      HighLevelStatemachine_DW.durationCounter_3_a = 0U;
      HighLevelStatemachine_DW.durationCounter_2_l = 0U;
      HighLevelStatemachine_DW.durationCounter_1_j = 0U;
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelStatema_IN_Discharging;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = Discharging;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    } else {
      if ((int32_T)HighLevelStatemachine_U.ProtectionOutput.ErrorDetect != 1) {
        HighLevelStatemachine_DW.durationCounter_1_a = 0U;
      }

      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_1_a * HighLevelStatemachine_U.looptimeStateMachine)
          > HighLevelStatemachine_U.Thresholds.FaultsModeTimeout_msec) {
        HighLevelStatemachine_DW.is_HighLevelStatemachine =
          HighLevelStatemac_IN_Fault_Mode;
        HighLevelStatemachine_DW.durationCounter_2_bc = 0U;
        HighLevelStatemachine_DW.durationCounter_1_k = 0U;
        HighLevelStatemachine_DW.is_Fault_Mode = HighLevelStatemac_IN_Protection;

        /* Outport: '<Root>/HighLevelStateMode' */
        HighLevelStatemachine_Y.HighLevelStateMode = ProtectionFault;
        HighLevelStatemachine_DW.durationCounter_2 = 0U;
        HighLevelStatemachine_DW.durationCounter_1_n = 0U;
      }
    }
    break;

   case HighLevelStatem_IN_SlowCharging:
    HighLevelStatemach_SlowCharging();
    break;

   case HighLevelState_IN_DeepSleepMode:
    /* Inport: '<Root>/DataPipeline' */
    if (!HighLevelStatemachine_U.DataPipeline.VCU.ServiceMode) {
      HighLevelStatemachine_DW.durationCounter_1_i = 0U;
    }

    /* Inport: '<Root>/Thresholds' */
    if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_1_i
         * 100) > HighLevelStatemachine_U.Thresholds.ServiceModeTimeout_msec) {
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelStatema_IN_ServiceMode;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = ServiceMode;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    }
    break;

   case HighLevelStatem_IN_LowPowerMode:
    /* Outport: '<Root>/HighLevelStateMode' */
    if (HighLevelStatemachine_Y.HighLevelStateMode != LowPowerMode) {
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    }

    /* Inport: '<Root>/Thresholds' */
    if ((real_T)(uint32_T)((int32_T)HighLevelStatemachine_DW.durationCounter_1_n
         * 100) > HighLevelStatemachine_U.Thresholds.PowerSaverModeTimeout_msec)
    {
      HighLevelStatemachine_DW.durationCounter_1_i = 0U;
      HighLevelStatemachine_DW.is_HighLevelStatemachine =
        HighLevelState_IN_DeepSleepMode;

      /* Outport: '<Root>/HighLevelStateMode' */
      HighLevelStatemachine_Y.HighLevelStateMode = DeepSleepMode;
      HighLevelStatemachine_DW.durationCounter_2 = 0U;
      HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    }
    break;

   default:
    /* case IN_ServiceMode: */
    break;
  }
}

/* Function for Chart: '<S1>/HighLevelStatemachine' */
static void HighLevelStatemachine_BMS_State(void)
{
  switch (HighLevelStatemachine_DW.is_BMS_State) {
   case HighLevelStatemac_IN_Activating:
    /* SystemInitialize for Outport: '<Root>/BMS_State' */
    HighLevelStatemachine_Y.BMS_State = MARVEL_ACTIVATING;

    /* Inport: '<Root>/ContactorsState' incorporates:
     *  Inport: '<Root>/ContactorCommand'
     */
    if ((int32_T)HighLevelStatemachine_U.ContactorsState == 5) {
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Active;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_ACTIVE;
    } else {
      if ((HighLevelStatemachine_U.ContactorCommand != 1) || (((int32_T)
            HighLevelStatemachine_U.ContactorsState != 0) && ((int32_T)
            HighLevelStatemachine_U.ContactorsState != 8))) {
        HighLevelStatemachine_DW.durationCounter_1_m = 0U;
      }

      /* Inport: '<Root>/Thresholds' incorporates:
       *  Inport: '<Root>/ContactorCommand'
       */
      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_1_m * HighLevelStatemachine_U.looptimeStateMachine)
          >
          HighLevelStatemachine_U.Thresholds.BMS_ActivatingToError_Timeout_msec)
      {
        HighLevelStatemachine_DW.durationCounter_1_p = 0U;
        HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Error;

        /* SystemInitialize for Outport: '<Root>/BMS_State' */
        HighLevelStatemachine_Y.BMS_State = MARVEL_ERROR;
      } else if ((HighLevelStatemachine_U.ContactorCommand == 0) && ((int32_T)
                  HighLevelStatemachine_U.ContactorsState == 0)) {
        HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Ready;

        /* SystemInitialize for Outport: '<Root>/BMS_State' */
        HighLevelStatemachine_Y.BMS_State = MARVEL_READY;
      }
    }
    break;

   case HighLevelStatemachine_IN_Active:
    /* SystemInitialize for Outport: '<Root>/BMS_State' */
    HighLevelStatemachine_Y.BMS_State = MARVEL_ACTIVE;

    /* Inport: '<Root>/ContactorCommand' incorporates:
     *  Inport: '<Root>/ContactorsState'
     */
    if ((HighLevelStatemachine_U.ContactorCommand == 1) && (((int32_T)
          HighLevelStatemachine_U.ContactorsState == 0) || ((int32_T)
          HighLevelStatemachine_U.ContactorsState == 8))) {
      HighLevelStatemachine_DW.durationCounter_1_p = 0U;
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Error;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_ERROR;
    } else if ((HighLevelStatemachine_U.ContactorCommand == 0) && ((int32_T)
                HighLevelStatemachine_U.ContactorsState != 5)) {
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Ready;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_READY;
    } else if (((int32_T)HighLevelStatemachine_U.ContactorsState < 6) &&
               (HighLevelStatemachine_U.ContactorCommand == 1) && ((int32_T)
                HighLevelStatemachine_U.ContactorsState != 5)) {
      HighLevelStatemachine_DW.durationCounter_1_m = 0U;
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemac_IN_Activating;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_ACTIVATING;
    }
    break;

   case HighLevelStatemachine_IN_Error:
    /* SystemInitialize for Outport: '<Root>/BMS_State' */
    HighLevelStatemachine_Y.BMS_State = MARVEL_ERROR;

    /* Inport: '<Root>/ProtectionOutput' incorporates:
     *  Inport: '<Root>/ContactorCommand'
     *  Inport: '<Root>/ContactorsState'
     */
    if ((HighLevelStatemachine_U.ProtectionOutput.ErrorDetect == NoError) &&
        ((int32_T)HighLevelStatemachine_U.ContactorsState == 0) &&
        (HighLevelStatemachine_U.ContactorCommand == 0)) {
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Ready;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_READY;
    } else {
      if ((HighLevelStatemachine_U.ContactorCommand != 1) || ((int32_T)
           HighLevelStatemachine_U.ContactorsState <= 0) || ((int32_T)
           HighLevelStatemachine_U.ContactorsState > 6)) {
        HighLevelStatemachine_DW.durationCounter_1_p = 0U;
      }

      /* Inport: '<Root>/Thresholds' */
      if ((real_T)(uint32_T)((int32_T)
                             HighLevelStatemachine_DW.durationCounter_1_p * HighLevelStatemachine_U.looptimeStateMachine)
          >
          HighLevelStatemachine_U.Thresholds.BMS_ErrorToActivating_Timeout_msec)
      {
        HighLevelStatemachine_DW.durationCounter_1_m = 0U;
        HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemac_IN_Activating;

        /* SystemInitialize for Outport: '<Root>/BMS_State' */
        HighLevelStatemachine_Y.BMS_State = MARVEL_ACTIVATING;
      }
    }
    break;

   case HighLevelStatemachine_IN_Idle:
    /* Inport: '<Root>/ContactorCommand' */
    if (HighLevelStatemachine_U.ContactorCommand == 0) {
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Ready;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_READY;
    } else if (HighLevelStatemachine_U.ContactorCommand == 1) {
      HighLevelStatemachine_DW.durationCounter_1_m = 0U;
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemac_IN_Activating;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_ACTIVATING;
    }
    break;

   default:
    /* SystemInitialize for Outport: '<Root>/BMS_State' */
    /* case IN_Ready: */
    HighLevelStatemachine_Y.BMS_State = MARVEL_READY;

    /* Inport: '<Root>/ContactorsState' incorporates:
     *  Inport: '<Root>/ContactorCommand'
     *  Inport: '<Root>/ProtectionOutput'
     */
    if (((int32_T)HighLevelStatemachine_U.ContactorsState > 0) &&
        (HighLevelStatemachine_U.ContactorCommand == 1)) {
      HighLevelStatemachine_DW.durationCounter_1_m = 0U;
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemac_IN_Activating;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_ACTIVATING;
    } else if ((HighLevelStatemachine_U.ProtectionOutput.ErrorDetect == Error) ||
               ((int32_T)HighLevelStatemachine_U.ContactorsState > 6)) {
      HighLevelStatemachine_DW.durationCounter_1_p = 0U;
      HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Error;

      /* SystemInitialize for Outport: '<Root>/BMS_State' */
      HighLevelStatemachine_Y.BMS_State = MARVEL_ERROR;
    }
    break;
  }
}

/* Model step function */
void HighLevelStatemachine_step(void)
{
  /* Chart: '<S1>/HighLevelStatemachine' incorporates:
   *  Inport: '<Root>/ContactorCommand'
   *  Inport: '<Root>/ContactorsState'
   *  Inport: '<Root>/DataPipeline'
   *  Inport: '<Root>/ProtectionOutput'
   *  Inport: '<Root>/Thresholds'
   *  Outport: '<Root>/HighLevelStateMode'
   */
  if (HighLevelStatemachine_DW.is_active_c8_HighLevelStatemach == 0U) {
    HighLevelStatemachine_DW.is_active_c8_HighLevelStatemach = 1U;
    HighLevelStatemachine_DW.durationCounter_4_o = 0U;
    HighLevelStatemachine_DW.durationCounter_3 = 0U;
    HighLevelStatemachine_DW.durationCounter_2 = 0U;
    HighLevelStatemachine_DW.durationCounter_1 = 0U;
    HighLevelStatemachine_DW.is_HighLevelStatemachine =
      HighLevelStatemachine_IN_Idle;
    HighLevelStatemachine_Y.HighLevelStateMode = Idle;
    HighLevelStatemachine_DW.durationCounter_1_n = 0U;
    HighLevelStatemachine_DW.is_BMS_State = HighLevelStatemachine_IN_Idle;
  } else {
    HighLevel_HighLevelStatemachine();
    HighLevelStatemachine_BMS_State();
  }

  if (HighLevelStatemachine_U.DataPipeline.VCU.ServiceMode) {
    HighLevelStatemachine_DW.durationCounter_1++;
  } else {
    HighLevelStatemachine_DW.durationCounter_1 = 0U;
  }

  if ((int32_T)HighLevelStatemachine_U.ProtectionOutput.ErrorDetect == 1) {
    HighLevelStatemachine_DW.durationCounter_1_j++;
    HighLevelStatemachine_DW.durationCounter_1_d++;
    HighLevelStatemachine_DW.durationCounter_1_h++;
    HighLevelStatemachine_DW.durationCounter_1_a++;
  } else {
    HighLevelStatemachine_DW.durationCounter_1_j = 0U;
    HighLevelStatemachine_DW.durationCounter_1_d = 0U;
    HighLevelStatemachine_DW.durationCounter_1_h = 0U;
    HighLevelStatemachine_DW.durationCounter_1_a = 0U;
  }

  if (HighLevelStatemachine_Y.HighLevelStateMode == Idle) {
    HighLevelStatemachine_DW.durationCounter_2++;
  } else {
    HighLevelStatemachine_DW.durationCounter_2 = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.VCU.ServiceMode) {
    HighLevelStatemachine_DW.durationCounter_1_jt++;
    HighLevelStatemachine_DW.durationCounter_1_i++;
    HighLevelStatemachine_DW.durationCounter_1_k++;
    HighLevelStatemachine_DW.durationCounter_1_dz++;
  } else {
    HighLevelStatemachine_DW.durationCounter_1_jt = 0U;
    HighLevelStatemachine_DW.durationCounter_1_i = 0U;
    HighLevelStatemachine_DW.durationCounter_1_k = 0U;
    HighLevelStatemachine_DW.durationCounter_1_dz = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.isChargeEn == 0) {
    HighLevelStatemachine_DW.durationCounter_3++;
  } else {
    HighLevelStatemachine_DW.durationCounter_3 = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.Current_mA <
      HighLevelStatemachine_U.Thresholds.ChargeDetectionThreshold_mA) {
    HighLevelStatemachine_DW.durationCounter_2_l++;
  } else {
    HighLevelStatemachine_DW.durationCounter_2_l = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.isChargeEn == 0) {
    HighLevelStatemachine_DW.durationCounter_2_b++;
  } else {
    HighLevelStatemachine_DW.durationCounter_2_b = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.Current_mA <
      HighLevelStatemachine_U.Thresholds.ChargeDetectionThreshold_mA) {
    HighLevelStatemachine_DW.durationCounter_3_e++;
  } else {
    HighLevelStatemachine_DW.durationCounter_3_e = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.isChargeEn == 1) {
    HighLevelStatemachine_DW.durationCounter_3_a++;
  } else {
    HighLevelStatemachine_DW.durationCounter_3_a = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.isChargeEn == 0) {
    HighLevelStatemachine_DW.durationCounter_2_h++;
  } else {
    HighLevelStatemachine_DW.durationCounter_2_h = 0U;
  }

  if ((!HighLevelStatemachine_U.DataPipeline.VCU.isChargerConnected) &&
      (HighLevelStatemachine_U.DataPipeline.isChargeEn == 1)) {
    HighLevelStatemachine_DW.durationCounter_4++;
  } else {
    HighLevelStatemachine_DW.durationCounter_4 = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.isChargeEn == 0) {
    HighLevelStatemachine_DW.durationCounter_2_g++;
  } else {
    HighLevelStatemachine_DW.durationCounter_2_g = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.isChargeEn == 1) {
    HighLevelStatemachine_DW.durationCounter_4_o++;
  } else {
    HighLevelStatemachine_DW.durationCounter_4_o = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.Current_mA <
      HighLevelStatemachine_U.Thresholds.ChargeDetectionThreshold_mA) {
    HighLevelStatemachine_DW.durationCounter_3_g++;
  } else {
    HighLevelStatemachine_DW.durationCounter_3_g = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.VCU.FastCharge) {
    HighLevelStatemachine_DW.durationCounter_4_e++;
  } else {
    HighLevelStatemachine_DW.durationCounter_4_e = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.VCU.SlowCharge) {
    HighLevelStatemachine_DW.durationCounter_4_k++;
  } else {
    HighLevelStatemachine_DW.durationCounter_4_k = 0U;
  }

  if (HighLevelStatemachine_Y.HighLevelStateMode == LowPowerMode) {
    HighLevelStatemachine_DW.durationCounter_1_n++;
  } else {
    HighLevelStatemachine_DW.durationCounter_1_n = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.VCU.VCUPermanentFail) {
    HighLevelStatemachine_DW.durationCounter_2_lq++;
  } else {
    HighLevelStatemachine_DW.durationCounter_2_lq = 0U;
  }

  if (HighLevelStatemachine_U.DataPipeline.VCU.TransmissionFail) {
    HighLevelStatemachine_DW.durationCounter_2_bc++;
  } else {
    HighLevelStatemachine_DW.durationCounter_2_bc = 0U;
  }

  if ((HighLevelStatemachine_U.ContactorCommand == 1) && (((int32_T)
        HighLevelStatemachine_U.ContactorsState == 0) || ((int32_T)
        HighLevelStatemachine_U.ContactorsState == 8))) {
    HighLevelStatemachine_DW.durationCounter_1_m++;
  } else {
    HighLevelStatemachine_DW.durationCounter_1_m = 0U;
  }

  if ((HighLevelStatemachine_U.ContactorCommand == 1) && ((int32_T)
       HighLevelStatemachine_U.ContactorsState > 0) && ((int32_T)
       HighLevelStatemachine_U.ContactorsState <= 6)) {
    HighLevelStatemachine_DW.durationCounter_1_p++;
  } else {
    HighLevelStatemachine_DW.durationCounter_1_p = 0U;
  }

  /* End of Chart: '<S1>/HighLevelStatemachine' */
}

/* Model initialize function */
void HighLevelStatemachine_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(HighLevelStatemachine_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&HighLevelStatemachine_DW, 0,
                sizeof(DW_HighLevelStatemachine_T));

  /* external inputs */
  (void)memset(&HighLevelStatemachine_U, 0, sizeof(ExtU_HighLevelStatemachine_T));
  HighLevelStatemachine_U.ContactorsState = OpenSubstate;
  HighLevelStatemachine_U.ProtectionOutput = HighLevelStatemachine_rtZProtec;

  /* external outputs */
  HighLevelStatemachine_Y.HighLevelStateMode = Idle;
  HighLevelStatemachine_Y.BMS_State = MARVEL_READY;

  /* SystemInitialize for Chart: '<S1>/HighLevelStatemachine' */
  HighLevelStatemachine_DW.is_BMS_State = HighLevelSta_IN_NO_ACTIVE_CHILD;
  HighLevelStatemachine_DW.is_HighLevelStatemachine =
    HighLevelSta_IN_NO_ACTIVE_CHILD;
  HighLevelStatemachine_DW.is_Fault_Mode = HighLevelSta_IN_NO_ACTIVE_CHILD;
  HighLevelStatemachine_DW.is_active_c8_HighLevelStatemach = 0U;

  /* SystemInitialize for Outport: '<Root>/HighLevelStateMode' incorporates:
   *  Chart: '<S1>/HighLevelStatemachine'
   */
  HighLevelStatemachine_Y.HighLevelStateMode = Idle;

  /* SystemInitialize for Outport: '<Root>/BMS_State' incorporates:
   *  Chart: '<S1>/HighLevelStatemachine'
   */
  HighLevelStatemachine_Y.BMS_State = MARVEL_READY;
}

/* Model terminate function */
void HighLevelStatemachine_terminate(void)
{
  /* (no terminate code required) */
}
