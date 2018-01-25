void wind_direction(){

  // calculate the theoretical voltage output at each angle, based on the supply voltage and voltage divider circuit
  for(int i=0; i < 16; i++){
    V_vane[i] = Vs_vane * Rdirection_vane[i] / (Rfixed_vane + Rdirection_vane[i]);
//    Serial.print("voltage = "); 
//    Serial.println(V_vane[i]); 
  }
  //Serial.println("");   
  
  float reading  = analogRead(vane_pin);      // voltage on voltage divider pin read as binary value (range 0 to 1023)   
  float voltage = reading * (Vs_vane / 1023.0);     // binary value converted to voltage
  Serial.print("voltage = "); 
  Serial.println(voltage); 
  
//  for (int i=0; i < 16; i++){
//    float voltage_diff[i] = abs(V_vane[i] - voltage);
//  }

//  // find the minimum difference between the measured voltage and the voltage in the look-up table
//  // the wind direction is the angle with the same index as the voltage selected from the look up table 
//  minimum  = voltage_diff[0];
//  windDirection = vane_angle[0];  
//  for (int i=0; i < 16; i++){
//      if (minimum > voltage_diff[i]){
//          minimum  = voltage_diff[i];
//          windDirection = vane_angle[i];
//      }      
//  }

}

