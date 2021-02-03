//EVALUATE POSTFIX EXPRESSION USING STACK ADT
#include<stdio.h>
#include<conio.h>
#include<string.h>

int evaluatepostfix(char*); 
void push(int*,int);  //stack is of type int because we explicitly convt char to int using ASCII relations
int pop(int*);

#define MAX 100
int stack[100]; //INTEGER STACK NOT CHARACTER STACK
int TOP=-1;

void main()
{
    char postfix[100];
    printf("\nEnter the postfix expression(Elements separated by single spaces):\t");
    gets(postfix);
    int result;
    result = evaluatepostfix(postfix);
    if(result!=-1)
    {
    	printf("\nResult after evaluating postfix expression:\t%d",result);
    }
}
//----------------------------------------------------------------------------------------------
int evaluatepostfix(char* expression)
{
	char op; //operator input
	int i=0,A,B;
	int elem; 
	int tempresult;
	while(expression[i]!='\0')
	{
		int tempdig=0; //to calculate value of number element
		if(expression[i]==' ')
		{
			i++;
		}
		else if(isdigit(expression[i]))
		{   //will work if the numbers have more than one digit
			while(isdigit(expression[i]))
			{
				elem=expression[i]-48; //using ASCII relation !!!IMPPPPPPPPPPP!!!(char to int)
				tempdig=tempdig*10;
                tempdig = tempdig + elem;
                i++;
			}
			//push(stack,expression[i]-48);
			//i++;
			push(stack,tempdig); //pushing int i.e. char already convtd to int
		}
		else if(expression[i]=='+' || expression[i]=='-' ||expression[i]=='/' || expression[i]=='*' || expression[i]=='%')
		{
			if(TOP==-1)
			{
				printf("\nIT IS NOT A POSTFIX EXPRESSION.");
				return -1;
			}
			//A and B were already convtd into int while pushing hence here no need to adjust
            A=pop(stack);
            B=pop(stack);
			op=expression[i];
			i++;
			switch(op)
			{
				case '+':
				    tempresult=B+A;
				    push(stack,tempresult);
				    break;
				case '-':
				    tempresult=B-A;
				    push(stack,tempresult);
				    break;
				case '*':
				    tempresult=B*A;
				    push(stack,tempresult);
				    break;
				case '/':
				    tempresult=B/A;
				    push(stack,tempresult);
				    break;
				case '%':
				    tempresult=B%A;
				    push(stack,tempresult);
				    break;
				default:
				    printf("\nInvalid element found.");
				    break;                    
			}
		}
		else
		{
			printf("\nINVALID EXPRESSION");
			exit(1);
		}
	}
	return pop(stack);
}
//----------------------------------------------------------------------------------------------
void push(int* stk, int num)
{
	if(TOP==MAX-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		TOP=TOP+1;
		stk[TOP]=num;
	}
}
//----------------------------------------------------------------------------------------------
int pop(int* stk)
{
	int temp;
	if(TOP==-1)
	{
		printf("\nSTACK UNDERFLOW (empty stack)");
	}
	else
	{
		temp=stk[TOP];
		TOP=TOP-1;
		return temp;
	}
}

