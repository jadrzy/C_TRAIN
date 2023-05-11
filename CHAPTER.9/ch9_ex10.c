#include <stdio.h>
void to_binary(unsigned long n, int b);
int main(void){
    unsigned long number;
    int base;
    printf("Enter an integer and a base (q to quit):\n");
    while (scanf("%lu%d", &number, &base) == 2){
        if(base < 2 || base > 10)
            printf("Base must be in the range 2-10\n");
        else{
            printf("Base-%d equivalent: ", base);
            to_binary(number, base);
            putchar('\n');
        }    
        printf("Enter an integer and a base (q to quit):\n");
    }
    printf("Done.\n");
    return 0;
}
void to_binary(unsigned long n, int b){
int r;
r = n % b;
if (n >= b)
    to_binary(n / b, b);
printf("%d", r);
return;
}