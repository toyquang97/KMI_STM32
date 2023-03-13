#include "button.h"

void readButtonWorking(buttonCall_t *pButton)
{
    pButton->button1 = HAL_GPIO_ReadPin(BT1_GPIO_Port,BT1_Pin);
    pButton->button2 = HAL_GPIO_ReadPin(BT2_GPIO_Port,BT2_Pin);
    pButton->button3 = HAL_GPIO_ReadPin(BT3_GPIO_Port,BT3_Pin);
    pButton->button4 = HAL_GPIO_ReadPin(BT4_GPIO_Port,BT4_Pin);
    pButton->eStopEmergency = HAL_GPIO_ReadPin(E_STOP_GPIO_Port,E_STOP_Pin);
    pButton->enableBurner = HAL_GPIO_ReadPin(SW_BUNRNER_GPIO_Port,SW_BUNRNER_Pin);
}
