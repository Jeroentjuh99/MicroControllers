#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void wait(int ms){
	for(int i = 0; i < ms; i++){
		_delay_ms(1);
	}
}

