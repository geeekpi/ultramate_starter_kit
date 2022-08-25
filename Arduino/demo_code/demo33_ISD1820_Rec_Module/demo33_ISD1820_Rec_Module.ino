int P_E = 5;
int REC = 6;
int FLAME_SENSOR = 12;

void setup() {
	Serial.begin(9600);
	pinMode(P_E, INPUT_PULLUP);
	pinMode(REC, OUTPUT);

	pinMode(FLAME_SENSOR, INPUT);

	// Call record function
	record();
}

void record(){
// Record for 10 seconds
digitalWrite(REC, HIGH);
delay(100);
digitalWrite(REC, LOW);
delay(5000);
digitalWrite(REC, HIGH);
}

void loop() {
	Serial.println(digitalRead(FLAME_SENSOR));

	if (digitalRead(FLAME_SENSOR) == 0) {
		Serial.println("Play_E start...");
		digitalWrite(P_E, HIGH);
		delay(100);
		digitalWrite(P_E, LOW);
		delay(1000);
		Serial.println("Play_E stop...");
	}
	delay(100);
}

