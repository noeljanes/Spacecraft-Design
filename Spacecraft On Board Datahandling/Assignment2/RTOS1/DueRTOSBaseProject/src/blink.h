/*
 * blink.h
 *
 * Created:   04/09/2018 11:32:52
 * Author:    Nikolaus Huber
 * Platform:  Arduino Due / Atmel SAM3X8E
 * Purpose:   Defines the blink period and the initialization interface
 */ 


#ifndef BLINK_H_
#define BLINK_H_

/* define blinking period in milliseconds */
#define BLINK_PERIOD_MS		1000

/**
 * Initiates blinking task                                              
 */
void blink_init( void );



#endif /* BLINK_H_ */