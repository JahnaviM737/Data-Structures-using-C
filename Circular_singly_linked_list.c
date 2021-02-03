//Circular Singly Linked List

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
struct node *create_cll(struct node *);
struct node *display_cll(struct node *);
struct node* insert_beg(struct node *);
struct node* insert_end(struct node *);
struct node* insert_bef(struct node *);
struct node* insert_aft(struct node *);
struct node* delete_beg(struct node *);
struct node* delete_end(struct node *);
struct node* delete_val(struct node *);
struct node* delete_bef(struct node *);
struct node* delete_aft(struct node *);
struct node* delete_lst(struct node *);
int count(struct node *);
struct node* find(struct node*);

int main()
{
	int op,c;
	printf("---------MENU--------");
	printf("\n1.Create circlular linked list.\n2.Display circular linked list.");
	printf("\n3.Insert node at begining.\n4.Insert node at end.");
	printf("\n5.Insert a node before a given node.\n6.Insert a node after a given node.\n");
	printf("7.Delete a node from the beginning.\n8.Delete a node from the end.");
	printf("\n9.Delete the node with given value.\n10.Delete a node before a given node.\n");
	printf("11.Delete a node after a given node.\n");
	printf("12.Delete the entire list.\n13.Count.\n14.find\n15.Exit.");

	top:
	printf("\nYour choice:  ");
	scanf("%d",&op);

	switch(op)
	{
		case 1:
			start = create_cll(start);
			break;
		case 2:
			start = display_cll(start);	
			break;
		case 3:
		    start = insert_beg(start);
		    break;
		case 4:
		    start = insert_end(start); 
		    break;
		case 5:
			start = insert_bef(start);	
			break;
		case 6:
			start = insert_aft(start);
			break;   
		case 7:
			start = delete_beg(start);
			break;
		case 8:
			start = delete_end(start);
			break;
		case 9:
			start = delete_val(start);
			break;
		case 10:
		    start = delete_bef(start);
			break;
		case 11:
			start = delete_aft(start);
			break;
		case 12:
			start = delete_lst(start);
		    break;	
		case 13:
			c = count(start);
			printf("\nNumber of nodes: %d",c);
			break;
		case 14:
			start = find(start);
			break;
		case 15:
			exit(0);
		    break;	  	
		default:
			printf("\nINVALID CHOICE.");
			break;
	}
	goto top;
	return 0;
}
//--------------------------------------------------------------------------------------------------
//Creating circular linked list
struct node *create_cll(struct node *start)
{
	int num;
	struct node *new_node,*ptr;
	printf("\nEnter -1 to stop creating the list.");
	printf("\nEnter value:\t");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		if(new_node==NULL)
		{
			printf("\nOut of memory space.");
			exit(0);
		}
		else
		{
			new_node->data = num;
			if(start == NULL)
			{
				start = new_node;
				new_node->next=start;
			}
			else
			{
				ptr = start;
				while(ptr->next!=start)
				{
					ptr=ptr->next;
				}
				ptr->next=new_node;
				new_node->next=start;
			}
		}
		printf("Enter value:\t");
		scanf("%d",&num);
	}
	return start;
}
//Displaying circular linked list
struct node *display_cll(struct node *start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
		struct node *ptr;
		ptr=start;
		while(ptr->next!=start) 
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\t",ptr->data); //NOTE ADDITIONAL STEP!!!!!!!!!!!!!!!!!!!
	}
	return start;
}
//Insert node at the begining
struct node* insert_beg(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("\nOUT OF MEMORY SPACE.");
		exit(0);
	}
	else
	{
		printf("\nEnter value:  ");
		scanf("%d",&num);
		new_node -> data = num;
		ptr = start;
		while(ptr->next!=start)
		{
			ptr = ptr->next;
		}
		ptr->next=new_node;
		new_node->next = start;
		start = new_node;
	}
	return start;
}
//Insert node at the end
struct node* insert_end(struct node *start)
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
		ptr=start;
		if(start==NULL)
		{
			start = new_node;
		}
		else
		{
			while(ptr->next!=start)
		    {
			    ptr = ptr -> next;
		    }
		    ptr -> next = new_node;
		    new_node -> next = start;
		}
	}
	return start;
}

//Add a node before a given node
struct node* insert_bef(struct node * start)
{
	int num,before;
	struct node *new_node, *ptr, *preptr;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("\nOut of memory space.");
		exit(0);
	}
	else
	{
		ptr=start;
		if(start==NULL)
		{
			printf("EMPTY LIST.");
		}
		else
		{
			printf("\nEnter value to add:  ");
			scanf("%d",&num);
			printf("\nEnter value before which new node is to be added:  ");
			scanf("%d",&before);
			new_node -> data = num;
			while(ptr->data!=before && ptr->next!=start) //2nd for if node not found
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			if(ptr==start) //means insert at begining case
			{
				new_node->data=num;
				new_node->next=start;
				start -> next = new_node; //
				start=new_node;
			}
			else if(ptr->next == start)
			{
				printf("\nNode before which value is to be added was not found.");
			}
			else
			{
				preptr -> next = new_node;
			    new_node -> next = ptr;
			}
		}
	}
	return start;
}

