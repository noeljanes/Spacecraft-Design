#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <led_off.h>
#include <led_on.h>
#include <diode.h>

/* Create prototype */
void vTaskLed_off;																			// Why is this needed?

void vTaskLed_off( void *pvParameters ) {
	if( ((PIOB->PIO_ODSR & (1 << 27)) > 0) ) {
		PIOB->PIO_CODR = 1 << 27;
	}
}

void led_off_init( )
{
	/* Initialize LED0 on Port B Pin 27*/
	PIOB->PIO_PER = 1 << 27;		/* Pin Enable Register (PER) */
	PIOB->PIO_OER = 1 << 27;		/* Output Enable Register (OER) */
	PIOB->PIO_OWER = 1 << 27;		/* Output Write Enable Register (OWER) */
	
	/* Create task */
	xTaskCreate(
	vTaskLed_off,			/* Function that implements the task. */
	"Led_off Task",       /* Text name for the task. */
	250,				/* Stack size in words, not bytes. */								// What's this?
	NULL,				/* Parameter passed into the task. */
	1,					/* Priority at which the task is created. */
	NULL 				/* Used to pass out the created task's handle. */
	);