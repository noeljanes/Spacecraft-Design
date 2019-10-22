/*
* writer1.h
*
* Created: 24/09/2019
* Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
* Platform: Arduino Due / Atmel SAM3X8E
* Purpose:  Initialises the vTaskwriter1 task which sends message1 to the console
*/


#ifndef WRITER1_H
#define WRITER1_H

#define WRITER1PERIOD 1

/* Initializes the writer1 task for use by the console function */
void init_writer1(void);

#endif /* writer1_H */