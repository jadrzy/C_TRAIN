// pe12-2b.c
// compile with pe12-2a.c
#include <stdio.h>
#include "pe12-3a.h"
int main(void){
    int mode;
    int previousMode = 0;
    float result;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0){
        mode = set_mode(mode, previousMode); // if mode is > 1 correct it and print warning
        result = get_info(mode); // calculate 
        show_info(mode, result); // print result
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        previousMode = mode;
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}