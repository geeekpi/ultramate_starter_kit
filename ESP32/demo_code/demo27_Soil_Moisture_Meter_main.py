from machine import Pin
from time import sleep


# Soil Moisture Meter
smm = Pin(4, Pin.IN)

while True:
    # print(smm.value())
    if smm.value() == 1:
        print("The Soil is going to dry, watering please!!!")
        sleep(0.5)
    else:
        print("The Soil is still wet...")
        sleep(0.5)
