/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *Example routine to emulate a simulate USB-CDC Device, USE USART2(PA2/PA3);
 *Please note: This code uses the default serial port 1 for debugging,
 *if you need to modify the debugging serial port, please do not use USART2
 */


#include "UART.h"
#include "debug.h"

void GPIO_Toggle_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
	char str_t[64];
	uint16_t count;
	uint8_t i = 0;

	SystemCoreClockUpdate( );
	Delay_Init( );
	USART_Printf_Init( 115200 );

	printf( "SystemClk:%d\r\n", SystemCoreClock );
	printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
	printf( "Simulate USB-CDC Device running on USBHS Controller\r\n" );
	GPIO_Toggle_INIT();
	RCC_Configuration( );

	/* Tim2 init */
	TIM2_Init( );

	/* Usart1 init */
	//UART2_Init( 1, DEF_UARTx_BAUDRATE, DEF_UARTx_STOPBIT, DEF_UARTx_PARITY );

	/* USB20 device init */
	USBHS_RCC_Init( );
	USBHS_Device_Init( ENABLE );

	while(1)
	{
		count = USB_CDC_RxAvailable();
		if (count > 0) {
			USB_CDC_Rx((uint8_t*)str_t,count);
			USB_CDC_Send((uint8_t*)str_t,count);

			//LED indica processo de dados
			GPIO_WriteBit(GPIOC, GPIO_Pin_8, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
		}

		//UART2_DataRx_Deal( );
		//UART2_DataTx_Deal( );
	}
}
