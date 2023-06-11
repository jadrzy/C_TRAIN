#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

int main (void){
    char choice;
    int count = 0;//counting total number of strings
    char strings[LIMIT][LENGHT] = {0};//main array with strings
    intro();//runs only on startup

    //loop
    while(1){    
        choice = menu(&count);
        switch (choice){
            case 'a':
                addstring(strings, &count);           
                break;
            case 'b':
                //sort();
                break;
            case 'c':
                display(strings);
                break;
            case 'd':
                //deletestring();
                break;
            case 'e':
                printf("Goodbye!\n");
                return 0;
            case 'i':
                information();
                break;
            default:
                break;
        }
    }
    return 0;
}