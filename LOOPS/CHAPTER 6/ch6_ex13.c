/* MAKING 2 ARRAYS */
/* THE FIRST ONE HAS 8 VALUES GIVEN BY A USER */
/* THE SECOND HAS 8 SUMMS OF ELEMENTS OF THE FIRST ARRAY 
(NUMBER OF SUMMED ELEMENTS DEPENDS ON INDICES) */

#include <stdio.h>
double array1[8], array2[8];
int i;

int main(void)
{
	printf("\nEnter 8 floating point numbers:");
	for (i = 0; i < 8; i++)
	{
		scanf("%lf", &array1[i]);
	}
	array2[0] = array1[0];
	for(i = 1; i < 8; i++)
	{
		array2[i] = array2[i - 1] + array1[i];
	}
	for (i = 0; i < 8; i++)	/* DISPLAY */
	{
		printf("%g\t", array1[i]);
	}
	printf("\n");
	for (i = 0; i < 8; i++)	/* DISPLAY */
	{
		printf("%g\t", array2[i]);
	}
	return 0;
}