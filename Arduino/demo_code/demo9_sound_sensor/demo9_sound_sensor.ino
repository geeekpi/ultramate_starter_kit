#define sound_sensor 13
void setup() {
	pinMode(sound_sensor, INPUT);
	Serial.begin(9600);
}

void loop() {
	Serial.print("sound_sensor : ");
	Serial.println(digitalRead(sound_sensor));
	if (digitalRead(sound_sensor) == 1){
		Serial.println("No sound detected!");
		delay(200);
	}
	else {
		Serial.println("Sound detected!");
		delay(200);
	}
}
