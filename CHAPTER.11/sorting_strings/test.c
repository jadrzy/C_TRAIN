#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

int main (void){
    int count = 0;
    char strings[LIMIT][LENGHT] = {0};
    for(int i = 0; i < LIMIT; i++){
        printf("%d. ", i + 1);
        fputs(strings[i], stdout);
        printf("\n");
    }
    return 0;
}