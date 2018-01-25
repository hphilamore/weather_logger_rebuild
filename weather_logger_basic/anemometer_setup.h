/*
 *  |----- Vs (e.g. 3.3V) 
 *  |
 *  | 1k
 *  |
 *  |----- anemometer 2 and Pin 9
 *  
 *  
 *  |----- anemometer 1
 *  | 
 *  | 10k
 *  |
 *  |----- GND
 */

#define period_anemom 1000
#define anemom_pin 9



unsigned long T_old_anemom;
int count_anemom = 0;
float windspeed;
