#define SONAR_PORT 		PORTB
#define SONAR_DDR 		DDRB
#define SONAR_TRIG 		PB1
#define SONAR_ECHO 		PB0
#define LWHEEL_F 		PB2
#define LWHEEL_B 		PB3
#define RWHEEL_F 		PB4
#define RWHEEL_B 		PB5
#define LWHEEL_PWR 		PB6
#define RWHEEL_PWR		PB7	

void robot_init();

void sonar_trig();						//sends sound waves out

unsigned int find_distance();					//finds distance to closest object

void robot_navigate(unsigned int distance);		//drives until object is 20cm or less infront
