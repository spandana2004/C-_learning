#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX 10
int top=-1,front=0;
int stack[MAX];
void push(char);
void pop();

void main(){
    int i,choice;
    char s[MAX],b;
    while(1){
        printf("1-enter string\n2-exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter the string\n");
            scanf("%s",s);
            for(i=0; s[i] != '\0'; i++){
                b=s[i];
                push(b);
            }
            for(i=0;i<(strlen(s)/2);i++){
                if(stack[top]==stack[front]){
                    pop();
                    front++;
                }
                else{
                    printf("%s is not a palindrome\n",s);
                    break;
                }
            }
            if((strlen(s)/2)==front)
            printf("%s is not a palindrome\n",s);
            front=0;
            top=-1;
            break;

            case 2:
            exit(0);

            default:
            printf("enter crt choice\n");
        }
    
    }
}

void push(char a){
    top++;
    stack[top]=a;
}

void pop(){
    top--;
}