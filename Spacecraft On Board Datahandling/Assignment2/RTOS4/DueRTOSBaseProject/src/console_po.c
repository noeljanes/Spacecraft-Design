#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>
#include <stdlib.h>
#include <stdio.h>




void printfConsole(const char * str) {

	if(xSemaphoreTake( xSemaphore, (TickType_t) 1) == pdTRUE) {	/* Check if the semaphore is available, otherwise check again after 1 ms */
		for(int i = 0; (str[i] != '\0'); i++) {
					printf("%c", str[i]);
		}
		xSemaphoreGive(xSemaphore);		/* Free up the semaphore for other tasks */
	}
	
}

void console_init()
{
	xSemaphore = xSemaphoreCreateMutex();
	
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	
	stdio_serial_init(CONF_UART, &usart_serial_options);

}






