from machine import Pin, ADC
from time import sleep
from neopixel import NeoPixel
from random import randint
import math


# connect the potentiometer's potb to pin 4. 
# and reset the reference voltage level to 3V, using: atten keyword and setting # the valid value as : ADC.ATTN_11DB:  11dB attenuation 
potb = ADC(Pin(4),atten=ADC.ATTN_11DB)

# define ws281x neopixel strip object. 60 means strip has 60 single ws2812 
# lights. 
led = Pin(2, Pin.OUT)
np = NeoPixel(led, 60) 

# define a map function.
def newmap(x, in_min, in_max, out_min, out_max):
    # print((x-in_min) * (out_max-out_min) / (in_max - in_min) + out_min)
    return (x-in_min) * (out_max-out_min) / (in_max - in_min) + out_min

while True:
    for i in range(60):
        res = newmap(potb.read(), 0, 4095, 0, 255)
        res = math.floor(res)
        print(res)
        r = newmap(res, 0, 255, 0, 255)
        r = math.floor(r)
        g = newmap(res, 0, 255, 10, 80)
        g = math.floor(g)
        b = newmap(res, 0, 255, 100, 0)
        b = math.floor(b)
        np[i] = (r, g, b)
        np.write()
        sleep(0.2)
