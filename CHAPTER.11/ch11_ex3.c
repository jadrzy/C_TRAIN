#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char *getstr(char *str);

int main(void){
char sentence[30];
getstr(sentence);
puts(sentence);
}

char *getstr(char *str){
    int i = 0;
    while(isspace(str[i] = getchar()));
        i = 1;     
    while(isspace(str[i] = getchar()) == 0)
        i++;
    str[i] = '\0';
    return str;
}
