/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "kmi_display.h"
#include"MAX31855.h"
#include"adc.h"
#include "stdbool.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
float temp = 0;
float voltage = 0;
	bool a = 0, b = 0, c = 0 , d= 0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  temp = Max31855_Read_Temp(hspi2);
  voltage = analogRead(hadc);
  /*LCD*/
	HAL_GPIO_WritePin(RW_GPIO_Port,RW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CONTRAST_GPIO_Port,CONTRAST_Pin, GPIO_PIN_SET);

  kmi_display_init();
  kmi_change_display(STARTUP_PAGE);
  HAL_Delay(1000);
  kmi_change_display(ARLARM_PAGE);
  HAL_Delay(1000);
 kmi_change_display(HOME_PAGE);




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		kmi_change_display(MENU_PAGE);
  HAL_Delay(1000);
#if 0
    if (HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin) == GPIO_PIN_RESET)
    {
      switch (state1)
      {
      case STARTUP_PAGE:
        kmi_change_display(MENU_PAGE);
        break;
      case MENU_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case SETTINGS_PAGE:
        kmi_change_display(RUNTIMES_PAGE);
        break;
      case RUNTIMES_PAGE:
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case CP_RESET_AUTH_PAGE:
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case BURNER_RESET_AUTH_PAGE:
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case BURNER_RUNTIMES_PAGE:
        kmi_change_display(BURNER_RESET_AUTH_PAGE);
        break;
      case CP_RUNTIMES_PAGE:
        kmi_change_display(CP_RESET_AUTH_PAGE);
        break;
      case IO_DIAGNOSTICS_1_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_2_PAGE);
        break;
      case IO_DIAGNOSTICS_2_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_3_PAGE);
        break;
      case IO_DIAGNOSTICS_3_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_4_PAGE);
        break;
      case IO_DIAGNOSTICS_4_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_1_PAGE);
        break;
      case ANALOG_PAGE:
        kmi_change_display(BURNER_PAGE);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(ASPHALT_SETPOINTS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;

      default:
        break;
      }
    }
    ////Button2////
    if (HAL_GPIO_ReadPin(BT2_GPIO_Port, BT2_Pin) == GPIO_PIN_RESET)
    {
      switch (state1)
      {
      case MENU_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_1_PAGE);
        break;
      case RUNTIMES_PAGE:
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case TEMP_PAGE:
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(ASPHALT_SETPOINTS_PAGE);
        break;
      case SETTINGS_PAGE:
        kmi_change_display(BURNER_DELAY_SETTINGS_PAGE);
        break;
      default:
        break;
      }
    }
    ////Button3////
    if (HAL_GPIO_ReadPin(BT3_GPIO_Port, BT3_Pin) == GPIO_PIN_RESET)
    {
      switch (state1)
      {
      case MENU_PAGE:
        voltage = analogRead(hadc);
        kmi_display_voltage(voltage);
        break;
      case SETTINGS_PAGE:
        kmi_change_display(TEMP_PAGE);
        break;
      case ANALOG_PAGE:
        kmi_change_display(ASPHALT_PAGE);
        break;
      case TEMP_PAGE:
        temp = Max31855_Read_Temp(hspi2);
        kmi_change_display(TEMP_UNIT_PAGE);
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(ASPHALT_SETPOINTS_PAGE);
        break;
      default:
        break;
      }
    }
    ////Button4////
    if (HAL_GPIO_ReadPin(BT4_GPIO_Port, BT4_Pin) == GPIO_PIN_RESET)
    {
      switch (state1)
      {
      case MENU_PAGE:
        kmi_change_display(HOME_PAGE);
        break;
      case SETTINGS_PAGE:
      case IO_DIAGNOSTICS_1_PAGE:
      case IO_DIAGNOSTICS_2_PAGE:
      case IO_DIAGNOSTICS_3_PAGE:
      case IO_DIAGNOSTICS_4_PAGE:
      case VOLTAGE_PAGE:
      case ANALOG_PAGE:
      case HOME_PAGE:
        kmi_change_display(MENU_PAGE);
        break;
      case TEMP_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case TEMP_UNIT_PAGE:
        kmi_change_display(TEMP_PAGE);
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(TEMP_PAGE);
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case RUNTIMES_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case CP_RESET_AUTH_PAGE:
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case BURNER_RESET_AUTH_PAGE:
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case BURNER_RUNTIMES_PAGE:
        kmi_change_display(RUNTIMES_PAGE);
        break;
      case CP_RUNTIMES_PAGE:
        kmi_change_display(RUNTIMES_PAGE);
        break;
      case BURNER_PAGE:
        kmi_change_display(ANALOG_PAGE);
        break;
      case ASPHALT_PAGE:
        kmi_change_display(ANALOG_PAGE);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      default:
        break;
      }
    }
		#endif
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted. 
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_SLAVE;
  hspi2.Init.Direction = SPI_DIRECTION_1LINE;
  hspi2.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, Buzzer_Pin|D5_Pin|D4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_4|GPIO_PIN_5|D7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|D6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SPI_CS1_Pin|BL_Pin|EN_Pin|RW_Pin 
                          |RS_Pin|CONTRAST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Buzzer_Pin D5_Pin D4_Pin */
  GPIO_InitStruct.Pin = Buzzer_Pin|D5_Pin|D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : BT2_Pin BT1_Pin */
  GPIO_InitStruct.Pin = BT2_Pin|BT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PF4 PF5 D7_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 D6_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|D6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SPI_CS1_Pin BL_Pin EN_Pin RW_Pin 
                           RS_Pin CONTRAST_Pin */
  GPIO_InitStruct.Pin = SPI_CS1_Pin|BL_Pin|EN_Pin|RW_Pin 
                          |RS_Pin|CONTRAST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI_CS2_Pin */
  GPIO_InitStruct.Pin = SPI_CS2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SPI_CS2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BT4_Pin BT3_Pin */
  GPIO_InitStruct.Pin = BT4_Pin|BT3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
