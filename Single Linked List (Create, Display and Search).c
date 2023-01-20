#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
    int data;
    struct node* next;
}node;
 
node* create(int n);
void display(node* head);
void search(node* head, int n);
node* insert(node* head, int* n);
node* delete(node* head, int* n);
 
int main(void)
{
    int n = 0;
    int s = 0;
    int a = 0;
    int x = 0;
    do
    {
        printf("Size: ");
        scanf("%i", &n);
    }while(n <= 0);

    node* head = create(n);

    while (x == 0)
    {
        printf("\nWhat do you want to do?\n1)Search \n2)Display \n3)Insert \n4)Delete \n5)Exit\n");
        scanf("%i", &a);
        switch (a)
        {
            case 1:
                printf("Element: ");
                scanf("%i", &s);
                search(head, s);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insert(head, &n);
                break;
            case 4:
                head = delete(head, &n);
                break;
            case 5:
                printf("Bye\n");
                return 0;
            default:
                printf("Bye\n");
                break;
        }
    }
}
 
node* create(int n)
{
    node* head;
    node* temp;
    node* p;
    
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
    temp = head;
    printf("Number 1: ");
    scanf("%i", &(head->data));
    n--;
    for (int i = 0; i < n; i++)
    {
        p = (node*)malloc(sizeof(node));
        printf("Number %i: ", i + 2);
        scanf("%i", &(p->data));
        temp->next = p;
        temp = p;
        p->next = NULL;
    }
    return(head);
}
 
void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%i ", (temp->data));
        temp = temp->next;
    }
    printf("\n\n");
}
 
void search(node* head, int n)
{
    node* temp = head;
    int flag = 0;
    int count = 1;
    while(temp != NULL)
    {
        if (temp->data == n)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
        count++;
    }
    
    if (flag == 1)
    {
        printf("%i exists at position %i\n", n, count);
    }
    else
    {
        printf("%i does not exist in the array\n", n);
    }
}

node* insert(node* head, int* n)
{
    node* p = (node*)malloc(sizeof(node));
    node* temp = head;
    int x = 0;
    do
    {
        printf("Position: ");
        scanf("%i", &x);
    }while (x < 1 || x > (*n) + 1);
    printf("Data: ");
    scanf("%i", &(p->data));

    if (x == 1)
    {
        head = p;
        p->next = temp;
    }
    else
    {
        x -= 2;
        while (x > 0)
        {
            temp = temp->next;
            x--;
        }
        p->next = temp->next;
        temp->next = p;
    }

    *n = (*n) + 1;

    return (head);
}

node* delete(node* head, int* n)
{
    node* temp = head;
    int x = 0;
    do
    {
        printf("Position: ");
        scanf("%i", &x);
    }while (x < 1 || x > (*n));

    if (x == 1)
    {
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        x -= 2;
        while (x > 0)
        {
            temp = temp->next;
            x--;
        }
        node* temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        free(temp2);
    }

    *n = (*n) - 1;

    return (head);
}