// Import NewPing library in Arduino Library Manager.
#include <NewPing.h>

///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - trigger - a digital pin
#define TRIGGER_PIN 5
// - echo - a digital pin
#define ECHO_PIN 6

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - interface for the sensor
#define maxDistance 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sensor(TRIGGER_PIN, ECHO_PIN, maxDistance); // NewPing setup of pins and maximum distance.
// - container for the result
unsigned long distance;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("Starting measurement with Ultrasonic Proximity Sensor");
  Serial.println("1. Distance measured in cm");
  Serial.println();
}
void loop() {
  // Delay between measurements.
  delay(50);

  // Read data
  distance = sensor.ping_cm();
  if (distance == 0){
    // Max distance defaults to 0
    Serial.println("Invalid Reading");
  } else{
    Serial.println(distance);
    // You can use data starting from here.
  }
}
