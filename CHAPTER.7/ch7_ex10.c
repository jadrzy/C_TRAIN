#include <stdio.h>
#include <unistd.h>
int tax_selection(void);

int main(void){
    int choice;
    float income, tax, threshold;
    do{
        threshold = 0.00;
        choice = tax_selection();
        switch(choice){
            case 1:
            threshold = 17850.00;
            break;
            case 2:
            threshold = 23900.00;
            break;
            case 3:
            threshold = 29750.00;
            break;
            case 4:
            threshold = 14875.00;
            break;
            case 5:
            return 0;
            default:
            printf("\nERROR! Wrong declaration.");
            break;
        }
        if (threshold != 0.00){
            printf("\nEnter your income:\n");
            scanf("%f", &income);
        } else {
            continue;
        }
        if (income <= threshold)
            tax = income * 0.15;
        else
            tax = threshold * 0.15 + (income - threshold) * 0.28;
        printf("\nGross: %0.2f\nTax: %0.2f", income - tax, tax);
    }while (1);
}

int tax_selection(void)
{
    int result;
    printf("\n\n**********************************************");
    printf("\nEnter the category of tax:");
    printf("\n1) Single\t\t2) Head of Household\n3) Married" 
    " Joint\t4) Married, Separate\n5) quit");
    printf("\n**********************************************\n\n");
    scanf("%d", &result);
    return result;
}