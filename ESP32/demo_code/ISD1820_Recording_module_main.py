from machine import Pin, TouchPad
import machine
from time import sleep
# import esp32


# define record trigger pin 4, and P_E pin as 0.
rec_pin = Pin(4, Pin.OUT)
play_E_pin = Pin(0, Pin.OUT)
t = TouchPad(Pin(14))
t.config(500)
# esp32.wake_on_touch(True)


while True:
    print(t.read())
    if t.read() < 500:
        play_E_pin.value(0)
        sleep(0.5)
    else:
        play_E_pin.value(1)
        sleep(0.5)
        # machine.lightsleep()

