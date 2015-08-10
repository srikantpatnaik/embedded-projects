README
======

GPIO access using `shell`
-------------------------

* Create a GPIO file access by writing into `/sys/class/gpio/export`. For example ::

	echo 21 > /sys/class/gpio/export

* This will now create a directory structure at ::

	/sys/class/gpio/gpio21/
	
* Now, simply write `1` to `value` file to turn ON the connected LED ::

	echo 1 > /sys/class/gpio/gpio21/value

* To delete the gpio node simply unexport ::

	echo 21 > /sys/class/gpio/unexport

	
