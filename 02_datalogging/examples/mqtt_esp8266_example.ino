#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// SETUP WIFI CREDENTIALS
const char* ssid = "YOURWIFIHERE";
const char* password = "YOURPASSWORDHERE";
const char* mqtt_server = "SERVERADDRESS";
const char* mqtt_user = "MQTTUSER";
const char* mqtt_pass = "MQTTPASS";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  // PUT THE CODE TO START YOUR SENSORS HERE
  
}

void loop() {

  if (!client.connected()) reconnect();
  client.loop();

  // Publish every 1000 milliseconds
  if (millis() % 1000 == 0) {

    // READ YOUR SENSOR DATA HERE
    float value = analogRead(A0);

    // Send value as characters
    char msg[50];
    snprintf (msg, 50, "%f", value);
    Serial.print("Publish message: ");
    Serial.println(msg);

    // SET THE TOPIC TO PUBLISH HERE
    client.publish("outTopic", msg);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  
  Serial.print("Message arrived [");
  Serial.print(topic);
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

void reconnect() {
  
  // Loop until we're reconnected
  while (!client.connected()) {
    
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
   
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
      Serial.println("connected");
      
      // SET THE TOPIC TO SUBSCRIBE HERE
      client.subscribe("testing");
    
    } else {

      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);

    }
  }
}

void setup_wifi() {
  
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}