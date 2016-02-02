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
		for (int i=0; i<ms; i++)
		{
			_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
		}
}

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();

	/* Insert application code here, after the board has been initialized. */
	DDRD = 0b10000000;
	PORTC = 0x0;

	while(1){
		if((PORTC & 0b00000001)!=0){
			PORTD = 0b10000000;
			wait(500);
			PORTD = 0b00000000;
			wait(500);		
			}
	}
	return 1;
}
