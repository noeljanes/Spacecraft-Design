/*
 * tc.h
 *
 * Created: 05/09/2018 10:26:04
 * Author:  Nikolaus Huber
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Receives char via UART in an interrupt and interprets them
 */


#ifndef TC_H_
#define TC_H_

/** 
 * Initializes TC object 
 */
void init_tc( void );
void handleInput (void);

#endif /* TC_H_ */