/*
 * console_po.h
 *
 * Created: 24/09/2019
 * Author: flapre-9 , dirhie-9 , noejan-9
 * Platform: Arduino Due - Atmel SAM3X8E
 *
 * Purpose: Protected object - UART0 module
 *
 * For configuration of the UART see conf_uart_serial.h!
 */ 


#ifndef UART_COMM_H_
#define UART_COMM_H_
SemaphoreHandle_t xSemaphore;

/**
 *  Configure and initialize the Console UART.
 */ 
void console_init(void);

/** 
 * Print function, ensures mutual exclusion
 */
void printfConsole(const char *);

//void taskCreateSemaphore(void *);

#endif /* UART_COMM_H_ */