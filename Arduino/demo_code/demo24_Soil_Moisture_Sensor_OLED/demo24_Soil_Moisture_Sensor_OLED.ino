#include "Wire.h"
#include "nano_gfx.h"
#include "ssd1306.h"

// set where the pin on arduino is connect to soil moisture sensor
#define soilMoistureSensor A0

// set variable to store char value of soil moiture data 
char val[20]; 

void setup() {
	// initialize i2c bus
	ssd1306_128x64_i2c_init();
	// set font
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	// clear screen
	ssd1306_clearScreen();
	// greetings 
	ssd1306_printFixed(0, 8, "Soil Moisture Detect", STYLE_BOLD);
	delay(2000);
}

void loop() {
	ssd1306_printFixed(0, 8, "Soil Moisture Detect", STYLE_BOLD);
	// reading sensor value from A0 pin 
	int sensorvalue = analogRead(soilMoistureSensor);
	 
	// convert the data from integer to char array
	itoa(sensorvalue, val, 10);
	ssd1306_printFixed(0, 16, "Moisture: ", STYLE_BOLD);
	ssd1306_printFixed(64, 16, val, STYLE_BOLD);
	ssd1306_printFixed(0, 24, "Status: ", STYLE_BOLD);
	if (sensorvalue > 800)
	{
		ssd1306_printFixed(64, 24, "DRY", STYLE_BOLD);
		ssd1306_printFixed(0, 32, "Neet watering!!!", STYLE_BOLD);
		ssd1306_printFixed(0, 40, "Neet watering!!!", STYLE_BOLD);
		ssd1306_printFixed(0, 48, "Neet watering!!!", STYLE_BOLD);
	}
	else {
		ssd1306_printFixed(64, 24, "Still wet ", STYLE_BOLD);
	}
	delay(1000);
	ssd1306_clearScreen();
}
