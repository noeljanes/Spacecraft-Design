/*
 * main.c
 *
 * Created: 24/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E 
 * Purpose:  The complete program takes a string and prints it to the console (UART). 
 *			 The printing is carried out using two writer objects (writer1 and writer2), 
 * 			 and  the  message is printed one symbol at a time. And the complete string is protected.
 *			 The protected object (console_po) ensures mutual exclusion. 
 *			 Main.c is responsible for declaration, initializing board peripherals, calls
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
