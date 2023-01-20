#include <stdio.h>

typedef struct 
{
	int data;
	struct node* left;
	struct node* right;
}node;

node* insert(node* root, int n);
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
void search(node* root, int n);
node* delete(node* root, int n);

int main(void)
{
	node* root = NULL;
	int n = 0;
	scanf("%i", &n);
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%i", &x);
		root = insert(root, x);
	}

	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	search(root, 69);
	delete(root, 69);
	delete(root, 100);
	delete(root, 1);
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
}

node* insert(node* root, int n)
{
	if (root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->data = n;
		root->right = NULL;
		root->left = NULL;
		return (root);
	}
	if (n > root->data)
	{
		root->right = insert(root->right, n);
	}
	else
	{
		root->left = insert(root->left, n);
	}

	return (root);
}

void preorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%i ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%i ", root->data);
	inorder(root->right);
}

void postorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%i ", root->data);
}

void search(node* root, int n)
{
	if (root == NULL)
	{
		printf("Not Found.\n");
		return;
	}
	if (root->data == n)
	{
		printf("Found.\n");
		return;
	}
	else if (n > root->data)
	{
		search(root->right, n);
	}
	else
	{
		search(root->left, n);
	}
}

node* delete(node* root, int n)
{
	if (root == NULL)
	{
		return (root);
	}

	if (n > root->data)
	{
		root->right = delete(root->right, n);
	}
	else if (n < root->data)
	{
		root->left = delete(root->left, n);
	}
	else
	{
		if (root->left == NULL)
		{
			node* p = root->right;
			free(root);
			return (p);
		}
		else if (root->right == NULL)
		{
			node* p = root->left;
			free(root);
			return (p);
		}

		node* temp = root->right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		root->data = temp->data;

		root->right = delete(root->right, temp->data);
	}
	return (root);
}