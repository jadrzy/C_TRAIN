#include <stdio.h>
#include <stdbool.h> // for boolean type
#include <string.h> // for strlen()
#include "header.h"

int main(void){
    char array[ROW][COL];
    char ch;
    int i, j;
    gets(array);
    displayA(array);
}

char *gets(char st[][COL]){
    char *ret_val;
    int i, j;
    FILE * file = fopen("string_list.txt", "r");
    if (file)
        puts("Data was uploaded");
    else {
        puts("Error");
        return NULL;
    }
    for (j = 0; j < ROW; j++){   
        fgets(st[j], COL, file);        
        st[j][strcspn(st[j], "\n")] = '\0';
    }
    return ret_val;
}
void displayA(char st[][COL]){
    puts("STRINGS:");
    for (int i = 0; i < ROW; i++)
        puts(st[i]);
}