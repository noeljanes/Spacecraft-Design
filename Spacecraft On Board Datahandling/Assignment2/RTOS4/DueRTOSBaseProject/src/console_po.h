/*
* console_po.h
*
* Created: 24/09/2019
* Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
* Platform: Arduino Due / Atmel SAM3X8E
* Protected object - UART0 module
*
* For configuration of the UART see conf_uart_serial.h!
* Ensures mutual exclusion when printing to the UART
*/

#ifndef UART_COMM_H_
#define UART_COMM_H_

/**
 *  Configure and initialize the Console UART.
 */ 
void console_init(void);

/** 
 * Print function, ensures mutual exclusion
 */
void printfConsole(const char *);

void addChar(unsigned char);
#endif /* UART_COMM_H_ */