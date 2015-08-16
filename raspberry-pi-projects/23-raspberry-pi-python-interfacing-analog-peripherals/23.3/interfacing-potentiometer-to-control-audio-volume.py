#!/usr/bin/python

import RPi.GPIO as GPIO
import time
import spidev
import subprocess

def loop():
	# Create an instance 
	spi = spidev.SpiDev()
	# Open CE0 of Raspberry Pi, to which MCP3002 ADC is connected
	spi.open(0,0)
	try:
		while True:
			# # Send start bit, sgl/diff, odd/sign, MSBF
	                # channel = 0 sends 0000 0001 1000 0000 0000 0000
 	                # channel = 1 sends 0000 0001 1100 0000 0000 0000
                        # sgl/diff = 1; odd/sign = channel; MSBF = 0

			r = spi.xfer2([1,(2+0)<<6,0])

			# spi.xfer2 returns same number of 8 bit bytes
		        # as sent. In this case, 3 - 8 bit bytes are returned
		        # We must then parse out the correct 10 bit byte from
		        # the 24 bits returned. The following line discards
		        # all bits but the 10 data bits from the center of
		        # the last 2 bytes: XXXX XXXX - XXXX DDDD - DDDD DDXX

			ret = ((r[1]&31) << 6) + (r[2] >> 2)

			# As 3.3V is AREF and its 10 bit ADC. So we have 2^10 i.e
			# 1024 samples within 3.3V. This means, 0 means 0V and 1024 is 3.3V
			# 'ret' will have the decimal equivalent of 10 bits received.
			# Convert 'ret' to actual analog voltage to know the 
			# temperature in deg centigrade (LM35 datasheet says 10mv/degC)
			# 1024 -> 3.3V, hence, 1 sample -> 3.3/1024V, 'ret' number of samples=3.3*ret/1024V

			# amixer set PCM 70%
			volume_control_percentage = int((ret / 1024.0)*100)
			amixer_command="amixer set PCM %s%s" %(volume_control_percentage,'%')
			#subprocess.Popen(amixer_command, shell=True, stdout=subprocess.PIPE)
			subprocess.Popen(amixer_command, shell=True) # with debug
			time.sleep(1)
	except KeyboardInterrupt:
		#GPIO.cleanup()
		spi.close()
		print "Good Bye!"

if __name__ == "__main__":
	loop()



