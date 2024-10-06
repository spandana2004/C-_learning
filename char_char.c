#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    FILE *fp;
    char str[10],var;
    int i;
    fp=fopen("text1.txt","w");
    printf("enter the string:");
    gets(str);
    for(i=0;i<strlen(str);i++)
    fscanf(fp,"%c",str[i]);
    printf("the string in file: ");
    for(i=0;i<strlen(str);i++)
    {
        var=fputc(str[i],fp);
        printf("%c",var);
    }
    fclose(fp);
}