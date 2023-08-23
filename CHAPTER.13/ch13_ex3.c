#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define BUFF_SIZE 64
int main(int argc, char ** argv){
    char buffer[BUFF_SIZE];
    char name_source[20];
    char name_output[20];
    size_t bytes_read;
    FILE * fo, * fc; // fo is original, fc is copy
    printf("Please enter the source file to be copied:\n");
    while (scanf("%s", name_source) == 0)
        printf("Error. Please try again:\n");
    if ((fo = fopen(name_source, "rb")) == NULL){
        perror("Error opening original file");
        exit(EXIT_FAILURE);
    }
    printf("Please enter the output file:\n");
    while (scanf("%s", name_output) == 0)
        printf("Error. Please try again:\n");
    if ((fc = fopen(name_output, "wb")) == NULL){
        perror("Error opening original file");
        exit(EXIT_FAILURE); 
    }
    while ((bytes_read = fread(buffer, sizeof(char), BUFF_SIZE, fo)) > 0){
        for (int i = 0; i < strlen(buffer); i++)
            buffer[i] = toupper(buffer[i]);
        fwrite(buffer, sizeof(char), bytes_read, fc);
    }
    fclose(fo);
    fclose(fc);
    return 0;
}