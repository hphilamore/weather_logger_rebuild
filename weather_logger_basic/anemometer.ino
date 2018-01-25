void rotations(){
  count_anemom += 1; 
}


void wind_speed(){
  if ((millis() - T_old_anemom) > period_anemom){ 
    calculate_wind_speed();
    Serial.println("calculating wind speed");
    }
}


void calculate_wind_speed(){
  detachInterrupt(anemom_pin);
  
  unsigned long T = millis();
  
//  Serial.print("count_anemom = ");
//  Serial.println(count_anemom);
//  Serial.print("period = ");
//  Serial.println(T - T_old_anemom);

  // number of counts (4 counts per rotation)
  float frequency = 1000 * count_anemom / (T - T_old_anemom);

  // convert to rps and windspeed(m/s) 
  Serial.print("freq = ");
  Serial.println(frequency);

  windspeed = frequency * 0.66;
  Serial.print("windspeed = ");
  Serial.println(windspeed); 
  
  T_old_anemom = millis();
  count_anemom = 0; 
  attachInterrupt(digitalPinToInterrupt(anemom_pin), rotations, RISING);
}
