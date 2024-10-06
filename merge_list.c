#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;
NODE f1=NULL,f2=NULL;
int n1,n2;

NODE getnode(){
    NODE ntemp;
    ntemp = (NODE)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&ntemp->info);
    ntemp->link=NULL;
    return ntemp;
}
void insert_rear(NODE *first){
    NODE cur;
    struct node *temp = getnode();
    if(*first==NULL){
        *first=temp;
        temp->link=NULL;
        return;
    }
    else{
        cur=*first;
        while(cur->link != NULL){
            cur=cur->link;
        }
        cur->link=temp;
        temp->link=NULL;
        return;
    }
}

void display(NODE first){
    NODE cur = first;
    while(cur != NULL){
            printf("%d\t",cur->info);
            cur=cur->link;
    }
}

void main(){
    printf("Enter the number of nodes in list1:");
    scanf("%d",&n1);
    printf("Enter the number of nodes in list2:");
    scanf("%d",&n2);
    printf("list1:\n");
    for(int i=0;i<n1;i++){
        insert_rear(&f1);
    }

    printf("list2:\n");
    for(int i=0;i<n2;i++){
        insert_rear(&f2);
    }

    NODE cur=f1;
    while(cur->link != NULL){
        cur=cur->link;
    }
    cur->link=f2;
    n1=n1+n2;

    for(int i=0;i<n1-1;i++){
        NODE cur1=f1;
        NODE cur2=f1->link;
        for(int j=0;j<n1-i-1;j++){
            if(cur2->info < cur1->info){
                int temp=cur1->info;
                cur1->info=cur2->info;
                cur2->info=temp;
            }
            else{
                cur1=cur1->link;
                cur2=cur2->link;
            }
        }
    }

    printf("sorted and meged list:\n");
    display(&f1);
    printf("\n");
}