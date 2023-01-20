#include <stdio.h>

#define a 100
int adj[a][a];
int visited[a];
int n;

void dfs(int start);

int main(void)
{
	printf("Number of Nodes: ");
	scanf("%i", &n);

	printf("Adjacency Matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%i", &adj[i][j]);
		}
		visited[i] = 0;
	}

	dfs(0);
}

void dfs(int start)
{
	printf("%i ", start);
	visited[start] = 1;
	for (int i = 0; i < n; i++)
	{
		if (adj[start][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}
	}
}