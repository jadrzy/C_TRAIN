#include <stdio.h>
int array[8];
int i;

int main(void){
	printf("\nType 8 integers:\n");
	for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("\n");
	for (i = 7; i > -1; i--)
	{
		printf("%d\t", array[i]);
	}
	return 0;
}