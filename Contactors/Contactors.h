/*
 * Contactors.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Contactors".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:50:06 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_Contactors_h_
#define RTW_HEADER_Contactors_h_
#ifndef Contactors_COMMON_INCLUDES_
#define Contactors_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Contactors_COMMON_INCLUDES_ */

#include "Contactors_types.h"
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
  real_T PreIntegratedTime;            /* '<S1>/Discrete-Time Integrator' */
  real_T PreTimeReset;                 /* '<S1>/Contactor_StateMachine' */
  int32_T Add;                         /* '<S1>/Add' */
  boolean_T Flags_Detection;           /* '<S1>/AND' */
} B_Contactors_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  uint32_T durationCounter_1;          /* '<S1>/Contactor_StateMachine' */
  uint32_T durationCounter_1_f;        /* '<S1>/Contactor_StateMachine' */
  uint32_T durationCounter_1_b;        /* '<S1>/Contactor_StateMachine' */
  ContactorsFlags Memory_PreviousInput;/* '<S1>/Memory' */
  ContactorsFlags Memory1_PreviousInput;/* '<S1>/Memory1' */
  ContactorsFlags Memory2_PreviousInput;/* '<S1>/Memory2' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S1>/Discrete-Time Integrator' */
  uint8_T is_ContactorOperations;      /* '<S1>/Contactor_StateMachine' */
  uint8_T is_PreCharging_Substate_Old; /* '<S1>/Contactor_StateMachine' */
  uint8_T is_PreCharging_Substate_New; /* '<S1>/Contactor_StateMachine' */
  uint8_T PreChargeRetryCheck;         /* '<S1>/Contactor_StateMachine' */
  uint8_T is_active_c1_Contactors;     /* '<S1>/Contactor_StateMachine' */
} DW_Contactors_T;

/* Invariant block signals (default storage) */
typedef struct {
  const ProtectionFlags DataTypeConversion9;/* '<S1>/Data Type Conversion9' */
} ConstB_Contactors_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T PreCharge_LoopTime_msec;      /* '<Root>/PreCharge_LoopTime_msec' */
  BMSState BMS_State;                  /* '<Root>/BMS_State' */
  boolean_T PermanentFailRecoveryTrigger;
                                     /* '<Root>/PermanentFailRecoveryTrigger' */
  int32_T TerminalVoltage_mV;          /* '<Root>/TerminalVoltage_mV' */
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
  ProtectionState_Out ProtectionOutput;/* '<Root>/ProtectionOutput' */
  DataPipelineBus DataPipeline;        /* '<Root>/DataPipeline' */
  uint8_T Communication_Flag;          /* '<Root>/Communication_Flag' */
  uint8_T ContactorCommand;            /* '<Root>/ContactorCommand' */
  uint8_T SC_Flag;                     /* '<Root>/SC_Flag' */
  ProtectionFlags PermanentFail_Flag;  /* '<Root>/PermanentFail_FB' */
  uint8_T ContactorError_Flag;         /* '<Root>/ContactorError_Flag' */
  ContactorsFlags PosContactors_FB;    /* '<Root>/PosContactors_FB' */
  ContactorsFlags PreChargeContactors_FB;/* '<Root>/PreChargeContactors_FB' */
  ContactorsFlags NegContactors_FB;    /* '<Root>/NegContactors_FB' */
  real_T looptimeContactors; /* Added variable */
} ExtU_Contactors_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  ContactorsFlags NegContactors;       /* '<Root>/NegContactors' */
  ContactorsFlags PreChargeContactors; /* '<Root>/PreChargeContactors' */
  ContactorsFlags PosContactors;       /* '<Root>/PosContactors' */
  ContactorsFlags ContactorsWeldWarning;/* '<Root>/ContactorsWeldWarning' */
  ProtectionFlags PermanentFaiil;      /* '<Root>/PermanentFaiil' */
  ContState ContactorsState;           /* '<Root>/ContactorsState' */
} ExtY_Contactors_T;

/* Real-time Model Data Structure */
struct tag_RTM_Contactors_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Contactors_T Contactors_B;

/* Block states (default storage) */
extern DW_Contactors_T Contactors_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Contactors_T Contactors_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Contactors_T Contactors_Y;

/* External data declarations for dependent source files */
extern const ProtectionState_Out Contactors_rtZProtectionState_O;/* ProtectionState_Out ground */
extern const ConstB_Contactors_T Contactors_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Contactors_initialize(void);
extern void Contactors_step(void);
extern void Contactors_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Contactors_T *const Contactors_M;

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
 * hilite_system('marvelMBD_v00_0A_0D_exported/Contactors')    - opens subsystem marvelMBD_v00_0A_0D_exported/Contactors
 * hilite_system('marvelMBD_v00_0A_0D_exported/Contactors/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'marvelMBD_v00_0A_0D_exported'
 * '<S1>'   : 'marvelMBD_v00_0A_0D_exported/Contactors'
 * '<S2>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant'
 * '<S3>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant1'
 * '<S4>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant10'
 * '<S5>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant11'
 * '<S6>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant12'
 * '<S7>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant13'
 * '<S8>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant14'
 * '<S9>'   : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant15'
 * '<S10>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant16'
 * '<S11>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant17'
 * '<S12>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant18'
 * '<S13>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant19'
 * '<S14>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant2'
 * '<S15>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant20'
 * '<S16>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant21'
 * '<S17>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant22'
 * '<S18>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant23'
 * '<S19>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant24'
 * '<S20>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant25'
 * '<S21>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant26'
 * '<S22>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant27'
 * '<S23>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant28'
 * '<S24>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant29'
 * '<S25>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant3'
 * '<S26>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant30'
 * '<S27>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant4'
 * '<S28>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant5'
 * '<S29>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant6'
 * '<S30>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant7'
 * '<S31>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant8'
 * '<S32>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Compare To Constant9'
 * '<S33>'  : 'marvelMBD_v00_0A_0D_exported/Contactors/Contactor_StateMachine'
 */
#endif                                 /* RTW_HEADER_Contactors_h_ */
