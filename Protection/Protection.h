/*
 * Protection.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Protection".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:51:48 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (8), Warnings (2), Error (0)
 */

#ifndef RTW_HEADER_Protection_h_
#define RTW_HEADER_Protection_h_
#ifndef Protection_COMMON_INCLUDES_
#define Protection_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Protection_COMMON_INCLUDES_ */

#include "Protection_types.h"
#include "rt_zcfcn.h"
#include <stddef.h>
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T IntegratedTime;               /* '<S1>/Discrete-Time Integrator' */
  real_T TimeReset;          /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  real32_T Add;                        /* '<S1>/Add' */
  real32_T Add1;                       /* '<S1>/Add1' */
  real32_T Now_Tmax;                   /* '<S4>/Now_Tmax' */
  real32_T Now_mV_min;                 /* '<S4>/Now_mV_min' */
  TempState TempState2;      /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  TempState TempState1;      /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags OCCFlag;   /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags OCDFlag;   /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags OVFlag;    /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags UVFlag;    /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags FlagGroup1;/* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags FlagGroup2;/* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags ThermalRunaway;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags TemperatureGradient;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags HighImbalanceFlag;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags ShortCircuitDetect;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags SuddenVoltageDrop;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags ErrorDetect;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags TempOverallState;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags eFuseDischargeFlag;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags eFuseChargeFlag;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags DCLI_CurrentFlag;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  ProtectionFlags DCLO_CurrentFlag;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
} B_Protection_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real32_T DCL_Current_A;    /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  int32_T OCC_Error_mA;      /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  int32_T OCC_Warning_mA;    /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  int32_T OCD_Error_mA;      /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  int32_T OCD_Warning_mA;    /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  int32_T Protections_OV_Recovery_mV;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  int32_T Protections_OV_Warning_mV;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  int32_T Protections_OV_Error_mV;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T temporalCounter_i1;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1;/* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_n;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_i;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_ik;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_o;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_b;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_or;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_iq;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2;/* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_o;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_m;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_d;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_b1;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_g;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_j;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_j;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_b;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_c;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_3;/* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_bu;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_c;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_h;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_my;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_e;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_k;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_ej;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_nw;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_gb;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_l;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_m;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_od;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_a;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_k;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_gc;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_an;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_ac;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_e;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_nb;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_f;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_nd;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_mf;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_fp;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_d;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_d5;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_da;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_kf;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_h;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_er;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_k5;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_3_k;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_fj;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_bi;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_4;/* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_fh;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_fs;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_f;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_kn;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_je;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_lr;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_d1;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_l;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_e5;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_dg;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_il;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_n3;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_p;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_gw;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_n;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_oe;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_e5;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_ox;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_ec;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_eh;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_3_g;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_pe;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_py;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_4_c;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_b0;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_aa;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_a;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_lb;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_i;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_jw;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_bg;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_2_mn;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint32_T durationCounter_1_e2;       /* '<S1>/Chart' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S1>/Discrete-Time Integrator' */
  uint8_T is_ThermalRunaway; /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_SuddenVoltageDrop;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_Current_Protection;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_Voltage_Protection;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_TemperatureGradient;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_OverallState;   /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_HighImbalanceFlag;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_ErrorDetect;    /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_ShortCircuitDetect;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_OVThresholds_Selection;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_DCL_CurrentProtection;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_Temperature_Protection_Group;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_Temperature_Protection_Gro_b;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T eFuseMeltCount;    /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_active_c2_Protection;
                             /* '<S1>/CurrentVoltageTemperature_Statemachine' */
  uint8_T is_c30_Protection;           /* '<S1>/Chart' */
  uint8_T m;                           /* '<S1>/Chart' */
  uint8_T is_active_c30_Protection;    /* '<S1>/Chart' */
  uint8_T temporalCounter_i1_g;        /* '<S1>/Chart' */
} DW_Protection_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
} PrevZCX_Protection_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
  DataPipelineBus DataPipeline;        /* '<Root>/DataPipeline' */
  real_T Protection_LoopTime_msec;     /* '<Root>/Protection_LoopTime_msec' */
  real_T looptimeProtection; /* Added variable */
} ExtU_Protection_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  ProtectionState_Out ProtectionState_Out_bus;/* '<Root>/ProtectionState_Out_bus' */
} ExtY_Protection_T;

/* Real-time Model Data Structure */
struct tag_RTM_Protection_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Protection_T Protection_B;

/* Block states (default storage) */
extern DW_Protection_T Protection_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Protection_T Protection_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_Protection_T Protection_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Protection_T Protection_Y;

/* External data declarations for dependent source files */
extern const ProtectionState_Out Protection_rtZProtectionState_O;/* ProtectionState_Out ground */

/* Model entry point functions */
extern void Protection_initialize(void);
extern void Protection_step(void);
extern void Protection_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Protection_T *const Protection_M;

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
 * hilite_system('marvelMBD_v00_0A_0D_exported/Protection')    - opens subsystem marvelMBD_v00_0A_0D_exported/Protection
 * hilite_system('marvelMBD_v00_0A_0D_exported/Protection/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'marvelMBD_v00_0A_0D_exported'
 * '<S1>'   : 'marvelMBD_v00_0A_0D_exported/Protection'
 * '<S2>'   : 'marvelMBD_v00_0A_0D_exported/Protection/Chart'
 * '<S3>'   : 'marvelMBD_v00_0A_0D_exported/Protection/CurrentVoltageTemperature_Statemachine'
 * '<S4>'   : 'marvelMBD_v00_0A_0D_exported/Protection/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_Protection_h_ */
