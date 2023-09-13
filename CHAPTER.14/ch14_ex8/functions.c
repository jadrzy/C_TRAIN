#include <stdio.h>
#include <string.h>     // for strchr()
#include <stdlib.h>     // for exit()
#include "header.h"

void menu(void);
void menu(void){
    printf("\nTo choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n"); 
}

int c_gets(void){                                                       // return value is an integer in the range 0-5
    char input;
    menu();
    while (strchr("abcdef" ,(input = getchar())) == NULL){              // input validation
        while (getchar() != '\n');                                      // clearing input buffer if answer is bad
        printf("Wrong input. Please try again.\n\n");
        menu();
    }
    while (getchar() != '\n');                                          // clearing input buffer if answer is good
    return input - 97;                                                  // changing ASCII numeration of characters into numbers in range 0-5
}

// functions from the menu
void show_num(struct seat *pts){
    int count = 0;
    for (int i = 0; i < MAXSEAT; i++, pts++)
        if (pts->empty == true)
            count++;
    printf("Empty seats = %d\n", count);
}

void show_list(struct seat *pts){
    printf("Empty seats:\n");
    for (int i = 0; i < MAXSEAT; i++, pts++)
        if (pts->empty == true)
            printf("%d ", pts->number);
    printf("\n");
}

void show_alp(struct seat *pts){
    int array[12] = {-1};
    int count = 0;
    int printed = 0;
    int current_guy;
    for (int i = 0; i < MAXSEAT; i++){
        if (pts[i].empty == false){
            array[count] = i;
            count++;
        }
    }
    
    while (printed < count){
        for (int i = 0; i < count; i++){
            if (array[i] != -1)
                current_guy = i;
        }
        if (count - printed == 1){                      // printing last guy
            printf(" ");
            break;
        }
        for (int i = 0; i < count; i++){                // connect two for loops for later!!!!!!!!!!!!!!!!!!!!!!!!
            if ((strcmp(pts[array[current_guy]].person.fname, pts[array[i]].person.fname) > 0) && array[i] != -1)
            current_guy = i;
        }
    }





}

void assign(struct seat *pts){
    int seat;
    for (int i = 0; i < MAXSEAT + 1; i++, pts){
        if (i == 12){
            printf("All seats are taken\n");
            return;
        }   
        if (pts[i].empty == true)
            break;
    }                                                
    printf("Enter number of the seat:\n");
    while (scanf("%d", &seat) != 1 || seat < 1 || seat > 12){
        printf("Error. Try again:\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    if (pts[seat - 1].empty == true){
        printf("Enter first and second name:\n");
        while ((scanf("%s %s", pts[seat - 1].person.fname, pts[seat - 1].person.lname)) != 2);
        pts[seat - 1].empty = false;
        while (getchar() != '\n');          
    }
    else{
        printf("Seat is taken\n");
    }
}

void delete(struct seat *pts){
    int seat;
    for (int i = 0; i < MAXSEAT + 1; i++, pts){
        if (i == 12){
            printf("All seats are empty\n");
            return;
        }   
        if (pts[i].empty == false)
            break;
    }
    printf("Enter number of the seat:\n");
    while (scanf("%d", &seat) != 1 || seat < 1 || seat > 12){
        printf("Error. Try again:\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n'); 
    if (pts[seat - 1].empty == false){
        for (int i = 0; i < MAXNAME; i++){
            pts->person.fname[i] = '\0';
            pts->person.lname[i] = '\0';
        }
        pts[seat - 1].empty = true;
    }
    else{
        printf("Seat is already empty\n");
    }
}

void save_quit(struct seat *pts){
    printf("Bye!\n");
    exit(EXIT_SUCCESS);
}