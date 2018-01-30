 /*
 *  |----- GND
 *  |
 *  | 10k
 *  |
 *  |----- anemometer 2
 *  
 *  
 *  |----- anemometer 3 and Pin 9
 *  | 
 *  | 1k
 *  |
 *  |----- Vs (e.g. 3.3V)
 */

#define period_anemom 1000
#define anemom_pin 9



unsigned long T_old_anemom;
int count_anemom = 0;
float windspeed;
