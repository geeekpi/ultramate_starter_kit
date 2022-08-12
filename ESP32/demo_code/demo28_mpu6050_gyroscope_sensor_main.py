from machine import Pin, I2C
from time import sleep
import mpu6050
import math


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

devices = i2c.scan()
if len(devices) == 0:
    print("No i2c device detected, please check the wiring cable !")
else:
    print('i2c devices found: {}'.format(len(devices)))

for device in devices:
    print("At address: {}".format(hex(device)))


# create imu object 
imu = mpu6050.accel(i2c)

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
    sleep(0.05)
