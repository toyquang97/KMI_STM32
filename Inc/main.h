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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Buzzer_Pin GPIO_PIN_13
#define Buzzer_GPIO_Port GPIOC
#define BT2_Pin GPIO_PIN_14
#define BT2_GPIO_Port GPIOC
#define BT1_Pin GPIO_PIN_15
#define BT1_GPIO_Port GPIOC
#define SPI_CS1_Pin GPIO_PIN_10
#define SPI_CS1_GPIO_Port GPIOB
#define SPI_CS2_Pin GPIO_PIN_11
#define SPI_CS2_GPIO_Port GPIOB
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

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
