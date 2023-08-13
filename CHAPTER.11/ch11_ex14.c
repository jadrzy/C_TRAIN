#include <stdio.h>
#include <stdlib.h>

// FUNCTION WORKS ONLY FOR POSITIVE POWERS
int main(int argc, char** argv){
double number, result = 1;
int power;
number = strtod(argv[1], NULL);
power = atoi(argv[2]);
for (int i = 0; i != power; i++)
    result *= number;
printf("%g to the power of %d is %g\n", number, power, result);
}