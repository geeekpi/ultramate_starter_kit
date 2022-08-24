#include "Wire.h"
#include "nano_gfx.h"
#include "ssd1306.h"

// define flame sensor's AO pin
#define flameSensor A0

void setup() {
	// initialize i2c bus
	ssd1306_128x64_i2c_init();
	// set font
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	// clear screen
	ssd1306_clearScreen();
	// greetings
	ssd1306_printFixed(0, 8, "Flame Sensor Test", STYLE_NORMAL);
	// delay
	delay(2000);
}

void loop() {
	ssd1306_printFixed(0, 8, "Flame Sensor Test", STYLE_NORMAL);
	if (analogRead(flameSensor) < 512)
	   {
		ssd1306_printFixed(0, 16, "Fire alarm!!!!!!!!", STYLE_NORMAL);
		ssd1306_printFixed(0, 24, "Call 911 please!!!", STYLE_NORMAL);
		ssd1306_printFixed(0, 32, "Fire alarm!!!!!!!!", STYLE_NORMAL);
		ssd1306_printFixed(0, 40, "Call 911 please!!!", STYLE_NORMAL);
		ssd1306_printFixed(0, 48, "Fire alarm!!!!!!!!", STYLE_NORMAL);
	   }
	else {
		ssd1306_printFixed(0, 24, "Nothing happened", STYLE_NORMAL);
		ssd1306_printFixed(0, 32, "Everything is OK", STYLE_NORMAL);
		ssd1306_printFixed(0, 48, "No fire alarm...", STYLE_NORMAL);
	}
}
