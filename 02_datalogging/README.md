## Presentation

Find it [here](presentations/MRAC_HARDWARE_II_2022_D2.pdf)

## Examples list
- ESP8266
    - [Read analog sensor and stream over MQTT](examples/ESP8266/00_SimpleLoudness_MQTT-Stream/00_SimpleLoudness_MQTT-Stream.ino)
- ESP32
    - [With ESP32Cam stream camera stream as images over HTTP](examples/ESP32Cam/00_CameraStream/00_CameraStream.ino)
- Python
    - Communication
        - [Reading serial stream from Arduino into a CSV with python](examples/Python/00_Communication/00_LogSerial.py)
        - [Sending a string stream over TCP](examples/Python/00_Communication/01_StringStreamerTCP.py)
        - [Receiving a string stream over TCP](examples/Python/00_Communication/02_StringStreamViewerTCP.py)
    - Raspberry Pi
        - [Read a Digital Sensor](examples/Python/01_RaspberryPi/00_digital_sensor.py)
        - [Stream a Digital Sensor over TCP](examples/Python/01_RaspberryPi/01_digital_sensor_streamTCP.py)
        - [Stream a Digital Sensor over MQTT](examples/Python/01_RaspberryPi/02_digital_sensor_streamMQTT.py)
    - OpenCV
        - [Camera Capture](examples/Python/02_OpenCV/00_video.py)
        - [Camera Capture and Storage](examples/Python/02_OpenCV/01_video_capture.py)


## Additional references

- [Installing anaconda](extras/python-anaconda-installation.md)
- [Getting started with rpi](extras/rpi-ssh.md)
- [Getting started with mosquitto](extras/mosquitto.md)
- Good OpenCV material: https://www.learnopencv.com
- Openframeworks tutorial (Lewis Lepton): https://www.youtube.com/channel/UC8Wzk_R1GoPkPqLo-obU_kQ

## Installing OpenCV on the Raspberry Pi

A [perfect guide](https://pimylifeup.com/raspberry-pi-opencv/) to help you set up OpenCV on your Raspberry Pi.
