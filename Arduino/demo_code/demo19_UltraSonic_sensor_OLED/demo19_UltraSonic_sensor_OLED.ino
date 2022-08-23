#include "Wire.h"
#include "ssd1306.h"
#include "nano_gfx.h"

#define echoPin 2  // attach pin D2 Arduino to pin Echo of Ultrasonic sensor.
#define trigPin 3  // attach pin D3 Arduino to pin Trig of Ultrasonic sensor.

// defines variables
long duration;  // variables for the duration of sound wave
int distance;  // variables for the distance measurement
char result[10]; // variables for the char data for oled screen.

void setup() {
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT 
	pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT 
	Serial.begin(9600);
	Serial.println("Ultrasonic sensor testing...");
	ssd1306_128x64_i2c_init(); // init i2c, it is very important.
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	ssd1306_clearScreen();
	//ssd1306_negativeMode();
	ssd1306_printFixed(ssd1306_displayWidth()/2-64, ssd1306_displayHeight()/2-32,
			"Starting...", STYLE_NORMAL);
	//ssd1306_positiveMode();
	delay(2000);
}

void loop() {
	ssd1306_clearScreen();
	ssd1306_printFixed(0, 8, "Distance Detection: ", STYLE_NORMAL);

	// Clears the trigPin condition
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);

	// Calculating the distance
	distance = duration * 0.034 / 2; 

	//Speed of sound wave divided by 2 ( go and back)

	//convert it from double or float to a char format
	dtostrf(distance, 5, 2, result);

	// draws on oled screen
	ssd1306_printFixed(0, 24, result, STYLE_BOLD);

	ssd1306_printFixed(32, 24, "CM", STYLE_BOLD);
	delay(1000);
}
