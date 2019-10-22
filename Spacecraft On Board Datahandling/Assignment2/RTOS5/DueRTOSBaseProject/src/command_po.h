/*
 * command_po.h
 *
 * Created: 26/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Protected object for current command
 */ 

#ifndef COMMAND_PO_H_
#define COMMAND_PO_H_


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