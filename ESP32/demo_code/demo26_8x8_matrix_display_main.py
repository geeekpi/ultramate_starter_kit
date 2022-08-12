# Hardware SPI bus
# There are two hardware SPI channels that allow faster 
# transmission rates (up to 80Mhz). 
# These may be used on any IO pins that support the required direction and
# are otherwise unused (see Pins and GPIO) but if they are not configured to
# their default pins then they need to pass through an extra layer of GPIO multiplexing,
# which can impact their reliability at high speeds.
# Hardware SPI channels are limited to 40MHz when used on pins other than the default
# ones listed below.
# |-------------------------------|
# |     | HSPI(id=1) | VSPI(id=2) |
# |-------------------------------|
# |sck  |     14     |    18      |
# |-------------------------------|
# |mosi |     13     |    23      |
# |-------------------------------|
# |miso |     12     |    19      |
# |-------------------------------|
# Hardware SPI is accessed via the machine.
# SPI class and has the same methods as software SPI above:
# from machine import Pin, SPI
#
# hspi = SPI(1, 10000000)
# hspi = SPI(1, 10000000, sck=Pin(14), mosi=Pin(13), miso=Pin(12))
# vspi = SPI(2, baudrate=80000000, polarity=0, phase=0, bits=8, 
#           firstbit=0, sck=Pin(18), mosi=Pin(23), miso=Pin(19))
#####################################################################
# 
# 
from machine import Pin, SPI, ADC
import max7219
from utime import sleep


MAX7219_NUM = 1 
MAX7219_INVERT = False
MAX7219_SCROLL_DELAY = 0.05
cs_pin = 2

hspi = SPI(1, 400000, sck=Pin(14), mosi=Pin(13))
display = max7219.Matrix8x8(spi=hspi, cs=Pin(cs_pin), num=MAX7219_NUM)
display.brightness(2)

p = MAX7219_NUM * 8
pota = ADC(Pin(25), atten=ADC.ATTN_11DB)

while True:
    print(pota.read())
    text = 'ADC: {}'.format(pota.read())

    for p in range(MAX7219_NUM * 8, len(text) * -8 - 1, -1):
        display.fill(MAX7219_INVERT)
        display.text(text, p, 1, not MAX7219_INVERT)
        display.show()
        sleep(MAX7219_SCROLL_DELAY)

