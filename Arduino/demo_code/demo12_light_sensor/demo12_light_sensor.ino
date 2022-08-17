#define light_sensor 5

void setup() {
	pinMode(light_sensor, INPUT);
	Serial.begin(9600);
}

void loop() {
	// no light - 1, light - 0.
	if (digitalRead(light_sensor) == 0) {
		Serial.println("Light Detected...");
		delay(200);
	}
	else {
		Serial.println("No Light Detected...");
		delay(200);
	}
}
