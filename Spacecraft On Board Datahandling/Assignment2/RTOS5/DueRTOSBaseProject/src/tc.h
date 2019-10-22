/*
 * tc.h
 * Created: 26/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Receives char via UART in an interrupt and interprets them
 */


#ifndef TC_H_
#define TC_H_

/** 
 * Initializes TC object
 */
void init_tc( void );
/* TC task function, interprets received data from UART
*/
void handleInput (unsigned char);

#endif /* TC_H_ */