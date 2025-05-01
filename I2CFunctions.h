#include <Wire.h>
Wire.begin();




/* 
 * I2CWriteData - запись данных в шину
 * @address - адресс Slave устроиства для записи
 * @data - данные для записи в шину
 * return - false = ошибка / true = успех
 */
bool I2CWriteData(uint8_t address, uint8_t data) {
  Wire.beginTransmission(address);
  Wire.write(data);
  if(Wire.endTransmission() != 0) return false;
  return true;
}

/* 
 * I2CWriteRegister - запись данных в регистр устройства
 * @address - адресс Slave устроиства для записи
 * @registerAddress - адрес регистра в Slave устроистве
 * @data - данные для записи в регистр
 * return - false = ошибка / true = успех
 */
bool I2CWriteRegister(uint8_t address, uint8_t registerAddress, uint8_t data) {
  Wire.beginTransmission(address);
  Wire.write(registerAddress);  
  Wire.write(data);
  if(Wire.endTransmission() != 0) return false;
  return true;
}
 /*I2CReadRegister8 - чтение одного 8ми битного регистра с устроиства
  * @address - адресс Slave устроиства для чтения
  * @registerAddress - адрес регистра в Slave устроистве
  * return - uint8_t число из регистра Slave устроиства
  */
uint8_t I2CReadRegister8(uint8_t address, uint8_t registerAddress) {
  Wire.beginTransmission(address);
  Wire.write(registerAddress);
  if (Wire.endTransmission() != 0) return 0;
  Wire.requestFrom(address, 1);
  return Wire.read();
}
