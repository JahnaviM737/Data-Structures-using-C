//Implement stack or linear queue ADT using linked list

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


struct node *start = NULL;
struct node* add_end(struct node *); //insertion
struct node* del_beg(struct node *); //deletion
struct node* display(struct node *); //display
int peek(struct node *); //peek

int main()
{
	int option,val;
	printf("**************LINEAR QUEUE*************");
	printf("\n***************MAIN MENU***************");
	printf("\n1.Insert an element.");
	printf("\n2.Delete an element.");
	printf("\n3.Peek.");
	printf("\n4.Display the queue.");
	printf("\n5.EXIT");

	top:

	printf("\nYour option:\t");
	scanf("%d",&option);

	switch(option)
	{
		case 1:
		    start = add_end(start);
		    break;
		case 2:
		    start = del_beg(start);
		    break;
		case 3:
            val=peek(start);
            if(val!=-1)
		        printf("\nElement in the front of the queue is:\t%d",val);
		    break;
		case 4:
		    start = display(start);
		    break;
		case 5:
		    exit(0);
		    break;
		default:
		    printf("\nINVALID INPUT.");
		    break;
	}

	goto top;
	return 0;
}

//-----------------------------------------------------------------
//Display queue
struct node* display(struct node *start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
		struct node *ptr;
		ptr=start;
		while(ptr!=NULL) //not ptr->next
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
	return start;
}

//Insertion 
struct node* add_end(struct node *start)
{
	int num;
	struct node *new_node,*ptr;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("\nOut of memory space.");
		exit(0);
	}
	else
	{
		printf("\nEnter value:  ");
		scanf("%d",&num);
		new_node -> data = num;
		new_node -> next = NULL;
		ptr=start;
		if(start==NULL)
		{
			start = new_node;
		}
		else
		{
			while(ptr->next!=NULL)
		    {
			    ptr = ptr -> next;
		    }
		    ptr -> next = new_node;
		}
	}
	return start;
}

//Deletion
struct node* del_beg(struct node *start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
	struct node *ptr;
	ptr=start;
	start=start->next; //NOT ptr=ptr->next
	free(ptr);
	}
	return start;
}

//peek
int peek(struct node * start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
		return -1;
	}
	else
	{
		return start->data;
	}
}