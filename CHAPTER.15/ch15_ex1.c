#include <stdio.h>
#include <math.h>
#include <string.h>

int b2v(char *ps, int n);

int main(void){
    char string[9] = {"011"};
    printf("%s in decimal is %d\n", string, b2v(string, strlen(string)));
    return 0;
}

int b2v(char * ps, int n){
    int value = 0;
    int power = 0;
    for (int i = n - 1; i >= 0; i--, power++){
        if (ps[i] == '1'){
            value += pow(2, power); 
        }
    }
    return value;
}