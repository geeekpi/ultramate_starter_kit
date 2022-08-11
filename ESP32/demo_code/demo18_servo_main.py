from machine import Pin, PWM
from time import sleep


# define pwm instance
# PWM can be enabled on all output-enabled pins.
# The base frequency can range from 1Hz to 40MHz but there is a tradeoff;
# as the base frequency increases the duty resolution decreases. 
# pwm0 = PWM(Pin(0))    # create PWM object from a Pin
# freq = pwm0.freq()    # get current frequency (default 5kHz)
# pwm0.freq(50)         # set PWM frequency from 1Hz to 40MHz
# duty = pwm0.duty()    # get current duty cycle, range 0-1023 (default 512,50%)
# pwm0.duty(256)    # set duty cycle from 0 to 1023 as a ratio duty/1023, (now 25%)
pwm0 = PWM(Pin(0))
pwm0.freq(50)

while True:

    for i in range(0,130,5):
        pwm0.duty(i)
        print(i)
        sleep(0.01)

    for i in range(130,0,-5):
        pwm0.duty(i)
        print(i)
        sleep(0.01)

