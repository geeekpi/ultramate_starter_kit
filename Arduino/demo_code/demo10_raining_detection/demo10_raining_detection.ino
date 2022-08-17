#define rain_sensor 5

void setup() {
	Serial.begin(9600);
	pinMode(rain_sensor, INPUT);
}

void loop() {
	int value = digitalRead(rain_sensor);
	if (value == 0){
		Serial.println("It's rainning...");
		//Serial.println(value);
		delay(500);
	}
	else {
		Serial.println("It's not rainning...");
		delay(500);
	}
}
