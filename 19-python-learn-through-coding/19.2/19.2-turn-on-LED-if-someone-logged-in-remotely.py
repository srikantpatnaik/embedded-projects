#!/usr/bin/python
import subprocess
import RPi.GPIO as GPIO
import time
# Just in case, unlock any blocked pins
GPIO.cleanup()
LED=21

# Use BCM style of pin numbering
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(LED, GPIO.OUT)

def check_ssh():
    # Run a netstat command and check whether ssh connection available
    netstat = subprocess.Popen('netstat', stdout=subprocess.PIPE)
    output = subprocess.Popen(('grep', 'ssh'), stdin=netstat.stdout, stdout=subprocess.PIPE)
    output.communicate()
    return output.returncode


while True:
    time.sleep(1)
    if check_ssh():
        GPIO.output(LED, False)
    else:
   	GPIO.output(LED, True)

