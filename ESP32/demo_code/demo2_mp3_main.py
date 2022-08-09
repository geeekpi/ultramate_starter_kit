from machine import Pin
from time import sleep


# connect to MP4 module's ADKey2 and ADKey1, so that you can trigger it to play the music which preload in TF card, you need to format the TF card as fat32 or fat16 format, and copy the mp3 file into it. 

ADKey2 = Pin(4, Pin.OUT)
ADKey1 = Pin(0, Pin.OUT)


while True:
    # play first mp3 file.
    ADKey2.value(1)
    # if this key is high level will trigger next song.
    # ADKey1.value(0)
    ADKey1.value(0)


