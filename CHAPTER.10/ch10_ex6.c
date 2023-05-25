#include <stdio.h>
void reverse(double *pointer, int n);
int main(void){
    double array[5] = {4.11, 54.33, 11151.11, 222.4, 278.0};
    reverse(array, sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < 5; i++)
        printf("%0.2lf ", array[i]);
    printf("\n");
    return 0;
}
void reverse(double *pointer, int n){
    int i;
    double barray[n];
    for (i = 0; i < n; i++){
        barray[i] = *pointer;
        pointer++;
    }
    for (i = 0, pointer--; i < n; i++){
        *pointer = barray[i];
        pointer--;
    }
}