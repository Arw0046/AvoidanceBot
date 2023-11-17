#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Robot.h"

int main() {
	
	robot_init();
	
	while(1) {
		
		sonar_trig();
		robot_navigate(find_distance());
		
	}
	
	return 0;
}