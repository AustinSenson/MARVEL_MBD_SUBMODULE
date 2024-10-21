/*
 * ChargingAlgorithm.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ChargingAlgorithm".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:54:16 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_ChargingAlgorithm_h_
#define RTW_HEADER_ChargingAlgorithm_h_
#ifndef ChargingAlgorithm_COMMON_INCLUDES_
#define ChargingAlgorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ChargingAlgorithm_COMMON_INCLUDES_ */

#include "ChargingAlgorithm_types.h"
#include "multiword_types.h"
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Constant_K;                   /* '<S1>/ChargingAlgorithmstep2' */
  boolean_T cvModeActivated;           /* '<S1>/ChargingAlgorithmstep2' */
  boolean_T trickleChargingEnabled;    /* '<S1>/ChargingAlgorithmstep2' */
  boolean_T IRComplete;                /* '<S1>/ChargingAlgorithmstep1' */
} B_ChargingAlgorithm_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T durationCounter_1;          /* '<S1>/ChargingAlgorithmstep2' */
  uint32_T durationCounter_1_n;        /* '<S1>/ChargingAlgorithmstep2' */
  uint32_T durationCounter_1_c;        /* '<S1>/ChargingAlgorithmstep2' */
  uint32_T durationCounter_1_i;        /* '<S1>/ChargingAlgorithmstep2' */
  uint32_T durationCounter_2;          /* '<S1>/ChargingAlgorithmstep2' */
  uint32_T durationCounter_1_l;        /* '<S1>/ChargingAlgorithmstep2' */
  uint32_T durationCounter_1_h;        /* '<S1>/ChargingAlgorithmstep2' */
  uint32_T durationCounter_2_p;        /* '<S1>/ChargingAlgorithmstep2' */
  uint8_T is_c32_ChargingAlgorithm;    /* '<S1>/ChargingAlgorithmstep2' */
  uint8_T is_TrickleCharging;          /* '<S1>/ChargingAlgorithmstep2' */
  uint8_T is_NormalCharging;           /* '<S1>/ChargingAlgorithmstep2' */
  uint8_T is_FastCharging;             /* '<S1>/ChargingAlgorithmstep2' */
  uint8_T is_SlowCharging;             /* '<S1>/ChargingAlgorithmstep2' */
  uint8_T is_active_c32_ChargingAlgorithm;/* '<S1>/ChargingAlgorithmstep2' */
  uint8_T is_c34_ChargingAlgorithm;    /* '<S1>/ChargingAlgorithmstep1' */
  uint8_T is_active_c34_ChargingAlgorithm;/* '<S1>/ChargingAlgorithmstep1' */
} DW_ChargingAlgorithm_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S1>/Saturation'
   */
  int64m_T Saturation_UpperSat;

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S1>/Saturation'
   */
  int64m_T Saturation_LowerSat;
} ConstP_ChargingAlgorithm_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  CC_OutputsBus CC_Outputs;            /* '<Root>/CC_Outputs' */
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
  real_T IR_calcEnable;                /* '<Root>/IR_calcEnable' */
  real_T maxAllowedImb_mv;             /* '<Root>/maxAllowedImb_mv' */
  DataPipelineBus DataPipeline;        /* '<Root>/DataPipeline' */
} ExtU_ChargingAlgorithm_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T RequestedCurrent_mA;          /* '<Root>/RequestedCurrent_mA' */
  ChargeState ChargingState;           /* '<Root>/ChargingState' */
} ExtY_ChargingAlgorithm_T;

/* Real-time Model Data Structure */
struct tag_RTM_ChargingAlgorithm_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_ChargingAlgorithm_T ChargingAlgorithm_B;

/* Block states (default storage) */
extern DW_ChargingAlgorithm_T ChargingAlgorithm_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ChargingAlgorithm_T ChargingAlgorithm_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ChargingAlgorithm_T ChargingAlgorithm_Y;

/* External data declarations for dependent source files */
extern const CC_OutputsBus ChargingAlgorithm_rtZCC_Outputs;/* CC_OutputsBus ground */

/* Constant parameters (default storage) */
extern const ConstP_ChargingAlgorithm_T ChargingAlgorithm_ConstP;

/* Model entry point functions */
extern void ChargingAlgorithm_initialize(void);
extern void ChargingAlgorithm_step(void);
extern void ChargingAlgorithm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ChargingAlgorithm_T *const ChargingAlgorithm_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S1>/Display3' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('marvelMBD_v00_0A_0D_exported/ChargingAlgorithm')    - opens subsystem marvelMBD_v00_0A_0D_exported/ChargingAlgorithm
 * hilite_system('marvelMBD_v00_0A_0D_exported/ChargingAlgorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'marvelMBD_v00_0A_0D_exported'
 * '<S1>'   : 'marvelMBD_v00_0A_0D_exported/ChargingAlgorithm'
 * '<S2>'   : 'marvelMBD_v00_0A_0D_exported/ChargingAlgorithm/ChargingAlgorithmstep1'
 * '<S3>'   : 'marvelMBD_v00_0A_0D_exported/ChargingAlgorithm/ChargingAlgorithmstep2'
 */
#endif                                 /* RTW_HEADER_ChargingAlgorithm_h_ */
