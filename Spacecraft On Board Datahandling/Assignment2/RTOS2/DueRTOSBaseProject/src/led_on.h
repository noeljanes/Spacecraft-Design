/*
 * led_on.h
 *
 * Created: 04/09/2018 16:15:27
 * Author:  Nikolaus Huber
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Defines LED on period and interface to init function
 */ 


#ifndef LED_ON_H_
#define LED_ON_H_

/* defines led on period */
#define LED_ON_PERIOD_MS	 2000

/**
 * Initializes and creates LED ON task 
 */
void init_led_on( void );

#endif /* LED_ON_H_ */