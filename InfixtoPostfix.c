//1 stack and 2 arrays of characters

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100
char stack[MAX];  // for operators and parenthesis
int TOP=-1;

void push(char stack[], char);
char pop(char stack[]);
void InfixtoPostfix(char source[],char target[]); //infix-source & postfix-destination
int getpriority(char);

int main()
{
	char infix[100],postfix[100];
	//clrscr();
	printf("\nEnter any infix expression:\t");
	gets(infix);
	strcpy(postfix,""); //Initialize postfix with null to remove garbage values
	InfixtoPostfix(infix,postfix);
	printf("\nThe corresponding postfix expression is:\t");
	puts(postfix);
	getch();
	return 0;
}

//INFIX expression can have three types of characters: operators(+,-,/,*,%) , ( , ) , operands(A,B..)
void InfixtoPostfix(char source[], char target[])
{
	int i=0,j=0;
	char temp;
	strcpy(target,""); //initialize target with null to remove garbage values if any
	while(source[i]!='\0')
	{
		//TYPE 1- (	open parenthesis
		if(source[i]=='(')
		{
			push(stack,source[i]);
			i++;
		}
		//TYPE 2- OPERANDS
		else if(isalpha(source[i]) || isdigit(source[i]))
		{
			target[j]=source[i];
			i++;
			j++;
		}
		//TYPE 3- ) close parenthesis
		else if(source[i]==')')
		{
			while((TOP!=-1)&&(stack[TOP]!='('))  //add operators to postfix till we get another ( 
			{                                    //or stack becomes empty
				target[j]=pop(stack);
				j++;
			}
			if(TOP==-1)  //means a close parenthesis ) without an open parenthesis (
			{
				printf("\nINCORRECT EXPRESSION");
				exit(1);
			}
			temp=pop(stack); //Remove ) corresponding to the encountered (
			i++;
		}
		else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='%')
		{
			while(TOP!=-1 && stack[TOP]!='(' && getpriority(stack[TOP])>getpriority(source[i]))
			{
				target[j]=pop(stack);
				j++;
			}
			push(stack,source[i]); //After transfering higher priority(if any) operators from 
			i++;                    //stack to postfix, add the encountered operator to stack
		}
		else
	    {
			printf("\nIncorrect element in expression.");
			exit(1);
		}
	}
	//Add remaining operators in stack to the postfix expression
	while(TOP!=-1 && stack[TOP]!='(')
	{
		target[j]=pop(stack);
		j++;
	}
	target[j]='\0';//End the postfix expression
}
//-----------------------------------------------------------------------------------------------
void push(char stack[], char c)
{
	if(TOP==MAX-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		TOP=TOP+1;
		stack[TOP]=c;
	}
}
char pop(char stack[])
{ 
	char temp1;
	if(TOP==-1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		temp1=stack[TOP];
		TOP=TOP-1;
		return temp1;
	}
}
int getpriority(char c)
{
	int p;
    if(c=='*' || c=='/' || c=='%')
    	return 1;
    else
    	return 0;
}
