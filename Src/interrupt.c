#include "main.h"
#include "stdbool.h"

extern TIM_HandleTypeDef htim6;
uint8_t count = 0;
extern tickTimer gFlagTimer;

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
}
