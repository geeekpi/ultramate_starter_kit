from machine import Pin, I2C
from time import sleep
import bmp280


# There are two hardware I2C peripherals with identifiers 0 and 1. 
# Any available output-capable pins can be used for SCL and SDA but
# the defaults are given below.
# ------------------------
# |     | I2C(0) | I2C(1)|
# ------------------------
# | SCL |  18    |  25   |
# | SDA |  19    |  26   |
# ------------------------
# The driver is accessed via the machine.I2C class and has the same methods
# as software I2C. 
# example code
# from machine import Pin, I2C
# i2c = I2C(0)
# i2c = I2C(1, scl=Pin(5), sda=Pin(4), freq=400000)
########################################################

i2c = I2C(1, scl=Pin(5), sda=Pin(4), freq=400000)

while True:
    bmp = bmp280.BMP280(i2c=i2c)
    temp = bmp.temperature
    hum = bmp.humidity
    pres = bmp.pressure

    print('T: ', temp)
    print('H: ', hum)
    print('P: ', pres)
    sleep(0.02)
