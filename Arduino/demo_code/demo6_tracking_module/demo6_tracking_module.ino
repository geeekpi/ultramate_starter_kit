#define tracking_module 7

void setup() {
	pinMode(tracking_module, INPUT);
	Serial.begin(9600);
}

void loop() {
	if (digitalRead(tracking_module) == 0) {
		Serial.println("Line Detected!!!");
		Serial.println(digitalRead(tracking_module));
	}
	else {
		Serial.println("No Line Detected!!!");
		Serial.println(digitalRead(tracking_module));
	}
}
