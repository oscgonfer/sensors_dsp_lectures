int reading;                               // the reading from the analog input
const int threshold = 20;                   // the threshold

int inputPin = A0;
int LED = 8;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {

  reading = analogRead(inputPin);
  digitalWrite(LED, LOW);

  if (reading >= threshold) {
    digitalWrite(LED, HIGH);
  }

  delay(1);        // delay in between reads for stability
}
