#include<stdio.h>
#include<stdlib.h>

void main(){
    int m,n,*pm,*pn,i;
    pm=&m;
    pn=&n;
    printf("enter the starting number:");
    scanf("%d",&m);
    printf("enter the last number:");
    scanf("%d",&n);
    for(i=*pm;i<=*pn;i++){
        printf("%d\n",i);
    }
}