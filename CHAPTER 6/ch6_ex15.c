/*Daphne invests $100 at 10% simple interest. Deirdre invests $100 
at 5% interest compounded annually. Write a program that finds how 
many years it takes for the value of Deirdre's investment to exceed 
the value of Daphne's investment.*/

#include <stdio.h>
int daphne, deirdre, i = 1;

int main(void)
{
	daphne = 110;
	deirdre = 105;
	while (daphne > deirdre)
	{
		daphne += 10;
		deirdre *= 1.05;
		i++;
	}
	printf("Deirde's investment will exceed Daphne's invest after %d years", i);
	return 0;
}