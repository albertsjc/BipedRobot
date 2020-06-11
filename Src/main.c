/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "config.h"
#include "main.h"
#include "clock_init.h"
#include "led.h"
#include "debug_uart5.h"
#include "key.h"
#include "usb2uart.h"

/**
  * @brief  The application entry point.
  * @retval int
  */


int main(void)
{
	u8 test[] = "hello";
//	DXL_HandlerTypeDef DXL_Handler;
//	u8 torque_en[] = {0x40,0x00,0x01};
//  u8 param1[] = {0x74,0x00,0x00,0x02,0x00,0x00};
//	u8 param2[] = {0x74,0x00,0xF4,0x0F,0x00,0x00};
  /* MCU Configuration--------------------------------------------------------*/
  CacheEnalble();
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  SystemClock_Config();
  /* Initialize all configured peripherals */
  LED_Init();
//  Debug_UART5_Init(115200);
//	KEY_Init();
//	DXLMotor_Init(1000000);
//	USB2UART_Init(1350000);
	USB2UART_DMA_Init();
	USB2UART_Init(1350000);
	USB2UART_ReceiverTimeoutInit();
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	
//		DXL_Handler.id=0;
//		DXL_Handler.len=3+sizeof(torque_en)/sizeof(u8);	
//		DXL_Handler.Param=torque_en;
//		DXL_Handler.Ins=Write;
//		DXL_ProtocolSendData(&DXL_Handler);
  while (1)
  {
		if(READ_BIT(huart4.Instance->ISR,USART_ISR_RTOF))
		{
				SET_BIT(huart4.Instance->ICR,USART_ICR_RTOCF);
//				HAL_UART_Transmit_DMA(&huart2,test,5);
//				while(__HAL_DMA_GET_FLAG(&hdma_usart2_tx,DMA_FLAG_TCIF2_6))
//				{
//						__HAL_DMA_CLEAR_FLAG(&hdma_usart2_tx,DMA_FLAG_TCIF2_6);
//						HAL_UART_DMAStop(&huart2);
//				}
				USB2UART_SendData(USB2UART_aRxBuffer,5);
				HAL_UART_Receive_IT(&huart4,USB2UART_aRxBuffer,USB2UART_RXBUFFSIZE);
		}
//		if(usb2uart_flag)
//		{
//			USB2UART_SendData(USB2UART_aRxBuffer,USB2UART_RXBUFFSIZE);
//			usb2uart_flag = 0;
//		}

    /* USER CODE END WHILE */
//		HAL_UART_Transmit(&huart5,test,8,1000);
//		while(__HAL_UART_GET_FLAG(&huart5,UART_FLAG_TC) != SET);
//		HAL_UART_Transmit(&huart4,test,5,1000);
//		while(__HAL_UART_GET_FLAG(&huart4,UART_FLAG_TC) != SET);
//		HAL_Delay(2000);
//		DXL_SendData(&test,1);
//		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14|GPIO_PIN_15);

//		DXL_Handler.id=0;
//		if(!flag)
//		{
//			DXL_Handler.len=3+sizeof(param1)/sizeof(u8);	
//			DXL_Handler.Param=param1;
//		  flag = 1;
//		}
//		else
//		{
//			DXL_Handler.len=3+sizeof(param2)/sizeof(u8);	
//			DXL_Handler.Param=param2;
//		  flag = 0;
//		}
//		DXL_Handler.Ins=Write;
//		DXL_ProtocolSendData(&DXL_Handler);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}



