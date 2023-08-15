// This code has three file-scope, internal-linkage variables
#include <stdio.h>
static int mode; // this mode variable overwrites main.c mode
static float distance, fuelConsumed;
void set_mode(int m){
    if (m > 1){
        m = mode; // if m is invalid, Mode is set to previous value
        printf("Invalid mode specified. Mode %d(US) used.\n", mode);
    }
    mode = m;
}
void get_info(void){
    if (mode == 0){ // metric mode
        printf("Enter distance travelled in kilometers: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuelConsumed);
    }else{ // US mode
        printf("Enter distance travelled in miles: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuelConsumed);
    }
}
void show_info(void){
    if (mode == 0)
        printf("Fuel consumption is %.1f liters per 100 km.\n", 100 * fuelConsumed / distance );
    else
        printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuelConsumed);
}
