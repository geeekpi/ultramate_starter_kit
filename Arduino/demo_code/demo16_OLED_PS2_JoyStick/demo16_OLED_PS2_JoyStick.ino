#include <Wire.h>
#include "ssd1306.h"
#include <stdio.h>
#include <string.h>
#include "nano_gfx.h"


/*
 * Heart image below is defined directly in flash memory.
 * This reduces SRAM consumption.
 * The image is defined from bottom to top (bits), from left to
 * right (bytes).
 */
const PROGMEM uint8_t heartImage[8] =
{
    0B00001110,
    0B00011111,
    0B00111111,
    0B01111110,
    0B01111110,
    0B00111101,
    0B00011001,
    0B00001110
};

/*
 * Define sprite width. The width can be of any size.
 * But sprite height is always assumed to be 8 pixels
 * (number of bits in single byte).
 */
const int spriteWidth = sizeof(heartImage);


// define PS2_Joystick's Pin out 
int VRx = A0;
int VRy = A1; 
int sw = 7;

char x_str[10];
char y_str[10];

static void spriteDemo()
{
	/* Declare variable that represents our sprite */
	SPRITE sprite1, sprite2, sprite3;
	/* Create sprite at 0, 40 position. the function initialize sprite
	 * structure. */
	sprite1 = ssd1306_createSprite(0, 40, spriteWidth, heartImage);
	sprite2 = ssd1306_createSprite(0, 48, spriteWidth, heartImage);
	sprite3 = ssd1306_createSprite(0, 56, spriteWidth, heartImage);

	for (int i=0; i<128; i++)
	{
		delay(5);
		sprite1.x+=1;
		sprite2.x+=2;
		sprite3.x+=3;

	if (sprite1.x >= ssd1306_displayWidth())
	{
		sprite1.x = 0;
	}
	if (sprite2.x >= ssd1306_displayWidth())
	{
		sprite2.x = 0;
	}
	if (sprite3.x >= ssd1306_displayWidth())
	{
		sprite3.x = 0;
	}
	/* Erase sprite on old place. the library knows old position of the sprite. */

	sprite1.eraseTrace();
	sprite2.eraseTrace();
	sprite3.eraseTrace();

	/* Draw sprite on new place */
	sprite1.draw();
	sprite2.draw();
	sprite3.draw();
	}
}

void setup() {
  //Serial.begin(9600);
  Wire.begin();

  ssd1306_128x64_i2c_init();
  ssd1306_setFixedFont(ssd1306xled_font6x8);
  ssd1306_printFixed(0, 8, "Init I2C device..", STYLE_NORMAL);
  delay(1000);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
	Serial.print("vrx: ");	
	Serial.println(analogRead(VRx));	

	Serial.print("vry: ");	
	Serial.println(analogRead(VRy));	

	sprintf(x_str, "%d", analogRead(VRx));
	sprintf(y_str, "%d", analogRead(VRy));
	

  	ssd1306_printFixed(0, 8, "VRx: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 8, x_str, STYLE_NORMAL);

  	ssd1306_printFixed(0, 16, "VRy: ", STYLE_NORMAL);
  	ssd1306_printFixed(30, 16, y_str, STYLE_NORMAL);
	if (digitalRead(sw) == 0) {
		ssd1306_printFixed(0, 24, "SW: ", STYLE_NORMAL);
		ssd1306_printFixed(30, 24, "Pressed!", STYLE_NORMAL);
		spriteDemo();
	}
	else {
		ssd1306_printFixed(0, 24, "SW: ", STYLE_NORMAL);
		ssd1306_printFixed(30, 24, "Not Pressed!", STYLE_NORMAL);
	}

	delay(100);
	ssd1306_clearScreen();
}
