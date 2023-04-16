/* EVALUATING TWO SERIES OF DATA */

#include <stdio.h>

int i, terms;
float sum1, sum2, fraction;

int main(void)
{
	printf("\nSUM1 = 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...");
	printf("\nSUM2 = 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...");
	printf("\n\nType how many terms of series printed above would you like to evaluate:");
	scanf("%d", &terms);
	for (i = 1; i <= terms; i++)	
	{
		fraction = 1.0 / (float) i;
		if (i % 2 == 1)
		{
			sum1 += fraction;
			sum2 += fraction; 
		}
		else
		{
			sum1 += fraction;
			sum2 -= fraction;
		}
		
	}
	printf("SUM1 = %f and SUM2 = %f\n\n", sum1, sum2);
	return 0;
}