#!/usr/bin/python

import subprocess
import psutil
import RPi.GPIO as GPIO
import time

R_PIN=21
G_PIN=16
B_PIN=20

def setup():
	GPIO.setwarnings(False)
	GPIO.cleanup()
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(R_PIN, GPIO.OUT)
	GPIO.setup(G_PIN, GPIO.OUT)
	GPIO.setup(B_PIN, GPIO.OUT)
	
def loop():
	while True:
		cpu_usage = psutil.cpu_percent()
		print cpu_usage
		if cpu_usage < 10:
			GPIO.output(B_PIN, False)
			GPIO.output(R_PIN, False)
			GPIO.output(G_PIN, True)
			time.sleep(1)
		elif cpu_usage > 10 and cpu_usage < 40:
			GPIO.output(G_PIN, False)
			GPIO.output(R_PIN, False)
			GPIO.output(B_PIN, True)
			time.sleep(1)
		else:
			GPIO.output(G_PIN, False)
			GPIO.output(B_PIN, False)
			GPIO.output(R_PIN, True)
			time.sleep(1)

if __name__ == "__main__":
	setup()
	loop()
