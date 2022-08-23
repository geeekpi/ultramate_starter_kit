#include "Wire.h"
#include "ssd1306.h"
#include "nano_gfx.h"

#define PIR 7

char result[10];

void setup() {
	pinMode(PIR, INPUT);
	Serial.begin(9600);
	ssd1306_128x64_i2c_init();
	ssd1306_clearScreen();
	ssd1306_setFixedFont(ssd1306xled_font6x8);
}

void loop() {
	ssd1306_clearScreen();
	ssd1306_printFixed(0, 8, "Motion Detection:", STYLE_NORMAL);

	//Serial.println(digitalRead(PIR));	

	itoa(digitalRead(PIR), result, 10);  // convert int to string. 

	ssd1306_printFixed(0,16, result, STYLE_NORMAL);
	if (digitalRead(PIR) == 1)
	{
		ssd1306_printFixed(0,24, "Motion detected!", STYLE_NORMAL);
		delay(1000);
	}
	else {
		ssd1306_printFixed(0, 24, "No Motion Detected!", STYLE_NORMAL);
		delay(1000);
	}
}
