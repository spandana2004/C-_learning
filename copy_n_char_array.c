#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mian(){
    char a1[10]="hello",a2[10],*s;
    s=&a1[0];
    int n=strlen(a1), m, i, j;
    printf("enter how many last characters of an array must be copied:");
    scanf("%d",&m);
    for(i=m,j=0;i<n;i++,j++){
        a2[j]=*s;
    }
    printf("%s",a2);
}