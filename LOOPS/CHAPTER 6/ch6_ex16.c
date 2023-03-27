/* Chuckie Lucky won a million dollars, which he places in an account 
that earns 8% a year. On the last day of each year, Chuckie withdraws 
$100,000. Write a program that finds out how many years it takes for 
Chuckie to empty his account. */

#include <stdio.h>
#define percentage 0.08
int years = 0, account = 1000000;

int main(void)
{
	printf("ACCOUNT BALANCE:");
	while (account > 0)
	{
		account -= 100000;
		account = account + account * percentage;
		if (account <= 0)
			account = 0;
		years++;
		printf("\n%d$", account);
	}
	printf("\nEmptying Chuckie's account would take %d years.", years);
	
	
	
	return 0;
}