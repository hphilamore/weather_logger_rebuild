void column_headings_to_SD(){
 /*  
  *  Parameters not being loggedshould be commented out
  */
  
  // open the file to write data
  logfile = SD.open(filename, FILE_WRITE);
  
  // if there is no SD card, print error message
  if( ! logfile ) {
    Serial.print("Couldnt create/open file: ");
    Serial.println(filename);
    errorLED(3);
  }
  
  logfile.print("Date"); logfile.print("\t"); logfile.print("Time"); logfile.print("\t");
  if (ECHO_TO_SERIAL){
    Serial.print("Date"); Serial.print("\t"); Serial.print("Time"); Serial.print("\t");
  }

  // UV index
  if( UVsensor ){
    logfile.print("UV_index"); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){  
      Serial.print("UV_index");
      Serial.print("\t");
    }
  }


 
  // windspeed
  if( anemometer ){
    logfile.print("windspeed(m/s)"); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){  
      Serial.print("windspeed(m/s)");
      Serial.print("\t");
    }
  }


  if( wind_vane ){
    logfile.print("windAngle(deg)"); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){  
      Serial.print("windAngle(deg)");
      Serial.print("\t");
    }
  }


  if( PV_cell ){
    logfile.print("PV_power(W)"); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){  
      Serial.print("PV_power(W)");
      Serial.print("\t");
    }
  }
  

  logfile.println("");
  if (ECHO_TO_SERIAL){  
    Serial.println("");
  }

  // close the file ensuring that written data is physically saved to the SD card
  logfile.close();
}



void save_to_SD(){
  /* 
   *  Saves data to SD card (and optionally prints to serial)
   *  Parameters not being loggedshould be commented out
   */
  // open the file to write data
  logfile = SD.open(filename, FILE_WRITE);
  
  // if there is no SD card, print error message
  if( ! logfile ) {
    Serial.print("Couldnt create/open file: ");
    Serial.println(filename);
  }

   
  // write timestamp to file on SD card (and serial monitor)
  logfile.print(rtc.getDay()); logfile.print("/"); logfile.print(rtc.getMonth()); logfile.print("/"); logfile.print(rtc.getYear());
  logfile.print("\t");    
  logfile.print(rtc.getHours()); logfile.print(":"); logfile.print(rtc.getMinutes()); logfile.print(":"); logfile.print(rtc.getSeconds());
  logfile.print("\t");


  if (ECHO_TO_SERIAL){
    Serial.print(rtc.getDay()); Serial.print("/"); Serial.print(rtc.getMonth()); Serial.print("/"); Serial.print(rtc.getYear());
    Serial.print("\t");
    Serial.print(rtc.getHours()); Serial.print(":"); Serial.print(rtc.getMinutes()); Serial.print(":"); Serial.print(rtc.getSeconds());
    Serial.print("\t");
  }


  // write uv index to file on SD card (and serial monitor)
  if( UVsensor ){
    logfile.print(UVindex); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){
      Serial.print(UVindex);
      Serial.print("\t");
    }
  }

  // write windspeed to file on SD card (and serial monitor)
  if( anemometer ){
    logfile.print(windspeed); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){
      Serial.print(windspeed);
      Serial.print("\t");
    }
  }


  if( wind_vane ){
    logfile.print(windDirection); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){  
      Serial.print(windDirection);
      Serial.print("\t");
    }
  }


  if( PV_cell ){
    logfile.print(Ppv, 5); 
    logfile.print("\t");
    if (ECHO_TO_SERIAL){  
      Serial.print(Ppv, 5);
      Serial.print("\t");
    }
  }
  

  logfile.println("");
  if (ECHO_TO_SERIAL){  
    Serial.println("");
  }

  // close the file ensuring that written data is physically saved to the SD card
  logfile.close();

 }
