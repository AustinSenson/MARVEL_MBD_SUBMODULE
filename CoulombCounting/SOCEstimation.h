/*
 * SOCEstimation.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SOCEstimation".
 *
 * Model version              : 4.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 23 20:32:49 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Debugging
 * Validation result: Passed (0), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_SOCEstimation_h_
#define RTW_HEADER_SOCEstimation_h_
#ifndef SOCEstimation_COMMON_INCLUDES_
#define SOCEstimation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* SOCEstimation_COMMON_INCLUDES_ */

#include "SOCEstimation_types.h"
#include "VoltagemV_Vs_CapacitymAh.h"
#include "UsableCapacity_mAh.h"
#include "SOC_WriteToFlash.h"
#include "SOC_ReadFromFlash.h"
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
  real_T SOC_ChargeDischarge;          /* '<S3>/Divide2' */
  real_T Switch1;                      /* '<S1>/Switch1' */
  real_T CalcEnable;                   /* '<S8>/SOH_Calibration' */
  uint32_T Initial_Guess_mAh;          /* '<S1>/Switch' */
  real32_T CC_InputsSensorAccuracy_pct100;
                                  /* '<S3>/CC_Inputs.SensorAccuracy_pct//100' */
  real32_T absCurrent_mA;              /* '<S3>/Add1' */
  real32_T DiscreteTimeIntegrator;     /* '<S7>/Discrete-Time Integrator' */
  real32_T Switch;                     /* '<S7>/Switch' */
  real32_T Gain2;                      /* '<S7>/Gain2' */
  real32_T CycleCount;                 /* '<S7>/Divide' */
  real32_T DataTypeConversion1;        /* '<S3>/Data Type Conversion1' */
  real32_T IntegratedCurrent;          /* '<S3>/Discrete-Time Integrator2' */
  real32_T Switch1_p;                  /* '<S3>/Switch1' */
  real32_T Multiply2;                  /* '<S3>/Multiply2' */
  real32_T SOC_cpct;                   /* '<S1>/Data Store Read1' */
  real32_T SOH;                        /* '<S7>/Divide1' */
  real32_T Subtract;                   /* '<S1>/Subtract' */
  real32_T Abs;                        /* '<S1>/Abs' */
  real32_T Gain1;                      /* '<S18>/Gain1' */
  real32_T CapacityExchange_mAh;       /* '<S18>/Gain2' */
  real32_T InitialCycleCount;          /* '<S18>/Divide' */
  real32_T InitialSOH;                 /* '<S18>/Divide1' */
  real32_T Gain3;                      /* '<S18>/Gain3' */
  real32_T Final_IntegratedCurrent;    /* '<S18>/Chart' */
  real32_T IntegratedCurrent_a;        /* '<S7>/Gain1' */
  real32_T IntegratedCurrent_h;        /* '<S7>/Chart' */
  real32_T IntegratedCurrent_g;        /* '<S3>/Gain2' */
  real32_T IntegratedCurrent_k;        /* '<S3>/Chart1' */
  int32_T MinCurrentLimit_mA;          /* '<S4>/Switch3' */
  int32_T absCurrent_mA_p;             /* '<S7>/Abs' */
  int32_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  int32_T Capacity_mAh;                /* '<S1>/Data Store Read' */
  int32_T MaxAllowedImb_mV;            /* '<S4>/Switch1' */
  int32_T MaxCurrentLimit_mA;          /* '<S4>/Switch2' */
  int32_T DataTypeConversion3;         /* '<S3>/Data Type Conversion3' */
  int32_T DataTypeConversion2;         /* '<S3>/Data Type Conversion2' */
  int32_T TotalSOCRemains_cpct;        /* '<S3>/Gain1' */
  int32_T SOH_cpct;                    /* '<S7>/Gain' */
  int32_T SOH_cpct_f;                  /* '<S1>/Saturation1' */
  int32_T TotalCapacityExchange_mAh;   /* '<S7>/Data Type Conversion' */
  int32_T SOC_cpct_h;                  /* '<S1>/Saturation' */
  int32_T absCurrent_mA_i;             /* '<S18>/Abs' */
  int32_T InitialSOH_cpct;             /* '<S18>/Gain' */
  int32_T Product;                     /* '<S18>/Product' */
  int32_T DataTypeConversion_f;        /* '<S18>/Data Type Conversion' */
  int32_T Initial_Capacity_mAh;        /* '<S4>/SOC_Calibration' */
  int32_T TotalCapacityRemains_mAh;    /* '<S3>/Chart' */
  int32_T Final_InstalledCapacity_mAh; /* '<S1>/Chart' */
  CCState CC_State;                    /* '<S4>/SOC_Calibration' */
  B_VoltagemV_Vs_CapacitymAh_T sf_Voltage_Vs_Capacity;/* '<S1>/Voltage_Vs_Capacity' */
  B_UsableCapacity_mAh_SOCEst_l_T sf_UsableCapacity_mAh_m;/* '<S18>/UsableCapacity_mAh' */
  B_UsableCapacity_mAh_SOCEstim_T sf_UsableCapacity_mAh;/* '<S7>/UsableCapacity_mAh' */
  B_SOC_WriteToFlash_SOCEstimat_T sf_SOC_WriteToFlash;/* '<S1>/SOC_WriteToFlash' */
  B_SOC_ReadFromFlash_SOCEstima_T sf_SOC_ReadFromFlash;/* '<S1>/SOC_ReadFromFlash' */
} B_SOCEstimation_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S3>/Discrete-Time Integrator2' */
  real32_T Add1_DWORK1;                /* '<S3>/Add1' */
  real32_T SOC_pct;                    /* '<S1>/Data Store Memory1' */
  real32_T IntegratedCurrent;          /* '<S18>/Chart' */
  int32_T CapacityRemains_mAh;         /* '<S1>/Data Store Memory' */
  int32_T TransitionCapacity_mAh;      /* '<S4>/SOC_Calibration' */
  uint32_T durationCounter_1;          /* '<S18>/Chart' */
  uint32_T durationCounter_1_i;        /* '<S18>/Chart' */
  uint32_T durationCounter_1_d;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_2;          /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_1_p;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_1_px;       /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_2_m;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_1_m;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_1_e;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_1_g;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_1_dq;       /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_2_m0;       /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_2_k;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_2_b;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_2_j;        /* '<S8>/SOH_Calibration' */
  uint32_T durationCounter_2_jc;       /* '<S8>/SOH_Calibration' */
  uint32_T temporalCounter_i1;         /* '<S4>/SOC_Calibration' */
  uint32_T durationCounter_1_l;        /* '<S4>/SOC_Calibration' */
  uint32_T durationCounter_1_mg;       /* '<S3>/Chart' */
  uint32_T durationCounter_1_n;        /* '<S3>/Chart' */
  uint32_T durationCounter_2_d;        /* '<S3>/Chart' */
  uint32_T durationCounter_1_k;        /* '<S1>/Chart' */
  int8_T DiscreteTimeIntegrator2_PrevRes;/* '<S3>/Discrete-Time Integrator2' */
  uint8_T is_c22_SOCEstimation;        /* '<S18>/Chart' */
  uint8_T is_active_c22_SOCEstimation; /* '<S18>/Chart' */
  uint8_T is_c21_SOCEstimation;        /* '<S8>/SOH_Calibration' */
  uint8_T is_active_c21_SOCEstimation; /* '<S8>/SOH_Calibration' */
  uint8_T is_active_c19_SOCEstimation; /* '<S7>/Chart' */
  uint8_T is_c15_SOCEstimation;        /* '<S4>/SOC_Calibration' */
  uint8_T is_active_c15_SOCEstimation; /* '<S4>/SOC_Calibration' */
  uint8_T is_c14_SOCEstimation;        /* '<S3>/Chart1' */
  uint8_T is_active_c14_SOCEstimation; /* '<S3>/Chart1' */
  uint8_T is_c27_SOCEstimation;        /* '<S3>/Chart' */
  uint8_T is_active_c27_SOCEstimation; /* '<S3>/Chart' */
  uint8_T is_c25_SOCEstimation;        /* '<S1>/Chart' */
  uint8_T is_active_c25_SOCEstimation; /* '<S1>/Chart' */
} DW_SOCEstimation_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<S1>/Subsystem' */
} PrevZCX_SOCEstimation_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  DataPipelineBus DataPipeline;        /* '<Root>/DataPipeline' */
  ProtectionState_Out ProtectionOutput;/* '<Root>/ProtectionOutput' */
  int32_T Current_mA;                  /* '<Root>/Current_mA' */
  int32_T Voltage_mV;                  /* '<Root>/Voltage_mV' */
  boolean_T triggerLatchPseudo;           /* '<Root>/triggerLatchPseudo' */
  CC_InputsBus CC_Inputs;              /* '<Root>/CC_Inputs' */
  CellBalancingOutputBus CellBalancingOutput;/* '<Root>/CellBalancingOutput' */
} ExtU_SOCEstimation_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  CC_OutputsBus CC_Outputs;            /* '<Root>/CC_Outputs' */
  real32_T SOC_FromFlash;              /* '<Root>/SOC_FromFlash' */
  real_T SOHCalibrationCycleCompletion;
                                    /* '<Root>/SOHCalibrationCycleCompletion' */
  boolean_T pseudoLatchTrigger;         /* '<Root>/pseudoLatchTrigger' */
} ExtY_SOCEstimation_T;

