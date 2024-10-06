#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    FILE *fp;
    int count=0;
    fp=fopen("text1.txt","r");
    printf("reading...\n");
    char ch = fgetc(fp);
    while(ch != EOF){
        count++;
        ch = fgetc(fp);
    }
    //printf("the charcters in the file is:");
    printf("the number of characters:%d",count);
    fclose(fp);
}