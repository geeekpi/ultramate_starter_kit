from machine import Pin
from rotary import Rotary
import utime as time


# GPIO pins as dt, clk, sw.
rotary = Rotary(2, 4, 22)
val = 0 

def rotary_changed(change):
    global val
    if change == Rotary.ROT_CW:
        val += 1
        print(val)
    elif change == Rotary.ROT_CCW:
        val -= 1
        print(val)
    elif change == Rotary.SW_PRESS:
        print("PRESS")
    elif change == Rotary.SW_RELEASE:
        print("RELEASE")

rotary.add_handler(rotary_changed)

while True:
    time.sleep(0.1)

