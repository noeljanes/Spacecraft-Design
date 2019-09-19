/*
 * blink.h
 *
 * Created:   19/9/2019
 * Author:    D.J.C.P Hiemstra, Flavia Pérez Cámara, Noel Janes
 * Platform:  Arduino Due / Atmel SAM3X8E
 * Purpose:   Holds the blinking task and init function
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
