#include "DHTStable.h"
#include "ssd1306.h"
#include "nano_gfx.h"
#include "Wire.h"


DHTStable DHT;

#define DHT11_PIN 5  // Digital Pin connected to the DHT sensor.

char temperature[10];
char humidity[10];

void setup() {
	Serial.begin(9600);
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	ssd1306_128x64_i2c_init();
	ssd1306_clearScreen();
}

void loop() {
	Serial.print("DHT11, \t");
	int chk = DHT.read11(DHT11_PIN);
	switch(chk)
	{
	case DHTLIB_OK:
		//Serial.print("OK, \t");
		ssd1306_printFixed(0, 0, "DHT Status: ", STYLE_NORMAL);
		ssd1306_printFixed(64, 0, " OK ", STYLE_NORMAL);
		break;
	case DHTLIB_ERROR_CHECKSUM:
		//Serial.print("Checksum error, \t");
		ssd1306_printFixed(0, 8, "Checksum: ", STYLE_NORMAL);
		ssd1306_printFixed(30, 8, "Error ", STYLE_NORMAL);
		break;
	case DHTLIB_ERROR_TIMEOUT:
		//Serial.print("Time out error, \t");
		ssd1306_printFixed(0, 16, "Timeout: ", STYLE_NORMAL);
		ssd1306_printFixed(30, 16, "Error ", STYLE_NORMAL);
		break;
	default:
		ssd1306_printFixed(0, 16, "Unknown: ", STYLE_NORMAL);
		ssd1306_printFixed(30, 16, "Error ", STYLE_NORMAL);
		//Serial.print("Unknown Error, \t");
		break;
	}
	//Display data
	/*
	Serial.print(DHT.getHumidity(), 1);
	Serial.print(",\t");
	Serial.println(DHT.getTemperature(), 1);
	delay(2000);
	*/
	dtostrf(DHT.getTemperature(), 5, 2,temperature); 
	dtostrf(DHT.getHumidity(), 5, 2, humidity); 

	ssd1306_printFixed(0, 24, "Temperature: ", STYLE_NORMAL);
	ssd1306_printFixed(55, 24, temperature, STYLE_NORMAL);
	ssd1306_printFixed(0, 32, "--------------------------------", STYLE_NORMAL);
	ssd1306_printFixed(0, 40, "Humidity: ", STYLE_NORMAL);
	ssd1306_printFixed(55, 40, humidity, STYLE_NORMAL);

	delay(2000);

	ssd1306_clearScreen();
}

