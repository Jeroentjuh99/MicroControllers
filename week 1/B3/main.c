#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define BIT(x) (1 << (x))

void wait(int ms)
{
	while(ms > 0){
		_delay_ms(1);
		ms--;
	}
}

int main(void){
	
	DDRC = 0x00;
	DDRD = 0xFF;
	
	PORTD &= ~BIT(7); // 0000 0000 & 0111 1111 = 0000 0000 
	
	while (1){
		
		if (PINC & 0x01){
			wait(200);
			PORTD = BIT(7);
		} else {
			PORTD = 0;
		}
		
	}
	
	return 0;
}
