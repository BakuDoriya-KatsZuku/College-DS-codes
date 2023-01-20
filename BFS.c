#include <stdio.h>

#define a 100
int adj[a][a];
int visited[a];
int n;
int queue[a];
int front = -1;
int rear = -1;

void bfs(int start);
void push(int x);
int pop();

int main(void)
{
	printf("Number of Nodes: ");
	scanf("%i", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%i", &adj[i][j]);
		}
		visited[i] = 0;
	}
	
	bfs(1);
}

void bfs(int start)
{
	visited[start] = 1;
	int x = 0;
	push(start);
	while (front != -1)
	{
		x = pop();
		printf("%i ", x);
		for (int i = 0; i < n; i++)
		{
			if (adj[x][i] == 1 && visited[i] == 0)
			{
				push(i);
				visited[i] = 1;
			}
		}
	}
}

void push(int x)
{
	if (rear == -1)
	{
		rear++;
		front++;
	}
	else
	{
		rear++;
	}
	queue[rear] = x;
}

int pop()
{
	int x = queue[front];
	if (rear == front)
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