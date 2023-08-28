#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

int main(void){
    FILE *fp;
    char words[MAX];
    char searching[MAX + 3];
    int num_of_lines = -1;

    // opening file
    if ((fp = fopen("wordy", "ab+")) == NULL){
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    // checking size of a file
    fseek(fp, 0, SEEK_END);                                     // seek to end of file
    long int size = ftell(fp);                                  // get current file pointer
    fseek(fp, 0, SEEK_SET);                                     // seek back to beginning of file

    // searching for the penultimate newline character
    if (size == 0)
        num_of_lines = 0;                                       // if size of file is 0 then number of lines must be 0
    else if (size <= MAX + 4)
        fread(searching, sizeof(char), MAX + 4, fp);            //  because of string max lenght, index num, dot, newline character and in order to skin first newline
    else {
        fseek(fp, -44L, SEEK_END);
        fread(searching, sizeof(char), MAX + 4, fp);
    }
    if (num_of_lines == -1){                                    // if size of file is larger than 0
        char *last_newline = strrchr(searching, '\n'); 
        *last_newline = '\0';                                   // deleting last lewline
        if ((last_newline = strrchr(searching, '\n')) == NULL)  // searching for the penultimate newline
            num_of_lines = 1;                                   // if there is none number of lines must be equal to 1
        else{
            num_of_lines = atoi(last_newline + 1);              // if there is a penultimate newline the number of lines is located in the next adress
        }
    }

    // appending words to the file
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%s", words) == 1) && (words[0] != '#')){
        num_of_lines++;
        fprintf(fp, "%d.%s\n", num_of_lines, words);
    }

    // displaying contents of the file
    puts("File contents:");
    rewind(fp);                                                 // go back to beginning of file 
    while (fscanf(fp,"%s",words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    return 0;
}