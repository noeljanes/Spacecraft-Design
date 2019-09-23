#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>




void printfConsole(const char * str) {
	str = "jllkdsflkjfds";
	for(;;) {
		for( int i = 0; i < 5; i++) {
			CONF_UART->UART_THR = "j";
			printf("k");
		}
	}
}

void console_init(void) {
	xTaskCreate(
	printfConsole,				/* Function that implements the task. */
	"printfConsole task",		/* Text name for the task. */
	250,						/* Stack size in words, not bytes. */								// What's this?
	NULL,						/* Parameter passed into the task. */
	1,							/* Priority at which the task is created. */
	NULL 						/* Used to pass out the created task's handle. */
	);
}