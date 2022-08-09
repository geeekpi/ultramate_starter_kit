from machine import Pin
from time import sleep


# variables setting.
line_detector = Pin(4, Pin.IN)

while True:
    if line_detector.value() == 1: 
        print("No Line Detected!")
    else:
        print("Line Detected!!!")
