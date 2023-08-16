#include <stdio.h>
#include <stdlib.h> // for malloc()
int * make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void){
    int * pa;
    int size;
    int value;
    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0){
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa){
            show_array(pa, size);
            free(pa);
        }
        printf("\nEnter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}
int * make_array(int elem, int val){
    int * ptr = (int*) malloc(elem * sizeof(int));
    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }
    for (int i = 0; i < elem; i++)
        *(ptr + i) = val;
    return ptr;
}
void show_array(const int ar[], int n){
int newline = 1;
    for (int i = 0; i < n; i++, newline++){
        printf("%d ", ar[i]);
        if (newline == 8){
            printf("\n");
            newline = 0;
        }
    }
}