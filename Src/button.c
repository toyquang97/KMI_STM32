#include "button.h"

void readButtonWorking(buttonCall_t *pButton)
{
#if (KEEP_DEBUG == 0)
    pButton->button1 = HAL_GPIO_ReadPin(BT1_GPIO_Port,BT1_Pin);
    pButton->button2 = HAL_GPIO_ReadPin(BT2_GPIO_Port,BT2_Pin);
    pButton->button3 = HAL_GPIO_ReadPin(BT3_GPIO_Port,BT3_Pin);
    pButton->button4 = HAL_GPIO_ReadPin(BT4_GPIO_Port,BT4_Pin);
    pButton->eStopEmergency = HAL_GPIO_ReadPin(E_STOP_GPIO_Port,E_STOP_Pin);
    pButton->enableBurner = HAL_GPIO_ReadPin(EN_BURNER_GPIO_Port,EN_BURNER_Pin);
    HAL_Delay(5);
#endif
}

void enableBurner(void)
{
  HAL_GPIO_WritePin(BURNER_EN_GPIO_Port,BURNER_EN_Pin,GPIO_PIN_SET);
}

void enablePowerBurner(void)
{
  HAL_GPIO_WritePin(RL_CM_GPIO_Port,RL_CM_Pin,GPIO_PIN_SET);
}

void enableLightBarWorking(void)
{
    HAL_GPIO_WritePin(RL_CR2_GPIO_Port,RL_CR2_Pin,GPIO_PIN_SET);
}

void disableBurner(void)
{
  HAL_GPIO_WritePin(BURNER_EN_GPIO_Port,BURNER_EN_Pin,GPIO_PIN_RESET);
}

void disablePowerBurner(void)
{
    HAL_GPIO_WritePin(RL_CM_GPIO_Port,RL_CM_Pin,GPIO_PIN_RESET);
}

void disableLightBarWorking(void)
{
    HAL_GPIO_WritePin(RL_CR2_GPIO_Port,RL_CR2_Pin,GPIO_PIN_RESET);
}

void emergencyStopWorking(void)
{
    disableBurner();
    disablePowerBurner();
    disableLightBarWorking();
    gTriggerAlarm = 1;
}

void burnerWorkingCondition(buttonCall_t pButton)
{
    if (pButton.enableBurner == 0)
    {
        enableBurner();
        enablePowerBurner();
        enableLightBarWorking();
    }
    else
    {
        disableBurner();
        disablePowerBurner();
        disableLightBarWorking();
    }

    if (pButton.eStopEmergency == 1)
    {
        emergencyStopWorking();
    }  
    else if(pButton.eStopEmergency == 0)
    {
        gTriggerAlarm = 0;
    }
}
