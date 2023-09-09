#include "main.h"
#include "stdbool.h"
#include "stdio.h"
#include "flash.h"

extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim15;
extern bool gTriggerBurnerWork;
extern userInput_t gUserSetInput;
extern userInput_t gUserSaveDataTemp;
uint8_t count = 0;
uint32_t count1 = 0;
uint32_t countMins = 0;
extern tickTimer gFlagTimer;
uint8_t checkButtonUnworking = 0;
uint8_t countBurnerWorkingTime = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == htim6.Instance)
  {
    count++;
    gFlagTimer.Time_5ms = 1;
    if ((count % 2) == 0)
    {
      gFlagTimer.Time_10ms = 1;
    }
    if ((count % 10) == 0)
    {
      gFlagTimer.Time_50ms = 1;
      if (count % 30 == 0)
      {
        gFlagTimer.Time_100ms = 1;
      }
      if ((count % 100) == 0)
      {
        gFlagTimer.Time_500ms = 1;
      }
    }
  }
  else if (htim->Instance == htim15.Instance) // count every 1s
  {
    count1++;
    gFlagTimer.Time_1000ms = 1;
    if ((count1 % 2) == 0)
    {
      gFlagTimer.Time_2s = 1;
      if ((count1 % 60) == 0)
      {
        gFlagTimer.Time_1m = 1;
        count1 = 0;
        countMins++;
        checkButtonUnworking++;
        if(gTriggerBurnerWork)
        {
          countBurnerWorkingTime++;
					if((countBurnerWorkingTime % 60) == 0)
					{
						gUserSaveDataTemp.burnerRuntime++;
						memcpy(&gUserSetInput, &gUserSaveDataTemp, USER_WRITE_SIZE);
						userInputWriteFlash(gUserSetInput);
						countBurnerWorkingTime = 0;
					}
        }
        if((countMins % 60) == 0)
        {
          countMins = 0;
          gFlagTimer.Time_1hr = 1;
        }
      }
    }
  }
}
