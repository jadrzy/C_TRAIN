#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

/* SETTINGS */
int status, sub = 50, number = 50;
bool correct = false;

/* INPUT FUNCTIONS */
int start(void);
int ask1(int number);
int ask2(int number);

int main(void){

/* INTRODUCTION */ 
    status = start();
    if (status == 1)
        sleep(0);
    else
        return 0;

/* MAIN LOOP */
    while(correct == false){
        if (sub != 1){
            sub = sub / 2;
        }
        if (number == -1){
            printf("Your number is too small");
            return 0;
        }
        if (number == 101){
            printf("Your number is too big");
            return 0;
        }   
        status = ask1(number);
        if (status == 2){
            printf("Great. %d... I knew from the beginning\n", number);
            correct = true;
        }else if (status == 1){
            status = ask2(number);
            if (status == 2){
                number += sub; 
            }else if (status == 1){
                number -= sub;
            }else{
                return 0;
            }
        }else{
            return 0;
        }        
    }
}

/* FUNCTIONS */
int start(void){
    printf("Please pick a integer between 0 and 100.\n");
    char response[6];
    while(1){
        printf("Type 'start' if you are ready and 'quit' if you want to leave:\n");    
        scanf("%s", response);
        if((strstr(response, "start") != NULL) && (strlen(response) == 5)){
            return 1;
        }else if((strstr(response, "quit") != NULL) && (strlen(response) == 4)){
            return 0;
        }else{
            printf("Error! Wrong command! Try again.\n");
            fflush(stdin);
        }    
    }
}
int ask1(int number){
    printf("Is it %d?\n", number);
    char response[6];
    while(1){
        printf("Type 'yes' or 'no'. Type 'quit' if you want to leave:\n");    
        scanf("%s", response);
        if((strstr(response, "yes") != NULL) && (strlen(response) == 3)){
            return 2;
        }else if((strstr(response, "no") != NULL) && (strlen(response) == 2)){
            return 1;
        }else if((strstr(response, "quit") != NULL) && (strlen(response) == 4)){
            return 0;
        }else{
            printf("Error! Wrong command! Try again.\n");
            fflush(stdin);
        }    
    }
}
int ask2(int number){
    printf("Is the number bigger or smaller than %d?\n", number);
    char response[7];
    while(1){
        printf("Type 'bigger' or 'smaller'. Type 'quit' if you want to leave:\n");    
        scanf("%s", response);
        if((strstr(response, "smaller") != NULL) && (strlen(response) == 7)){
            return 1;
        }else if((strstr(response, "bigger") != NULL) && (strlen(response) == 6)){
            return 2;
        }else if((strstr(response, "quit") != NULL) && (strlen(response) == 4)){
            return 0;
        }else{
            printf("Error! Wrong command! Try again.\n");
            fflush(stdin);
        }    
    }
}