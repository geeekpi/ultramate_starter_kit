# arduino-cli command 
## Arduino UNO
* create new sketch
```bash
arduino-cli sketch new yourSketchName
```
* compile and upload sketch 
```bash
arduino-cli compile -b arduino:avr:uno -p /dev/ttyACM0 --upload
```
* Arduino Monitor 
```bash
arduino-cli monitor -p /dev/ttyACM0 
```
* Library install 
```bash
arduino-cli lib search yourLibraryName
arduino-cli lib install yourLibraryName
arduino-cli lib unintall yourLibraryName
```
## for other board
* the others:
> arduino:avr:uno
> arduino:avr:pro:cpu=8MHzatmega168
> arduino:avr:pro:cpu=16MHzatmega168
> arduino:avr:pro:cpu=8MHzatmega328
> arduino:avr:pro:cpu=16MHzatmega328
> arduino:avr:nano:cpu=atmega168
> arduino:avr:nano:cpu=atmega328
> arduino:avr:nano:cpu=atmega328old
> arduino:avr:atmegang:cpu=atmega168
> arduino:avr:atmegang:cpu=atmega8
> arduino:avr:leonardo
> arduino:avr:mega:cpu=atmega2560
> arduino:avr:mega:cpu=atmega1280
----
* For example:
If your dev board is Arduino micro which is a miniature version of the Arduino
Leonardo board. It has an ATmega32U4 microcontroller at its heart.
```bash
arduino-cli compile -b arduino:avr:micro -p /dev/ttyACM0 --upload 
```
