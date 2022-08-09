from machine import Pin, ADC
from time import sleep
from neopixel import NeoPixel
from random import randint


led = Pin(2, Pin.OUT)
potA = ADC(Pin(4))
potB = ADC(Pin(0))

np = NeoPixel(led, 60)
while True:
    r = randint(0, 255)
    g = randint(0, 255) 
    b = randint(0, 255)
    raw_data_A = (3.3 / 4096) * potA.read() 
    raw_data_B = (3.3 / 4096) * potB.read() 
    raw_data = (raw_data_A + raw_data_B) * 100.0
    print(r, g, b, raw_data)
    for i in range(60):
        np[i] = (int(255 - r*raw_data), int(255 - g*raw_data), int(255 - b*raw_data))
        np.write()
        sleep(0.01)

