
void loop(){
  color.r = 10; color.g = 0; color.b = 0; LED.set_crgb_at(1, color);  LED.sync();
  sBus.FeedLine();
  cnDataUpdate();
  color.r = 0; color.g = 10; color.b = 0; LED.set_crgb_at(1, color);  LED.sync();
  remoteControl();
  float Altit = pressureToAltitude(bme.readPressure()) - startAltit;
  writeSD("H = ", 0, 0, 1);
  writeSD(String(Altit), 0, 0, 2);
  
}
