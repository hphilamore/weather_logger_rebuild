void PVpower(){
  sense_pv  = analogRead(PV_sense_pin);                // voltage on voltage divider pin read as binary value (range 0 to 1023) 
    
  Vsense_pv = sense_pv * (Vs / 1023.0);           // binary value converted to voltage
  
  Vpv = Vsense_pv * (R1 + R2) / R1;                  // voltage output from PV panel calculated 
  Serial.print("PV voltage = ");
  Serial.println(Vpv); 

  Ppv = sq(Vpv) / (R1 + R2);
  Serial.print("PV power = ");
  Serial.println(Ppv); 

  Serial.print("");

}



