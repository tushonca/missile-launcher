ISR(TIMER1_COMPA_vect) {PINE |= (1 << PINE5);}
void buzzerTone(uint16_t FREQIN) {OCR1A = FREQIN; TIMSK1 |= (1 << OCIE1A);}
void buzzerNoTone() {TIMSK1 &= 0b11111101; PORTE  &= 0b11011111; DDRE   &= 0b11011111;}
