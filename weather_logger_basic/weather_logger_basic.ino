#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <RTCZero.h>
//#include "UV_lightmeter_setup.h"
//#include "anemometer_setup.h"

#define cardSelect 4              // pin used for SD card
//#define LOG_INTERVAL 1000       // mills between entries
//#define ECHO_TO_SERIAL true     // echo data to serial port
#define redLED 13
#define greenLED 8
//#include "error_LED_signal.h"


char filename[15];              // create text array with desired number of characters
File logfile;                   // create logging file object

RTCZero rtc;                  // create real time clock object

//// RTC time and date setup
//// Set to true and set clock a few seconds in the future.
//// Set to false and re-upload the program (if the board remains powered, the RTC will hold the date/time)
//int set_RTC_date_time = 1;
//int D = 23, M = 1, Y = 18;
//int h = 16, m = 42, s = 0; 


void setup() {
  
  Serial.begin(115200);       // 115200 to read the GPS fast enough and echo without dropping chars
  Wire.begin();  
  rtc.begin();                // Start the RTC

//  // set the date and time
//  if (set_RTC_date_time){
//    rtc.setTime(h, m, s);  
//    rtc.setDate(D, M, Y);  
//  }    
  
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
  
//  // comment out if not using UV sensor
//  if (! uv.begin()) {
//    Serial.println("Didn't find Si1145");
//    while (1);
//  }
  
  

  
  


  
//  column_headings_to_SD();
//
//  // comment out if ot using anemometer
//  pinMode(9, INPUT);
//  attachInterrupt(digitalPinToInterrupt(9), rotations, RISING);
}


uint8_t i=0;

void loop() {


  digitalWrite(8, HIGH);
  logfile = SD.open(filename, FILE_WRITE);
  logfile.print("A0 = "); logfile.println(analogRead(0));
  logfile.close();
  Serial.print("A0 = "); Serial.println(analogRead(0));
  digitalWrite(8, LOW);
  
  delay(100);

//  readUVindex();
//
//  wind_speed();
  
  
//  // LED on to show device is on
//  digitalWrite(greenLED, HIGH);
//
//  // save data to SD card (and print to serial) 
//  save_to_SD();
//
//  // LED off to show readings have bee taken
//  digitalWrite(greenLED, LOW);
//
//  // delay between readings
//  delay(LOG_INTERVAL);

  //Serial.println(anemometer_count);
 } 


 // blink out an error code
void errorLED(uint8_t errno) {
  while(1) {
    uint8_t i;
    for (i=0; i<errno; i++) {
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
    }
    for (i=errno; i<10; i++) {
      delay(200);
    }
  }
}


//void rpm_fun()
// {
//   //Each rotation, this interrupt function is run twice, so take that into consideration for 
//   //calculating RPM
//   //Update count
//   //count++;  // use if count is byte
//   count +=1;
//      
// }
