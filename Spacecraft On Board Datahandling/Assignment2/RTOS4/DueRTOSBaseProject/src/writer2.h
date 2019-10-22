/*
 * writer2.h
 *
 * Created: 24/09/2019
 * Author:  Cornelis Peter Hiemstra, Noel Janes & Flavia Pérez Cámara
 * Platform: Arduino Due / Atmel SAM3X8E
 * Purpose:  Initialises the vTaskwriter2 task which sends message2 to the console

 */

#ifndef WRITER2_H
#define WRITER2_H

#define WRITER2PERIOD 1

/* Initializes the writer2 task for use by the console function */
void init_writer2(void);

#endif /* writer2_H */