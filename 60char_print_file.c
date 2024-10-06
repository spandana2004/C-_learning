#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    FILE *fp;
    int i;
    char s[10],scopy[10];
    fp=fopen("text1.txt","w");
    printf("enter the string:");
    fgets(s,10,stdin);
    strcpy(scopy,s);
    fputs(scopy,fp);
    fclose(fp);
}