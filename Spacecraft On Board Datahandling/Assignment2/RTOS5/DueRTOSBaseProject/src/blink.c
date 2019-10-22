/*
 * blink.c
 * Created: 26/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:   Holds the blinking task and init function
 */

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <blink.h>
#include <command_po.h>

/* Prototypes */
int delay = 0;
bool ready = false;

/* * Enumerate states:
 START : LED is constantly off
 READY : LED is constantly on
 LOWF  : LED is blinking at low frequency
 HIGHF : LED is blinking at high frequency
*/
static enum states
{
	START = 0,
	READY = 1,
	LOWF  = 2,
	HIGHF = 3
};

/* Define global variables */
/* Initialize state which will hold the current state and set initial * state */
static enum states currentState = START;

void blink(void *pvParameters ) {
	
	TickType_t xLastWakeTime;		/* Last wake time of the task, needed for periodic execution */
	xLastWakeTime = xTaskGetTickCount();
	
	for( ;; ) {
		
		switch (get_cmd()) {    /* Get the command value */
			case (0):
			currentState = READY;       /* Ready state */
			break;
			case (1):
			currentState = LOWF; /* Low frequency blinking state */    
			break;
			case (2):
			currentState = HIGHF; /* High frequency blinking state */        
			break;
		}
		
		switch(currentState) {
			case(START):
			/* If not ready -> keep LED off */
			PIOB->PIO_CODR = 1 << 27;
			break;
			
			case(READY):
			/* If ready -> keep LED on continuously */
			PIOB->PIO_SODR = 1 << 27;
			break;
			
			case(HIGHF):
			delay = 50;
			if((PIOB->PIO_ODSR & (1 << 27)) > 0) {
				/* If pin 27 is active -> turn off via Clear Output Data Register (CODR) */
				PIOB->PIO_CODR = 1 << 27;
				} else {
				/* If pin 27 is not active -> turn on via Set Output Data Register (SODR) */
				PIOB->PIO_SODR = 1 << 27;
			}
			break;
			
			case(LOWF):
			delay = 250;
			if((PIOB->PIO_ODSR & (1 << 27)) > 0) {
				/* If pin 27 is active -> turn off via Clear Output Data Register (CODR) */
				PIOB->PIO_CODR = 1 << 27;
				} else {
				/* If pin 27 is not active -> turn on via Set Output Data Register (SODR) */
				PIOB->PIO_SODR = 1 << 27;
			}
			break;
		}
		vTaskDelayUntil(&xLastWakeTime, delay/portTICK_RATE_MS); /* Absolute delay */
	
	}

}



void init_blink( )
{
	/* Initialize LED0 on Port B Pin 27*/
	PIOB->PIO_PER = 1 << 27;		/* Pin Enable Register (PER) */
	PIOB->PIO_OER = 1 << 27;		/* Output Enable Register (OER) */
	PIOB->PIO_OWER = 1 << 27;		/* Output Write Enable Register (OWER) */
	
		/* Create task */
		xTaskCreate(
		blink,			    /* Function that implements the task. */
		"Blink Task",       /* Text name for the task. */
		250,				/* Stack size in words, not bytes. */
		NULL,				/* Parameter passed into the task. */
		1,					/* Priority at which the task is created. */
		NULL 				/* Used to pass out the created task's handle. */
		);
}