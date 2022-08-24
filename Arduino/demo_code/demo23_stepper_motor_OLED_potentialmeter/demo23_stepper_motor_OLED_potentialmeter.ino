#include <Stepper.h>
#include "Wire.h"
#include "nano_gfx.h"
#include "ssd1306.h"

// set revolution of stepper motor.
const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11.
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// variable for oled display.
char val[10];

void setup() {
	// initialize the serial port
	Serial.begin(9600);

	pinMode(A0, INPUT);

	// initialize oled i2c bus
	ssd1306_128x64_i2c_init();
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	ssd1306_clearScreen();
	ssd1306_printFixed(0, 8, "Stepper Motor Testing", STYLE_BOLD);
	delay(2000);
}

void loop() {
	ssd1306_printFixed(0, 8, "Stepper Motor Testing", STYLE_BOLD);
	
	// read the sensor value	
	int sensorReading = analogRead(A0);
	
	// map it to a range from 0 to 100
	int motorSpeed = map(sensorReading, 0, 1023, 0, 100);

	ssd1306_printFixed(0, 16, "Speed", STYLE_NORMAL);
	if (motorSpeed > 0) 
	{
		myStepper.setSpeed(motorSpeed);
		myStepper.step(stepsPerRevolution / 100);
		itoa(motorSpeed, val, 10);
	
		ssd1306_printFixed(0, 24, val, STYLE_BOLD);
		delay(20);
		ssd1306_clearScreen();
	}
}
