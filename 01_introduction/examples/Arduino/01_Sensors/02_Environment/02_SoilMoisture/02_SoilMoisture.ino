///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - an analog pin
#define DATA_PIN A0
// - power - a digital pin 
// NB! to increase longevity of the sensor and minimize oxidization
// it is recomended to only power it for the measurement time
#define POWER_PIN 3

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - settings
// duration of the measuring cycle (approximately how often do you measure), must be at least 20
#define cycleDuration 30
// - containers for the result
int soilMoistureRaw;
float soilPercentage;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  // Prepare the sensor.
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);
  
  Serial.println();
  Serial.println("Starting measurement with Soil Moisture Sensor");
  Serial.println("1. Soil Moisture, moisture level");
  Serial.println();
} 
void loop() {
  // Delay between measurements.
  delay(cycleDuration-10);
  
  digitalWrite(POWER_PIN, HIGH);          // turn the power on
  delay(10);                              // give time for the sensor to start
  soilMoistureRaw = analogRead(DATA_PIN); // read the value
  digitalWrite(POWER_PIN, LOW);           // turn the power off
  
  // Convert raw value into percentage between 0 and 1.
  soilPercentage = ((float)soilMoistureRaw)/1023.0;
  Serial.println(soilPercentage);
  // You can use data starting from here.
}
