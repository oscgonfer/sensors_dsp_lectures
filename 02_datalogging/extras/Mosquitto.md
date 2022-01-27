Install Mosquitto

For Windows:
Navigate to the folder where it's installed in command line to have access to Mosquitto's programms. (You can also add this folder address to PATH variable to be accessible from any location, but than config file needs to be where you run the commands from)

In separate command line windows:
1 run a server
	mosquitto -v -c mosquitto.conf
2 run a subscriber
	mosquitto_sub -h localhost -t YOUR_MQTT_TOPIC
3 run a publisher
	mosquitto_pub -h localhost -t YOUR_MQTT_TOPIC -m “YOUR_MQTT_MESSAGE”

To allow remote access:
1 modify config file "mosquitto.conf" adding following lines, where 1883 - port to listen to. NB! Text editor requires administrator priviladges.
	listener 1883
	allow_anonymous true

To limit access to specific credentials.
In console with with admin privilages
1 create passord file (inputting YOUR_MQTT_PASSWORD in console, when you run operation)
	mosquitto_passwd -c passfile.txt YOUR_MQTT_USERNAME
2 modify config file "mosquitto.conf" adding following lines, where 1883 - port to listen to. NB! Text editor requires administrator priviladges.
	listener 1883
	allow_anonymous false
	password_file passfile.txt
2 server works in same way, in subscribers or publishers you would need to add your credentials
mosquitto_sub -h localhost -t YOUR_MQTT_TOPIC -u YOUR_MQTT_USERNAME -P YOUR_MQTT_PASSWORD
mosquitto_pub -h localhost -t YOUR_MQTT_TOPIC -m “YOUR_MQTT_MESSAGE” -u YOUR_MQTT_USERNAME -P YOUR_MQTT_PASSWORD

---

Based on:
https://www.kolkataonweb.com/code-bank/miscellaneous/how-to-setup-mqtt-server-on-a-windows-10-desktop/
https://mosquitto.org/documentation/authentication-methods/
