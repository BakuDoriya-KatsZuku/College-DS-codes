#include <stdio.h>

int stack[100];
int top = -1;
int n = 0;

void push();
int pop();
void display();

int main(void)
{
	do
	{
		printf("Size: ");
		scanf("%i", &n);
		if (n > 100)
		{
		    printf("Maximum size is 100");
		}
		else if (n < 1)
		{
		    printf("Minimum size is 1");
		}
	}while(n > 100 || n < 1);

	int a = 0;
	int s = 0;
	int x = 0;
	while (a == 0)
	{
		printf("\n1)Push\n2)Pop\n3)Display\n4)Exit\n");
		scanf("%i", &s);
		switch (s)
		{
			case 1:
				push();
				break;
			case 2:
				x = pop();
				printf("Popped Number: %i\n", x);
				break;
			case 3:
				display();
				break;
			case 4:
				a = 1;
				printf("Bye.");
				break;
		}
	}
}

void push()
{
	int x = 0;
	printf("Number: ");
	scanf("%i", &x);
	if (top >= n - 1)
	{
		printf("Stack is Full.\n");
	}
	else
	{
		top++;
		stack[top] = x;
	}
}

int pop()
{
	if (top < 0)
	{
		printf("Stack is Empty.\n");
		return -1;
	}
	else
	{
		int x = stack[top];
		top--;
		return x;
	}
}

void display()
{
	if (top < 0)
	{
		printf("Stack is Empty.");
	}
	else
	{
		for (int i = 0; i <= top; i++)
		{
			printf("%i ", stack[i]);
		}
	}
	
	printf("\n");
}