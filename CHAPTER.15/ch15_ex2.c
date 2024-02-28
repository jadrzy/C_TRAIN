#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h> // for strlen()
#include <ctype.h>  // for isdigit()
#include <math.h>   // for pow()

int str2bin(char *, int);

int main(int argc, char **argv)
{
// START OF VALIDATION PROCESS
    // NUMBER OF ARGUMENTS VALIDATION
	if (argc != 3)
	{
        fprintf(stderr, "Error! Wrong declaration. Usage: %s <string1> <string2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int lenght1 = strlen(argv[1]),
        lenght2 = strlen(argv[2]);

	// STRING 1 VALIDATION     
	for (int i = 0; i < lenght1; i++)
	{
		if (*(argv[1] + i) != '0' && *(argv[1] + i) != '1')
		{                                    
			fprintf(stderr, "Error! Wrong declaration %s." 
					"Enter a number written in binary.\n", argv[1]);
            exit(EXIT_FAILURE);
		}
    }
	// STRING 2 VALIDATION
    for (int i = 0; i < lenght2; i++)
	{
        if (*(argv[2] + i) != '0' && *(argv[2] + i) != '1')
		{                        
			fprintf(stderr, "Error! Wrong declaration %s." 
					"Enter a number written in binary.\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

// CALCULATIONS
    int number1 = str2bin(argv[1], lenght1), 
        number2 = str2bin(argv[2], lenght2);
 
    printf("The results of applying \"~\" operator ---> \tnumber 1: %d\t number 2: %d\n", 
																		~number1, ~number2);
    printf("The results of applying \"&\" operator ---> \tnumber: %d\n", number1 & number2);
    printf("The results of applying \"|\" operator ---> \tnumber: %d\n", number1 | number2);
    printf("The results of applying \"^\" operator ---> \tnumber: %d\n", number1 ^ number2);

    return 0;
}

// FUNCTION BINARY TO DECIMAL
int str2bin(char *str, int n)
{
    int value = 0;
    int power = 0;
    for (int i = n - 1; i >= 0; i--, power++)
	{
        if (str[i] == '1')
            value += pow(2, power); 
    }
    return value; 
}
