///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - an analog pin
#define DATA_PIN A0
// - power - a digital pin 
// NB! to increase longevity of the sensor it is recomended to only power it 
// for the measurement time
#define POWER_PIN 3

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - settings
// duration of the measuring cycle (approximately how often do you measure), must be at least 20
#define cycleDuration 30
// - containers for the result
int waterLevelRaw;
float waterLevelPercentage;

///////////////////////////////////////////////////////////////////////////////////////
void setup() { 
  // Start the serial.
  Serial.begin(115200);
  
  // Prepare the sensor.
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);
  
  Serial.println();
  Serial.println("Starting measurement with Water Level Sensor");
  Serial.println("1. Water Level, percentage along the sensor length");
  Serial.println();
} 
void loop() {
  // Delay between measurements.
  delay(cycleDuration-10);

  digitalWrite(POWER_PIN, HIGH);        // turn the power on
  delay(10);                            // give time for the sensor to start
  waterLevelRaw = analogRead(DATA_PIN); // read the value
  digitalWrite(POWER_PIN, LOW);         // turn the power off

  // Convert raw value into percentage between 0 and 1.
  waterLevelPercentage = ((float)waterLevelRaw)/1023.0;
  Serial.println(waterLevelPercentage);
  // You can use data starting from here.
}
