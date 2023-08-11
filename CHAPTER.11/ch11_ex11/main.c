#include <stdio.h>
#include "header.h"

int main(void){
    char array[ROW][COL];
    gets(array);

char response;    
    while (1){
        response = menu();
        switch (response){
            case 'a':
                displayA(array);
                break;
            case 'b':
                displayB(array);
                break;
            case 'c':
                displayC(array);
                break;
            case 'd':
                displayD(array);
                break;
            case 'e':
                puts("GOODBYE!");
                return 0;
            default:
                break;
        }
    }
}