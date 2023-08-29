#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h> // for strlen()
#include <ctype.h> // for isnum()

int main(void){
    char array_of_symbols[10] = {" .~:=!*#$@"};
    FILE * fp;
    if ((fp = fopen("picture.txt", "r")) == NULL){
        printf("Error opening file picture.txt\n");
        exit(EXIT_FAILURE);
    }
    // calculating dimensions of array
    int size = 0,
        row = 0,
        col = 0,
        number;
    char test[1000];
    while (fscanf(fp, "%d", &number) == 1)
        size++;
    rewind(fp);
    fgets(test, 1000, fp);
    for (int i = 0; i < strlen(test); i++)
        if (isdigit(test[i]) != 0)
            col++;
    row = size / col;
    // implementing VLA
    int array[row][col + 1];

    int row_count = 0;
    int col_count = 0;
    while (fscanf(fp, "%d", &number) == 1){                         // scanning numbers from file
        array[row_count][col_count] = array_of_symbols[number];     // converting numbers to symbols and saving results in the array
        col_count++;
        if (col_count == col){
            col_count = 0;
            row_count++;
        }
    }
    fclose(fp);                                                     // creating new file 
    if ((fp = fopen("symbols.txt", "w")) == NULL){
        printf("Error opening file picture.txt\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row; i++){                                  // printing to the file
        for (int j = 0; j < col; j++)
            fprintf(fp, "%c ", array[i][j]);
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}