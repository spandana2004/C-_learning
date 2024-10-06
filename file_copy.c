#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    FILE *fp1 = fopen("text1.txt", "r");

// Open file to store the result
FILE *fp3 = fopen("file3.txt", "w");
char c;

if (fp1 == NULL || fp3 == NULL)
{
		puts("Could not open files");
		exit(0);
}

// Copy contents of first file to file3.txt
while ((c = fgetc(fp1)) != EOF)
	fputc(c, fp3);

fclose(fp1);
fclose(fp3);
}