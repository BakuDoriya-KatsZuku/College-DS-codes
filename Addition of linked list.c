#include <stdio.h>

typedef struct 
{
	int data;
	struct node *next;
}node;

node* create(int size);

int main(void)
{
	//Make the linked lists
	int size1;
	int size2;

	printf("Size of first list: ");
	scanf("%i", &size1);
	node *first = create(size1);

	printf("Size of second list: ");
	scanf("%i", &size2);
	node *second = create(size2);

	// Connect them
	node *temp = first;
	//Traverse until last node of first and then connect it to second
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = second;

	//Check if connected or not
	temp = first;
	while(temp != NULL)
	{
		printf("%i ", temp->data);
		temp = temp->next;
	}
}

node* create(int size)
{
	node *head;
	node *p;
	node *temp;

	head = (node*)malloc(sizeof(node));
	printf("Data 1: ");
	scanf("%i", &(head->data));
	head->next = NULL;
	temp = head;

	size--;
	for (int i = 0; i < size; i++)
	{
		p = (node*)malloc(sizeof(node));
		printf("Data %i: ", i + 2);
		scanf("%i", &(p->data));
		temp->next = p;
		temp = p;
		p->next = NULL;
	}

	return (head);
}