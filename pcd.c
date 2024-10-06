#include<stdio.h>
#include<conio.h>
void main(){
int c;
int cpcd;
printf("enter the PCD Details as follows:\n1. 6inch-M8\n2. 8inch-M12\n3. 12inch-M8\n4. 16inch-M12\n5. 22inch-M12\n6. 900mm-M12\n7. 1200mm-M12\n");
scanf("%d",&c);
int ta2, ts2, ta6, ts6, ta8, ts8, ta10_1, ts10_1, ta10_2, ts10_2, ta16, ts16;
ta2 = 0x03;
ts2 = 0x0F;
ta6 = 0x0F;
ts6 = 0x0F;
ta8 = 0x0F;
ts8 = 0x3F;
ta10_1 = 0x0F;
ts10_1 = 0x1F;
ta10_2 = 0x0F;
ts10_2 = 0x7F;
ta16 = 0x1A;
ts16 = 0xC0;

switch(c){
    case 1:
        cpcd = 0x01;
        break;
    case 2:
        cpcd = 0x02;
        break;
    case 3:
        cpcd = 0x04;
        break; 
    case 4:
        cpcd = 0x08;
        break;
    case 5:
        cpcd = 0x10;
        break;
    case 6:
        cpcd = 0x20;
        break;
    case 7:
        cpcd = 0x40;
        break;
    default:
        printf("None of the shakkers are available as per your choice!!\n");
        exit(0);                
}
int check = 0;
switch(shaker[i]){
    case 2:
    check = ta2 & cpcd;
    break;
    case 6:
    check = ta6 & cpcd;
    break;
    case 8:
    check = ta8 & cpcd;
    break;
    case 11:
    check = ta10_1 & cpcd;
    break;
    case 12:
    check = ta10_2 & cpcd;
    break;
    case 16:
    check = ta16 & cpcd;
    break;              
}

if(check == 1){
    printf("%d\n",shaker[i]);
}
}