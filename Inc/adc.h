#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"

#define ADC_VOL_MES             3.2 // this one need to real measure
#define R3 			            100000
#define R4 		                10000
#define OFFSET_VALUE            0.1055       // Now is 10%, need to chose type 1% -> so 0.1 -> 0.01

#define LOW_VOLTAGE_BATTERY     11

void readBatteryVoltage(ADC_HandleTypeDef hadc, float *pVoltageData);
#endif
