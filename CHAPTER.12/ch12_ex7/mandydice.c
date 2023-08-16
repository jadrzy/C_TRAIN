#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()
#include "diceroll.h"

int main(void){
    int dice, sides, roll, sets;
    int status;
    srand((unsigned int) time(0)); // reset seed
    printf("How many sets? Enter q to stop.\n");
    while (scanf("%d", &sets) == 1){
        printf("How many sides and how many dice? ");
        while ((status = scanf("%d %d", &sides, &dice)) != 2 || sides < 0 || dice < 1){
            if (status == EOF)
                break;
            else{
                printf("You should have entered two integers.\n");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;
                printf("How many sides and how many dice?\n");
                continue;
            }
        }
            printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
            for (int i = 0; i < sets; i++){
                roll = roll_n_dice(dice, sides);
                printf("%d ", roll);
            }
            printf("\nHow many sets? Enter q to stop.\n");
    }
    printf("The rollem() function was called %d times.\n",
    roll_count);
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}