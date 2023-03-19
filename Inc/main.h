/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
#define KEEP_DEBUG 0
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BT2_Pin GPIO_PIN_14
#define BT2_GPIO_Port GPIOC
#define BT1_Pin GPIO_PIN_15
#define BT1_GPIO_Port GPIOC
#define E_STOP_Pin GPIO_PIN_0
#define E_STOP_GPIO_Port GPIOA
#define EN_BURNER_Pin GPIO_PIN_1
#define EN_BURNER_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_2
#define BUZZER_GPIO_Port GPIOA
#define BURNER_EN_Pin GPIO_PIN_4
#define BURNER_EN_GPIO_Port GPIOF
#define RL_CM_Pin GPIO_PIN_5
#define RL_CM_GPIO_Port GPIOF
#define RL_CR2_Pin GPIO_PIN_4
#define RL_CR2_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_5
#define LED1_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_6
#define LD2_GPIO_Port GPIOA
#define SPI_CS1_Pin GPIO_PIN_10
#define SPI_CS1_GPIO_Port GPIOB
#define SPI_CS2_Pin GPIO_PIN_11
#define SPI_CS2_GPIO_Port GPIOB
#define SPI_SCK_Pin GPIO_PIN_13
#define SPI_SCK_GPIO_Port GPIOB
#define SPI_DATA_Pin GPIO_PIN_14
#define SPI_DATA_GPIO_Port GPIOB
#define BT4_Pin GPIO_PIN_11
#define BT4_GPIO_Port GPIOA
#define BT3_Pin GPIO_PIN_12
#define BT3_GPIO_Port GPIOA
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOF
#define D6_Pin GPIO_PIN_15
#define D6_GPIO_Port GPIOA
#define D5_Pin GPIO_PIN_10
#define D5_GPIO_Port GPIOC
#define D4_Pin GPIO_PIN_11
#define D4_GPIO_Port GPIOC
#define D3_Pin GPIO_PIN_12
#define D3_GPIO_Port GPIOC
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOD
#define D1_Pin GPIO_PIN_3
#define D1_GPIO_Port GPIOB
#define D0_Pin GPIO_PIN_4
#define D0_GPIO_Port GPIOB
#define BL_Pin GPIO_PIN_5
#define BL_GPIO_Port GPIOB
#define EN_Pin GPIO_PIN_6
#define EN_GPIO_Port GPIOB
#define RW_Pin GPIO_PIN_7
#define RW_GPIO_Port GPIOB
#define RS_Pin GPIO_PIN_8
#define RS_GPIO_Port GPIOB
#define CONTRAST_Pin GPIO_PIN_9
#define CONTRAST_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

typedef struct _SET_POINT_
{
  uint16_t targetTempAsphaltSet;
  uint16_t lowEnableAsphaltSet;
  uint16_t overTempCombustionAlarm;
  uint16_t burnerDelaySet;
  uint16_t cpRuntime;
  uint16_t burnerRuntime;
  bool temperatureUnit;
  volatile uint32_t resetPassword;
}userInput_t;

typedef struct timer
{
	uint8_t Time_5ms : 1;	// 10ms 
	uint8_t Time_10ms : 1;	// 10ms 
	uint8_t Time_50ms : 1;	// 50ms 
	uint8_t Time_100ms : 1; // 100ms 
	uint8_t Time_500ms : 1; // 500ms 
} tickTimer;

#define USER_WRITE_SIZE (sizeof(userInput_t) - 4)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
