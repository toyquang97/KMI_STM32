/*
 * adc.c
 *
 *  Created on: Mar 5, 2023
 *      Author: PC
 */
/* Includes ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

#include "stm32f0xx_hal.h"
#include "adc.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Used To Get ADC Value
void readBatteryVoltage(ADC_HandleTypeDef hadc, float *pVoltageData)
{
	uint16_t rawdata;
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
	rawdata = HAL_ADC_GetValue(&hadc);
	*pVoltageData = (rawdata) * (ADC_VOL_MES)*((R3 + R4) / R4);
	*pVoltageData = (*pVoltageData)/4095;
	*pVoltageData = (*pVoltageData) + ((*pVoltageData)*OFFSET_VALUE);
}

bool checkLowVoltage(float voltage)
{
	if (voltage <= LOW_VOLTAGE_BATTERY)
	{
		return true;
	}
	return false;
}

