#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *fp;
    char name[10];
    printf("enter the text:");
    gets(name);
    fp=fopen("text1.txt","w");
    fprintf(fp,"Text is %s",name);
    fclose(fp);
}