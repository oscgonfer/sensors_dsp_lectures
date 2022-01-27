# Imports
import time
from machine import Pin

# Start
print("Starting Blink MicroPython program")

# Set up
led = Pin (22, Pin.OUT) # a digital pin GP22 pin

# Infinite loop
while True:
    # Set LED pin high
    led.high()
    # Delay for half a second
    time.sleep(0.5)
    # Set LED pin low
    led.low()
    # Delay for half a second
    time.sleep(0.5)