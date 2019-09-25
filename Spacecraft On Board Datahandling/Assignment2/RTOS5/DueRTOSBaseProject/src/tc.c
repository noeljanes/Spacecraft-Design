/*
 * tc.c
 *
* Created: 24/09/2019
* Author:  flapre-9 , dirhie-9 , noejan-9
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

/* Creates a queue handle */
QueueHandle_t xCommandQueue;

/* Declares the global variable to store the blink command */
static unsigned char blink_cmd;

/* Declares the TC message variable */
static unsigned char TC_message ; 

/* Declares the TC task function */
void vTaskTC( void* );


/** 
 * TC task function, interprets received data from UART and converts the character received to a number
 */
void vTaskTC( void *pvParameters ) {
	
	if( xSemaphoreTake( xSemaphore, portMAX_DELAY ) == pdTRUE )
	
	{
		if ( xQueueReceive( xCommandQueue , &blink_cmd , portTICK_PERIOD_MS) == pdTRUE ) {

			switch (blink_cmd) {

				case 'a':
					set_cmd('0');
					break;
				case 'b':
					set_cmd('1');
					break;
				case 'c':
					set_cmd('2');
					break;
			}
		}
		xSemaphoreGive(xSemaphore);
	}
	vTaskDelay(10);
}


/** 
 * Interrupt service routine for UART RXTX
 */
void UART_Handler( ){
	
	
	/* The UART interrupt is triggered both for RX and TX, therefore
	   we have to see if RXRDY is set in the UART status register */
	if((CONF_UART->UART_SR & UART_SR_RXRDY) == UART_SR_RXRDY) {
		
		/* Assigns the value received to a TC_message and adds it to the end of the queue */
		
		TC_message = (unsigned char) CONF_UART->UART_RHR;
		xQueueSendToBackFromISR(xCommandQueue, (void*) & TC_message, NULL);
		
	}
}

/** 
 * Initializes UART console, UART interrupt, command queue
 * and creates TC task 
 */
void init_tc( ) {
	
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
	NVIC_SetPriority(CONF_UART_ID, configMAX_PRIORITIES);

	/* Create a queue capable of containing 3 characters */
	xCommandQueue = xQueueCreate( 4 , sizeof( char ));

	if (xCommandQueue == NULL ) {
		printf("Queue doesn't exist");
	}

	xTaskCreate(
		vTaskTC, 		/* Function that implements the task that is created */
		"Telecommand", 	/* Name of the task */
		250, 			/* Stack size in words (not bytes) */
		NULL, 			/* Parameter that is passed into the task */
		3, 				/* Priority at which the task is created. */
		NULL 			/* Used to pass out the created task's handle. */

	);
	

}