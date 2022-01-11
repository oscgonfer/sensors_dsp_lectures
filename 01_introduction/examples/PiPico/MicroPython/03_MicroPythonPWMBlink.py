# Imports
import time, math
from machine import Pin

# Handy functions for the operations
# - remap a number from a range to a range
def remap(value, fromLow, fromHigh, toLow, toHigh):
    return toLow + (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow)
# - constrain a number within a range
def constrain(value, low, high):
    return min(high, max(low, value))

# Start
print("Starting PWM Blink MicroPython program")

# Set up
led = machine.PWM (Pin(22)) # a digital pin GP22 pin
# set PWM frequency to 200 Hz
led.freq(200)

# Variables
timeInCycle = 0.0    # internal variable to keep track of cycle
step = 0.1           # time of the delay
cycleDuration = 5.0  # duration of the cycle

# Infinite loop
while True:
    # Calculate progress within cycle 
    t = math.floor(remap(timeInCycle, 0.0, cycleDuration, 1.0, 65534.0))
    # Set PWM duty cycle to the calculated progress
    led.duty_u16(t)
    # Delay and update progress variables
    time.sleep(abs(step))
    timeInCycle+=step
    if ((timeInCycle > cycleDuration) or (timeInCycle < 0)):
        step *= -1
        timeInCycle = constrain(timeInCycle, 0, cycleDuration)
