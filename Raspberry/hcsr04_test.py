import RPi.GPIO as GPIO
import time

Trig_Pin = 23
Echo_Pin = 24

GPIO.setmode(GPIO.BCM)
GPIO.setup(Trig_Pin, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(Echo_Pin, GPIO.IN)

time.sleep(2)

def checkdist():
    print("Running checkdist")
    GPIO.output(Trig_Pin, GPIO.HIGH)
    time.sleep(0.00001)
    GPIO.output(Trig_Pin, GPIO.LOW)
    while not GPIO.input(Echo_Pin):
        print("in Echo_Pin")
        pass
    print("get t1")
    t1 = time.time()
    while GPIO.input(Echo_Pin):
        print("in Echo_Pin again")
        pass
    print("get t2")
    t2 = time.time()
    return (t2-t1)*340*100/2

try:
    while True:
        print("Staring")
        print ('Distance:%0.2f cm' % checkdist())
        time.sleep(1)
except KeyboardInterrupt:
    print("cleaning up GPIO")
    GPIO.cleanup()
