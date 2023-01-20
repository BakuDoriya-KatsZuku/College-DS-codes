#include <stdio.h>

void merge(int a[], int left, int half, int right)
void mergesort(int a[], int left, int right);

int main(void)
{
	int n = 0;
	scanf("%i", &n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%i", &a[i]);
	}

	mergesort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%i ", a[i]);
	}
}

void merge(int a[], int left, int half, int right)
{
	int n1 = half - left + 1;
	int n2 = right - half;

	int x[n1];
	int y[n2];

	for (int i = 0; i < n1; i++)
	{
		x[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++)
	{
		y[i] = a[half + i + 1];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2)
	{
		if (x[i] <= y[j])
		{
			a[k] = x[i];
			i++;
		}
		else
		{
			a[k] = y[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = x[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = y[j];
		j++;
		k++;
	}
}


void mergesort(int a[], int left, int right)
{
	if (left < right)
	{
		int half = (left + right) / 2;
		mergesort(a, left, half);
		mergesort(a, half + 1, right);
		merge(a, left, half, right);
	}
}