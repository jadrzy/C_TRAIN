#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *getstr(char *str, int n);
int is_within(char *str, char ch); 

int main(void){
    char sentence[30];
    char *ptr;
    getstr(sentence, 29);
    puts(sentence);
    printf("%d\n", is_within(sentence, 'g'));
}


char *getstr(char *str, int n){
    int i = 0;
    while(isspace(str[i] = getchar()));
        i = 1;     
    while(isspace(str[i] = getchar()) == 0 && i < n)
        i++;
    str[i] = '\0';
    return str;
}

int is_within(char *str, char ch){
    int i, ret;
    ret = 0;
    for (i = 0; str[i] != '\0'; i++){
        if(str[i] == ch)
            ret = 1;
    }
    return ret;
}