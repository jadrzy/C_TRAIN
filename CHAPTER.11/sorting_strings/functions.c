#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

//ACTION FUNCTIONS
char menu(int *n){
    puts(PLHOLDER);
    while(getchar() != '\n');
    char c;
    printf("\n\t\tMAIN MENU\n");
    puts(ASTERISKS);
    printf("a) add new string\tb) sort strings\n");
    printf("c) display strings\td) delete string\n");
    printf("e) exit\t\t\ti) information\n");
    puts(ASTERISKS);
    printf("\t\t  Strings occupied: %d/%d\n", *n, LIMIT);
    printf("Option selection: ");
    c = input_validation();
    return c;
}

char input_validation(void){
    int i;
    char ch, string[2];
    bool valid = false;
    while(valid != true){
        while((ch = getchar()) == ' ' || ch == '\n');
        //if(ch == '\n')
           // continue;
        if(ch != 'a' && ch != 'b' && ch != 'c' 
        && ch != 'd' && ch != 'e' && ch != 'i'){
            printf("\nError! Please try again!\n");
            printf("Option selection: ");
        }else{
            valid = true;
            while(getchar() != '\n');
        }
    }
    return ch;
}

//INFO FUNCTIONS
void intro(void){
    printf("Welcome into the sorting program.\n");//start intro
    sleep(1);
    printf("Please follow instructions.\n");
    sleep(1);
    printf("For more information choose option i from the menu.\n");//end intro 
    sleep(1);
}
void information(void){
    printf("\nThis program can store strings and sort them.\nThere is a limit of 20 strings inserted.\n");
    printf("Each string can fit 80 characters.\nYou can delete any string by choosing d from menu an selecting index of string.\n");
    printf("To exit choose option e from the main menu.\n");
}