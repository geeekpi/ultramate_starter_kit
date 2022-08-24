#include <Stepper.h>
#include "Wire.h"
#include "nano_gfx.h"
#include "ssd1306.h"

// set revolution of stepper motor.
const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11.
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// number of steps the motor has taken 
int stepCount = 0;
char val[10];

void setup() {
	// set the speed at 60 rpm 
	myStepper.setSpeed(60);
	// initialize the serial port
	Serial.begin(9600);
	// initialize oled i2c bus
	ssd1306_128x64_i2c_init();
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	ssd1306_clearScreen();
	ssd1306_printFixed(0, 8, "Stepper Motor Testing", STYLE_BOLD);
	delay(2000);
}

void loop() {
	ssd1306_printFixed(0, 8, "Stepper Motor Testing", STYLE_BOLD);
	Serial.println("Clockwise");
	ssd1306_printFixed(0, 16, "Clockwise", STYLE_NORMAL);
	myStepper.step(1);
	stepCount++;
	itoa(stepCount, val, 10);
	ssd1306_printFixed(0, 24, val, STYLE_BOLD);
	delay(500);
	
	// step one revolution in the other direction.
	Serial.println("Counterclockwise");
	ssd1306_printFixed(0, 16, "Counterclockwise", STYLE_NORMAL);
	myStepper.step(1);
	stepCount++;
	itoa(stepCount, val, 10);
	ssd1306_printFixed(0, 24, val, STYLE_BOLD);
	delay(500);
	
	ssd1306_clearScreen();
}
