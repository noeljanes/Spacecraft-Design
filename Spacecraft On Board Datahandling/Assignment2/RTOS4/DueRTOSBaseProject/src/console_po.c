#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>
#include <stdlib.h>
#include <stdio.h>




void printfConsole(char[] str) {
	
	int i;
	i = 0;
	if ( xSemaphore != NULL) {
		if(xSemaphoreTake( xSemaphore, (TickType_t) 1) == pdTRUE) {	/* Check if the semaphore is available, otherwise check again after 1 ms */
			while(str[i] != '\0') {				/* Run the loop until the end of the string is reached */
				CONF_UART->UART_THR = str;		/*Print the character from the string */
				i++;
			}
			xSemaphoreGive(xSemaphore);		/* Free up the semaphore for other tasks */
		}
	}
	
}

void console_init()
{
	SemaphoreHandle_t xSemaphore = NULL ;
	xSemaphore = xSemaphoreCreateMutex();
	
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	
	stdio_serial_init(CONF_UART, &usart_serial_options);

}






