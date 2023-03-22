#include <stdio.h>
#include <string.h>

int x = 0;
int y = 0;
int l;
char string[2];
char Yes[] = "Yes";
char No[] = "No";
double fahrenheit = 1;
void Temperatures(double value);

int main(void)
{
	while (x == 0)
	{
		while (y == 0)
		{
			printf("\nDo you want to leave? Yes or No:\n");
			scanf("%s", string);
			char *ptry = strstr(string, Yes);
			char *ptrn = strstr(string, No);
			l = strlen(string);		
			if (ptry != NULL && l == 3)
			{
				return 0;
			}
			else if (ptrn != NULL && l == 2)
			{
				y = 1;
			}
			else
			{
				printf("Invalid command. Try again:\n");
			}
		}
		printf("Please enter temperature in Fahrenheit:\n");
		scanf("%lf", &fahrenheit);
		Temperatures(fahrenheit);
		y = 0;
	}
	return 0;
}

void Temperatures(double value)
{
	const double Fahrenheit =  value;
	const double Celsius = (5/9) * (Fahrenheit - 32.0);
	const double Kelvin = Celsius + 273.16;
	printf("\nTemperature in:\nFahrenheit = %.2lf\t Celsius = %.2lf\t Kelvin = %.2lf\t\n", Fahrenheit, Celsius, Kelvin);
}
