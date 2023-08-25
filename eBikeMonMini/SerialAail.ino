uint8_t rx_buf[14];
uint8_t rx_counter = 0;

//90 16 10 100 10 1 0 125 1 0 0 0 48 55  -  100% 10km/h
//90 16 10 99 9 1 0 125 1 0 0 0 48 53  -  99% 9km/h
//90 16 10 50 25 1 0 125 1 0 0 0 48 20  -  50% 25km/h
void Serial1Avail()
{
  uint8_t rxd, i;
  rxd = Serial1.read();
  //수신된 패킷을 USB시리얼로 전달
  Serial.write(rxd);

  for (i = 0; i < 13; i++) {
    rx_buf[i] = rx_buf[i + 1];
  }
  rx_buf[13] = rxd;
  if (checksum()) {
    pbat = rx_buf[3];
    cspeed = rx_buf[4];
    if (bSD) {
      serialDisp();
      bSD = false;
    }
  }
}

void SerialUSBAvail()
{
  uint8_t txd;
  txd = Serial.read();
  Serial1.write(txd);
}

boolean checksum()
{
  uint8_t i, s = 0;
  if (rx_buf[0] != 0x5A) return false;
  if (rx_buf[1] != 0x10) return false;
  if (rx_buf[2] != 0x0A) return false;
  for (i = 1; i < 13; i++) s += rx_buf[i];
  if (s == rx_buf[13]) return true;
  else return false;
}
