#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node* link;
};

typedef struct Node* node;
node f1=NULL;
node f2=NULL;

node getnode(){
    node newnode = (node)malloc(sizeof(struct Node));
    printf("enter element:");
    scanf("%d",&newnode->info);
    newnode->link=NULL;
    return newnode;
}

void insert_rear(node *first){
    node cur;
    struct Node *temp = getnode();
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
void display(node f){
    node cur = f;
    while(cur != NULL){
            printf("%d\t",cur->info);
            cur=cur->link;
    }
}

void main(){
    int n1,n2,i;
    printf("enter the no of elements of node 1:\n");
    scanf("%d",&n1);
    printf("enter the no of elements of node 2:\n");
    scanf("%d",&n2);

    printf("enter the elements of node1:\n");
    for(i=0;i<n1;i++){
        insert_rear(&f1);
    }

    printf("enter the elements of node2:\n");
    for(i=0;i<n1;i++){
        insert_rear(&f2);
    }

/*     printf("Node1:");
    display(&f1);
    printf("Node2:");
    display(&f2);
 */
    node cur=f1;
    while(cur->link != NULL){
        cur=cur->link;
    }
    cur->link=f2;
    int n = n1 + n2;

    node ncur = f1;
    node next = ncur->link;
    int temp;

    while(next->link != NULL){
        if(ncur->info < next->info){
            temp=ncur->info;
            ncur->info=next->info;
            next->info=temp;
        }
        else{
            ncur=ncur->link;
            next=next->link;
        }
    }

    printf("merged list:\n");
    display(&f1);
    return;    
}