/* Parameters (default storage) */
struct P_SOCEstimation_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 10000
                                        * Referenced by: '<S3>/Gain1'
                                        */
  int32_T Tested_InstalledCapacity_mAh_Y0;
                          /* Computed Parameter: Tested_InstalledCapacity_mAh_Y0
                           * Referenced by: '<S18>/Tested_InstalledCapacity_mAh'
                           */
  int32_T Saturation1_UpperSat;      /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  int32_T Saturation1_LowerSat;      /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  int32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S1>/Saturation'
                                       */
  int32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S1>/Saturation'
                                       */
  int32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S1>/Data Store Memory'
                              */
  int32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S7>/Discrete-Time Integrator'
                            */
  int32_T Gain3_Gain;                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real32_T Gain1_Gain_g;               /* Computed Parameter: Gain1_Gain_g
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S18>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S7>/Discrete-Time Integrator'
                                 */
  real32_T Gain2_Gain_k;               /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<S3>/Discrete-Time Integrator2'
                           */
  real32_T DiscreteTimeIntegrator2_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                * Referenced by: '<S3>/Discrete-Time Integrator2'
                                */
  real32_T Multiply2_Gain;             /* Computed Parameter: Multiply2_Gain
                                        * Referenced by: '<S3>/Multiply2'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S7>/Gain'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S1>/Switch1'
                                        */
  real32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<S1>/Data Store Memory1'
                             */
  boolean_T DataStoreMemory2_InitialValue;/* Expression: false
                                           * Referenced by: '<S1>/Data Store Memory2'
                                           */
  int8_T CC_InputsSensorAccuracy_pct100_;
                          /* Computed Parameter: CC_InputsSensorAccuracy_pct100_
                           * Referenced by: '<S3>/CC_Inputs.SensorAccuracy_pct//100'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_SOCEstimation_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_SOCEstimation_T SOCEstimation_P;

/* Block signals (default storage) */
extern B_SOCEstimation_T SOCEstimation_B;

