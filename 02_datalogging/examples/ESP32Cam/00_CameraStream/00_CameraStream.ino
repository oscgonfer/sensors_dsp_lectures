#include <Arduino.h>
#include "CameraInterface.h"
#include "WiFiInterface.h"
//disable brownout problems
#include <soc/soc.h>
#include <soc/rtc_cntl_reg.h>

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector

  // Initiate camera
  if (!CameraBegin()){
    return;  
  }
  // Initiate Wi-Fi connection
  WiFiBegin();
  // Start streaming web server
  CameraServerBegin();
}

void loop() {
  // needed for sketch to compile, doesn't actually do anything.
  delay(1);
}
