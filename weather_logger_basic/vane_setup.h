/*
 *  |----- GND
 *  |
 *  | 
 *  |
 *  |----- vane 1 
 *  
 *  
 *  |----- vane 4 and Pin A1
 *  | 
 *  | Rvane = 10K
 *  |
 *  |----- Vvane (e.g. 3.3V) 
 */

#define vane_pin A1     // the pin to read the sensor voltage on
#define Vs_vane 3.3       // the supply voltage of the wind vane
#define Rfixed_vane 10000     // the fixed resister in the voltage divider circuit 

// 0 points north
float vane_angle[16]      = {0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 
                             180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5};

// internal resistance of sensor at each vane angle
float Rdirection_vane[16] = {33000, 6570, 8200, 891, 1000, 688, 2200, 1410, 
                             3900, 3140, 16000, 14120, 120000, 42120, 64900, 21880};
                              
//float V_vane[16]  = {2.53, 1.30, 1.48, 0.26, 0.3, 0.21, 0.59, 0.40, 
//                             0.92, 0.78, 2.03, 1.93, 3.04, 2.66, 2.85, 2.264}




float V_vane[16];
float V_vane_diff[16];   
float windDirection;
float minimum;

 
