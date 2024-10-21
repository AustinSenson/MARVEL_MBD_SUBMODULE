/*
 * CellBalancing.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CellBalancing".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:48:53 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_CellBalancing_h_
#define RTW_HEADER_CellBalancing_h_
#ifndef CellBalancing_COMMON_INCLUDES_
#define CellBalancing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* CellBalancing_COMMON_INCLUDES_ */

#include "CellBalancing_types.h"
#include "WriteMosfetsData.h"
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
  real_T BalancingTimeOn_msec;         /* '<S3>/Chart' */
  int32_T Balancing_OVThr_mV;          /* '<S3>/Chart2' */
  boolean_T BalanceEn;                 /* '<S3>/Switch' */
  B_WriteMosfetsData_CellBalanc_T sf_WriteMosfetsData;/* '<S1>/WriteMosfetsData' */
} B_CellBalancing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T x;                            /* '<S3>/Chart' */
  real_T i;                            /* '<S1>/BalancingStateMachine' */
  uint32_T durationCounter_1;          /* '<S3>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S1>/BalancingStateMachine' */
  uint32_T durationCounter_1_c;        /* '<S1>/BalancingStateMachine' */
  uint32_T durationCounter_1_k;        /* '<S1>/BalancingStateMachine' */
  uint32_T durationCounter_1_h;        /* '<S1>/BalancingStateMachine' */
  uint32_T durationCounter_1_n;        /* '<S1>/BalancingStateMachine' */
  uint8_T is_c4_CellBalancing;         /* '<S3>/Chart2' */
  uint8_T is_active_c4_CellBalancing;  /* '<S3>/Chart2' */
  uint8_T is_c26_CellBalancing;        /* '<S3>/Chart1' */
  uint8_T is_active_c26_CellBalancing; /* '<S3>/Chart1' */
  uint8_T is_c6_CellBalancing;         /* '<S3>/Chart' */
  uint8_T is_active_c6_CellBalancing;  /* '<S3>/Chart' */
  uint8_T is_c3_CellBalancing;         /* '<S1>/BalancingStateMachine' */
  uint8_T is_active_c3_CellBalancing;  /* '<S1>/BalancingStateMachine' */
} DW_CellBalancing_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  int32_T NumberOfMosfets;             /* '<Root>/NumberOfMosfets' */
  int32_T BalancingTempGroup;          /* '<Root>/BalancingTempGroup' */
  real32_T maxAllowedImbalance;        /* '<Root>/maxAllowedImbalance' */
  int32_T StLineEq_varA;               /* '<Root>/StLineEq_varA' */
  int32_T StLineEq_varB;               /* '<Root>/StLineEq_varB' */
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
  DataPipelineBus DataPipeline;        /* '<Root>/DataPipeline' */
} ExtU_CellBalancing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int8_T BalanceCmd[18];               /* '<Root>/BalanceCmd' */
  int8_T fetStates[18];                /* '<Root>/fetStates' */
  CellBalancingOutputBus CellBalancingOutput;/* '<Root>/CellBalancingOutput' */
} ExtY_CellBalancing_T;

/* Real-time Model Data Structure */
struct tag_RTM_CellBalancing_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_CellBalancing_T CellBalancing_B;

/* Block states (default storage) */
extern DW_CellBalancing_T CellBalancing_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CellBalancing_T CellBalancing_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_CellBalancing_T CellBalancing_Y;

/* External data declarations for dependent source files */
extern const CellBalancingOutputBus CellBalancing_rtZCellBalancingO;/* CellBalancingOutputBus ground */

/* Model entry point functions */
extern void CellBalancing_initialize(void);
extern void CellBalancing_step(void);
extern void CellBalancing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CellBalancing_T *const CellBalancing_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
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
 * hilite_system('marvelMBD_v00_0A_0D_exported/CellBalancing')    - opens subsystem marvelMBD_v00_0A_0D_exported/CellBalancing
 * hilite_system('marvelMBD_v00_0A_0D_exported/CellBalancing/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'marvelMBD_v00_0A_0D_exported'
 * '<S1>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing'
 * '<S2>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing/BalancingStateMachine'
 * '<S3>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing/InputProcessing'
 * '<S4>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing/WriteMosfetsData'
 * '<S5>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing/InputProcessing/Chart'
 * '<S6>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing/InputProcessing/Chart1'
 * '<S7>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing/InputProcessing/Chart2'
 * '<S8>'   : 'marvelMBD_v00_0A_0D_exported/CellBalancing/InputProcessing/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_CellBalancing_h_ */
