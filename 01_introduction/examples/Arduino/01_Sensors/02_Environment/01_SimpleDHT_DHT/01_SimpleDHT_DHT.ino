// Import SimpleDHT library in Arduino Library Manager.
#include <SimpleDHT.h>

///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - a digital pin
#define DATA_PIN 5

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - interface for the sensor
SimpleDHT11 sensor(DATA_PIN);
// - containers for the result
int temperature = 0;
int humidity = 0;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("Starting measurement with DHT");
  Serial.println("1. Temperature measured in *C");
  Serial.println("2. Humidity measured in  RH%");
  Serial.println();
}
void loop() {
  // Delay between measurements.
  // NB! since DHT11 reads at 1HZ. Trying to read faster result in error.
  delay(1500);
  
  // Try to read data
  byte temperatureRaw, humidityRaw;
  int err = sensor.read(&temperatureRaw, &humidityRaw, NULL);
  if (err != SimpleDHTErrSuccess) {
    // Error, check library for the type of error
    Serial.print("DHT: Read failed.");
    Serial.print(" Error code: ");
    Serial.print(SimpleDHTErrCode(err));
    Serial.print(", ");
    Serial.println(SimpleDHTErrDuration(err));
  } else {
    // Success
    temperature = (int)temperatureRaw;
    humidity = (int)humidityRaw;
    Serial.print(temperature);
    Serial.print(", ");
    Serial.println(humidity);
    // You can use data starting from here.
  }
}
