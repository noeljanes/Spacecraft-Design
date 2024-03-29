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


#ifndef WRITER1_H
#define WRITER1_H
void writer1(void);
void init_writer1(void);

#endif /* writer1_H */