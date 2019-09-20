/*
 * blink.c
 *
 * Created:   19/09/2019
 * Author:    D.J.C.P. Hiemstra & Señorita Pérez &  & N.S. Janes
 * Platform:  Arduino Due / Atmel SAM3X8E
 * Purpose:   Turn on LED after a certain delay in ms
 */

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <led_off.h>
#include <led_on.h>
#include <diode.h>

/* Create prototype */
void vTaskLed_on(void*);																			// Why is this needed?

void vTaskLed_on( void *pvParameters ) {
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	vTaskDelayUntil(&xLastWakeTime, 8000 / portTICK_RATE_MS); // Added delay before starting blinking
	for(;;) {
		set_diode();
		vTaskDelayUntil(&xLastWakeTime, LED_ON_PERIOD_MS / portTICK_RATE_MS);
	}
}

void init_led_on( )
{

	/* Create task */
	xTaskCreate(
	vTaskLed_on,			/* Function that implements the task. */
	"Led_on Task",       /* Text name for the task. */
	250,				/* Stack size in words, not bytes. */								// What's this?
	NULL,				/* Parameter passed into the task. */
	1,					/* Priority at which the task is created. */
	NULL 				/* Used to pass out the created task's handle. */
	);
}