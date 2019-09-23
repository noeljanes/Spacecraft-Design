#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>

SemaphoreHandle_t xSemaphore;

void taskCreateSemaphore (void * pvParameters) {

	xSemaphore = xSemaphoreCreateMutex();

	if ( xSemaphore == NULL ) {
		printf('Error when creating semaphore')
	}
	else {
		printf('Semaphore is ready for use')
	}
}


void printfConsole(const char * str) {
	//printf(str);
	//xSemaphoreTake(xSemaphore,10);
	for( int i = 0; i < sizeof(str); i++) {
		CONF_UART->UART_THR = str;
	}
	//xSemaphoreGive(xSemaphore);

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
	
	
	// Semaphore

	/*xSemaphore = xSemaphoreCreateMutex();

   if( xSemaphore != NULL )
   {
       /* The semaphore was created successfully and
       can be used. 
	   printf('error');
   } */

}





