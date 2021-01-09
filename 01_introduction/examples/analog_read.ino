/*
Example from @vicobarberan on Input Class of Fabacademy 2020
*/


int R2 = 10000;
float VIN = 5.0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Get the value of R1
  int ldr = ((R2 * VIN) / voltage) - R2;
  
  // print out the value you read:
  Serial.print("voltage: ");
  Serial.println(voltage);
  Serial.print("LDR value: ");
  Serial.println(ldr);
}

