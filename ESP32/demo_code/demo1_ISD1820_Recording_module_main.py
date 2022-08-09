from machine import Pin, TouchPad
import machine
from time import sleep
# import esp32


# define record trigger pin 4, and P_E pin as 0.
rec_pin = Pin(4, Pin.OUT)
play_E_pin = Pin(0, Pin.OUT)

# define touch pin to trigger play sound or recording voice.
t = TouchPad(Pin(14))

# define touch threshold, means if touch value below 500 will consider to be touched. 
t.config(500)

# if you want to enable esp32's light sleep mode, uncomment this line.
# esp32.wake_on_touch(True)


while True:
    print(t.read())
    if t.read() < 500:
        play_E_pin.value(0)
        sleep(0.5)
    else:
        play_E_pin.value(1)
        sleep(0.5)
        # enable light sleep mode.
        # machine.lightsleep()

