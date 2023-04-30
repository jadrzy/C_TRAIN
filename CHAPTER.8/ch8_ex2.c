#include <stdio.h>
#include <unistd.h>
void printing(char c);
int in_out(int flag);
char ch;
int count, flag = 1;
int main(void){
    /* reading input */
    while (count++, flag = in_out(flag),(ch = getchar()) != EOF){
        printing(ch);
        if (count == 10){
            printf("\n");
            count = 0;
        }
    }
    printf("\n");
    return 0;
}
/* function for printing output */
void printing(char c){
    char modch;
    flag = in_out(flag);
    if (c <= ' '){
        if (c == '\n'){
            printf("\t\\n");
            printf(" %d", c);
            count = 0;
            flag = 1;           
        } else if (c == '\t'){
            printf("\t\\t");
            printf(" %d", c);
        } else {
            modch = 64 + c;
            printf("\t^%c", modch);
            printf(" %d", c);
        }
    } else {
        printf("\t%c", c);
        printf(" %d", c);
    }
}
/* function for printing "INPUT:" and "OUTPUT:" */
int in_out(int flag){
    if (flag == 1){
        printf("\nINPUT:\n");
        flag = -1;
    }else if (flag == -1){
        printf("OUTPUT:\n");
        flag = 0;
    }else{
        sleep(0);
    }
    return flag;
}