#include<stdio.h>
#include<stdlib.h>
#define LINE printf("\n");
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *PUSH(node *first)
{
	node *temp;
	temp=(node *)malloc(sizeof(temp));
	printf("\nEnter the node ");
	scanf("%d",&temp->data);
	temp->next=first;
	first=temp;
	return first;
}

node *POP(node *first)
{
	if(first!=NULL)
	{
		printf("\nPopped %d ",first->data);
		first=first->next;
		return first;
	}
	else
	{
		printf("\nStack empty ");
		return NULL;
	}
}

void display(node *first)
{
	node *temp=first;
	if(temp==NULL)
	{
		printf("\nStack empty!!!!\n");
		return;
	}
	LINE
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

main()
{
	node *first=NULL;
	int ch;
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.Display\n4.Exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				first=PUSH(first);
				break;
			case 2:
				first=POP(first);
				break;
			case 3:
				display(first);
				break;
			case 4:
				exit(0);
		}
	}
}
