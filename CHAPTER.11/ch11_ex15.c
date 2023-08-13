#include <stdio.h>
#include <ctype.h> // for isdigit()
#include <stdlib.h> // for atoi()

// FUNCTION THAT CHECKS IF STRING IS PURE INTEGER NUMBER
int sipn(char* str);

int main(int argc, char** argv){
    if (sipn(argv[1]))
        printf("Number is %d\n", atoi(argv[1]));
    else
        puts("Error! Number is incorrect!\n");
    return 0;
}

int sipn(char* str){
    int i;
    for (i = 0; str[i] != '\0'; i++)
        if (isdigit(str[i]) == 0)
            return 0;
    return 1;
}