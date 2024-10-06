#include<stdio.h>

void main(){
    int arr[10],n,*ptr,i;
    printf("enter the number of elements of array:");
    scanf("%d",&n);
    printf("enter the elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int sum = 0;
    for(i=0;i<n;i++){
        ptr=&arr[i];
        sum = sum + *ptr;
    }
    printf("sum=%d\n",sum);
}