/*
 * led_off
 *
 * Created:   19/09/2019
 * Author:    D.J.C.P. Hiemstra & Señorita Pérez &  & N.S. Janes
 * Platform:  Arduino Due / Atmel SAM3X8E
 * Purpose:   Turn off LED after a certain delay in ms
 */


#ifndef LED_OFF_H_
#define LED_OFF_H_

/* defines LED off period in milliseconds */
#define LED_OFF_PERIOD_MS	1000

/** 
 * Initializes the LED off task 
 */
void init_led_off( void );

#endif /* LED_OFF_H_ */