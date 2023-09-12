#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int num;
};

int calculate_name(char name[10]);
int calculate_abbre(char abbrev[4]);
int calculate_number(int num);
char * s_gets(char * st, int n);

struct month months[12] = {
    {"january", "jan", 31, 1},
    {"february", "feb", 28, 2},
    {"march", "mar", 31, 3},
    {"april", "apr", 30, 4},
    {"may", "may", 31, 5},
    {"june", "jun", 30, 6},
    {"july", "jul", 31, 7},
    {"august", "aug", 31, 8},
    {"september", "sep", 30, 9},
    {"october", "oct", 31, 10},
    {"november", "nov", 30, 11},
    {"december", "dec", 31, 12}
};

union data {
    char name[10];
    int number;
};

int main(void){
    union data input; 
    int sum;
    printf("Enter name, abbreviation or number of the month. -1 to quit\n");
    while (1){
        if (scanf("%d", &input.number) == 1){
            if (input.number == -1){
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            }
            sum = calculate_number(input.number);
        }
        else{ 
            s_gets(input.name ,9);
            if (strlen(input.name) == 3)
                sum = calculate_abbre(input.name);
            else
                sum = calculate_name(input.name);
        }
        printf("Sum of days preceding choosen month and including it is %d\n\n", sum);
        printf("Please enter name of the month. -1 to quit\n");
    }  
}

int calculate_name(char name[10]){
    int sum = 0;
    for (int i = 0; i < 13; i++){
        sum +=months[i].days; 
        if (strcmp(name, months[i].name) == 0)
            break;
        if (i == 12){
            printf ("Error. Wrong input.\n");
            return -1;
        }
    }
    return sum;
}

int calculate_abbre(char abbrev[4]){
    int sum = 0;
    for (int i = 0; i < 13; i++){
        sum +=months[i].days; 
        if (strcmp(abbrev, months[i].abbrev) == 0)
            break;
        if (i == 12){
            printf ("Error. Wrong input.\n");
            return -1;
        }
    }
    return sum;
}

int calculate_number(int num){
    int sum = 0;
    for (int i = 0; i < 13; i++){
        sum +=months[i].days; 
        if (num == months[i].num)
            break;
        if (i == 12){
            printf ("Error. Wrong input.\n");
            return -1;
        }
    }
    return sum;
}

char * s_gets(char * st, int n){
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        for (int i = 0; i < n; i++)
            *(st + i) = tolower(*(st + i));
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}