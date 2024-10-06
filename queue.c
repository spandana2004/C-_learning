#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int f = 0, r = -1, q[MAX], ele;

void insert_rear()
{
    if (r == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter the element to insert:");
    scanf("%d", &ele);
    r++;
    q[r] = ele;
    return;
}

void delete_front()
{
    if (f > r)
    {
        printf("Queue underflow\n");
        return;
    }
    ele = q[f];
    f++;
    printf("Element deleted is %d\n", ele);
    return;
}

void display()
{
    if (f > r)
    {
        printf("Queue underflow\n");
    }
    printf("Elements of queue:\n");
    for (int i = f; i <= r; i++)
    {
        printf("%d\t", q[i]);
    }
    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n----- Queue Menu -----\n");
        printf("1. Insert Rear\n");
        printf("2. Delete Front\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_rear();
            break;
        case 2:
            delete_front();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program. Bye!\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
