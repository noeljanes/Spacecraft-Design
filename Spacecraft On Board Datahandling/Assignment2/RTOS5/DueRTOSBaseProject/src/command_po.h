/*
 * command_po.h
 *
 * Created: 05/09/2018 10:25:35
 * Author:  Nikolaus Huber
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Protected object for current command
 */ 

#include <asf.h>



#ifndef COMMAND_PO_H_
#define COMMAND_PO_H_




SemaphoreHandle_t xSemaphore;

/** 
 * Initializes command object 
 */
void init_cmd ( void );

/** 
 * Returns current command, ensures mutual exclusion 
 */
unsigned char get_cmd( void ); 


/** 
 * Sets current command, ensures mutual exclusion 
 */
void set_cmd ( unsigned char );


#endif /* COMMAND_PO_H_ */