#include <stdio.h>
// function prototype
double min(double x, double y);
int main(void){
    double val1, val2;
    // variable declaration
    val1 = 21.0;
    val2 = 2.22222;
    // function call
    printf("%g\n", min(val1, val2));
    return 0;
}
// function min 
double min(double x, double y){
    double result;
    (x > y) ? (result = y) : (result = x);
    return result;
}