## Presentations

Find it [here](presentations/MRAC_HARDWARE_II_2022_D1.pdf)
Computer Types [here](presentations/MRAC_HARDWARE_II_2022_COMPUTERS.pdf)
Back to basics [here](presentations/MRAC_HARDWARE_II_2022_BackToBasics.pdf)

**NB**
Heavily inspired by: https://fablabbcn-projects.gitlab.io/learning/fabacademy-local-docs/material/extras/week09/inputdevices/

## Examples list

- [Arduino examples on C++](examples/Arduino/)
    - Input		- examples on reading simple inputs
        - [Simple Button](examples/Arduino/00_Input/00_SimpleButton/00_SimpleButton.ino) 						- read a simple button value with a digital pin
        - [Transition Button](examples/Arduino/00_Input/01_TransitionButton/01_TransitionButton.ino)					- isolate transitions of a button
        - [Simple Potentiometer](examples/Arduino/00_Input/02_SimplePotentiometer/02_SimplePotentiometer_Diagram.jpg)				- read potentiometer values with an analog pin
        - [Debouncing Button](examples/Arduino/00_Input/03_DebounceButton/03_DebounceButton.ino)				    - debounce a push-button value
    - Sensors		- examples on reading simple sensor values
        - Sound
            - [Simple Loudness](examples/Arduino/01_Sensors/00_Sound/00_SimpleLoudness/00_SimpleLoudness.ino) 				- read digital and analog raw values
            - [Manual Threshold Loudness](examples/Arduino/01_Sensors/00_Sound/01_ManualThresholdLoudness/01_ManualThresholdLoudness.ino)		- just using analog custom calibrate sensor
        - Proximity
            - [Ultrasonic Proximity](examples/Arduino/01_Sensors/01_Proximity/00_UltrasonicProximity/00_UltrasonicProximity.ino)			- read proximity, define a function
            - [NewPing Ultrasonic Proximity](examples/Arduino/01_Sensors/01_Proximity/01_NewPing_UltrasonicProximity/01_NewPing_UltrasonicProximity.ino)	- read proximity through a library
        - Environment
            - [Adaftuit DHT](examples/Arduino/01_Sensors/02_Environment/00_Adafruit_DHT/00_Adafruit_DHT.ino)					- read temperature and humidity values from a sensor
            - [SimpleDHT DHT](examples/Arduino/01_Sensors/02_Environment/01_SimpleDHT_DHT/01_SimpleDHT_DHT.ino)					- alternative comparison with different library
            - [Soil Moisture](examples/Arduino/01_Sensors/02_Environment/02_SoilMoisture/02_SoilMoisture.ino)					- read soil moisture level
            - [Water Level](examples/Arduino/01_Sensors/02_Environment/03_WaterLevel/03_WaterLevel.ino)						- read water level (almost identical structure)
            - [LDR](examples/Arduino/01_Sensors/02_Environment/04_LDR/04_LDR.ino)						        - read light sensor (simple analog sensor) with unit conversion
            - [Thermistor](examples/Arduino/01_Sensors/02_Environment/05_Thermistor/05_Thermistor.ino)						- read temperature (simple analog sensor) with unit conversion
    - Actuators 	- examples on triggering actuators
        - [Simple Relay](examples/Arduino/02_Actuators/00_SimpleRelay/00_SimpleRelay.ino)						- toggle periodically a relay

- [PiPico examples on C++ and on MicroPython](examples/PiPico/)
    - C++
        - [Blink](examples/PiPico/C++/00_Blink/00_Blink.ino)		- Blink the LED through a digital pin
    - MicroPython - examples on MicroPython for the Raspberry Pi Pico
        - [Hello World](01_introduction/examples/PiPico/MicroPython/00_HelloWorld.py)                                          - Test running python and reading in the console
        - [Blink](01_introduction/examples/PiPico/MicroPython/01_Blink.py)                                          - Blink the LED through a digital pin
        - [Light Sensor](01_introduction/examples/PiPico/MicroPython/02_LightSensor.py)                                          - Read data from an analog pin
        - [PWM Blink](01_introduction/examples/PiPico/MicroPython/03_PWMBlink.py)                                          - Gradually blink the LED with a digital pin using PWM

- [Adafruit SHT31](https://github.com/adafruit/Adafruit_SHT31/blob/master/examples/SHT31test/SHT31test.ino)

## Additional references

- [Add other boards to ArduinoIDE](extras/ArduinoIDE_README.md)
- Find an ever-growing sensor list [here](https://hackmd.io/xAjS5n_ASTOmX9EhacRRhw?view) (again by @vicobarberan)
