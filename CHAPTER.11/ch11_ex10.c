#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char *nospaces(char *st);

int main(void){
    char array[5][30];
    bool empty = false;
    int i, j;
    while (empty != true){
        for (i = 0; i < 5; i++){
            if(empty == true)
                break;
            fgets(array[i], 29, stdin);
            for (j = 0, empty = true; j < (int) strlen(array[i]); j++){
                if (isspace(array[i][j]) == 0){
                    empty = false;
                }
            }
        }
    }
    for(i = 0; i < 5; i++)
        nospaces(array[i]);
}

char *nospaces(char *st){
    int j, k;
    char ch;
    for (j = 0, k = 0; st[j] != '\0'; j++, k = j){
        if(isspace(st[j])){
            ch = st[j];
            while (isspace(st[k]) != 0)
                k++;
            if(st[k] == '\0'){
                st[j] = '\0';
                continue;
            }
            st[j] = st[k];
            st[k] = ch;
        }
    }
    fputs(st, stdout);
    putchar('\n');
}