#include <stdio.h>
#define LENGHT 4
void sum(const int *ptr1, const int *ptr2, int *ptr3, int n);
int main(void){
    const int array1[LENGHT] = {2, 4, 5, 8};
    const int array2[LENGHT] = {1, 0, 4, 6};
    int array3[LENGHT];
    sum(array1, array2, array3, LENGHT);
    return 0;
}
void sum(const int *ptr1, const int *ptr2, int *ptr3, int n){
    for (int i = 0; i < n; i++, ptr1++, ptr2++, ptr3++){
        *ptr3 = *ptr2 + *ptr1;
        printf("%d ", *ptr3);
    }
    printf("\n");
}