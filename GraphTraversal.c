//GRAPH TRAVERSAL TECHNIQUE
#include<stdio.h>
#define MAX 20
int a[20][20],visited[],queue[MAX],stack[MAX];
void DFS(int start)
{
int stack[MAX];
int top = -1, i;
printf("%c \t",start + 65);
visited[start] = 1;
stack[++top] = start;
while(top!=-1)
{
start = stack[top];
for(i = 0; i < MAX; i++)
{
if(a[start][i] && visited[i] == 0)
{
stack[++top] = i;
printf("%c \t",i + 65);
visited[i] = 1;
break;
}
}
if(i == MAX)
top--;
}
}
void BFS(int start) {
int queue[MAX],rear =-1,front =-1, i;
queue[++rear] = start;
visited[start] = 1;
while(rear != front)
{
start = queue[++front];
if(start==4)
printf("%c \t",start +65);
else
printf("%c \t",start + 65);
for(i = 0; i < MAX; i++)
{
if(a[start][i] == 1 && visited[i] == 0)
{
queue[++rear] = i;
visited[i] = 1;
}
}
}
}
int main()
{
int i,j,ch,n;
printf("Enter the number of vertices: \n");
scanf("%d",&n);
printf("Enter adjecency matrix of the graph: \n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
printf("1. Depth First Search \n");
printf("2. Breadth First Search \n");
do
{
printf(" \n Enter operation to be performed \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n DFS traversal:-\n");
for(i=0;i<n;i++)
visited[i]=0;
DFS(0);
break;
case 2:
printf("\n BFS traversal:-\n");
for(i=0;i<n;i++)
visited[i]=0;
BFS(0);
break;
default: printf("No such Graph Traversal Algorithm ");
printf("Thankyou!");
break;
}
}while(ch<=2);
return 0;
}
