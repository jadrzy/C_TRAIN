#include <stdio.h>
#include <stdlib.h>     // exit()
#include "header.h"     // structures and prototypes

int main(void){
    int action;
    FILE *pf;
    int size = sizeof(struct seat);    
    void (*ptf[6])(struct seat *pts) = {                            // array of pointers to functions
        show_num, show_list, show_alp,
        assign, delete, save_quit
    };
    struct seat plane[MAXSEAT] = {                                  // setting defalut data array called plane
        {1, true}, {2, true}, {3, true}, {4, true},
        {5, true}, {6, true}, {7, true}, {8, true},
        {9, true}, {10, true}, {11, true}, {12, true}
    };
    if ((pf = fopen("seats.dat", "rb+")) == NULL){                  // chceck if previous file exists
        printf("Cannot open seats.dat file\n");
        printf("All data has been set to defalut\n");
    }  
    else{
        rewind(pf);                                                 // if file exists copy its contents into the plane array
        int count = 0;
        while ((fread(&plane[count++], size, MAXSEAT, pf)) == 1);
        fclose(pf);
    }            
    while (1){                                                      // infinite loop
        action = c_gets();                                          // menu + user input is returned
        (ptf[action])(&plane[0]);                                   // using choosen by user function
    }
    return 0;
}