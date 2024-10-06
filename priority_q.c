// Insertion, Deletion in the PRIORITY QUEUE
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = 0, rear = -1, i, j, ele, choice;
int pq[MAX]; // pq->PRIORITY QUEUE

void insert();
void delete();
void display();

void main()
{
    while (1)
    {
        printf("1.Insert to the PRIORITY QUEUE\n");
        printf("2.Delete from the PRIORITY QUEUE as per the priority\n");
        printf("3.Display the elements of PRIORITY QUEUE\n");
        printf("4.Exit\n");
        printf("Enter the choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void insert()
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter element to be inserted:\n");
    scanf("%d", &ele);
    j = rear;
    while ((j >= 0) && (ele < pq[j]))
    {
        pq[j + 1] = pq[j];
        j--;
    }
    pq[++j] = ele;
    rear++;
    return;
}

void delete()
{
    if (front > rear)
    {
        printf("The priority queue is empty\n");
        return;
    }
    ele = pq[front];
    printf("The element deleted is %d\n", ele);
    front++;
}

void display()
{
    if (front > rear)
    {
        printf("The priority queue is empty\n");
    }
    printf("The elements in the priority queue are :\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d\n", pq[i]);
    }
}