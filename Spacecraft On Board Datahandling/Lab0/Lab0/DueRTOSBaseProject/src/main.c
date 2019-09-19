/*
 * main.c
 *
 * Created: 22/08/2018 14:13:50
 * Author: Nikolaus Huber
 * Platform: Arduino Due - Atmel SAM3X8E
 *
 * Purpose: Blinks the LED0 on the Arduino Due
 *
 */ 

#include <asf.h>  /* include asf library*/
#include <delay.h>

int main (void)
{
	/* System clock initialization */
	sysclk_init();
	
	/* Board peripherals initialization */
	board_init();
	
	/* Initialize LED0 on Port B Pin 27*/
	PIOB->PIO_PER = 1 << 27;		/* Pin Enable Register (PER) */
	PIOB->PIO_OER = 1 << 27;		/* Output Enable Register (OER) */
	PIOB->PIO_OWER = 1 << 27;		/* Output Write Enable Register (OWER) */
	
	/* Defining Morse code constants */
	int dot ;  /* dot is the Short symbol */
	int dash ; /* dash is the long symbol */
	int symbolBreaK ; /* This is the space between two morse or symbol characters */
	//int wordBreak ; /* This is the space between two words in morse */
	
	dot = 200 ;
	dash = 3*dot ;
	symbolBreaK = 2*dot ;
	//wordBreak = 6*dot ;
	
	void off() {
		if((PIOB->PIO_ODSR & (1 << 27)) > 0) {
			/* If pin 27 is active -> turn off via Clear Output Data Register (CODR) */
			PIOB->PIO_CODR = 1 << 27;
			delay_ms(200);
		}
	}
	
	void on() {
		if((PIOB->PIO_ODSR & (1 << 27)) < 1)
			PIOB->PIO_SODR = 1 << 27;
	}
	
	void blink(int t_on) {
		on();
		delay_ms(t_on);
		off();
		delay_ms(200);
	}
	
	void symbolBreak(){
		off();
		delay_ms(400);
	}
	
	void wordBreak(){
		off();
		delay_ms(1400);
	}
	
	/* Main loop */
	while(1) {
		
		//H
		blink(dot);
		blink(dot);
		blink(dot);
		blink(dot);
		symbolBreak();
		//E
		blink(dot); 
		symbolBreak();
		//L
		blink(dot);
		blink(dash);
		blink(dot);
		blink(dot);
		symbolBreak();
		//L
		blink(dot);
		blink(dash);
		blink(dot);
		blink(dot);
		symbolBreak();
		//O
		blink(dash);
		blink(dash);
		blink(dash);
		wordBreak(); // space
		//W
		blink(dot);
		blink(dash);
		blink(dash);
		symbolBreak();
		//O
		blink(dash);
		blink(dash);
		blink(dash);
		symbolBreak();
		//R
		blink(dot);
		blink(dash);
		blink(dot);
		symbolBreak();
		//L
		blink(dot);
		blink(dash);
		blink(dot);
		blink(dot);
		symbolBreak();
		//D
		blink(dash);
		blink(dot);
		blink(dot);
		symbolBreak();
		off();
		delay_ms(9000);
		
		
		
		
		/* See if pin 27 in Output Data Status Register (ODSR) is set */ 
		/*
		if((PIOB->PIO_ODSR & (1 << 27)) > 0) {
			/* If pin 27 is active -> turn off via Clear Output Data Register (CODR) */
			/*PIOB->PIO_CODR = 1 << 27;
			delay_ms(200);
		}
		else {
			/* If pin 27 is not active -> turn off via Set Output Data Register (SODR) */
			//PIOB->PIO_SODR = 1 << 27;
		//}
		
		
	} /* while(1) */
	
	/* Should never reach here ... */
	return 1;
}