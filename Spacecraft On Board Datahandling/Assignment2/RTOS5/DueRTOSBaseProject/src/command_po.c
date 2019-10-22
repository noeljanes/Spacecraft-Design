/*
 * command_po.c
 *
 * Created: 26/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Protected object for current command
 */ 


#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <command_po.h>

#include <stdlib.h>
#include <stdio.h>


static xSemaphoreHandle xCommandSemaphore; /* Semaphore declaration */

/* Prototypes */
static unsigned char cmd_curr;

/* Initializes command object
*/
void init_cmd() {
	
	xCommandSemaphore = xSemaphoreCreateMutex();
	cmd_curr = 1;
	
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	stdio_serial_init(CONF_UART, &usart_serial_options);
}


unsigned char get_cmd() {
	
	unsigned char cmd_temp;
	xSemaphoreTake( xCommandSemaphore, (TickType_t) 1);
	cmd_temp = cmd_curr; 
	xSemaphoreGive( xCommandSemaphore);
	return cmd_temp; /* returns the current command value*/
	
}


void set_cmd ( unsigned char c) {
	
	xSemaphoreTake( xCommandSemaphore, (TickType_t) 1);
	cmd_curr = c; /* sets the current command value to new the value*/
	xSemaphoreGive( xCommandSemaphore);
	
}




