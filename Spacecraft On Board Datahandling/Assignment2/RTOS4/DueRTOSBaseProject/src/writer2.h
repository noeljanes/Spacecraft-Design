
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


#ifndef WRITER2_H
#define WRITER2_H

#define writer2Period 1

//void writer2(void);
void init_writer2(void);

#endif /* writer2_H */