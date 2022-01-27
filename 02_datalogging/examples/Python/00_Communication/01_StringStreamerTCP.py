# Import packages
# - Python Native
import time
import argparse
# - PyZMQ
import zmq

def stream(server_address, port):

    print("Connecting to ", server_address, "at", port)
    context = zmq.Context()
    footage_socket = context.socket(zmq.PUB)
    footage_socket.connect('tcp://' + server_address + ':' + port)
    keep_running = True

    while True:
        print ('Sending hello')
        # Replace below with sensor reading
        footage_socket.send_string('hello')
        time.sleep (5)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--port',
                        help='Port for stream', default = '5555',
                        required=False)
    parser.add_argument('-s', '--server',
                        help='IP of Server for stream', default = 'localhost',
                        required=False)

    args = parser.parse_args()
    stream(args.server, args.port)
