/*
 * writer1.h
 *
 * Created: 19/09/2019
 * Author:  Jonathan Lange, Björn Dierks & August Zedigh
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  
 */ 

#ifndef WRITER1_H
#define WRITER1_H

/* defines writing period */
#define writer1_period	 1

/**
 * Initializes and creates WRITING1 task 
 */
void init_writer1( void );

#endif /* WRITING1_H_ */