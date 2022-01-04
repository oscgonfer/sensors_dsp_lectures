///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - trigger - a digital pin
#define TRIGGER_PIN 5
// - echo - a digital pin
#define ECHO_PIN 6

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - container for the result
long duration;
int distance;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial.
  Serial.begin(115200);
  
  // Prepare the sensor.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println();
  Serial.println("Starting measurement with Ultrasonic Proximity Sensor");
  Serial.println("1. Distance measured in cm");
  Serial.println();
}
void loop() {
  // Delay between measurements.
  delay(50);

  // Read data
  distance = MeasureDistance();
  Serial.println(distance);
  // You can use data starting from here.
}

int MeasureDistance(){
  // Clears the TRIGGER_PIN condition
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  // Sets the TRIGGER_PIN HIGH (ACTIVE) for 10 microseconds
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  return duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}
