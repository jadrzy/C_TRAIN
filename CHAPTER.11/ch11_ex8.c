#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
char *getstr(char *str, int n);
char *string_in(char *str1, char *str2);

int main(void){
    char sentence1[30], sentence2[30];
    char *ptr;
    getstr(sentence1, 29);
    puts(sentence1);
    getstr(sentence2, 29);
    puts(sentence2);
    puts(string_in(sentence1, sentence2));
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

char *string_in(char *str1, char *str2){
    int i = 0, j;
    bool in = false;
    char *ret;
    while (in != true && str1[i] != '\0'){
        j = 0;
        while (str1[i] != str2[j] && str1[i] != '\0'){
            i++;
        }
        ret = &str1[i];
        if (str1[i] == '\0')
            break;
        while (str1[i] == str2[j] && str1[i] != '\0'){
            i++;
            j++;
        }
        if (str2[j] == '\0'){
            in = true;
        }        
    }
    if (in == false)
        ret = NULL;
    return ret;
}
