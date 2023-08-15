// This code has three file-scope, internal-linkage variables
#include <stdio.h>
int set_mode(int m, int preMode){
    if (m > 1){
        m = preMode; // if m is invalid, Mode is set to previous value
        printf("Invalid mode specified. Mode %d used.\n", preMode);
    }
    return m;
}
float get_info(int mod){
    float distance, fuelConsumed, result;
    if (mod == 0){ // metric mode
        printf("Enter distance travelled in kilometers: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuelConsumed);
        result = 100 * fuelConsumed / distance; // formula for liter per 100 km 
    }else{ // US mode
        printf("Enter distance travelled in miles: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuelConsumed);
        result = distance / fuelConsumed; // formula for miles per gallon
    }
    return result;
}
void show_info(int mode, float result){
    if (mode == 0)
        printf("Fuel consumption is %.2f liters per 100 km.\n", result);
    else
        printf("Fuel consumption is %.1f miles per gallon.\n", result);
}
