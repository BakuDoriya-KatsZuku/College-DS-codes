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

	int mini = 0;
	int temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		mini = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[mini])
			{
				mini = j;
			}
		}
		temp = a[mini];
		a[mini] = a[i];
		a[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%i ", a[i]);
	}
}