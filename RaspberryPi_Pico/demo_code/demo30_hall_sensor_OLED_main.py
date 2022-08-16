from machine import Pin, ADC, I2C
from time import sleep
from ssd1306 import SSD1306_I2C
import framebuf


# define width and height
WIDTH = 128
HEIGHT = 64

# create instance of i2c bus.
bus = I2C(1, scl=Pin(15), sda=Pin(14), freq=2000000)

# create oled object by using SSD1306_I2C
oled = SSD1306_I2C(WIDTH, HEIGHT, bus)

oled.fill(0) # clear screen
oled.show()

hall_sensor = ADC(Pin(26))  # define hall sensor connected Pin number, GP26 ADC Pin, connect to hall's AO pin.


while True:
    oled.text("Hall Sensor Detection", 0, 0)
    oled.show()
    oled.text("V: {}".format(hall_sensor.read_u16()), 20, 30)
    oled.show()
    sleep(0.1)
    oled.fill(0)
    oled.show()
  