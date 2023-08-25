#include <U8g2lib.h>
#include "font.h"
#include "disp.h"

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R3, /* reset=*/ U8X8_PIN_NONE);
uint32_t ms;
uint8_t cspeed=88, pbat=188;
uint8_t sspeed = 20, gear = 1;
uint16_t cnt = 0, msc = 0;
boolean bSD = true;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  u8g2.begin();
  initDisp();
  //serialDisp();
}

void loop() {
  while (Serial1.available()) Serial1Avail();
  while (Serial.available()) SerialUSBAvail();

  ms = millis();
  if (ms % 500 == 0) {
    bSD = true;
  }
  if (ms % 1000 == 0) timeDisp();
}
