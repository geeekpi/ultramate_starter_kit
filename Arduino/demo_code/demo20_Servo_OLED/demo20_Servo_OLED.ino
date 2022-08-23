#include <Servo.h>
#include "Wire.h"
#include "nano_gfx.h"
#include "ssd1306.h"

Servo myservo; // create servo object to control a Servo

int pos = 0; //variable to store the servo position 
char pos_val[10]; // variable to pos_val for OLED screen to display

void setup() {
	myservo.attach(9); // attaches the servo on pin 9 to the Servo object
	ssd1306_128x64_i2c_init(); // init i2c for oled
	ssd1306_clearScreen();
	ssd1306_setFixedFont(ssd1306xled_font6x8); // set fonts
	ssd1306_printFixed(0, 8, "Servo Status Monitor", STYLE_NORMAL); //greetings 
	delay(1000);
}

void loop() {
	for (pos=0; pos<=180; pos++) {
		ssd1306_printFixed(0, 8, "Servo Status Monitor", STYLE_NORMAL); //greetings 
		itoa(pos, pos_val, 10);
		ssd1306_printFixed(0, 24, pos_val, STYLE_BOLD);
		ssd1306_printFixed(32, 24, "Degree", STYLE_BOLD);
		myservo.write(pos);
		delay(15);
		ssd1306_clearScreen();
	}
	for (pos=180; pos>=0; pos--) {
		ssd1306_printFixed(0, 8, "Servo Status Monitor", STYLE_NORMAL); //greetings 
		itoa(pos, pos_val, 10);
		ssd1306_printFixed(0, 24, pos_val, STYLE_BOLD);
		ssd1306_printFixed(32, 24, "Degree", STYLE_BOLD);
		myservo.write(pos);
		delay(15);
		ssd1306_clearScreen();
	}
}
