#include <stdio.h>
#include <stdlib.h> // exit() prototype
int main(int argc, char *argv[]){
    int ch; // place to store each character as read
    char name[20];
    FILE *fp; // "file pointer"
    unsigned long count = 0;
    printf("Please enter filename : ");
    while (scanf("%s", name) != 1)
        printf("Error.Try again.\nPlease enter filename : ");
    if ((fp = fopen(name, "r")) == NULL){
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF){
        putc(ch,stdout); // same as putchar(ch);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters\n", name, count);
    return 0;
}