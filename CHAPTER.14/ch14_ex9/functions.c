#include <stdio.h>
#include <string.h>     // for strchr()
#include <stdlib.h>     // for exit()
#include "header.h"

void menu1(void);
void menu2(void);

void menu1(void){
    printf("\nTo choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Save\n"); 
    printf("g) Quit to main menu\n"); 
}

int c_gets(void){                                                       // return value is an integer in the range 0-5
    char input;
    menu1();
    while (strchr("abcdefg" ,(input = getchar())) == NULL){              // input validation
        while (getchar() != '\n');                                      // clearing input buffer if answer is bad
        printf("Wrong input. Please try again.\n\n");
        menu1();
    }
    while (getchar() != '\n');                                          // clearing input buffer if answer is good
    return input - 97;                                                  // changing ASCII numeration of characters into numbers in range 0-5
}

// functions from the menu
void show_num(struct seat *pts, char *ptr){                                        // function prints how many seats are available
    int count = 0;
    for (int i = 0; i < MAXSEAT; i++, pts++)
        if (pts->empty == true)
            count++;
    printf("Empty seats = %d\n", count);
}

void show_list(struct seat *pts, char *ptr){                                       // function prints numbers of empty seats
    printf("Empty seats:\n");
    for (int i = 0; i < MAXSEAT; i++, pts++)
        if (pts->empty == true)
            printf("%d ", pts->number);
    printf("\n");
}

void show_alp(struct seat *pts, char *ptr){                                        // function prints passengers and their seat number in the order sorted by name
    int array[12] = {-1};
    int count = 0;
    int printed = 0;    // for tracking number of printed passengers
    int current_guy;
    for (int i = 0; i < MAXSEAT; i++){                                  // create array for tracking printed passengers
        if (pts[i].empty == false){
            array[count] = i;
            count++;
        }
    }
    while (1){
        for (int i = 0; i < count + 1; i++){                                // find first person that has not been printed yet
            if (array[i] != -1){
                current_guy = i;
                break;
            }
        }
        if (count == 0){
            printf("All seats are empty\n");
            return;
        }
        if (count - printed == 1){                                      // printing last guy
            printf("%15s%15s\t%d\n", 
            pts[array[current_guy]].person.fname, 
            pts[array[current_guy]].person.lname, 
            pts[array[current_guy]].number);
            break;
        }
        else{
            for (int i = 0; i < count; i++){                            // comparing current and next passenger
                if ((strcmp(pts[array[current_guy]].person.fname, 
                            pts[array[i]].person.fname) > 0) 
                    && array[i] != -1)
                current_guy = i;
            }
        }
        printf("%15s%15s\t%d\n", 
        pts[array[current_guy]].person.fname, 
        pts[array[current_guy]].person.lname, 
        pts[array[current_guy]].number);
        array[current_guy] = -1;
        printed++;
    }
}

void assign(struct seat *pts, char *ptr){                                          // function for assigining new passengers to the plane array
    int seat;
    for (int i = 0; i < MAXSEAT + 1; i++, pts){
        if (i == 12){                                                   // report error if all seats are taken
            printf("All seats are taken\n");
            return;
        }   
        if (pts[i].empty == true)
            break;
    }                                                
    printf("Enter number of the seat:\n");                              // get a seat number from the user
    while (scanf("%d", &seat) != 1 || seat < 1 || seat > 12){
        printf("Error. Try again:\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    if (pts[seat - 1].empty == true){
        printf("Enter first and second name:\n");  
        while ((scanf("%s %s",                                          // get the name and surname of the passenger
                pts[seat - 1].person.fname, 
                pts[seat - 1].person.lname)) != 2);
        pts[seat - 1].empty = false;
        while (getchar() != '\n');          
    }
    else{
        printf("Seat is taken\n");                                      // report if seat is taken
    }
}
void delete(struct seat *pts, char *ptr){                                          // function that deletes choosen passenger from the plane array  
    int seat;
    for (int i = 0; i < MAXSEAT + 1; i++, pts){
        if (i == 12){
            printf("All seats are empty\n");                            // report if all seats are empty
            return;
        }   
        if (pts[i].empty == false)
            break;
    }
    printf("Enter number of the seat:\n");                              // get a seat number from the user
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
        printf("Seat is already empty\n");                              // report if seat is already empty
    }
}

void save(struct seat *pts, char *ptr){                                       // function that saves data into seats.dat file and terminates program
    FILE *pf;
    int size = sizeof(struct seat);
    if ((pf = fopen(ptr, "wb+")) == NULL){                      // open file for writing in binary mode
        printf("Error opening %s file\n", ptr);
        printf("Data has not been saved\n");
        exit(EXIT_FAILURE);
    }
    rewind(pf);
    for (int i = 0; i < MAXSEAT; i++){
        fwrite(&pts[i], size, 1, pf);
    }
    fclose(pf);
}
void return_to_main(struct seat *pts, char *ptr){                                       // function that saves data into seats.dat file and terminates program

}
// EXERCISE 9 EXPANSION

void menu2(void){
    printf("\nTo choose a flight, enter its letter label:\n");
    printf("a) Flight 102\n");
    printf("b) Flight 311\n");
    printf("c) Flight 444\n");
    printf("d) Flight 519\n");
    printf("e) Quit\n"); 
}

int c_gets_flight(void){                                                       // return value is an integer in the range 0-5
    char input;
    menu2();
    while (strchr("abcde" ,(input = getchar())) == NULL){              // input validation
        while (getchar() != '\n');                                      // clearing input buffer if answer is bad
        printf("Wrong input. Please try again.\n\n");
        menu2();
    }
    while (getchar() != '\n');                                          // clearing input buffer if answer is good
    return input - 97;                                                  // changing ASCII numeration of characters into numbers in range 0-5
}