// Measuring a distance using a ultrasonic sensor HC-SR04 and an Arduino Uno
// Extra notes: https://antoine.studio/input-devices-ultrasonic-sensor.html

#include <Arduino.h>

int trigPin = 11;
int echoPin = 12;
long duration, cm;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;
  Serial.print(cm);
  Serial.print("cm");
  delay(250);
}