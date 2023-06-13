#include <stdio.h>
#include "header.h"

int main (void){
    char strings[LIMIT][LENGHT] = {0};//CREATE AND DEFINE MAIN ARRAY
    int count = 0;//COUNTING NUMBER OF STRINGS PRESENT IN THE MAIN ARRAY
    char choice;
    intro();//runs only on startup

    //MAIN LOOP
    while(1){    
        choice = menu(&count);
        switch (choice){
            case 'a':
                printf("\n***OPERATION: ADD NEW STRING***\n\n");
                addstring(strings, &count);           
                break;
            case 'b':
                printf("\n***OPERATION: SORT STRINGS***\n\n");
                sort(strings);
                break;
            case 'c':
                printf("\n***OPERATION: DISPLAY STRINGS***\n\n");
                display(strings);
                break;
            case 'd':
                printf("\n***OPERATION: DELETE STRING***\n\n");
                deletestring(strings, &count, "one");
                break;
            case 'e':
                printf("\n***OPERATION: CLEAR ARRAY***\n\n");
                deletestring(strings, &count, "all");
                break;
            case 'i':
                printf("\n***OPERATION: INFORMATION***\n\n");
                information();
                break;
            case 'q':
                printf("\n***OPERATION: QUIT***\n\n");
                printf("Goodbye!\n");
                return 0;
            default:
                break;
        }
    }
}