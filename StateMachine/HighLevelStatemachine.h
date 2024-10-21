/*
 * HighLevelStatemachine.h
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

#ifndef RTW_HEADER_HighLevelStatemachine_h_
#define RTW_HEADER_HighLevelStatemachine_h_
#ifndef HighLevelStatemachine_COMMON_INCLUDES_
#define HighLevelStatemachine_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                              /* HighLevelStatemachine_COMMON_INCLUDES_ */

#include "HighLevelStatemachine_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T durationCounter_1;          /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_j;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_2;          /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_d;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_h;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_a;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_jt;       /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_i;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_k;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_dz;       /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_3;          /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_2_l;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_2_b;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_3_e;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_3_a;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_2_h;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_4;          /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_2_g;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_4_o;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_3_g;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_4_e;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_4_k;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_n;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_2_lq;       /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_2_bc;       /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_m;        /* '<S1>/HighLevelStatemachine' */
  uint32_T durationCounter_1_p;        /* '<S1>/HighLevelStatemachine' */
  uint8_T is_HighLevelStatemachine;    /* '<S1>/HighLevelStatemachine' */
  uint8_T is_Fault_Mode;               /* '<S1>/HighLevelStatemachine' */
  uint8_T is_BMS_State;                /* '<S1>/HighLevelStatemachine' */
  uint8_T is_active_c8_HighLevelStatemach;/* '<S1>/HighLevelStatemachine' */
} DW_HighLevelStatemachine_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  DataPipelineBus DataPipeline;        /* '<Root>/DataPipeline' */
  uint8_T ContactorCommand;            /* '<Root>/ContactorCommand' */
  ContState ContactorsState;           /* '<Root>/ContactorsState' */
  ProtectionState_Out ProtectionOutput;/* '<Root>/ProtectionOutput' */
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
} ExtU_HighLevelStatemachine_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  HighLevelMode HighLevelStateMode;    /* '<Root>/HighLevelStateMode' */
  BMSState BMS_State;                  /* '<Root>/BMS_State' */
} ExtY_HighLevelStatemachine_T;

/* Real-time Model Data Structure */
struct tag_RTM_HighLevelStatemachine_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_HighLevelStatemachine_T HighLevelStatemachine_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_HighLevelStatemachine_T HighLevelStatemachine_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_HighLevelStatemachine_T HighLevelStatemachine_Y;

/* External data declarations for dependent source files */
extern const ProtectionState_Out HighLevelStatemachine_rtZProtec;/* ProtectionState_Out ground */

/* Model entry point functions */
extern void HighLevelStatemachine_initialize(void);
extern void HighLevelStatemachine_step(void);
extern void HighLevelStatemachine_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HighLevelStatemachin_T *const HighLevelStatemachine_M;

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
 * hilite_system('marvelMBD_v00_0A_0D_exported/HighLevelStatemachine')    - opens subsystem marvelMBD_v00_0A_0D_exported/HighLevelStatemachine
 * hilite_system('marvelMBD_v00_0A_0D_exported/HighLevelStatemachine/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'marvelMBD_v00_0A_0D_exported'
 * '<S1>'   : 'marvelMBD_v00_0A_0D_exported/HighLevelStatemachine'
 * '<S2>'   : 'marvelMBD_v00_0A_0D_exported/HighLevelStatemachine/HighLevelStatemachine'
 */
#endif                                 /* RTW_HEADER_HighLevelStatemachine_h_ */
