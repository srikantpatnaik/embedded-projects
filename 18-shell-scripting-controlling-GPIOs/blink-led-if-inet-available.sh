#!/bin/bash

# Create node for GPIO 21
echo 21 > /sys/class/gpio/export

# Configure GPIO as output
echo out > /sys/class/gpio/gpio21/direction

# Check whether google.com accessible
wget google.com &>/dev/null

# Check for return status. If success the above wget command
# will return 0, else non-zero. 
if [ $? -eq 0 ]; then
	# If internet is available blink LED for 3 times and stop
	for each in {1..3}; do 
		# Writing 1 to file 'value' will make the LED ON
		echo 1 > /sys/class/gpio/gpio21/value
		# Sleep for half second
		sleep 0.5
		# Writing 0 to file 'value' will make the LED OFF
		echo 0 > /sys/class/gpio/gpio21/value
		sleep 0.5
	done
fi
# Delete node for GPIO 21
echo 21 > /sys/class/gpio/unexport
