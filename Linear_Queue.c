//IMPLEMENTING LINEAR QUEUE USING ARRAY

#include<stdio.h>
#include<conio.h>

//Declaring global variables
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

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
		    insert();
		    break;
		case 2:
		    val=delete_element();
		    if(val!=-1)
		        printf("\nElement deleted:\t%d",val);
		    break;
		case 3:
            val=peek();
            if(val!=-1)
		        printf("\nElement in the front of the queue is:\t%d",val);
		    break;
		case 4:
		    display();
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
//-----------------------------------------------------------------------------------------------------------
 //INSERTION
void insert(void)
{
	int num;
	if(rear==MAX-1)
		printf("\nQUEUE IS FULL(OVERFLOW CONDITION)");
	else 
	{
	printf("\nEnter the element you wish to insert:\t");
    scanf("%d",&num);
	if(front==-1 && rear==-1)
		{
			//EMPTY QUEUE
			front=0;
            rear=0;
        }
    else
    {
    	rear=rear+1;
	}
    } 
    
    queue[rear]=num;
}

//DELETION
int delete_element(void)
{
	int val;
	if(front==-1 || front>rear)
	{
		printf("\nQUEUE IS EMPTY.(UNDERFLOW)");
		return -1;
	}
	else
	{
		val=queue[front];
		front=front+1;
	}
	return val;
}

//PEEK-RETURN ELEMENT AT FRONT
int peek(void)
{
	if(front==-1 || front>rear)
		{
			printf("\nQUEUE IS EMPTY.");
			return -1;
		}	
    else
    {
    	return queue[front];
    }
}

//DISPLAY
void display(void)
{
	int i;
	printf("\n");
	if(front==-1 || front>rear)
		printf("\nQUEUE IS EMPTY.");
    else
    {
    	for(i=front;i<=rear;i++)
    		printf("%d\t",queue[i]);
    }


}

