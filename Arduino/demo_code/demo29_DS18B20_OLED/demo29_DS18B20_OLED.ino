#include "Wire.h"
#include <ssd1306.h>
#include <nano_gfx.h>
#include <DS18B20.h>
#include <OneWire.h>


// 1-wire protocol, connect outpin of DS18B20 to arduino Pin 2
#define pin 2

// variables for oled display temperature data.
float temp;
char val[20];

// Create instance of DS18B20 object.
DS18B20 ds(pin);

void setup() {
	//  for testing 
	// Serial.begin(9600);
	// initialize oled i2c bus
	ssd1306_128x64_i2c_init();
	// set font
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	// clear screen
	ssd1306_clearScreen();
	// greetings 
	ssd1306_printFixed(0, 8, "DS18B20 Temperature", STYLE_BOLD);
	delay(2000);
}

void loop() {
	ssd1306_printFixed(0, 8, "DS18B20 Temperature", STYLE_BOLD);
	while (ds.selectNext()) {
		//Serial.println(ds.getTempC());
	    temp = ds.getTempC();
		// convert double to string 
		dtostrf(temp, 5, 2, val);
		//draw on screen
		ssd1306_printFixed(0, 24, "Temperature:", STYLE_BOLD);
		ssd1306_printFixed(80, 24, val, STYLE_BOLD);
		ssd1306_printFixed(112, 24, "*C", STYLE_BOLD);
	}
}
