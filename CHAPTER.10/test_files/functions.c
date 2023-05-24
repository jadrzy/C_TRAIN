#include <stdio.h>
#include "header.h"
void sumcol(int (*pointer)){
    int ic, ir, sum;
    for(ic = 0; ic < COL; ic++){ 
        for(ir = 0, sum = 0; ir < ROW; ir++){
            sum += *(pointer + ir*COL);
        }
        printf("COL %d: SUM = %d\n", ic, sum);
        pointer++;
    }
}
void sumrow(int (*pointer)){
    int ic, ir, sum;
    for(ir = 0; ir < ROW; ir++){ 
        for(ic = 0, sum = 0; ic < COL; ic++){
            sum += *(pointer + ic);
        }
        printf("ROW %d: SUM = %d\n", ir, sum);
        pointer += COL;
    }
}
void sumall(int (*pointer)){
    int ic, ir, sum;
    for(ir = 0, sum = 0; ir < ROW; ir++){ 
        for(ic = 0; ic < COL; ic++){
            sum += *(pointer + ic);
        }
        pointer += COL;
    }
    printf("SUM OF ALL = %d\n", sum);
}