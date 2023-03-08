#include "main.h"
#include "stdbool.h"

extern TIM_HandleTypeDef htim6;
extern bool gFlagReadInput5ms;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
 if(htim->Instance == htim6.Instance)
 {
   gFlagReadInput = 1;
 }
}