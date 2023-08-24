// reducto.c -- reduces your files by two-thirds!
#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>
#define LEN 20
int main(int argc, char *argv[]){
    FILE *in, *out; // declare two FILE pointers
    int ch;
    char name[LEN]; // storage for output filename
    int count = 0;
    printf("Please enter source file: \n");
    while (scanf("%s", name) != 1)
        printf("Error, try again:\n");
    if ((in = fopen(name, "r")) == NULL){
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    strncpy(name,argv[1], LEN - 5); // copy filename
    name[LEN - 5] = '\0';
    strcat(name,".red");
    if ((out = fopen(name, "w")) == NULL){
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out); // print every 3rd char
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    return 0;
}