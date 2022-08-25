#include "Wire.h"
#include <ESP8266WiFi.h>
#include "ssd1306.h"

int x = 0;

void setup() {
	ssd1306_128x64_i2c_init();
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	ssd1306_clearScreen();
	ssd1306_printFixed(0, 8, "ESP8266 WIFI info", STYLE_BOLD);
	delay(2000);

	WiFi.begin("TP-208","stm32f429");
}

void loop() {
	ssd1306_printFixed(0, 8, "ESP8266 WIFI info", STYLE_BOLD);
	ssd1306_printFixed(0, 16, "Connecting", STYLE_BOLD);
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		ssd1306_printFixed(48+x, 16, ".", STYLE_BOLD);
		x++;
	}

	ssd1306_printFixed(0, 38, "Connected, IP addr: ", STYLE_BOLD);
	char ip[48]; 
	ip = WiFi.localIP();
	ssd1306_printFixed(0, 46, ip, STYLE_BOLD);

}
