/*
 * writer2.c
 *
 * Created: 24/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:   Sends message to the projected object function
 */

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>
#include <console_po.h>
#include <writer2.h>

/* Declares the object writer2 for later definition of tasks */
void writer2 (void*);


void writer2 (void *pvParameters) {

	portTickType xLastWakeTime ;
	xLastWakeTime = xTaskGetTickCount();
	char cStr[] = "Bra! \n"; 	/* Creates the string to be printed to the console */
	
	for(;;) {
		
		printfConsole(cStr);	/* Calls the printing function defined in the console_po.c file */
		vTaskDelayUntil(&xLastWakeTime, (writer2Period/portTICK_PERIOD_MS)); /* Tells the controller to wait before switching to the next task to prevent overlapping of tasks */
	}
	

	vTaskDelete( NULL ); /* Removes the task from the RTOS memory to free up resources upon completion */
}



void init_writer2() {
	/* Creates the writer2 task */
	xTaskCreate(
	writer2,					/* Function that implements the task. */
	"Message 2 print task",		/* Text name for the task. */
	250,						/* Stack size in words, not bytes. */
	NULL,						/* Parameter passed into the task. */
	1,							/* Priority at which the task is created. */
	NULL 						/* Used to pass out the created task's handle. */
	);
}