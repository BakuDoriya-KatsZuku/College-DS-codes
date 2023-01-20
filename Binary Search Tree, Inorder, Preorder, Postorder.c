#include <stdio.h>

// Defining Data Structure
typedef struct
{
	int data;
	struct node *left;
	struct node *right;
}node;

//Prototyping
node *insert(node *root, int n);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
node *delete(node *root, int n);
void search(node *root, int n);

int main(void)
{
	node *root = NULL;
	int n = 0;
	printf("Number of elements: ");
	scanf("%i", &n);
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		printf("Data: ");
		scanf("%i", &x);
		root = insert(root, x);	
	}

	printf("\nInorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
}

node *insert(node *root, int n)
{
	//If node is not present make it else go ahead for finding the position of insertion
	if (root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = n;
		return (root);
	}
	else
	{
		if (n < root->data)
		{
			root->left = insert(root->left, n);
		}
		else
		{
			root->right = insert(root->right, n);
		}
	}

	return (root);
}

void inorder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%i ", root->data);
	inorder(root->right);
}

void preorder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%i ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%i ", root->data);
}

node *delete(node *root, int n)
{
	node *temp = root;
	node *temp2 = root;
	while (temp->data != n)
	{
		if (n < temp->data)
		{
			temp2 = temp;
			temp = temp->left;
		}
		else
		{
			temp2 = temp;
			temp = temp->right;
		}
	}

	if (temp->left == NULL && temp->right == NULL)
	{
		if (temp2->left == temp)
		{
			temp2->left = NULL;
		}
		else
		{
			temp2->right = NULL;
		}
	}
	else if ((temp->left == NULL || temp->right == NULL))
	{
		if (temp->right == NULL)
		{
			if (temp2->left == temp)
			{
				temp2->left = temp->left;
			}
			else if (temp2 == temp)
			{
				root = temp->left;
			}
			else
			{
				temp2->right = temp->left;
			}
		}
		else
		{
			if (temp2->left == temp)
			{
				temp2->left = temp->right;
			}
			else if (temp == temp2)
			{
				root = temp->right;
			}
			else
			{
				temp2->right = temp->right;
			}
		}
	}
	else
	{
		if (temp2->left == temp)
		{
			temp2->left = temp->right;
		}
		else if (temp2 == temp)
		{
			root = temp->right;
		}
		else
		{
			temp2->right = temp->right;
		}
		node *t = temp->right;
		while (t->left != NULL)
		{
			t = t->left;
		}
		t->left = temp->left;
	}

	temp->right = NULL;
	temp->left = NULL;
	free(temp);

	return (root);
}

void search(node *root, int n)
{
	if (root == NULL)
	{
		printf("Not Found");
		return;
	}
	if (n == root->data)
	{
		printf("Found");
		return;
	}
	else if (n < root->data)
	{
		search(root->left, n);
	}
	else
	{
		search(root->right, n);
	}
}