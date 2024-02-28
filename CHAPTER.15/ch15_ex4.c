#include <stdio.h>
#include <stdlib.h>		// for atoi(), exit()

char isON(int num, int pos); 

int main(int argc, char ** argv) 
{ 
	int number, position;
// INPUT VALIDATION
	if (argc != 3)	
	{
		fprintf(stderr, "Error! Wrong declaration.\nUsage: %s <number> <position>\n", argv[0]);
		exit(EXIT_FAILURE);
	}	
	if ((number = atoi(argv[1])) == 0)
	{
		fprintf(stderr, "Error! First argument has to be an intiger."
			"\nUsage: %s <number> <position>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((position = atoi(argv[2])) == 0)
	{
    	fprintf(stderr, "Error! Second argument has to be an intiger."
			"\nUsage: %s <number> <position>\n", argv[0]); 
		exit(EXIT_FAILURE);
	}
// FUNCTION CALL
	printf("Bit of number: %d in position: %d is %s\n", number, position, 
			(isON(number, position) == 1 ? "ON" : "OFF"));
	return 0; 
}

// FUNCTION
// isON() returns 1 if bit of number (arg1) in position (arg2) is ON and 0 if OFF
char isON(int num, int pos)
{
	char output;
	int mask = 1;
	mask = mask << (pos - 1);
	((mask & num) != 0) ? (output = 1) : (output = 0); 
}
