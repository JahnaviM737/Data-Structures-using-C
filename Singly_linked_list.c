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
struct node* create_ll(struct node *); 
struct node* display(struct node *);
struct node* add_beg(struct node *);
struct node* add_end(struct node *);
struct node* add_bef(struct node *);
struct node* add_aft(struct node *);
struct node* del_beg(struct node *);
struct node* del_end(struct node *);
struct node* del_val(struct node *);
struct node* del_bef(struct node *);
struct node* del_aft(struct node *);
struct node* del_lst(struct node *);
struct node* sort(struct node *);
int count(struct node *);
struct node* find(struct node*);

int main()
{
	int op,c;
	printf("----MENU----");
	printf("\n1.Create a list.\n2.Display the list.\n3.Add a node at the beginning.\n4.Add a node at the end.");
	printf("\n5.Add a node before a given node.\n6.Add a node after a given node.\n");
	printf("7.Delete a node from the beginning.\n8.Delete a node from the end.");
	printf("\n9.Delete the node with given value.\n10.Delete a node before a given node.\n");
	printf("11.Delete a node after a given node.\n");
	printf("12.Delete the entire list.\n13.Sort the list.\n14.Count.\n15.find\n16.Exit.");
	top:
	printf("\nYour option:  ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			start = create_ll(start);
			break;
		case 2:
			start = display(start);
			break;
		case 3:
		    start = add_beg(start);
			break;
		case 4:
		    start = add_end(start);
			break;
		case 5:
			start = add_bef(start);	
			break;
		case 6:
			start = add_aft(start);
			break;
		case 7:
			start = del_beg(start);
			break;
		case 8:
			start = del_end(start);
			break;
		case 9:
			start = del_val(start);
			break;
		case 10:
		    start = del_bef(start);
			break;
		case 11:
			start = del_aft(start);
			break;
		case 12:
			start = del_lst(start);
		    break;	
		case 13:
		    start = sort(start);
			break;
		case 14:
			c = count(start);
			printf("\nNumber of nodes: %d",c);
			break;
		case 15:
			start = find(start);
			break;
		case 16:
			exit(0);
		    break;
		default:
		    printf("\nINVALID CHOICE.");
	}
	goto top;
}
//---------------------------------------------------------------------------------------------------
//CREATING LINKED LIST
struct node* create_ll(struct node *start)
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
		new_node->data=num;
		new_node->next=NULL;
		if(start==NULL)
		{
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
		}
		printf("Enter value:\t");
		scanf("%d",&num);
    }
    return start;
}
//DISPLAY LINKED LIST
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
//ADD NODE IN THE BEGINING
struct node* add_beg(struct node *start)
{
	int num;
	struct node *new_node;
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
		new_node->data=num;
		new_node->next=start;
		start=new_node;
	}
	return start;
}
//ADD NODE AT THE END
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
//ADD NODE BEFORE A GIVEN NODE
struct node* add_bef(struct node *start)
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
			while(ptr->data!=before && ptr->next!=NULL) //2nd for if node not found
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			if(ptr==start) //means insert at begining case
			{
				new_node->data=num;
				new_node->next=start;
				start=new_node;
			}
			else if(ptr->next == NULL)
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
//ADD NODE AFTER A GIVEN NODE
struct node* add_aft(struct node *start)
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
			while(preptr->data!=after && preptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			if(preptr->data==after && preptr->next==NULL) //insert at end case
			{
				new_node->next=NULL;
				preptr->next=new_node;
			}
			else if(preptr->next==NULL)//reached end but req node not found
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
//DELETE NODE FROM THE BEGINING
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
//DELETE NODE FROM THE END
struct node* del_end(struct node *start)
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
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	}
	return start;
}
//DELETE NODE WITH GIVEN VALUE
struct node* del_val(struct node *start)
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
	while(ptr->data!=val && ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=postptr; //NOTE!!! dont write = pte->next
		postptr=postptr->next;
	}
	if(ptr==start) //first node
	{
		start = del_beg(start);
	}
	else if(ptr->data == val && ptr->next==NULL) //last node
	{
		start = del_end(start);
	}
	else if(ptr->data != val && ptr->next==NULL)
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
//DELETE NODE BEFORE A GIVEN NODE
struct node* del_bef(struct node *start)
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
		while(postptr->data != val && postptr->next != NULL)
		{
			preptr=ptr;
			ptr=postptr;
			postptr=postptr->next;
		}
		if(postptr==start) //delete node before first node but it does not exist
		{
			printf("\nNo node before first node for deletion.");
		}
		else if(postptr->data != val && postptr->next ==NULL)
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
//DELETE NODE AFTER A GIVEN NODE
struct node* del_aft(struct node *start)
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
		while(preptr->data!=val && preptr->next!=NULL)
		{
			preptr=ptr;
			ptr=postptr;
			if(postptr==NULL)
				{continue;}
			postptr=postptr->next;
		}
		if(preptr->data == val && preptr->next==NULL) //delete node after last node which doesnot exist
		{
			printf("\nNo node after last node for deletion.");
		}
		else if(preptr->data != val && preptr->next==NULL)
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
//DELETE ENTIRE LIST
struct node* del_lst(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr = start;
		start = ptr->next;
		free(ptr);
	}
	return start;
}
//SORT LINKED LIST
struct node* sort(struct node *start)
{
	struct node *ptri,*ptrj;
	int temp;
	ptri=start;
	while(ptri->next!=NULL)
	{
		ptrj=ptri->next;
		while(ptrj!=NULL)
		{
			if(ptri->data > ptrj->data)
			{
				temp=ptri->data;
				ptri->data =ptrj->data;
				ptrj->data=temp;
			}
			ptrj=ptrj->next;
		}
		ptri=ptri->next;
	}
	return start;
}
//Count number of nodes
int count(struct node *start)
{
	struct node *ptr;
	int count=0;
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}
//Finding a node
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
		while(ptr!=NULL)
		{
			count++;
			if(ptr->data == val)
			{
				printf("\n%d found at position %d from the start.",val,count);
				c1++;
			}
			ptr=ptr->next;
		}
		if(ptr==NULL && c1==0)
		{
			printf("\n%d was not found in the linked list",val);
		}
		else
		{
			printf("\n%d was found %d times in the linked list",val,c1);
		}
	}
	return start;
}
