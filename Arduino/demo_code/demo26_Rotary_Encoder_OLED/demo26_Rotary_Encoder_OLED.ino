#include "Wire.h"
#include "nano_gfx.h"
#include "ssd1306.h"

// Rotary Encoder Inputs
#define CLK 2
#define DT 3
#define SW 4

// variables
int counter = 0;
int currentStateCLK;
int lastStateCLK;

char number[15];
unsigned long lastButtonPress = 0;


void setup() {
	// initialize i2c bus for oled
	ssd1306_128x64_i2c_init();
	// set font
	ssd1306_setFixedFont(ssd1306xled_font6x8);
	// clear screen
	ssd1306_clearScreen();
	// greetings
	ssd1306_printFixed(0, 8, "Rotary Encoder Status", STYLE_BOLD);
	delay(2000);

	// Set encoder pins are Inputs
	pinMode(CLK, INPUT);
	pinMode(DT, INPUT);
	pinMode(SW, INPUT_PULLUP);

	// Read the initial state of CLK
	lastStateCLK = digitalRead(CLK);
}

void loop() {
	//ssd1306_clearScreen();
	ssd1306_printFixed(0, 8, "Rotary Encoder Status", STYLE_BOLD);

	// Read the current state of CLK
	currentStateCLK = digitalRead(CLK);

	// If last and current state of CLK are different, then 
	// pulse occurred, React to only 1 state change to avoid double counter
	if (currentStateCLK != lastStateCLK && currentStateCLK != 1) {
		
		// If the DT state is different than the CLK state then 
		// encoder is rotating CCW so decrement 
		if (digitalRead(DT) != currentStateCLK) 
		{
			counter++;
			ssd1306_printFixed(0, 16,"Direction:  ", STYLE_BOLD);
			ssd1306_printFixed(68, 16, "CW ", STYLE_BOLD);

			ssd1306_printFixed(0, 24,"Number:  ", STYLE_BOLD);
			itoa(counter, number, 10); 
			ssd1306_printFixed(68, 24, number, STYLE_BOLD);
		}
		else {
			counter--;
			ssd1306_printFixed(0, 16,"Direction:  ", STYLE_BOLD);
			ssd1306_printFixed(68, 16, "CCW", STYLE_BOLD);
			ssd1306_printFixed(0, 24,"Number:  ", STYLE_BOLD);
			itoa(counter, number, 10); 
			ssd1306_printFixed(68, 24, number, STYLE_BOLD);
		}
	}
	 // remember last CLK state
	lastStateCLK = currentStateCLK;

	 // Read the button state
	int btnState = digitalRead(SW);

	// If we detect LOW signal, button is pressed.
	if (btnState == LOW) {
		// If 50ms have passed since last LOW pulse, it means that the 
		// button has been pressed, released and pressed again
		if (millis() - lastButtonPress > 50) {
			ssd1306_printFixed(0, 48, "BTN Status: ", STYLE_BOLD);
			ssd1306_printFixed(68, 48, "Pressed", STYLE_BOLD);
		}
		else {
			ssd1306_printFixed(0, 48, "BTN Status: ", STYLE_BOLD);
			ssd1306_printFixed(68, 48, "           ", STYLE_BOLD);

		}

		// Remember last button press evend
		lastButtonPress = millis();
	}
	// Put in a slight delay to help debounce the reading 
	delay(1);
}
