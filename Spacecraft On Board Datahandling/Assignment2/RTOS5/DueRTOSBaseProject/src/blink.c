/*
 * blink.c
 *
 * Created:   19/9/2019
 * Author:    D.J.C.P Hiemstra, Flavia Pérez Cámara, Noel Janes
 * Platform:  Arduino Due / Atmel SAM3X8E
 * Purpose:   Holds the blinking task and init function
 */ 

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <blink.h>
#include <command_po.h>
#include <tc.h>

/* Prototypes */
void blink(void);
int delay;		/* The blinking delay in ms */

void blink() {
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	
	for( ;; ) {
				
		switch(get_cmd()) {		/* Get the current command from command_po and set the blinking frequency accordingly */
			case '0':
				delay = 500;
				break;
				
			case '1':
				delay = 100;
				break;
				
			case '2':
				delay = 50;
				break;
		}
		
		/* See if pin 27 in Output Data Status Register (ODSR) is set */
		if((PIOB->PIO_ODSR & (1 << 27)) > 0)
		{
			/* If pin 27 is active -> turn off via Clear Output Data Register (CODR) */
			PIOB->PIO_CODR = 1 << 27;
			} else {
			/* If pin 27 is not active -> turn off via Set Output Data Register (SODR) */
			PIOB->PIO_SODR = 1 << 27;
		}
		
		/*vTaskDelay( BLINK_PERIOD_MS / portTICK_RATE_MS );*/ /* This was old code */
		vTaskDelayUntil(&xLastWakeTime, delay / portTICK_RATE_MS); /* Improved by using absolute instead of relative timing*/
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
		blink,			/* Function that implements the task. */
		"Blink Task",       /* Text name for the task. */
		250,				/* Stack size in words, not bytes. */
		NULL,				/* Parameter passed into the task. */
		1,					/* Priority at which the task is created. */
		NULL 				/* Used to pass out the created task's handle. */
		);
}
