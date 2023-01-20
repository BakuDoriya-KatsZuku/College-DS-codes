#include <stdio.h>

int main(void)
{
	int a[7] = {1, 2, 3, 4, 5, 69, 420};
	int size = 7;

	int n = 0;
	printf("Number: ");
	scanf("%i", &n);

	int left = 0;
	int right = size - 1;
	int half = 0;
	int flag = 0;

	while (left <= right)
	{
		half = (left + right) / 2;
		if (a[half] == n)
		{
			printf("%i was found at index %i", n, half);
			flag = 0;
			break;
		}
		else if (n > a[half])
		{
			left = half + 1;
		}
		else
		{
			right = half - 1;
		}
	}

	if (flag == 0)
	{
		printf("%i is not in the array.", n);
	}
}