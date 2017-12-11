/*
 * main.c
 *
 *  Created on: Nov 28, 2017
 *      Author: manf
 */

#include <avr/io.h>
#include "tiny10test.h"

int main() {
	init();
	loop();
}

void init() {
	//Initialize 16 bit pwm

	//PRR.PRTIM0 should be zero, nobody needs PRADC so turning it on
	PRR = _BV(PRADC);	// shutting down adc in this case, leaving PRTIM0 zero
						// for timer/counter0 being turned on

	//Select mode:
	// OC0B Enabled, non inverting. OC0A Disconnected
	// Selecting fast PWM mode 15
	TCCR0A = _BV(COM0B1) | _BV(WGM00) | _BV(WGM01);
	TCCR0B = _BV(WGM02) | _BV(WGM03) | _BV(CS00); // no prescaler

	// Well, Now setting TOP Value (OCR1A)
	OCR0A = 127; // make TOP bit lower
				 // (Mode 15 TOP: OCR1A	Bottom 0, Fast PWM
				 // here we get over 60 khz at 8 mhz

	OCR0B = 32;  // 25% duty

	DDRB |= _BV(DDB1); //set port as output



}

void loop() {
	for (;;) {
	}
}
