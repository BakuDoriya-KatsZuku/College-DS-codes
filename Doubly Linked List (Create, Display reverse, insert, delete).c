#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int data;
	struct node *next;
	struct node *prev;
}node;

node *create(int n);
node *delete_position(node *head, int n);
node *insert_position(node *head, int n);
void print_rev(node *head);
void print_for(node *head);

int main(void)
{
	int size = 0;
	do
	{
		printf("Size: ");
		scanf("%i", &size);
		if (size < 1)
		{
			printf("Size has to be greater than 0\n");
		}
	}while (size < 1);
	
	node *head = create(size);

	int x = 0;
	int y = 0;
	int n = 0;
	printf("\n");
	while (y == 0)
	{
		do
		{
			printf("1) Insert at specific position\n2) Delete at specific position\n3) Print reverse of list\n4) Print reverse of list\n5) Exit\n");
			scanf("%i", &x);
		}while(x < 1 || x > 4);

		switch(x)
		{
			case 1:
				do
				{
					printf("Position: ");
					scanf("%i", &n);
					if (n < 1)
					{
						printf("Position has to be greater than 0");
					}
					else if (n > size)
					{
						printf("Position has to be less than %i", size + 1);
					}
				}while(n < 1 || n > size);
				head = insert_position(head, n);
				printf("\n\n");
				break;
			case 2:
				do
				{
					printf("Position: ");
					scanf("%i", &n);
					if (n < 1)
					{
						printf("Position has to be greater than 0");
					}
					else if (n > size)
					{
						printf("Position has to be less than %i", size + 1);
					}
				}while(n < 1 || n > size);
				head = delete_position(head, n);
				printf("\n\n");
				break;
			case 3:
				print_rev(head);
				printf("\n\n");
				break;
			case 4:
				print_for(head);
				printf("\n\n");
			case 5:
                printf("Bye\n");
				return 0;
			default:
				printf("Bye\n");
				break;
		}
	}
}

node *create(int n)
{
	node *head;
	node *p;
	node *temp;

	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	head->prev = NULL;
	temp = head;
	int d = 0;
	printf("Number 1: ");
	scanf("%i", &d);
	head->data = d;
	n--;
	for (int i = 0; i < n; i++)
	{
		p = (node*)malloc(sizeof(node));
		printf("Number %i: ", i+2);
		scanf("%i", &d);
		p->data = d;
		p->next = NULL;
		p->prev = temp;
		temp->next = p;
		temp = p;
	}

	return (head);
}

node *insert_position(node *head, int n)
{
	node *p = (node*)malloc(sizeof(node));
	node *temp = head;

	int d = 0;
	printf("Data: ");
	scanf("%i", &d);
	p->data = d;

	if (n == 1)
	{
		p->prev = NULL;
		p->next = head;
		head->prev = p;
		head = p;
	}
	else
	{
		int count = 0;
		while (count != n - 2)
		{
			temp = temp->next;
			count++;
		}

		p->next = temp->next;
		p->prev = temp;
		if (temp->next != NULL)
		{
			node *temp1 = temp->next;
			temp1->prev = p;
		}
		temp->next = p;
	}
	return (head);
}

node *delete_position(node *head, int n)
{
	node *temp = head;

	int count = 0;
	while (count != n - 1)
	{
		temp = temp->next;
		count++;
	}

	node *temp1 = temp->next;
	node *temp2 = temp->prev;
	if (temp->next == NULL)
	{
		temp2->next = NULL;
	}
	else if (temp->prev == NULL)
	{
		head = temp->next;
		temp1->prev = NULL;
	}
	else
	{
		temp2->next = temp->next;
		temp1->prev = temp->prev;
	}

	temp->next = NULL;
	temp->prev = NULL;
	free(temp);

	return (head);
}

void print_rev(node *head)
{
	node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	while (temp != NULL)
	{
		printf("%i ", temp->data);
		temp = temp->prev;
	}
}

void print_for(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		printf("%i ", temp->data);
	}
}