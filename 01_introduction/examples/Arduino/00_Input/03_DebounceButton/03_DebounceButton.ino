/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/
///////////////////////////////////////////////////////////////////////////////////////
// Layout:
// - button - a digital pin for push button
#define BUTTON_PIN 2
// - echo - a digital pin for LED
#define LED_PIN 13

///////////////////////////////////////////////////////////////////////////////////////
// Global variables
// - container for the states
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current buttonRawState from the input pin
int buttonRawState;      // the raw state of the input
int lastButtonState = LOW;   // the previous buttonRawState from the input pin
// - debounce setting
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
// - internal
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
// These variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Prepare the sensor.
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  // Set initial LED state
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  // read the state of the switch:
  buttonRawState = digitalRead(BUTTON_PIN);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (buttonRawState != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the buttonRawState is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (buttonRawState != buttonState) {
      buttonState = buttonRawState;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(LED_PIN, ledState);

  // save the buttonRawState. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = buttonRawState;
}
