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
  logfile.print("UV_index"); 
  logfile.print("\t");
  if (ECHO_TO_SERIAL){  
    Serial.print("UV_index");
    Serial.print("\t");
  }
 
  // windspeed
  logfile.print("windspeed"); 
  logfile.print("\t");
  if (ECHO_TO_SERIAL){  
    Serial.print("windspeed");
    Serial.print("\t");
  }



  logfile.print("\n");
  if (ECHO_TO_SERIAL){  
    Serial.print("\n");
  }

  // close the file ensuring that written data is physically saved to the SD card
  logfile.close();
}

