/*
 * writer2.c
 *
 * Created: 19/09/2019
 * Author:  Jonathan Lange, Björn Dierks & August Zedigh
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  
 */ 

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>
#include <writer2.h>

#include <console_po.h>

/* Prototypes */
void vTaskWriter2(void*);


void vTaskWriter2 (void *pvParameters)
{
	char message2[] = "2222222222222222222222222222222222222222222222222 ";
	
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	for(;;)
	{
		printfConsole(message2);
		vTaskDelayUntil(&xLastWakeTime, (writer2_period / portTICK_RATE_MS ));
	}
	/* Tasks must not attempt to return from their implementing
	function or otherwise exit.  In newer FreeRTOS port
	attempting to do so will result in an configASSERT() being
	called if it is defined.  If it is necessary for a task to
	exit then have the task call vTaskDelete( NULL ) to ensure
	its exit is clean. */
	vTaskDelete( NULL );
}


void init_writer2()
{
	/* Create task */
	xTaskCreate(
	vTaskWriter2,			/* Function that implements the task. */
	"Writer2",         /* Text name for the task. */
	250,				/* Stack size in words, not bytes. */
	NULL,				/* Parameter passed into the task. */
	2,					/* Priority at which the task is created. */
	NULL 				/* Used to pass out the created task's handle. */
	);
}