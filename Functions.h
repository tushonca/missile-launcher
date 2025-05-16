ISR(TIMER1_COMPA_vect) {PINE |= (1 << PINE5);}
void buzzerTone(uint16_t FREQIN) {OCR1A = FREQIN; TIMSK1 |= (1 << OCIE1A);}
void buzzerNoTone() {TIMSK1 &= 0b11111101; PORTE  &= 0b11011111; DDRE   &= 0b11011111;}

void cnDataUpdate(){
  if (sBus.toChannels == 0) {return;}
  sBus.UpdateChannels();
  for (byte i = 0; i < 6; i++) {
    if (sBus.channels[i + 4] > 10 && sBus.channels[i + 4] < 600){cnData[i] = 1;}
    if (sBus.channels[i + 4] > 600 && sBus.channels[i + 4] < 1300){cnData[i] = 3;}
    if (sBus.channels[i + 4] > 1300 && sBus.channels[i + 4] < 2000){cnData[i] = 2;}
  }
}

void writeSD(String data, bool lines, bool files, byte fileManip) {
  if (fileManip == 1 || fileManip == 3){
    if (files == 0) {myFile = SD.open("DATA.csv", FILE_WRITE);} // Если fileManip 1 - откроем наш файл
    if (files == 1) {myFile = SD.open("INIT.log", FILE_WRITE);} // Если fileManip 1 - откроем наш файл
  }
  if (lines == 1) {myFile.println(data);}
  if (lines == 0) {myFile.print(data);}
  if (fileManip == 2 || fileManip == 3) {myFile.close();} // Если fileManip 2 - закроем файл
    // Если fileManip не 1 и не 2, то ничешл с файлом не деалем
    // Если 3, то открываем и закрываем файл
}

void remoteControl(){
  if (cnData[4] == 1) { // Пока нажат курок подтверждения
    if (cnData[0] == 1 && mode == 0) {mode = 1; startTime = millis(); writeSD("AUTOmode ON", 1, 1, 3);} // запуск АУ
    if (cnData[0] == 2 && mode == 0) {mode = 2; startTime = millis(); writeSD("OPmode ON", 1, 1, 3);} // запуск РУ
          
    if (cnData[5] == 3 && mode == 2) {mode = 3; digitalWrite(Q1, 1); writeSD("OPmode 1 engine ON", 1, 1, 3);} // запуск 1й ступент РУ
    if (cnData[5] == 1 && mode == 3) {mode = 4; digitalWrite(Q2, 1); writeSD("OPmode 2 engine ON", 1, 1, 3);} // запуск 2й ступени РУ
              
    //if (cnData[3] == 1 && mode != 0) {writeSD("EMERGENCY Parat ON", 1, 1, 3); mode = 8; start2EngineTime = millis();} // открываем парашют
  }
  
  if (mode == 1) {start1EngineTime = millis(); mode = 5; digitalWrite(Q1, 1); writeSD("AUTOmode 1st engine start", 1, 1, 3);} // запуск 1й ступени в АУ
  if (mode == 5 && millis() - start1EngineTime >= DELAY_SECOND_ENGINE) {start2EngineTime = millis(); mode = 6; digitalWrite(Q2, 1); writeSD("AUTOmode 2nd engine start", 1, 1, 3);} // запуск 2й ступени АУ
  //if (mode == 6 && millis() - start2EngineTime >= DELAY_PARACHUTE) {mode = 7; digitalWrite(Q5, 1); writeSD("AUTOmode parachute ON", 1, 1, 3);} // запуск парашюта АУ  
  if (start2EngineTime != 0 && millis() - start2EngineTime >= SMOKE_DELAY) {digitalWrite(Q4, 1); writeSD("AUTO/OPmode smoke ON", 1, 1, 3);} // запуск дыма АУ / РУ
}
