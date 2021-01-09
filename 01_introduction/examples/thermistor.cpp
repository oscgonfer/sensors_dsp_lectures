// Read the raw analog values of a thermistor using an Arduino Uno and convert them to Celsius values
// Extra notes: https://antoine.studio/input-devices-thermistor.html

#include <Arduino.h>
#include <math.h>

void setup()
{
  Serial.begin(9600);
}

// Function that applies the Steinhart-Hart equation
float thermistor(int val)
{
  float temp;
  // From raw analog values
  temp = log(((10240000 / val) - 10000));
  // To Kelvin values
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
  // Convert Kelvin to Celsius
  temp = temp - 273.15;
  return temp;
}

void loop()
{
  int val;
  float temp;
  val = analogRead(0);
  temp = thermistor(val);
  Serial.print(temp);
  Serial.println(" °C");
  delay(1000);
}