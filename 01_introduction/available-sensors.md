# Available sensors and their characteristics

- Is it an analog or a digital sensor?
- Suited for Arduino or Raspberry Pi?
- Voltage levels, supply current?
- Existing librairies?

---

## RGBD camera

### Kinect v1

### INTEL REALSENSE D435i

- Digital sensor ([reference](https://www.intelrealsense.com/depth-camera-d435i/))
- Suited for Raspberry Pi: [installation guide](https://github.com/IntelRealSense/librealsense/blob/master/doc/installation_raspbian.md) + example ([3D scanning using a RPI4 and Intel Realsense camera](https://hackaday.com/2020/03/31/handheld-3d-scanning-using-raspberry-pi-4-and-intel-realsense-camera/))
- Operating voltage: 4.5-5.25 V
- Operating current: 300 mA

## Thermal camera
### Flir one

- Digital sensor ([reference](https://www.flir.co.uk/flir-one/) + [datasheet](https://www.flirmedia.com/MMC/THG/Brochures/IND_036/IND_036_EN.pdf))
- Suited for Rasberry Pi: [installation guide](https://github.com/groupgets/LeptonModule)
- Operating voltage: 5V

## Tracking camera board
### Pixy2 Smart Vision Sensor

- Digital sensor ([reference](https://pixycam.com/pixy2/) + [documentation](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:start))
- Suited for Arduino and Raspberry Pi
- Operating voltage: 5V ([doc](https://docs.pixycam.com/wiki/doku.php?id=wiki:v1:powering_pixy&s[]=power))
- Operating current: 1.5A
- Inspirational [projects](https://pixycam.com/projects/)

## Orientation sensor
### BNO055 Absolute Orientation Sensor

- Analog sensor ([reference](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/overview) + [pinouts](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/pinouts) + [datasheet](https://cdn-shop.adafruit.com/datasheets/BST_BNO055_DS000_12.pdf))
- Suited for Arduino
- Operating voltage: 3.3-5V
- [Library](https://github.com/adafruit/Adafruit_BNO055)

## GPS module + antena
### AdaFruit 746 GPS Ultimate Module

- Analog sensor ([reference](https://learn.adafruit.com/adafruit-ultimate-gps))
- Suited for Arduino
- Operating voltage: 5V
- Operating current: 20mA
- [Library](https://github.com/adafruit/Adafruit_GPS)

## Ultrasonic Sensor

### HC-SR04 (Basic)

- Analog sensor ([reference](https://learn.adafruit.com/ultrasonic-sonar-distance-sensors/))
- Suited for Arduino
- Operating voltage: 3.3V-5V
- [Library](https://github.com/d03n3rfr1tz3/HC-SR04)

### MB7389 HRXL-MaxSonar-WRMT (++)

- Analog sensor ([reference](https://www.maxbotix.com/ultrasonic_sensors/mb7389.htm) + [datasheet](https://www.maxbotix.com/documents/HRXL-MaxSonar-WR_Datasheet.pdf))
- Suited for Arduino
- Operating voltage: 2.7-5.5V
- Operating current: 3.1 mA
- Arduino [examples and tutorials](https://www.maxbotix.com/articles/mb7389-x-arduino-tutorial-with-code-examples.htm)

## laser distance sensor

### JRT_U81

- Analog sensor ([reference](https://jrt-measure.en.made-in-china.com/product/nsvQjZMrQFVN/China-Laser-Distance-Sensor-Price-Jrt-U81.html))
- Suited for Arduino ([manufacturer's guide](https://www.laserrangesensor.com/laser-distance-sensor/short-range-laser-distance-sensor/short-distance-measurement-sensor.html))
- Operating voltage: 2.0-3.3V

## Pressure Sensor
### IFM with I/O Link

## Flow Meter	(IFM with I/O Link)

## Arduino Basic Sensors kit

## Air Temp & Hum Sensor (SHT31-D Air Temperature & Humidity Sensor)

## Contact Temp Sensor	(DS18B20 Waterproof Contact temperature sensor)

## Touch Sensor (Velostat Adafruit 1361)

---

## HTC Vive Tracker

- Reference: [https://www.vive.com/us/accessory/vive-tracker/](https://www.vive.com/us/accessory/vive-tracker/)
- [Open-source alternative](https://hackaday.io/project/160182-hivetracker): Tiny, low-cost and scalable device for sub-millimetric 3D positioning

## Action Camera (Mobius)

- Reference: http://www.mobius-actioncam.com/mobius/wp-content/uploads/2015/01/Mobius-Manual-23jan15a.pdf

