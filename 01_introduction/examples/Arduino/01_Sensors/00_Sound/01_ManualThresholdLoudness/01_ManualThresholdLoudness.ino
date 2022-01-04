///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - data - an analog pin
#define DATA_PIN A0

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - settings
#define initialSampleCount 100
// - container for the result
int loudnessBaseLine;
int loudnessRaw;
float loudnessPercentage;

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the serial
  Serial.begin(115200);
  
  // Prepare the sensor.
  // Find max loudness over initial sample count as a calibration
  Serial.println("Calibrating");
  delay(10);
  loudnessBaseLine = 0;
  for (int i =0; i < initialSampleCount; i++){
    loudnessRaw = analogRead(DATA_PIN);
    // Serial.println(loudnessRaw);
    Serial.print(".");
    if (loudnessRaw > loudnessBaseLine){
      loudnessBaseLine = loudnessRaw;
    }
    delay(10);
  }
  Serial.println();
  Serial.print("Max Baseline Loundness: ");
  Serial.println(loudnessBaseLine);
  
  Serial.println();
  Serial.println("Starting measurement with Sound Loudness Sensor");
  Serial.println("1. Loudness raw analog reading");
  Serial.println("2. Loudness percentage between 0 and 1");
  Serial.println("3. Loudness binary presence");
  Serial.println();
}
void loop() {  
  loudnessRaw = analogRead(DATA_PIN);
  Serial.print(loudnessRaw);
  Serial.print(", ");
  loudnessPercentage = ((float)loudnessRaw)/1023.0;
  Serial.print(loudnessPercentage);
  Serial.print(", ");
  // You can use data starting from here.
  if (loudnessRaw > loudnessBaseLine){
    // Sound above threshold made.
    Serial.print(1.0);
  } else {
    // Bellow base sound level.  
    Serial.print(0.0);
  }
  Serial.println();
}
