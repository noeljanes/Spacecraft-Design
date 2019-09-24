/*
 * console_po.c
 *
 * Created: 19/09/2019
 * Author:  Jonathan Lange, Björn Dierks & August Zedigh
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  
 */ 

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

#include <console_po.h>
#include <writer1.h>
#include <writer2.h>

#include <stdio_serial.h>
#include <conf_uart_serial.h>

/* Declare Semaphor */
SemaphoreHandle_t xSemaphore;

/*
* printfConsole is called by tasks to manage the tasking order using 
* semaphores and to print the string which is passed to it.
*/
void printfConsole(const char * str)
{
	int i=0;
	
	/*
	* Determine whether Sempahore is available in order to print task. 
	* If Semaphore is not available wait for 1ms to see if it frees up.
	*/
	if( xSemaphoreTake( xSemaphore, ( TickType_t ) 1 ) == pdTRUE )
	{
		/* Loop through string length until end of line character is reached */
		while(str[i]!='\0')
		{
			/* 
			* Determine whether micro-controller is ready to send next character
			* Send Character
			*/
			if((CONF_UART->UART_SR&UART_SR_TXRDY)==UART_SR_TXRDY)
			{
				CONF_UART->UART_THR = (unsigned char) str[i];
				i++;
			}
		}
		/* Free up Semaphore*/
		xSemaphoreGive(xSemaphore);
	}
}

void console_init()
{
	/* Create Mutex Semaphore */
	xSemaphore = xSemaphoreCreateMutex();
	
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	
	stdio_serial_init(CONF_UART, &usart_serial_options);
}