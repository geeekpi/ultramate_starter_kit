#include <Wire.h>
#include <MPU6050.h>

MPU6050 imu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO

#define LED_PIN 13
bool blinkState = false;


void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Initializing I2C device...");
  imu.initialize();
  Serial.println("Testing device connections...");
  Serial.println(imu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
	imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
#ifdef OUTPUT_READABLE_ACCELGYRO
	Serial.print("a/g: \t");
	Serial.print(ax);Serial.print("\t");
	Serial.print(ay);Serial.print("\t");
	Serial.print(az);Serial.print("\t");
	Serial.print(gx);Serial.print("\t");
	Serial.print(gy);Serial.print("\t");
	Serial.println(gz);
#endif
	blinkState = !blinkState;
	digitalWrite(LED_PIN, blinkState);
}
