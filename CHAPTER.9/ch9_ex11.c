#include <stdio.h>
void fibonacci(unsigned n);
int main(void){
    unsigned numbers;
    while(1){
        printf("How many fibonacci numbers do you want to display:");
        scanf("%u", &numbers);
        if(numbers < 2)
            printf("Minimum number is 2\n");
        else
            break;
    }
    fibonacci(numbers);
    return 0;
}
void fibonacci(unsigned n){
    int number1 = 1, number2 =1, number3;
    int repetitions = 2;
    printf("1 1 ");
    while(repetitions != n){
        number3 = number1 + number2;
        number1 = number2;
        number2 = number3;
        printf("%d ", number3);
        repetitions++;
    }
    printf("\n");
}