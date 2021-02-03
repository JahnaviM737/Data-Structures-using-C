//IMPLEMENTING CIRCULAR QUEUE USING ARRAY

#include<stdio.h>
#include<conio.h>

//Declaring global variables
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;

void enQueue(void);
int deQueue(void);
int peek(void);
int peekrear(void);
int avail(void);
void search(void);
void display(void);

int main()
{
	int option,val;
	printf("************CIRCULAR QUEUE*************");
	printf("***************MAIN MENU***************");
	printf("\n1.Insert an element.(ENQUEUE)");
	printf("\n2.Delete an element.(DEQUEUE)");
	printf("\n3.Peek front.");
	printf("\n4.Peek rear.");
	printf("\n5.Display the queue.");
	printf("\n6.Spaces available.");
	printf("\n7.Search.");
	printf("\n8.EXIT");

	top:

	printf("\nYour option:\t");
	scanf("%d",&option);

	switch(option)
	{
		case 1:
		    enQueue();
		    break;
		case 2:
		    val=deQueue();
		    if(val!=-1)
		        printf("\nElement deleted:\t%d",val);
		    break;
		case 3:
            val=peek();
            if(val!=-1)
		        printf("\nElement in the front of the queue is:\t%d",val);
		    break;
		case 4:
		    val=peekrear();
		    if(val!=-1)
		        printf("\nElement in the rear of the queue is:\t%d",val);
		    break;
		case 5:
		    display();
		    break;
		case 6:
			val=avail();
			printf("\n%d spaces are available.",val);
			break;
		case 7:
		    search();
			break;	
		case 8:
		    exit(0);
		    break;
		default:
		    printf("\nINVALID INPUT.");
		    break;
	}

	goto top;
	return 0;
}
//-----------------------------------------------------------------------------------------
//INSERT OR ENQUEUE
void enQueue(void)
{
	int val;
	if((front==0 && rear==MAX-1)||(rear==front-1))
	{
		printf("\nQueue is full.");//OVERFLOW
	}
	else
	{
		printf("\nEnter an integer you wish to insert:\t");
		scanf("%d",&val);
		if(front==-1 && rear==-1)
		{
			front=rear=0;//EMPTY QUEUE
		}
		else if(rear==MAX-1 && front!=0)
		{
			rear=0;
		}
		else
		{
			rear=rear+1;
		}
		queue[rear]=val;
	}
}
//DELETE OR DEQUEUE
int deQueue(void)
{
	int val;
	if(front==-1 && rear==-1)  //EMPTY
	{
		printf("\nQueue is already empty.");
		return -1;
	}
	else
	{
		val=queue[front];
		if(front==MAX-1)
		{
			front=0;
		}
		else
		{
			front=front+1;
		}
		return val;
	}
}
//PEEK
int peek(void)
{
	int val;
	if(front==-1 && rear==-1)  //EMPTY
	{
		printf("\nQueue is empty.");
		return -1;
	}
	else
	{
		val=queue[front];
		return val;
	}
}
//PEAKREAR
int peekrear(void)
{
	int val;
	if(front==-1 && rear==-1)  //EMPTY
	{
		printf("\nQueue is empty.");
		return -1;
	}
	else
	{
		val=queue[rear];
		return val;
	}
}
//AVAILABLE
int avail(void)
{
	int val;
	if(front<rear)
	{
		val=(MAX-1-rear)+(front);
	}
	else
	{
		val=rear-front-1;
	}
	return val;
}
//SEARCH
void search(void)
{
	int num,i;
	if(front==-1 && rear==-1)  //EMPTY
	{
		printf("\nQueue is empty.");
	}
	else
	{
		printf("\nEnter the value you want to search.");
		scanf("%d",&num);
		if(front<rear)
	    {
		    for(i=front;i<=rear;i++)
		    {
			    if(queue[i]==num)
			    {
			    	printf("\n%d is present at index %d and position %d",num,i,i+1);
			    }
		    }
	    }
	    else //rear<front
	    {
		    for(i=front;i<=MAX-1;i++)
			    {
			    	if(queue[i]==num)
			        {
			    	    printf("\n%d is present at position %d",num,i);
			        }
			    }
		    for(i=0;i<=rear;i++)
			    {
			    	if(queue[i]==num)
			        {
			    	    printf("\n%d is present at position %d",num,i);
			        }
			    }
	    }

	}
}
//DISPLAY
void display(void)
{
	int i;
	if(front==-1 && rear==-1)  //EMPTY
	{
		printf("\nQueue is empty.");
	}
	else if(front<rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
	else //rear<front
	{
		for(i=front;i<=MAX-1;i++)
			printf("%d\t",queue[i]);
		for(i=0;i<=rear;i++)
			printf("%d\t",queue[i]);
	}
}
