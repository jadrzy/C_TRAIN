#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>  // for strchr()
#include <stdbool.h> // for boolean
#define BUFF_LEN 3
int main(int argc, char ** argv){
    if (argc != 3){
        printf("Usage %s <filename1> <filename2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE * pf1, * pf2;
    char buffer[BUFF_LEN];
    if ((pf1 = fopen(argv[1], "rb")) == NULL){ // read 1 file
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((pf2 = fopen(argv[2], "rb")) == NULL){ // read 2 file
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    bool file1_end = false,  file2_end = false;
    while(file1_end != true || file2_end != true){
        if (file1_end != true){ // for 1 file
            if (fgets(buffer, BUFF_LEN, pf1) == NULL) // EOF if nothing was encountered
                file1_end = true;
            else{ 
                fputs(buffer, stdout);
                while (strchr(buffer, '\n') == NULL){ // check if whole line was scanned
                    if (fgets(buffer, BUFF_LEN, pf1) == NULL){ // EOF if nothing was encountered
                        printf("\n"); // add newline to the last printed line
                        break; // terminate loop if EOF
                    } else {
                        fputs(buffer, stdout); // scan the rest of the line
                    }
                }
            }
        }
        if (file2_end != true){ // for 2 file
            if (fgets(buffer, BUFF_LEN, pf2) == NULL)
                file2_end = true;
            else{
                fputs(buffer, stdout);
                while (strchr(buffer, '\n') == NULL){
                    if (fgets(buffer, BUFF_LEN, pf2) == NULL){
                        printf("\n");
                        break; 
                    } else {
                        fputs(buffer, stdout);
                    }
                }
            }
        }
    }
    fclose(pf1);
    fclose(pf2);
    return 0;
}