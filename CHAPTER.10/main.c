#include <stdio.h>
#define ROW 3
#define COL 4
void sumraw(int (*pointer)[COL], int rows);
void sumcol(int (*pointer)[COL], int rows);
void sumall();

int main(void){
    int array[ROW][COL]={
        {1, 2, 3, 4}, 
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    sumcol(array, ROW);
    return 0;
}

void sumcol(int (*pointer)[COL], int rows){
    int sum, ir, ic;
    for (ic = 0; ic < COL; ic++){  
        for(ir = 0, sum = 0; ir < rows; ir++){
            sum += *pointer[ir];
        }
        printf("col %d: sum = %d\n",ic, sum);
        printf("",ic, sum);
        pointer += 0x001;
    }
}