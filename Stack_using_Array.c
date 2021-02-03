#include<stdio.h>
#include<conio.h>

#define MAX 10
int TOP=-1;
int stack[MAX];

void push();
int pop();
int peek();
int size();
char isEmpty();
char isFull();
void display();

int main()
{
	int option,val;
	char v;
	printf("******MAIN MENU******");
	printf("\n1.Push()\n2.Pop()\n3.Peek\n4.Size\n5.isEmpty()\n6.isFull()\n7.Display()\n8.Exit");

    top:

	printf("\nYour option:\t");
	scanf("%d",&option);

	switch(option)
	{
		case 1:
		    push();
		    break;
		case 2:
		    val=pop();
		    if(val!=-1)
		    	printf("\nValue removed from top of stack: %d",val);
		    break;
		case 3:
		    val=peek();
		    if(val!=-1)
		    	printf("\nValue at the top of stack is:%d",val);
		    break;
		case 4:
		    val=size();
		    if(val==-1)
		    	{printf("\nStack is empty.");}
		    else
		    	{printf("\n Size is: %d",val);}
		    break;
		case 5:
		    v=isEmpty();
		    if(v=='T')
		    	printf("\nSTACK IS EMPTY.");
		    else
		    	printf("\nStack is not empty.");
		    break;
		case 6:
		    v=isFull();
		    if(v=='T')
		    	printf("\nSTACK IS FULL.");
		    else
		    	printf("\nStack is not full.");
		    break;
		case 7:
		    display();
		    break;
		case 8:
		    exit(0);
		    break;
		default:
		    printf("\nInvalid Input");
		    break;
	}
	goto top;
	return 0;
}
//-----------------------------------------------------------------------------------------

void push()
{
	if(TOP==MAX-1)
		printf("\nOVERFLOW");
	else
	{
		int num;
		printf("\nEnter element you want to add:\t");
		scanf("%d",&num);
		TOP=TOP+1;
		stack[TOP]=num;
	}
}
//************************************************************
int pop()
{
	int val;
	if(TOP==-1)
	{
		printf("\nUNDERFLOW.");
		return -1;
	}
	else
	{
		val=stack[TOP];
		TOP=TOP-1;
		return val;//Return value always at the end coz after return, statements not executed.
	}
}

//************************************************

int peek()
{
	if(TOP==-1)
	{
		printf("\nUNDERFLOW.");
		return -1;
	}
	else
	{
		return stack[TOP];
	}
}

//*************************************************

int size()
{
	if(TOP==-1)
		{return -1;}
	else
	{
		int temp;
		temp = TOP +1;
		return temp;
	}
}

//******************************************************

char isEmpty()
{
    if(TOP==-1)
    	return 'T';
    else
    	return 'F';
}

//******************************************************

char isFull()
{
	if(TOP==MAX-1)
    	return 'T';
    else
    	return 'F';
}

//**********************************************************

void display()
{
    if(TOP==-1)
    	printf("\nSTACK IS EMPTY");
    else
    	{
    		int i;
    		for(i=0;i<=TOP;i++)
    			printf("%d\t",stack[i]);
    	}	
}
