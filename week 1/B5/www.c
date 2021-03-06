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

 typedef struct {
	unsigned char bits;
} STATE;

int main (void)
{
	// Patroon
	STATE bit_pattern[4] = { {BIT(0)}, {BIT(1)}, {BIT(2)}, {BIT(3)} };

	DDRD = 0b11111111;	
	
	while (1) {
		int counter;
		counter = sizeof(bit_pattern)/sizeof(STATE);

		while (counter > 0) {
			PORTD |= bit_pattern[counter].bits;
			_delay_ms(50);
			counter--;
		}
	}
}

