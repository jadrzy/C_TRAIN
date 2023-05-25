#include <stdio.h>
#define ROW 3
#define COL 5
#define asterisks "************************************"
void display(int array[][COL]);
void dbl(int array[][COL]);
int main(void){
    int array1[ROW][COL] ={
            {22, 12, 23, 8, 52},
            {6, 42, 23, 327, 662},
            {644, 44, 63, 44, 231}};
    display(array1);
    dbl(array1);
    display(array1);
    return 0;
}
void display(int array[][COL]){
    printf("%s\n", asterisks);
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++)
            printf("%d\t", array[i][j]);
        printf("\n");
    }
    printf("%s\n", asterisks);
}
void dbl(int array[][COL]){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++)
            array[i][j] *= 2;
    }    
}
