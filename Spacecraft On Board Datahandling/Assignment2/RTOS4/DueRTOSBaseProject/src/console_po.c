/*
* console_po.c
*
* Created: 24/09/2019
* Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
* Platform: Arduino Due / Atmel SAM3X8E
* Protected object - UART0 module
*
* For configuration of the UART see conf_uart_serial.h!
* Ensures mutual exclusion when printing to the UART
*/

/* Imported libraries */
#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

/* Required interfaces */
#include <stdlib.h>
#include <stdio.h>

/* Semaphore declaration */
SemaphoreHandle_t xSemaphore;


void printfConsole(const char * cStr) {

	xSemaphoreTake( xSemaphore, (TickType_t) 1); 
		/* If we're able to access the semaphore then the task gains access to the shared resources */
		
	for(int i = 0; (cStr[i] != '\0'); i++) {
		/* For loop to iterate through the string in writer character by character */	
						
				
			/* Checks if the microcontroller is ready to send the next message */	
			addChar(cStr[i]); 
				
				
	}
	xSemaphoreGive(xSemaphore);		/* Free up the semaphore for other tasks */
	
	
}

void addChar(unsigned char c) { /* If the microcontroller is ready it prints the element of the string */
	CONF_UART->UART_THR = c;
}

void console_init()
{
	xSemaphore = xSemaphoreCreateMutex(); /* Creates a mutual exclusion semaphore for use by the tasks */
	
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	
	stdio_serial_init(CONF_UART, &usart_serial_options);

}






