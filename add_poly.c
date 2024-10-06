#include<stdio.h>
#include<math.h>

struct node
{
	int coef, x_exp, y_exp ,z_exp;
	struct node *link;
};

typedef struct node *NODE;
NODE FIRST, SECOND, RESULT;

void display(NODE START)
{
	NODE temp;
	temp=START;
	while(temp!= NULL)
	{
		if(temp->coef<0)
		     printf("%d x^%d y^%d z^%d ",temp->coef,temp->x_exp, temp->y_exp,temp->z_exp);
		else
		      printf("+%dx^%d y^%d z^%d ",temp->coef,temp->x_exp,temp->y_exp,temp->z_exp);
		temp=temp->link;
	}
	printf("\n");
}

void attach (int coef, int x_expo, int y_expo, int z_expo, NODE START) 
{
	NODE temp,cur;
	temp=(NODE)malloc(sizeof(struct node));
	temp->coef =coef;
	temp->x_exp=x_expo;
	temp->y_exp=y_expo;
	temp->z_exp=z_expo;
    if ( START == NULL)
    {
		START=temp;   
        temp->link=NULL;   
        return;
    }
	cur=START;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	temp->link=NULL;
	return;
}

void readpoly(NODE START)
{
	int i=1,coef, x_expo, y_expo, z_expo;
	printf("enter the coefficient as -99 to end the polynomial\n");
	while(1)
	{
		printf("enter the %d term of the polynomial\n", i++);
		printf("enter the coefficient:\n");
		scanf("%d",&coef);
		if(coef==-99)
			break;
		printf("enter the x exponent:\n");
		scanf("%d",&x_expo);
		printf("enter the y exponent:\n");
		scanf("%d",&y_expo);
		printf("enter the z exponent:\n");
		scanf("%d",&z_expo);

		attach(coef,x_expo,y_expo,z_expo,START);
	}
	display(START);
	return;
}

void addpoly( )
{
	NODE A,B;
	int sum;
	A=FIRST;
	B=SECOND;

	while(A!=NULL && B!=NULL)
	{
		if(A->x_exp==B->x_exp)
		{
			if(A->y_exp==B->y_exp)
			{
                if(A->z_exp==B->z_exp)
                {
	                sum=A->coef+B->coef;
	                attach(sum, A->x_exp,A->y_exp,A->z_exp, RESULT);
	                A=A->link;
	                B=B->link;
                }
                else if(A->z_exp>B->z_exp)
                {
	                attach(A->coef, A->x_exp, A->y_exp, A->z_exp, RESULT);
	                A=A->link;
                }
                else
                {
	                attach(B->coef, B->x_exp, B->y_exp, B->z_exp, RESULT);
	                B=B->link;
                }
            }
            else if(A->y_exp>B->y_exp)
            {
	            attach(A->coef, A->x_exp, A->y_exp , A->z_exp, RESULT);
                A=A->link;
            }
            else
            {
	            attach(B->coef, B->x_exp, B->y_exp, B->z_exp, RESULT);
	            B=B->link;
            }
        }
        else if(A->x_exp > B->x_exp)
        {
	        attach(A->coef, A->x_exp, A->y_exp , A->z_exp, RESULT);
            A=A->link;
        }
        else
        {
	        attach(B->coef, B->x_exp, B->y_exp, B->z_exp, RESULT);
	        B=B->link;
        }
    }
    while(A!=NULL)
    {
	    attach(A->coef,A->x_exp,A->y_exp,A->z_exp,RESULT); 
	    A=A->link;
    }
    while(B!=NULL)
    {
	    attach(B->coef,B->x_exp,B->y_exp,B->z_exp,RESULT); 
	    B=B->link;
    }
}

void main()
{
		printf("Enter the first polynomial\n");					
        readpoly(FIRST);

		printf("\nEnter the second polynomial\n"); 				
        readpoly(SECOND);

		printf("\nthe first polynomial is:");	
		display(FIRST);

		printf("\nthe second polynomial is:");	
		display(SECOND);

		addpoly(FIRST,SECOND,RESULT);

		printf("\nthe result of adding two polynomials is:");			
        display(RESULT);
}