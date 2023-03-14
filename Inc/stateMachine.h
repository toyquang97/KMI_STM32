#ifndef __STATEMACHINE_H
#define __STATEMACHINE_H

#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "kmi_display.h"
#include "button.h"
extern uint8_t state1;
extern buttonCall_t gButton;

void onScreenDisplay(void);
void changeUnitTemperature(void);
void reloadPageNeeded(void);
#endif
