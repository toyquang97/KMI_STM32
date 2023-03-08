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

uint16_t rawdata;
float data;
// Used To Get ADC Value
float analogRead(ADC_HandleTypeDef hadc)
{
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
	rawdata = HAL_ADC_GetValue(&hadc);
	data = (rawdata) * (ADC_VOL_MES)*((R3 + R4) / R4);
	data = data/4096;
	return data;
}

