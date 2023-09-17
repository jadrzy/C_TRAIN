#include <stdio.h>
#include <stdlib.h>     // exit()
#include <string.h>     // for strcpy()
#include "header.h"     // structures and prototypes

int main(void){
    int flight;
    while (1){
        char fl_number_file[8];
        char fl_number[4];
        if ((flight = c_gets_flight()) == 4)                                          // menu + user input is returned
            break;
        switch (flight){
        case 0:
            strcpy(fl_number_file, "102.dat");
            strcpy(fl_number, "102");
            break;
        case 1:
            strcpy(fl_number_file, "311.dat");
            strcpy(fl_number, "311"); 
            break;
        case 2:
            strcpy(fl_number_file, "444.dat");
            strcpy(fl_number, "444");           
            break;
        case 3:
            strcpy(fl_number_file, "519.dat");
            strcpy(fl_number, "519");
            break;
        default:
            break;
        }
        int action;
        FILE *pf;
        int size = sizeof(struct seat);    
        void (*ptf[7])(struct seat *pts, char *ptr) = {                            // array of pointers to functions
            show_num, show_list, show_alp,
            assign, delete, save, return_to_main
        };
        struct seat plane[MAXSEAT] = {                                  // setting defalut data array called plane
            {1, true}, {2, true}, {3, true}, {4, true},
            {5, true}, {6, true}, {7, true}, {8, true},
            {9, true}, {10, true}, {11, true}, {12, true}
        };
        if ((pf = fopen(fl_number_file, "rb+")) == NULL){                  // chceck if previous file exists
            printf("Cannot open %s file\n", fl_number_file);
            printf("All data has been set to defalut\n");
        }  
        else{
            rewind(pf);                                                 // if file exists copy its contents into the plane array
            int count = 0;
            while ((fread(&plane[count++], size, MAXSEAT, pf)) == 1);
            fclose(pf);
        }            
        while (1){                                                      // infinite loop
            printf("\nThis is flight %s\n", fl_number);
            if ((action = c_gets()) == 6)                                          // menu + user input is returned
                break;
            (ptf[action])(&plane[0], fl_number_file);                                   // using choosen by user function
        }
    }
    printf("Bye!\n");
    return 0;
}