/*
 * SOCEstimation.c
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

#include "SOCEstimation.h"
#include "rtwtypes.h"
#include "SOCEstimation_types.h"
#include "SOC_ReadFromEEPROM.h"
#include <math.h>
#include <string.h>

/* Named constants for Chart: '<S3>/IntegCurrent' */
#define SOCEstimat_IN_IntegratedCurrent ((uint8_T)1U)
#define SOCEstimatio_IN_IntegratorReset ((uint8_T)2U)
#define SOCEstimatio_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Named constants for Chart: '<S3>/SOC_Calibration' */
#define SOCEsti_IN_Recalibrate_Charging ((uint8_T)3U)
#define SOCEstimatio_IN_CoulombCounting ((uint8_T)1U)
#define SOCEstimatio_IN_Vehicle_at_Rest ((uint8_T)4U)
#define SOCEstimation_IN_PseudoLatching ((uint8_T)2U)

/* Block signals (default storage) */
B_SOCEstimation_T SOCEstimation_B;

/* Block states (default storage) */
DW_SOCEstimation_T SOCEstimation_DW;

/* External inputs (root inport signals with default storage) */
ExtU_SOCEstimation_T SOCEstimation_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SOCEstimation_T SOCEstimation_Y;

/* Real-time model */
static RT_MODEL_SOCEstimation_T SOCEstimation_M_;
RT_MODEL_SOCEstimation_T *const SOCEstimation_M = &SOCEstimation_M_;

/* Forward declaration for local functions */
static void SOCEstimation_calculate(int32_T vMax, int32_T vMin, int32_T
  Current_mA, int32_T MaxCurrentLimit_mA, int32_T MinCurrentLimit_mA, uint16_T
  minVoltageForLatch, real32_T cycleCount, boolean_T isChargerConnected,
  boolean_T fullChargeLatch, boolean_T pseudoChargeLatch, int32_T
  capacityRemains, int32_T MaxImbalance_mV, int32_T MaxAllowedImb_mV, int32_T
  *capacLatch, boolean_T *calcSoH, boolean_T *latchMake);
const CC_OutputsBus SOCEstimation_rtZCC_OutputsBus = { 0,/* Initial_Capacity_mAh */
  0,                                   /* Total_CapacityRemains_mAh */
  0,                                   /* SOC_cpct */
  Vehicle_at_Rest,                     /* CC_State */
  0,                                   /* MaxUsableCapacity_mAh */
  0,                                   /* TotalCapacityExchange_mAh */
  0.0F,                                /* SOH_pct */
  0.0F                                 /* SoH2 */
};

const CellBalancingOutputBus SOCEstimation_rtZCellBalancingO = { 0,/* MaxImbalance_mV */
  false,                               /* BalanceEn */
  Terminate                            /* CurrentBalancingState */
};

/*
 * Function for Chart: '<S3>/SOC_Calibration'
 * function [capacLatch, calcSoH, latchMake]  = calculate(vMax, vMin, Current_mA, MaxCurrentLimit_mA,...
 *  MinCurrentLimit_mA, minVoltageForLatch, cycleCount, isChargerConnected,...
 *     fullChargeLatch, pseudoChargeLatch, capacityRemains, MaxImbalance_mV, ...
 *     MaxAllowedImb_mV)
 */
