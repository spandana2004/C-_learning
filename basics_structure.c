#include<stdio.h>
struct Student
{
    int usn;
    char name[10];
    float fee;
    int m1,m2,m3;
    int total;
    int per;
};
void main(){
    struct Student s[3];
    int i;
    for(i=0;i<3;i++){
    printf("enter the name of the student:");
    gets(s[i].name);
    printf("enter the usn:");
    scanf("%d",&s[i].usn);
    }
}