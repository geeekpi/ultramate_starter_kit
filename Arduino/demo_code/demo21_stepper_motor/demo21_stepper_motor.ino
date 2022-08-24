#include <Stepper.h>

// change this to the number of steps on your motor.
#define STEPS 100

// create an instance of the stepper class. specifying 
// the number of steps of the motor and the pins it's 
// attached to.
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input 
int previous = 0;


void setup() {
	// set the speed of the motor to 30 RPMS
	stepper.setSpeed(30);
	// open serial port 
	Serial.begin(9600);
}

void loop() {
	// get the sensor values
	int val = analogRead(0);

	// print val's value
	Serial.println(val);

	// move a number of steps equal to the change in the 
	// sensor reading 
	stepper.step(val - previous);

	// remember the previous value of the sensor
	previous = val;
}
