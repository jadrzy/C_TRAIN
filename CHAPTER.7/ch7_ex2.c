#include <stdio.h>
int main(void)
{
    char ch;
    int count = 0;
    while ((ch = getchar()) != '#')
    {
        if (count % 8 == 0)
            printf("\n");
        putchar(ch);
        if (ch != '\n' && ch != '\t')
            printf(" = %d\t", ch);
        count++;
    }
return 0;
}