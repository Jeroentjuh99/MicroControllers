#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void wait(int ms){
	for(int i = 0; i<=ms; i++){
		_delay_ms(1);
	}
}

void lcd_command(unsigned char dat)
{
	PORTC = dat & 0XF0;     // top nibble
	PORTC = PORTC | 0x08;   // data (RS=0)
	// start (EN=1)
	_delay_ms(1);               // Wait 1 ms
	PORTC = 0x04;           // stop (EN=0)

	PORTC = (dat & 0x0F) << 4;  // Down nibble
	PORTC = PORTC | 0x08;       // data (RS=0)
	// start (EN=1)
	_delay_ms(1);                   // Wait 1 ms
	PORTC = 0x00;               // stop(EN=0, RS=0)
	              // wait 15 ms for command delay
}

void main(void){
	DDRC = 0xFF;
	PORTC = 0x00;
	_delay_ms(20);
	init();
}

void init(void){
	_delay_ms(1000);         // wait 300 ms for initialisation
	lcd_command( 0x02 );    // return home
	_delay_ms(15);
	lcd_command( 0x28 );    // set mode to: 4 bits interface data, 2 lines, 5x8 dots
	_delay_ms(15);
	lcd_command( 0x0E );    // display: on, cursor off, blinking off
	_delay_ms(15);
	lcd_command( 0x06 );    // entry mode: cursor to right, no shift
	_delay_ms(15);
	lcd_command( 0x80 );    // RAM address: 0, first position, line 1
	_delay_ms(100);         // wait 100 ms
}

void toggleE(void){
	PORTC |= (1<<3);
	PORTC &= ~(1<<3);
}

void display_text(char *str){
	
}

void set_cursor(int position){
	
}
