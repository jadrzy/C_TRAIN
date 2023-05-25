#include <stdio.h>
#include "ex14.h"
int main(void){
    double array1[ROW][COL]; 
    input(ROW, COL, array1);
    printf("\t      CREATED ARRAY\n");
    display(ROW, COL, array1);
    average(ROW, COL, array1);
    largest(ROW, COL, array1);
    return 0;
}