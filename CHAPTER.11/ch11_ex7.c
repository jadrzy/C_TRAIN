#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *getstr(char *str, int n);
char *mystrncpy(char *st1, char *st2, int n);

int main(void){
    char sentence1[30], sentence2[30];
    char *ptr;
    getstr(sentence1, 29);
    puts(sentence1);
    getstr(sentence2, 29);
    puts(sentence2);
    puts(mystrncpy(sentence1, sentence2, 10));
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

char *mystrncpy(char *st1, char *st2, int n){
    int i, j;
    i = 0;
    while (st1[i] != '\0')
        i++;
    printf("%d\n", i);
    for (j = 0; j < n; j++, i++){
        st1[i] = st2[j]; 
    }
    return &st1[0];
}
