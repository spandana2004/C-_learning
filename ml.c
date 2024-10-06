#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE f1 = NULL, f2 = NULL;
NODE res = NULL;

NODE getnode()
{
    NODE new;
    new = (NODE)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the element: ");
    scanf("%d", &new->info);
    new->link = NULL;
    return new;
}

void insert_rear(NODE *f)
{
    NODE cur, temp;
    temp = getnode();
    if (*f == NULL)
    {
        *f = temp;
    }
    else
    {
        cur = *f;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
}

void display(NODE f)
{
    NODE cur;
    if (f == NULL)
    {
        printf("\nLinked list empty\n");
        return;
    }
    cur = f;
    printf("\nElements of linked list are: \n");
    while (cur != NULL)
    {
        printf("%d\t", cur->info);
        cur = cur->link;
    }
    printf("\n");
}

void main()
{
    int n1, n2;
    printf("Enter the number of nodes in first Linked List: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        insert_rear(&f1);
    }
    printf("Linked List 1 created\n");
    printf("Enter the number of nodes in second Linked List: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        insert_rear(&f2);
    }
    printf("Linked List 2 created\n");
    NODE cur = f1;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = f2;
    n1 = n1 + n2;
    for (int i = 0; i < n1 - 1; i++)
    {
        NODE cur1 = f1;
        NODE cur2 = f1->link;
        for (int j = 0; j < n1 - i - 1; j++)
        {
            if (cur2->info < cur1->info)
            {
                int temp = cur1->info;
                cur1->info = cur2->info;
                cur2->info = temp;
            }
            cur1 = cur1->link;
            cur2 = cur2->link;
        }
    }
    printf("Linked lists are concatenated successfully and sorted\n");
    display(f1);
}