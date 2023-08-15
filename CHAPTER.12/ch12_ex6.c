// generate 1000 random numbers in range 1-10
// print how many times each number was produced
#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()
#define iterations 1000
#define range 10 
int main(int argc, char** argv){
    srand(time(NULL));
    int results[range] = {0}; // array of summed up results
    for (int i = 0; i < iterations; i++){  // generating 100 random numbers
        int number;
        number = rand() % range + 1; // in range 1-10
        results[number - 1] += 1; 
    }
    printf("NUMBER:\t\tX TIMES:\n"); // printing results
    for (int i = 0; i < range; i++){
        printf("%d\t\t%d\n", i + 1, results[i]);
    }
    return 0;
}