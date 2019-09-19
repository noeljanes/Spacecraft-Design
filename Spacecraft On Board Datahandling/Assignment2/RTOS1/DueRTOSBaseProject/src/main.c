#include <asf.h>
#include <FreeRTOS.h>
#include <task.h>

#include <blink.h>


int main (void)
{
	/* System clock initialization */
	sysclk_init();
	
	/* Board peripherals initialization */
	board_init();
	
	/* Init blinker task */
	blink_init();
	
	/* Start scheduler */
	vTaskStartScheduler();
	
	/* Should never reach here ... */
	return 1;
}
