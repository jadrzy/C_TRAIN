#include <stdio.h>
int main(void){
    char ch, chb;
    int ei = 0;
    while ((ch = getchar()) != '#'){
        if ( ch == 'i' && chb == 'e')
            ei++;
        chb = ch;
    }
    printf("Number of 'ei' repetitions: %d\n", ei);
    return 0;
}