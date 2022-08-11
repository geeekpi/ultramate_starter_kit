from machine import Pin
from time import sleep 
from neopixel import NeoPixel


# define rain_sensor, connect to driver board on DO Pin, means data out.
rain_sensor = Pin(4, Pin.IN)

# define ws281x light strip, with 60 lights on it. 
led = Pin(2, Pin.OUT)
np = NeoPixel(led, 60)

while True:
    if rain_sensor.value() == 0:
        print("It is rainning...")
        for i in range(60):
            np[i] = (255,0,0)  # define color R, G, B, range from 0-255.
            np.write()         # light up the strip.
            sleep(0.01)
    else:
        print("It is not rainning...")
        for i in range(60):
            np[i] = (0,255,100) 
            np.write()
            sleep(0.01)



