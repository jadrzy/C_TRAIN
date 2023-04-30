#include <stdio.h>
char ch;
int count = 0;
int main(void){
    while ((ch = getchar()) != EOF){
        count++;
    }
    printf("%d\n", count);
    return 0;
}