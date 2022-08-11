from ultrasonic import UltraSonic
from time import sleep


# ESP32
sensor = UltraSonic(trigger_pin=2, echo_pin=4, echo_timeout_us=10000)

while True:
    distance_in_cm = sensor.distance_cm()
    distance_in_mm = sensor.distance_mm()
    print("Distance in cm: {}, in mm: {}".format(distance_in_cm,
        distance_in_mm))
    sleep(1)
