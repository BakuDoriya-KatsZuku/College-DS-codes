#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int data;
	struct node* next;
}node;

node* create(int size);
void display(node* head);
node* delete(node* head, int* size);
node* insert(node* head, int* size);

int main(void)
{
	int size = 0;
	printf("Size: ");
	scanf("%i", &size);

	node* head = create(size);

	int x = 0;
	int a = 1;
	while(a == 1)
	{
		x = 0;
		printf("\nWhat do you want to do?\n1) Delete\n2) Display\n3) Insert\n4) Exit\n");
		scanf("%i", &x);
		printf("\n");
		switch (x)
		{
			case 1:
				head = delete(head, &size);
				printf("\n");
				break;
			case 2:
				display(head);
				printf("\n");
				break;
			case 3:
				head = insert(head, &size);
				printf("\n");
				break;
			case 4:
				printf("Bye\n");
				return 0;
			default:
				printf("Bye\n");
				break;
		}
	}
}

node* create(int size)
{
	int n = size;
	node* head;
	node* temp;
	node* p;
	head = (node*)malloc(sizeof(node));
	printf("Number 1: ");
	scanf("%i", &(head->data));
	temp = head;
	temp->next = head;
	n--;
	for (int i = 0; i < n; i++)
	{
		p = (node*)malloc(sizeof(node));
		printf("Number %i: ", i + 2);
		scanf("%i", &(p->data));
		p->next = temp->next;
		temp->next = p;
		temp = p;
	}

	return (head);
}

void display(node* head)
{
	node* temp = head;
	while (temp->next != head)
	{
		printf("%i ", (temp->data));
		temp = temp->next;
	}
	printf("%i", (temp->data));
}

node* delete(node* head, int* size)
{
	node* temp = head;
	int x = 0;
	do
	{
		printf("Position: ");
		scanf("%i", &x);
	}while(x < 1 || x > *size);


	if (x == 1)
	{
		while (temp->next != head)
    	{
    		temp = temp->next;
    	}
		node* temp2 = temp->next;
		head = temp2->next;
		temp->next = head;
		temp2->next = NULL;
		free(temp2);
	}
	else
	{
    	x -= 2;	
    	while(x > 0)
    	{
    		temp = temp->next;
    		x--;
    	}
    	node* temp2 = temp->next;
    	temp->next = temp2->next;
    	temp2->next = NULL;
    	free(temp2);
	}
	
    *size = (*size) - 1;

	return (head);
}

node* insert(node* head, int* size)
{
	node* temp = head;
	node* p = (node*)malloc(sizeof(node));
	int x = 0;
	do
	{
		printf("Position: ");
		scanf("%i", &x);
	}while(x < 1 || x > (*size) + 1);
	
	printf("Data: ");
	scanf("%i", &(p->data));

	if (x == 1)
	{
	    while (temp->next != head)
    	{
    		temp = temp->next;
    	}
    	head = p;
    	p->next = temp->next;
    	temp->next = head;
	}
	else
	{
    	x -= 2;
    	if (x < 0)
    	{
    		x = size - 1;
    	}
    	while(x > 0)
    	{
    		temp = temp->next;
    		printf("%i", (temp->data));
    		x--;
    	}
    	p->next = temp->next;
    	temp->next = p;
	}

	*size = (*size) + 1;

	return (head);
}