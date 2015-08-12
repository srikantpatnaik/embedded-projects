#!/usr/bin/python

import RPi.GPIO as GPIO
import subprocess
import time
import yweather

location="New York, USA"  # Change for yours
# Push button connected to GPIO 21
button=21

def setup():
	GPIO.setwarnings(False)
	# Clean/Release any previous GPIO access
	GPIO.cleanup()
	GPIO.setmode(GPIO.BCM)
	# Make button input, and enable software PULL UP(means, internally
	# the pin is configured as HIGH)
	GPIO.setup(button, GPIO.IN, GPIO.PUD_UP)

def fetch_weather():
	client = yweather.Client()
	weather_on_earth_id = client.fetch_woeid(location)
 	my_weather = client.fetch_weather(weather_on_earth_id)
	return 'Humidity: ' + my_weather["atmosphere"]["humidity"] \
		   + '%, Temp: ' + my_weather["condition"]["temp"] + 'F'

def loop():
	while True:
		GPIO.wait_for_edge(button, GPIO.FALLING)
		osd = "echo -n " + fetch_weather() + ', ' + location +\
		 "| osd_cat --color=red --pos=top --align=right --offset=50\
 		--indent=50 --delay 2  --font '-*-fixed-*-*-*-*-35-*-*-*-*-*-*-*' "
		subprocess.Popen(osd, shell=True)
		time.sleep(1)

if __name__ == "__main__":
	setup()
	loop()
