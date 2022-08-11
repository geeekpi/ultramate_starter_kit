from rotary import Rotary
import utime as time
from machine import Pin, PWM
from time import sleep


pwm0 = PWM(Pin(0))
pwm0.freq(50)

# pwm0.duty(512)

# GPIO pins as dt, clk, sw.
rotary = Rotary(2, 4, 22)
val = 127 

def rotary_changed(change):
    global val
    if change == Rotary.ROT_CW:
        val += 5
        if val <= 127:
            print(val)
            pwm0.duty(val)
        else:
            print("out of range")
            pwm0.duty(127)
    elif change == Rotary.ROT_CCW:
        val -= 5
        print(val)
        if val >= 0:
            pwm0.duty(val)
        else: 
            print("out of range")
            pwm0.duty(0)
    elif change == Rotary.SW_PRESS:
        print("PRESS")
        pwm0.duty(64)
    elif change == Rotary.SW_RELEASE:
        print("RELEASE")
        pwm0.duty(127)

rotary.add_handler(rotary_changed)

while True:
    time.sleep(0.1)

