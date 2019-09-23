#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>



if (xSemaphore == NULL ) {
	/* Checks if the semaphore handle exists before creating one */

	SemaphoreHandle_t xSemaphore;

	void taskCreateSemaphore (void * pvParameters) {

		xSemaphore = xSemaphoreCreateMutex(); /* Creates a mutual exclsion semaphore */ 

		if ( xSemaphore == NULL ) {
			printf('Error when creating semaphore')   /* Checks to see if the semaphore was created successfully and prints and error message if not */
		}
		
	}
}

void printfConsole(const char * str) {

	for( int i = 0; i < sizeof(str); i++) {
		CONF_UART->UART_THR = str;
	}

}

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





