#include <stdio.h>
#define BASIC 10.00
#define OVERTIME 15.00
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25
#define THRESH1 300.00
#define THRESH2 150.00
int main(void){
    float hours, pay, tax, gross;
    printf("Type number of hours worked:\n");
    while (scanf("%f",&hours) == 1){
        /* NET VALUE */
        if (hours < 40.00)
        pay = hours * BASIC;
        else
        pay = 40.00 * BASIC + (hours - 40.00) * OVERTIME;
        /* TAX */
        if (pay < THRESH1){
        tax = pay * TAX1;
        }else if (pay < THRESH1 + THRESH2){
        tax = THRESH1 * TAX1 + (pay - THRESH1) * TAX2;
        }else{
        tax = THRESH1 * TAX1 + THRESH2 * TAX2 + 
        (pay - THRESH1 - THRESH2) * TAX3; 
        }
        /* GROSS */
        printf("\nYour tax is: %0.2f", tax);
        gross = (pay - tax);
        printf("\nGross payment: %0.2f", gross);
        printf("\nType q to quit.\n");
        printf("Type number of hours worked:");
    }
    printf("\nBYE!");
    return 0;
}