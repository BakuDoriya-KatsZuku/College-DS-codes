#include <stdio.h>

char stack[100];
int top = -1;

void push(char x);
char pop();

int main(void)
{
	char s[100];
	printf("Expression: ");
	scanf("%s", s);
	int n = strlen(s);

	int flag = 0;
	char x = '.';
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			push(s[i]);
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (top == -1)
			{
				printf("Unbalanced Paranthesis");
				flag = 1;
				break;
			}
			else
			{
				if (stack[top] == '(' && s[i] == ')')
				{
					x = pop();
				}
				else if (stack[top] == '{' && s[i] == '}')
				{
					x = pop();
				}
				else if (stack[top] == '[' && s[i] == ']')
				{
					x = pop();
				}
				else
				{
					printf("Unbalanced Paranthesis");
					flag = 1;
					break;
				}
			}
		}
	}

	if (top != -1)
	{
		flag = 1;
		printf("Unbalanced Paranthesis");
	}
	if (flag == 0)
	{
		printf("Balanced Paranthesis");
	}
}

void push(char x)
{
	top++;
	stack[top] = x;
}

char pop()
{
	char x = stack[top];
	top--;
	return x;
}