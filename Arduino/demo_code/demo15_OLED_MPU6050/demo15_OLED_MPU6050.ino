#include <Wire.h>
#include <MPU6050.h>
#include "ssd1306.h"


MPU6050 imu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

char ax_buf[10];
char ay_buf[10];
char az_buf[10];
char gx_buf[10];
char gy_buf[10];
char gz_buf[10];

#define OUTPUT_READABLE_ACCELGYRO

#define LED_PIN 13
bool blinkState = false;


void setup() {
  ssd1306_128x64_i2c_init();
  ssd1306_setFixedFont(ssd1306xled_font6x8);
  Wire.begin();
  Serial.begin(9600);
  //Serial.println("Initializing I2C device...");
  ssd1306_printFixed(0, 8, "Init I2C device..", STYLE_NORMAL);
  imu.initialize();
  //Serial.println("Testing device connections...");
  //Serial.println(imu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
	//ssd1306_clearScreen();
	imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
#ifdef OUTPUT_READABLE_ACCELGYRO
	//Serial.print("a/g: \t");
	dtostrf(ax, 6, 1, ax_buf);
	dtostrf(ay, 6, 1, ay_buf);
	dtostrf(az, 6, 1, az_buf);
	dtostrf(gx, 6, 1, gx_buf);
	dtostrf(gy, 6, 1, gy_buf);
	dtostrf(gz, 6, 1, gz_buf);

  	ssd1306_printFixed(0, 8, "ax: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 8, ax_buf, STYLE_NORMAL);

  	ssd1306_printFixed(0, 16, "ay: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 16, ay_buf, STYLE_NORMAL);

  	ssd1306_printFixed(0, 24, "az: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 24, az_buf, STYLE_NORMAL);

  	ssd1306_printFixed(0, 32, "gx: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 32, gx_buf, STYLE_NORMAL);

  	ssd1306_printFixed(0, 40, "gy: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 40, gy_buf, STYLE_NORMAL);

  	ssd1306_printFixed(0, 48, "gz: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 48, gz_buf, STYLE_NORMAL);
	delay(1000);
	ssd1306_clearScreen();

#endif
	blinkState = !blinkState;
	digitalWrite(LED_PIN, blinkState);
	//ssd1306_drawBitmap(0, 0, 32, 32, aaa);
	//delay(3000);
	//ssd1306_clearScreen();
}
