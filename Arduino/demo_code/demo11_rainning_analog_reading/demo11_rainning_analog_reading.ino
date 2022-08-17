#define rain_module 5

void setup() {
	pinMode(rain_module, INPUT);
	Serial.begin(9600);
}

void loop() {
	Serial.print("Rain module Analog Reading: ");
	Serial.println(analogRead(rain_module));
	delay(500);
}
