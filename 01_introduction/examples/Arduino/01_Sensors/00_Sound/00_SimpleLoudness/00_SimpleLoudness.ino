///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - a digital pin
#define DATA_PIN 3
#define RAWDATA_PIN A0
// Use the potentiometer to adjust the Sound Sensor sensitivity.
// Clockwise to lower, and counter-clockwise to increase threshold and thus reduce sensiivity.
  

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - container for the result
int loudness;
int loudnessRaw;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial
  Serial.begin(115200);
  
  // Prepare the sensor.
  pinMode(DATA_PIN, INPUT);
  
  Serial.println();
  Serial.println("Starting measurement with Sound Loudness Sensor");
  Serial.println("1. Loudness binary presence (digital)");
  Serial.println("2. Loudness raw analog reading");
  Serial.println();
}
void loop() {  
  loudness = digitalRead(DATA_PIN);
  loudnessRaw = analogRead(RAWDATA_PIN);
  Serial.print(loudness);
  Serial.print(", ");
  Serial.println(loudnessRaw);
  // You can use data starting from here.
}
