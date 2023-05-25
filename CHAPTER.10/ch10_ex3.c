#include <stdio.h>
int largest(int *pointer, int n);
int main(void){
    int number;
    int array[5] = {99, 5, 11, 21, 2};
    number = largest(array, sizeof(array) / sizeof(array[0]));
    printf("%d\n", number);    
    return 0;
}
int largest(int *pointer, int n){
    int *plarge = pointer;
    int i;
    for (i = 1; i < n; i++){
        pointer++;
        if (*pointer > *plarge)
            plarge = pointer;
    return *plarge;
    }
}