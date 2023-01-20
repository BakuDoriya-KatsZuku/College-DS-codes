#include <stdio.h>

int main(void)
{
	int n = 0;
	scanf("%i", &n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%i", &a[i]);
	}

	int j = 0;
	int key = 0;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%i ", a[i]);
	}
}