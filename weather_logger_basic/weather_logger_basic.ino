#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <RTCZero.h>
#include "UVlightmeter_setup.h"
#include "anemometer_setup.h"
#include "vane_setup.h"
#include "PV_power_setup.h"

RTCZero rtc;                  // create real time clock object

// RTC time and date setup
// Set to true and set clock a few seconds in the future.
// Set to false and re-upload the program (if the board remains powered, the RTC will hold the date/time)
#define set_RTC_date_time false
int D = 27, M = 1, Y = 18;
int h = 15, m = 12, s = 0; 

// User defined parameters
#define LOG_INTERVAL 1000       // mills between entries
#define ECHO_TO_SERIAL true     // echo data to serial port
#define anemometer true         // measure anemometer
#define wind_vane true          // measure wind_vane
#define UVsensor false          // measure UV index
#define PV_cell true           // measure PV cell power output

#define redLED 13
#define greenLED 8
#define cardSelect 4            // pin used for SD card

char filename[15];              // create text array with desired number of characters
File logfile;                   // create logging file object
//bool first_loop = true;       // defines operations that only happen the first time the code loops

unsigned long T_old;

void setup() {
  
  Serial.begin(115200);         // 115200 to read the GPS fast enough and echo without dropping chars
  Wire.begin();  
  rtc.begin();                  // Start the RTC

  // set the date and time
  if (set_RTC_date_time){
    rtc.setTime(h, m, s);  
    rtc.setDate(D, M, Y);  
  }    
  
  // on board LED pins
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(cardSelect)) {
    Serial.println("Card init. failed!");
    errorLED(2);
  }

  strcpy(filename, "ANALOG00.TXT");     // initialise the variable filename with a string

  // loop through 100 possible filenames...
  for (uint8_t i = 0; i < 100; i++) {   
    filename[6] = '0' + i/10;
    filename[7] = '0' + i%10;
        
    // ...stop when an unused filename is reached
    if (! SD.exists(filename)){
      break;
    }    
  }

  logfile = SD.open(filename, FILE_WRITE);
  if( ! logfile ) {
    Serial.print("Couldnt create "); 
    Serial.println(filename);
    errorLED(3);
  }
  
  Serial.print("Writing to ");
  Serial.println(filename);

  column_headings_to_SD();

  T_old = millis();

  if( anemometer ){
    T_old_anemom = millis();
    attachInterrupt(digitalPinToInterrupt(anemom_pin), rotations, RISING);
  }


  if( UVsensor ){
    //uv.begin();
    if (! uv.begin()) {
      Serial.println("Didn't find Si1145 UV meter");
      
    }  
  }

  
}


uint8_t i=0;

void loop() {

  if ((millis() - T_old) > LOG_INTERVAL){ 
    
    digitalWrite(greenLED, HIGH);         // LED on to show device is on

    if( anemometer ){
      wind_speed();
    }
    
    if( wind_vane ){
      wind_direction();
    }

    if( UVsensor ){
      UV_index();
    }

    if (PV_cell ){
      PVpower();
    }
    
    save_to_SD();
    T_old = millis();  

    digitalWrite(greenLED, LOW);          // LED off to show readings have been taken
    
  }
} 


 // blink out an error code
void errorLED(uint8_t errno) {
  while(1) {
    uint8_t i;
    for (i=0; i<errno; i++) {
      digitalWrite(redLED, HIGH);
      delay(100);
      digitalWrite(redLED, LOW);
      delay(100);
    }
    for (i=errno; i<10; i++) {
      delay(200);
    }
  }
}



