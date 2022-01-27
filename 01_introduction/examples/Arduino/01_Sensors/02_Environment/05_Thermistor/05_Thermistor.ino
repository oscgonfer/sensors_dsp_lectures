/* 
 Read the raw analog sensorValueRawues of a thermistor using an Arduino Uno and convert them to Celsius sensorValueRawues
 Based on notes: https://antoine.studio/input-devices-thermistor.html
*/
///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - a digital pin
#define DATA_PIN A0

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - container for the result
int sensorValueRaw;
float temperature;
  
void setup() {
  // Start the serial
  Serial.begin(9600);

  Serial.println();
  Serial.println("Starting measurement with Termistor");
  Serial.println("1. Temperature, measured in °C");
  Serial.println();
}

void loop() {
  // Delay between measurements.
  delay(1000);

  // Read and condition the value.
  sensorValueRaw = analogRead(DATA_PIN);
  temperature = ConditionValue(sensorValueRaw);
  Serial.println(temperature);
  // You can use data starting from here.
}

// Function that applies the Steinhart-Hart equation
float ConditionValue(int sensorValueRaw) {
  float sensorValue;
  // From raw analog values
  sensorValue = log(((10240000 / sensorValue) - 10000));
  // To Kelvin sensorValueRawues
  sensorValue = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sensorValue * sensorValue)) * sensorValue);
  // Convert Kelvin to Celsius
  sensorValue = sensorValue - 273.15;
  return sensorValue;
}
