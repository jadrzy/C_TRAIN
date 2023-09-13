#include <stdio.h>
#include "header.h"     // structures and prototypes

int main(void){
    int action;
    void (*ptf[6])(struct seat *pts) = {                           // array of pointers to functions
        show_num, show_list, show_alp,
        assign, delete, save_quit
    };              
    struct seat plane[MAXSEAT] = {
        {1, true}, {2, true}, {3, true}, {4, true},
        {5, true}, {6, true}, {7, true}, {8, true},
        {9, true}, {10, true}, {11, true}, {12, true}
    };
    
    while (1){                                                     // infinite loop
        action = c_gets();                                         // menu + user input is returned
        (ptf[action])(&plane[0]);                                  // using choosen by user function
    }
    return 0;
}