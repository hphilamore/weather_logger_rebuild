void rotations(){
  count_anemom += 1; 
}


void wind_speed(){
  if ((millis() - T_old_anemom) > period_anemom){ 
    calculate_wind_speed();
    }
}


void calculate_wind_speed(){
  detachInterrupt(anemom_pin);
  
  unsigned long T = millis();
  
  float frequency = 1000 * count_anemom / (T - T_old_anemom);   // 4 counts per rotation

  windspeed = frequency * 0.66;
  
  T_old_anemom = millis();
  count_anemom = 0;
  
  attachInterrupt(digitalPinToInterrupt(anemom_pin), rotations, RISING);
}
