#!/usr/bin/python

# Import packages
import serial
import datetime
import glob
import sys
from sys import stdout

# Numpy
import numpy as np

# I2C device definition
PORT = '/dev/cu.usbmodem1411'
BAUDRATE = 115200

def serial_ports():
    """Lists serial ports
    :raises EnvironmentError:
        On unsupported or unknown platforms
    :returns:
        A list of available serial ports
    """
    if sys.platform.startswith('win'):
        ports = ['COM' + str(i + 1) for i in range(256)]

    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this is to exclude your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')

    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')

    else:
        raise EnvironmentError('Unsupported platform')

    result = []

    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result

def ReadSerial(serial):

    return serial.readline().replace("\r\n", "")

# Retrieve constants (ports, time, header)
ports = serial_ports()
ser = serial.Serial(ports[1], 9600)
# print (ser)

# Create header
print ("TIME, SENSOR_READING")

# Create the reading
while True:
    timestamp = datetime.datetime.now()
    reading = ReadSerial(ser)
    #~ print reading
    #  Print it and flush standard output
    print "{},{}".format(timestamp,reading)
    sys.stdout.flush()
