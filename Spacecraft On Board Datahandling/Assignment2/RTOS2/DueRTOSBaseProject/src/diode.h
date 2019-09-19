/*
 * diode.h
 *
 * Created: 04/09/2018 16:16:40
 * Author:  Nikolaus Huber
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Defines LED init, clear and set functions for amber
 *           LED on Port B Pin 27 on the Arduino Due Board
 */ 


#ifndef DIODE_H_
#define DIODE_H_

/** 
 * Initializes amber LED 
 */
void init_diode( void );

/** 
 * Turns LED on 
 */
void set_diode( void );

/** 
 * Turns LED off 
 */
void clear_diode( void );

#endif /* DIODE_H_ */