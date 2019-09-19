/*
 * blink.c
 *
 * Created:   04/09/2018 11:32:52
 * Author:    Nikolaus Huber
 * Platform:  Arduino Due / Atmel SAM3X8E
 * Purpose:   Holds the blinking task and init function
 */ 

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <blink.h>

/* Prototypes */
void vTaskBlink( void* );
void led_on(void*);
void led_off(void*);

void led_on(void *pvParameters) {
	if((PIOB->PIO_ODSR & (1 << 27)) > 0) {
		/* If pin 27 is active -> turn off via Clear Output Data Register (CODR) */
		PIOB->PIO_CODR = 1 << 27;
		} else {
		/* If pin 27 is not active -> turn off via Set Output Data Register (SODR) */
		PIOB->PIO_SODR = 1 << 27;
	}
}

void led_off(void *pvParameters) {
	
}

void vTaskBlink( void *pvParameters ) {
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	
	for( ;; )
	{
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
		vTaskDelayUntil(&xLastWakeTime, BLINK_PERIOD_MS / portTICK_RATE_MS); /* Improved by using absolute instead of relative timing*/
	}

    /* Tasks must not attempt to return from their implementing
    function or otherwise exit.  In newer FreeRTOS port
    attempting to do so will result in an configASSERT() being
    called if it is defined.  If it is necessary for a task to
    exit then have the task call vTaskDelete( NULL ) to ensure
    its exit is clean. */
    vTaskDelete( NULL );
}



void blink_init( )
{
	/* Initialize LED0 on Port B Pin 27*/
	PIOB->PIO_PER = 1 << 27;		/* Pin Enable Register (PER) */
	PIOB->PIO_OER = 1 << 27;		/* Output Enable Register (OER) */
	PIOB->PIO_OWER = 1 << 27;		/* Output Write Enable Register (OWER) */
	
	/* Create task */
	xTaskCreate(
		vTaskBlink,			/* Function that implements the task. */
		"Blink Task",       /* Text name for the task. */
		250,				/* Stack size in words, not bytes. */
		NULL,				/* Parameter passed into the task. */
		1,					/* Priority at which the task is created. */
		NULL 				/* Used to pass out the created task's handle. */
	);
}
