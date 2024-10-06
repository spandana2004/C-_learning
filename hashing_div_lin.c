#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record
{
    char name[20];
    int id, flag;
}ht[10];

int hash(int key)
{
    return key%10;
}

void main()
{
    FILE *in;
    int i,j,k,n,id,location;
    char name[20];
    
}