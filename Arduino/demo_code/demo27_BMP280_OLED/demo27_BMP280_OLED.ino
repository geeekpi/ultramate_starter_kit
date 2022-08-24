#include "Wire.h"
#include "nano_gfx.h"
#include <BMP280_DEV.h>
#include "ssd1306.h"

// create the temperature, pressure, altitude variables
float temperature, pressure, altitude;
char t[100];
char p[100];
char a[100];

BMP280_DEV bmp280;  // Set up I2C communications 

//  Alternatively an auxiliary or secondary I2C (wire) port can be specified:
// BMP280_DEV bmp280(Wire1); //  Set up I2C communications on a secondary port
// By default the library uses the BMP280's I2C address 0x77. (To use the
// alternate I2C address: 0x76, see the begin() function below.
// More detials:  https://github.com/MartinL1/BMP280_DEV

void setup() {
	// set serial port 
	Serial.begin(9600);
	
	// Initialise I2c OLED
	ssd1306_128x64_i2c_init();

	// set font 
	ssd1306_setFixedFont(ssd1306xled_font6x8);

	// clear screen
	ssd1306_clearScreen();

	// greetings 
	ssd1306_printFixed(0, 8, "BMP280 Testing...", STYLE_BOLD);

	// sleep a while to let oled show the greetings.
	delay(2000);

	// Initialise the BMP280 with default configuration
	if (bmp280.begin(NORMAL_MODE) == 1) {
		ssd1306_printFixed(0, 16, "BMP280 Initialise OK", STYLE_BOLD);
	}
	else {
		ssd1306_printFixed(0, 16, "BMP280 Initialise failed...", STYLE_BOLD);
	}

	// Set the standby time to 1s
	bmp280.setTimeStandby(TIME_STANDBY_1000MS);

	// Start continuous conversions, separated by the standby time
	bmp280.startNormalConversion();
}

void loop() {
	ssd1306_printFixed(0, 8, "BMP280 Testing...", STYLE_BOLD);
	if (bmp280.getMeasurements(temperature, pressure, altitude)) {
		Serial.println(temperature);
		Serial.println(pressure);
		Serial.println(altitude);
		char t[20];
		char p[20];
		char a[20];
		// turn float value to a string.
		// dtostrf(float_value, min_width, num_digits_after_decimal,
		// where_to_store_string)
		dtostrf(temperature, 5, 2, t);
		dtostrf(pressure, 5, 2, p);
		dtostrf(altitude, 5, 2, a);

		// draw them on oled screen.
		// Temperature
		ssd1306_printFixed(0, 16, "Temperature: ", STYLE_NORMAL);
		ssd1306_printFixed(68, 16, t, STYLE_NORMAL);
		ssd1306_printFixed(120, 16, "C", STYLE_NORMAL);

		// pressure
		ssd1306_printFixed(0, 24, "Pressure: ", STYLE_NORMAL);
		ssd1306_printFixed(68, 24, p, STYLE_NORMAL);
		ssd1306_printFixed(120, 16, "hPa", STYLE_NORMAL);

		// altitude
		ssd1306_printFixed(0, 32, "Altitude: ", STYLE_NORMAL);
		ssd1306_printFixed(68, 32, a, STYLE_NORMAL);
		ssd1306_printFixed(120, 16, "m", STYLE_NORMAL);
	}
	delay(500);
}

