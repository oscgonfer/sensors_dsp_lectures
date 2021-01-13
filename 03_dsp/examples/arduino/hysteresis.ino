int reading;                               // the reading from the analog input
const int threshold = 20;                   // the threshold
const int hysteresis = 2; 

int inputPin = A0;
int LED = 8;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {

  reading = analogRead(inputPin);

  if (reading >= threshold + hysteresis/2) {
    digitalWrite(LED, HIGH);
  } elseif (reading <= threshold - hysteresis/2) {
    digitalWrite(LED, LOW);
  }

  delay(1);        // delay in between reads for stability
}
