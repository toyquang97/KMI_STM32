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
#define DELAY_TIME_USER 500

void onScreenDisplay(void);
void changeUnitTemperature(void);
void reloadPageNeeded(void);
void setPasswordReset(void);
void setBunerDelaySetpoint(void);
void setAsphaltSetpoint(uint8_t index);
void setCombustionSetpoint(uint8_t index);
void setBunerDelayTimeSetpoint(uint8_t index);
void setBlinkIndexUser(uint8_t index[][2], uint8_t count);
void increaseValueSetpoint(uint8_t index, uint16_t *pGetValue);
void isConfirmOk(uint8_t *pIndex);
void isConfirmESC(uint8_t *pIndex);
void readLoadInputUserType(uint8_t index);
#endif
