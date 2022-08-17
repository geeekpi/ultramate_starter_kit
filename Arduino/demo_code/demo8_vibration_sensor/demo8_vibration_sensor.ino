#define vibration_sensor 9

void setup() {
	pinMode(vibration_sensor, INPUT);
	Serial.begin(9600);
}

void loop() {
	if (digitalRead(vibration_sensor) == 0) {
		Serial.print("vibration detected!!!");
		Serial.println(digitalRead(vibration_sensor));
	}
	else {
		Serial.print("No vibration detected!!!");
		Serial.println(digitalRead(vibration_sensor));
	}
}
