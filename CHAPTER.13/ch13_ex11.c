#include <stdio.h>
#include <string.h> // for strstr()
#include <stdlib.h> // for exit()
#define MAX 255

int main(int argc, char ** argv){
    char string[255];
    FILE * fp;
    if (argc != 3){
        printf("Usage %s <string> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL){
        printf("Error opening file %s", argv[2]);
    }
    while (fgets(string, MAX, fp) != NULL){
        if (strstr(string, argv[1]) != NULL)
            fputs(string, stdout);
    }
    printf("\n");
    return 0;
}