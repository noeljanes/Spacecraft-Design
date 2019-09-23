#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>

void writer1 (){
	for(;;) {
		
		if ( xSemaphore !== NULL ) {
			/* Checks if the semaphore exists before attempting to take it */
		
			if ( xSemaphoreTake( xSemaphore , 10 ) == pdTRUE) {
				/* This only runs the rest of the task if the semaphore is successfully taken, this is done to cut down on wasted compute time */
				const char * pcStr = "Vad bra! "; 	/* Creates the string to be printed to the console */
				printfConsole(pcStr);	/* Calls the printing function defined in the console_po.c file */

				xSemaphoreGive( xSemaphore ); 	/* We're finished with the shared resources so we give the semaphore back to unblock the next task */
			}
			
		}

		else {
			printf('There is no assigned semaphore')
		}
	}

}
	
void init_writer1() {
	/* Create task */
	xTaskCreate(
	writer1,					/* Function that implements the task. */
	"Message 1 print task",		/* Text name for the task. */
	250,						/* Stack size in words, not bytes. */							
	NULL,						/* Parameter passed into the task. */
	1,							/* Priority at which the task is created. */
	NULL 						/* Used to pass out the created task's handle. */
	);
}