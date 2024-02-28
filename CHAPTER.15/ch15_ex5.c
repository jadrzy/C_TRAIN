#include <stdio.h>
#include <stdlib.h>		// for rand(), srand()
#include <time.h>		// for time()

void rotate(unsigned char * const ptr, char trans);

int main(int argc, char ** argv)
{
	char tr;
	srand((unsigned int)time(NULL));	// randomize seed	
	unsigned char x = rand()%256;		// generate random 8 bit positive number
	printf("Random 8 bits long number x: %d\n", x);
	puts("Swap bits to the left by how many places?");
	while ((scanf("%d", &tr) == 0) || ((tr < 0) || (tr > 8)))	// get translation from user
	{
		while (getchar() != '\n');
		printf("Error! Try again!\n");
	}
	rotate(&x, tr);		// function call
	printf("New value of x: %d\n", x);
	return 0;
}

// FUNCTION
void rotate(unsigned char * const ptr, char trans)
{
	if (trans != 0)		// if translation is 0 omit procedure
	{
		unsigned char temp;
		temp = (*ptr >> (8*sizeof(char) - trans));	// disappearnig after trans part of the number
		*ptr = (*ptr << trans) | temp;	// saving result in memory
	}
}
