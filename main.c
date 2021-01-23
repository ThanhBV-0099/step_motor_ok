/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
uint16_t goc=0;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define dir_ox DIR_1_GPIO_Port,DIR_1_Pin
#define step1_ox STEP_1_GPIO_Port,STEP_1_Pin
#define dir_oz DIR_2_GPIO_Port,DIR_2_Pin
#define step1_oz STEP_2_GPIO_Port,STEP_2_Pin
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
uint16_t time_ox,time_oz,sobuoc_ox,sobuoc_oz,sp_ox,sp_oz,value_ox,value_oz;
uint16_t c_enc1,c_enc,enc1,enc;
uint16_t tocdo_ox=100, tocdo_oz=50;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void abc(void)
{
	if(value_ox==0)
	{
		HAL_GPIO_WritePin(dir_ox,GPIO_PIN_RESET);
		if(sp_ox>=tocdo_ox)  // speed : 100
		{
		sp_ox=0;
		sobuoc_ox++;
		HAL_GPIO_TogglePin(step1_ox);
		}
		else
		{
			sp_ox++;
		}
	}
		if(sobuoc_ox==400)  // 1 vong 400
		{
			time_ox++;
			value_ox=1;
		}
		if(time_ox>=10000)  // delay
		{
			value_ox=0;
			time_ox=0;
			sobuoc_ox=0;
			sp_ox=tocdo_ox;
		}
		
		if(value_oz==0)
		{
		if(sp_oz>=tocdo_oz)  // speed : 100
		{
		sp_oz=0;
		sobuoc_oz++;
		HAL_GPIO_TogglePin(step1_oz);
		}
		else
		{
			sp_oz++;
		}
		}
		if( sobuoc_oz==1600)
		{
		time_oz++;	
		if(enc1==0)
		{
			value_oz=1;
			enc1=1;
			c_enc1++;
	}
}
		else
		{
			enc1=0;
		}
//		//if(i1==400)  // 1 vong 400
//		{
//			b1++;
//			a1=1;
//		}
		if(time_oz>=10000) //delay
		{
//			if(c_enc1<10)
			{
			value_oz=0;
			time_oz=0;
			sobuoc_oz=0;
			sp_oz=tocdo_oz;
			}
//			else
//			{
//			value_oz=1;
//			}
		}
}


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
  /* USER CODE BEGIN 2 */
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		abc();
//		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		//for(int16_t i=0;i<2025;i++)
//	if(goc==0)
//		{
//		for(uint16_t i=0;i<400;i++)
//		{
//			HAL_GPIO_WritePin(step,GPIO_PIN_SET);
//			speed();
//			HAL_GPIO_WritePin(step,GPIO_PIN_RESET);
//			speed();
//		}
//		break;
		
//	}
//		else if(goc==1)
//		{
//				for(uint16_t y=0;y<100;y++)
//		{
//			HAL_GPIO_WritePin(step,GPIO_PIN_SET);
//			HAL_Delay(1);
//			HAL_GPIO_WritePin(step,GPIO_PIN_RESET);
//			HAL_Delay(1);
//		}
//	}
		//HAL_Delay(1000);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, STEP_2_Pin|DIR_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, STEP_1_Pin|DIR_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : STEP_2_Pin DIR_2_Pin */
  GPIO_InitStruct.Pin = STEP_2_Pin|DIR_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : STEP_1_Pin DIR_1_Pin */
  GPIO_InitStruct.Pin = STEP_1_Pin|DIR_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
