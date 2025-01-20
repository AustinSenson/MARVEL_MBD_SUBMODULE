/*
 * Code generation for system system '<S1>/SOC_ReadFromEEPROM'
 *
 * Model                      : SOCEstimation
 * Model version              : 7.19
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Sat Dec  7 16:55:25 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "SOC_ReadFromEEPROM.h"
#include "SOCEstimation_private.h"
#include "threadxMain.h"
#include "bmsConfiguration.h"
#include "controlOperations.h"

extern uint8_t debouncer;
extern coulombCountingOutput_t ccOutputDataEEPROM;
extern coulombCountingOutput_t ccOutputDataFlash;
extern coulombCountingInput_t ccInputData;
extern uint8_t eepromCorrupted;
uint8_t ReadFromFlashCounter = 0;
extern uint8_t cmuFailCounter;
extern bool SoCFromLookupTableFlag;
/* Output and update for atomic system: '<S1>/SOC_ReadFromEEPROM' */
void SOCEstimatio_SOC_ReadFromEEPROM(B_SOC_ReadFromEEPROM_SOCEstim_T *localB)
{
  if((ReadFromFlashCounter == 0) && (SoCFromLookupTableFlag == false))
  {
        //totalCapacityRemaining at end of previous power cycle will be the initial capacity for next cycle
        if(eepromCorrupted)
        {
        localB->CapacityRemains_mAh = ccOutputDataFlash.totalCapacityRemaining;     //TotalCapacityRemaining from Flash
        localB->SoH                 = ccOutputDataFlash.SOH_pct;
        localB->SoH2                = ccOutputDataFlash.SoH2_pct;
        localB->cycleCount          = ccOutputDataFlash.CycleCount;
        localB->PrevLatch           = ccOutputDataFlash.PrevLatch;
        localB->SoHCalcEn           = true;
        }
        else
        {
        localB->CapacityRemains_mAh = ccOutputDataEEPROM.totalCapacityRemaining;    //TotalCapacityRemaining from EEPROM
        localB->SoH                 = ccOutputDataEEPROM.SOH_pct;
        localB->SoH2                = ccOutputDataEEPROM.SoH2_pct;
        localB->cycleCount          = ccOutputDataEEPROM.CycleCount;
        localB->PrevLatch           = ccOutputDataEEPROM.PrevLatch;
        localB->SoHCalcEn           = true;
        // localB->CapacityRemains_mAh = 90000;
        }
        ReadFromFlashCounter = 1;
  }

  else
  {
        localB->SoHCalcEn = false;
  }
  
  if (debouncer < (CMU_FAIL_SUSPEND_COUNT + 1))
  {
        localB->TcompPersist = 1;
        debouncer++;
  }
  else
  {   
       if (debouncer == (CMU_FAIL_SUSPEND_COUNT + 1))
      {     
      //   ccOutputDataEEPROM.Tcomp = calculateTcomp(ccInputData.tMin, ccOutputDataEEPROM.CycleCount);
      //   localB->TcompPersist = ccOutputDataEEPROM.Tcomp;
        debouncer++;  
      }
      ccOutputDataEEPROM.Tcomp = calculateTcomp(ccInputData.tMin, ccOutputDataEEPROM.CycleCount);
      localB->TcompPersist     = ccOutputDataEEPROM.Tcomp;
  }
}
