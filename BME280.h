/* BME280 functions */
/* BME280 datasheet https://static.chipdip.ru/lib/798/DOC059798074.pdf */
/* BME280 max I2C frequency = 3.4MHz */
#define BMEADDR 0x76

struct {
  uint16_t _T1; uint16_t _T2; uint16_t _T3; // Регистры температуры
  uint16_t _P1; uint16_t _P2; uint16_t _P3; // Регистры давления
  uint16_t _P4; uint16_t _P5;  uint16_t _P6; // Регистры давления
  uint16_t _P7; uint16_t _P8; uint16_t _P9; // Регистры давления
  uint16_t _H1; uint16_t _H2; uint16_t _H3; // Регистры влажности
  uint16_t _H4; uint16_t _H5; uint16_t _H6; // Регистры влажности
} BMECalibrationData;

bool BMEBegin(void) {
    if (!BMEReset()) return false;  // Аппаратный сброс BME280
    uint8_t ID = I2CReadRegister8(BMEADDR, 0xD0); if (ID != 0x60) return false; // Проверка ID чипа (0x60 = BME280)
    BMEReadCalibrationData();                       // Read all calibration values

    /* === Load settings to BME280 === */
    writeRegister(0xF2, _hum_oversampl);                                                        // write hum oversampling value
    writeRegister(0xF2, readRegister(0xF2));                                                    // rewrite hum oversampling register
    writeRegister(0xF4, ((_temp_oversampl << 5) | (_press_oversampl << 2) | _operating_mode));  // write temp & press oversampling value , normal mode
    writeRegister(0xF5, ((_standby_time << 5) | (_filter_coef << 2)));                          // write standby time & filter coef
    return true;
}

bool BMEReset() {
  return I2CWriteRegister(BMEADDR, 0xE0, 0xB6);
  delay(10);
}


void BMEReadCalibrationData(void) {
    if (!I2CWriteData(BMEADDR, 0x88)) return;
    Wire.requestFrom(BMEADDR, 26);
    BMECalibrationData._T1 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._T2 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._T3 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P1 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P2 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P3 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P4 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P5 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P6 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P7 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P8 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._P9 = (Wire.read() | (Wire.read() << 8));
    Wire.read();  // skip 25
    BMECalibrationData._H1 = Wire.read();

    if (!I2CWriteData(BMEADDR, 0xE1)) return;
    Wire.requestFrom(BMEADDR, 8);
    BMECalibrationData._H2 = (Wire.read() | (Wire.read() << 8));
    BMECalibrationData._H3 = Wire.read();
    BMECalibrationData._H4 = (Wire.read() << 4);
    uint8_t interVal = Wire.read();
    BMECalibrationData._H4 |= (interVal & 0xF);
    BMECalibrationData._H5 = (((interVal & 0xF0) >> 4) | (Wire.read() << 4));
    BMECalibrationData._H6 = Wire.read();
}
