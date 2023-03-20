/*************************************************************************************
 Title	 :  MAXIM Integrated MAX31855 Library for STM32 Using HAL Libraries
 Author  :  Bardia Alikhan Afshar <bardia.a.afshar@gmail.com>
 Software:  STM32CubeIDE
 Hardware:  Any STM32 device
*************************************************************************************/
#include"MAX31855.h"
extern userInput_t gUserSaveDataTemp;
// ------------------- Functions ----------------
uint32_t readThermocoupleData(chamberType_t type)
{
	uint32_t rawdata = 0;												   // Temperature Variable
	if (type == ASPHALT)
	{
		HAL_GPIO_WritePin(SPI_CS1_GPIO_Port, SPI_CS1_Pin, GPIO_PIN_RESET); // Low State for SPI Communication
	}
	else
	{
		HAL_GPIO_WritePin(SPI_CS2_GPIO_Port, SPI_CS2_Pin, GPIO_PIN_RESET); // Low State for SPI Communication
	}
	
	for (int i = 31; i >= 0; i--)
	{
		HAL_GPIO_WritePin(SPI_SCK_GPIO_Port, SPI_SCK_Pin, GPIO_PIN_SET);
		rawdata = rawdata << 1;
		rawdata |= HAL_GPIO_ReadPin(SPI_DATA_GPIO_Port, SPI_DATA_Pin) & 1;
		HAL_GPIO_WritePin(SPI_SCK_GPIO_Port, SPI_SCK_Pin, GPIO_PIN_RESET);
	}
	if (type == ASPHALT)
	{
		HAL_GPIO_WritePin(SPI_CS1_GPIO_Port, SPI_CS1_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(SPI_CS2_GPIO_Port, SPI_CS2_Pin, GPIO_PIN_SET);
	}
																	 	
	return rawdata; 	
}

errorType_t getErrorType(uint32_t rawData)
{
	if(rawData & 0x01) 	return NO_CONNECT;
	if(rawData & 0x02) 	return SHORT_GND;
	if(rawData & 0x04) 	return SHORT_VCC;
	return NONE;
}

float getTemperatureData(chamberType_t type, errorType_t *pError)
{
	uint32_t tempData = 0;
	uint32_t rawData = 0;

	rawData = readThermocoupleData(type);
	*pError = getErrorType(rawData);
	if(rawData & BIT16)
	{
		return -999;
	}
	tempData = (rawData >> 18) & 0x1FFF; // get data bit 18 -> bit 30
	if (rawData >> 31) // get sign
	{
		tempData = (~tempData + 1) & 0x1FFF;
		return (-((float)tempData * 0.25));
	}
	return  ((float)tempData * 0.25); 
}

float getInternalTempratureData(chamberType_t type)
{
	uint32_t tempData = 0;
	uint32_t rawData = 0;

	rawData = readThermocoupleData(type);
	tempData = (rawData >> 4) & 0x7FF; // get data bit 4 -> bit 14
	if ((rawData >> 15) & 1) // get sign
	{
		tempData = (~tempData + 1) & 0x7FF;
		return (-((float)tempData * 0.0625));
	}
	return  ((float)tempData * 0.0625); 	
}

bool checkFrameData(uint32_t rawData)
{
	if(rawData & BIT17 || rawData & BIT3)	return false;
	return true;
}

void calibTempratueData(uint32_t *pTemp, uint32_t internalData)
{

}

void convertUnitTemperature(float *pAsphastTemp, float *pCombustionTemp, userInput_t type)
{
  if (type.temperatureUnit == FAHRENHEIT)
  {
    *pAsphastTemp    = (*pAsphastTemp) * 1.8 + 32;
    *pCombustionTemp = (*pCombustionTemp) * 1.8 + 32;
  }
}

void convertDataRunTime(userInput_t *pData)
{
  if (pData->temperatureUnit == FAHRENHEIT)
  {
    pData->targetTempAsphaltSet    = (pData->targetTempAsphaltSet) * 1.8 + 32;
    pData->lowEnableAsphaltSet     = (pData->lowEnableAsphaltSet) * 1.8 + 32;
    pData->overTempCombustionAlarm = (pData->overTempCombustionAlarm) * 1.8 + 32;
  }
  else if (pData->temperatureUnit == CELSIUS)
  {
	pData->targetTempAsphaltSet    = ((pData->targetTempAsphaltSet)   - 32) / 1.8;
    pData->lowEnableAsphaltSet     = ((pData->lowEnableAsphaltSet)    - 32) / 1.8;
    pData->overTempCombustionAlarm = ((pData->overTempCombustionAlarm)- 32) / 1.8;
  }
  
}

void readBothSensor(float *pAsphastTemp, float *pCombustionTemp, userInput_t type, errorType_t *pErrAsphalt, errorType_t *pErrCombustion)
{
	*pAsphastTemp 	 = getTemperatureData(ASPHALT, pErrAsphalt);
	*pCombustionTemp = getTemperatureData(COMBUSTION, pErrCombustion);
	convertUnitTemperature(pAsphastTemp, pCombustionTemp, type);
}

void sensorInit(void)
{
	HAL_GPIO_WritePin(SPI_CS1_GPIO_Port, SPI_CS1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SPI_CS2_GPIO_Port, SPI_CS2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SPI_SCK_GPIO_Port, SPI_SCK_Pin, GPIO_PIN_RESET);
}
