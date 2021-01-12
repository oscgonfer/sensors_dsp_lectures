import zmq
import time
import numpy as np
import argparse


def receive(port = '5555'):
	context = zmq.Context()
	footage_socket = context.socket(zmq.SUB)
	footage_socket.bind('tcp://*:' + port)
	footage_socket.setsockopt_string(zmq.SUBSCRIBE, np.unicode(""))

	while footage_socket:
		try:
			print (footage_socket.recv_string())
		except KeyboardInterrupt:
			break
	print ('Streaming done')

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--port',
                        help='Port for stream', default = '5555', 
                        required=False)

    args = parser.parse_args()
    receive(args.port)

if __name__ == '__main__':
    main()	