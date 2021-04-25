/*	Author: Stephen Dong
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
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
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char button = 0x00;
	unsigned char led = 0x07;

	enum LED {RST, WAIT, WAIT_INC_RELEASE, WAIT_DEC_RELEASE, INC, DEC} LED_STATE;
    LED_STATE = WAIT;

	while(1) {
        button = ~PINA & 0x03;
        
        switch (LED_STATE) {
            case RST:
                if (!button) {		// no button pressed
                    	LED_STATE = WAIT;
                }
                else if ((button & 0x01) && !(button & 0x02)) {	// inc immediately pressed
                    	LED_STATE = INC;
                }
                else if ((button & 0x02) && !(button & 0x01)) {	// dec immediately pressed
                    	LED_STATE = DEC;
                }
		else {
			LED_STATE = RST;	// repeat
		}

                break;
            case WAIT:
                if ((button & 0x01) && !(button & 0x02)) {
                    	LED_STATE = INC;
                }
                else if ((button & 0x02) && !(button & 0x01)) {
                    	LED_STATE = DEC;
                }
                else if ((button & 0x01) && (button & 0x02)) {
                    	LED_STATE = RST;
                }
		else {
			LED_STATE = WAIT;	// repeat
		}

                break;
            case WAIT_INC_RELEASE:
                if (!button) {
                    	LED_STATE = WAIT;
                }
                else if ((button & 0x02) && !(button & 0x01)) {
                    	LED_STATE = DEC;
                }
                else if ((button & 0x01) && (button & 0x02)) {
                    	LED_STATE = RST;
                }
		else {
			LED_STATE = WAIT_INC_RELEASE;	// repeat
		}

                break;
            case WAIT_DEC_RELEASE:
                if (!button) {
                    	LED_STATE = WAIT;
                }
                else if ((button & 0x01) && !(button & 0x02)) {
                 	LED_STATE = INC;
                }
                else if ((button & 0x01) && (button & 0x02)) {
                    	LED_STATE = RST;
                }
		else {
			LED_STATE = WAIT_DEC_RELEASE;	// repeat
		}

                break;
            case INC:
                if ((button & 0x01) && !(button & 0x02)) {
                    	LED_STATE = WAIT_INC_RELEASE;
                }
                else if ((button & 0x02) && !(button & 0x01)) {
                    	LED_STATE = DEC;
                }
                else if ((button & 0x01) && (button & 0x02)) {
                   	LED_STATE = RST;
                }
		else {
			LED_STATE = INC;	// repeat
		}

                break;
            case DEC:
                if ((button & 0x01) && !(button & 0x02)) {
                    	LED_STATE = INC;
                }
                else if ((button & 0x02) && !(button & 0x01)) {
                    	LED_STATE = WAIT_DEC_RELEASE;
                }
                else if ((button & 0x01) && (button & 0x02)) {
                    	LED_STATE = RST;
                }
		else {
			LED_STATE = DEC;	// repeat
		}

                break;
            default:
                led = 0x07;
                LED_STATE = WAIT;
                break;
        }

        switch (LED_STATE) {
            case RST:
                led = 0x00;
                break;
            case WAIT:			// nothing
                break;
            case WAIT_INC_RELEASE:	// nothing
                break;
            case WAIT_DEC_RELEASE:	// nothing
                break;
            case INC:
                if (led < 9) {	// max 9
                    led++;
                }
                break;
            case DEC:
                if (led > 0) {	// min 0
                    led--;
                }
                break;
        }

        PORTC = led;
	}


	return 1;
}
