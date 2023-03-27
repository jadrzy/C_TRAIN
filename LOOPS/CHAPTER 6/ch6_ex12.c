/* DISPLAYING FIRST 8 POWERS OF 2 IN ARRAY */

#include <stdio.h>
#include <math.h>

int i, array[8];

int main(void)
{
	printf("\nThe program will display first 8 powers of 2:");
	for (i = 0; i < 8; i++)
	{
		array[i] = pow(2, i + 1);
	}
	printf("\n");
	i = 0;
	do
	{
		printf("%d\t", array[i]);
	}
	while(++i, i < 8);	
	return 0;
}
