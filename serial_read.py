#!/usr/bin/python3.5
import time
import serial
import re
import os

os.system("sudo systemctl start nodered.service")

ser =  serial.Serial( port = '/dev/ttyUSB0',
                      baudrate = 115200,
                      parity = serial.PARITY_NONE,
                      stopbits = serial.STOPBITS_ONE,
                      bytesize = serial.EIGHTBITS,
                      timeout = 1
                      )

counter = 0

while 1:
	line = ser.readline().decode('utf-8')
	temps = re.findall(r'\d+',line)
	if len(temps) == 4:
		meattemp = temps[0]
		chambertemp = temps[2]
		os.system("mosquitto_pub -h localhost -t \"/MeatTemp\" -m \""+ meattemp + "\" ")
		os.system("mosquitto_pub -h localhost -t \"/ChamberTemp\" -m \""+ chambertemp + "\" ")
		print (meattemp)
		print (chambertemp)
	else:
		print (temps)
		print (line)
        
