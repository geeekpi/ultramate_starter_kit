#define flame_sensor 5

void setup() {
	pinMode(flame_sensor, INPUT);
	Serial.begin(9600);
}

void loop() {
	if (digitalRead(flame_sensor) == 0) {
		Serial.println("Fire Alarm!!!");
		delay(200);
	}
	else {
		Serial.println("Everything is Fine!!!");
		delay(200);
	}
}
