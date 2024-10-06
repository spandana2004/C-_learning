#include<stdio.h>
#include<stdlib.h>
void main(){
    FILE *fp;
    fpos_t pos;
    fp=fopen("text1.txt","w");
    fgetpos(fp,&pos);
    fputs("america",fp);
    fsetpos(fp,&pos);
    fputs("india",fp);
    fclose(fp);
}