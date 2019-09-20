#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>

void writer1 (){
	for(;;) {
		printf("a"); // test
		const char * str = "Vad bra! ";
		printfConsole(str);
	}

}
	
void init_writer1() {
	/* Create task */
	xTaskCreate(
	writer1,				/* Function that implements the task. */
	"Message 1 print task",		/* Text name for the task. */
	250,						/* Stack size in words, not bytes. */								// What's this?
	NULL,						/* Parameter passed into the task. */
	1,							/* Priority at which the task is created. */
	NULL 						/* Used to pass out the created task's handle. */
	);
}