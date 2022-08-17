#define R 2
#define G 3
#define B 4

void setup() {
	// initializing R/G/B led
	pinMode(R, OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(B, OUTPUT);
}

void loop() {
	digitalWrite(R, HIGH);
	delay(20);
	digitalWrite(R, LOW);
	delay(20);

	digitalWrite(G, HIGH);
	delay(20);
	digitalWrite(G, LOW);
	delay(20);

	digitalWrite(B, HIGH);
	delay(20);
	digitalWrite(B, LOW);
	delay(20);

}
