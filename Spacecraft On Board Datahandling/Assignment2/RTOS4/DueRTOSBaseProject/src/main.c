/*
 * main.c
 *
 * Created: 24/09/2019
 * Author:  dirhie-9 , flapre-9 , noejan-9
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Main function declaration, initializes board peripherals, calls
 *           all other init functions and starts the FreeRTOS scheduler.
 */

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <console_po.h>

#include <writer1.h>
#include <writer2.h>

int main (void)
{
	/* System clock initialization */
	sysclk_init();
	
	/* Board peripherals initialization */
	board_init();
	
	/* Init UART console */
	console_init();
	/* Init tasks */
	init_writer1();
	init_writer2();
	
	/* Start scheduler */
	vTaskStartScheduler();
	
	/* Should never reach here ... */
	return 1;
}
