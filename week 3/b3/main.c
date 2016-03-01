/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** ioisr.c
**
** Beschrijving:	ISR on PORTD demonstrattion  
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ioisr.c
**					avr-gcc -g -mmcu=atmega128 -o ioisr.elf ioisr.o
**					avr-objcopy -O ihex ioisr.elf ioisr.hex 
**					or type 'make'
** Author: 			dkroeske@gmail.com
** -------------------------------------------------------------------------*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BIT(x) (1 << (x))

/*
typedef struct STUFF {
	{ 0x00, 0x01, 0x02, 0x04, 0x08 }
} STUFF;
*/

int msCount 	= 	0;
int seconden 	= 	0;
int minuten 	= 	0;
int uren    	= 	0;

/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void timer2init(){
	OCR2 = 250;
	TIMSK |= BIT(7);
	SREG |= BIT(7);
	TCCR2 = 0b00001011;
}
/*
ISR( TIMER2_COMP_vect ) 
{ 
	msCount++;
	// Increment ms counter 
	if (msCount == 500 ) { 
		PORTC ^= BIT(0);
		// Toggle bit 0 van PORTC 
		msCount = 0;
		// Reset ms_count  value 
	}
}
*/
ISR (TIMER2_COMP_vect){
	msCount++;
	
	if (msCount == 50){
		PORTC ^= BIT(0);
		msCount = 0;
		seconden++;
		
		if (seconden == 60){
			seconden = 0;
			minuten++;
			
			if (minuten == 60){
				minuten = 0;
				uren++;
			}
		}
	}
}

int main( void ) { 
	DDRC = 0xFF;
	TCCR2 = 0b00001011;
	// set PORTC for output (toggle PC0) 
	timer2init(); 
	while (1) 
	{ 
		// do something else 
		wait(10);
		// every 10 ms (busy waiting 
	} 
} 