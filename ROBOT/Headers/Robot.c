#include "Robot.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int TimerOverflow = 0;

ISR (TIMER1_OVF_vect) {
	TimerOverflow++;
}
	
void robot_init() {
	
	TIMSK1 |= (1 << TOIE1);                         		//enable timer overflow interrupt
	TCCR1A = 0;                          					//normal operation of timer
	SONAR_DDR = ~(1 << SONAR_ECHO);          				//all pins are out except echo
	SONAR_PORT |= (1 << LWHEEL_PWR) | (1 << RWHEEL_PWR);	//full power to both motors
	SONAR_PORT |= (1 << SONAR_ECHO);                      	//pullup for echo pin
	sei();                                         			//enables global interrupt
	_delay_ms(100);  										//requires reset if not a delay??
}

void sonar_trig() {
	
	SONAR_PORT |= (1 << SONAR_TRIG); 
	_delay_us(10);
	SONAR_PORT &= ~(1 << SONAR_TRIG);
}

unsigned int find_distance() {
	
	long counts;
	unsigned int distance;
	
	//prepare timer
	TCNT1 = 0;                               	//clear timer counter
	TCCR1B |= (1 << ICES1) | (1 << CS10);      	//1 to capture rising edge, no prescale
	TIFR1 |= (1 << ICF1) | (1 << TOV1);         //clear timer & icp flag
		
	//calculate time of pulse
	while((TIFR1 & (1 << ICF1)) == 0) {}        //wait for rising edge
	TCNT1 = 0;                                	//clear timer counter
	TCCR1B &= ~(1 << ICES1);                   	//capture falling edge, still no prescale;
	TIFR1 |= (1 << ICF1) | (1 << TOV1);         //clear timer & icp flag
		
	while((TIFR1 & (1 << ICF1)) == 0) {}        //wait for falling edge
	
	counts = ICR1 + (65535 * TimerOverflow);    //amount of timer counts in pulse       
	TimerOverflow = 0;
	
	return distance = (unsigned int) counts / 58;
}

void robot_navigate(unsigned int distance) {
	
	if(distance >= 20) SONAR_PORT |= (1 << PB2) | (1 << PB4);
	
	else {
		SONAR_PORT &= ~(1 << PB2);
		SONAR_PORT &= ~(1 << PB4);
		_delay_ms(1000);
		SONAR_PORT |= (1 << PB3);
		SONAR_PORT |= (1 << PB4);
		_delay_ms(250);
		SONAR_PORT &= ~(1 << PB3);
		SONAR_PORT &= ~(1 << PB4);
	}		
}