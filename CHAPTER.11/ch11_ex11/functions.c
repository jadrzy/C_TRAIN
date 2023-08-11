#include <stdio.h>
#include <stdbool.h> // for boolean type
#include <string.h> // for strlen()
#include <ctype.h> // for isalnum()
#include "header.h"

// THIS IS EDITED FUNCTION FROM THE BOOK
// IT TAKES 2D ARRAY INSTEAD OF 1D
char *gets(char st[][COL]){
    char *ret_val;
    int i, j;
    FILE * file = fopen("string_list.txt", "r"); // FUNCTION READS STRINGS FROM TXT FILE
    if (file)
        puts("Data was uploaded");
    else {
        puts("Error");
        return NULL;
    }
    for (j = 0; j < ROW; j++){   
        fgets(st[j], COL, file);        
        st[j][strcspn(st[j], "\n")] = '\0'; // NEWLINE IS REPLACED WITH \0
    }
    fclose(file);
    return ret_val;
}
char menu(void){
    char response;
    puts("CHOOSE FROM THE MENU:");
    puts("a) print strings");
    puts("b) print in ASCII collating sequence");
    puts("c) print in order of increasing lenght");
    puts("d) print in order of the lenght of the first word");
    puts("e) quit");
    puts("Option selection: ");
    response = input_validation();
    return response;
}
// FUNCTION FOR USER'S INPUT
char input_validation(void){
    int i;
    char ch;
    bool isValid = false;
    while (isValid == false){
        while ((ch = getchar()) == ' ' || ch == '\n'); // GET CHAR FROM USER (FIRST NONSPACE CHAR)
        if(ch != 'a' && ch != 'b' && ch != 'c' 
        && ch != 'd' && ch != 'e'){ // CHECK IF CH IS CORRECT
            puts("Error! Please try again!");
            puts("Option selection: ");
            while (getchar() != '\n'); // GET RID OF THE REMAINING CHARACTERS
        }else{
            isValid = true;
            while (getchar() != '\n'); // GET RID OF THE REMAINING CHARACTERS
        }
    }
    return ch;
}
// FUNCTION PRINTS THE ORIGINAL LIST OF INSERTED STRINGS
void displayA(char st[][COL]){
    puts("STRINGS:");
    for (int i = 0; i < ROW; i++)
        puts(st[i]);
}
// FUNCTION PRINTS THE STRINGS IN ASCII COLLATING SEQUENCE
// FUNCTION IS LAZY WRITTEN :(
void displayB(char st[][COL]){
    char *sortedArray[ROW];
    char *placeholder;
    int i, j, g;
    for (i = 0; i < ROW ; ++i)
        sortedArray[i] = st[i]; // FUNCTION USES ADDITIONAL ARRAY OF POINTERS
    for (g = 0; g < ROW -1; g++){ // ARRAY IS SORTED IN THIS LOOP
        for (i = ROW - 1; i > 0 + g; i--){
            j = 0;
            while ((*(sortedArray[i] + j) == *(sortedArray[i - 1] + j)) 
            && *(sortedArray[i] + j) != '\0')
                j++;
            if (*(sortedArray[i] + j) < *(sortedArray[i - 1] + j)){
                placeholder = sortedArray[i];
                sortedArray[i] = sortedArray[i - 1];
                sortedArray[i - 1] = placeholder; 
            } 
        }
    }
    puts("STRINGS:");
    for (int i = 0; i < ROW; i++)
        puts(sortedArray[i]);
}
// FUNCTION PRINTS STRINGS IN ORDER OF INCREASING LENGHT
void displayC(char st[][COL]){
    char *sortArray[ROW];
    char *placeholder;
    int i, g;
    for (i = 0; i < ROW ; ++i)
        sortArray[i] = st[i]; // FUNCTION USES ADDITIONAL ARRAY OF POINTERS
    for (g = 0; g < ROW - 1; g++){
        for (i = ROW -1; i > 0; i--){
            if(strlen(sortArray[i]) < strlen(sortArray[i - 1])){
                placeholder = sortArray[i];
                sortArray[i] = sortArray[i - 1];
                sortArray[i - 1] = placeholder; 
            }
        }
    }
    puts("STRINGS:");
    for (int i = 0; i < ROW; i++)
        puts(sortArray[i]);
}
// FUNCTION SORTS STRINGS IN ORDER OF INCREASING LENGHT OF FIRST WORD
void displayD(char st[][COL]){
    char *sortArray[ROW];
    char *placeholder;
    int i, j, g;
    int letters1, letters2;
    for (i = 0; i < ROW ; ++i)
        sortArray[i] = st[i]; // FUNCTION USES ADDITIONAL ARRAY OF POINTERS
    for (g = 0; g < ROW - 1; g++){
        for (i = ROW -1; i > 0; i--){
            j = 0;
            letters1 = 0;
            while (isalnum(*(sortArray[i] + j)) == 0 && *(sortArray[i] + j) != '\0') // FUNCTION LOOKS FOR A FIRST WORD
                j++;
            while(isalnum(*(sortArray[i] + j)) != 0){ // FUNCTION COUNTS LETTERS OF A FIRST WORD
                letters1++;
                j++;
            }
            j = 0;
            letters2 = 0;
            while (isalnum(*(sortArray[i - 1] + j)) == 0 && *(sortArray[i - 1] + j) != '\0')
                j++;
            while(isalnum(*(sortArray[i - 1] + j)) != 0){
                letters2++;
                j++;
            }
            if (letters1 > letters2){
                placeholder = sortArray[i];
                sortArray[i] = sortArray[i - 1];
                sortArray[i - 1] = placeholder; 
            }
        }
    }
    puts("STRINGS:");
    for (int i = 0; i < ROW; i++)
        puts(sortArray[i]);
}