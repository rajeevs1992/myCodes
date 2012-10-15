#include<stdio.h>
#include<stdlib.h>
void push(int item,int *top ,int Stack[],int l,int no);
void pop(int *top ,int Stack[],int l,int no);


int main()
{
	int NumberOfStacks,*Stack,LengthOfStack,*top,choice,StackNumber,i,item;
	printf("\nEnter the number of stacks ");
	scanf("%d",&NumberOfStacks);
	printf("\nEnter length of each stack ");
	scanf("%d",&LengthOfStack);
	Stack=(int *)malloc(sizeof(Stack)*LengthOfStack*NumberOfStacks);
	top=(int *)malloc(sizeof(top)*NumberOfStacks);
	for(i=0;i<NumberOfStacks;i++)
		top[i]=i*LengthOfStack;
	while(1)
	{
		printf("\nSelect operation \n1.PUSH\n2.POP\n3.QUIT ");
		scanf("%d",&choice);
		system("clear");
		if(choice == 3)
			exit(0);
		do
		{
			printf("\nEnter stack number ");
			scanf("%d",&StackNumber);
		}while(StackNumber>NumberOfStacks);
		switch(choice)
		{
			case 1:
				printf("\nEnter the item to be pushed ");
				scanf("%d",&item);
				push(item,&top[StackNumber-1],Stack,LengthOfStack,StackNumber);
				break;
			case 2:
				pop(&top[StackNumber-1],Stack,LengthOfStack,StackNumber);
				break;
		}
	}
}

void push(int item,int *top,int Stack[],int l,int no)
{
	if(*top==(l*(no)))
		printf("\nStack Full!!!!!!!!Cant push!!!!!");
	else
	{
		printf("\nPushing %d to Stack ",item);
		Stack[(*top)++]=item;
	}
}

void pop(int *top,int Stack[],int l,int no)
{
	(*top==l*(no-1))?printf("\nStack empty!!!!!! Cant POP "):printf("\nPOPped %d !!!!!!!",Stack[--(*top)]);
}
