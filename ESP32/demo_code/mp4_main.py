from machine import Pin
from time import sleep


ADKey2 = Pin(4, Pin.OUT)
ADKey1 = Pin(0, Pin.OUT)
# fire = Pin(15, Pin.IN)


while True:
    #if fire.value() == 0:
    ADKey2.value(1)
    ADKey1.value(0)


