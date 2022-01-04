#include <Arduino.h>
#include <WiFi.h>

///////////////////////////////////////////////////////////////////////////////////////
// NB! Replace with your network credentials
const char *ssid = "MiFibra-6FFA";
const char *password = "acM75LAY";

///////////////////////////////////////////////////////////////////////////////////////
// Try toto connect to Network.
void WiFiBegin(){
  Serial.println();
  Serial.print("WiFi: Connecting to the network ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi: Connected successfully!");
  
  Serial.print("WiFi: Local IP: http://");
  Serial.println(WiFi.localIP());
}
