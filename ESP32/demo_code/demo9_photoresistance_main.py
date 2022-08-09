from machine import Pin
from time import sleep


# connect to 4 pin. and set direction to Pin.IN, so that ESP32 can read the level from Pin 4. 
photo_pin = Pin(4, Pin.IN)

while True:
    if photo_pin.value() == 0:
        print("Sufficient Lighting...")
        sleep(0.2)
    elif photo_pin.value() == 1:
        print("Insufficient Lighting...")
        sleep(0.2)

