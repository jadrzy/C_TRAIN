#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *getstr(char *str, int n);
char *reverse_string(char *str);

int main(void){
    char sentence[30];
    char *ptr;
    getstr(sentence, 29);
    puts(sentence);
    puts(reverse_string(sentence));
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

char *reverse_string(char *str){
    int i, j, lenght;
    char ch;
    lenght = strlen(str);
    for (i = 0; i < lenght; i++){
        for (j = lenght - 1; j - i > 0; j--){
            ch = str[j];
            str[j] = str[j-1];
            str[j-1] = ch;
        }
    }
    return str;
}
