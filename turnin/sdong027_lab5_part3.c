/*	Author: Stephen Dong
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
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
  	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char button = 0x00;
	unsigned char led = 0x00;
	unsigned char direction = 0x01;	// 0x00 = right, 0x01 = left

	enum LED {WAIT, WAIT_RELEASE, NEXT_LED_L, NEXT_LED_R, CLEAR_LED} LED_STATE;

	while(1) {
		button = ~PINA & 0x01;
		
		switch (LED_STATE) {
			case WAIT:
				if (button && direction) {	// going left
					if (led & 0x20) {
						LED_STATE = NEXT_LED_R;
					}
					else {
						LED_STATE = NEXT_LED_L;
					}
				}
				else if (button && !direction) {	// going right
					if (led & 0x01) {
						LED_STATE = CLEAR_LED;	// reset after going right all the way
					}
					else {
						LED_STATE = NEXT_LED_R;
					}
				}
				break;
			case WAIT_RELEASE:
				if (!button) {
					LED_STATE = WAIT;
				}
				break;
			case NEXT_LED_L:
				LED_STATE = WAIT_RELEASE;
				break;
			case NEXT_LED_R:
				LED_STATE = WAIT_RELEASE;
				break;
			case CLEAR_LED:
				LED_STATE = WAIT_RELEASE;
				break;
			default:
				led = 0x00;
				direction = 0x01;
				LED_STATE = WAIT;
				break;
		}

		switch (LED_STATE) {
			case WAIT:
				// nothing
				break;
			case WAIT_RELEASE:
				// nothing
				break;
			case NEXT_LED_L:
				direction = 0x01;
				if (!led) {
					led = led| 0x01;
				}
				else {
					led = (led << 1);
				}
				break;
			case NEXT_LED_R:
				direction = 0x00;
				led = (led >> 1);
				break;
			case CLEAR_LED:
				led = 0x00;
				direction = 0x01;

				break;
		}

		PORTB = led;
	}


	return 0;
}
