#include <stdio.h>

int countBits(int number);

int main(int argc, char ** argv)
{
	int num;
	puts("Insert number:");
	while (scanf("%d", &num) == 0)
		while (getchar() != '\n');
	puts("");
	printf("Number of bits ON: %d\n", countBits(num));
	return 0;
}

int countBits(int number)
{
	int counter = 0,
		mask = 1;
	for (int i=0; i<8*sizeof(int); ++i)
	{
		if ((number & mask) != 0)
			++counter;
		mask = mask << 1;
	}
	return counter;
}
