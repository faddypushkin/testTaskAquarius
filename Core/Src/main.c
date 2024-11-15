/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @author Dmitriy Stepanenko
  * @date November 2024 
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
TIM_HandleTypeDef htim2;			///<	Variable where timer (TIM2) settings are stored

UART_HandleTypeDef huart1;			///< Variable where UART (USART1) settings are stored

/* USER CODE BEGIN PV */
int firstPartOfMessage = 0;         ///< Flag responsible for the first part of the message
int secondPartOfMessage = 0;        ///< Flag responsible for the second part of the message

char message[5] = "00000";          ///< Variable for storing the received message
char code[6] = "000000";            ///< Variable for storing the code

char firstPartOfCode[3] = "000";    ///< Variable for storing the first part of the message
char secondPartOfCode[3] = "000";   ///< Variable for storing the second part of the message

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
void selectMessage(void);
void analysisMessage(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  * 
  * Code after initialize all configured parameters
  * @code
  * HAL_TIM_Base_Start_IT(&htim2);
  * 
  * while (1){
  *     HAL_UART_Receive_IT(&huart1, message, 5);
  * 
  *     selectMessage();
  * }
  * @endcode
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
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  HAL_TIM_Base_Start_IT(&htim2);

  while (1)
  {
    /* USER CODE END WHILE */
      
    /* USER CODE BEGIN 3 */
      HAL_UART_Receive_IT(&huart1, message, 5);

      selectMessage();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * 
  * Processor frequency - 80 MHz\n
  * 
  * Other settings are standard for CubeMX
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * 
  * Processor frequency - 80 MHz;\n
  * Prescaler = 40000-1;\n
  * Period = 7200000;\n
  * 
  * =>Counter fills up in an hour\n
  * 
  * Other settings are standard for CubeMX
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 40000-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 7200000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * 
  * Baud Rate = 9600 Bits/s;\n
  * Word Length = 8 Bits;\n
  * Stop Bits = 1;\n
  * 
  * Other settings are standard for CubeMX
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * 
  * Settings are standard for CubeMX
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/**
 * @brief Select messages function
 * 
 * Function that determines what part of the code was sent
 * @param None
 * @retval None
 * 
 * @code
 * if (message[0] == '1') {
 *       firstPartOfMessage = 1;
 *       for (int i = 0; i != 3; ++i) {
 *           firstPartOfCode[i] = message[i + 2];
 *       }
 *   }
 *   else if (message[0] == '2') {
 *       secondPartOfMessage = 1;
 *       for (int i = 0; i != 3; ++i) {
 *           secondPartOfCode[i] = message[i + 2];
 *       }
 *   }
 * @endcode
 */
void selectMessage(void) {
    if (message[0] == '1') {
        firstPartOfMessage = 1;
        for (int i = 0; i != 3; ++i) {
            firstPartOfCode[i] = message[i + 2];
        }
    }
    else if (message[0] == '2') {
        secondPartOfMessage = 1;
        for (int i = 0; i != 3; ++i) {
            secondPartOfCode[i] = message[i + 2];
        }
    }
}

/**
 * @brief Analyzes messages function
 * 
 * Function that analyzes messages that have arrived in the last hour and sends a response
 * @param None
 * @retval None
 *
 * @code
 * if ((firstPartOfMessage == 1) && (secondPartOfMessage == 0)) {
 *       HAL_UART_Transmit_IT(&huart1, (uint8_t)"There is no the second part of the code\n", (uint16_t)40);
 *   }
 *   else if ((firstPartOfMessage == 0) && (secondPartOfMessage == 1)) {
 *       HAL_UART_Transmit_IT(&huart1, (uint8_t)"There is no the first part of the code\n", (uint16_t)39);
 *   }
 *   else if ((firstPartOfMessage == 1) && (secondPartOfMessage == 1)) {
 *       HAL_UART_Transmit_IT(&huart1, (uint8_t)"There are all parts of the code\n", (uint16_t)32);
 *       firstPartOfMessage = 0;
 *       secondPartOfMessage = 0;
 *
 *       for (int i = 0; i != 3; ++i) {
 *           code[i] = firstPartOfCode[i];
 *       }
 *
 *       for (int i = 0; i != 3; ++i) {
 *           code[i + 3] = secondPartOfCode[i];
 *       }
 *   }
 * @endcode
 */
void analysisMessage(void) {
    if ((firstPartOfMessage == 1) && (secondPartOfMessage == 0)) {
        HAL_UART_Transmit_IT(&huart1, (uint8_t)"There is no the second part of the code\n", (uint16_t)40);
    }
    else if ((firstPartOfMessage == 0) && (secondPartOfMessage == 1)) {
        HAL_UART_Transmit_IT(&huart1, (uint8_t)"There is no the first part of the code\n", (uint16_t)39);
    }
    else if ((firstPartOfMessage == 1) && (secondPartOfMessage == 1)) {
        HAL_UART_Transmit_IT(&huart1, (uint8_t)"There are all parts of the code\n", (uint16_t)32);
        firstPartOfMessage = 0;
        secondPartOfMessage = 0;

        for (int i = 0; i != 3; ++i) {
            code[i] = firstPartOfCode[i];
        }

        for (int i = 0; i != 3; ++i) {
            code[i + 3] = secondPartOfCode[i];
        }
    }
}

/**
 * @brief Internal interrupt that fires every hour and calls the analysisMessage function
 * @param None
 * @retval None
 *
 * @code
 * if (htim->Instance == TIM2)
 *   {
 *       analysisMessage();
 *   }
 * @endcode
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM2)
    {
        analysisMessage();
    }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
