#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv){
    char name_of_file[30];
    long int position = 1L;
    char buff[100];
    FILE * pf;
    printf("Please enter name of the file: ");                     // getting file name
    while (scanf("%s", name_of_file) == 0)                          
        perror("Error. Please enter name of the file again: ");
    if ((pf = fopen(name_of_file, "r")) == NULL){                   // opening file
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }
    // checking size of a file
    fseek(pf, 0, SEEK_END);                                     // seek to end of file
    long int size = ftell(pf);                                  // get current file pointer
    fseek(pf, 0, SEEK_SET);                                     // seek back to beginning of file

    // MAIN LOOP
    while (1){
        printf("Enter position in file (-1 to exit): ");
        while (scanf("%ld", &position) == 0){                   // get position from the user
            printf("Error. Please enter position again (-1 to exit): ");
            while (getchar() != '\n');
        }
        if (position < 0L)                                      // if position is < 0 exit loop
            break;
        else if (position > size){                              // if position is larger than a file repeat
            printf("Error. Wrong position\n");
            continue;
        }
        else{                                                   // if position is correct print until newline is encountered
            if (fseek(pf, position, SEEK_SET) != 0){
                perror("Error. wrong position\n");
                continue;
            }
            printf("\n");
            fputs(fgets(buff ,100, pf), stdout);
            printf("\n");
        }
    }
    fclose(pf);
    return 0;
}