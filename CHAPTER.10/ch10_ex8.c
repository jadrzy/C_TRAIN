#include <stdio.h>
void copy_ptr(double *pointer1, double *pointerb, int n);
int main(void){
    double array[7] = 
    {4.11, 54.33, 11151.11, 222.4, 278.0, 342.11, 683.6};
    double carray[3];
    copy_ptr(&array[2], carray, 3);
    return 0;
}
void copy_ptr(double *pointer1, double *pointerb, int n){
    int i;
    for(i = 0; i < n; i++, pointer1++, pointerb++){
        *pointerb = *pointer1;
        printf("%g ", *pointerb);
    }
    printf("\n");
}