//Add a node after a given node
struct node* insert_aft(struct node * start)
{
	int num,after;
	struct node *new_node,*ptr,*preptr;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("\nOut of memory space.");
		exit(0);
	}
	else
	{
		ptr=start;
		if(start==NULL)
		{
			printf("EMPTY LIST.");
		}
		else
		{
			printf("\nEnter value to add:  ");
			scanf("%d",&num);
			printf("\nEnter value after which new node is to be added:  ");
			scanf("%d",&after);
			new_node -> data = num;
			preptr=ptr; //VVIMPPP!!!!!!!!!!!!!!!!!
			while(preptr->data!=after && preptr->next!=start)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			if(preptr->data==after && preptr->next==start) //insert at end case
			{
				new_node->next=start;
				preptr->next=new_node;
			}
			else if(preptr->next==start)//reached end but req node not found
			{
				printf("\nNode after which value is to be added was not found.");
			}
			else
			{
				new_node->next=ptr;
				preptr->next=new_node;
			}
		}
	}
	return start;
}

//Delete node from beginning
struct node* delete_beg(struct node * start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
	struct node *ptr;
	ptr = start;
	while(ptr->next!=start)
	{
		ptr = ptr -> next;
	}
	ptr -> next = start -> next;
	ptr = start;
	start = start -> next;
	free(ptr);
	}
	return start;
}
//Delete node from end
struct node* delete_end(struct node * start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=ptr;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=start;
	free(ptr);
	}
	return start;
}
//Delete node with given value
struct node* delete_val(struct node * start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
	int val;
	struct node *preptr,*ptr,*postptr;
	printf("\nEnter the value you wish to delete: ");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	postptr=start->next;
	while(ptr->data!=val && ptr->next!=start)
	{
		preptr=ptr;
		ptr=postptr; //NOTE!!! dont write = ptr->next
		postptr=postptr->next;
	}
	if(ptr==start) //first node
	{
		start = delete_beg(start);
	}
	else if(ptr->data == val && ptr->next==start) //last node
	{
		start = delete_end(start);
	}
	else if(ptr->data != val && ptr->next==start)
	{
		printf("\nNode with entered value not found.");
	}
	else
	{
		preptr->next = postptr;
		free(ptr);
	}
	}
	
	return start;
}
//Delete a node before a node with given value
struct node* delete_bef(struct node * start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
		int val;
		struct node *preptr,*ptr,*postptr;
		printf("\nEnter the value before which you wish to delete a node: ");
		scanf("%d",&val);
		postptr=start;
		ptr=NULL;    //NOTE
		preptr=NULL; //NOTE
		while(postptr->data != val && postptr->next != start)
		{
			preptr=ptr;
			ptr=postptr;
			postptr=postptr->next;
		}
		if(postptr==start) //delete node before first node that is last node
		{
			start = delete_end(start);
		}
		else if(postptr->data != val && postptr->next == start)
		{
			printf("\nNode with entered value not found.");
		}
		else
		{
			preptr->next=postptr;
			free(ptr);
		}
	}
	return start;
}
//Delete a node after a node with given value
struct node* delete_aft(struct node * start)
{
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
		int val;
		struct node *preptr,*ptr,*postptr;
		printf("\nEnter the value after which you wish to delete a node: ");
		scanf("%d",&val);
		preptr=start;      //NOTE
		ptr=start->next;   //NOTE
		postptr=ptr->next; //NOTE
		while(preptr->data!=val && preptr->next!=start)
		{
			preptr=ptr;
			ptr=postptr;
			postptr=postptr->next;
		}
		if(preptr->data == val && preptr->next==start) //delete node after last node that is 1st node
		{
			start = delete_beg(start);
		}
		else if(preptr->data != val && preptr->next==start)
		{
			printf("\nDesired node not found.");
		}
		else
		{
			preptr->next=postptr;
			free(ptr);
		}
	}
	return start;
}
//Delete entire list
struct node* delete_lst(struct node * start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr = start;
		start = ptr->next;
		free(ptr);
	}
	ptr = start;
    start = NULL;
    free(ptr);
	return start;
}
//Count the number of nodes
int count(struct node * start)
{
	struct node *ptr;
	int count=0;
	ptr=start;
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
		return 0;
	}
	else
	{
		while(ptr->next!=start)
	    {
		    count++;
		    ptr=ptr->next;
	    }
	    count++;
	    return count;
	}
}
//Find a node with given value
struct node* find(struct node* start)
{
	struct node *ptr;
	ptr=start;
	int val,count=0,c1=0;
	if(start==NULL)
	{
		printf("\nLINKED LIST IS EMPTY.");
	}
	else
	{
		printf("\nEnter the value to find: ");
		scanf("%d",&val);
		while(ptr -> next != start )
		{
			count++;
			if(ptr->data == val)
			{
				printf("\n%d found at position %d from the start.",val,count);
				c1++;
			}
			ptr=ptr->next;
		}
		if(ptr->next==start) //last node tested separately
		{
			count++;
			if(ptr->data == val)
			{
				printf("\n%d found at position %d from the start.",val,count);
				c1++;
			}
			else if(c1==0)
			{
				printf("\n%d was not found in the linked list",val);
			}
		}
		else
		{
			printf("\n%d was found %d times in the linked list",val,c1);
		}
	}
	return start;
}
