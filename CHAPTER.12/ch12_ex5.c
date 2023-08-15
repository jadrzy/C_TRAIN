// generate 100 random number in range 1-10 
// and sort them in decreasing order
#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()
#define size 100
#define range 10 
int main(int argc, char** argv){
    srand(time(NULL));
    int array[size];
    for (int i = 0; i < size; i++){  // generating 100 random numbers
        array[i] = rand() % range + 1; // in range 1-10
    }
    for (int j = range; j >= 1; j--){
        for (int i = 0; i < size; i++){
            if (array[i] == j)
                printf("%d\n", array[i]);
        }
    }
    return 0;
}