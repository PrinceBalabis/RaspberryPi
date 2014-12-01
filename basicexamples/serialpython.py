#!/usr/bin/env python

import serial
import sys
import time

ser = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(0.1)
ser.write(str(sys.argv[1]))
ser.close()
