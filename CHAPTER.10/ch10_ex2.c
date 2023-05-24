#include <stdio.h>
void copy_arr(double array1[], double arrayb[], int n);
void copy_ptr(double *pointer1, double *pointerb, int n);
void copy_ptrs(double array3[], double arrayb[], double *pointer2);
int main(void){
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    return 0;
}
void copy_arr(double array1[], double arrayb[], int n){
    int i;
    for(i = 0; i < n; i++){
        array1[i] = arrayb[i];
        printf("%g ", array1[i]);
    }
    printf("\n");
}
void copy_ptr(double *pointer1, double *pointerb, int n){
    int i;
    for(i = 0; i < n; i++){
        *pointer1 = *pointerb;
        printf("%g ", *pointer1);
        pointer1++;
        pointerb++;
    }
    printf("\n");
}
void copy_ptrs(double array3[], double arrayb[], double *pointer2){   
    int i = 0;
    while(&arrayb[i] != pointer2){ 
        array3[i] = arrayb[i];
        printf("%g ", array3[i]);
        i++;
    }
    printf("\n");
}