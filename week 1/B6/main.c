/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <util/delay.h>

void wait(int ms)
{
	for(int i=0; i<ms; i++){
		_delay_ms(1);
	}
}

int main (void)
{
	int blinksPerSecond;
	blinksPerSecond = 1;

	while (1){
		if (PORTC & 1){
			blinksPerSecond = 1;
		}		
		if (PORTC == 0){
			blinksPerSecond = 4;
		}
		pause(100 / blinksPerSecond);
		
	}
}

