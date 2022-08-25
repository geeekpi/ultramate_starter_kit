#include "Wire.h"
#include "ssd1306.h"


void setup() {
	ssd1306_128x64_i2c_init();
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	ssd1306_clearScreen();
	ssd1306_printFixed(0, 8, "ESP8266 Testing..", STYLE_BOLD);
	delay(2000);
}

void loop() {
	ssd1306_printFixed(0, 8, "ESP8266 Testing..", STYLE_BOLD);
	ssd1306_printFixed(0, 16, "ESP8266 Testing..", STYLE_BOLD);
	ssd1306_printFixed(0, 24, "ESP8266 Testing..", STYLE_BOLD);
	ssd1306_printFixed(0, 32, "ESP8266 Testing..", STYLE_BOLD);
	ssd1306_printFixed(0, 40, "ESP8266 Testing..", STYLE_BOLD);
	delay(2000);
	ssd1306_clearScreen();
}
