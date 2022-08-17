from machine import Pin, I2C
from time import sleep
from ssd1306 import SSD1306_I2C
import framebuf



# define width and height
WIDTH = 128
HEIGHT = 64

# define byte array of fire icon in 32x32 pixels
buffer = bytearray(b"\x00\x07\x00\x00\x00\x0f\x80\x00\x00\x0f\x80\x00\x00\x0f\xe0\x00\x00\x0f\xf0\x00\x00\x0f\xf8\x00\x00\x0e|\xc0\x00\x0e<`\x00\x1e<`\x00>>`\x00~\x1ep\x00\xfc\x1e\xf0\x01\xfc\x0e\xf0\x01\xf8\x0e\xf0\x03\xf8\x1f\xf0\x07\xf87\xb0\x07\xf0'0\x0f\xf0o0\x0f\xe0n0\x0fp\xc60\x0fy\x800\x0fq\x00p\x0f8\x00\xf0\x07\x9c\x0c\xf0\x07\x98\x1c\xf0\x03\x009\xf0\x03\xc0q\xe0\x01\xc1\xc3\xc0\x00\xf1\x07\xc0\x00\xfa\x0f\x80\x00|\x0e\x00\x008\x0f\x00"
)

# define frame buffer object in 32x32pixels.
fb = framebuf.FrameBuffer(buffer, 32, 32, framebuf.MONO_HLSB)

# create instance of i2c bus.
bus = I2C(1, scl=Pin(15), sda=Pin(14), freq=2000000)

# create oled object by using SSD1306_I2C
oled = SSD1306_I2C(WIDTH, HEIGHT, bus)

oled.fill(0) # clear screen
oled.show()


next_pin = Pin(9, Pin.OUT) # define next trigger pin 
next_pin.value(1)

next_key = Pin(3, Pin.IN, Pin.PULL_UP) # next key


while True:
    oled.text("MP3 player", 0, 0)
    oled.text(str(next_key.value()), 0, 10)
    oled.show()
    sleep(0.5)
    oled.fill(0) # clear screen
    oled.show()
    if next_key.value() == 0:
        next_pin.value(0)
        sleep(0.1)
        next_pin.value(1)
        sleep(0.5)
