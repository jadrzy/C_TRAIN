// power.c -- raises numbers to integer powers
#include <stdio.h>
double power(double n, int p); // ANSI prototype
int main(void){
    double x, xpow;
    int exp;
    printf("Enter a number and the integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2){
        xpow = power(x,exp);
        // function call
        if (x == 0 && exp == 0)
            printf("0 to the power of 0 is undefinded\n");
        else
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}

double power(double n, int p){
    if (p >= 0)
        if (p != 0)
            return (n * power(n, p-1));
        else
            return 1;
    else
        if (p != 0)
            return ((1/n)* power(n, p+1));
        else
            return 1;
}