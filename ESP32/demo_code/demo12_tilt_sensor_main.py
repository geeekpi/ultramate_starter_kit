from machine import Pin
from time import sleep
from neopixel import NeoPixel


# define ws281x RGB light strip.
# 60 is the number of light.
led = Pin(2, Pin.OUT)
np = NeoPixel(led, 60)

# define tilt sensor.
tilt = Pin(4, Pin.IN)

# define a function to light up the strip.
def light_up(color):
    for i in range(60):
        np[i] = color
        np.write()
        sleep(0.01)


while True:
    if tilt.value() == 1:
        print(tilt.value())
        color = (255, 0, 0)
        light_up(color)
        sleep(0.5)
    else:
        print(tilt.value())
        color = (0, 255, 0)
        light_up(color)
        sleep(0.5)

