/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char sensor = 0x00;
	unsigned char led = 0x00;

    /* Insert your solution below */
	while (1) {
		sensor = PINA & 0x0F;
		led = 0x00;

		if (sensor >= 13) {   // 13 - 15
			led = 0x00 | 0x3F; // PC5 - PC0
		}
		else if (sensor >= 10) {  // 10 - 12
			led = 0x00 | 0x3E; // PC5 - PC1
		}
		else if (sensor >= 7) {   // 7 -9
			led = 0x00 | 0x3C; // PC5 - PC2
		}
		else if (sensor >= 5) {   // 5 - 6
			led = 0x00 | 0x38; // PC5 - PC3
		}
		else if (sensor >= 3) {   // 3 - 4
			led = 0x00 | 0x30; // PC5 - PC4
		}
		else if (sensor >= 1) {   // 1 - 2
			led = 0x00 | 0x20; // PC5
		}

		// low fuel
		if (sensor <= 4) {	// if any of the lower leds are on, fuel light will not turn on
			led = led | 0x40;
		}
		
		PORTC = 0x00 | led;
	}


	return 1;
}
