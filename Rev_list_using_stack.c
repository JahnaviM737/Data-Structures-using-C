//WAP to reverse a list using stack

#include<stdio.h>
#include<conio.h>

void push(int*,int);
int pop(int*);
display(int*,int);

#define MAX 20
int stack[20],list[20],revlist[20];
int TOP=-1;

void main()
{
	int i,n;
	printf("Enter the number of elements in the list:\t");
	scanf("%d",&n);
	printf("\nEnter array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
		push(stack,list[i]);
	}
	for(i=0;i<n;i++)
	{
		revlist[i]=pop(stack);
	}

	printf("\nEntered list:\t");
	display(list,n);
	printf("\n\nReversed list:\t");
	display(revlist,n);

}
//------------------------------------------------------------------
void push(int stk[20],int p)
{
    if(TOP==MAX-1)
    	printf("\nSTACK IS FULL!(OVERFLOW)");
    else
    	{
    		TOP=TOP+1;
    		stk[TOP]=p;
    	}
}
int pop(int stk[20])
{   
	int temp;
    if(TOP==-1)
    	printf("\nSTACK IS EMPTY!(UNDERFLOW)");
    else
    	{
    		temp=stk[TOP];
    		TOP=TOP-1;
    		return temp;
    	}
}
display(int stk[20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d  ",stk[i]);
	}
}
