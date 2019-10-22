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
#include <tc.h>

/* Prototypes */
int delay = 0;
bool ready = false;

void blink() {
	
	TickType_t xLastWakeTime;		/* Last wake time of the task, needed for periodic execution */
	xLastWakeTime = xTaskGetTickCount();
	
	for( ;; ) {
		
		switch (get_cmd()) {    /* Get the command value */
			case ('0'):
			ready = true;       /* Ready state */
			break;
			case ('1'):
			delay = 250;        /* Low frequency blinking state */
			break;
			case ('2'):
			delay = 50;         /* High frequency blinking state */
			break;
		}
		
				
		if(!ready) {
			/* If not ready -> keep LED off */
			PIOB->PIO_CODR = 1 << 27;
		} else if(delay == 0) {
			/* If ready -> keep LED on continuously */
			PIOB->PIO_SODR = 1 << 27;
		} else {
			if((PIOB->PIO_ODSR & (1 << 27)) > 0) {
				/* If pin 27 is active -> turn off via Clear Output Data Register (CODR) */
				PIOB->PIO_CODR = 1 << 27;
				} else {
				/* If pin 27 is not active -> turn on via Set Output Data Register (SODR) */
				PIOB->PIO_SODR = 1 << 27;
			}
			vTaskDelayUntil(&xLastWakeTime, delay/portTICK_RATE_MS); /* Absolute delay */
		}
		vTaskDelay(10);
		
	}

    /* Tasks must not attempt to return from their implementing
    function or otherwise exit.  In newer FreeRTOS port
    attempting to do so will result in an configASSERT() being
    called if it is defined.  If it is necessary for a task to
    exit then have the task call vTaskDelete( NULL ) to ensure
    its exit is clean. */
    vTaskDelete( NULL );
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
