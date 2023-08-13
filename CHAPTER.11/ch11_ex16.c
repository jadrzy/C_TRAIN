#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* gets(char* str, int n);

int main(int argc, char** argv){
    if (argc > 2 ||
       (argc == 2 && strcmp(argv[1], "-p") != 0 
                  && strcmp(argv[1], "-u") != 0 
                  && strcmp(argv[1], "-l") != 0)){
        puts("Error! Wrong declaration!");
        return 0;
    } 
    char string[100];
    gets(string, 100);
    if (argc == 1 || strcmp(argv[1], "-p") == 0)
        puts(string);
    if (argc == 2 && strcmp(argv[1], "-u") == 0){
        for (int i = 0; string[i] != '\0'; i++)
            printf("%c", toupper(string[i]));
        printf("\n");
    }
    if (argc == 2 && strcmp(argv[1], "-l") == 0){
        for (int i = 0; string[i] != '\0'; i++)
            printf("%c", tolower(string[i]));
        printf("\n");
    }
    return 0;
}

char* gets(char* str, int n){
    char *retVal;
    retVal = fgets(str, n, stdin);
    str[strcspn(str, "\n")] = '\0';
    return retVal;
}