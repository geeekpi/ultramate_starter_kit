# Readme 
1. FastLED library is required.
2. if you are using arduino-cli command line tool, install FastLED library as
   following command:
```bash
arduino-cli lib install FastLED
```
3. Compile and upload sketch.
```bash
arduino-cli compile -b arduino:avr:uno -p /dev/ttyACM0 --upload 
```
4. Start Monitor:
```bash
arduino-cli monitor -p /dev/ttyACM0 
```

