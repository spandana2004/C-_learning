#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int info;
    struct Node *lchild, *rchild;
};

typedef struct Node* NODE;
NODE root=NULL;

void insert(int ele){
    NODE newn=(NODE)malloc(sizeof(struct Node));
    newn->info=ele;

    if(root==NULL){
        root=newn;
        return;
    }

    NODE cur=root,prev;
    while(cur!=NULL){
        prev=cur;
        if(ele < cur->info){
            cur=cur->lchild;
        }
        else
            cur=cur->rchild;
    }

    if(ele < prev->info){
        prev->lchild=newn;
    }
    else
        prev->rchild=newn;
}

void preorder(NODE root){
    if(root==NULL)
    {
        printf("Empty tree\n");
        return;
    }

    printf("%d ",root->info);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(NODE root){
    if(root==NULL)
    {
        printf("Empty tree\n");
        return;
    }

    inorder(root->lchild);
    printf("%d ",root->info);
    inorder(root->rchild);
}

void postorder(NODE root){
    if(root==NULL)
    {
        printf("Empty tree\n");
        return;
    }

    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->info);
}

void search(int ele){
    NODE cur=root;
    while(cur!=NULL){
        if(cur->info == ele)
            break;  
        
        if(ele < cur->info)
            cur=cur->lchild;
        else
            cur=cur->rchild;
    }

    if(cur!=NULL)
        printf("search successful\n");
    else
        printf("Element not found\n");
}

void min(NODE root){
    if(root==NULL){
        printf("Empty tree\n");
        return;
    }

    NODE cur=root;
    while(cur->lchild != NULL){
        cur=cur->lchild;
    }
    printf("MIN:%d\n",cur->info);
}

void man(NODE root){
    if(root==NULL){
        printf("Empty tree\n");
        return;
    }

    NODE cur=root;
    while(cur->rchild != NULL){
        cur=cur->rchild;
    }
    printf("MAX:%d\n",cur->info);
}

void display(NODE root,int level){
    int i;
    if(root){
        display(root->rchild,level+1);
        printf("\n");
        for(i=0;i<level;i++){
            printf("\t");
        }
        printf("%d",root->info);
        dispaly(root->lchild,level+1);
    }
    return;
}

void main(){
    int ch,ele,n;

    while(1){
        printf("1.create\n2.preorder\n3.inorder\n4.postorder\n5.search\n6.min\n7.max\n8.display\n9.display\nenter your choice:");
        switch(ch){
            case 1:
                printf("enter the no. of nodes:");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    printf("enter the element:");
                    scanf("%d",&ele);
                    insert(ele);
                }
            break;

            case 2:
        }
    }
}