/* Block states (default storage) */
extern DW_SOCEstimation_T SOCEstimation_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_SOCEstimation_T SOCEstimation_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_SOCEstimation_T SOCEstimation_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SOCEstimation_T SOCEstimation_Y;

/* External data declarations for dependent source files */
extern const ProtectionState_Out SOCEstimation_rtZProtectionStat;/* ProtectionState_Out ground */
extern const CellBalancingOutputBus SOCEstimation_rtZCellBalancingO;/* CellBalancingOutputBus ground */
extern const CC_OutputsBus SOCEstimation_rtZCC_OutputsBus;/* CC_OutputsBus ground */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern boolean_T PSEUDO_LATCH_SUCCESS; /* '<S1>/Data Store Memory2' */

/* Model entry point functions */
extern void SOCEstimation_initialize(void);
extern void SOCEstimation_step(void);
extern void SOCEstimation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SOCEstimation_T *const SOCEstimation_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S7>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('v00_0A_0D/SOCEstimation')    - opens subsystem v00_0A_0D/SOCEstimation
 * hilite_system('v00_0A_0D/SOCEstimation/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'v00_0A_0D'
 * '<S1>'   : 'v00_0A_0D/SOCEstimation'
 * '<S2>'   : 'v00_0A_0D/SOCEstimation/Chart'
 * '<S3>'   : 'v00_0A_0D/SOCEstimation/CoulombCounter'
 * '<S4>'   : 'v00_0A_0D/SOCEstimation/SOC_Calibration'
 * '<S5>'   : 'v00_0A_0D/SOCEstimation/SOC_ReadFromFlash'
 * '<S6>'   : 'v00_0A_0D/SOCEstimation/SOC_WriteToFlash'
 * '<S7>'   : 'v00_0A_0D/SOCEstimation/SOH_Calculation'
 * '<S8>'   : 'v00_0A_0D/SOCEstimation/SOH_Calibration'
 * '<S9>'   : 'v00_0A_0D/SOCEstimation/Subsystem'
 * '<S10>'  : 'v00_0A_0D/SOCEstimation/Voltage_Vs_Capacity'
 * '<S11>'  : 'v00_0A_0D/SOCEstimation/powergui'
 * '<S12>'  : 'v00_0A_0D/SOCEstimation/CoulombCounter/Chart'
 * '<S13>'  : 'v00_0A_0D/SOCEstimation/CoulombCounter/Chart1'
 * '<S14>'  : 'v00_0A_0D/SOCEstimation/SOC_Calibration/SOC_Calibration'
 * '<S15>'  : 'v00_0A_0D/SOCEstimation/SOH_Calculation/Chart'
 * '<S16>'  : 'v00_0A_0D/SOCEstimation/SOH_Calculation/UsableCapacity_mAh'
 * '<S17>'  : 'v00_0A_0D/SOCEstimation/SOH_Calibration/SOH_Calibration'
 * '<S18>'  : 'v00_0A_0D/SOCEstimation/SOH_Calibration/Subsystem'
 * '<S19>'  : 'v00_0A_0D/SOCEstimation/SOH_Calibration/Subsystem/Chart'
 * '<S20>'  : 'v00_0A_0D/SOCEstimation/SOH_Calibration/Subsystem/UsableCapacity_mAh'
 */
#endif                                 /* RTW_HEADER_SOCEstimation_h_ */
