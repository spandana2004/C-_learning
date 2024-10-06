#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
//include<calloc.h>
void main(){
    char *s1,*s2;
    int n;

    s1=(char *)malloc(10);
    strcpy(s1,"Hello");
    printf("%s\n",s1);
    s2=(char*)calloc(10,sizeof(char));
    strcpy(s2,"welcom");
    printf("%s\n",s2);
    s1 = realloc(s1,15*sizeof(char));
    strcat(s1,".world");
    printf("%s\n",s1);
    s2 = (char*)realloc(s2,15);
    strcat(s2,".here");
    printf("%s\n",s2);
}