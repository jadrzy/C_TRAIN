#include <stdio.h>
#include<unistd.h>
void function(double *first, double *second, double *third);
int main(void){
    double number1 = -1;
    double number2 = -2;
    double number3 = -3333;
    function(&number1, &number2, &number3);
    printf("Number1: %g   Number2: %g   , Number3: %g   \n",
    number1, number2, number3);
    return 0;
}
void function(double *first, double *second, double *third){
    double placeholder; 
    if (*first > *second){
        placeholder = *first;
        *first = *second;
        *second = placeholder;
    }
    if (*second > *third){
        placeholder = *second;
        *second = *third;
        *third = placeholder;
    }
    if (*first > *second){
        placeholder = *first;
        *first = *second;
        *second = placeholder;
    }    
}