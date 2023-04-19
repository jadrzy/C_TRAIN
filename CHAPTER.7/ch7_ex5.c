#include <stdio.h>
int main(void){
    char ch;
    int subs = 0;
    while ((ch = getchar()) != '#'){
        switch (ch)
        {
        case '.':
            printf("!");
            subs++;
            break;
        case '!':
            printf("..");
            subs++;
            break;
        default:
            putchar(ch);
            break;
        }
    }
    printf("Number of substitutions: %d\n", subs);
    return 0;
}