from machine import Pin
from time import sleep


# PIR sensor Pin
PIR = Pin(4, Pin.IN)

while True:
    if PIR.value() == 1:
        print("Motion Detected!")
        sleep(0.2)
    else:
        print("No Motion Detected!!")
        sleep(0.2)
