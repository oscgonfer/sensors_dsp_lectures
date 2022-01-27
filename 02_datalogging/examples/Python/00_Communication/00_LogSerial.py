#!/usr/bin/python

# Import packages
# - Python Native
import datetime
import glob
import sys
from sys import stdout
# - PySerial
import serial
# - Numpy
import numpy as np

BAUDRATE = 9600

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

    return serial.readline().decode().replace("\r\n", "")

# Retrieve constants (ports, time, header)
ports = serial_ports()
print (ports)
ser = serial.Serial(ports[1], BAUDRATE)

filename = 'log.csv'
# Create header
with open(filename, 'a') as file:
    file.write(f"TIME,READING\n")

# Create the reading
while True:
    timestamp = datetime.datetime.now()
    reading = ReadSerial(ser)
    print ("Reading sensor...")
    #  Print it and flush standard output
    with open(filename, 'a') as file:
        file.write(f"{timestamp},{reading}\n")
    sys.stdout.flush()
