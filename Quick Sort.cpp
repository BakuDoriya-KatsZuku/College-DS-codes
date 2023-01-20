#include <stdio.h>

void swap(int* a, int* b);
int partition(int a[], int left, int right);
void quicksort(int a[], int left, int right);

int main(void)
{
	int n = 0;
	scanf("%i", &n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%i", &a[i]);
	}

	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%i ", a[i]);
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int left, int right)
{
	int pivot = a[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}

	swap(&a[i + 1], &a[right]);
	return (i + 1);
}

void quicksort(int a[], int left, int right)
{
	if (left < right)
	{
		int p = partition(a, left, right);
		quicksort(a, p + 1, right);
		quicksort(a, left, p - 1);
	}
}