///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - an analog pin
#define DATA_PIN A0

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - containers for the result
int potentiometerState;
float potentiometerPercentage;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("Read Potentiometer Input");
  Serial.println("1. potentiometer analog state, 0 through 1023");
  Serial.println("2. potentiometer percentage, 0.0 through 1.0");
  Serial.println();
} 
void loop() {
  // Delay between measurements (for slightly smoother, more stable readings).
  delay(50);
  
  potentiometerState = analogRead(DATA_PIN);
  potentiometerPercentage = ((float)potentiometerState)/1023.0;
  Serial.print(potentiometerState);
  Serial.print(", ");
  Serial.println(potentiometerPercentage);
  // You can use data starting from here.
}
