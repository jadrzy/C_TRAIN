#include <stdio.h>
int menu(void);
int valid(int a, int b);
int main(void){
    int ch;
    ch = valid(1, 4);

    return 0;
}
int valid(int a, int b){
    int choice;
    choice = menu();
    while(choice < a || choice > b){
        printf("\nEnter 1, 2, 3 or 4\n");        
        choice = menu();
    }
}
int menu(void){
    int choice;
    printf("Please choose one of the following:\n");
    printf("1) copy files\t\t2) move files\n"
    "3) remove files\t\t4) quit\n");\
    printf("Enter the number of your choice: ");
    if(scanf("%d", &choice) == 0)
        choice = 4;
    return choice;
}