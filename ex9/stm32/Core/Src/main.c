/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
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
#include "software_timer.h"
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//khai bao bien
extern int led_buffer[];
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;


int scroll_index = 0;

uint8_t matrix_buffer[8] = {
	    0x18,  // 00011000
	    0x24,  // 00100100
	    0x24,  // 00100100
	    0x7E,  // 01111110
	    0x7E,  // 01111110
	    0x42,  // 01000010
	    0x42,  // 01000010
		0x42,


};

uint8_t full_matrix_buffer[16] = {
    0x00, // 0 - Hàng trống dưới cùng
    0x00, // 1
    0x00, // 2
    0x00, // 3
    0x18, // 4  - Dữ liệu chữ "A" bắt đầu từ đây
    0x24, // 5
    0x24, // 6
    0x7E, // 7
    0x7E, // 8
    0x42, // 9
    0x42, // 10
    0x42, // 11
    0x00, // 12 - Hàng trống trên cùng
    0x00, // 13
    0x00, // 14
    0x00  // 15
};



//end khai bao bien


//khai bao ham
void display7SEG(int num){
		 		  switch (num){

		 		  case 0: //so 0

		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);

		 			 	 		  break;
		 		  case 1: //so 1



		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);

		 			 	 		  break;
		 		  case 2: //so 2



		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);

		 			 	 		  break;

		 		  case 3: //so 3



		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
		 			 	 		  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);

		 			 	 		  break;
		 		  case 4: //so 4
								  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
								  break;
		 		  case 5: //so 5
								  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
								  break;
		 		  case 6: //so 6
								  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
								  break;
		 		  case 7: //so 7
								  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
								  break;
		 		  case 8: //so 8
								  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
								  break;
		 		  case 9: //so 9
								  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
								  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
								  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
								  break;

		 		  default:
		 			  	  	  	  break;

		 		  }

}

void updateLEDMatrix(int index) {
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin, GPIO_PIN_SET); // Tắt tất cả cột
    switch (index) {
        case 0: HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_RESET); break;
        case 1: HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_RESET); break;
        case 2: HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_RESET); break;
        case 3: HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_RESET); break;
        case 4: HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_RESET); break;
        case 5: HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_RESET); break;
        case 6: HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_RESET); break;
        case 7: HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_RESET); break;
        default: break;
    }
    //on/off cac led tren hang dua tren phan tu cua matrix_buffer
    HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (matrix_buffer[index] & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (matrix_buffer[index] & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (matrix_buffer[index] & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (matrix_buffer[index] & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (matrix_buffer[index] & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (matrix_buffer[index] & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (matrix_buffer[index] & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (matrix_buffer[index] & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);


}

//2 cham chinh giua down
//void shiftDown() {
//    uint8_t last_row = matrix_buffer[7];  // Lưu hàng cuối cùng
//    for (int i = 7; i > 0; i--) {
//        matrix_buffer[i] = matrix_buffer[i - 1];  // Dịch từng hàng xuống
//    }
//    matrix_buffer[0] = last_row;  // Đưa hàng cuối lên đầu
//}


void updateMatrixBuffer() {
    for (int i = 0; i < 8; i++) {
        int idx = i + scroll_index;
        if (idx >= 0 && idx < 16) {
            matrix_buffer[i] = full_matrix_buffer[idx];
        } else {
            matrix_buffer[i] = 0x00; // Hàng trống
        }
    }
}




//end khai bao ham
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  int hour = 12 , minute = 4 , second = 50;
  const int MAX_LED = 4;
  	setTimer1(500);
  	setTimer2(100);
  	setTimer0(100);
  	setTimer3(100);
  	setTimer4(100);
  	int index_led = 0;
  	int index_led8x8 = 0;
  while (1)
  {
	  if(timer1_flag == 1){
		  index_led++;
		  switch(index_led){
		  case 1:

			  display7SEG(led_buffer[0]);

		  	  HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
			  HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
			  HAL_GPIO_WritePin(GPIOA, EN2_Pin, 1);
			  HAL_GPIO_WritePin(GPIOA, EN3_Pin, 1);

			  break;
		  case 2:
			  display7SEG(led_buffer[1]);


			  HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
			  HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
			  HAL_GPIO_WritePin(GPIOA, EN2_Pin, 1);
			  HAL_GPIO_WritePin(GPIOA, EN3_Pin, 1);

			  break;
		  case 3:
			  display7SEG(led_buffer[2]);


			  HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
			  HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
			  HAL_GPIO_WritePin(GPIOA, EN2_Pin, 0);
			  HAL_GPIO_WritePin(GPIOA, EN3_Pin, 1);

			  break;
		  case 4:
			  display7SEG(led_buffer[3]);


				  HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
				  HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
				  HAL_GPIO_WritePin(GPIOA, EN2_Pin, 1);
				  HAL_GPIO_WritePin(GPIOA, EN3_Pin, 0);

				  break;

			  default:
				  break;
		  }
				 if(index_led >= MAX_LED){
					 index_led = 0;
				 }
				 setTimer1(500);

	  } //end if


	  //timer2_flag manages clock logic
	  	  if(timer2_flag == 1){
	  		  second++;

	  		  if ( second >= 60) {
	  		  	   second = 0;
	  		  	   minute ++;
	  		 }
	  		  if( minute >= 60) {
	  		  	   minute = 0;
	  		  	   hour ++;
	  		 }
	  		  if( hour >= 24) {
	  		  	   hour = 0;
	  		 }
	  		 updateClockBuffer(hour, minute);
	  		 setTimer2(100);
	  	  }

	  	  	 if(timer0_flag == 1){
		  		  HAL_GPIO_TogglePin(DOT_GPIO_Port , DOT_Pin);
				  HAL_GPIO_TogglePin(GPIOA, LR_Pin);
				  setTimer0(100);
	  	  	 }


	  	  	if (timer3_flag == 1) {
	  	  	    scroll_index++;
	  	  	    if (scroll_index > 8) { // 16 (kích thước mảng) - 8 (kích thước ma trận LED)
	  	  	        scroll_index = 0;
	  	  	    }
	  	  	    updateMatrixBuffer();
	  	  	    setTimer3(100);
	  	  	}


	  	  	if(timer4_flag == 1){
				  updateLEDMatrix(index_led8x8);
				  	  	  		index_led8x8++;
				  	  	  		if(index_led8x8 >= MAX_LED_MATRIX ){
				  	  	  			index_led8x8 = 0;
				  	  	  		}
				  	  	  		setTimer4(2);
	  	  	}


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
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
  * @brief TIM2 Initialization Function
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
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1;
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LR_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LR_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LR_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timer_run();

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
