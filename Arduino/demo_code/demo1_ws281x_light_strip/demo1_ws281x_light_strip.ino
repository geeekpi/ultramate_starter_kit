#include <FastLED.h>

#define LED_PIN = 7
#define NUM_LEDS 60 

CRGB leds[NUM_LEDS];

void setup() {
	FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
}

void loop() {
	for(int i=0; i<=60; i++) {
		leds[i] = CRGB(0, 0, 255);
		FastLED.show();
		delay(20);
	}
	for(int i=60; i>=0; i--) {
		leds[i] = CRGB(255, 0, 0);
		FastLED.show();
		delay(20);
	}
	for(int i=0; i<=60; i++) {
		leds[i] = CRGB(0, 255, 0);
		FastLED.show();
		delay(20);
	}
	for(int i=60; i>=0; i--) {
		leds[i] = CRGB(127, 127, 0);
		FastLED.show();
		delay(20);
	}
}
