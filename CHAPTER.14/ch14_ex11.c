// compile with -lm to link math.h library


#include <stdio.h>
#include <math.h>
#define LENGHT 10

int transform(
    double source_arr[], 
    double target_arr[], 
    int arr_lenght,
    double (*function)(double)
);

int main(void){
    double source_array[LENGHT];
    double target_array[LENGHT];   
    for (int i = 0; i < LENGHT; i++)
        source_array[i] = i;
    printf("Original:\n");
    for (int i = 0; i < LENGHT; i++)
        printf("%g\n", source_array[i]); 
    
    transform(source_array, target_array, LENGHT, sqrt);
    printf("Sqrt:\n");
    for (int i = 0; i < LENGHT; i++)
        printf("%g\n", target_array[i]);    
    
    transform(source_array, target_array, LENGHT, exp);
    printf("Exp:\n");
    for (int i = 0; i < LENGHT; i++)
        printf("%g\n", target_array[i]); 

    transform(source_array, target_array, LENGHT, sin);
    printf("Sin:\n");
    for (int i = 0; i < LENGHT; i++)
        printf("%g\n", target_array[i]); 

    transform(source_array, target_array, LENGHT, cos);
    printf("Cos:\n");
    for (int i = 0; i < LENGHT; i++)
        printf("%g\n", target_array[i]); 
    
    return 0;
}

int transform(    
        double source_arr[], 
        double target_arr[], 
        int arr_lenght,
        double (*function)(double)
){
    for(int i = 0; i < arr_lenght; i++){
        target_arr[i] = (*function)(source_arr[i]);
    }
}