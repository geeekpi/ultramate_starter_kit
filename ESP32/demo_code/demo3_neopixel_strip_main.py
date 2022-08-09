from machine import Pin, ADC
from time import sleep
from neopixel import NeoPixel
from random import randint


potb = ADC(Pin(4))
led = Pin(2, Pin.OUT)
np = NeoPixel(led, 60) 

while True:
    for i in range(60):
        res = int(potb.read_u16() / 1000.0 * 255 / 100.0)
        np[i] = (res//255+i, randint(0,res), randint(0,res))
        print("Pot:" + str(res))
        np.write()
        sleep(0.01)
