#define hall_sensor 6

void setup() {
	pinMode(hall_sensor, INPUT);
	Serial.begin(9600);
}

void loop() {
	if (digitalRead(hall_sensor) == 0)
	{
		//Serial.print(digitalRead(hall_sensor));
		Serial.println("Detected magnetic field");
		
		delay(20);
	}
	else {
		//Serial.print(digitalRead(hall_sensor));
		Serial.println("No magnetic field Detected!");
		delay(20);
	}
}
