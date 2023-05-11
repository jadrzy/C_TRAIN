// ASCII lowercase scope (97-122)
//       uppercase scope (65-90)
#include <stdio.h>
#include <ctype.h>
int num_location(char character);
int main(void){
    char ch;
    while((ch = getchar()) != EOF){
        printf("%c", ch);
        if (num_location(ch) > 0)
            printf("%d", num_location(ch));
        printf("\n");
    }
    printf("\n");
    return 0;
}
int num_location(char character){
    int location;
    if (islower(character)){
        location = (int) character - 96;
    } else if (isupper(character)){
        location = (int) character - 64;
    } else {
        location = -1;
    }
    return location;
}