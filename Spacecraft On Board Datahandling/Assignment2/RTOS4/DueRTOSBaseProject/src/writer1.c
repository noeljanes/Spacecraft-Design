/*
 * writer1.c
 *
 * Created: 24/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Initialises the vTaskwriter1 task which sends message1 to the console
 */


#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>
#include <console_po.h>
#include <writer1.h>

/* Declares the object writer1 for later definition of tasks */
static void writer1(void*); /* Declared static to protect the function from being accessed by other objects*/

static void writer1 (void *pvParameters) { 
	portTickType xLastWakeTime ;
	xLastWakeTime = xTaskGetTickCount();
	char cStr[] = "Vad "; 	/* Creates the string to be printed to the console */
	
	for(;;) {
		
		printfConsole(cStr);	/* Calls the printing function defined in the console_po.c file */
		vTaskDelayUntil(&xLastWakeTime, (WRITER1PERIOD/portTICK_PERIOD_MS)); /* Tells the controller to wait before switching to the next task to prevent overlapping of tasks */
	}
	
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