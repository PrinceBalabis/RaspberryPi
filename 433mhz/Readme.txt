# About
This is a fork from rcswitch-pi: https://github.com/r10r/rcswitch-pi

rcswitch-pi is for controlling rc remote controlled power sockets 
with the raspberry pi. Kudos to the projects [rc-switch](http://code.google.com/p/rc-switch)
and [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi).
I just adapted the rc-switch code to use the wiringpi library instead of
the library provided by the arduino.
---

# Installation & Setup

## 1. WiringPi
First you have to install the [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library.
	* git clone git://git.drogon.net/wiringPi
	* cd wiringPi
	* ./build

## 2. 
Connect the 433 Mhz Transmitter to GPIO pin 17/0

## 3. RCSwitch-Pi
git clone https://github.com/PrinceBalabis/RaspberryPi
---


#Usage
RaspberryPi/433mhz/send {Unit Code Value}
example: RaspberryPi/433mhz/send 5510485

## Group 1 Unit Code Values:
Channel | On | Off
--- | --- | ---
1| 5510485 | 5510484
2 | 5525845 | 5525844

---
