from machine import Pin
from time import sleep


sensor = Pin(4, Pin.IN)

while True:
    if sensor.value() == 1: 
        print(sensor.value())
    else:
        print("No detect")

