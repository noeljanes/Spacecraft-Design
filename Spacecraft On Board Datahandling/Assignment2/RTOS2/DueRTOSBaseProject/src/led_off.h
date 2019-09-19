/*
 * led_off.h
 *
 * Created: 04/09/2018 16:16:09
 * Author:  Nikolaus Huber
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Defines LED off period and interface to init function
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