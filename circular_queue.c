#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

int front=0,rear=-1,count=0;
int q[MAX],ele,choice,i;

void insert()
{
    if(count == MAX)
    {
        printf("Queue is overflow\n");
        return;
    }
    printf("enter the element to insert:");
    scanf("%d",&ele);
    rear = (rear+1)%MAX;
    q[rear]=ele;
    count++;
}

void delete()
{
    if(count == 0)
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Element deleted is:%d\n",q[front]);
    front=(front+1)%MAX;
    count--;
}

void display()
{
    if(count == 0)
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Queue elements are:\n");
    for(i=front; i != rear; i=(i+1)%MAX)
    {
        printf("%d\t",q[i]);
    }
    printf("%d\n",q[i]);
}

void main()
{
    while(1)
    {
    printf("enter your choice\n1.Insert\n2.Delete\n3.Display\n4.exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:insert();
            break;
        case 2:delete();
            break;
        case 3:display();
            break;
        case 4:exit(0);
            break;
        default:printf("invalid choice\n");
    }
    }
}