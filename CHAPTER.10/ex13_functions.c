#include <stdio.h>
#include "ex13.h"
#include <stdbool.h>
void input(double array[][COL]){
    bool read_row;
    int i, j;
    printf("Enter 3 sets of 5 double numbers.\n");
    for (i = 0; i < ROW; i++){
        printf("Please enter %d set:\n", i + 1);
        read_row = false;
        while (read_row == false){
            int val_read = 0;
            for (j = 0; j < COL; j++){
                if (scanf("%lf", &array[i][j]) == 1)
                    val_read++;
            }
            while(getchar() != '\n');
            if (val_read == 5)
                read_row = true;
            else
                printf("ERROR! Please enter correct values:\n");
        }
    }
}
void display(double array[][COL]){
    printf("%s\n", asterisks);
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++)
            printf("%5g\t", array[i][j]);
        printf("\n");
    }
    printf("%s\n", asterisks);
}
void average(double array[][COL]){
    double sum_row, sum_all;
    int i, j;
    for (i = 0, sum_row = 0; i < ROW; i++){
        for (j = 0, sum_row = 0; j < COL; j++){
            sum_row += array[i][j];
        }
        sum_all += sum_row;
        printf("SET %d: AVERAGE = %g\n", i + 1, sum_row / COL); 
    }
    printf("THE AVERAGE OF ALL NUMBERS = %g\n", sum_all / (COL * ROW)); 
}
void largest(double array[][COL]){
    double lnumber = array[0][0];
    int i, j;
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
            if (lnumber < array[i][j])
                lnumber = array[i][j];
        }
    }
    printf("THE LARGEST VALUE OF ALL IS = %g\n", lnumber);
}