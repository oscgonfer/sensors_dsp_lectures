# Import packages
# - Python Native
import time
import argparse
# - local Adafruit library
from Adafruit_SHT31 import *
# - PyZMQ
import zmq

# Define SHT31 Address
sensor = SHT31(address = 0x44)

def readSHT():
    try:
        return sensor.read_temperature(), sensor.read_humidity()
    except:
        return None, None

def stream(server_address, port, string):

    print("Connecting to ", server_address, "at", port)
    context = zmq.Context()
    footage_socket = context.socket(zmq.PUB)
    footage_socket.connect('tcp://' + server_address + ':' + port)
    keep_running = True

    while True:
        # Replace below with sensor reading
        footage_socket.send_string(string)
        time.sleep (5)

if __name__ == "__main__":
    print ('hello')
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--port',
                        help='Port for stream', default = '5555',
                        required=False)
    parser.add_argument('-s', '--server',
                        help='IP of Server for stream', default = 'localhost',
                        required=False)

    args = parser.parse_args()

    try:
        while True:
            print ('Reading SHT31')
            temp, humidity = readSHT()
            # stream(args.server, args.port, 'Temp = {0:0.3f} deg C'.format(temp))
            stream(args.server, args.port, 'Humidity= {0:0.2f} %'.format(humidity))

            print ('Sending data')
            print ('Temp             = {0:0.3f} deg C'.format(temp))
            print ('Humidity         = {0:0.2f} %'.format(humidity))

    except KeyboardInterrupt:
        raise SystemExit
