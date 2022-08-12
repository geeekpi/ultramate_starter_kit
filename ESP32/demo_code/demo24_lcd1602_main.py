from machine import Pin, I2C 
from time import sleep
from machine_i2c_lcd import I2cLcd

# Please upload lcd_api.py and machine_i2c_lcd.py to /pyboard/ folder via
# rshell tool.
# initializing i2c, using hard I2C 0.
# ------------------------
# |    | I2C(0) | I2C(1) |
# ------------------------
# |scl | 18     | 25     |
# ------------------------
# |sda | 19     | 26     | 
# ------------------------
i2c = I2C(0, sda=Pin(19), scl=Pin(18), freq=400000)

devices = i2c.scan()
if len(devices) == 0:
    print("No i2c device !")
else:
    print('i2c devices found: {}'.format(len(devices)))

for device in devices:
    print("At address: {}".format(hex(device)))

addr = devices[0]

# create lcd object, args: i2c object, i2c_addr, num_of_row, num_of_columns
lcd = I2cLcd(i2c, addr, 2, 16)

while True:
    lcd.putstr("Hello ESP32!\n")
    lcd.putstr("1234567890\n")
    sleep(1)
    # lcd.backlight_off()
    lcd.clear()
    sleep(1)
    # lcd.backlight_on()
