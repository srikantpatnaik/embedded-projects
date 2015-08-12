README
======

Instructions
------------

* Install `osd_cat` ::

	sudo apt-get install xosd-bin

* Install weather package from `pip`::

	sudo pip install yweather

* Invoke `tightvncserver` as root, as the GPIO access requires sudo 
  privileges and `osd_cat` or `notify-bin` won't work in VNC with other
  user. 
  `notify-bin` was crashing, probably due to `notification-daemon`.

Explanation tips
----------------
 
* Show the installation and coding step by step.

* Show connecting VNC everytime

* Show normal user error and also tell about weied notify-send issue 
