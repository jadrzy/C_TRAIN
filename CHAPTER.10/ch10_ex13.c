#include <stdio.h>
#include "ex13.h"
int main(void){
    double array1[ROW][COL]; 
    input(array1);
    printf("\t      CREATED ARRAY\n");
    display(array1);
    average(array1);
    largest(array1);
    return 0;
}