#include <stdio.h>
#include <ctype.h>

int menu(void);
int get_ch(void);
float first(void);
float second(void);

int main(void){
    int choice;
    float number1, number2;
    while (1){
        choice = menu();
        if (choice == 'q'){
            printf("Bye.\n");
            return 0;
        }
        number1 = first();
        number2 = second();
        switch(choice){
            case 'a':
                printf("%g + %g = %g\n", number1, number2, number1+number2);
                break;
            case 's':
                printf("%g - %g = %g\n", number1, number2, number1-number2);
                break;
            case 'm':
                printf("%g * %g = %g\n", number1, number2, number1*number2);
                break;
            case 'd':
                while (number2 == 0){
                    printf("Enter a number other than 0.\n");
                    number2 = second();
                }
                printf("%g / %g = %g\n", number1, number2, number1/number2);
                break;
        }
        while(getchar() != '\n');
    }
}

/* MENU FUNCTION */
int menu(void){
    int input;
    printf("Enter the operation of your choice:\n");
    printf("a.  add\t\ts.  subtract\n");
    printf("m.  multiply\td.  divide\n");
    printf("q.  quit\n");
    input = get_ch();
    while (input != 'a' && input != 's' && input != 'm'
    && input != 'd' && input != 'q'){
        printf("Please respond with a, s, m, d or q.\n");
        input = get_ch();
    }
    return input;
}

/* CHOICE FUNCTION */
int get_ch(void){
    int input;
    while ((input = getchar()) == ' ');
    while (getchar() != '\n')
        continue;
    return input;
}

/* NUMBER 1 INPUT */
float first(void){
    float number;
    char string[10];
    printf("Enter first number: ");
    while (scanf("%f", &number) != 1){
        scanf("%s", string);
        printf("%s is not an number.\n", string);
        printf("Please enter a number, such as 2.5, -178E8, or 3: ");
    }
    return number;
}

/* NUMBER 2 INPUT */
float second(void){
    float number;
    char string[10];
    printf("Enter second number: ");
    while (scanf("%f", &number) != 1){
        scanf("%s", string);
        printf("%s is not an number.\n", string);
        printf("Please enter a number, such as 2.5, -178E8, or 3: ");
    }
    return number;
}