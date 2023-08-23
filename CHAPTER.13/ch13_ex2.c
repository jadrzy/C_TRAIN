#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 64
int main(int argc, char ** argv){
    char buffer[BUFF_SIZE];
    size_t bytes_read;
    FILE * fo, * fc; // fo is original, fc is copy
    if (argc != 3){
        printf("Usage %s <original_filename> <copy_filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fo = fopen(argv[1], "rb")) == NULL){
        perror("Error opening original file");
        exit(EXIT_FAILURE);
    }
    if ((fc = fopen(argv[2], "wb")) == NULL){
        perror("Error opening original file");
        exit(EXIT_FAILURE); 
    }
    while ((bytes_read = fread(buffer, sizeof(char), BUFF_SIZE, fo)) > 0)
        fwrite(buffer, sizeof(char), bytes_read, fc);
    fclose(fo);
    fclose(fc);
    return 0;
}