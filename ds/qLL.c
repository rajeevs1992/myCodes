#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node * PUSH(node *rear)
{
	node *temp;
	temp=(node *)malloc(sizeof temp);
	printf("\nEnter data ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(rear!=NULL)
		rear->next=temp;
	return temp;
}

node *POP(node *front)
{
	if(front==NULL)
		printf("\nQueue empty!!!!!\n");
	else
	{
		printf("\nPopped %d ",front->data);
		front=front->next;
		return front;
	}
	return NULL;
}
void display(node *front)
{
	if(front==NULL)
		printf("\nQueue empty!!!!!\n");
	else
	{
		node *temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

main()
{	
	int ch;
	node *front,*rear;
	front=(node *)malloc(sizeof front);
	rear=(node *)malloc(sizeof rear);
	while(1)
	{
		printf("\nEnter choice\n1.Push\n2.Pop\n3.Display\n4.Exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	
				rear=PUSH(rear);
				break;
			case 2:
				front=POP(front);
				break;
			case 3:
				display(front);
				break;
			case 4:
				exit(0);
		}
	}
}
