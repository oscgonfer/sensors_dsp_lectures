// Import DHT_sensor_library  and its dependency library Adafruit_Unified_Sensor_Driver in Arduino Library Manager.
#include <DHT.h>

///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - a digital pin
#define DATA_PIN 5
// - data - a sensor type
#define sensorType DHT11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - interface for the sensor
DHT sensor(DATA_PIN, sensorType);
// - containers for the result
float temperature = 0;
float humidity = 0;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  // Prepare the sensor.
  sensor.begin();
  
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
  temperature = sensor.readTemperature();
  humidity = sensor.readHumidity();
  if (isnan(humidity) || isnan(temperature)) {
    // Error
    Serial.println("DHT: Read failed.");
  } else {
    // Success
    Serial.print(temperature);
    Serial.print(", ");
    Serial.println(humidity);
    // You can use data starting from here.
  }
}
