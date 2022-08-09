from machine import Pin, ADC
from time import sleep


# The internal ADC reference voltage is typically 1.1v, but varies slightly from package to package.
# The ADC is less linear close to the reference voltage(particularly at higher attenuations) and has a minimum measurement voltage around 100mV,
# voltages at or below this will read as 0. 
# To read voltages accurately, it is recommended to use the read_uv() method.

# To read voltages above the reference voltage, apply input attenuation with the# atten keyword argument. Valid values(and approximate linear measurement ranges) are:
# ADC.ATTN_0DB:  NO attenuation (100mV-950mV)
# ADC.ATTN_2_5DB: 2.5dB attenuation (100mV-1250mV)
# ADC.ATTN_6DB:  6dB attenuation (100mV-1750mV)
# ADC.ATTN_11DB: 11dB attenuation (150mV-2450mV)
# NOTE: Note that the absolute maximum voltage rating for input pins is 3.6V!!!
# NOTE: Going near to this boundary risks damage to the IC!!!!

# Here we use 3.3v as input voltage, so initializing the ADC pin need to use ADC.ATTN_11DB to be set 3V as reference voltage.
# use keyword atten=ADC.ATTN_11DB to set the reference voltage to 3V

pota = ADC(Pin(26), atten=ADC.ATTN_11DB)
potb = ADC(Pin(25), atten=ADC.ATTN_11DB)

while True:
    print(pota.read(), potb.read())
    sleep(0.02)

