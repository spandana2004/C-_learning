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
    if (f > r)
    {
        f = 0, r = -1;
    }
    return;
}

void insert_front()
{
    if (f == 0 && r == -1)
    {
        printf("Enter element to insert:");
        scanf("%d", &ele);
        q[++r] = ele;
        return;
    }
    if (f != 0)
    {
        printf("Enter element to insert:");
        scanf("%d", &ele);
        q[--f] = ele;
        return;
    }
    printf("Element insertion not possible\n");
    return;
}

void delete_rear()
{
    if (f > r)
    {
        printf("Queue underflow\n");
        return;
    }
    ele = q[r];
    r--;
    printf("Element deleted is %d\n", ele);
    if (f > r)
    {
        f = 0, r = -1;
    }
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
        printf("3. Insert Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
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
            insert_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting the program. Bye!\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
