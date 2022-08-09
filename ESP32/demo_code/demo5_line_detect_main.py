from machine import Pin
from time import sleep


detector = Pin(4, Pin.IN)

while True:
    if detector.value() == 1: 
        print("No Line Detected!")
    else:
        print("Line Detected!!!")
