#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

void main(){
    int *arr,i,n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    printf("enter the elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",(arr+i));
    printf("the array elements are:\n");
    for(i=0;i<n;i++)
    printf("%d",*(arr+i));

}