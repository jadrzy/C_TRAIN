/* SCRIPT SUGGESTS NUMBER OF HOURS */
/* WORKED BASED ON DESIRED INCOME */
#include <stdio.h>
#include <math.h>
#define BASIC 10.00
#define OVERTIME 15.00
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25
#define THRESH1 300.00
#define THRESH2 150.00
int main(void){
    float hours, pay, tax, grossdesired, grossph, match, hoursfinal;
    /* $8,50 is MIN income and $10,58 is MAX */
    /* FOR VALUE OF VARIABLES ABOVE */
    printf("Type desired pay rate ($8,50 - $10,58):\n");
    while (scanf("%f",&grossdesired) == 1){
        for (hours = 0.50, match = 10.00; hours <= 168; hours += 0.50)
        {
            /* NET */
            if (hours < 40.00)
                pay = hours * BASIC;
            else
                pay = 40.00 * BASIC + (hours - 40.00) * OVERTIME;
            /* TAX */
            if (pay < THRESH1)
                tax = pay * TAX1;
            else if (pay < THRESH1 + THRESH2)
                tax = THRESH1 * TAX1 + (pay - THRESH1) * TAX2;
            else
                tax = THRESH1 * TAX1 + THRESH2 * TAX2 + 
                (pay - THRESH1 - THRESH2) * TAX3; 
            /* GROSS */
            grossph = (pay - tax) / hours;
            if (fabs(grossph - grossdesired) < match){\
                match = fabs(grossph - grossdesired); 
                hoursfinal = hours;
            }
        }
        if (match > 0.1)
            printf("\nWrong value. Enter value from scope.");
        else
            printf("\nSuggested hours worked in a week: %0.1f", hoursfinal);
        printf("\nq to quit.");
        printf("\nType desired pay rate ($8,50 - $10,58):\n");

    }
    printf("\nBYE!\n");
    return 0;
}