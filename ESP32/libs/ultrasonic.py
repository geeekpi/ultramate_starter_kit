from machine import Pin
import time
import machine

# ultrasonic sensor HC-SR04
# The ultrasonic sensor uses sonar to determine the distance to an object. Here’s how it works:
# The ultrasound transmitter (trig pin) emits a high-frequency sound (40 kHz).
# The sound travels through the air. If it finds an object, it bounces back to the module.
# The ultrasound receiver (echo pin) receives the reflected sound (echo).
# Taking into account the sound’s velocity in the air and the travel time 
# (time passed since the transmission and reception of the signal) 
# we can calculate the distance to an object. Here’s the formula:
# distance to an object = ((speed of sound in the air)*time)/2
# speed of sound in the air at 20ºC (68ºF) = 343m/s

class UltraSonic:
    """ 
    Driver to use the ultrasonic sensor.
    Sensor range is between 2cm and 4m. 
    The timeouts received listening to echo pin are converted to 
    OSError('Out of range')
    """
    # echo_timeout_us is based in chip range limit(400cm)
    def __init__(self, trigger_pin, echo_pin, echo_timeout_us=500*2*30):
        """
        trigger_pin: Output pin to send pulses
        echo_pin: Readonly pin to measure the distance. The pin should be protected with 1k resistor.
        echo_timeout_us: Timeout in microseconds to listen to echo pin. 
        By default is based in sensor limit range(4m)
        """
        self.echo_timeout_us = echo_timeout_us
        # Init trigger pin (output)
        self.trigger = Pin(trigger_pin, mode=Pin.OUT, pull=None)
        self.trigger.value(0)

        # Init echo pin (input)
        self.echo = Pin(echo_pin, mode=Pin.IN, pull=None)


    def _send_pulse_and_wait(self):
        """
        Send the pulse to trigger and listen on echo pin.
        We use the method `machine.time_pulse_us()` to get microseconds
        until the echo is received.
        """
        self.trigger.value(0) # Stabilize the sensort
        time.sleep_us(5)
        self.trigger.value(1)
        # send a 10us pulse.
        time.sleep_us(10)
        self.trigger.value(0) 
        try:
            pulse_time = machine.time_pulse_us(self.echo, 1,
                    self.echo_timeout_us)
            return pulse_time
        except OSError as e:
            if e.args[0] == 110: # 110 = ETIMEOUT
                raise OSError('Out of range')
            raise e

    
    def distance_mm(self):
        """
        Get the distance in millimeters without floating point operations.
        """
        pulse_time = self._send_pulse_and_wait()
        # To calculate the distance we get the pulse_time and divide it by 2
        # (the pulse walk the distance twice) and by 29.1 becasue
        # the sound speed on air (343.2 m/s), that It's equivalent to
        # 0.34320 mm/us that is 1mm each 2.91us
        # pulse_time // 2 // 2.91 -> pulse_time // 5.82 -> pulse_time * 100 // 582
        mm = pulse_time * 100 // 582
        return mm

    def distance_cm(self):
        """
        Get the distance in centimeters with floating point operations.
        It returns a float.
        """
        pulse_time = self._send_pulse_and_wait()

        # To calculate the distance we get the pulse_time and divide it by 2
        # (the pulse walk the distance twice) and by 29.1 becasue
        # the sound speed on air (343.2 m/s), that It's equivalent to
        # 0.034320 cm/us that is 1cm each 29.1us
        cms = (pulse_time / 2) / 29.1
        return cms





