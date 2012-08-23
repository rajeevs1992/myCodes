#include<stdio.h>
#include<stdlib.h>
#define LINE printf("\n");
#define	POP top==-1?printf("\nStack empty!!!!!!"):printf("\nPopped %d ",stack[top--])
#define MAX 50
void PUSH(int stack[],int *top,int max);
void display(int stack[],int top);

char getch()
{
	system("stty raw");
	char ch=getchar();
	system("stty cooked");
	return ch;
}

int main()
{
	int top=-1,max,stack[MAX],ch;	
	printf("\nEnter the size of the stack ");
	scanf("%d",&max);
	getch();
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				PUSH(stack,&top,max);
				break;
			case 2:
				POP;
				break;
			case 3:
				display(stack,top);
				break;
			case 4:
				exit(0);
		}
//		getch();
//		system("clear");
	}
}

void PUSH(int stack[],int *top,int max)
{
	if(*top==max-1)
		printf("\nStack full!!!!!\n");
	else
	{
		printf("\nEnter the number to be pushed ");
		scanf("%d",&stack[++*top]);
	}
}

void display(int stack[],int top)
{
	int i;
	LINE;
	printf("\nDisplaying stack ");
	if(top==-1)
		printf("\nStack Empty!!!!!!\n");
	else
		for(i=top;i>=0;i--)
			printf("%d ",stack[i]);
}