static void SOCEstimation_calculate(int32_T vMax, int32_T vMin, int32_T
  Current_mA, int32_T MaxCurrentLimit_mA, int32_T MinCurrentLimit_mA, uint16_T
  minVoltageForLatch, real32_T cycleCount, boolean_T isChargerConnected,
  boolean_T fullChargeLatch, boolean_T pseudoChargeLatch, int32_T
  capacityRemains, int32_T MaxImbalance_mV, int32_T MaxAllowedImb_mV, int32_T
  *capacLatch, boolean_T *calcSoH, boolean_T *latchMake)
{
  /* MATLAB Function 'calculate': '<S10>:174' */
  /* '<S10>:174:6' if (((fullChargeLatch || pseudoChargeLatch) == false) && isChargerConnected == 1) */
  if ((!fullChargeLatch) && (!pseudoChargeLatch) && isChargerConnected) {
    boolean_T guard1;

    /* '<S10>:174:8' if ((vMin >= minVoltageForLatch) && (abs(Current_mA) < MaxCurrentLimit_mA && ... */
    /* '<S10>:174:9'             abs(Current_mA) > MinCurrentLimit_mA) &&  isChargerConnected == 1 && ... */
    /* '<S10>:174:10'                 MaxImbalance_mV < MaxAllowedImb_mV) */
    guard1 = false;
    if (vMin >= minVoltageForLatch) {
      int32_T tmp;
      if (Current_mA < 0) {
        if (Current_mA <= MIN_int32_T) {
          tmp = MAX_int32_T;
        } else {
          tmp = -Current_mA;
        }
      } else {
        tmp = Current_mA;
      }

      if (tmp < MaxCurrentLimit_mA) {
        if (Current_mA < 0) {
          if (Current_mA <= MIN_int32_T) {
            tmp = MAX_int32_T;
          } else {
            tmp = -Current_mA;
          }
        } else {
          tmp = Current_mA;
        }

        if ((tmp > MinCurrentLimit_mA) && (MaxImbalance_mV < MaxAllowedImb_mV))
        {
          /* '<S10>:174:11' capacLatch = int32(capacityRemains); */
          *capacLatch = capacityRemains;

          /* '<S10>:174:12' calcSoH  = true; */
          *calcSoH = true;

          /* '<S10>:174:13' latchMake = true; */
          *latchMake = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if ((vMax >= 3550) && (cycleCount > 200.0F)) {
        /* '<S10>:174:15' elseif ((vMax >= 3550 && cycleCount> 200)) */
        /* '<S10>:174:16' capacLatch = int32(capacityRemains); */
        *capacLatch = capacityRemains;

        /* '<S10>:174:17' calcSoH  = true; */
        *calcSoH = true;

        /* '<S10>:174:18' latchMake = false; */
        *latchMake = false;
      } else {
        /* '<S10>:174:20' else */
        /* '<S10>:174:21' capacLatch = int32(capacityRemains); */
        *capacLatch = capacityRemains;

        /* '<S10>:174:22' calcSoH  = false; */
        *calcSoH = false;

        /* '<S10>:174:23' latchMake = false; */
        *latchMake = false;
      }
    }
  } else {
    /* '<S10>:174:25' else */
    /* '<S10>:174:26' capacLatch = int32(capacityRemains); */
    *capacLatch = capacityRemains;

    /* '<S10>:174:27' calcSoH  = false; */
    *calcSoH = false;

    /* '<S10>:174:28' latchMake = false; */
    *latchMake = false;
  }
}

/* Model step function */
void SOCEstimation_step(void)
{
  real_T coefficients[5];
  real_T rtb_DataTypeConversion4;
  real_T rtb_MaxUsableCapacity_mAh;
  real_T rtb_factor1;
  real_T rtb_weight1;
  int32_T rtb_DataTypeConversion3;
  int32_T rtb_Switch;
  int32_T tmp;
  int32_T tmp_0;
  real32_T rtb_SoH2;
  boolean_T tmp_1;

  /* MATLAB Function: '<S1>/SOC_ReadFromEEPROM' */
  SOCEstimatio_SOC_ReadFromEEPROM(&SOCEstimation_B.sf_SOC_ReadFromEEPROM);

  /* Outputs for Enabled SubSystem: '<S1>/SoH calculation' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoHCalcEn) {
    SOCEstimation_DW.SoHcalculation_MODE = true;

    /* MATLAB Function: '<S13>/MATLAB Function' incorporates:
     *  DataTypeConversion: '<S13>/Data Type Conversion1'
     *  Inport: '<Root>/CC_Inputs'
     */
    /* MATLAB Function 'SOCEstimation/SoH calculation/SoH1 calculation/MATLAB Function': '<S16>:1' */
    /* '<S16>:1:4' coefficients = [ A, B, C, D, E]; */
    coefficients[0] = SOCEstimation_U.CC_Inputs.Coefficients.elementZero;
    coefficients[1] = SOCEstimation_U.CC_Inputs.Coefficients.elementOne;
    coefficients[2] = SOCEstimation_U.CC_Inputs.Coefficients.elementTwo;
    coefficients[3] = SOCEstimation_U.CC_Inputs.Coefficients.elementThree;
    coefficients[4] = SOCEstimation_U.CC_Inputs.Coefficients.elementFour;

    /* '<S16>:1:5' y = 0.0; */
    rtb_DataTypeConversion4 = 0.0;

    /* '<S16>:1:7' for i = 1:length(coefficients) */
    for (rtb_Switch = 0; rtb_Switch < 5; rtb_Switch++) {
      /* '<S16>:1:8' y = y + coefficients(i) * cycleCount^(5 - (i)); */
      rtb_DataTypeConversion4 += pow
        (SOCEstimation_B.sf_SOC_ReadFromEEPROM.cycleCount, 5.0 - ((real_T)
          rtb_Switch + 1.0)) * coefficients[rtb_Switch];
    }

    /* Saturate: '<S13>/Saturation' incorporates:
     *  MATLAB Function: '<S13>/MATLAB Function'
     */
    if (rtb_DataTypeConversion4 > 100.0) {
      rtb_DataTypeConversion4 = 100.0;
    } else if (rtb_DataTypeConversion4 < 0.0) {
      rtb_DataTypeConversion4 = 0.0;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Switch: '<S12>/Switch' incorporates:
     *  Abs: '<S12>/Abs'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S15>/Constant2'
     *  Constant: '<S15>/Constant3'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  Inport: '<Root>/CC_Inputs'
     *  Logic: '<S12>/AND'
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     *  Product: '<S15>/Product2'
     *  RelationalOperator: '<S12>/GreaterThan'
     *  RelationalOperator: '<S12>/GreaterThan1'
     *  Sum: '<S12>/Subtract2'
     *  Sum: '<S15>/Add1'
     *  Sum: '<S15>/Subtract'
     */
    if ((fabsf(SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoH2 - (real32_T)
               rtb_DataTypeConversion4) > SOCEstimation_U.CC_Inputs.SoHThresh) &&
        SOCEstimation_B.sf_SOC_ReadFromEEPROM.PrevLatch &&
        (SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoH2 > 50.0F)) {
      /* Product: '<S15>/Divide1' incorporates:
       *  Constant: '<S15>/Constant1'
       */
      rtb_MaxUsableCapacity_mAh = SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoH2 /
        100.0;

      /* Product: '<S15>/Divide' incorporates:
       *  Constant: '<S15>/Constant'
       */
      rtb_factor1 = (real32_T)rtb_DataTypeConversion4 / 100.0;

      /* Product: '<S15>/Divide2' incorporates:
       *  Sum: '<S15>/Add'
       */
      rtb_weight1 = rtb_factor1 / (rtb_factor1 + rtb_MaxUsableCapacity_mAh);
      rtb_MaxUsableCapacity_mAh = ((1.0 - rtb_weight1) *
        rtb_MaxUsableCapacity_mAh + rtb_factor1 * rtb_weight1) * 100.0;
    } else {
      rtb_MaxUsableCapacity_mAh = (real32_T)rtb_DataTypeConversion4;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Saturate: '<S12>/Saturation' */
    if (rtb_MaxUsableCapacity_mAh > 100.0) {
      rtb_MaxUsableCapacity_mAh = 100.0;
    } else if (rtb_MaxUsableCapacity_mAh < 0.0) {
      rtb_MaxUsableCapacity_mAh = 0.0;
    }

    /* End of Saturate: '<S12>/Saturation' */
    /* Switch: '<S5>/Switch' incorporates:
     *  RelationalOperator: '<S5>/GreaterThan'
     */
    if ((rtb_MaxUsableCapacity_mAh >= SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoH) && SOCEstimation_B.sf_SOC_ReadFromEEPROM.PrevLatch)
    {
      /* Switch: '<S5>/Switch' */
      SOCEstimation_B.Switch = SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoH;
    } else {
      /* Switch: '<S5>/Switch' */
      SOCEstimation_B.Switch = (real32_T)rtb_MaxUsableCapacity_mAh;
    }

    /* End of Switch: '<S5>/Switch' */

    /* Product: '<S14>/Product4' incorporates:
     *  Constant: '<S14>/Constant3'
     *  Inport: '<Root>/CC_Inputs'
     *  Product: '<S14>/Divide3'
     */
    rtb_DataTypeConversion4 = (real_T)
      SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh / 100.0 *
      SOCEstimation_B.Switch;

    /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion2'
     */
    SOCEstimation_B.Effectiveusablecapacity = (int32_T)floorf((real32_T)
      rtb_DataTypeConversion4);
  } else {
    SOCEstimation_DW.SoHcalculation_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/SoH calculation' */

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  Constant: '<S6>/Constant'
   */
  /* MATLAB Function 'SOCEstimation/Subsystem/MATLAB Function': '<S17>:1' */
  /* '<S17>:1:3' if isempty(counter) */
  if (!SOCEstimation_DW.counter_not_empty) {
    /* '<S17>:1:4' counter = init_value; */
    SOCEstimation_DW.counter = 0.0;
    SOCEstimation_DW.counter_not_empty = true;
  } else if (SOCEstimation_DW.counter != 9.0) {
    if(SOCEstimation_DW.counter == 7.0) {        //manually added
          memoryWriteOverride = true;
        }
    /* '<S17>:1:7' else */
    /* '<S17>:1:8' counter = counter + 1; */
    SOCEstimation_DW.counter++;
  } else {
    /* '<S17>:1:5' elseif counter == 9 */
    /* '<S17>:1:6' counter = counter; */
  }

  /* Chart: '<S3>/IntegCurrent' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Inport: '<Root>/Current_mA'
   *  Inport: '<Root>/DataPipeline'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  /* '<S17>:1:10' counterOut = counter; */
  /* Gateway: SOCEstimation/SOC_Calc/IntegCurrent */
  /* During: SOCEstimation/SOC_Calc/IntegCurrent */
  if (SOCEstimation_DW.is_active_c42_SOCEstimation == 0U) {
    /* Entry: SOCEstimation/SOC_Calc/IntegCurrent */
    SOCEstimation_DW.is_active_c42_SOCEstimation = 1U;

    /* Entry Internal: SOCEstimation/SOC_Calc/IntegCurrent */
    /* Transition: '<S8>:4' */
    SOCEstimation_DW.is_c42_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;

    /* Entry 'IntegratedCurrent': '<S8>:3' */
  } else if (SOCEstimation_DW.is_c42_SOCEstimation ==
             SOCEstimat_IN_IntegratedCurrent) {
    /* During 'IntegratedCurrent': '<S8>:3' */
    /* '<S8>:8:1' sf_internal_predicateOutput = CC_State ==0  || CC_State == 3; */
    if (((int32_T)SOCEstimation_DW.CCState_k == 0) || ((int32_T)
         SOCEstimation_DW.CCState_k == 3)) {
      /* Transition: '<S8>:8' */
      SOCEstimation_DW.is_c42_SOCEstimation = SOCEstimatio_IN_IntegratorReset;

      /* Entry 'IntegratorReset': '<S8>:7' */
    } else {
      /* '<S8>:3:3' IntegratedCurrent = single(single(LoopTimer_SOC_msec)*single(Current_mA))+IntegratedCurrent; */
      SOCEstimation_B.IntegratedCurrent +=
        SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec * (real32_T)
        SOCEstimation_U.Current_mA;
    }

    /* During 'IntegratorReset': '<S8>:7' */
    /* '<S8>:12:1' sf_internal_predicateOutput = CC_State ==1 || CC_State ==2; */
  } else if (((int32_T)SOCEstimation_DW.CCState_k == 1) || ((int32_T)
              SOCEstimation_DW.CCState_k == 2)) {
    /* Transition: '<S8>:12' */
    SOCEstimation_DW.is_c42_SOCEstimation = SOCEstimat_IN_IntegratedCurrent;

    /* Entry 'IntegratedCurrent': '<S8>:3' */
  } else {
    /* '<S8>:7:3' IntegratedCurrent = 0; */
    SOCEstimation_B.IntegratedCurrent = 0.0F;
  }

  /* End of Chart: '<S3>/IntegCurrent' */

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Multiply2'
   */
  rtb_DataTypeConversion3 = (int32_T)floorf(0.001F *
    SOCEstimation_B.IntegratedCurrent * 0.000277777785F);

  /* Switch: '<S6>/Switch' incorporates:
   *  MATLAB Function: '<S6>/MATLAB Function'
   *  Product: '<S6>/Product'
   */
  if (SOCEstimation_DW.counter > 7.0) {
    rtb_Switch = (int32_T)floor((real_T)SOCEstimation_B.Effectiveusablecapacity *
      SOCEstimation_B.sf_SOC_ReadFromEEPROM.TcompPersist);
  } else {
    rtb_Switch = SOCEstimation_B.Effectiveusablecapacity;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Chart: '<S3>/SOC_Calibration' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   *  Inport: '<Root>/CellBalancingOutput'
   *  Inport: '<Root>/Current_mA'
   *  Inport: '<Root>/DataPipeline'
   *  MATLAB Function: '<S6>/MATLAB Function'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch2'
   *  Switch: '<S3>/Switch3'
   */
  /* Gateway: SOCEstimation/SOC_Calc/SOC_Calibration */
  if (SOCEstimation_DW.temporalCounter_i1 < MAX_uint32_T) {
    SOCEstimation_DW.temporalCounter_i1++;
  }

  /* During: SOCEstimation/SOC_Calc/SOC_Calibration */
  if (SOCEstimation_DW.is_active_c15_SOCEstimation == 0U) {
    /* Entry: SOCEstimation/SOC_Calc/SOC_Calibration */
    SOCEstimation_DW.is_active_c15_SOCEstimation = 1U;

    /* Entry Internal: SOCEstimation/SOC_Calc/SOC_Calibration */
    /* Transition: '<S10>:24' */
    SOCEstimation_DW.temporalCounter_i1 = 0U;
    SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_Vehicle_at_Rest;

    /* Entry 'Vehicle_at_Rest': '<S10>:9' */
    /* '<S10>:9:2' CC_State = CCState.Vehicle_at_Rest; */
    SOCEstimation_DW.CCState_k = Vehicle_at_Rest;
  } else {
    switch (SOCEstimation_DW.is_c15_SOCEstimation) {
     case SOCEstimatio_IN_CoulombCounting:
      SOCEstimation_DW.CCState_k = CoulombCounting;

      /* During 'CoulombCounting': '<S10>:3' */
      /* '<S10>:158:1' sf_internal_predicateOutput = duration((pseudoLatchFlag == true && fullChargeFlag == false)... */
      /* '<S10>:158:2' ,msec) > DebouncingTimeout_msec; */
      if ((!SOCEstimation_U.CC_Inputs.pseudoLatchFlag) ||
          SOCEstimation_U.CC_Inputs.fullChargeFlag) {
        SOCEstimation_DW.durationCounter_1 = 0U;
      }

      if ((uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1 * SOCEstimation_U.looptimeSoC) >
          (uint16_T)SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
        /* Transition: '<S10>:158' */
        SOCEstimation_DW.durationCounter_1_c = 0U;
        SOCEstimation_DW.temporalCounter_i1 = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimation_IN_PseudoLatching;

        /* Entry 'PseudoLatching': '<S10>:153' */
        /* '<S10>:153:3' CC_State = CCState.PseudoLatching; */
        SOCEstimation_DW.CCState_k = PseudoLatching;
      } else {
        /* '<S10>:78:1' sf_internal_predicateOutput = duration(latchMake == true, msec) >DebouncingTimeout_msec; */
        if (!SOCEstimation_DW.latchMake) {
          SOCEstimation_DW.durationCounter_2 = 0U;
        }

        if ((uint32_T)((int32_T)SOCEstimation_DW.durationCounter_2 * SOCEstimation_U.looptimeSoC) >
            (uint16_T)SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
          /* Transition: '<S10>:78' */
          SOCEstimation_DW.temporalCounter_i1 = 0U;
          SOCEstimation_DW.is_c15_SOCEstimation =
            SOCEsti_IN_Recalibrate_Charging;

          /* Entry 'Recalibrate_Charging': '<S10>:6' */
          /* '<S10>:6:3' CC_State = CCState.Recalibrate; */
          SOCEstimation_DW.CCState_k = Recalibrate;

          /* '<S10>:6:4' Initial_Capacity_mAh = int32(MaxUsableCapacity_mAh); */
          SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh = rtb_Switch;

          /* '<S10>:6:5' TotalCapacityRemains_mAh = Initial_Capacity_mAh; */
          SOCEstimation_B.TotalCapacityRemains_mAh =
            SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh;
        } else {
          /* '<S10>:3:5' TotalCapacityRemains_mAh = Initial_Capacity_mAh + IntegratedCurrent */
          if ((SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh < 0) &&
              (rtb_DataTypeConversion3 < MIN_int32_T
               - SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh)) {
            SOCEstimation_B.TotalCapacityRemains_mAh = MIN_int32_T;
          } else if ((SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh > 0) &&
                     (rtb_DataTypeConversion3 > MAX_int32_T
                      - SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh)) {
            SOCEstimation_B.TotalCapacityRemains_mAh = MAX_int32_T;
          } else {
            SOCEstimation_B.TotalCapacityRemains_mAh =
              SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh +
              rtb_DataTypeConversion3;
          }

          /* Switch: '<S3>/Switch2' incorporates:
           *  Inport: '<Root>/DataPipeline'
           *  Switch: '<S3>/Switch1'
           *  Switch: '<S3>/Switch3'
           */
          /* '<S10>:3:6' [capLatch, calcSoH, latchMake] = calculate(DataPipeline.VoltageSenseBus.mV_max,... */
          /* '<S10>:3:7'         DataPipeline.VoltageSenseBus.mV_min, Current_mA, MaxCurrentLimit_mA, MinCurrentLimit_mA,... */
          /* '<S10>:3:8'         minVoltageForLatch, cycleCount, DataPipeline.VCU.isChargerConnected, fullChargeFlag ,pseudoLatchFlag,... */
          /* '<S10>:3:9'         TotalCapacityRemains_mAh, CellBalancingOutput.MaxImbalance_mV, MaxAllowedImb_mV); */
          if (SOCEstimation_U.DataPipeline.VCU.FastCharge) {
            rtb_DataTypeConversion3 =
              SOCEstimation_U.CC_Inputs.FastCharge.MaxCurrentLimit_mA;
            tmp = SOCEstimation_U.CC_Inputs.FastCharge.MinCurrentLimit_mA;
            tmp_0 = SOCEstimation_U.CC_Inputs.FastCharge.MaxAllowedImb_mV;
          } else {
            rtb_DataTypeConversion3 =
              SOCEstimation_U.CC_Inputs.SlowCharge.MaxCurrentLimit_mA;
            tmp = SOCEstimation_U.CC_Inputs.SlowCharge.MinCurrentLimit_mA;
            tmp_0 = SOCEstimation_U.CC_Inputs.SlowCharge.MaxAllowedImb_mV;
          }

          SOCEstimation_calculate
            (SOCEstimation_U.DataPipeline.VoltageSenseBus.mV_max,
             SOCEstimation_U.DataPipeline.VoltageSenseBus.mV_min,
             SOCEstimation_U.Current_mA, rtb_DataTypeConversion3, tmp,
             SOCEstimation_U.CC_Inputs.minVoltageForLatch_mV,
             SOCEstimation_U.CC_Inputs.CycleCountTo_SOH,
             SOCEstimation_U.DataPipeline.VCU.isChargerConnected,
             SOCEstimation_U.CC_Inputs.fullChargeFlag,
             SOCEstimation_U.CC_Inputs.pseudoLatchFlag,
             SOCEstimation_B.TotalCapacityRemains_mAh,
             SOCEstimation_U.CellBalancingOutput.MaxImbalance_mV, tmp_0,
             &SOCEstimation_B.capLatch, &SOCEstimation_B.calcSoH,
             &SOCEstimation_DW.latchMake);
          if (!SOCEstimation_DW.latchMake) {
            SOCEstimation_DW.durationCounter_2 = 0U;
          }
        }
      }
      break;

     case SOCEstimation_IN_PseudoLatching:
      SOCEstimation_DW.CCState_k = PseudoLatching;

      /* During 'PseudoLatching': '<S10>:153' */
      /* '<S10>:159:1' sf_internal_predicateOutput = (TotalCapacityRemains_mAh >= MaxUsableCapacity_mAh) && after(DebouncingTimeout_msec, msec); */
      if ((SOCEstimation_B.TotalCapacityRemains_mAh >= rtb_Switch) && ((uint32_T)
           ((int32_T)SOCEstimation_DW.temporalCounter_i1 * SOCEstimation_U.looptimeSoC) >= (uint16_T)
           SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec)) {
        /* Transition: '<S10>:159' */
        SOCEstimation_DW.temporalCounter_i1 = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEsti_IN_Recalibrate_Charging;

        /* Entry 'Recalibrate_Charging': '<S10>:6' */
        /* '<S10>:6:3' CC_State = CCState.Recalibrate; */
        SOCEstimation_DW.CCState_k = Recalibrate;

        /* '<S10>:6:4' Initial_Capacity_mAh = int32(MaxUsableCapacity_mAh); */
        SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh = rtb_Switch;

        /* '<S10>:6:5' TotalCapacityRemains_mAh = Initial_Capacity_mAh; */
        SOCEstimation_B.TotalCapacityRemains_mAh =
          SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh;
      } else {
        /* '<S10>:206:1' sf_internal_predicateOutput = duration((pseudoLatchFlag == false && fullChargeFlag == false)... */
        /* '<S10>:206:2' ,msec) > DebouncingTimeout_msec; */
        if (SOCEstimation_U.CC_Inputs.pseudoLatchFlag ||
            SOCEstimation_U.CC_Inputs.fullChargeFlag) {
          SOCEstimation_DW.durationCounter_1_c = 0U;
        }

        if ((uint32_T)((int32_T)SOCEstimation_DW.durationCounter_1_c * SOCEstimation_U.looptimeSoC) >
            (uint16_T)SOCEstimation_U.CC_Inputs.DebouncingTimeout_msec) {
          /* Transition: '<S10>:206' */
          SOCEstimation_DW.durationCounter_2 = 0U;
          SOCEstimation_DW.durationCounter_1 = 0U;
          SOCEstimation_DW.is_c15_SOCEstimation =
            SOCEstimatio_IN_CoulombCounting;

          /* Entry 'CoulombCounting': '<S10>:3' */
          /* '<S10>:3:3' CC_State = CCState.CoulombCounting; */
          SOCEstimation_DW.CCState_k = CoulombCounting;

          /* '<S10>:153:5' TotalCapacityRemains_mAh = Initial_Capacity_mAh + IntegratedCurrent; */
        } else if ((SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh < 0) &&
                   (rtb_DataTypeConversion3 < MIN_int32_T
                    - SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh)) {
          SOCEstimation_B.TotalCapacityRemains_mAh = MIN_int32_T;
        } else if ((SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh > 0) &&
                   (rtb_DataTypeConversion3 > MAX_int32_T
                    - SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh)) {
          SOCEstimation_B.TotalCapacityRemains_mAh = MAX_int32_T;
        } else {
          SOCEstimation_B.TotalCapacityRemains_mAh =
            SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh +
            rtb_DataTypeConversion3;
        }
      }
      break;

     case SOCEsti_IN_Recalibrate_Charging:
      SOCEstimation_DW.CCState_k = Recalibrate;

      /* During 'Recalibrate_Charging': '<S10>:6' */
      /* '<S10>:28:1' sf_internal_predicateOutput = after(CC_Inputs.CCTimeout_msec, msec); */
      if ((uint32_T)((int32_T)SOCEstimation_DW.temporalCounter_i1 * SOCEstimation_U.looptimeSoC) >=
          (uint16_T)SOCEstimation_U.CC_Inputs.CCTimeout_msec) {
        /* Transition: '<S10>:28' */
        /* '<S10>:28:2' latchMake = false; */
        SOCEstimation_DW.latchMake = false;
        SOCEstimation_DW.durationCounter_2 = 0U;
        SOCEstimation_DW.durationCounter_1 = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_CoulombCounting;

        /* Entry 'CoulombCounting': '<S10>:3' */
        /* '<S10>:3:3' CC_State = CCState.CoulombCounting; */
        SOCEstimation_DW.CCState_k = CoulombCounting;
      }
      break;

     default:
      SOCEstimation_DW.CCState_k = Vehicle_at_Rest;

      /* During 'Vehicle_at_Rest': '<S10>:9' */
      /* '<S10>:19:1' sf_internal_predicateOutput = (SynchCounter > 7) &&... */
      /* '<S10>:19:2'  after(CC_Inputs.CCTimeout_msec, msec); */
      if ((SOCEstimation_DW.counter > 7.0) && ((uint32_T)((int32_T)
            SOCEstimation_DW.temporalCounter_i1 * SOCEstimation_U.looptimeSoC) >= (uint16_T)
           SOCEstimation_U.CC_Inputs.CCTimeout_msec)) {
        /* Transition: '<S10>:19' */
        SOCEstimation_DW.durationCounter_2 = 0U;
        SOCEstimation_DW.durationCounter_1 = 0U;
        SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_CoulombCounting;

        /* Entry 'CoulombCounting': '<S10>:3' */
        /* '<S10>:3:3' CC_State = CCState.CoulombCounting; */
        SOCEstimation_DW.CCState_k = CoulombCounting;
      } else {
        /* Switch: '<S11>/Switch2' incorporates:
         *  RelationalOperator: '<S11>/LowerRelop1'
         *  RelationalOperator: '<S11>/UpperRelop'
         *  Switch: '<S11>/Switch'
         */
        /* '<S10>:9:4' Initial_Capacity_mAh = int32(Initial_Guess_mAh); */
        if (SOCEstimation_B.sf_SOC_ReadFromEEPROM.CapacityRemains_mAh >
            rtb_Switch) {
          SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh = rtb_Switch;
        } else if (SOCEstimation_B.sf_SOC_ReadFromEEPROM.CapacityRemains_mAh < 0)
        {
          /* Switch: '<S11>/Switch' incorporates:
           *  Constant: '<S3>/Constant2'
           */
          SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh = 0;
        } else {
          SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh =
            SOCEstimation_B.sf_SOC_ReadFromEEPROM.CapacityRemains_mAh;
        }

        /* End of Switch: '<S11>/Switch2' */
        /* '<S10>:9:5' TotalCapacityRemains_mAh = Initial_Capacity_mAh */
        SOCEstimation_B.TotalCapacityRemains_mAh =
          SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh;
      }
      break;
    }
  }

  tmp_1 = !SOCEstimation_U.CC_Inputs.fullChargeFlag;
  if (SOCEstimation_U.CC_Inputs.pseudoLatchFlag && tmp_1) {
    SOCEstimation_DW.durationCounter_1++;
  } else {
    SOCEstimation_DW.durationCounter_1 = 0U;
  }

  if ((!SOCEstimation_U.CC_Inputs.pseudoLatchFlag) && tmp_1) {
    SOCEstimation_DW.durationCounter_1_c++;
  } else {
    SOCEstimation_DW.durationCounter_1_c = 0U;
  }

  if (SOCEstimation_DW.latchMake) {
    SOCEstimation_DW.durationCounter_2++;
  } else {
    SOCEstimation_DW.durationCounter_2 = 0U;
  }

  /* End of Chart: '<S3>/SOC_Calibration' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  SOCEstimation_DW.CapacityRemains_mAh =
    SOCEstimation_B.TotalCapacityRemains_mAh;

  /* DataTypeConversion: '<S3>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = (real_T)SOCEstimation_DW.CCState_k;

  /* Chart: '<S3>/Modulus IntegCurrent' incorporates:
   *  Abs: '<S3>/Abs'
   *  Inport: '<Root>/DataPipeline'
   */
  /* Gateway: SOCEstimation/SOC_Calc/Modulus IntegCurrent */
  /* During: SOCEstimation/SOC_Calc/Modulus IntegCurrent */
  if (SOCEstimation_DW.is_active_c20_SOCEstimation == 0U) {
    /* Entry: SOCEstimation/SOC_Calc/Modulus IntegCurrent */
    SOCEstimation_DW.is_active_c20_SOCEstimation = 1U;

    /* Entry Internal: SOCEstimation/SOC_Calc/Modulus IntegCurrent */
    /* Transition: '<S9>:4' */
    /* Entry 'ModIntegratedCurrent': '<S9>:3' */
  } else {
    /* Abs: '<S3>/Abs' incorporates:
     *  Inport: '<Root>/Current_mA'
     */
    /* During 'ModIntegratedCurrent': '<S9>:3' */
    /* '<S9>:3:3' ModIntegratedCurrent = single(single(LoopTimer_SOC_msec)*single(Current_mA))+ModIntegratedCurrent; */
    if (SOCEstimation_U.Current_mA < 0) {
      rtb_DataTypeConversion3 = -SOCEstimation_U.Current_mA;
    } else {
      rtb_DataTypeConversion3 = SOCEstimation_U.Current_mA;
    }

    SOCEstimation_B.ModIntegratedCurrent +=
      SOCEstimation_U.DataPipeline.LoopTimer_SOC_msec * (real32_T)
      rtb_DataTypeConversion3;
  }

  /* End of Chart: '<S3>/Modulus IntegCurrent' */

  /* DataTypeConversion: '<S3>/Data Type Conversion5' incorporates:
   *  Gain: '<S3>/Gain3'
   *  Gain: '<S3>/Multiply1'
   */
  SOCEstimation_Y.CC_Outputs.TotalCapacityExchange_mAh = (int32_T)floorf(0.001F *
    SOCEstimation_B.ModIntegratedCurrent * 0.000277777785F);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  if (rtb_DataTypeConversion4 >= 3.0) {
    SOCEstimation_Y.CC_Outputs.SOC_cpct = 10000;
  } else {
    /* Gain: '<S3>/Gain1' incorporates:
     *  Product: '<S3>/Divide2'
     */
    rtb_DataTypeConversion3 = (int32_T)floor((real_T)
      SOCEstimation_B.TotalCapacityRemains_mAh / (real_T)rtb_Switch * 10000.0);

    /* Saturate: '<S3>/Saturation' */
    if (rtb_DataTypeConversion3 > 10000) {
      SOCEstimation_Y.CC_Outputs.SOC_cpct = 10000;
    } else if (rtb_DataTypeConversion3 < 0) {
      SOCEstimation_Y.CC_Outputs.SOC_cpct = 0;
    } else {
      SOCEstimation_Y.CC_Outputs.SOC_cpct = rtb_DataTypeConversion3;
    }

    /* End of Saturate: '<S3>/Saturation' */
  }

  /* End of Switch: '<S3>/Switch' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Inport: '<Root>/CC_Inputs'
   */
  /* MATLAB Function 'SOCEstimation/MATLAB Function': '<S2>:1' */
  /* '<S2>:1:3' if (calcSoH && prevLatch) */
  if (SOCEstimation_B.calcSoH && SOCEstimation_B.sf_SOC_ReadFromEEPROM.PrevLatch)
  {
    /* '<S2>:1:4' SoH2 = single((single(capLatch) / single(insCap)) / Tcomp) * 100; */
    rtb_SoH2 = (real32_T)SOCEstimation_B.capLatch / (real32_T)
      SOCEstimation_U.CC_Inputs.InstalledCapacity_mAh / (real32_T)
      SOCEstimation_B.sf_SOC_ReadFromEEPROM.TcompPersist * 100.0F;
    SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoH2 = rtb_SoH2;                          //manual changes
    SOCEstimation_B.calcSoH                    =  false; 
  } else {
    /* '<S2>:1:5' else */
    /* '<S2>:1:6' SoH2 = prevSoH2; */
    rtb_SoH2 = SOCEstimation_B.sf_SOC_ReadFromEEPROM.SoH2;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* BusCreator: '<S1>/Bus Creator1' incorporates:
   *  Outport: '<Root>/CC_Outputs'
   */
  SOCEstimation_Y.CC_Outputs.Total_CapacityRemains_mAh =
    SOCEstimation_B.TotalCapacityRemains_mAh;
  SOCEstimation_Y.CC_Outputs.CC_State = SOCEstimation_DW.CCState_k;
  SOCEstimation_Y.CC_Outputs.MaxUsableCapacity_mAh = rtb_Switch;
  SOCEstimation_Y.CC_Outputs.SOH_pct = SOCEstimation_B.Switch;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_SoH2 > 100.0F) {
    /* BusCreator: '<S1>/Bus Creator1' incorporates:
     *  Outport: '<Root>/CC_Outputs'
     */
    SOCEstimation_Y.CC_Outputs.SoH2 = 100.0F;
  } else if (rtb_SoH2 < 0.0F) {
    /* BusCreator: '<S1>/Bus Creator1' incorporates:
     *  Outport: '<Root>/CC_Outputs'
     */
    SOCEstimation_Y.CC_Outputs.SoH2 = 0.0F;
  } else {
    /* BusCreator: '<S1>/Bus Creator1' incorporates:
     *  Outport: '<Root>/CC_Outputs'
     */
    SOCEstimation_Y.CC_Outputs.SoH2 = rtb_SoH2;
  }

  /* End of Saturate: '<S1>/Saturation' */
}

/* Model initialize function */
void SOCEstimation_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SOCEstimation_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &SOCEstimation_B), 0,
                sizeof(B_SOCEstimation_T));

  /* states (dwork) */
  (void) memset((void *)&SOCEstimation_DW, 0,
                sizeof(DW_SOCEstimation_T));

  /* external inputs */
  (void)memset(&SOCEstimation_U, 0, sizeof(ExtU_SOCEstimation_T));
  SOCEstimation_U.CellBalancingOutput = SOCEstimation_rtZCellBalancingO;

  /* external outputs */
  SOCEstimation_Y.CC_Outputs = SOCEstimation_rtZCC_OutputsBus;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  SOCEstimation_DW.CapacityRemains_mAh = 0;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  SOCEstimation_DW.CCState_k = Vehicle_at_Rest;

  /* SystemInitialize for DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  Outport: '<S5>/MaxUsableCapacity'
   */
  SOCEstimation_B.Effectiveusablecapacity = 0;

  /* SystemInitialize for Switch: '<S5>/Switch' incorporates:
   *  Outport: '<S5>/SOH_pct'
   */
  SOCEstimation_B.Switch = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S1>/SoH calculation' */

  /* SystemInitialize for MATLAB Function: '<S6>/MATLAB Function' */
  SOCEstimation_DW.counter_not_empty = false;

  /* SystemInitialize for Chart: '<S3>/IntegCurrent' */
  SOCEstimation_B.IntegratedCurrent = 0.0F;
  SOCEstimation_DW.is_active_c42_SOCEstimation = 0U;
  SOCEstimation_DW.is_c42_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S3>/SOC_Calibration' */
  SOCEstimation_DW.temporalCounter_i1 = 0U;
  SOCEstimation_B.capLatch = 0;
  SOCEstimation_B.TotalCapacityRemains_mAh = 0;
  SOCEstimation_Y.CC_Outputs.Initial_Capacity_mAh = 0;
  SOCEstimation_B.calcSoH = false;
  SOCEstimation_DW.latchMake = false;
  SOCEstimation_DW.is_active_c15_SOCEstimation = 0U;
  SOCEstimation_DW.is_c15_SOCEstimation = SOCEstimatio_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S3>/Modulus IntegCurrent' */
  SOCEstimation_B.ModIntegratedCurrent = 0.0F;
  SOCEstimation_DW.is_active_c20_SOCEstimation = 0U;
}

/* Model terminate function */
void SOCEstimation_terminate(void)
{
  /* (no terminate code required) */
}
