from Adafruit_SHT31 import *
import time

# Define SHT31 Address
sensor = SHT31(address = 0x44)

def readSHT():
    try:
        return sensor.read_temperature(), sensor.read_humidity()
    except:
        return None, None

if __name__ == "__main__":
    try:
        while True:
            temp, humidity = readSHT()
            time.sleep(1)
            print ('Temp             = {0:0.3f} deg C'.format(temp))
            print ('Humidity         = {0:0.2f} %'.format(humidity))
    except KeyboardInterrupt:
        raise SystemExit