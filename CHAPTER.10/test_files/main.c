/* MODIFIED  Listing 10.17 */
/* COMPILE WITH functions.c */
/* FUNCTION PROTOTYPES ARE INSIDE header.h FILE */
/* FUNCTION DESCRIPTIONS ARE INSDE functions.c FILE */
#include <stdio.h>
#include "header.h"
int main(void){
    int array[ROW][COL]={
        {1, 2, 3, 4}, 
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    sumcol(&array[0][0]);
    sumrow(&array[0][0]);
    sumall(&array[0][0]);
    return 0;
}
/* Script uses standard single int pointer 
instead of pointer to array of four ints */