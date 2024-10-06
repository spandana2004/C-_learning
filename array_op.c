#include <stdio.h>
#include <stdlib.h>
int a[100], n, i, pos;

void create()
{
    printf("Enter the no. of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d elements in array\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display()
{
    printf("The Array Contents are :\n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
}

void insert()
{
    int ele;
    printf("enter the element to be inserted and its position\n");
    scanf("%d%d", &ele, &pos);
    if (pos > n || pos < 0)
    {
        printf("Invalid Position\n");
        return;
    }
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = ele;
    n = n + 1;
    printf("\nArray after Insertion\n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
    return;
}

void del()
{
    printf("Enter the position to delete element:\t");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n)
    {
        printf("Invalid Position\n");
        return;
    }
    printf("Element deleted is %d\n", a[pos]);
    for (i = pos + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    n = n - 1;
    printf("\nArray after Deletion\n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
}

void main()
{
    int ch;
    for (;;)
    {
        printf("\nEnter 1 : create array");
        printf("\nEnter 2 : display array");
        printf("\nEnter 3 : insert element in to array");
        printf("\nEnter 4 : delete element from array");
        printf("\nEnter 5 : Exit");
        printf("\n enter the choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            if (n == 0)
                printf("Array is Empty\n");
            else
                display();
            break;
        case 3:
            if (n == 0)
                printf("Create the array first\n");
            else
                insert();
            break;
        case 4:
            if (n == 0)
                printf("Array is Empty\n");
            else
                del();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}
