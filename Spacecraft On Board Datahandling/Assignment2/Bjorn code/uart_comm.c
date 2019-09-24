/*
 * uart_comm.c
 *
 * Created: 22/08/2018 14:13:50
 * Author: Nikolaus Huber
 * Platform: Arduino Due - Atmel SAM3X8E
 *
 * Purpose: This module provides an interface via the UART/USB bridge on 
 *          the Arduino Due (Programming Port)
 *
 * For configuration of the UART see conf_uart_serial.h!
 */ 



#include "asf.h"
#include "stdio_serial.h"
#include "conf_uart_serial.h"
#include "uart_comm.h"

/**
 *  Configure and initialize the Console UART.
 */
void console_init()
{
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	
	stdio_serial_init(CONF_UART, &usart_serial_options);
}
