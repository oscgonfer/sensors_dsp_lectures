# Imports
import time
from machine import Pin

# Start
print("Starting Blink MicroPython program")

# Set up
led = machine.ADC(0) # an analog pin ADC0

# Infinite loop
while True:
    # Read the value, value range 0-65535
    value = led.read_u16()
    # Print to console
    print(value)
    # Delay
    time.sleep(0.1)
