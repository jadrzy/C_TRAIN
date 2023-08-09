#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *getstr(char *str, int n);
char *strchr2(char *str, char ch);

int main(void){
char sentence[30];
char *ptr;
getstr(sentence, 29);
puts(sentence);
printf("%d\n", (int) (strchr2(sentence, 'g') -  sentence));
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

char *strchr2(char *str, char ch){
    int i;
    char *ret = NULL;
    for(i = 0; ret == NULL && str[i] != '\0'; i++){
        if(str[i] == ch)
            ret = &str[i];
    }   
    return ret;
}