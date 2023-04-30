#include <stdio.h>
#include <ctype.h>

int main(void){
    char ch;
    int lower = 0, upper = 0, other = 0;
    printf("Please enter string of characters:\n");
    while((ch = getchar()) != EOF){
        if (islower(ch))
            lower++;
        else if (isupper(ch))
            upper++;
        else
            other++;
    }
    printf("There are:\n *%d\tlowercase letters\n *%d\tupperase letters"
    "\n *%d\tother symbols\n", lower, upper, other);
    return 0;
}