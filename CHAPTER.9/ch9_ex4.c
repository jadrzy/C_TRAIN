# include <stdio.h>
double harmonic(double a, double b);
int main(void){
    double number1 = 13.553;
    double number2 = -75.201;
    printf("%g\n",harmonic(number1, number2));
    return 0;
}
double harmonic(double a, double b){
    double result;
    result = 1/(((1 / a) + (1 / b)) / 2); 
    return result;
}