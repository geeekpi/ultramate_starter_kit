from machine import Pin, I2C
from time import sleep
import mpu6050
import math
from ssd1306 import SSD1306_I2C
import framebuf

WIDTH = 128
HEIGHT = 64

buffer = bytearray(b'\x00\x00\x00\x00\x01\xf0\x0f\x00\x06\x860\xb0\x04\x01@\x10\x04\x01\x000\x02\x10\x89 \x02\x05\xd2 \x01\x03\xe0@\x01\x87\xe0\x80\x10~?\x00\x00\x88\x11\x80\x01\x18\x08@\x02><@\x02a\xc3@C\xc1\x81\xe0\x05\x80\x90\x91\x08\x80\x80\x98\x08\x81\xc0\x88\t\x83\xe1\x98)\xe4\x1f\x98\x07\xf8\x0e0\x068\x0c \x02\x18\x080\x02\x88\x08 \x03\x0e0A\x01\x8f\xf8\x80\x00|\x1f\x00\x008\x0c\x00\x00\x0c0\x02\x00\x03\xe0\x00\x00\x00\x80\x00\x01\x00\x00\x04')

fb = framebuf.FrameBuffer(buffer, 32, 32, framebuf.MONO_HLSB)


# define variable to store imu data.
imu_data = {}

# initializing i2c, using hard I2C 0.
# ------------------------
# |    | I2C(0) | I2C(1) |
# ------------------------
# |scl | 18     | 25     |
# ------------------------
# |sda | 19     | 26     | 
# ------------------------
i2c = I2C(1, sda=Pin(26), scl=Pin(25), freq=400000)

oled_i2c = I2C(0, sda=Pin(19), scl=Pin(18), freq=400000)


devices = i2c.scan()
if len(devices) == 0:
    print("No i2c device detected, please check the wiring cable !")
else:
    print('i2c devices found: {}'.format(len(devices)))

for device in devices:
    print("At address: {}".format(hex(device)))


# create imu object 
imu = mpu6050.accel(i2c)
oled = SSD1306_I2C(WIDTH, HEIGHT, oled_i2c)

# initializing 3 axis value. 
accx = 0 
accy = 0 
accz = 0 

gyx = 0
gyy = 0
gyz = 0

yaw_angle = 0.0
pitch_angle = 0.0
roll_angle = 0.0


while True:
    # data format 
    # {'GyZ': -89, 'GyY': -53, 'GyX': -1014, 
    # 'Tmp': 30.6947, 'AcZ': 10696, 'AcY': 9952, 'AcX': -5720}
    imu_data = imu.get_values()
    accx = (imu_data['AcX']) / 16384.0
    accy = (imu_data['AcY']) / 16384.0
    accz = (imu_data['AcZ']) / 16384.0

    gyx = (imu_data['GyX']) / 131.0
    gyy = (imu_data['GyY']) / 131.0
    gyz = (imu_data['GyZ']) / 131.0

    roll_angle = math.atan2(accz,accx)*180/math.pi /100.0 - 0.80
    pitch_angle = math.atan2(accz,accy)*180/math.pi /100.0 - 0.80 
    yaw_angle = math.atan2(math.sqrt(accy*accy+accz*accz), accx)*180/math.pi /100.0 - 0.01

    print('roll: {:.2f}, pitch: {:.2f}, yaw:{:.2f}'.format(roll_angle,
        pitch_angle,
        yaw_angle))
    oled.fill(0)
    x = int(64+64*pitch_angle)
    y = int(32+32*roll_angle)
    if x >= 128:
        x = 128
    elif x <=0:
        x = 0

    if y >= 64:
        y = 64 
    elif y <=0:
        y = 0
    
    oled.blit(fb, x, y)
    oled.show()
    sleep(0.01)
    oled.fill(0)
