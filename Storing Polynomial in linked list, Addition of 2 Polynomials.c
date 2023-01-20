#include <stdio.h>

typedef struct
{
	int coeff;
	int power;
	struct node *next;
}node;

node *create(int n);
void add(node *first, node *second);
void printsign(int n);

int main(void)
{
	int n1 = 0;
	int n2 = 0;

	printf("Number of Coefficients: ");
	scanf("%i", &n1);
	node *first = create(n1);
	
	printf("Number of Coefficients: ");
	scanf("%i", &n2);
	node *second = create(n2);

	add(first, second);
}

node *create(int n)
{
	node *head;
	node* temp;
	node* p;

	head = (node*)malloc(sizeof(node));
	printf("Coefficient 1: ");
	scanf("%i", &(head->coeff));
	printf("Power 1: ");
	scanf("%i", &(head->power));
	head->next = NULL;
	temp = head;

	n--;
	for (int i = 0; i < n; i++)
	{
		p = (node*)malloc(sizeof(node));
		printf("Coefficient %i: ", i + 2);
		scanf("%i", &(p->coeff));
		printf("Power %i: ", i + 2);
		scanf("%i", &(p->power));
		p->next = NULL;
		temp->next = p;
		temp = p;
	}
	
	return (head);
}

void add(node *first, node *second)
{
	node *temp1;
	node *temp2;

	temp1 = first;
	temp2 = second;
	int x = 0;

	while(temp1 != NULL || temp2 != NULL)
	{
		if (temp1 != NULL && temp2 != NULL)
		{
			//If power is same then add
			if (temp1->power == temp2 ->power)
			{
				x = temp1->coeff + temp2->coeff;
				printsign(x);
				printf("%ix^%i ", x, temp1->power);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else
			{
				//If power is not same then print with lower power first and go ahead
				if (temp1->power > temp2->power)
				{
					printsign(temp2->coeff);
					printf("%ix^%i ", temp2->coeff, temp2->power);
					temp2 = temp2->next;
				}
				else
				{
					printsign(temp1->coeff);
					printf("%ix^%i ", temp1->coeff, temp1->power);
					temp1 = temp1->next;
				}
			}
		}
		else
		{
			//If one of the lists is over then print the other in same order
			if (temp1 == NULL)
			{
				printsign(temp2->coeff);
				printf("%ix^%i ", temp2->coeff, temp2->power);
				temp2 = temp2->next;
			}
			else
			{
				printsign(temp1->coeff);
				printf("%ix^%i ", temp1->coeff, temp1->power);
				temp1 = temp1->next;
			}
		}
	}
}

void printsign(int n)
{
    if (n >= 0)
    {
        printf("+ ");
    }
}