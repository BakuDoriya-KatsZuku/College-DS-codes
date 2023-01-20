#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;
int n = -0;

int main(void)
{
	do
	{
		printf("Size: ");
		scanf("%i", &n);
		if (n > 100)
		{
			printf("Maximum size is 100,");
		}
		else if (n < 1)
		{
			printf("Minimum size is 1.");
		}
	}while(n < 1 || n > 100);

	int s = 0;
	int a = 0;
	while(a == 0)
	{
		printf("\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit")
		scanf("%i", &s);
		switch(s)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Bye.");
				a = 1;
				break;
			default:
				printf("Select again\n");
				break;
		}
	}

}

void enqueue()
{
	if (rear >= n - 1)
	{
		printf("Queue is Full.\n");
	}
	else
	{
		int x = 0;
		printf("Numer: ");
		scanf("%i", &x);

		if (front == -1)
		{
			front++;
			rear++;
		}
		else
		{
			rear++;
		}
		queue[rear] = x;
	}
}

int dequeue()
{
	if (front < 0)
	{
		printf("Queue is Empty.\n");
		return -1;
	}
	else
	{
		int x = queue[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front++;
		}
		return x;
	}
}

void display()
{
	if (front == -1)
	{
		printf("Queue is Empty.\n");
	}
	else
	{
		for (int i = front; i <= rear; i++)
		{
			printf("%i ", queue[i]);
		}
	}
	printf("\n");
}