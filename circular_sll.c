#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node * link;
};

typedef struct node * NODE;
NODE last;

NODE getnode(){
    NODE newnode;
    int ele;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("insufficient memory\n");
        return;
    }
    printf("enter the data:");
    scanf("%d",&ele);
    newnode->info=ele;
    return newnode;
}

void insert_front(){
    NODE temp;
    temp=getnode();
    if(last==NULL){
        last=temp;
        last->link=last;
        return;
    }
    temp->link=last->link;
    last->link=temp;
    printf("insert front\n");
    return;
}

void insert_end(){
    NODE temp;
    temp=getnode();
    if(last==NULL){
        last=temp;
        last->link=last;
        printf("insert end\n");
        return;
    }
    temp->link=last->link;
    last->link=temp;
    last=temp;
    printf("insert end\n");
    return;
}

void delete_front(){
    NODE first;
    if(last == NULL){
        printf("ll is empty\n");
        return;
    }
    if(last->link == last){
        printf("node deleted:%d\n",last->info);
        free(last);
        last=NULL;
        return;
    }
    first=last->link;
    printf("node deleted:%d\n",first->info);
    last->link = first->link;
    free(first);
    first=NULL;
    return;
}

void delete_end(){
    NODE prev;
    if(last == NULL){
        printf("ll is empty\n");
        return;
    }
    if(last->link == last){
        printf("node deleted:%d\n",last->info);
        free(last);
        last=NULL;
        return;
    }
    prev=last->link;
    printf("node deleted:%d\n",last->info);
    while(prev->link != last){
        prev=prev->link;
    }
    prev->link=last->link;
    free(last);
    last=prev;
    return;
}

void display(){
    NODE cur;
    if(last == NULL){
        printf("ll is empty\n");
        return;
    }
    cur=last->link;
    printf("elements of ll:\n");
    while(cur != last){
        printf("%d\t",cur->info);
        cur=cur->link;
    }
    printf("%d\n",last->info);
    return;
}

void main(){
    int c;
    while(1){
        printf("enter your choice:");
        scanf("%d",&c);
        switch(c){
            case 1:insert_front();
            break;
            case 2:insert_end();
            break;
            case 3:display();
            break;
            case 4:delete_front();
            break;
            case 5:delete_end();
            break;
            case 6:exit(0);
            break;
        }
    }
}