from machine import Pin, ADC, I2C
from time import sleep
from ssd1306 import SSD1306_I2C
import framebuf


# Define width and height
WIDTH = 128
HEIGHT = 64

# i2c bus
bus = I2C(1, scl=Pin(15), sda=Pin(14), freq=2000000)

# define oled object
oled = SSD1306_I2C(WIDTH, HEIGHT, bus)

# define pot pin connection to GP26 which is ADC.
pot = ADC(Pin(26))  

# define a map function to convert 200 - 65535 to 0 to 128.
def mapValue(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

# draw another FrameBuffer on top of the current one at the given coordinates.
# buf = framebuf.FrameBuffer(bytearray(8*8*1), 8, 8, framebuf.MONO_VLSB)
# buf.line(12, 12, 7,7,1)
# oled.blit(buf, 15, 15, 0)
# oled.show()

while True:

    """
    there are plenty methods you can use to draw.
    oled.fill(0)                         # fill entire screen with colour=0
    oled.pixel(0, 10)                    # get pixel at x=0, y=10
    oled.pixel(0, 10, 1)                 # set pixel at x=0, y=10 to colour=1
    oled.hline(0, 8, 4, 1)               # draw horizontal line x=0, y=8, width=4, colour=1
    oled.vline(0, 8, 4, 1)               # draw vertical line x=0, y=8, height=4, colour=1
    oled.line(0, 0, 127, 63, 1)          # draw a line from 0,0 to 127,63
    oled.rect(10, 10, 107, 43, 1)        # draw a rectangle outline 10,10 to 117,53, colour=1
    oled.fill_rect(10, 10, 107, 43, 1)   # draw a solid rectangle 10,10 to 117,53, colour=1
    oled.text('Hello World', 0, 0, 1)    # draw some text at x=0, y=0, colour=1
    oled.scroll(20, 0)                   # scroll 20 pixels to the right

    """
    data = mapValue(pot.read_u16(), 200, 65535, 0, 128)
    oled.text("Pot value: ", 0, 0)
    oled.text(str(pot.read_u16()), 0, 20) # draw the pot's value on screen at x=10, y=20 position.
    oled.rect(1, 40, 127, 20, 1)
    oled.fill_rect(2, 40, data, 20, 1)
    oled.show()
    sleep(0.3)
    oled.fill(0)
    oled.show()
    sleep(0.001)
    
