
#define POSBATPERX 35

void initDisp() {
  uint8_t i;
  u8g2.firstPage();
  do {
    //배경
    u8g2.drawXBMP(0, 0, 64, 128, background);

    //전화번호 윗줄 010-
    for (i = 0; i < sizeof(TEL0); i++) {
      u8g2.drawXBMP(5 + i * 6, 106, 5, 7, num_5_7[TEL0[i]]);
    }

    //전화번호 아랫줄 0000-0000
    for (i = 0; i < sizeof(TEL1); i++) {
      u8g2.drawXBMP(5 + i * 6, 117, 5, 7, num_5_7[TEL1[i]]);
    }

  } while ( u8g2.nextPage());
}

void serialDisp() {
  uint8_t i;


  //배터리 바 7,6
  u8g2.drawXBMP(7, 6, 3, 4, batbar_3_4[pbat >= 20]);
  u8g2.drawXBMP(11, 6, 3, 4, batbar_3_4[pbat >= 40]);
  u8g2.drawXBMP(15, 6, 3, 4, batbar_3_4[pbat >= 60]);
  u8g2.drawXBMP(19, 6, 3, 4, batbar_3_4[pbat >= 80]);
  u8g2.drawXBMP(23, 6, 3, 4, batbar_3_4[pbat >= 100]);

  //배터리 퍼센트
  if (pbat >= 100) u8g2.drawXBMP(POSBATPERX, 5, 5, 7, num_5_7[1]);
  else  u8g2.drawXBMP(POSBATPERX, 5, 5, 7, num_5_7[16]);
  u8g2.drawXBMP(POSBATPERX + 6, 5, 5, 7, num_5_7[pbat / 10 % 10]);
  u8g2.drawXBMP(POSBATPERX + 12, 5, 5, 7, num_5_7[pbat  % 10]);

  //속도
  if (cspeed >= 10) u8g2.drawXBMP(8, 50, 14, 26, num_14_26[cspeed / 10 % 10]);
  else u8g2.drawXBMP(8, 50, 14, 26, num_14_26[10]);
  u8g2.drawXBMP(26, 50, 14, 26, num_14_26[cspeed % 10]);

  //설정속도
  //u8g2.drawXBMP(43, 72, 5, 7, num_5_7[sspeed / 10 % 10]);
  //u8g2.drawXBMP(49, 72, 5, 7, num_5_7[sspeed  % 10]);

  //기어
  u8g2.drawXBMP(41, 82, 14, 26, num_14_26[gear % 10]);

  //serial data 0~3
  for (i = 0; i < 4; i++) {
    u8g2.drawXBMP(5 + i * 14, 18, 5, 7, num_5_7[rx_buf[i] / 16 % 16]);
    u8g2.drawXBMP(5 + 6 + i * 14, 18, 5, 7, num_5_7[rx_buf[i] % 16]);
  }
  //serial data 4-7
  for (i = 0; i < 4; i++) {
    u8g2.drawXBMP(5 + i * 14, 28, 5, 7, num_5_7[rx_buf[i + 4] / 16 % 16]);
    u8g2.drawXBMP(5 + 6 + i * 14, 28, 5, 7, num_5_7[rx_buf[i + 4] % 16]);
  }
  //serial data 8-11
  for (i = 0; i < 4; i++) {
    u8g2.drawXBMP(5 + i * 14, 38, 5, 7, num_5_7[rx_buf[i + 8] / 16 % 16]);
    u8g2.drawXBMP(5 + 6 + i * 14, 38, 5, 7, num_5_7[rx_buf[i + 8] % 16]);
  }
  //serial data 12-13
  for (i = 0; i < 2; i++) {
    u8g2.drawXBMP(5 + i * 14, 82, 5, 7, num_5_7[rx_buf[i + 12] / 16 % 16]);
    u8g2.drawXBMP(5 + 6 + i * 14, 82, 5, 7, num_5_7[rx_buf[i + 12] % 16]);
  }

  u8g2.sendBuffer();
}

void timeDisp()
{
  if (ms / 1000 / 60 / 60 / 10 % 10 == 0) u8g2.drawXBMP(5, 92, 5, 7, num_5_7[16]);
  else u8g2.drawXBMP(5, 92, 5, 7, num_5_7[ms / 1000 / 60 / 60 / 10 % 10]);
  u8g2.drawXBMP(11, 92, 5, 7, num_5_7[ms / 1000 / 60 / 60 % 10]);
  u8g2.drawXBMP(18, 92, 1, 7, spc_1_7[ms / 1000   % 2]);
  u8g2.drawXBMP(21, 92, 5, 7, num_5_7[ms / 1000 / 60 / 10 % 6]);
  u8g2.drawXBMP(27, 92, 5, 7, num_5_7[ms / 1000 / 60 % 10]);
  u8g2.sendBuffer();
}
