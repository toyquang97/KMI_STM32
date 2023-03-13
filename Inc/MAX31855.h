/*************************************************************************************
 Title	 :  MAXIM Integrated MAX31855 Library for STM32 Using HAL Libraries
 Author  :  Bardia Alikhan Afshar <bardia.a.afshar@gmail.com>
 Software:  STM32CubeIDE
 Hardware:  Any STM32 device
*************************************************************************************/
#ifndef MAX31855_H_
#define MAX31855_H_
#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// ------------------------- Defines -------------------------
extern uint8_t Error;	   // Error Detection - 1-> No Connection / 2-> Short to GND / 4-> Short to VCC

typedef enum{
    ASPHALT,
    COMBUSTION,
}chamberType_t;

typedef enum{
    NO_CONNECT,
    SHORT_GND,
    SHORT_VCC,
    NONE,
}errorType_t;

typedef enum
{
    CELSIUS ,
    FAHRENHEIT,
}unitTempType_t;

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80
#define BIT8 0x100
#define BIT9 0x200
#define BIT10 0x400
#define BIT11 0x800
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000
#define BIT16 0x10000
#define BIT17 0x20000
#define BIT18 0x40000
#define BIT19 0x80000
#define BIT20 0x100000
#define BIT21 0x200000
#define BIT22 0x400000
#define BIT23 0x800000
#define BIT24 0x1000000
#define BIT25 0x2000000
#define BIT26 0x4000000
#define BIT27 0x8000000
#define BIT28 0x10000000
#define BIT29 0x20000000
#define BIT30 0x40000000
#define BIT31 0x80000000

// ------------------------- Functions  ----------------------
uint32_t readThermocoupleData(chamberType_t type);
float getInternalTempratureData(chamberType_t type);
float getTemperatureData(chamberType_t type);
void sensorInit(void);
bool checkFrameData(uint32_t rawData);
errorType_t getErrorType(uint8_t rawData);
void readBothSensor(float *pAsphastTemp, float *pCombustionTemp, unitTempType_t type);
void convertUnitTemperature(float *pAsphastTemp, float *pCombustionTemp, unitTempType_t type);
#endif
