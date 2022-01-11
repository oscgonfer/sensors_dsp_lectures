import paho.mqtt.client as mqtt
import time

mqtt_broker = "SERVERADDRESS"
mqtt_user = "MQTTUSER"
mqtt_pass = "MQTTPASS"
broker_port = 1883

def on_connect(client, userdata, flags, rc):
   print(f"Connected With Result Code: {rc}")

def on_message(client, userdata, message):
   print(f"Message Recieved: {message.payload.decode()}")
   # Do something here with the message

def on_log(client, obj, level, string):
    print (string)

def read_sensor():
	sensor_reading = "Hola hola caracola"
	return sensor_reading

client = mqtt.Client(clean_session = True)
client.on_connect = on_connect
client.on_message = on_message
client.on_log = on_log
client.username_pw_set(username = mqtt_user, password = mqtt_pass)
client.connect(mqtt_broker, broker_port)


# Subscribe to your topic here
client.subscribe("output/yourname", qos=1)
client.publish(topic="input", payload="Hello from python", qos = 1, retain = False)


# Start looping (non-blocking)
client.loop_start()

while True:
	# Read data here
	sensor_reading = read_sensor()
	# Publish data here
	client.publish(topic="input", payload=sensor_reading, qos = 1, retain = False)
	time.sleep(5)