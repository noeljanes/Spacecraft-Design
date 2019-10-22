/*
 * main.c
 * Created: 26/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Main function declaration, initializes board peripherals, calls
 *           all other init functions and starts the FreeRTOS scheduler.
 */ 

#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <blink.h>
#include <command_po.h>
#include <tc.h>


int main (void)
{
	/* System clock initialization */
	sysclk_init();
	
	/* Board peripherals initialization */
	board_init();
	
	/* Init tasks */
	init_blink();
	init_cmd();
	init_tc();
	
	/* Start scheduler */
	vTaskStartScheduler();
	
	/* Should never reach here ... */
	return 1;
}
