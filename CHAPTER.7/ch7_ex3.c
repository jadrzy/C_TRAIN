#include <stdio.h>
int main(void)
{
    int number, choice, odd = 0, even = 0;
    float sumodd = 0.0, sumeven = 0.0, avodd = 0.0, aveven = 0.0;
    do
    {
        scanf("%d",&number);  
        choice = number % 2;
        switch (choice)
        {
            case 0:
                even++;
                sumeven += number;
                break;
            case 1:
                odd++;
                sumodd += number;
                break;
            default:
                break;
        }
        aveven = sumeven / (float) even;
        if (number == 0 && odd == 0)
            avodd = 0.0;
        else
            avodd = sumodd / (float) even; 
    }
    while (number != 0);
    printf("Quantity of numbers entered:\n");
    printf("%6d odd %6.2g was average odd %6d even %6.2g was average even\n",
     odd, avodd, even, aveven);
    return 0;
}