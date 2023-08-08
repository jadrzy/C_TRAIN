#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *getstr(char *str, int n);

int main(void){
char sentence[30];
getstr(sentence, 30);
puts(sentence);
}

char *getstr(char *str, int n){
    char *ret;
    int i;
    ret = str;
    for(i = 0; isspace(str[i-1]) == 0 && i < n ; i++){
        str[i] = getchar();
    }
    return ret;
}
