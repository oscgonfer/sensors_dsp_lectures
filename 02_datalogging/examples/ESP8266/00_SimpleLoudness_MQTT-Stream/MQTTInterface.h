// Import PubSubClient library in Arduino Library Manager.
#include <PubSubClient.h>

///////////////////////////////////////////////////////////////////////////////////////
// SETUP WIFI CREDENTIALS
const char* mqtt_server = "YOUR_MQTT_SERVER";
int mqtt_port = 1883;
const char* mqtt_user = "YOUR_MQTT_USERNAME";
const char* mqtt_pass = "YOUR_MQTT_PASSWORD";

WiFiClient espClient;
PubSubClient client(espClient);

///////////////////////////////////////////////////////////////////////////////////////
void callback(char* mqtt_topic, byte* payload, unsigned int length);
void reconnect();
void beginMQTT() {
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}
void loopMQTT() {
  if (!client.connected()) reconnect();
  client.loop();
}
void publishMQTT(char* mqtt_topic, float value) {
  // Send value as characters
  char msg[50];
  snprintf (msg, 50, "%f", value);
  Serial.print("MQTT: Publish message: ");
  Serial.println(msg);
  client.publish(mqtt_topic, msg);
}

///////////////////////////////////////////////////////////////////////////////////////
// Infite loop trying to reconnect to Mqtt server.
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("MQTT: Attempting connection...");
    Serial.print("MQTT: server: ");
    Serial.println(mqtt_server);
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    Serial.print("MQTT: as client: ");
    Serial.println(clientId);

    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
      // Success
      Serial.println("MQTT: connected");

      // SET THE TOPIC TO SUBSCRIBE HERE
      client.subscribe("testing");
    } else {
      // Failed
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);

    }
  }
}
void callback(char* mqtt_topic, byte* payload, unsigned int length) {
  Serial.print("MQTT: Message arrived [");
  Serial.print(mqtt_topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  String strPayload = String((char*)payload);

  // Serial.println(strPayload.toFloat());
  // Serial.println(strPayload.toInt());

  // USE RECEIVED DATA HERE
  if (strPayload.toInt() > 5) digitalWrite(LED_BUILTIN, LOW);
  else digitalWrite(LED_BUILTIN, HIGH);
}
