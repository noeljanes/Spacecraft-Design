/*
 * writer2.h
 *
 * Created: 19/09/2019
 * Author:  Jonathan Lange, Björn Dierks & August Zedigh
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  
 */ 

#ifndef WRITER2_H
#define WRITER2_H

/* defines writing period */
#define writer2_period	 1

/**
 * Initializes and creates WRITING2 task 
 */
void init_writer2( void );

#endif /* WRITING2_H_ */