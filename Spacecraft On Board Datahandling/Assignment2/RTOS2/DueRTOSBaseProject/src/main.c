/*
 * main.c
 *
 * Created: 04/09/2018 15:15:27
 * Author:  Nikolaus Huber
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Main function declaration, initializes board peripherals, calls
 *           all other init functions and starts the FreeRTOS scheduler.
 */

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <led_off.h>
#include <led_on.h>
#include <diode.h>

int main (void)
{
	/* System clock initialization */
	sysclk_init();
	
	/* Board peripherals initialization */
	board_init();
	
	/* Init amber LED diode */
	init_diode();
	
	/* Init tasks */
	init_led_off();
	init_led_on();
	
	/* Start scheduler */
	vTaskStartScheduler();
	
	/* Should never reach here ... */
	return 1;
}
