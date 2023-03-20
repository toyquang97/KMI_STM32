#ifndef __BUTTON_H
#define __BUTTON_H
#include "main.h"
#include <stdio.h>
#include "stdbool.h"
extern alarmType_t gAlarmSys;
extern userInput_t gUserSetInput;
extern userInput_t gUserSaveDataTemp;
extern float gAsphaltTemp;
extern float gCombustionTemp;
extern float gVoltageBattery;

typedef enum 
{
    IPRESS,
    HOLD,
    DOUBLECLICK,
} buttonWorking_t;

typedef struct 
{
    bool button1;
    bool button2;
    bool button3;
    bool button4;
    bool eStopEmergency;
    bool enableBurner;
}buttonCall_t;

void readButtonWorking(buttonCall_t *pButton);
void burnerWorkingCondition(buttonCall_t pButton);
void emergencyStopWorking(void);
void turnOffBuzzer(void);
void turnOnBuzzer(void);

#endif
