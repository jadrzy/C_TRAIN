#include <stdio.h>

int menu(void);

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(void);

int main(void){
    void (*array[5])(void) = {
        fun1, fun2, fun3, fun4 ,fun5
    };
    int number = menu() - 1;
    array[number]();
}

int menu(void){
    int ret;
    printf("Choose function from 1-5\n");
    while ((scanf("%d", &ret)) != 1 || ret > 5 || ret < 1){
        printf("Wrong value. Try again\n");
    }
    return ret;
}

void fun1(void){
printf("One\n");
}
void fun2(void){
printf("Two\n");
}
void fun3(void){
printf("Three\n");
}
void fun4(void){
printf("Four\n");
}
void fun5(void){
printf("Five\n");
}