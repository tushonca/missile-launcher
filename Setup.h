void setup() {
  delay(1000);
  noInterrupts();
  DDRB |= 0b01000011; DDRD |= 0b10011100; DDRE |= 0b00110000;
  PMX0 = (1 << WCE); PMX0 = (1 << RXD5);
  TCNT1 = 0; TCCR1A = 0; TCCR1C = 0;
  TCCR1B = (1 << WGM12)|(1 << CS10);
  interrupts();
  
  /* --- ALEDS --- */
  LED.setOutput(7); color.r = 10; color.g = 0; color.b = 0; LED.set_crgb_at(0, color);  LED.sync();
  /* ---#ALEDS --- */
  
  buzzerTone(20000);
  
  /* --- microSD --*/
  color.r = 20; color.g = 0; color.b = 0; LED.set_crgb_at(1, color);  LED.sync(); // показываем цвет инициализации microSD
  while (!SD.begin(1, 10)){};
  SD.remove("INIT.csv"); SD.remove("DATA.csv"); delay(100);
  myFile = SD.open("INIT.csv", FILE_WRITE); myFile.println("SD OK"); myFile.close();
  /* ---#microSD --*/

  /* --- BME280 ---*/
  color.r = 0; color.g = 0; color.b = 20; LED.set_crgb_at(1, color); LED.sync(); // показываем цвет инициализации BME280
  bme.setMode(NORMAL_MODE); bme.setFilter(FILTER_DISABLE); bme.setStandbyTime(STANDBY_10MS); while (!bme.begin()){}; delay(10);
  myFile = SD.open("INIT.csv", FILE_WRITE); myFile.println("BME OK");  myFile.close();
  /* ---#BME280 ---*/

  /* --- MPU9250 --- */
  //myFile.println("MPU OK"); 
  /* ---#MPU9250 --- */
  
  /* --- SBUS --- */
  color.r = 0; color.g = 20; color.b = 0; LED.set_crgb_at(1, color); LED.sync(); // показываем цвет инициализации SBUS
  sBus.begin(); delay(10);
  myFile = SD.open("INIT.csv", FILE_WRITE);
  myFile.println("SBUS OK"); myFile.close(); delay(10);
  color.r = 0; color.g = 100; color.b = 0; LED.set_crgb_at(0, color);
  color.r = 0; color.g = 0; color.b = 0; LED.set_crgb_at(1, color);   // показываем цвет окончания инициализации
  LED.sync(); buzzerNoTone();
  /* ---#SBUS --- */
}
