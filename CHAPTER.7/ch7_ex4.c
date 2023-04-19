#include <stdio.h>
int main(void){
    char ch;
    int subs = 0;
    while ((ch = getchar()) != '#'){
        if (ch == '.'){
            printf("!");
            subs++;
        }else if (ch == '!'){        
            printf("..");
            subs++;
        }else
            putchar(ch);
    }
    printf("Number of substitutions: %d\n", subs);
    return 0;
}