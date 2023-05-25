#include <stdio.h>
#define ROW 3
#define COL 5
void copyf(int N, int M, double arraya[N][M], double arrayb[N][M]);
void display(int N, int M, double arraya[N][M], double arrayb[N][M]);
int main(void){
    double array1[ROW][COL] ={
            {22.3, 12.1, 23.8, 8.3, 52.1},
            {6.11, 42, 23.111, 327, 662},
            {644.5, 44.2, 63.3, 44, 231.1}};
    double array2[ROW][COL];
    copyf(ROW, COL, array1, array2);
    display(ROW, COL, array1, array2);
    return 0;
}
void copyf(int N, int M, double arraya[N][M], double arrayb[N][M]){
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            arrayb[i][j] = arraya[i][j];
    }
}
void display(int N, int M, double arraya[N][M], double arrayb[N][M]){
    printf("ARRAY 1: \n");
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            printf("%0.3f\t", arraya[i][j]);
        printf("\n");
    }
        printf("ARRAY 2: \n");
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            printf("%0.3f\t", arrayb[i][j]);
        printf("\n");
    }
}