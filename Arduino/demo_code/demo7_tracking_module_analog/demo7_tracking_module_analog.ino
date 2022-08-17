#define tracking_module 6
// connect to ~6 pin which supports analog reading.

void setup() {
	pinMode(tracking_module, INPUT);
	Serial.begin(9600);
}

void loop() {
	Serial.print("Tracking Module Analog Reading: ");
	Serial.println(analogRead(tracking_module));
	delay(200);
}
