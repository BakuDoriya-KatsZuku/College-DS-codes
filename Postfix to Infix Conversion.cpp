#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define a 100

void pop();
void push(char x);
int priority (char x);

int top = 0;
int size = 100;
char stack[a];

int main(void)
{
    char s[100];
    printf("Infix: ");
    scanf("%s", s);
    size = strlen(s);
    
	for (int i = 0; i < size; i++)
	{
		if (s[i] == '(')
		{
			push(s[i]);
		}
		else if (s[i] >= 48 && s[i] <= 57)
		{
			printf("%c", s[i]);
		}
		else if (s[i] == ')')
		{
			while (stack[top] != '(')
			{
				pop();
			}
		}
		else
		{
			while (priority(s[i]) < priority(stack[top]))
			{
				pop();
			}
			push(s[i]);
		}
	}

	while (top != -1)
	{
		pop();
	}
}

void pop()
{
	if (top == -1)
	{
		printf("Stack is empty.");
	}
	char y = stack[top];
	top--;
	printf("%c", y);
}

void push(char x)
{
	if (top == size - 1)
	{
		printf("Stack is full.");
	}
	top++;
	stack[top] = x;
}

int priority (char x)
{
	int p = -1;
	if (x == '+' || x == '-')
	{
		p = 1;
	}
	else if (x == '*' || x == '/')
	{
		p = 2;
	}
	else if (x == '%')
	{
		p = 3;
	}

	return p;
}