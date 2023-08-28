#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>
#define ROW 20
#define COL 30

int main(void){
    char array_of_symbols[10] = {" .~:=!*#$@"};
    int number;
    char test[1000];
    int row, col;
    FILE * fp;
    if ((fp = fopen("picture.txt", "r")) == NULL){
        printf("Error opening file picture.txt\n");
        exit(EXIT_FAILURE);
    }
    // checking size of a file
    fseek(fp, 0, SEEK_END);                           
    long int size = ftell(fp);                                 
    fseek(fp, 0, SEEK_SET);  
    fgets(test, 1000, fp);
    while (fscanf(%d,))
    col = strlen(test);
    row = size / col;
    printf("col: %d row: %d", col, row);

    int array[ROW][COL + 1];    

    int row_count = 0;
    int col_count = 0;
    while (fscanf(fp, "%d", &number) == 1){                         // scanning numbers from file
        array[row_count][col_count] = array_of_symbols[number];     // converting numbers to symbols and saving results in the array
        col_count++;
        if (col_count == COL){
            col_count = 0;
            row_count++;
        }
    }
    fclose(fp);                                                     // creating new file 
    if ((fp = fopen("symbols.txt", "w")) == NULL){
        printf("Error opening file picture.txt\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ROW; i++){                                  // printing to the file
        for (int j = 0; j < COL; j++)
            fprintf(fp, "%c ", array[i][j]);
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}