///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - relay control pin - a digital pin
#define RELAY_PIN 3

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - controls for the setup
// durations on and off states in milliseconds
int onDuration = 2000;
int offDuration = 2000;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Prepare the actuator.
  pinMode(RELAY_PIN, OUTPUT);
}
void loop() {
  // turn the relay on and wait
  digitalWrite(RELAY_PIN, HIGH);
  delay(onDuration);
  // turn the relay off and wait
  digitalWrite(RELAY_PIN, LOW);
  delay(offDuration);
}
