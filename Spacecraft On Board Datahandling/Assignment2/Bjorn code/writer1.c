/*
 * writer1.c
 *
 * Created: 19/09/2019
 * Author:  Jonathan Lange, Björn Dierks & August Zedigh
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  
 */ 

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>
#include <writer1.h>

#include <console_po.h>

/* Prototypes */
void vTaskWriter1(void*);


void vTaskWriter1 (void *pvParameters)
{
	char message1[] = "1111111111111111111111111111111111111111111111111 ";
	
	portTickType xLastWakeTime;
	xLastWakeTime=xTaskGetTickCount();
	
	for(;;)
	{
		printfConsole(message1);
		vTaskDelayUntil(&xLastWakeTime, (writer1_period / portTICK_RATE_MS ));
	}
	/* Tasks must not attempt to return from their implementing
    function or otherwise exit.  In newer FreeRTOS port
    attempting to do so will result in an configASSERT() being
    called if it is defined.  If it is necessary for a task to
    exit then have the task call vTaskDelete( NULL ) to ensure
    its exit is clean. */
    vTaskDelete( NULL );
}


void init_writer1()
{
	/* Create task */
	xTaskCreate(
	vTaskWriter1,			/* Function that implements the task. */
	"Writer1",         /* Text name for the task. */
	250,				/* Stack size in words, not bytes. */
	NULL,				/* Parameter passed into the task. */
	2,					/* Priority at which the task is created. */
	NULL 				/* Used to pass out the created task's handle. */
	);
}