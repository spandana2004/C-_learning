#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int s[30],top=-1,op1,op2,res,i;
char symbol,postfix[20];

void push(int item){
    top=top+1;
    s[top]=item;
    return;
}

int pop()
{
    int item;
    item=s[top];
    top=top-1;
    return item;
}

void main()
{
    printf("enter valid postfix exp:");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++){
        symbol=postfix[i];
        if(isdigit(symbol)){
            push(symbol - '0');
        }
        else{
            op2=pop();
            op1=pop();
            switch(symbol){
                case '+':push(op1+op2);
                break;
                case '-':push(op1-op2);
                break;
                case '*':push(op1*op2);
                break;
                case '/':push(op1/op2);
                break;
                case '^':
                case '$':push(pow(op1,op2));
                break;
                default:printf("invalid operator\n");
            }
        }

    }
    res=pop();
    printf("result:%d\n",res);
}