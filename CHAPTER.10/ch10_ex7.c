#include <stdio.h>
#define ROW 3
#define COL 4
void copy(double *pointer, double *cpointer, int n);
int main(void){
    double array[ROW][COL] ={
            {22.3, 12.1, 23.8, 8.3},
            {6.11, 42, 23.111, 327},
            {644.5, 44.2, 63.3, 44}};
    double carray[ROW][COL];
    for (int i = 0; i < ROW; i++){
        copy(&array[i][0], &carray[i][0], COL);
        printf("\n");
    }
    return 0;
}
void copy(double *pointer, double *cpointer, int n){
    for (int i = 0; i < n; i++, pointer++, cpointer++){
        *cpointer = *pointer;
        printf("%0.3f ", *cpointer);
    }
}