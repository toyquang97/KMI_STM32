#ifndef __STATEMACHINE_H
#define __STATEMACHINE_H

#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "kmi_display.h"
#include "button.h"
#include "lcd.h"
#include "flash.h"

extern uint8_t state1;
extern buttonCall_t gButton;
extern alarmType_t gAlarmSys;
extern float gAsphaltTemp;
extern float gCombustionTemp;
extern float gVoltageBattery;
extern userInput_t gUserSetInput;
extern userInput_t gUserSaveDataTemp;
extern userInput_t userDefaultValue;
extern errorType_t asphErrorTher;
extern errorType_t combErrorTher;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim15;

#define DELAY_TIME_USER 250

void onScreenDisplay(void);
void changeUnitTemperature(void);
void reloadPageNeeded(void);
void setPasswordReset(uint8_t index);
void setBunerDelaySetpoint(uint8_t index);
void setAsphaltSetpoint(uint8_t index);
void setCombustionSetpoint(uint8_t index);
void setBunerDelayTimeSetpoint(uint8_t index);
void setBlinkIndexUser(uint8_t index[][2], uint8_t count);
void increaseValueSetpoint(uint8_t index, uint16_t *pGetValue);
void isConfirmOk(uint8_t *pIndex);
void isConfirmESC(uint8_t *pIndex);
void readLoadInputUserType(uint8_t index);
void setPoisitionBlinkCursor(uint8_t index[][2] ,uint8_t *pIndex, uint8_t size);
void getPasswordReset(uint8_t index, uint32_t *pGetValue);
void isResetRunTime(void);
void killSystemWorking(void);
void checkAlarmSystem(void);
void setLowVoltageSetpoint(uint8_t index);
void getLowVoltageSetpoint(uint8_t index, uint16_t *pGetValue);
#endif
