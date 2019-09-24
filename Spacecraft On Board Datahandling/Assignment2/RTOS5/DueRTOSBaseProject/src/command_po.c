#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <command_po.h>

#include <stdlib.h>
#include <stdio.h>
#include <blink.h>


unsigned char cmd;
void set_cmd ( unsigned char c) {	/* This method sets the current command to a specified value */
	cmd = c;
}

unsigned char get_cmd() {			/* other objects can call this method to read the current command */
	return cmd;
}

void init_cmd()
{
	//xSemaphore = xSemaphoreCreateMutex();
	
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	stdio_serial_init(CONF_UART, &usart_serial_options);
	

}






