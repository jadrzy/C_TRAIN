#include <stdio.h>
#define MONTHS 12
#define YEARS 5
void avyear(const float array[][MONTHS]);
void avmonth(const float array[][MONTHS]);
int main(void){
    const float rain[YEARS][MONTHS] ={
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}};
    avyear(rain);
    avmonth(rain);
    return 0;
}
void avyear(const float array[][MONTHS]){
    int i, j;
    float subtot = 0, total = 0;
    printf(" YEAR RAINFALL (inches)\n");
    for (i = 0; i < YEARS; i++){
        for (j = 0, subtot = 0; j < MONTHS; j++)
            subtot += array[i][j];
        printf("%5d %15.1f\n", 2010 + i, subtot);
        total += subtot;  
    }
    printf("\nThe yearly average is %.1f inches.\n\n",
    total/YEARS);
}
void avmonth(const float array[][MONTHS]){
    printf("MONTHLY AVERAGES:\n\n");
    printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
    printf("Nov Dec\n");
    int i, j;
    float subtot;
    for (j = 0; j < MONTHS; j++){  
        for (i = 0, subtot = 0; i < YEARS; i++){
            subtot += array[i][j];
        }
        printf("%3.1f ", subtot/YEARS);
    }
    printf("\n");
}