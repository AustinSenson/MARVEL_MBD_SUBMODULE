/*
 * DataPipeline.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DataPipeline".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  7 18:52:37 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->Cortex_M3
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_DataPipeline_h_
#define RTW_HEADER_DataPipeline_h_
#ifndef DataPipeline_COMMON_INCLUDES_
#define DataPipeline_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* DataPipeline_COMMON_INCLUDES_ */

#include "DataPipeline_types.h"
#include "MinimumFunction.h"
#include "MaximumFunction.h"
#include "I2t_perParallelCell.h"
#include "DynamicCurrentLimits_perParallelCell.h"
#include "AverageFunction.h"
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
  B_MinimumFunction_DataPipelin_T sf_MinimumFunction;/* '<S1>/MinimumFunction' */
  B_MaximumFunction_DataPipelin_T sf_MaximumFunction;/* '<S1>/MaximumFunction' */
  B_I2t_perParallelCell_DataPip_T sf_I2t_perParallelCell;/* '<S1>/I2t_perParallelCell' */
  B_DynamicCurrentLimits_perPar_T sf_DynamicCurrentLimits_perPara;
                               /* '<S1>/DynamicCurrentLimits_perParallelCell' */
  B_AverageFunction_DataPipelin_T sf_AverageFunction;/* '<S1>/AverageFunction' */
} B_DataPipeline_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int16_T Mean_AccVal;                 /* '<S1>/Mean' */
  int16_T Mean1_AccVal;                /* '<S1>/Mean1' */
} DW_DataPipeline_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Gain7_Gain
   * Referenced by: '<S1>/Gain7'
   */
  int64m_T Gain7_Gain;
} ConstP_DataPipeline_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
  int32_T SOC;                         /* '<Root>/SOC' */
  boolean_T isDynamicCurrentEn;        /* '<Root>/isDynamicCurrentEn' */
  uint8_T nCells_series;               /* '<Root>/nCells_Series' */
  int8_T nCells_parallel;              /* '<Root>/nCells_Parallel' */
  boolean_T TempSelectForDCL;          /* '<Root>/TempSelectForDCL' */
  real_T nCellTempGrps;                /* '<Root>/nCellTempGrps' */
  boolean_T SlowCharge;                /* '<Root>/SlowCharge' */
  boolean_T FastCharge;                /* '<Root>/FastCharge' */
  boolean_T isChargerConnected;        /* '<Root>/isChargerConnected' */
  boolean_T TransmissionFail;          /* '<Root>/TransmissionFail' */
  boolean_T VCUPermanentFail;          /* '<Root>/VCUPermanentFail' */
  boolean_T ServiceMode;               /* '<Root>/ServiceMode' */
  boolean_T PreChargeLogic;            /* '<Root>/PreChargeLogic' */
  boolean_T BalanceEn_atRest;          /* '<Root>/BalanceEn_atRest' */
  real32_T LoopTimer_SOC_msec;         /* '<Root>/LoopTimer_SOC_msec' */
  boolean_T EmergencyDisconnectEn;     /* '<Root>/EmergencyDisconnectEn' */
  uint32_T SlowChargersCurrentLimit_A; /* '<Root>/SlowChargersCurrentLimit_A' */
  uint32_T FastChargersCurrentLimit_A; /* '<Root>/FastChargersCurrentLimit_A' */
  boolean_T IR_Calculation_En;         /* '<Root>/IR_Calculation_En' */
  int32_T TerminalVoltage_mV;          /* '<Root>/TerminalVoltage_mV' */
  boolean_T IRComplete;                /* '<Root>/IRComplete' */
  boolean_T IRSlowGuard;               /* '<Root>/IRSlowGuard' */
  boolean_T IRFastGuard;               /* '<Root>/IRFastGuard' */
  uint32_T RecordedCycleCount;         /* '<Root>/RecordedCycleCount' */
  int16_T Temperatures2_C[7];          /* '<Root>/Temperatures2_C' */
  int16_T Temperatures1_C[7];          /* '<Root>/Temperatures1_C' */
  int32_T VoltageSense_mV[18];         /* '<Root>/VoltageSense_mV' */
  int32_T CurrentSense_mA;             /* '<Root>/CurrentSense_mA' */
  real32_T Inport1;                    /* '<Root>/Inport1' */
} ExtU_DataPipeline_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  DataPipelineBus DataPipelineb;       /* '<Root>/DataPipelineb' */
} ExtY_DataPipeline_T;

/* Parameters (default storage) */
struct P_DataPipeline_T_ {
  int8_T nCells_parallel;              /* Variable: nCells_parallel
                                        * Referenced by:
                                        *   '<S1>/Gain2'
                                        *   '<S1>/Gain3'
                                        *   '<S1>/Gain5'
                                        *   '<S1>/Gain9'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DataPipeline_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_DataPipeline_T DataPipeline_P;

/* Block signals (default storage) */
extern B_DataPipeline_T DataPipeline_B;

/* Block states (default storage) */
extern DW_DataPipeline_T DataPipeline_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_DataPipeline_T DataPipeline_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DataPipeline_T DataPipeline_Y;

/* External data declarations for dependent source files */
extern const DataPipelineBus DataPipeline_rtZDataPipelineBus;/* DataPipelineBus ground */

/* Constant parameters (default storage) */
extern const ConstP_DataPipeline_T DataPipeline_ConstP;

/* Model entry point functions */
extern void DataPipeline_initialize(void);
extern void DataPipeline_step(void);
extern void DataPipeline_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DataPipeline_T *const DataPipeline_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S1>/Gain1' : Unused code path elimination
 * Block '<S1>/Gain6' : Unused code path elimination
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
 * hilite_system('marvelMBD_v00_0A_0D_exported/DataPipeline')    - opens subsystem marvelMBD_v00_0A_0D_exported/DataPipeline
 * hilite_system('marvelMBD_v00_0A_0D_exported/DataPipeline/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'marvelMBD_v00_0A_0D_exported'
 * '<S1>'   : 'marvelMBD_v00_0A_0D_exported/DataPipeline'
 * '<S2>'   : 'marvelMBD_v00_0A_0D_exported/DataPipeline/AverageFunction'
 * '<S3>'   : 'marvelMBD_v00_0A_0D_exported/DataPipeline/DynamicCurrentLimits_perParallelCell'
 * '<S4>'   : 'marvelMBD_v00_0A_0D_exported/DataPipeline/GetN3'
 * '<S5>'   : 'marvelMBD_v00_0A_0D_exported/DataPipeline/I2t_perParallelCell'
 * '<S6>'   : 'marvelMBD_v00_0A_0D_exported/DataPipeline/MaximumFunction'
 * '<S7>'   : 'marvelMBD_v00_0A_0D_exported/DataPipeline/MinimumFunction'
 */
#endif                                 /* RTW_HEADER_DataPipeline_h_ */
