/*
 * Voltage divider circuit. 
 * Calculates the voltage of the PV cell (Vpv) at resistance (R1 + R2) 
 * Calculates the power output of the PV cell based on Vpv and (R1 + R2)
 * 
 * 
 * Voltage divider connections:
 * |---- Vpv 
 * |
 * | R1 (e.g. 100 ohms)
 * |
 * |----Pin A0
 * |
 * | R2 (e.g. 100 ohms)
 * |
 * |---- GND
 */

#define Vs 3.3                // supply voltage of microcontroller 
#define PV_sense_pin A0       // the voltage divider pin (connected to Vs by probe)  
#define R1 100                // fixed resister 
#define R2 100                // fixed resister 


int sense_pv;           // voltage on voltage divider pin read as binary value (range 0 to 1023)  
float Vsense_pv;        // binary value converted to voltage
float Vpv;              // calculated voltage of PV panel
float Ppv;              // calculated power output at external load R = (R1 + R2)


// Variables used to map the binary input reading to a different scale (e.g. for output)
int max_reading = 1023;    // the maximum value 
int min_reading = 0;        // the minimum value 


