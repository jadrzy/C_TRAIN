#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int num;
};

int calculate(char name[10]);
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

int main(void){
    char name[10];
    printf("Please enter name of the month. Empty line to quit\n");
    while (s_gets(name ,9) != NULL && name[0] != '\0'){
        printf("Sum of the days preceding %s and %s itself is %d\n\n", name, name, calculate(name));
        printf("Please enter name of the month. Empty line to quit\n");
    }
    return 0;
}

int calculate(char name[10]){
    int sum = 0;
    for (int i = 0; i < 12; i++){
        sum +=months[i].days; 
        if (strcmp(name, months[i].name) == 0)
            break;
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