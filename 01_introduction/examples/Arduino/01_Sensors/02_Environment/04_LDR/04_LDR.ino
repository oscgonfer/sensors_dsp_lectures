/*
  Example based on @vicobarberan on Input Class of Fabacademy 2020.
*/
///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data pin - an analog pin
#define DATA_PIN A0

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - container for the result
int sensorValueRaw;
float voltage;
int ldr;
// - settings for conversion of LDR values:
int R2 = 10000;
float VIN = 5.0;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(9600);

  Serial.println();
  Serial.println("Starting measurement with LDR");
  Serial.println("1. Voltage measured in Volts");
  Serial.println("2. Light value");
  Serial.println();
}

void loop() {
  // Delay between measurements.
  delay(10);

  // Read the input on analog pin 0:
  sensorValueRaw = analogRead(DATA_PIN);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  voltage = sensorValueRaw * (5.0 / 1023.0);

  // Get the value of R1
  ldr = ((R2 * VIN) / voltage) - R2;

  // Print out the value you read:
  Serial.print(voltage);
  Serial.print(", ");
  Serial.println(ldr);
  // You can use data starting from here.
}
