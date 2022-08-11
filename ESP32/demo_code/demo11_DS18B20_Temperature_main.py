from machine import Pin
from time import sleep, sleep_ms
from neopixel import NeoPixel
import onewire
import ds18x20


# The OneWire dirver is implemented in software and works on all pins:
# ow = onewire.OneWire(Pin(4)) # create a OneWire bus on GPIO 4.
# ow.scan()  # return a list of devices on the bus
# ow.reset() # reset the bus
# ow.readbyte() # read a byte on the bus
# ow.writebyte(0x12) # write a byte on the bus
# ow.write('123')  # write bytes on the bus
# ow.select_rom(b'12345678') # select a specific device by its ROM code.

# define ds18x20 temperature sensor.
ow = onewire.OneWire(Pin(4)) # create a OneWire bus on GPIO 4.
ds = ds18x20.DS18X20(ow)

# define ws281x RGB light strip
led = Pin(2, Pin.OUT)
np = NeoPixel(led, 60) 
color = (60,40,20)

def get_temp():
    roms = ds.scan()
    ds.convert_temp()
    sleep_ms(750)
    for rom in roms:
        return ds.read_temp(rom)

def light_up(color):
    """color must be a tuple, (R, G, B) format, 
       each argument range from 0-255.
    """
    for i in range(60):
        np[i] = color
        np.write()
        sleep(0.01)


while True:
    temp = get_temp()
    print(temp)
    if temp <= 27.0:
        color = (255, 0, 0) # red
        light_up(color)
    elif temp > 27.0 and temp < 28.0:
        color = (0, 0, 255) # blue
        light_up(color)
    elif temp > 30.0:
        color = (0, 255, 20) # green
        light_up(color)

