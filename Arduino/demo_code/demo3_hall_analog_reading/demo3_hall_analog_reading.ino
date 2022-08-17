#define hall_sensor 6

void setup() {
	pinMode(hall_sensor, INPUT);
	Serial.begin(9600);
}

void loop() {
		Serial.print("Magnetic field value is: ");

		Serial.println(analogRead(hall_sensor));
		
		delay(20);
}
