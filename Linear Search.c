#include <stdio.h>

int main(void)
{
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	int size = 7;

	int n = 0;
	printf("Number: ");
	scanf("%i", &n);
	int flag = 1;
	for (int i = 0; i < size; i++)
	{
		if (n == a[i])
		{
			printf("The number %i was found at index %i", n, i + 1);
			flag = 0;
			break;
		}
	}

	if(flag == 1)
	{
		printf("The number is not there in the array");
	}
}