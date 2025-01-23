/*
 * SOCEstimation_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SOCEstimation".
 *
 * Model version              : 7.76
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Fri Jan 17 17:05:33 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef SOCEstimation_types_h_
#define SOCEstimation_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_VoltageSenseBus_
#define DEFINED_TYPEDEF_FOR_VoltageSenseBus_

typedef struct {
  int32_T Voltages_mV[18];
  int32_T mV_min;
  int32_T mV_max;
  int32_T VoltageDelta_mV;
} VoltageSenseBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TemperatureSenseBus_
#define DEFINED_TYPEDEF_FOR_TemperatureSenseBus_

typedef struct {
  int16_T Temperatures_C[7];
  int16_T T_min;
  int16_T T_max;
  int16_T TemperatureDelta_C;
} TemperatureSenseBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VCU_
#define DEFINED_TYPEDEF_FOR_VCU_

typedef struct {
  boolean_T SlowCharge;
  boolean_T FastCharge;
  boolean_T isChargerConnected;
  boolean_T TransmissionFail;
  boolean_T VCUPermanentFail;
  boolean_T ServiceMode;
  boolean_T BalanceEn_atRest;
  boolean_T EmergencyDisconnectEn;
  uint32_T SlowChargersCurrentLimit_A;
  uint32_T FastChargersCurrentLimit_A;
} VCU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DataPipelineBus_
#define DEFINED_TYPEDEF_FOR_DataPipelineBus_

typedef struct {
  int32_T Current_mA;
  VoltageSenseBus VoltageSenseBus;
  int16_T MaxTemperature_C;
  int16_T DeltaTemperature_C;
  int16_T MinTemperature_C;
  int16_T DeltaTemperatureGroup1_C;
  int16_T DeltaTemperatureGroup2_C;
  TemperatureSenseBus TemperatureSenseBus[2];
  uint8_T isChargeEn;
  boolean_T isDynamicCurrentEn;
  uint8_T nCells_series;
  int8_T nCells_parallel;
  real32_T DCL_ChargingCurrent_A;
  real32_T DCL_DisChargingCurrent_A;
  real32_T DCL_arcReactor_A;
  real32_T i2t_ChargingCurrent_A2sec;
  real32_T i2t_DisChargingCurrent_A2sec;
  real32_T LoopTimer_SOC_msec;
  VCU VCU;
  boolean_T PreChargeLogic;
  int32_T TerminalVoltage_mV;
  boolean_T IR_Calculation_En;
  uint32_T RecordedCycleCount;
  boolean_T IRSlowGuard;
  boolean_T IRFastGuard;
  boolean_T IRComplete;
} DataPipelineBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SlowCharge_
#define DEFINED_TYPEDEF_FOR_SlowCharge_

typedef struct {
  int32_T MaxVoltageLimit_mV;
  int32_T MaxCurrentLimit_mA;
  int32_T MinCurrentLimit_mA;
  int32_T MaxAllowedImb_mV;
} SlowCharge;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FastCharge_
#define DEFINED_TYPEDEF_FOR_FastCharge_

typedef struct {
  int32_T MaxVoltageLimit_mV;
  int32_T MaxCurrentLimit_mA;
  int32_T MinCurrentLimit_mA;
  int32_T MaxAllowedImb_mV;
} FastCharge;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Coefficients_
#define DEFINED_TYPEDEF_FOR_Coefficients_

typedef struct {
  real_T elementZero;
  real_T elementOne;
  real_T elementTwo;
  real_T elementThree;
  real_T elementFour;
} Coefficients;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CC_InputsBus_
#define DEFINED_TYPEDEF_FOR_CC_InputsBus_

typedef struct {
  int32_T InstalledCapacity_mAh;
  int32_T EquivalentCycleCapacity_mAh;
  int32_T SensorOffset_mA;
  int32_T SensorAccuracy_pct;
  int32_T BleedingCurrent_mA;
  int16_T CCTimeout_msec;
  int16_T DebouncingTimeout_msec;
  boolean_T LoopTimeSelector;
  SlowCharge SlowCharge;
  FastCharge FastCharge;
  uint16_T minVoltageForLatch_mV;
  boolean_T pseudoLatchFlag;
  boolean_T fullChargeFlag;
  boolean_T SOH_Calc_Enable;
  real32_T CycleCountTo_SOH;
  boolean_T PrevLatch;
  Coefficients Coefficients;
  real32_T Tcomp;
  real32_T SoHThresh;
} CC_InputsBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BalancingState_
#define DEFINED_TYPEDEF_FOR_BalancingState_

typedef enum {
  Terminate = 0,                       /* Default value */
  Lobby,
  Even_Balancing,
  Odd_Balancing
} BalancingState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CellBalancingOutputBus_
#define DEFINED_TYPEDEF_FOR_CellBalancingOutputBus_

typedef struct {
  int32_T MaxImbalance_mV;
  boolean_T BalanceEn;
  BalancingState CurrentBalancingState;
} CellBalancingOutputBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CCState_
#define DEFINED_TYPEDEF_FOR_CCState_

typedef enum {
  Vehicle_at_Rest = 0,                 /* Default value */
  CoulombCounting,
  PseudoLatching,
  Recalibrate
} CCState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CC_OutputsBus_
#define DEFINED_TYPEDEF_FOR_CC_OutputsBus_

typedef struct {
  int32_T Initial_Capacity_mAh;
  int32_T Total_CapacityRemains_mAh;
  int32_T SOC_cpct;
  CCState CC_State;
  int32_T MaxUsableCapacity_mAh;
  int32_T TotalCapacityExchange_mAh;
  real32_T SOH_pct;
  real32_T SoH2;
} CC_OutputsBus;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_SOCEstimation_T RT_MODEL_SOCEstimation_T;

#endif                                 /* SOCEstimation_types_h_ */
