#include <stdio.h>
int main(void)
{
    char ch;
    int nl, sp, oth;
    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            nl++;
        else if (ch == ' ')
            sp++;
        else
            oth++;
    }
printf("%d spaces  %d newline  %d other", sp, nl, oth);
return 0;
}