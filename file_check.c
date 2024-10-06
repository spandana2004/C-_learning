#include<stdio.h>
#include<stdlib.h>

void main(){
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("text1.txt","r");
    fp2=fopen("text2.txt","r");
    int check=0;
    char c1=fgetc(fp1),c2=fgetc(fp2);
    while((c1!=EOF))
    {
        if(c1 == c2)
        {
            check=1;
            break;
        }
        c1=fgetc(fp1),c2=fgetc(fp2);
    }
    if(check == 1)
    {
        printf("files identical");
    }
    else
    printf("files not identical");
}
