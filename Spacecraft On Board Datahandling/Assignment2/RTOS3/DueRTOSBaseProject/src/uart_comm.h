/*
 * uart_comm.h
 *
 * Created: 22/08/2018 14:13:50
 * Author: Nikolaus Huber
 * Platform: Arduino Due - Atmel SAM3X8E
 *
 * Purpose: This module provides an interface via the UART/USB bridge on 
 *          the Arduino Due (Programming Port)
 *
 * For configuration of the UART see conf_uart_serial.h!
 */ 


#ifndef UART_COMM_H_
#define UART_COMM_H_

/**
 *  Configure and initialize the Console UART.
 */ 
void console_init(void);

#endif /* UART_COMM_H_ */