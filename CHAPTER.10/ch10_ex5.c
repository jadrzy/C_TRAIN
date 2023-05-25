#include <stdio.h>
int difference(double *pointer, int n);
int main(void){
    double value;
    double array[5] = {4.11, 54.33, 11151.11, 222.4, 278.0};
    value = difference(array, sizeof(array) / sizeof(array[0]));
    printf("%g\n", value);
    return 0;
}
int difference(double *pointer, int n){
    int i;
    double *plargest = pointer;
    double *psmallest = pointer;
    for (i = 1; i < n; i++){
        pointer++;
        if (*plargest < *pointer)
            plargest = pointer;
        if (*psmallest > *pointer)
            psmallest = pointer;
    }
    return *plargest - *psmallest;
}