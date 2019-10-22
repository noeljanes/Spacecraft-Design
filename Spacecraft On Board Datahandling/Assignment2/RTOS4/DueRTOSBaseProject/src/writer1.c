/*
 * writer1.c
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
#include <writer1.h>

/* Declares the object writer1 for later definition of tasks */
void writer1(void*);

void writer1 (void *pvParameters) {
	portTickType xLastWakeTime ;
	xLastWakeTime = xTaskGetTickCount();
	char cStr[] = "Vad "; 	/* Creates the string to be printed to the console */
	
	for(;;) {
		
		printfConsole(cStr);	/* Calls the printing function defined in the console_po.c file */
		vTaskDelayUntil(&xLastWakeTime, (writer1Period/portTICK_PERIOD_MS)); /* Tells the controller to wait before switching to the next task to prevent overlapping of tasks */
	}
	
	vTaskDelete( NULL ); /* Removes the task from the RTOS memory to free up resources upon completion */
}
	
void init_writer1() {
	/* Creates the writer1 task */
	xTaskCreate(
	writer1,					/* Function that implements the task. */
	"Message 1 print task",		/* Text name for the task. */
	250,						/* Stack size in words, not bytes. */							
	NULL,						/* Parameter passed into the task. */
	1,							/* Priority at which the task is created. */
	NULL 						/* Used to pass out the created task's handle. */
	);
}