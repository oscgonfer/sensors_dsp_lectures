///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - a digital pin
// Button connected with default state off with puill-down resistor on reading side.
#define DATA_PIN 5

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - containers for the result
bool buttonState;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  // Prepare the sensor.
  pinMode(DATA_PIN, INPUT);
  
  Serial.println();
  Serial.println("Read Button input");
  Serial.println("1. button state, 0 - disconnected and 1 - connected");
  Serial.println();
} 
void loop() {
  buttonState = (bool)digitalRead(DATA_PIN);
  Serial.println(buttonState);
  // You can use data starting from here.
}
