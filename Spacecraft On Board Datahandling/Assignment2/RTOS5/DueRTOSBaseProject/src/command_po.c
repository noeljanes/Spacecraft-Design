#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <conf_uart_serial.h>
#include <stdio_serial.h>

#include <command_po.h>
#include <tc.h>
#include <blink.h>

//if (xSemaphore == NULL ) {
	/* Checks if the semaphore handle exists before creating one */

	

void taskCreateSemaphore (void * pvParameters) {
	printf("creating task");
	//xSemaphore = xSemaphoreCreateMutex(); /* Creates a mutual exclsion semaphore */

	if ( xSemaphore == NULL ) {
		printf("Error when creating semaphore");   /* Checks to see if the semaphore was created successfully and prints and error message if not */
	}
		
}
//}

void init () {

}

void get () {
    
}
/*
void set ( unsigned char ) {

}*/