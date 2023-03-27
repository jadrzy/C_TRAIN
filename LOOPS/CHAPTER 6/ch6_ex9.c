#include <stdio.h>

float a, b, subtraction, division, product;
float function(float a, float b);

int main(void)
{
 printf("Q TO EXIT\nPODAJ DWIE LICZBY ZMIENNOPRZECINKOWE:");
 scanf("%f %f", &a, &b);
 do
 {
 	division = function(a ,b);
 	printf("\nWYNIK:\n%g", division);
 }
 while (printf("\n\nQ TO EXIT\nPODAJ DWIE LICZBY ZMIENNOPRZECINKOWE:\n") != 0 && scanf("%f %f", &a, &b) != 0);
 
 return 0;
}

float function(float a, float b)
{
	subtraction = a - b;
 	product = a * b;
 	division = subtraction / product;
	return division;
}
