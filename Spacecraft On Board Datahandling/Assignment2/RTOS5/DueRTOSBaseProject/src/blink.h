/*
 * blink.h
 * Created: 26/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:   Holds the blinking task
 */
#ifndef BLINK_H_
#define BLINK_H_

/* Initializes and creates blink task */
void init_blink( void );
void blink(void);

#endif /* BLINK_H_ */