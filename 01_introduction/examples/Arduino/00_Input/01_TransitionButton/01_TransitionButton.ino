///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - a digital pin
// Button connected with default state off with puill-down resistor on reading side.
#define DATA_PIN 5

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - containers for the result
bool buttonState;
bool previousButtonState;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  // Prepare the sensor.
  pinMode(DATA_PIN, INPUT);
  
  Serial.println();
  Serial.println("Read Button transition state");
  Serial.println("1. button transition state (rising edge, held down, falling edge, or held up)");
  Serial.println();
} 
void loop() {
  // To mitigate bouncing introduce delay between readings
  // (but not too high to not miss quick button presses).
  delay(10);
  
  buttonState = (bool)digitalRead(DATA_PIN);
  // Uncomment whichever state you are interested in and trigger events in the statement
  if ((previousButtonState == false) && (buttonState == true)){
    Serial.println("Rising Edge");
  } else if ((previousButtonState == true) && (buttonState == true)){
    //Serial.println("Held down");
  } else if ((previousButtonState == true) && (buttonState == false)){
    //Serial.println("Falling Edge");
  } else {// if ((previousButtonState == false) && (buttonState == false)){
    //Serial.println(Held up);
  }
  // Record currentState as previous for the next reading.
  previousButtonState = buttonState;
}
