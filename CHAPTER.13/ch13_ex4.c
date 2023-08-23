#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv){
    char string[20];
    if (argc < 3){
        printf("Usage: %s <filename1> <filename2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("Choose file to display its contents:\n");
    for (int i = 1 ; i < argc; i++)
        printf("-%s\n", argv[i]);
    
    while (scanf("%s", string) == 1){
        // example fopen(...)
        printf("Choose another file to display its contents:\n");
        for (int i = 1 ; i < argc; i++)
            printf("-%s\n", argv[i]);     
    }
    return 0;
}