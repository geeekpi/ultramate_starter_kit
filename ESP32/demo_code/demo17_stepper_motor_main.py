from machine import Pin
from time import sleep

IN1 = Pin(26, Pin.OUT)
IN2 = Pin(25, Pin.OUT)
IN3 = Pin(33, Pin.OUT)
IN4 = Pin(32, Pin.OUT)

pins = [IN1, IN2, IN3, IN4]

sequence_ccw = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]

while True:
    for step in sequence_ccw:
        for i in range(len(pins)):
            pins[i].value(step[i])
            sleep(0.001)

