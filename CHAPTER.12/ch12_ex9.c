#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv){
    int words;
    int status; 
    char tempArr[30];
    printf("How many words you wish to enter? ");
    while (status = scanf("%d", &words) != 1){
        if (status == EOF)
            break;
        else{
            puts("You have to type integer. Try again.");
            while(getchar() != '\n')
                continue;
            printf("How many words you wish to enter? ");
        }
    }
    char** ptr = (char**) malloc(words * sizeof(char*));
    for (int i = 0; i < words; i++){
        scanf("%s", tempArr);
        *(ptr + i) = (char*) malloc(strlen(tempArr) * sizeof(char));
        strcpy(*(ptr + i), tempArr);

    }
    for (int i = 0; i < words; i++){
        puts(*(ptr + i));
        free(*(ptr + i));
    }
    free(ptr);
    return 0;
}