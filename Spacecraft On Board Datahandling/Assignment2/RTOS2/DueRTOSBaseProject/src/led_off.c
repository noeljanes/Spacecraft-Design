#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <led_off.h>
#include <led_on.h>
#include <diode.h>

/* Create prototype */
void vTaskLed_off(void*);


void vTaskLed_off( void *pvParameters ) {
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	for(;;) {
		clear_diode();
		vTaskDelayUntil(&xLastWakeTime, LED_OFF_PERIOD_MS / portTICK_RATE_MS);
	}
}

void init_led_off( ) {

	/* Create task */
	xTaskCreate(
	vTaskLed_off,			/* Function that implements the task. */
	"Led_off Task",       /* Text name for the task. */
	250,				/* Stack size in words, not bytes. */								// What's this?
	NULL,				/* Parameter passed into the task. */
	2,					/* Priority at which the task is created. */
	NULL 				/* Used to pass out the created task's handle. */
	);
}