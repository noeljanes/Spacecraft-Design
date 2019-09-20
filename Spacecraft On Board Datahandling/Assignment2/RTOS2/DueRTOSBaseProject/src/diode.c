/*
 * diode.c
 *
 * Created:   19/09/2019
 * Author:    D.J.C.P. Hiemstra & Señorita Pérez &  & N.S. Janes
 * Platform:  Arduino Due / Atmel SAM3X8E
 * Purpose:   Manage LED status
 */


#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <led_off.h>
#include <led_on.h>
#include <diode.h>

/* Prototypes */




void init_diode() {
		/* Initialize LED0 on Port B Pin 27*/
		PIOB->PIO_PER = 1 << 27;		/* Pin Enable Register (PER) */
		PIOB->PIO_OER = 1 << 27;		/* Output Enable Register (OER) */
		PIOB->PIO_OWER = 1 << 27;		/* Output Write Enable Register (OWER) */
}
	
void set_diode() {					/* Used by led_on */
	PIOB->PIO_SODR = 1 << 27;		/* Turn off via Set Output Data Register (SODR)*/
}
	
void clear_diode() {					/* Used by led_off */
	PIOB->PIO_CODR = 1 << 27;		/* Turn off via Clear Output Data Register (CODR) */
}
