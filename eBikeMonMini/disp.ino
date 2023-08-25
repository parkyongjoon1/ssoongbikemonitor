
#define POSBATPERX 35

void initDisp() {
  u8g2.drawXBMP(0, 0, 28, 17, bat_28_17);
  u8g2.sendBuffer();
}

void serialDisp() {
  uint8_t i;


  //배터리 바 7,6
  u8g2.drawXBMP(4, 3, 3, 11, batbar_3_11[pbat >= 25]);
  u8g2.drawXBMP(9, 3, 3, 11, batbar_3_11[pbat >= 50]);
  u8g2.drawXBMP(14, 3, 3, 11, batbar_3_11[pbat >= 75]);
  u8g2.drawXBMP(19, 3, 3, 11, batbar_3_11[pbat >= 100]);

  //배터리 퍼센트
  u8g2.setFont( u8g2_font_spleen12x24_mn);
  u8g2.setCursor(28, 17);
  u8g2.printf("%3d", pbat);

  //속도
  u8g2.setFont( u8g2_font_spleen32x64_mn);
  u8g2.setCursor(0, 72);
  u8g2.printf("%2d", cspeed);

  u8g2.sendBuffer();
}

void timeDisp()
{
  u8g2.setFont( u8g2_font_spleen12x24_mn);
  u8g2.setCursor(0, 128);
  if (ms / 1000 % 2 == 0) {
    u8g2.printf("%2d:%02d", ms / 1000 / 60 / 60 % 100, ms / 1000 / 60 % 60);
  }
  else {
    u8g2.printf("%2d %02d", ms / 1000 / 60 / 60 % 100, ms / 1000 / 60 % 60);
  }
  u8g2.sendBuffer();
}
