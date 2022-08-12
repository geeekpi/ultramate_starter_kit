from machine import Pin, TouchPad
from time import sleep


# define touch pad pin.
t = TouchPad(Pin(14))

# TouchPad.read returns a value relative to the capacitive variation.
# Small numbers(typically in the tens) are common when a pin is touched,
# larger numbers(above one thousand) when no touch is present.
# However the values are relative and can vary depending on the board and 
# surrounding composition so some calibration may be required.
# configure the threshold at which the pin is considered touched.
t.config(500)

relay = Pin(0, Pin.OUT)

while True:
    if t.read() >= 580:
        print(t.read())
        print("Relay Off")
        relay.value(0)
        sleep(0.2)
    elif t.read() <= 200:
        print(t.read())
        print("Relay On")
        relay.value(1)
        sleep(0.2)

