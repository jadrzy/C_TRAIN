#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
int main(int argc, char ** argv){
    FILE *fa, *fs; // fa for append file, fs for source file
    int files = 0; // number of files appended
    char file_app[SLEN]; // name of append file
    char file_src[SLEN]; // name of source file
    int ch;
    if (argc != 3){
        printf("Usage: %s <append_filename> <source_filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strcpy(file_app, argv[1]);
    strcpy(file_src, argv[2]);

    if ((fa = fopen(file_app, "a+")) == NULL){
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0){
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (strcmp(file_src, file_app) == 0){
        fputs("Can't append file to itself\n",stderr);
        exit(EXIT_FAILURE);
    }
    else if ((fs = fopen(file_src, "r")) == NULL)
        fprintf(stderr, "Can't open %s\n", file_src);
    else{
        if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0){
            fputs("Can't create input buffer\n",stderr);
            exit(EXIT_FAILURE);
        }
        append(fs, fa);
        if (ferror(fs) != 0)
            fprintf(stderr,"Error in reading file %s.\n", file_src);
        if (ferror(fa) != 0)
            fprintf(stderr,"Error in writing file %s.\n", file_app);
        fclose(fs);
        printf("File %s appended.\n", file_src);
    }
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("\nDone displaying.");
    fclose(fa);
    return 0;
}

void append(FILE *source, FILE *dest){
    size_t bytes;
    static char temp[BUFSIZE]; // allocate once
    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}