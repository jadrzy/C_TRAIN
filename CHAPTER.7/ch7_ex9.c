#include <stdio.h>
#include <stdbool.h>
int main(void){
    int number, i, j;
    bool istatus;
    printf("Enter positive integer:\n");
    while (scanf("%d", &number) == 1){
        if (number < 0){
            printf("ERROR! Integer has to be positive!\n");
            continue;
        }else{
            printf("Prime numbers smaller than input:\n");
            for (i = 2; i < number; i++)
            {
                for (j = 2, istatus = true; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        istatus = false;
                    }
                }
                if (istatus == true){
                    printf("%d ", i);
                }
            }
            printf("\n\nq to quit");
            printf("\nEnter positive integer:");
        }
    }
    printf("\n***************");
    printf("\nBYE!");
    printf("\n***************\n");
    return 0;
}