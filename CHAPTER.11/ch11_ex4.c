#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char *getstr(char *str, int n);

int main(void){
char sentence[30];
getstr(sentence, 29);
puts(sentence);
}

char *getstr(char *str, int n){
    int i = 0;
    while(isspace(str[i] = getchar()));
        i = 1;     
    while(isspace(str[i] = getchar()) == 0 && i < n){
        printf("%d\n", i);
        i++;
    }
    str[i] = '\0';
    return str;
}
