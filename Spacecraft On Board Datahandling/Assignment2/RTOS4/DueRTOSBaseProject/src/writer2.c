#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>


void writer2(){
	for(;;) {
		//xSemaphoreTake(xSemaphore,10);
		const char * str = "Mycket kaffe! ";
		printfConsole(str);
		xSemaphoreGive(xSemaphore);
	}
}


void init_writer2() {
	/* Create task */
	xTaskCreate(
	writer2,				/* Function that implements the task. */
	"Message 2 print task",		/* Text name for the task. */
	250,						/* Stack size in words, not bytes. */								// What's this?
	NULL,						/* Parameter passed into the task. */
	1,							/* Priority at which the task is created. */
	NULL 						/* Used to pass out the created task's handle. */
	);
}