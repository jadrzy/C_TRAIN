/* SCANNING A LINE ON TEXT AND PRINTING IN REVERSE ORDER */

#include <stdio.h>
#include <string.h>
char c, array[255];
int i = 0;

int main(void)
{
	printf("\nEnter full sentence:\n");
	while (c != '\n')
	{
		scanf("%c", &c);
		array[i] = c;
		i++;
	}
	i--; /* i has 1 iteration too many */
	for(;i >= 0 ;i--) /* DISPLAY */
	{
		printf("%c", array[i]);
	}
	return 0;
}