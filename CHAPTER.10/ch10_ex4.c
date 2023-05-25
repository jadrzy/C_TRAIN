#include <stdio.h>
int largest(double *pointer, int n);
int main(void){
    int index;
    double array[5] = {4.1, 54.33, 1111.11, 222.4, 2098978.0};
    index = largest(array, sizeof(array) / sizeof(array[0]));
    printf("%d\n", index);
    return 0;
}
int largest(double *pointer, int n){
    int i, inverted;
    double *plargest = pointer;
    for (i = 1; i < n; i++){
        pointer++;
        if (*plargest < *pointer)
            plargest = pointer;
    }
    inverted = pointer - plargest;
    return n - inverted - 1; // -1 because first index is 0 not 1 
}