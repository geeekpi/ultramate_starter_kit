# Device Control
Allows Arduino boards to control a variety of servo motors.
This library can control a great number of servos. It makes careful use of
timers: the library can control 12 servos using only 1 timer. On the Arduino Due
you can control up to 60 servos.

## Compatiblility 
This library is compatible with the avr, megaavr, sam, samd, nrf52, stm32f4, mbed, mbed_nano, mbed_portenta, mbed_rp2040 architectures so you should be able to use it on the following Arduino boards:

* Arduino Micro
* Arduino Leonardo
* Arduino Mega
* Arduino Due
* Arduino MKR FOX 1200
* Arduino MKR GSM 1400
* Arduino MKR NB 1500
* Arduino MKR VIDOR 4000
* Arduino MKR WAN 1300 (LoRa connectivity)
* Arduino MKR WAN 1310
* Arduino MKR WiFi 1010
* Arduino MKR ZERO (I2S bus & SD for sound, music & digital audio data)
* Arduino MKR1000 WIFI
* Arduino Nano
* Arduino Nano 33 BLE
* Arduino Nano 33 IoT
* Arduino Nano Every
* Arduino Uno
* Arduino Uno WiFi REV2
* Arduino Yún
* Arduino Zero
* Portenta H7

## Releases
To use this library, open the Library Manager in the Arduino IDE and install it from there.

* 1.1.8 (latest)
* 1.1.7
* 1.1.6
* 1.1.5
* 1.1.4
* 1.1.3
* 1.1.2
* 1.1.1
* 1.1.0
* 1.0.3
* 1.0.2
* 1.0.1
* 1.0.0

## Usage
This library allows an Arduino board to control RC (hobby) servo motors. Servos have integrated gears and a shaft that can be precisely controlled. Standard servos allow the shaft to be positioned at various angles, usually between 0 and 180 degrees. Continuous rotation servos allow the rotation of the shaft to be set to various speeds.

The Servo library supports up to 12 motors on most Arduino boards and 48 on the Arduino Mega. On boards other than the Mega, use of the library disables analogWrite() (PWM) functionality on pins 9 and 10, whether or not there is a Servo on those pins. On the Mega, up to 12 servos can be used without interfering with PWM functionality; use of 12 to 23 motors will disable PWM on pins 11 and 12.

To use this library:
<pre>
#include <Servo.h>
</pre>
## Circuit
Servo motors have three wires: power, ground, and signal. The power wire is typically red, and should be connected to the 5V pin on the Arduino board. The ground wire is typically black or brown and should be connected to a ground pin on the Arduino board. The signal pin is typically yellow, orange or white and should be connected to a digital pin on the Arduino board. Note that servos draw considerable power, so if you need to drive more than one or two, you’ll probably need to power them from a separate supply (i.e. not the 5V pin on your Arduino). Be sure to connect the grounds of the Arduino and external power supply together.

## How to install servo library via arduino-cli command line tool? 
```bash
arduino-cli lib install servo
```
that's it.
