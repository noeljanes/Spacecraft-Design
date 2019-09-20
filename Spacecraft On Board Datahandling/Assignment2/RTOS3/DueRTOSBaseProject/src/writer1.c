#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <uart_comm.h>

#include <writer1.h>

void writer1 (){
	unsigned char message1[] = "1234";
	for(;;) {
		for( int i = 0; i < 3; i++) {
			CONF_UART->UART_THR = message1[i];
			vTaskDelay(100);
			//CONF_UART->UART_THR = 'a';
		}
		vTaskDelay(100);
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