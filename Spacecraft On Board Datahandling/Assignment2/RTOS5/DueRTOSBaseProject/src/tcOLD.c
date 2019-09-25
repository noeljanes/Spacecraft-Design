/*
 * tc.c
 *
 * Created: 05/09/2018 10:25:50
 * Author:  Nikolaus Huber
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Receives char via UART in an interrupt and interprets them
 */ 


#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <conf_uart_serial.h>
#include <stdio_serial.h>

#include <command_po.h>
#include <tc.h>

/*YOUR CODE HERE*/

/** 
 * Initializes UART console, UART interrupt, command queue
 * and creates TC task 
 */

QueueHandle_t xQueue1;													// COPIED
static unsigned char TC_message;									// COPIED
static unsigned char blink_cmd;											//COPIED


/** 
 * TC task function, interprets received data from UART
 */
void vTaskTC( void *pvParameters ) {
	printf(" vTaskTC ");
	if (xQueueReceive(xQueue1,&blink_cmd, portMAX_DELAY)== pdTRUE)	{
		printf(" vTASK got triggered from queue");

		set_cmd('1');
	}
}

void init_tc( )
{
	/* Configure UART communication */
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits   = CONF_UART_STOP_BITS
	};
	
	/* redirect printf / scanf function calls to UART */
	stdio_serial_init(CONF_UART, &usart_serial_options);
	
    /* Enable UART Interrupt for RX ready */
	uart_enable_interrupt( CONF_UART, UART_IER_RXRDY );
	
	/* Enable Interrupt Handler */
	NVIC_EnableIRQ((IRQn_Type) CONF_UART_ID);
	
	/* ATTENTION!
	 * It is very important to manually set the priority of the interrupt
	 * to a higher value, as per default all interrupts have priority 0,
	 * which is the highest priority. This causes problems when calling
	 * FreeRTOS APIs that end in ...fromISR( ), since they check if they 
	 * were not called from an ISR with higher or equal priority as 
	 * configMAX_SYSCALL_INTERRUPT_PRIORITY 
	*/
	/*YOUR CODE HERE*/
	NVIC_SetPriority(CONF_UART_ID, configMAX_PRIORITIES);
	/** xQueue1 = xQueueCreate( 4, sizeof( char ) );
	/* Create TC task */
	xTaskCreate(
	vTaskTC, /* Function that implements the task. */				// Need to change this it's copied
	"TC", /* Text name for the task. */
	250, /* Stack size in words, not bytes. */
	NULL, /* Parameter passed into the task. */
	1, /* Priority at which the task is created. */
	NULL); /* Used to pass out the created task's handle. */

}



/** 
 * Interrupt service routine for UART RXTX
 */
void UART_Handler( ) {
	printf(" UART HANDLER ");
	/* The UART interrupt is triggered both for RX and TX, therefore
	   we have to see if RXRDY is set in the UART status register */
	if((CONF_UART->UART_SR & UART_SR_RXRDY) == UART_SR_RXRDY) {
		//..... /*your code here*/
		TC_message = (unsigned char) CONF_UART->UART_RHR;
		xQueueSendToBackFromISR(xQueue1, (void*) &TC_message, NULL);			// Copied, change!
		printf(" Adding something to the queue ");

	}
}

