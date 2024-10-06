#include <stdio.h>
#include <string.h>
int i, j, flag, max;
char s[70], p[50];
int patern_match();

void main()
{
    int a;
    a = patern_match();
    if (a == -1)
    {
        printf("The entered patern not found\n");
    }
    else
        printf("The entered patern found from position %d\n", a + 1);
}

int patern_match()
{
    printf("Enter the main string: \n");
    gets(s);
    printf("Enter the patern: \n");
    gets(p);
    int LS = strlen(s);
    int LP = strlen(p);
    max = LS - LP + 1;
    for (i = 0; i <= max; i++)
    {
        flag = 1;
        for (j = 0; j < LP && flag == 1; j++)
        {
            if (p[j] != s[j + i])
            {
                flag = 0;
            }
            if (flag == 1)
            {
                return i;
            }
        }
    }
    return -1;
}