/*
 * console_po.h
 *
 * Created: 05/09/2018 09:43:50
 * Author: Nikolaus Huber
 * Platform: Arduino Due - Atmel SAM3X8E
 *
 * Purpose: Protected object - UART0 module
 *
 * For configuration of the UART see conf_uart_serial.h!
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

#endif /* UART_COMM_H_ */