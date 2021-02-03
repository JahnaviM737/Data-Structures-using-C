//Implement stack using linked list

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

struct stack * top = NULL;
struct stack * Push(struct stack *);
struct stack * Pop(struct stack *);
int peek(struct stack *);
int size(struct stack *);
void Display(struct stack *);

int main()
{
	int option,val;
	printf("******MAIN MENU******");
	printf("\n1.Push\n2.Pop\n3.Peek\n4.Size\n5.Display\n6.Exit");

	top:

	printf("\nYour option:\t");
	scanf("%d",&option);

	switch(option)
	{
		case 1:
		    top = Push(top);
		    break;
		case 2:
		    top = Pop(top);
		    break;
		case 3:
		    val = peek(top);
		    if(val!=-1)
		    	printf("\nValue at the top of stack is:%d",val);
		    break;
		case 4:
		    val = size(top);
		    if(val==-1)
		    	{printf("\nStack is empty.");}
		    else
		    	{printf("\nSize is: %d",val);}
		    break;
		case 5:
		    Display(top);
		    break;
		case 6:
		    exit(0);
		    break;
		default:
		    printf("\nInvalid Input");
		    break;
	}
	goto top;
	return 0;
}

//--------------------------------------------------------------------------------------

//PUSH
struct stack * Push(struct stack * top)
{
	int num;
	struct stack *new_node;
	new_node = (struct stack*)malloc(sizeof(struct stack));
	if(new_node==NULL)
	{
		printf("\nOut of memory space.");
		exit(0);
	}
	else
	{
		printf("\nEnter value:  ");
		scanf("%d",&num);
		if(top==NULL)
		{
			new_node -> data = num;
			top = new_node;
			new_node -> next =NULL;
		}
		else
		{
			new_node -> data = num;
		    new_node -> next = top;
		    top = new_node;	
		}
	}
	return top;
}

//POP
struct stack * Pop(struct stack * top)
{
	int temp=-1;
	if(top==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
	struct stack  *ptr;
	ptr = top;
	temp = ptr -> data;
	top = top -> next;
	free(ptr);
	printf("\nValue removed from top of stack: %d",temp);
	}
	return top;
}

//PEEK
int peek(struct stack * top)
{
	int temp=-1;
	if(top==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
	temp = top -> data;
	}
	return temp;
}

//SIZE
int size(struct stack * top)
{
	int count=0;
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		struct stack *ptr;
		ptr = top;
		while(ptr !=NULL)
		{
			count++;
			ptr = ptr -> next;
		}
		return count;
	}
}

//DISPLAY
void Display(struct stack * top)
{
	if(top==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
		struct stack *ptr;
		ptr = top;
		while(ptr != NULL)
		{
			printf("%d  " , ptr -> data );
			ptr = ptr -> next;
		}
	}
}
