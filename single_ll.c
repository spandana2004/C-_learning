#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node * link;
};

typedef struct node * NODE;
NODE first;

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
    temp->link=first;
    first=temp;
    printf("insert front successful\n");
    return;
}

void insert_end(){
    NODE cur,temp;
    temp=getnode();
    temp->link=NULL;
    if(first==NULL){
        first=temp;
        printf("insert end successful\n");
        return;
    }
    if(first->link==NULL){
        first->link=temp;
        printf("insert end successful\n");
        return;
    }
    cur=first;
    while(cur->link !=NULL){
        cur=cur->link;
    }
    cur->link=temp;
    printf("insert end successful\n");
    return;
}

void display(){
    NODE cur;
    if(first == NULL){
        printf("ll is empty\n");
        return;
    }
    cur=first;
    printf("elements of ll:\n");
    while(cur != NULL){
        printf("%d\t",cur->info);
        cur=cur->link;
    }
    printf("\n");
    return;
}

void delete_front(){
    NODE temp;
    temp=first;
    if(first == NULL){
        printf("ll is empty\n");
        return;
    }
    printf("node deleted:%d\n",first->info);
    first=first->link;
    free(temp);
    return;
}

void delete_end(){
    NODE cur,prev;
    if(first==NULL){
        printf("ll is empty\n");
        return;
    }
    if(first->link==NULL){
        printf("node deleted :%d\n",first->info);
        free(first);
        first=NULL;
        return;
    }
    cur=first;
    prev=NULL;
    while(cur->link != NULL){
        prev=cur;
        cur=cur->link;
    }
    printf("node deleted:%d\n",cur->info);
    free(cur);
    prev->link=NULL;
    return;
}

void insert_specific(){
    NODE temp,cur,prev;
    int i=1,pos=0;
    printf("enter the position:");
    scanf("%d",&pos);
    temp=getnode();
    cur=first;
    prev=NULL;
    while(i<pos){
        prev=cur;
        cur=cur->link;
        i++;
    }
    prev->link=temp;
    temp->link=cur;
    printf("insert sucessfull\n");
    return;
}

void delete_specific(){
    NODE cur,prev;
    int i=1,pos=0;
    printf("enter the position:");
    scanf("%d",&pos);
    cur=first;
    prev=NULL;
    while(i<pos){
        prev=cur;
        cur=cur->link;
        i++;
    }
    printf("node deleted:%d\n",cur->info);
    prev->link=cur->link;
    free(cur);
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
            case 6:insert_specific();
            break;                      
            case 7:exit(0);
            break;
            case 8:delete_specific();
            break;
            
        }
    }
}