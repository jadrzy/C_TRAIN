#include <stdio.h>
#include <stdlib.h> // for exit()
#include <stdbool.h> // for boolean 
#define ROW 20
#define COL 30
int deglitching(int arr[][COL + 1]);
int main(void){
    int array[ROW][COL + 1];                                    // array to store converted image
    char array_of_symbols[10] = {" .~:=!*#$@"};
    int number;
    FILE * fp;
    if ((fp = fopen("picture.txt", "r")) == NULL){
        printf("Error opening file picture.txt\n");
        exit(EXIT_FAILURE);
    }
    int row_count = 0;
    int col_count = 0;
    while (fscanf(fp, "%d", &number) == 1){                     // scanning numbers from file
        array[row_count][col_count] = number;                   // converting numbers to symbols and saving results in the array
        col_count++;
        if (col_count == COL){
            col_count = 0;
            row_count++;
        }
    }
    fclose(fp);                                                 // creating new file 
    if ((fp = fopen("symbols.txt", "w")) == NULL){
        printf("Error opening file picture.txt\n");
        exit(EXIT_FAILURE);
    }
    if (deglitching(array) == 1){
        printf("Error using function deglitching\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ROW; i++){                              // printing to the file
        for (int j = 0; j < COL; j++)
            fprintf(fp, "%c ", array_of_symbols[array[i][j]]);
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}

int deglitching(int arr[][COL + 1]){
    int deglitched_array[ROW][COL] = {0};                       // dummy array
    // deglitching the array
    for (int i = 0; i < ROW; i++){                  
        for (int j = 0; j < COL; j++){
            int division = 1;
            int sum = arr[i][j];
            bool flag = false;
            if (j - 1 > 0){                                     // checking if value is outside border
                if (abs(arr[i][j - 1] - arr[i][j]) > 1){        // checking if difference between cells is bigger than 1
                    flag = true;                                // communicate status using flag
                }
            }
            if (j + 1 < COL){
                if (abs(arr[i][j + 1] - arr[i][j]) > 1){
                    flag = true;
                }
            }
            if (i - 1 > 0){
                if (abs(arr[i - 1][j] - arr[i][j]) > 1){
                    flag = true;
                }
            }
            if (j + 1 < ROW){
                if (abs(arr[i + 1][j] - arr[i][j]) > 1){
                    flag = true;
                }
            }
            // when flag is true calculating new value initializes
            if (flag == true){
                if (j - 1 > 0){
                    sum += arr[i][j - 1];
                    ++division;
                }
                if (j + 1 < COL){
                    sum += arr[i][j + 1];
                    ++division;
                }
                if (i - 1 > 0){
                    sum += arr[i - 1][j];
                    ++division;
                }
                if (i + 1 < ROW){
                    sum += arr[i + 1][j];
                    ++division;
                }
            }
            deglitched_array[i][j] = sum / division;                // calculating final result
        }
    }
    // finished deglitching
    for (int i = 0; i < ROW; i++){
        for (int j = 0 ; j < COL; j++)
            arr[i][j] = deglitched_array[i][j];
    }
}