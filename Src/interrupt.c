#include "main.h"
#include "stdbool.h"

extern TIM_HandleTypeDef htim6;
extern bool gFlagReadInput5ms;
extern bool gFlagReadInput10ms;
extern bool gFlagReadInput50ms;
extern bool gFlagReadInput100ms;
extern bool gFlagReadInput500ms;
uint8_t count = 0;

// typestruct struct timer
// {
// 	uint8_t Time_5ms : 1;	// 10ms 
// 	uint8_t Time_10ms : 1;	// 10ms 
// 	uint8_t Time_50ms : 1;	// 50ms 
// 	uint8_t Time_100ms : 1; // 100ms 
// 	uint8_t Time_500ms : 1; // 500ms 
// } tickTimer;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
 if(htim->Instance == htim6.Instance)
 {
     gFlagReadInput5ms = 1;
     count++;
     if ((count % 2) == 0)
     {
         gFlagReadInput10ms = 1;
         //tickTimer.Time_10ms = 1;
     }
     if ((count % 10) == 0)
     {
         gFlagReadInput50ms = 1;
         //tickTimer.Time_50ms = 0;
         if (count % 30 == 0)
         {
             gFlagReadInput100ms = 1;
             //tickTimer.Time_100ms = 1;
         }
         if ((count % 100) == 0)
         {
            gFlagReadInput500ms = 1;
            //tickTimer.Time_500ms = 1;
         }
     }
 }
}
